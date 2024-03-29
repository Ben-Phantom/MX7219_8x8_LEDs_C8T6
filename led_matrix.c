//
// Created by benwa on 2024/3/27.
//

#include "led_matrix.h"
#include "stm32f1xx_hal.h"

extern SPI_HandleTypeDef hspi1; // 名为 hspi1 的SPI句柄

// 定义MAX7219的一些控制命令
#define MAX7219_REG_NOOP        0x00
#define MAX7219_REG_DIGIT0      0x01
#define MAX7219_REG_DECODEMODE  0x09
#define MAX7219_REG_INTENSITY   0x0A
#define MAX7219_REG_SCANLIMIT   0x0B
#define MAX7219_REG_SHUTDOWN    0x0C
#define MAX7219_REG_DISPLAYTEST 0x0F

/* SPI1 init function */

// CS (片选) 控制函数
void MAX7219_CS_Select() {
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_RESET); // CS连接到PA12
}

void MAX7219_CS_Deselect() {
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_SET);
}

// 向MAX7219发送命令和数据
void MAX7219_SendCommand(uint8_t cmd, uint8_t data) {
    uint8_t txData[2];
    txData[0] = cmd;
    txData[1] = data;
    MAX7219_CS_Select();
    HAL_SPI_Transmit(&hspi1, txData, 2, 100); // 发送数据
    MAX7219_CS_Deselect();
}

// 初始化MAX7219
void MAX7219_Init(void) {
    MAX7219_SendCommand(MAX7219_REG_NOOP, 0x00);      // 扫描限制，使用所有行
    MAX7219_SendCommand(MAX7219_REG_SHUTDOWN, 0x01);       // 退出关机模式
    MAX7219_SendCommand(MAX7219_REG_DISPLAYTEST, 0x00);    // 关闭显示测试
    MAX7219_SendCommand(MAX7219_REG_SCANLIMIT, 0x07);      // 扫描限制，使用所有行
    MAX7219_SendCommand(MAX7219_REG_DECODEMODE, 0x00);     // 使用LED矩阵（无解码）
    MAX7219_SendCommand(MAX7219_REG_INTENSITY, 0x08);      // 中等亮度
}

// 发送8x8 LED矩阵的图案
void MAX7219_Display(uint8_t *data) {
    for(uint8_t i = 0; i < 8; i++) {
        MAX7219_SendCommand(MAX7219_REG_DIGIT0 + i, data[i]);
    }
}

