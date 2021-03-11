TARGET=minimal

CC=arm-none-eabi-gcc
OBJ=arm-none-eabi-objcopy
DUMP=arm-none-eabi-objdump

ARCH_FLAGS=-mthumb -mcpu=cortex-m4
STARTUP=startup.S
LDSCRIPTS=-L. -T minimal.ld

USE_NANO=-specs=nano.specs
USE_SEMIHOST=-specs=rdimon.specs
USE_NOHOST=-specs=nosys.specs

CFLAGS=$(ARCH_FLAGS) -g
LFLAGS=$(USE_NANO) $(USE_SEMIHOST) $(LDSCRIPTS)
OFLAGS=-Obinary
DFLAGS=-D




$(TARGET).bin: $(TARGET).axf
	$(OBJ) $(OFLAGS) $(TARGET).axf $(TARGET).bin

$(TARGET).axf: $(TARGET).c $(STARTUP)
		$(CC) $^ $(CFLAGS) $(LFLAGS) -o $@

list:
	$(DUMP) $(DFLAGS) $(TARGET).elf > $(TARGET).list

clean:
	rm -f $(TARGET)*.elf *.map *.o *.bin *.list
