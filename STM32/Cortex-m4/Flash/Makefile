NAME=File
FAMILY=-mthumb -mcpu=cortex-m4

WAY=/Users/Mac/Project/STM32/Flash/

AS=arm-none-eabi-as
LD=arm-none-eabi-ld
OBJ=arm-none-eabi-objcopy
DUMP=arm-none-eabi-objdump

AFLAGS=-mthumb -mcpu=cortex-m4 -g
LFLAGS=-T file.ld -o
OFLAGS=-Obinary
DFLAGS=-D


	
$(NAME).bin: File.axf
	$(OBJ) $(OFLAGS) $(WAY)$(NAME).axf $(WAY)$(NAME).bin
	
$(NAME).axf: $(NAME).o
	$(LD) $(LFLAGS) $(WAY)$(NAME).axf	$(WAY)$(NAME).o
	
$(NAME).o: $(NAME).s    
	$(AS) $(AFLAGS) $(WAY)$(NAME).s -o $(WAY)$(NAME).o	
 

clean: 
	rm -f $(NAME).axf *.o *.bin *.list
	
list:
	$(DUMP) $(DFLAGS) $(WAY)$(NAME).axf > $(WAY)file.list
	



    
