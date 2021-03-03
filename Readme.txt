#Install macporst https://www.macports.org/


sudo port install arm-none-eabi-gcc
sudo port install arm-none-eabi-gdb
sudo port install stlink
#QEMU emulate hardware
sudo port install qemu
sudo port install qemu +target_arm

#End user session

Залить прошивку
st-flash write blink.bin 0x8000000

Отладка с помощью arm-none-eabi-gdb микроконтроллера STM32F407VG

1. Необходимо запустить утилиту st-util из пакеты stlink
2. Запустить arm-none-eabi-gdb fancyblink.axf, где fancyblink объектный файл
3. Ввести команду tar extended-remote :4242 для подключения к микроконтроллеру
4. Запуск команд отладки:
   load
   next
   step
   run
   finish
   break
   clear
   info registers
   x/fx адрес

Описание находится в папке stlink файл README