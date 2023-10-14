################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/SRV_Motor/SRV_Motor.c 

OBJS += \
./HAL/SRV_Motor/SRV_Motor.o 

C_DEPS += \
./HAL/SRV_Motor/SRV_Motor.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/SRV_Motor/%.o: ../HAL/SRV_Motor/%.c HAL/SRV_Motor/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\alsol\eclipse-workspace\drivers" -I"C:\Users\alsol\eclipse-workspace\drivers\APP" -I"C:\Users\alsol\eclipse-workspace\drivers\CFG" -I"C:\Users\alsol\eclipse-workspace\drivers\HAL" -I"C:\Users\alsol\eclipse-workspace\drivers\MCAL" -I"C:\Users\alsol\eclipse-workspace\drivers\SERVICES" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


