//
// Created by benwa on 2024/3/27.
//

#ifndef CHEST_LED_MATRIX_H
#define CHEST_LED_MATRIX_H

#include "stm32f1xx_hal.h"

void MAX7219_Init(void);
void MAX7219_Display(uint8_t *data);

#endif //CHEST_LED_MATRIX_H