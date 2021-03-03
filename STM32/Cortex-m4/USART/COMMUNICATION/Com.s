  .syntax unified
  .arch armv7-m

  /*Адрес регистра кофигурации внешнего тактового генератора*/
  .equ RCC_CR         ,0x40023800
  .equ HSE_ON         ,0x10000

  /*Адрес кофигурации тактирования шины AHB1*/
  .equ RCC_AHB1ENR    ,0x40023830
  .equ GPIOСEN        ,0x4

  /*Адрес кофигурации тактирования шины APB1*/
  .equ RCC_APB1       ,0x40023840
  .equ UART4EN        ,0x80000

  /*Адрес конфигурации порта C GPIO*/
  .equ GPIOС          ,0x40020800
  .equ GPIOD_MODER    ,0xA00000 /*Выбор альтернативной функции для порта C*/

  /*Адрес конфигурации выводов альтернативной функции*/
  .equ GPIOC_AFRH     ,0x40020824
  .equ GPIOC_AFRH_EN  ,0x8800 /*выбранные выводы PC10 PC11*/

  /*Высокоскоростной внешний тактовый генератор HSE включен*/


  /*Включение тактирования UART4*/







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
    MOV32 r0   ,RCC_BASE + RCC_AHB1ENR
    MOV32 r1   ,GPIODEN
    str r1     ,[r0]

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
    MOV32	r2   ,0x00100000

Delay_loop:
    subs	     r2, r2, 1
    bne	       Delay_loop
    bx	       lr

