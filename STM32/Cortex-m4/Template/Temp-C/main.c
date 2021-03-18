//
//  empty.c
//  
//
//  Created by Slava on 18.03.2021.
//

#include <stdio.h>
#include "rcc.h"

#define GPIOD (*(volatile uint32_t *)(0x40020C00))
#define GPIO_BSSR (*(volatile uint32_t *)(0x40020C18))


void main() {
    gpioPortDEnable();
    GPIOD = 0x01000000;
    
    while (1) {
        GPIO_BSSR = 0x1000;
        int i;
        for (i = 0; i < 1000000; i++) {    /* Wait a bit. */
            __asm__("nop");
        }
        GPIO_BSSR = 0x10000000;
        for (i = 0; i < 1000000; i++) {    /* Wait a bit. */
            __asm__("nop");
        }
    }
}
