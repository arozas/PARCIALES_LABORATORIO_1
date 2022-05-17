################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Primer_Parcial_Laboratorio_I.c \
../src/eProduct.c \
../src/eTracking.c \
../src/eUser.c \
../src/input.c \
../src/menu.c \
../src/myTime.c \
../src/operations.c \
../src/uOperations.c 

C_DEPS += \
./src/Primer_Parcial_Laboratorio_I.d \
./src/eProduct.d \
./src/eTracking.d \
./src/eUser.d \
./src/input.d \
./src/menu.d \
./src/myTime.d \
./src/operations.d \
./src/uOperations.d 

OBJS += \
./src/Primer_Parcial_Laboratorio_I.o \
./src/eProduct.o \
./src/eTracking.o \
./src/eUser.o \
./src/input.o \
./src/menu.o \
./src/myTime.o \
./src/operations.o \
./src/uOperations.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Primer_Parcial_Laboratorio_I.d ./src/Primer_Parcial_Laboratorio_I.o ./src/eProduct.d ./src/eProduct.o ./src/eTracking.d ./src/eTracking.o ./src/eUser.d ./src/eUser.o ./src/input.d ./src/input.o ./src/menu.d ./src/menu.o ./src/myTime.d ./src/myTime.o ./src/operations.d ./src/operations.o ./src/uOperations.d ./src/uOperations.o

.PHONY: clean-src

