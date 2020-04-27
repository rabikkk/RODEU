################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf *.lst *.lis *.lpp *.map *.x *.lbp src/*.src src/*.p src/*.pp *.bls *.libelf *.lbk *.abs

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include src/subdir.mk
-include src/mylib/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_UPPER_DEPS)),)
-include $(C++_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(O_DEPS)),)
-include $(O_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(ABS_DEPS)),)
-include $(ABS_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(SRC_DEPS)),)
-include $(SRC_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(SRC_UPPER_DEPS)),)
-include $(SRC_UPPER_DEPS)
endif
ifneq ($(strip $(CP_DEPS)),)
-include $(CP_DEPS)
endif
ifneq ($(strip $(CPP_UPPER_DEPS)),)
-include $(CPP_UPPER_DEPS)
endif
ifneq ($(strip $(OBJ_DEPS)),)
-include $(OBJ_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CP_UPPER_DEPS)),)
-include $(CP_UPPER_DEPS)
endif
ifneq ($(strip $(CC_UPPER_DEPS)),)
-include $(CC_UPPER_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_UPPER_DEPS)),)
-include $(CXX_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LINKER_OUTPUT_OUTPUTS += \
LineFollower_v1_0.abs \

LIBRARY_GENERATOR_OUTPUTTYPE_OUTPUTS += \
LineFollower_v1_0.lib \


# All Target
all: LineFollower_v1_0.mot
	@echo 'Build complete.'

# Tool invocations
LineFollower_v1_0.mot: $(LINKER_OUTPUT_OUTPUTS)
	@echo 'Invoking: Converter'
	optlnk   "C:\Users\ECE\Desktop\Workspace\LineFollower_v1_0\HardwareDebug\LineFollower_v1_0.abs" -form=stype  -output="C:\Users\ECE\Desktop\Workspace\LineFollower_v1_0\HardwareDebug\LineFollower_v1_0.mot"
	@echo 'Finished building target:'
	@echo.
	$(MAKE) --no-print-directory post-build

LineFollower_v1_0.abs: $(OBJS) $(LIBRARY_GENERATOR_OUTPUTTYPE_OUTPUTS)
	@echo 'Invoking: Linker'
	@echo 'Building target:'
	optlnk  $(USER_OBJS) $(LIBS) -library="C:\Users\ECE\Desktop\WORKSP~1\LINEFO~1\HARDWA~2\LineFollower_v1_0.lib"   -noprelink -list="LineFollower_v1_0.map" -nooptimize -start=SU,SI,B_1,R_1,B_2,R_2,B,R/0,PResetPRG/0FFFC0000,C_1,C_2,C,C"$$"*,D*,W*,L/0FFFC1000,PIntPRG/0FFFC6000,P/0FFFC8000,FIXEDVECT/0FFFFFFD0 -rom=D=R,D_1=R_1,D_2=R_2 -nomessage -nologo -output="C:\Users\ECE\Desktop\Workspace\LineFollower_v1_0\HardwareDebug\LineFollower_v1_0.abs" -subcommand="C:/Users/ECE/Desktop/Workspace/LineFollower_v1_0\HardwareDebug\LinkerSubCommand.tmp"
	@echo 'Finished building:'
	@echo.

LineFollower_v1_0.lib:  
	@echo 'Invoking: Standard Library'
	lbgrx -head=runtime,math,stdio,stdlib,string -cpu=rx600 -endian=big -output="LineFollower_v1_0.lib"
	@echo 'Finished building:'
	@echo.

# Other Targets
clean:
	-$(RM) $(C++_UPPER_DEPS)$(OBJS)$(C_DEPS)$(O_DEPS)$(S_DEPS)$(ABS_DEPS)$(CONVERTOR_OUTPUT_OUTPUTS)$(CXX_DEPS)$(S_UPPER_DEPS)$(C++_DEPS)$(SRC_DEPS)$(CC_DEPS)$(LINKER_OUTPUT_OUTPUTS)$(SRC_UPPER_DEPS)$(CP_DEPS)$(CPP_UPPER_DEPS)$(LIBRARY_GENERATOR_OUTPUTTYPE_OUTPUTS)$(OBJ_DEPS)$(CPP_DEPS)$(CP_UPPER_DEPS)$(CC_UPPER_DEPS)$(C_UPPER_DEPS)$(CXX_UPPER_DEPS) LineFollower_v1_0.mot
	@echo.
	@echo 'Clean complete.'

post-build:
	@echo.
	-C:\Renesas\e2studio\DEBUGC~1\RX\RX_CON~1.EXE LineFollower_v1_0.abs LineFollower_v1_0.x
	@echo.
	@echo.

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
