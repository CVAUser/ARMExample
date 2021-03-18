//
//  rcc.c
//  
//
//  Created by Slava on 18.03.2021.
//

#include "rcc.h"

void gpioPortDEnable() {
    RCC_AHB1ENR = GPIO_D_ENABLE;
}
