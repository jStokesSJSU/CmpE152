################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../wci/backend/compiler/CodeGenerator.cpp 

O_SRCS += \
../wci/backend/compiler/CodeGenerator.o 

OBJS += \
./wci/backend/compiler/CodeGenerator.o 

CPP_DEPS += \
./wci/backend/compiler/CodeGenerator.d 


# Each subdirectory must supply rules for building sources it contributes
wci/backend/compiler/%.o: ../wci/backend/compiler/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I/usr/local/boost_1_68_0/ -I/usr/local/boost_1_68_0/boost/ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


