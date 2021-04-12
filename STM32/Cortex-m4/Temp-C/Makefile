TARGET=empty
PROG=main

CC=arm-none-eabi-gcc
OBJ=arm-none-eabi-objcopy
DUMP=arm-none-eabi-objdump

ARCH_FLAGS=-mthumb -mcpu=cortex-m4
STARTUP=startup.S
LDSCRIPTS=-T script.ld

CFLAGS=-nostdlib $(ARCH_FLAGS) -g 
LFLAGS=$(LDSCRIPTS) -Wl,-Map=$(TARGET).map -Wl,--gc-sections
OFLAGS=-Obinary
DFLAGS=-D




$(TARGET).bin: $(TARGET).axf
	$(OBJ) $(OFLAGS) $^ $@

$(TARGET).axf: *.c $(STARTUP)
		$(CC) $(CFLAGS) $(LFLAGS) $^ -o $@

list:
	$(DUMP) $(DFLAGS) $(TARGET).axf > $(TARGET).list

clean:
	rm -f *.elf *.axf *.map *.o *.bin *.list
