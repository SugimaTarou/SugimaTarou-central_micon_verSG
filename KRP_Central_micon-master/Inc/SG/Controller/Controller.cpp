/*
 * Controller.cpp
 *
 *  Created on: 2020/01/28
 *      Author: shint
 */

#include <SG/Controller/Controller.hpp>
#include <stdio.h>

Controller::Controller(LowlayerHandelTypedef *hlow) {
	phlow=hlow;
}

void Controller::Controller_chain(int X,int Y,float F,float R){

	XX= (X)-(135);
	YY=(Y)-(135);
	if( XX >= -20 && XX <= 20 ){
		XX=0;
	 }
		if(XX>=80){
			XX=80;
		}
		if(XX<=-80){
			XX=-80;
		}
	if( YY >= -20 && YY <= 20 ){
		YY=0;
	}
		if(YY>=100){
			YY=80;
		}
		if(YY<=-100){
		YY=-80;
		}
	F=((F/255)*100);
		if(F>=80){
			F=90;
		}
		if(F<=10){
			F=0;
		}
	FF=F;

	R=((R/255)*100);
		if(R>=90){
			R=85;
		}
		if(R<=10){
			R=0;
		}
	RR=R;
	 phlow->M5.SetDuty(FF);
				//printf("RR b=,%d\n\r,", RR);
}
