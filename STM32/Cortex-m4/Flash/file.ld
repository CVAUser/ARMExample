MEMORY
{
    FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 1024K
    RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 128K
}

_Start_Stack = ORIGIN(RAM) + LENGTH(RAM);

ENTRY(Reset_Exception)

SECTIONS
{
    .text :
    {
        *(.text)

    } > FLASH

    .stack :
    {
	KEEP(*(.stack))
    } > RAM

}
