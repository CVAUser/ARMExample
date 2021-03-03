.syntax unified
.arch armv7-m

.text
.thumb
.global start
.global _Start_Stack
.type start, %function

.long _Start_Stack /* Вот это вершина стека */
.long start         /* А здесь инициализируем PC */


start:
	ldr r1, =c_entry
	bx r1
