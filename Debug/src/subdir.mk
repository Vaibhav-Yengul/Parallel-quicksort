################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Box.cpp \
../src/csvreadwrite.cpp \
../src/helper.cpp \
../src/main-parallel-quicksort2.cpp \
../src/quicksort.cpp \
../src/sortwriter.cpp 

OBJS += \
./src/Box.o \
./src/csvreadwrite.o \
./src/helper.o \
./src/main-parallel-quicksort2.o \
./src/quicksort.o \
./src/sortwriter.o 

CPP_DEPS += \
./src/Box.d \
./src/csvreadwrite.d \
./src/helper.d \
./src/main-parallel-quicksort2.d \
./src/quicksort.d \
./src/sortwriter.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


