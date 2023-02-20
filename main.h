/*
 * main.h
 *
 *  Created on: Dec 5, 2022
 *      Author: Мария
 */

#ifndef MAIN_H_
#define MAIN_H_


//Библа для типов данных по типу uint8_t
#include <stdint.h>

//Наш файл с адресами регистров
#include "regmap.h"


//Постоянные для регулирования частоты моргания(в единицах ARR, для 1 мс периода таймера-  в мс)
#define	MODE_1_BLINK_PERIOD	100		//Режим 1
#define	MODE_2_BLINK_PERIOD	300		//Режим 2
#define	MODE_3_BLINK_PERIOD	700		//Режим 3
#define	MODE_4_BLINK_PERIOD	1000	//Режим 4

//Время ожидания для антидребезга(в единицах ARR, для 1 мс периода таймера-  в мс
#define BUTTON_NOISE_WAIT_TIME 150

//Вспомогательные переменные и массивы для работы режимов
uint8_t blink_mode1_current_stage = 0;
char blink_mode1_ActiveLeds[8] = {'r','g','b','n','n','n','n','n'};
uint8_t blink_mode1_frequency = 1;

uint8_t blink_mode2_current_stage = 0;
char blink_mode2_ActiveLeds[8] = {'r','g','n','n','n','n','n','n'};
uint8_t blink_mode2_frequency = 2;

uint8_t blink_mode3_current_stage = 0;
char blink_mode3_ActiveLeds[8] = {'r','b','n','n','n','n','n','n'};
uint8_t blink_mode3_frequency = 3;

uint8_t blink_mode4_current_stage = 0;
char blink_mode4_ActiveLeds[8] = {'g','b','n','n','n','n','n','n'};
uint8_t blink_mode4_frequency = 4;

//Переменные для антидребезга
uint8_t isBtn_waitForClick = 0;
uint8_t isBtn_waitForRelease = 0;
uint8_t isBtn_clicked = 0;

//Режим моргания
uint8_t ledMode = 0;

//Прототипы функций

void SystemClockInit(void);
void switch_Led(char);
void setLedMode(uint8_t);
void setLedFrequencyMode(uint8_t);
void processLedMode();

#endif /* MAIN_H_ */
