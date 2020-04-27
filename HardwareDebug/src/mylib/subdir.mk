################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
..\src/mylib/misc.c \
..\src/mylib/pid.c \
..\src/mylib/timers.c 

OBJS += \
./src/mylib/misc.obj \
./src/mylib/pid.obj \
./src/mylib/timers.obj 

C_DEPS += \
./src/mylib/misc.d \
./src/mylib/pid.d \
./src/mylib/timers.d 


# Each subdirectory must supply rules for building sources it contributes
src/mylib/%.obj: ../src/mylib/%.c src/mylib/%.d
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	ccrx -output=obj=$(dir $@)$(basename $(notdir $@)).obj -include="C:\Renesas\e2studio\Tools\Renesas\RX\1_2_1\include" -debug -nologo -change_message=warning -cpu=rx600 -endian=big  -lang=c "$<"
	@echo 'Finished building: $<'
	@echo.


# Each subdirectory must supply rules for scanning sources it contributes
src/mylib/%.d: ../src/mylib/%.c
	@echo 'Scanning started: $<'
	scandep1 -MM -MP -MF  "$(@:%.obj=%.d)" -MT  "$(@:%.obj=%.d)"   -I"C:/Users/ECE/Desktop/Workspace/LineFollower_v1_0" -I"C:\Renesas\e2studio\Tools\Renesas\RX\1_2_1\include" -D__RX600=1 -D__BIG=1   -D__FPU=1  -D__RON=1 -D__UCHAR=1 -D__DBL4=1 -D__UBIT=1 -D__BITRIGHT=1 -D__DOFF=1   -D__RENESAS__=1 -D__RENESAS_VERSION__=0x01020100 -D__RX=1   -E -quiet -I. -C $<
	@echo 'Finished scanning: $<'
	@echo.

