################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Uart/subdir.mk
-include Extra/subdir.mk
-include Device/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Atmega8Uart.lss \

FLASH_IMAGE += \
Atmega8Uart.hex \

EEPROM_IMAGE += \
Atmega8Uart.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Atmega8Uart.elf secondary-outputs

# Tool invocations
Atmega8Uart.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C++ Linker'
	avr-g++ -Wl,-Map,Atmega8Uart.map,--cref -mrelax -Wl,--gc-sections -mmcu=atmega8 -o "Atmega8Uart.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Atmega8Uart.lss: Atmega8Uart.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Atmega8Uart.elf  >"Atmega8Uart.lss"
	@echo 'Finished building: $@'
	@echo ' '

Atmega8Uart.hex: Atmega8Uart.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Atmega8Uart.elf  "Atmega8Uart.hex"
	@echo 'Finished building: $@'
	@echo ' '

Atmega8Uart.eep: Atmega8Uart.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Atmega8Uart.elf  "Atmega8Uart.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Atmega8Uart.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega8 Atmega8Uart.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(CXX_DEPS)$(S_UPPER_DEPS)$(C++_DEPS)$(ASM_DEPS)$(CC_DEPS)$(CPP_DEPS)$(C_UPPER_DEPS)$(SIZEDUMMY) Atmega8Uart.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
