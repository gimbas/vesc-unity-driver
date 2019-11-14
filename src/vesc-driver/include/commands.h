#ifndef COMM_H_
#define COMM_H_

#include <errno.h>
#include <fcntl.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

#include "buffer.h"
#include "crc.h"
#include "datatypes.h"
#include "pack.h"

#include "commands.h"
/*
void auto_set_Current(float current1, float current2);
void auto_set_Position(float position1, float position2);
void auto_set_Duty(float duty1, float duty2);
void auto_set_RPM(float rpm1, float rpm2);
void auto_set_CurrentBrake(float brakeCurrent1, float brakeCurrent2);
*/
//void AutoGetValues();
/*
void VescLegacySetCurrent(float current);
void VescLegacySetPosition(float position);
void VescLegacySetDuty(float duty);
void VescLegacySetRPM(float rpm);
void VescLegacySetCurrentBrake(float brakeCurrent);

void VescSetCurrent(float current);
void VescSetPosition(float position);
void VescSetDuty(float duty);
void VescSetRPM(float rpm);
void VescSetCurrentBrake(float brakeCurrent);
*/

void vesc_get_version();

void unity_set_current(float current1, float current2);
void unity_set_position(float position1, float position2);
void unity_set_duty(float duty1, float duty2);
void unity_set_rpm(float rpm1, float rpm2);
void unity_set_currentBrake(float brakeCurrent1, float brakeCurrent2);

#endif /* COMM_H */