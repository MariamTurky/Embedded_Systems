################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../GPT/Gpt.c 

OBJS += \
./GPT/Gpt.o 

C_DEPS += \
./GPT/Gpt.d 


# Each subdirectory must supply rules for building sources it contributes
GPT/%.o: ../GPT/%.c GPT/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -Wall -Wextra -g -DNDEBUG -DSTM32F401xE -DHSE_VALUE=8000000 -I"../include" -I"C:\Users\dell\eclipse-workspace\final_project\GPT" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -I"C:\Users\dell\eclipse-workspace\final_project\Lib" -I"C:\Users\dell\eclipse-workspace\final_project\Rcc" -I"C:\Users\dell\eclipse-workspace\final_project\Gpio" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


