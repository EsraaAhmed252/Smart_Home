################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/LCD/LCD.c \
../HAL/LCD/MOTOR.c 

OBJS += \
./HAL/LCD/LCD.o \
./HAL/LCD/MOTOR.o 

C_DEPS += \
./HAL/LCD/LCD.d \
./HAL/LCD/MOTOR.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/LCD/%.o: ../HAL/LCD/%.c HAL/LCD/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\alsol\eclipse-workspace\test\APP" -I"C:\Users\alsol\eclipse-workspace\test\CFG" -I"C:\Users\alsol\eclipse-workspace\test\HAL" -I"C:\Users\alsol\eclipse-workspace\test\MCAL" -I"C:\Users\alsol\eclipse-workspace\test\SERVICES" -I"C:\Users\alsol\eclipse-workspace\test" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


