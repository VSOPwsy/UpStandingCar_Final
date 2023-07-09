#include "tim.h"

#include "upstand.h"
#include "pid.h"
#include "motor.h"
#include "./ATK_MS6050/atk_ms6050.h"
#include "./ATK_MS6050/eMPL/inv_mpu.h"
#include "gpio.h"

PID angle_pid, speed_pid;

float pit, rol, yaw;
int16_t gyr_x, gyr_y, gyr_z;

float angularVelocity;

float angle_pid_output, speed_pid_output;
uint16_t speed_control_counter = 0;

void UpStand_Init()
{
	PID_Init(&angle_pid);
	PID_Set_Coefficients(&angle_pid, 95, 0, -0.6);

	PID_Init(&speed_pid);
	PID_Set_Coefficients(&speed_pid, 20, 0, 0.1);

	atk_ms6050_init();

	atk_ms6050_dmp_init();
}

void UpStand()
{
	UpStand_Init();
	while (1)
	{
		atk_ms6050_dmp_get_data(&pit, &rol, &yaw);
		atk_ms6050_get_gyroscope(&gyr_x, &gyr_y, &gyr_z);
	}
}

