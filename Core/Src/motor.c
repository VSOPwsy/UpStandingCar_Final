#include "motor.h"

int 	DirectionL;
int 	DirectionR;
int MotorSpeedL;
int MotorSpeedR;

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
			__HAL_TIM_SET_COMPARE(&TB6612FNG_PWMA_HANDLER, TB6612FNG_PWMA_CHANNEL, speed);
			__HAL_TIM_SET_COMPARE(&TB6612FNG_PWMB_HANDLER, TB6612FNG_PWMB_CHANNEL, speed);

			HAL_GPIO_WritePin(TB6612FNG_AIN2_GPIO_PORT, TB6612FNG_AIN2_GPIO_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(TB6612FNG_AIN1_GPIO_PORT, TB6612FNG_AIN1_GPIO_PIN, GPIO_PIN_SET);

			HAL_GPIO_WritePin(TB6612FNG_BIN1_GPIO_PORT, TB6612FNG_BIN1_GPIO_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(TB6612FNG_BIN2_GPIO_PORT, TB6612FNG_BIN2_GPIO_PIN, GPIO_PIN_SET);
    }
    else
    {
			__HAL_TIM_SET_COMPARE(&TB6612FNG_PWMA_HANDLER, TB6612FNG_PWMA_CHANNEL, -speed);
			__HAL_TIM_SET_COMPARE(&TB6612FNG_PWMB_HANDLER, TB6612FNG_PWMB_CHANNEL, -speed);

			HAL_GPIO_WritePin(TB6612FNG_AIN2_GPIO_PORT, TB6612FNG_AIN2_GPIO_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(TB6612FNG_AIN1_GPIO_PORT, TB6612FNG_AIN1_GPIO_PIN, GPIO_PIN_RESET);

			HAL_GPIO_WritePin(TB6612FNG_BIN1_GPIO_PORT, TB6612FNG_BIN1_GPIO_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(TB6612FNG_BIN2_GPIO_PORT, TB6612FNG_BIN2_GPIO_PIN, GPIO_PIN_RESET);
    }
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim==&TIM_INTERRUPT_HANDLER){		
		DirectionL = __HAL_TIM_IS_TIM_COUNTING_DOWN(&TB6612FNG_PWMA_ENCODER_HANDLER);
		DirectionR = __HAL_TIM_IS_TIM_COUNTING_DOWN(&TB6612FNG_PWMB_ENCODER_HANDLER);

		MotorSpeedL = DirectionL == 0 ? __HAL_TIM_GET_COUNTER(&TB6612FNG_PWMA_ENCODER_HANDLER)
																	:-__HAL_TIM_GET_COUNTER(&TB6612FNG_PWMA_ENCODER_HANDLER);
		MotorSpeedR = DirectionR == 1 ? __HAL_TIM_GET_COUNTER(&TB6612FNG_PWMB_ENCODER_HANDLER)
																	:-__HAL_TIM_GET_COUNTER(&TB6612FNG_PWMB_ENCODER_HANDLER);
		
        MotorSpeedL = MotorSpeedL > 1e4 ? 65535 - MotorSpeedL : (MotorSpeedL < -1e4 ? - (65535 + MotorSpeedL) : MotorSpeedL);
        MotorSpeedR = MotorSpeedR > 1e4 ? 65535 - MotorSpeedR : (MotorSpeedR < -1e4 ? - (65535 + MotorSpeedR) : MotorSpeedR);

		__HAL_TIM_SET_COUNTER(&TB6612FNG_PWMA_ENCODER_HANDLER, 0);
		__HAL_TIM_SET_COUNTER(&TB6612FNG_PWMB_ENCODER_HANDLER, 0);
	}
}
