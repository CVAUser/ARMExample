.syntax unified
.arch armv7-m

.text
.thumb
.global start
.global _Start_Stack
.type start, %function

.long _Start_Stack
.long start   

start:
	ldr r1, =main
	bx r1