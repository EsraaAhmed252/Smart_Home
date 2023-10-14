################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/Automated\ Door\ Control\ System/ADCS.c 

OBJS += \
./APP/Automated\ Door\ Control\ System/ADCS.o 

C_DEPS += \
./APP/Automated\ Door\ Control\ System/ADCS.d 


# Each subdirectory must supply rules for building sources it contributes
APP/Automated\ Door\ Control\ System/ADCS.o: ../APP/Automated\ Door\ Control\ System/ADCS.c APP/Automated\ Door\ Control\ System/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\alsol\eclipse-workspace\drivers" -I"C:\Users\alsol\eclipse-workspace\drivers\APP" -I"C:\Users\alsol\eclipse-workspace\drivers\CFG" -I"C:\Users\alsol\eclipse-workspace\drivers\HAL" -I"C:\Users\alsol\eclipse-workspace\drivers\MCAL" -I"C:\Users\alsol\eclipse-workspace\drivers\SERVICES" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"APP/Automated Door Control System/ADCS.d" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


