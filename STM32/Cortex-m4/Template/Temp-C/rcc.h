//
//  rcc.h
//  
//
//  Created by Slava on 18.03.2021.
//

#ifndef rcc_h
#define rcc_h

#include <stdio.h>

#endif /* rcc_h */

#define RCC_AHB1ENR (*(volatile uint32_t *)(0x40023830))
#define GPIO_D_ENABLE (0x00000008)

void gpioPortDEnable();
