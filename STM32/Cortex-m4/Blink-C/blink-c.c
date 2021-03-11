#define RCC_AHB1ENR (*(volatile int *)(0x40023830U))
#define GPIO_D_ENABLE (0x00000008U)

#define GPIOD (*(volatile int *)(0x40020C00U))
#define GPIO_BSSR (*(volatile int *)(0x40020C18U))

void main() {
	RCC_AHB1ENR = GPIO_D_ENABLE;
	GPIOD = 0x01000000U;

	while (1) {
		GPIO_BSSR = 0x1000U;
		int i;
		for (i = 0; i < 1000000; i++) {	/* Wait a bit. */
			__asm__("nop");
		}
		GPIO_BSSR = 0x10000000U;
		for (i = 0; i < 1000000; i++) {	/* Wait a bit. */
			__asm__("nop");
		}
	}
}
