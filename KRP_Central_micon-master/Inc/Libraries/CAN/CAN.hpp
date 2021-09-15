/*
 * CAN.hpp
 *
 *  Created on: 2018/12/28
 *      Author: �T��
 */

#ifndef CAN_CAN_HPP_
#define CAN_CAN_HPP_

#include "stm32f4xx_hal.h"

class CanBus
{

	uint8_t TX_BUF[8] = {
		0,
	};
	bool Txok = false;
	bool error_flag = false;
	bool txend = false;
	int error_code = 0;
	unsigned long IDE;
	unsigned long RTR;
	int txled = 0;

	void SetError();

public:
	CanBus(unsigned long _IDE, unsigned long _RTR) : IDE(_IDE), RTR(_RTR)
	{
	}
	short Send(unsigned long ID, unsigned char DLC, unsigned char *data);
};

#endif /* CAN_CAN_HPP_ */
