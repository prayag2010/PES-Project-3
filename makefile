# @file makefile
# @brief A common makefile for PC and FRDM KL25Z
#
# This makefile is common between two platforms, a PC and a FRDM
# KL25Z
# The four targets are as follows:
#
# frdm_debug - This target builds the output for the KL25Z.
# The output LEDs will change according to a LUT, and a log output
# of the status of LED, current time, and time elapsed since the
# last LED transition is available
#
# frdm_release - This target builds the output for the KL25Z.
# The output LEDs will change according to a LUT, but no log output
# will be available
#
# pc_debug - This target builds the output for the PC.
# The output LEDs will print on console according to a LUT, 
# and a log output of the status of LED, current time, and time 
# elapsed since the last LED transition is available
#
# # frdm_release - This target builds the output for the PC.
# The output LEDs will print according to a LUT, but no log output
# will be available
#
# @author Rahul Ramaprasad, Prayag Milan Desai
# @date October 3 2019
# @version 1.0

###################################################
# Command for removing files
RM := rm -rf

###################################################
# Compiler for freedom board
CC_FRDM := arm-none-eabi-gcc
# Compiler for PC
CC_PC := gcc 

###################################################
# Linker for KL25Z
LL_FRDM := arm-none-eabi-gcc
# Linker for PC
LL_PC := gcc

###################################################
# Binary/exectable to build for the KL25Z
EXE_FRDM := \
  ./debug_frdm/outputFRDM.axf

# Binary/exectable to build for the PC 
EXE_PC := \
  ./debug_pc/outputPC.exe
  

###################################################
# List of object files for the KL25Z
OBJS_FRDM := \
  ./debug_frdm/main.o \
  ./debug_frdm/CMSIS/startup_MKL25Z4.o \
  ./debug_frdm/CMSIS/system_MKL25Z4.o

# List of user object files for the KL25Z
USER_OBJS_FRDM := \
	./debug_frdm/board/board.o \
	./debug_frdm/board/clock_config.o \
	./debug_frdm/board/peripherals.o \
	./debug_frdm/board/pin_mux.o \
	./debug_frdm/drivers/fsl_clock.o \
	./debug_frdm/drivers/fsl_common.o \
	./debug_frdm/drivers/fsl_flash.o \
	./debug_frdm/drivers/fsl_gpio.o \
	./debug_frdm/drivers/fsl_lpsci.o \
	./debug_frdm/drivers/fsl_lptmr.o \
	./debug_frdm/drivers/fsl_smc.o \
	./debug_frdm/drivers/fsl_tsi_v4.o \
	./debug_frdm/drivers/fsl_uart.o \
	./debug_frdm/utilities/fsl_debug_console.o \
	./debug_frdm/frdm_includes/allocate_words.o \
	./debug_frdm/frdm_includes/display_memory.o \
	./debug_frdm/frdm_includes/free_words.o \
	./debug_frdm/frdm_includes/gen_pattern.o \
	./debug_frdm/frdm_includes/invert_block.o \
	./debug_frdm/frdm_includes/malloc.o \
	./debug_frdm/frdm_includes/verify_pattern.o \
	./debug_frdm/frdm_includes/write_memory.o \
	./debug_frdm/frdm_includes/write_pattern.o \
	./debug_frdm/frdm_includes/get_address.o \
	./debug_frdm/frdm_includes/ledControl.o \
	./debug_frdm/frdm_includes/loggerFunctions.o \
	./debug_frdm/frdm_includes/unitTest.o \
	./debug_frdm/System.o
	
 
# List of object files for the PC  
OBJS_PC := \
  	./debug_pc/main.o \
  	./debug_pc/ledControl.o \
	./debug_pc/allocate_words.o \
	./debug_pc/display_memory.o \
	./debug_pc/free_words.o \
	./debug_pc/gen_pattern.o \
	./debug_pc/invert_block.o \
	./debug_pc/malloc.o \
	./debug_pc/verify_pattern.o \
	./debug_pc/write_memory.o \
	./debug_pc/write_pattern.o \
	./debug_pc/get_address.o \
	./debug_pc/loggerFunctions.o
###################################################
# List of dependency files for KL25Z
C_DEPS_FRDM = \
  ./debug_frdm/main.d \
  ./debug_frdm/startup_MKL25Z4.d \
  ./debug_frdm/system_MKL25Z4.d
 
# List of dependency files for PC 
C_DEPS_PC = \
  ./debug_pc/main.d

###################################################

# List of source files for PC
C_SRC_PC = \
 ./source_common/main.c 
  
###################################################

