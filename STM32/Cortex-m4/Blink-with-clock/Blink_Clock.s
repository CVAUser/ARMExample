
/**********************************************
  Мигание светодиодом.
  Частота системной шины настроена на 168 MHz
  через PLL (ФАПЧ).
 *********************************************/

.include "RCC_register_map.h"

  .syntax unified
  .arch armv7-m

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

    /*Включить внешнее тактирование*/

    MOV32 r0   ,RCC_CR
    MOV32 r1   ,HSEON
    str r1     ,[r0]

    /*Настройка делителей PLL*/

    MOV32 r0   ,RCC_PLLCFGR
    MOV32 r1   ,PLLM + PLLN + PLLP + PLLSRC + PLLQ
    str r1     ,[r0]

    /*Включить PLL*/

    MOV32 r0   ,RCC_CR
    MOV32 r1   ,PLLON
    str r1     ,[r0]

    /*Конфигурации тактирования*/

    MOV32 r0   ,RCC_CFGR
    MOV32 r1   ,SW + HPRE + PPRE1 + PPRE2 + RTCPRE + MCO1 + I2SSRC + MCO1PRE + MCO2PRE
    str r1     ,[r0]

    /*Включения тактирования периферии шины AHB1*/

    MOV32 r0   ,RCC_AHB1ENR
    MOV32 r1   ,GPIODEN
    str r1     ,[r0]

    /*Включение порта GPIOD*/

    MOV32 r2   ,GPIOD
    MOV32 r3   ,GPIOD_MODER
    str r3     ,[r2]

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

    MOV32 r2   ,0x1500000

Delay_loop:

    subs       r2, r2, 1
    bne	       Delay_loop
    bx	       lr
