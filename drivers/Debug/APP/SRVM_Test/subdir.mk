################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/SRVM_Test/SRVM.c 

OBJS += \
./APP/SRVM_Test/SRVM.o 

C_DEPS += \
./APP/SRVM_Test/SRVM.d 


# Each subdirectory must supply rules for building sources it contributes
APP/SRVM_Test/%.o: ../APP/SRVM_Test/%.c APP/SRVM_Test/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\alsol\eclipse-workspace\drivers" -I"C:\Users\alsol\eclipse-workspace\drivers\APP" -I"C:\Users\alsol\eclipse-workspace\drivers\CFG" -I"C:\Users\alsol\eclipse-workspace\drivers\HAL" -I"C:\Users\alsol\eclipse-workspace\drivers\MCAL" -I"C:\Users\alsol\eclipse-workspace\drivers\SERVICES" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


