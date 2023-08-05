################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/bmi085.c \
../Core/Src/bmi088.c \
../Core/Src/bmi088_stm32.c \
../Core/Src/bmi08a.c \
../Core/Src/bmi08g.c \
../Core/Src/bmp280.c \
../Core/Src/checking.c \
../Core/Src/crc.c \
../Core/Src/custom_bus.c \
../Core/Src/dma.c \
../Core/Src/freertos.c \
../Core/Src/gpio.c \
../Core/Src/i2c.c \
../Core/Src/madgwick.c \
../Core/Src/main.c \
../Core/Src/sdio.c \
../Core/Src/stm32f4xx_hal_msp.c \
../Core/Src/stm32f4xx_hal_timebase_tim.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system.c \
../Core/Src/system_stm32f4xx.c \
../Core/Src/usart.c \
../Core/Src/yrt_fram.c \
../Core/Src/yrt_ms5611.c \
../Core/Src/yrt_simpleKalman.c 

OBJS += \
./Core/Src/bmi085.o \
./Core/Src/bmi088.o \
./Core/Src/bmi088_stm32.o \
./Core/Src/bmi08a.o \
./Core/Src/bmi08g.o \
./Core/Src/bmp280.o \
./Core/Src/checking.o \
./Core/Src/crc.o \
./Core/Src/custom_bus.o \
./Core/Src/dma.o \
./Core/Src/freertos.o \
./Core/Src/gpio.o \
./Core/Src/i2c.o \
./Core/Src/madgwick.o \
./Core/Src/main.o \
./Core/Src/sdio.o \
./Core/Src/stm32f4xx_hal_msp.o \
./Core/Src/stm32f4xx_hal_timebase_tim.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system.o \
./Core/Src/system_stm32f4xx.o \
./Core/Src/usart.o \
./Core/Src/yrt_fram.o \
./Core/Src/yrt_ms5611.o \
./Core/Src/yrt_simpleKalman.o 

C_DEPS += \
./Core/Src/bmi085.d \
./Core/Src/bmi088.d \
./Core/Src/bmi088_stm32.d \
./Core/Src/bmi08a.d \
./Core/Src/bmi08g.d \
./Core/Src/bmp280.d \
./Core/Src/checking.d \
./Core/Src/crc.d \
./Core/Src/custom_bus.d \
./Core/Src/dma.d \
./Core/Src/freertos.d \
./Core/Src/gpio.d \
./Core/Src/i2c.d \
./Core/Src/madgwick.d \
./Core/Src/main.d \
./Core/Src/sdio.d \
./Core/Src/stm32f4xx_hal_msp.d \
./Core/Src/stm32f4xx_hal_timebase_tim.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system.d \
./Core/Src/system_stm32f4xx.d \
./Core/Src/usart.d \
./Core/Src/yrt_fram.d \
./Core/Src/yrt_ms5611.d \
./Core/Src/yrt_simpleKalman.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../X-CUBE-MEMS1/Target -I../Drivers/BSP/Components/lis3mdl -O0 -ffunction-sections -fdata-sections -Wall -u_printf_float -u_scanf_float -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/bmi085.cyclo ./Core/Src/bmi085.d ./Core/Src/bmi085.o ./Core/Src/bmi085.su ./Core/Src/bmi088.cyclo ./Core/Src/bmi088.d ./Core/Src/bmi088.o ./Core/Src/bmi088.su ./Core/Src/bmi088_stm32.cyclo ./Core/Src/bmi088_stm32.d ./Core/Src/bmi088_stm32.o ./Core/Src/bmi088_stm32.su ./Core/Src/bmi08a.cyclo ./Core/Src/bmi08a.d ./Core/Src/bmi08a.o ./Core/Src/bmi08a.su ./Core/Src/bmi08g.cyclo ./Core/Src/bmi08g.d ./Core/Src/bmi08g.o ./Core/Src/bmi08g.su ./Core/Src/bmp280.cyclo ./Core/Src/bmp280.d ./Core/Src/bmp280.o ./Core/Src/bmp280.su ./Core/Src/checking.cyclo ./Core/Src/checking.d ./Core/Src/checking.o ./Core/Src/checking.su ./Core/Src/crc.cyclo ./Core/Src/crc.d ./Core/Src/crc.o ./Core/Src/crc.su ./Core/Src/custom_bus.cyclo ./Core/Src/custom_bus.d ./Core/Src/custom_bus.o ./Core/Src/custom_bus.su ./Core/Src/dma.cyclo ./Core/Src/dma.d ./Core/Src/dma.o ./Core/Src/dma.su ./Core/Src/freertos.cyclo ./Core/Src/freertos.d ./Core/Src/freertos.o ./Core/Src/freertos.su ./Core/Src/gpio.cyclo ./Core/Src/gpio.d ./Core/Src/gpio.o ./Core/Src/gpio.su ./Core/Src/i2c.cyclo ./Core/Src/i2c.d ./Core/Src/i2c.o ./Core/Src/i2c.su ./Core/Src/madgwick.cyclo ./Core/Src/madgwick.d ./Core/Src/madgwick.o ./Core/Src/madgwick.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/sdio.cyclo ./Core/Src/sdio.d ./Core/Src/sdio.o ./Core/Src/sdio.su ./Core/Src/stm32f4xx_hal_msp.cyclo ./Core/Src/stm32f4xx_hal_msp.d ./Core/Src/stm32f4xx_hal_msp.o ./Core/Src/stm32f4xx_hal_msp.su ./Core/Src/stm32f4xx_hal_timebase_tim.cyclo ./Core/Src/stm32f4xx_hal_timebase_tim.d ./Core/Src/stm32f4xx_hal_timebase_tim.o ./Core/Src/stm32f4xx_hal_timebase_tim.su ./Core/Src/stm32f4xx_it.cyclo ./Core/Src/stm32f4xx_it.d ./Core/Src/stm32f4xx_it.o ./Core/Src/stm32f4xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system.cyclo ./Core/Src/system.d ./Core/Src/system.o ./Core/Src/system.su ./Core/Src/system_stm32f4xx.cyclo ./Core/Src/system_stm32f4xx.d ./Core/Src/system_stm32f4xx.o ./Core/Src/system_stm32f4xx.su ./Core/Src/usart.cyclo ./Core/Src/usart.d ./Core/Src/usart.o ./Core/Src/usart.su ./Core/Src/yrt_fram.cyclo ./Core/Src/yrt_fram.d ./Core/Src/yrt_fram.o ./Core/Src/yrt_fram.su ./Core/Src/yrt_ms5611.cyclo ./Core/Src/yrt_ms5611.d ./Core/Src/yrt_ms5611.o ./Core/Src/yrt_ms5611.su ./Core/Src/yrt_simpleKalman.cyclo ./Core/Src/yrt_simpleKalman.d ./Core/Src/yrt_simpleKalman.o ./Core/Src/yrt_simpleKalman.su

.PHONY: clean-Core-2f-Src

