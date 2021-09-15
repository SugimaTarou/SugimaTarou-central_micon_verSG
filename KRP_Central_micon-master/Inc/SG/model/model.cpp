/*
 * model.cpp
 *
 *  Created on: 2019/07/08
 *      Author: shint
 */

#include "model.hpp"
#include <math.h>
#include "stdio.h"

void model::TAIYA4(float Vx, float Vy, float th, float w)/*���݂̊p�x,x�������ւ̑����,y�������ւ̑����,���݂̊p���x*/
{
 	V1=  ( sin( th+ (pi/4) ) )*Vx 	+ ( cos ( th+ (pi/4) ) )*Vy		+0.365*w;
	V2=  ( sin( th- (pi/4) ) )*Vx 	+ ( cos ( th- (pi/4) ) )*Vy		+0.365*w;
	V3= -( sin( th+ (pi/4) ) )*Vx 	- ( cos ( th+ (pi/4) ) )*Vy		+0.365*w;
	V4= -( sin( th- (pi/4) ) )*Vx 	- ( cos ( th- (pi/4) ) )*Vy		+0.365*w;

	V1=roundf(V1);
	V2=roundf(V2);
	V3=roundf(V3);
	V4=roundf(V4);

	printf("V1: %d, V2: %d, V3: %d V4: %d   \n\r,",  V1,V2,V3,V4);
}
