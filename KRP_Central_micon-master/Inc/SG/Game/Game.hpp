/*
 * Game.hpp
 *
 *  Created on: 2019/04/07
 *      Author: shint
 */

#ifndef GAME_GAME_HPP_
#define GAME_GAME_HPP_
#include "../Inc/Libraries/LowlayerHandel.hpp"
#include"SG/Robo/Robo.hpp"
#include "SG/bezier/bezier.hpp"

#include <stdio.h>

class Game{
	public:
		Game(LowlayerHandelTypedef *hlow);
		void test(float x,float y, float th,float cg);

	private:
		LowlayerHandelTypedef *phlow;
};
#endif /* GAME_GAME_HPP_ */
