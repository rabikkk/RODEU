################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
..\src/LineFollower_v1_0.c \
..\src/dbsct.c \
..\src/funcs.c \
..\src/idcode.c \
..\src/interrupt_handlers.c \
..\src/reset_program.c \
..\src/sbrk.c \
..\src/vector_table.c 

OBJS += \
./src/LineFollower_v1_0.obj \
./src/dbsct.obj \
./src/funcs.obj \
./src/idcode.obj \
./src/interrupt_handlers.obj \
./src/reset_program.obj \
./src/sbrk.obj \
./src/vector_table.obj 

C_DEPS += \
./LineFollower_v1_0.d \
./dbsct.d \
./funcs.d \
./idcode.d \
./interrupt_handlers.d \
./reset_program.d \
./sbrk.d \
./vector_table.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.obj: ../src/%.c src/%.d
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	ccrx -output=obj=$(dir $@)$(basename $(notdir $@)).obj -include="C:\Renesas\e2studio\Tools\Renesas\RX\1_2_1\include" -nologo -change_message=warning -cpu=rx600 -endian=big  -lang=c "$<"
	@echo 'Finished building: $<'
	@echo.


# Each subdirectory must supply rules for scanning sources it contributes
src/%.d: ../src/%.c
	@echo 'Scanning started: $<'
	scandep1 -MM -MP -MF  "$(@:%.obj=%.d)" -MT  "$(@:%.obj=%.d)"   -I"C:/Users/Cemal/Desktop/robotik/Renesas/e2studio/Workspace/LineFollower_v1_0" -I"C:\Renesas\e2studio\Tools\Renesas\RX\1_2_1\include" -D__RX600=1 -D__BIG=1   -D__FPU=1  -D__RON=1 -D__UCHAR=1 -D__DBL4=1 -D__UBIT=1 -D__BITRIGHT=1 -D__DOFF=1   -D__RENESAS__=1 -D__RENESAS_VERSION__=0x01020100 -D__RX=1   -E -quiet -I. -C $<
	@echo 'Finished scanning: $<'
	@echo.

