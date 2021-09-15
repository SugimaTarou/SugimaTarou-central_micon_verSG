/*
 * PID.hpp
 *
 *  Created on: 2019/07/08
 *      Author: shint
 */

#ifndef PID_PID_HPP_
#define PID_PID_HPP_

class PID {
public:
	PID(){};
	void Init(float kp, float ki, float kd);
	float UpdateError(float goal_potision,float now_potision);
	//float difference();

private:
	float KI;
	float KP;
	float KD;
	float i_0;
	float i_1;
	float integral;
	float now_potision;
	float goal_potision;
	float A;
	int dt;
};

#endif /* PID_PID_HPP_ */
