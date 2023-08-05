import serial
import time
import re
import threading

import sys


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
        with open('kongrul1.txt','r') as f:
            prevTick = None
            for line in f:
                line = line.strip()
                numbers = re.findall(r'-?\d+(?:\.\d+)?', line)
                numbers_with_commas = ','.join(numbers)

                currentTick = float(numbers[6])
            
                if prevTick is not None:
                    timeDiff = currentTick - prevTick
                    time.sleep(timeDiff)  #kongrulda saniye cinsinden veri aldık

                    ser.write(bytes(numbers_with_commas + '\n', 'utf-8'))


                prevTick = currentTick
        
    except KeyboardInterrupt:
        ser.close()
        sys.exit(0)

threadMain = threading.Thread(target=main)
threadReadSerial = threading.Thread(target=readSerial)


threadMain.start()
threadReadSerial.start()

#bu kısma terkar bakılacak

#main()




    



    