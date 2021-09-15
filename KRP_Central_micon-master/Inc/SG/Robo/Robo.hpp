/*
 * Robo.hpp
 *
 *  Created on: 2019/08/20
 *      Author: shint
 */

#ifndef ROBO_ROBO_HPP_
#define ROBO_ROBO_HPP_
#include "../Inc/Libraries/LowlayerHandel.hpp"
#include "SG/bezier/bezier.hpp"
#include "SG/model/model.hpp"
#include "SG/PID/PID.hpp"

class Robo {
	public:
		Robo(LowlayerHandelTypedef *phlow);

		void set_status(float kp, float ki, float kd);
		void GHQ(float now_x, float now_y, float now_th, float now_w,float goal_x, float goal_y, float goal_th, float goal_w);

		float pid_x_value=0;
		float pid_y_value=0;
		float pid_th_value=0;
		float pid_w_value=0;

		PID pid_x;
		PID pid_y;
		PID pid_th;
		PID pid_w;
		model  model_instance;

	private:
		LowlayerHandelTypedef *hlow;
		//bezier bezier_instance;
};

#endif /* ROBO_ROBO_HPP_ */
