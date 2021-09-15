/*
 * PID.cpp
 *
 *  Created on: 2019/07/08
 *      Author: shint
 */

#include "PID.hpp"
#include <stdio.h>

void PID::Init(float kp, float ki, float kd) {
	KP = kp;
	KI = ki;
	KD = kd;
}

float PID::UpdateError(float goal_potision, float now_potision) {
	i_0 = i_1;
	i_1 = goal_potision - now_potision;
	integral =( integral +( (i_0 + i_1) *0.005) )/ 2;

	while(dt==1){
		dt=dt+0.005;
	}
	if(dt>=1){
		dt=0;
		integral=0;
	}

	A= ( KP * i_1 ) + ( KI * integral ) +  KD * ( ( (i_1 - i_0) ) / 0.005 );
	return A;
	//printf("%f\n\r,",  A  );
}
