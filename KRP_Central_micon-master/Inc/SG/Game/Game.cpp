/*
 * TestStraight.cpp
 *
 *  Created on: 2019/04/06
 *      Author: shint
 */

#include "Game.hpp"
#include <stdio.h>

Game::Game(LowlayerHandelTypedef *hlow) {
	this->phlow=hlow;
}

void Game::test(float x,float y, float th, float cg){
	//rintf("x :%f ,y :%f \n\r,",x ,y );

	bezier bezier_instance();
	Robo robo_instance(phlow);
	robo_instance.GHQ( x, y, th,0,  0,0,0,0);//X,Y,TH,W
	}
