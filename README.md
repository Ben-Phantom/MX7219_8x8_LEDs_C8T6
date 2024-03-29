# MX7219_8x8_LEDs_C8T6 
### This is a library used on STM32 to controll the MX7219_8x8_LEDs_group_module.
## ⚓ Function
The library when properly used, may show simple digits 0 ~ 9 on the MX7219_8x8_LEDs_group.

Also, if you are interested in creating customized animation on the light screen, you may edit the const *digits* by yourself.

How? Actually, each first-level element of the two-dimensional array *digits* is a whole animation matrix to be showed.

And each element of them is a row of 8 LED lights--so there will be 8 elements and they are all binary literals in the form of "0b00000000",

which represents the on and off of this row of small lights.
## 🙂 How to use



- include "led_matrix.h"

- To set up you write the following statements in the main function

```
for(int i = 0; i < 10; i++) {
            displayNumber(i);
            HAL_Delay(1000);
      }
```
## ❤️ Tips
- If you R not familliar with the MX7219_8x8_LEDs_group.

- I am using _ on STM32F103.
  - GPIO 12 : Set your own GPIO in *led_matrix.c* to use it!
  - SPI1 : The CLK & CS should be connected repectively to PB3 and PB5 as SCK and MOSI
  
