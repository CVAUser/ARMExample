.syntax unified
.arch armv7-m

.section .vectors
.global vector
.global start
.global _Start_Stack
vector:
    .long _Start_Stack
    .long   start
    .long   NMI_Handler           /* NMI Handler */
    .long   HardFault_Handler     /* Hard Fault Handler */

    .size    vector, . - vector

.text
.thumb
.type start, %function

start:
	ldr r1, =main
	bx r1
