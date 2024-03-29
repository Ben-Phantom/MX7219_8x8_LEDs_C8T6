//
// Created by SISYPHUS on 2024/3/27.
//

#ifndef CHEST_LED_MATRIX_H
#define CHEST_LED_MATRIX_H

#include "stm32f1xx_hal.h"
#include "led_matrix_font.h"

void MAX7219_Init(void);
void MAX7219_Display(uint8_t *data);
void displayNumber(uint8_t number);

#endif //CHEST_LED_MATRIX_H