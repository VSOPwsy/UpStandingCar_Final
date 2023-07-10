#ifndef __MOTOR_H
#define __MOTOR_H

#include "stm32f1xx_hal.h"
#include "tim.h"

#define TIM_INTERRUPT_HANDLER     htim1   //用于定时中断测速的定时器

#define TB6612FNG_PWMA_HANDLER              htim2
#define TB6612FNG_PWMA_CHANNEL              TIM_CHANNEL_3
#define TB6612FNG_PWMA_ENCODER_HANDLER      htim3
#define TB6612FNG_AIN1_GPIO_PORT            GPIOB
#define TB6612FNG_AIN2_GPIO_PORT            GPIOB
#define TB6612FNG_AIN1_GPIO_PIN             GPIO_PIN_12
#define TB6612FNG_AIN2_GPIO_PIN             GPIO_PIN_13

#define TB6612FNG_PWMB_HANDLER              htim2
#define TB6612FNG_PWMB_CHANNEL              TIM_CHANNEL_4
#define TB6612FNG_PWMB_ENCODER_HANDLER      htim4
#define TB6612FNG_BIN1_GPIO_PORT            GPIOB
#define TB6612FNG_BIN2_GPIO_PORT            GPIOB
#define TB6612FNG_BIN1_GPIO_PIN             GPIO_PIN_14
#define TB6612FNG_BIN2_GPIO_PIN             GPIO_PIN_15


extern int MotorSpeedL;
extern int MotorSpeedR;

void Motor_Output(float speed);

#endif
