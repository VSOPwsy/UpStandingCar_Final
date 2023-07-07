#include "motor.h"
#include "tim.h"
void Motor_Output(float speed)
{	
		if (speed > 1000)
		{
			speed = 1000;
		}
		else if (speed < -1000)
		{
			speed = -1000;
		}
		
		
    if (speed>0)
    {
        __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, speed);
        __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, speed);

        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);

        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);
    }
    else
    {
        __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, -speed);
        __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, -speed);

        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);

        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);
    }
}
