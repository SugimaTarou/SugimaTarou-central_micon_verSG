/*
 * bezier.hpp
 *
 *  Created on: 2019/07/08
 *      Author: shint
 */

#ifndef BEZIER_BEZIER_HPP_
#define BEZIER_BEZIER_HPP_

class bezier {
	public:
		bezier();
		virtual ~bezier();

		float field_x0=0;
		float field_y0=0;
		float field_x1=0;
		float field_y1=0;
		float field_x2=0;
		float field_y2=0;
		void O();
		void A();
		void B();
		short int t=0;

	private:
		float p_x0[4]={0,1.5,1.5,1.5};
		float p_y0[4]={0,0,0,1.5};

		float p_x1[3]={-1181,-1255,-2035};//���̒l1572,1545,688 ���_2807,267
		float p_y1[3]={626,21,130};//���̒l770,246,270�@���_267

		float p_x2[4]={1158,-124,-508,-508};
		float p_y2[4]={151,186,775,1447};
	};
#endif /* BEZIER_BEZIER_HPP_ */
