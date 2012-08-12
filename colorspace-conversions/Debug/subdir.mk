################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../colorspace-conversions.c \
../colorspace_body.c \
../colorspace_constructors.c 

OBJS += \
./colorspace-conversions.o \
./colorspace_body.o \
./colorspace_constructors.o 

C_DEPS += \
./colorspace-conversions.d \
./colorspace_body.d \
./colorspace_constructors.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


