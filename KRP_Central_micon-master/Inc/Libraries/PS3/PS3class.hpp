/*
 * PS3class.hpp
 *
 *  Created on: 2018/08/20
 *      Author: �T��
 */

#ifndef PS3_PS3CLASS_HPP_
#define PS3_PS3CLASS_HPP_
#include "Libraries/CAN/CAN.hpp"

#define USEI2C
class PS3controller
{
private:
	CanBus *canbus;
	int tx_led = 0;
	short Data[8] = {
		0,
	};
	short Maskbyte(int matrixnum, int shiftnum);
	const unsigned long begincmd = 0x70;
	unsigned long timecount = 0;
	bool beginend = false;
	bool TXok = false;

public:
	PS3controller(CanBus *_canbus) : canbus(_canbus)
	{
	}
	void SetconData();
	void SendRequest();
	void begin();
	short SELECT();
	short L3(); // L3�{�^��
	short R3();
	short START();
	short UP();
	short RIGHT();
	short DOWN();
	short LEFT();
	short L2();
	short R2();
	short L1();
	short R1();
	short SANKAKU();
	short MARU();
	short BATSU();
	short SHIKAKU();
	short ANALOG_RIGHT_X();
	short ANALOG_RIGHT_Y();
	short ANALOG_LEFT_X();
	short ANALOG_LEFT_Y();
};

#endif /* PS3_PS3CLASS_HPP_ */
