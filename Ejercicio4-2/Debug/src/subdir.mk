################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Ejercicio4-2.c \
../src/conversion.c \
../src/validacion.c 

OBJS += \
./src/Ejercicio4-2.o \
./src/conversion.o \
./src/validacion.o 

C_DEPS += \
./src/Ejercicio4-2.d \
./src/conversion.d \
./src/validacion.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


