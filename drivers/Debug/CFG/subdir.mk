################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CFG/DIO_Cfg.c \
../CFG/KeyPad_Cfg.c \
../CFG/MOTOR_Cfg.c 

OBJS += \
./CFG/DIO_Cfg.o \
./CFG/KeyPad_Cfg.o \
./CFG/MOTOR_Cfg.o 

C_DEPS += \
./CFG/DIO_Cfg.d \
./CFG/KeyPad_Cfg.d \
./CFG/MOTOR_Cfg.d 


# Each subdirectory must supply rules for building sources it contributes
CFG/%.o: ../CFG/%.c CFG/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\alsol\eclipse-workspace\drivers\APP" -I"C:\Users\alsol\eclipse-workspace\drivers\CFG" -I"C:\Users\alsol\eclipse-workspace\drivers\HAL" -I"C:\Users\alsol\eclipse-workspace\drivers\MCAL" -I"C:\Users\alsol\eclipse-workspace\drivers\SERVICES" -I"C:\Users\alsol\eclipse-workspace\drivers" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


