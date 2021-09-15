/*
 * model.hpp
 *
 *  Created on: 2019/07/08
 *      Author: shint
 */

#ifndef MODEL_MODEL_HPP_
#define MODEL_MODEL_HPP_
#define pi 3.14159265358979f
#include "main.h"

class model {
public:
	model(){};
	void TAIYA4(float Vx,float Vy,float th,float w);

	short int V1=0;
	short int V2=0;
	short int V3=0;
	short int V4=0;
};

#endif /* MODEL_MODEL_HPP_ */
