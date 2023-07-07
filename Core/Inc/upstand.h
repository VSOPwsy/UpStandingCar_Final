#ifndef __UPSTAND_H
#define __UPSTAND_H

#include "pid.h"

extern PID angle_pid, speed_pid;

extern float pit, rol, yaw;
extern int16_t gyr_x, gyr_y, gyr_z;

extern float angle_pid_output, speed_pid_output;


void UpStand_Init(void);
void UpStand(void);

#endif