# List of common source files
C_SRC_COMMON = \
 ./common_includes/allocate_words.c \
 ./common_includes/display_memory.c \
 ./common_includes/free_words.c \
 ./common_includes/gen_pattern.c \
 ./common_includes/get_address.c \
 ./common_includes/invert_block.c \
 ./common_includes/loggerFunctions.c \
 ./common_includes/malloc.c \
 ./common_includes/verify_pattern.c \
 ./common_includes/write_memory.c \
 ./common_includes/write_pattern.c \
  
  
###################################################

#List of macros to be included for different targets
PC_DEBUG_MACRO = pc_debug
PC_RELEASE_MACRO = pc_release
FRDM_RELEASE_MACRO = frdm_release
FRDM_DEBUG_MACRO = frdm_debug

###################################################

#Current EPOCH to pass to the KL25Z
EPOCH = $(shell date +'%s')

###################################################
#Include generated dependency files (only if not clean target)
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS_FRDM)),)
-include $(C_DEPS_FRDM)
endif
endif

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS_PC)),)
-include $(C_DEPS_PC)
endif
endif

###################################################
# Compiler options for KL25Z
CC_OPTIONS_FRDM := -c -std=gnu99 -O0 -g -ffunction-sections -fdata-sections -fno-builtin -mcpu=cortex-m0plus -mthumb -DCPU_MKL25Z128VLK4 -D__USE_CMSIS -I"CMSIS" -I"source" 

# Compiler options for PC
CC_OPTIONS_PC := -Wall -Werror

###################################################
# Linker Options for KL25Z
LL_FRDM_OPTIONS := -nostdlib -Xlinker -Map="debug_frdm/MyMakeProject.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -mcpu=cortex-m0plus -mthumb -T linkerfileFRDM.ld -o $(EXE_FRDM)

# Linker Options for KL25Z
LL_PC_OPTIONS := -Wall -Werror -o $(EXE_PC)

###################################################

# Build all targets
.PHONY: all
all: $(EXE_FRDM) $(EXE_PC)
	@echo "*** finished building ***"
	
# Doesn't give in error while building all
.PHONY: phony
$(EXE_PC): phony

# Build the KL25Z debug target
.PHONY: frdm_debug
frdm_debug: $(EXE_FRDM)
	@echo "*** finished building ***"

# Build the KL25Z release target
.PHONY: frdm_release
frdm_release: $(EXE_FRDM)
	@echo "*** finished building ***"


