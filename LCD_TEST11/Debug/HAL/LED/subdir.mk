################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/LED/LED_prog.c 

OBJS += \
./HAL/LED/LED_prog.o 

C_DEPS += \
./HAL/LED/LED_prog.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/LED/%.o: ../HAL/LED/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"F:\communication engineering\embedded system\nti\avr interfaces\eclipse_ex\LCD_TEST11\APP" -I"F:\communication engineering\embedded system\nti\avr interfaces\eclipse_ex\LCD_TEST11\HAL\LCD" -I"F:\communication engineering\embedded system\nti\avr interfaces\eclipse_ex\LCD_TEST11\HAL\LED" -I"F:\communication engineering\embedded system\nti\avr interfaces\eclipse_ex\LCD_TEST11\LIB" -I"F:\communication engineering\embedded system\nti\avr interfaces\eclipse_ex\LCD_TEST11\MCAL\DIO" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


