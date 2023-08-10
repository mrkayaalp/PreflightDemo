import serial
import time
import re
import threading
import csv
import numpy as np
import pandas as pd


import sys

CSV_FILE = 'flight_computer_trimmed.csv'
TXT_FILE = 'flight_computer_trimmed.txt'

flight_comp_tri = ['time', 'ax', 'ay', 'az', 'gx', 'gy', 'gz', 'mx', 'my', 'mz', 'latitude', 'longitude', 'altitude', 'satellite_count', 'position_lock', 'temperature', 'pressure', 'barometer_altitude', 'rocket_state', 'l1_extension', 'l2_extension','smt']


flight2_comp = ['time', 'ax', 'ay', 'az', 'gx', 'gy', 'gz', 'mx', 'my', 'mz',
    'latitude', 'longitude', 'altitude', 'satellite_count', 'position_lock',
    'temperature', 'pressure', 'barometer_altitude', 'highg_ax', 'highg_ay',
    'highg_az', 'rocket_state0', 'rocket_state1', 'rocket_state2', 'rocket_state3',
    'flap_extension', 'state_est_x', 'state_est_vx', 'state_est_ax', 'state_est_apo',
    'battery_voltage']

def openSerial():
    try:
        ser = serial.Serial('COM14', 115200) #COM 11 -- 14
        return ser
    except:
        print("Error opening serial port")
        sys.exit(1)

ser = openSerial()
currentTick = 0
timeDiff = 0


        
def dataArrange():
    data = pd.read_csv(CSV_FILE, names= flight_comp_tri)


    data.to_csv('arrData.csv', columns= ['time', 'ax', 'ay', 'az', 'gx', 'gy', 'gz','latitude','longitude','barometer_altitude','pressure'], index=False, header=False)
    




def readSerial():
    global ser
    global currentTick
    global timeDiff
    try:
        while True:
            with open('serialRead.txt','a') as fs:
                lineS = ser.readline()
                if  lineS is not None:
                    lineS = lineS.decode('utf-8')
                    lineS = parseStatement(lineS) #bu kısımdan pek emin değilim
                    lineS = lineS.strip()
                    fs.write(f'Time:{currentTick} || State: ' + lineS + '\n')
                    #time.sleep(timeDiff) #bu beklemeyi nasıl yerleştireceğimiz konusunda emin değilim
                else:
                    return
                

    except KeyboardInterrupt:
        ser.close()
        sys.exit(1)

def parseStatement(line):
    match int(line): 
        case 1:
            return 'START!\n'
        case 4:
            return 'AFTER_LIFTOFF\n'
        case 5:
            return 'AFTER_APOGEE\n'
        case 6:
            return 'AFTER_MAIN_PAR\n'
        

    
def main():
    global ser
    global currentTick
    global timeDiff
    try:
        with open('arrData.csv','r') as f:
            prevTick = None
            for line in f:
                line = line.strip()
                numbers = re.findall(r'-?\d+(?:\.\d+)?', line)
                numbers_with_commas = ','.join(numbers)

                currentTick = int(numbers[0]) #kongrulda float olacak
            
                if prevTick is not None:
                    timeDiff = currentTick - prevTick
                    time.sleep(timeDiff / 1000)  #kongrulda saniye cinsinden yazılacak

                    ser.write(bytes(numbers_with_commas + '\n', 'utf-8'))


                prevTick = currentTick
        
    except KeyboardInterrupt:
        ser.close()
        sys.exit(0)

dataArrange()

threadMain = threading.Thread(target=main)
threadReadSerial = threading.Thread(target=readSerial)

threadMain.start()
threadReadSerial.start()

#bu kısma tekrar bakılacak

#main()




    



    