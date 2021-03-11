TARGET=blink-c

CC=arm-none-eabi-gcc
OBJ=arm-none-eabi-objcopy
DUMP=arm-none-eabi-objdump

ARCH_FLAGS=-mthumb -mcpu=cortex-m4
STARTUP=startup.S
LDSCRIPTS=-T $(TARGET).ld

CFLAGS=-nolibc -nostdlib $(ARCH_FLAGS) -g
LFLAGS=$(LDSCRIPTS)
OFLAGS=-Obinary
DFLAGS=-D




$(TARGET).bin: $(TARGET).axf
	$(OBJ) $(OFLAGS) $(TARGET).axf $(TARGET).bin

$(TARGET).axf: $(TARGET).c $(STARTUP)
		$(CC) $(CFLAGS) $(LFLAGS) $(STARTUP) $(TARGET).c -o $(TARGET).axf

list:
	$(DUMP) $(DFLAGS) $(TARGET).axf > $(TARGET).list

clean:
	rm -f *.elf *.axf *.map *.o *.bin *.list
