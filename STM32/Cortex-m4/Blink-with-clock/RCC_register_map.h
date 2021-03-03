/*--------------------------------------------------------------------------------------------

Cистема тактирования и сброса.

В этом файле описаны адреса и значения RCC регистров управления
настройки тактирования от внутреннего, внешнего или ФАПЧ (фазовая автоподстройка частоты)
генератора, а также режимы сброса, калибровки и тактового измерения.

--------------------------------------------------------------------------------------------*/

/********************************************************************************************

Clock Control Register - регистр управления тактированием.
 
Без состояния ожидание
Доступ к регистру: слово, полуслово, байт
Значение после сброса 0x0000XX83 где X не определено
 
*********************************************************************************************/

.equ RCC_CR           ,0x40023800   /*Адрес регистра для записи значений*/

.equ HSION            ,0x1          /*HSI oscillator ON*/
.equ HSIRDY           ,0x2          /*HSI oscillator ready*/
.equ HSITRIM          ,0x80         /*Internal high-speed clock trimming*/
.equ HSEON            ,0x10000      /*HSE oscillator ON*/
.equ HSERDY           ,0x20000      /*HSE oscillator ready*/
.equ HSEBYP           ,0x40000      /*HSE oscillator bypassed with an external clock*/
.equ CSSON            ,0x80000      /*Clock security system ON*/
.equ PLLON            ,0x1000000    /*PLL ON*/
.equ PLLRDY           ,0x2000000    /*PLL locked*/
.equ PLLI2SON         ,0x4000000    /*PLLI2S ON*/
.equ PLLI2SRDY        ,0x8000000    /*PLLI2S locked*/

/*********************************************************************************************

Регистр настройки ФАПЧ.

f(VCO clock) = f(PLL clock input) / PLLM × PLLN

f(PLL general clock output) = f(VCO clock) / PLLP

f(USB OTG FS, SDIO, RNG clock output) = f(VCO clock) / PLLQ

Значение после сброса 0x24003010

*********************************************************************************************/

.equ RCC_PLLCFGR      ,0x40023804   /*Адрес регистра для записи значений*/

.equ PLLM             ,0x8         /*(1 MHz) VCO input = PLL input / PLLM with 2 ≤ PLLM ≤ 63*/
.equ PLLN             ,0x5400      /*(336 MHz) VCO output = VCO input × PLLN with 50 ≤ PLLN ≤ 432*/
.equ PLLP             ,0x0         /*(168 MHz) PLL output = VCO / PLLP with PLLP = 2, 4, 6, or 8*/ 
.equ PLLSRC           ,0x400000    /*HSE oscillator clock selected as PLL and PLLI2S clock entry*/
.equ PLLQ             ,0x3000000   /*(48 MHz) USB OTG FS, SDIO and random number generator clocks*/

/*********************************************************************************************

Регистр конфигурации тактирования
Значение после сброса 0x00000000

*********************************************************************************************/

.equ RCC_CFGR         ,0x40023808  /*Адрес регистра для записи значений*/

.equ SW               ,0x2         /*PLL selected as system clock*/
.equ SWS              ,0x8         /*PLL used as the system clock (status bit)*/
.equ HPRE             ,0x70        /*system clock not divided (AHB prescaler)*/
.equ PPRE1            ,0xC00       /*AHB clock not divided (APB1 Low speed prescaler)*/
.equ PPRE2            ,0x6000      /*AHB clock not divided (APB2 high-speed prescaler)*/
.equ RTCPRE           ,0x10000     /*No clock (HSE division factor for RTC clock 1 MHz) */
.equ MCO1             ,0x600000    /*PLL clock selected (Microcontroller clock output 1)*/
.equ I2SSRC           ,0x800000    /*PLLI2S clock used as I2S clock source*/
.equ MCO1PRE          ,0x3000000   /*MCO1 prescaler no division*/
.equ MCO2PRE          ,0x18000000  /*MCO2 prescaler no division*/
.equ MCO2             ,0x0         /*System clock (SYSCLK) selected (MCO2)*/

/*********************************************************************************************

Регистр прерываня тактирования
Значение после сброса 0x00000000

********************************************************************************************/

.equ RCC_CIR          ,0x4002380C  /*Адрес регистра для записи значений*/



/********************************************************************************************/

.equ RCC_AHB1RSTR     ,0x40023810
.equ RCC_AHB2RSTR     ,0x40023814
.equ RCC_AHB3RSTR     ,0x40023818
.equ RCC_APB1RSTR     ,0x40023820
.equ RCC_APB2RSTR     ,0x40023824
/********************************************************************************************

Регистр включения тактирования периферии

********************************************************************************************/

.equ RCC_AHB1ENR      ,0x40023830  /*Адрес регистра для записи значений*/

.equ GPIODEN          ,0x8         /*IO port D clock enable*/

/********************************************************************************************/

.equ RCC_AHB2ENR      ,0x40023834
.equ RCC_AHB3ENR      ,0x40023838
.equ RCC_APB1ENR      ,0x40023840
.equ RCC_APB2ENR      ,0x40023844
.equ RCC_AHB1LPENR    ,0x40023850
.equ RCC_AHB2LPENR    ,0x40023854
.equ RCC_AHB3LPENR    ,0x40023858
.equ RCC_APB1LPENR    ,0x40023860
.equ RCC_APB2LPENR    ,0x40023864
.equ RCC_BDCR         ,0x40023870 
.equ RCC_CSR          ,0x40023874
.equ RCC_SSCGR        ,0x40023880
.equ RCC_PLLI2SCFGR   ,0x40023884
