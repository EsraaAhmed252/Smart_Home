################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/KeyPad/KeyPad.c 

OBJS += \
./HAL/KeyPad/KeyPad.o 

C_DEPS += \
./HAL/KeyPad/KeyPad.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/KeyPad/%.o: ../HAL/KeyPad/%.c HAL/KeyPad/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\alsol\eclipse-workspace\test\APP" -I"C:\Users\alsol\eclipse-workspace\test\CFG" -I"C:\Users\alsol\eclipse-workspace\test\HAL" -I"C:\Users\alsol\eclipse-workspace\test\MCAL" -I"C:\Users\alsol\eclipse-workspace\test\SERVICES" -I"C:\Users\alsol\eclipse-workspace\test" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


