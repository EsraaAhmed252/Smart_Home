################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/DIO/DIO.c 

OBJS += \
./MCAL/DIO/DIO.o 

C_DEPS += \
./MCAL/DIO/DIO.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/DIO/%.o: ../MCAL/DIO/%.c MCAL/DIO/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\alsol\eclipse-workspace\drivers" -I"C:\Users\alsol\eclipse-workspace\drivers\APP" -I"C:\Users\alsol\eclipse-workspace\drivers\CFG" -I"C:\Users\alsol\eclipse-workspace\drivers\HAL" -I"C:\Users\alsol\eclipse-workspace\drivers\MCAL" -I"C:\Users\alsol\eclipse-workspace\drivers\SERVICES" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


