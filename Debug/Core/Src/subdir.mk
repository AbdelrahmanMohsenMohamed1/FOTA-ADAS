################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Car_Program.c \
../Core/Src/Data_Manager.c \
../Core/Src/GSM_GPS.c \
../Core/Src/IR.c \
../Core/Src/Motor.c \
../Core/Src/Ultrasonic.c \
../Core/Src/WaterSensor.c \
../Core/Src/dht22.c \
../Core/Src/main.c \
../Core/Src/stm32f1xx_hal_msp.c \
../Core/Src/stm32f1xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f1xx.c 

OBJS += \
./Core/Src/Car_Program.o \
./Core/Src/Data_Manager.o \
./Core/Src/GSM_GPS.o \
./Core/Src/IR.o \
./Core/Src/Motor.o \
./Core/Src/Ultrasonic.o \
./Core/Src/WaterSensor.o \
./Core/Src/dht22.o \
./Core/Src/main.o \
./Core/Src/stm32f1xx_hal_msp.o \
./Core/Src/stm32f1xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f1xx.o 

C_DEPS += \
./Core/Src/Car_Program.d \
./Core/Src/Data_Manager.d \
./Core/Src/GSM_GPS.d \
./Core/Src/IR.d \
./Core/Src/Motor.d \
./Core/Src/Ultrasonic.d \
./Core/Src/WaterSensor.d \
./Core/Src/dht22.d \
./Core/Src/main.d \
./Core/Src/stm32f1xx_hal_msp.d \
./Core/Src/stm32f1xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f1xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/Car_Program.cyclo ./Core/Src/Car_Program.d ./Core/Src/Car_Program.o ./Core/Src/Car_Program.su ./Core/Src/Data_Manager.cyclo ./Core/Src/Data_Manager.d ./Core/Src/Data_Manager.o ./Core/Src/Data_Manager.su ./Core/Src/GSM_GPS.cyclo ./Core/Src/GSM_GPS.d ./Core/Src/GSM_GPS.o ./Core/Src/GSM_GPS.su ./Core/Src/IR.cyclo ./Core/Src/IR.d ./Core/Src/IR.o ./Core/Src/IR.su ./Core/Src/Motor.cyclo ./Core/Src/Motor.d ./Core/Src/Motor.o ./Core/Src/Motor.su ./Core/Src/Ultrasonic.cyclo ./Core/Src/Ultrasonic.d ./Core/Src/Ultrasonic.o ./Core/Src/Ultrasonic.su ./Core/Src/WaterSensor.cyclo ./Core/Src/WaterSensor.d ./Core/Src/WaterSensor.o ./Core/Src/WaterSensor.su ./Core/Src/dht22.cyclo ./Core/Src/dht22.d ./Core/Src/dht22.o ./Core/Src/dht22.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/stm32f1xx_hal_msp.cyclo ./Core/Src/stm32f1xx_hal_msp.d ./Core/Src/stm32f1xx_hal_msp.o ./Core/Src/stm32f1xx_hal_msp.su ./Core/Src/stm32f1xx_it.cyclo ./Core/Src/stm32f1xx_it.d ./Core/Src/stm32f1xx_it.o ./Core/Src/stm32f1xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f1xx.cyclo ./Core/Src/system_stm32f1xx.d ./Core/Src/system_stm32f1xx.o ./Core/Src/system_stm32f1xx.su

.PHONY: clean-Core-2f-Src

