#!/bin/sh

arm-none-eabi-as -c -mthumb -mlittle-endian -march=armv7-m -mcpu=cortex-m3 startup.S -o startup.o
arm-none-eabi-gcc -c -mthumb -ffreestanding -mlittle-endian -march=armv7-m -mcpu=cortex-m3 test.c -o test.o
arm-none-eabi-ld -T test.ld test.o startup.o -o test.elf
