  .syntax unified
  .arch armv7-m

  .equ RCC_BASE       ,0x40023800
  .equ RCC_AHB1ENR    ,0x00000030
  .equ GPIODEN        ,0x00000008

  .equ GPIOD          ,0x40020C00
  .equ GPIOD_MODER    ,0x01000000

  .equ GPIO_BSSR      ,0x18

  .macro  MOV32 regnum,number
          MOVW \regnum,:lower16:\number
          MOVT \regnum,:upper16:\number
  .endm

  .text
  .thumb
  .global Reset_Exception
  .global _Start_Stack
  .type Reset_Exception, %function

  .long _Start_Stack
  .long Reset_Exception
  
Reset_Exception:
    mov.w r1,   GPIODEN
    ldr r0,     =RCC_BASE + RCC_AHB1ENR
    str r1,     [r0]


    mov.w r3,   GPIOD_MODER
    ldr r2,     =GPIOD
    str r3,     [r2]

BLINK_Loop:
    MOV32 r0   ,GPIOD + GPIO_BSSR
    MOV32 r1   ,0x1000
    str r1     ,[r0]

    bl         DELAY

    MOV32 r0   ,GPIOD + GPIO_BSSR
    MOV32 r1   ,0x10000000
    str r1     ,[r0]

    bl         DELAY

    b          BLINK_Loop

DELAY:
    MOV32	r2   ,0x00100000

Delay_loop:
    subs	     r2, r2, 1
    bne	       Delay_loop
    bx	       lr

