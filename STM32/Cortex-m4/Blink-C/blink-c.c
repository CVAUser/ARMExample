#include <stdio.h>

#define RCC_AHB1ENR (*(volatile uint32_t *)(0x40023830))
#define GPIO_D_ENABLE (0x00000008)

#define GPIOD (*(volatile uint32_t *)(0x40020C00))
#define GPIO_BSSR (*(volatile uint32_t *)(0x40020C18))

void main() {
	RCC_AHB1ENR = GPIO_D_ENABLE;
	GPIOD = 0x01000000;

	while (1) {
		GPIO_BSSR = 0x1000;
		int i;
		for (i = 0; i < 1000000; i++) {	/* Wait a bit. */
			__asm__("nop");
		}
		GPIO_BSSR = 0x10000000;
		for (i = 0; i < 1000000; i++) {	/* Wait a bit. */
			__asm__("nop");
		}
	}
}
