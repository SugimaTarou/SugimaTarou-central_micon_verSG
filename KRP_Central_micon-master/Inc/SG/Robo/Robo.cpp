/*
 * Robo.cpp
 *
 *  Created on: 2019/08/20
 *      Author: shint
 */

#include "Robo.hpp"
#include <stdio.h>

Robo::Robo(LowlayerHandelTypedef *phlow) {
	// TODO Auto-generated constructor stub
this->hlow=phlow;
}

void Robo::GHQ(float now_x, float now_y, float now_th , float now_w, float goal_x, float goal_y, float goal_th, float goal_w)
{
	this->pid_x.Init(700, 0.00, 0.00);
	this->pid_y.Init(1000, 0.00, 0.00);
	this->pid_w.Init(1000, 0.00, 0.00);

	pid_x_value  =  this->pid_x.UpdateError(goal_x, now_x);
	pid_y_value  =  this->pid_y.UpdateError(goal_y, now_y);
	pid_w_value  =  this->pid_w.UpdateError(goal_th, now_th);

		this->model_instance.TAIYA4(pid_x_value, pid_y_value, now_th, pid_w_value);

		hlow->M1.SetVelocity(this->model_instance.V1);
		hlow->M2.SetVelocity(this->model_instance.V2);
		hlow->M3.SetVelocity(this->model_instance.V3);
		hlow->M4.SetVelocity(this->model_instance.V4);
		//printf("x :%f ,y :%f \n\r,",now_x,now_y);
}
