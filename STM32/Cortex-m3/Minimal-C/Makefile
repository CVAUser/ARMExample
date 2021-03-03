TARGET=minimal

CC=arm-none-eabi-gcc
AS=arm-none-eabi-as
LD=arm-none-eabi-ld
OBJ=arm-none-eabi-objcopy
DUMP=arm-none-eabi-objdump

STARTUP=startup
ARCH_FLAGS=-c -mthumb -mcpu=cortex-m4
CFLAGS=$(ARCH_FLAGS) -ffreestanding -nostdlib -g

OFLAGS=-Obinary
DFLAGS=-D

$(TARGET).bin: $(TARGET).elf
	$(OBJ) $(OFLAGS) $(TARGET).elf $(TARGET).bin

$(TARGET).elf: $(STARTUP).o $(TARGET).o $(TARGET).ld
	$(LD) -T $(TARGET).ld *.o -o $(TARGET).elf

$(TARGET).o: $(TARGET).c 
	$(CC) $(CFLAGS) *.c -o $(TARGET).o

$(STARTUP).o: $(STARTUP).S
	$(AS) $(ARCH_FLAGS) $(STARTUP).S -o $(STARTUP).o

list:
	$(DUMP) $(DFLAGS) $(TARGET).elf > $(TARGET).list

clean: 
	rm -f $(TARGET)*.elf *.map *.o *.bin *.list