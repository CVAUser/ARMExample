NAME=blink
FAMILY=-mthumb -mcpu=cortex-m4

AS=arm-none-eabi-as
LD=arm-none-eabi-ld
OBJ=arm-none-eabi-objcopy
DUMP=arm-none-eabi-objdump

AFLAGS=-mthumb -mcpu=cortex-m4 -g
OFLAGS=-Obinary

	
$(NAME).bin: $(NAME).axf
	$(OBJ) $(OFLAGS) $(NAME).axf $(NAME).bin
	
$(NAME).axf: $(NAME).o
	$(LD) -T $(NAME).ld $(NAME).o -o $(NAME).axf 
	
$(NAME).o: $(NAME).s    
	$(AS) $(AFLAGS) $(NAME).s -o $(NAME).o	
 

clean: 
	rm -f *.axf *.elf *.o *.bin *.list
	
list:
	$(DUMP) -D $(NAME).axf > file.list
	



    