###################################################
# Clean target
.PHONY: clean
clean:
	-$(RM) $(EXECUTABLES) $(OBJS_FRDM) $(USER_OBJS_FRDM) $(OBJS_PC) $(EXE_FRDM) $(EXE_PC)
	-$(RM) ./debug_frdm/*.map
	-$(RM) ./debug_pc/*.map
	-@echo ' '

###################################################

# Link freedom object files to create executable
$(EXE_FRDM): $(OBJS_FRDM) $(USER_OBJS_FRDM) linkerfileFRDM.ld
	@echo 'Building target: $@'
	@echo 'Invoking: Linker'
	$(LL_FRDM) $(LL_FRDM_OPTIONS) $(OBJS_FRDM) $(USER_OBJS_FRDM) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Link PC object files to create executable (debug)
.PHONY: pc_debug
pc_debug : $(OBJS_PC) 
	@echo 'Attempting to link PC object files'
	$(LL_PC) $(OBJS_PC) $(LL_PC_OPTIONS)
	@echo 'PC source files $< linked'
	@echo 'Executable created'
	@echo "*** finished building ***"
	@echo ' '
	
.PHONY: pc_release
pc_release : $(OBJS_PC) 
	@echo 'Attempting to link PC object files'
	$(LL_PC) $(OBJS_PC) $(LL_PC_OPTIONS)
	@echo 'PC source files $< linked'
	@echo 'Executable created'
	@echo "*** finished building ***"
	@echo ' '

###################################################

# Rule to build the files in the common source folder for FRDM
./debug_frdm/%.o: ./source_common/%.c 
	@echo 'Building file: $<'
ifeq ($(MAKECMDGOALS),frdm_debug)
	$(CC_FRDM) $(CC_OPTIONS_FRDM) -D $(FRDM_DEBUG_MACRO) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
endif
ifeq ($(MAKECMDGOALS),frdm_release)
	$(CC_FRDM) $(CC_OPTIONS_FRDM) -D $(FRDM_RELEASE_MACRO) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
endif
	@echo 'Finished building: $<'
	@echo ' '

# Rule to build the files in the common source folder for PC
./debug_pc/%.o: ./source_common/%.c 
	@echo 'Building file: $<'
ifeq ($(MAKECMDGOALS),pc_debug)
	$(CC_PC) $(CC_OPTIONS_PC) -D $(PC_DEBUG_MACRO) -c "$<" -o "$@"
endif
ifeq ($(MAKECMDGOALS),pc_release)
	$(CC_PC) $(CC_OPTIONS_PC) -D $(PC_RELEASE_MACRO) -c "$<" -o "$@"
endif
	@echo 'Finished building: $<'
	@echo ' '
#
#	Rule to build the files in the includes folder for PC
./debug_pc/%.o: ./pc_includes/%.c 
	@echo 'Building file: $<'
ifeq ($(MAKECMDGOALS),pc_debug)
	$(CC_PC) $(CC_OPTIONS_PC) -D $(PC_DEBUG_MACRO) -c "$<" -o "$@"
endif
ifeq ($(MAKECMDGOALS),pc_release)
	$(CC_PC) $(CC_OPTIONS_PC) -D $(PC_RELEASE_MACRO) -c "$<" -o "$@"
endif
	@echo 'Finished building: $<'
	@echo ' '

###################################################

# Rule to build the files in the CMSIS folder
./debug_frdm/CMSIS/%.o: ./CMSIS/%.c
	@echo 'Building file: $<'
	$(CC_FRDM) $(CC_OPTIONS_FRDM) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

# Rule to build the files in the board folder
./debug_frdm/board/%.o: ./board/%.c
	@echo 'Building file: $<'
	$(CC_FRDM) $(CC_OPTIONS_FRDM) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
	
# Rule to build the files in the utilities folder
./debug_frdm/utilities/%.o: ./utilities/%.c
	@echo 'Building file: $<'
	$(CC_FRDM) $(CC_OPTIONS_FRDM) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

# Rule to build the files in the drivers folder
./debug_frdm/drivers/%.o: ./drivers/%.c
	@echo 'Building file: $<'
	$(CC_FRDM) $(CC_OPTIONS_FRDM) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
	
# Rule to build the files in the drivers folder
./debug_frdm/frdm_includes/%.o: ./frdm_includes/%.c
	@echo 'Building file: $<'
	$(CC_FRDM) $(CC_OPTIONS_FRDM) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

# Rule to build the files in the includes folder	
./debug_frdm/%.o: ./frdm_includes/%.c
	@echo 'Building file: $<'
ifeq ($(MAKECMDGOALS),frdm_debug)
	$(CC_FRDM) $(CC_OPTIONS_FRDM) -D $(FRDM_DEBUG_MACRO) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
endif
ifeq ($(MAKECMDGOALS),frdm_release)
	$(CC_FRDM) $(CC_OPTIONS_FRDM) -D $(FRDM_RELEASE_MACRO) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
endif
	@echo 'Finished building: $<'
	@echo ' ' 
	
./debug_frdm/%.o: ./uCUnit/%.c
	@echo 'Building file: $<'
ifeq ($(MAKECMDGOALS),frdm_debug)
	$(CC_FRDM) $(CC_OPTIONS_FRDM) -D $(FRDM_DEBUG_MACRO) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
endif
ifeq ($(MAKECMDGOALS),frdm_release)
	$(CC_FRDM) $(CC_OPTIONS_FRDM) -D $(FRDM_RELEASE_MACRO) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
endif
	@echo 'Finished building: $<'
	@echo ' ' 
	
./debug_frdm/frdm_includes/%.o: ./common_includes/%.c
	@echo 'Building file: $<'
ifeq ($(MAKECMDGOALS),frdm_debug)
	$(CC_FRDM) $(CC_OPTIONS_FRDM) -D $(FRDM_DEBUG_MACRO) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
endif
ifeq ($(MAKECMDGOALS),frdm_release)
	$(CC_FRDM) $(CC_OPTIONS_FRDM) -D $(FRDM_RELEASE_MACRO) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
endif
	@echo 'Finished building: $<'
	@echo ' ' 

./debug_pc/%.o: ./common_includes/%.c
	@echo 'Building file: $<'
ifeq ($(MAKECMDGOALS),pc_debug)
	$(CC_PC) $(CC_OPTIONS_PC) -D $(PC_DEBUG_MACRO) -c "$<" -o "$@"
endif
ifeq ($(MAKECMDGOALS),pc_release)
	$(CC_PC) $(CC_OPTIONS_PC) -D $(PC_RELEASE_MACRO) -c "$<" -o "$@"
endif
	@echo 'Finished building: $<'
	@echo ' '