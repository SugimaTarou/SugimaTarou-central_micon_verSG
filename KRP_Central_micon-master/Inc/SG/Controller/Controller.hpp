/*
 * Controller.hpp
 *
 *  Created on: 2020/01/28
 *      Author: shint
 */

#ifndef SG_CONTROLLER_CONTROLLER_HPP_
#define SG_CONTROLLER_CONTROLLER_HPP_
#include "../Inc/Libraries/LowlayerHandel.hpp"

class Controller {
public:
	Controller(LowlayerHandelTypedef *hlow);
	void Controller_chain(int X,int Y,float F,float R);

	int XX;
	int YY=0;
	int FF=0;
	int RR=0;

private:
	LowlayerHandelTypedef *phlow;
};

#endif /* SG_CONTROLLER_CONTROLLER_HPP_ */
