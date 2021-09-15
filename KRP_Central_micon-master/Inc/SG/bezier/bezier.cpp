/*
 * bezier.cpp
 *
 *  Created on: 2019/07/08
 *      Author: shint
 */

#include "bezier.hpp"
#include"math.h"

bezier::bezier() {
	// TODO Auto-generated constructor stub

}

bezier::~bezier() {
	// TODO Auto-generated destructor stub
}
	void bezier::O(){
		t=t+0.005;

		if(t<=1){
			field_x0 =(1-t)*(1-t)*p_x0[0] + 2*(1-t)*t*p_x0[1] + t*t*p_x0[2];
			field_y0 = ((1-t)*(1-t)*p_y0[0] + 2*(1-t)*t*p_y0[1] + t*t*p_y0[2]);
		}
		if(t>=1){
			t=0;
		}
	}
	void bezier::A(){
		if(t<=1)
		{
			field_x1 =(1-t)*(1-t)*p_x1[0] + 2*(1-t)*t*p_x1[1] + t*t*p_x1[2];
			field_y1 = ((1-t)*(1-t)*p_y1[0] + 2*(1-t)*t*p_y1[1] + t*t*p_y1[2]);
		}
		if(t>=1){
		t=1;
		}
	}
	void bezier::B(){
		if(t<=1){
			field_x2=(1-t)*(1-t)*(1-t)*p_x2[0] + 3*(1-t)*(1-t)*t*p_x2[1] + 3*(1-t)*t*t*p_x2[2] + t*t*t*p_x2[3];
			field_y2=(1-t)*(1-t)*(1-t)*p_y2[0] + 3*(1-t)*(1-t)*t*p_y2[1] + 3*(1-t)*t*t*p_y2[2] + t*t*t*p_y2[3];
		}
		if(t>=1){
		t=0;
		}
	}
