/*
 * CAN.cpp
 *
 *  Created on: 2018/12/28
 *      Author: �T��
 */

#include "CAN.hpp"
#include "can.h"
#include "stdio.h"
#include "Libraries/LowlayerHandel.hpp"
#include "Libraries/DefineLED.h"
unsigned char RxFIFO_Data[8];
CAN_RxHeaderTypeDef RXmsg;
bool CanRxFlag = false;
extern LowlayerHandelTypedef *plow;

#define MASKID_L 0x0000
#define FILTERID_L 0x0000

int Fulllevel = 0;

int rx_led = 0;

void FilterConfig()
{
	CAN_FilterTypeDef sFilterConfig;
	sFilterConfig.FilterIdHigh = 0x0000;
	sFilterConfig.FilterIdLow = FILTERID_L;
	sFilterConfig.FilterMaskIdHigh = 0x0000;
	sFilterConfig.FilterMaskIdLow = MASKID_L;
	sFilterConfig.FilterFIFOAssignment = CAN_FILTER_FIFO0; //��M�t�B���^��FIFO0�ɐݒ�
	sFilterConfig.FilterBank = 0;						   //�t�B���^�o���N�ԍ���� 0-13
	sFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;	   //�t�B���^�X�P�[��ExtId�܂�
	sFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;	   //�}�X�N���[�h
	sFilterConfig.FilterActivation = ENABLE;			   //�t�B���^�L��
														   //	sFilterConfig.SlaveStartFilterBank=14;

	if (HAL_CAN_ConfigFilter(&hcan1, &sFilterConfig) != HAL_OK)
	{
		printf("filter config error!");
	}
	HAL_CAN_Start(&hcan1);
	HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO0_MSG_PENDING);
}

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
	HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &RXmsg, RxFIFO_Data);
	CanRxFlag = true;
	plow->Ad1.SetData();
	plow->Msw1.SetData();
	plow->loca.Setloca();
	plow->encoder1.SetData();
	if (rx_led > 20)
	{
		TOGGLE_RX_LED;
		rx_led = 0;
	}
	else
	{
		rx_led++;
	}
}
void HAL_CAN_RxFifo0FullCallback(CAN_HandleTypeDef *hcan)
{
}

void HAL_CAN_RxFifo1MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
}
#define ERROCODE_Pos 0b111 << 4
#define ERRORPUSSIVE_pos 1 << 1
void CanBus::SetError()
{
	error_code = (hcan1.Instance->ESR) & ERROCODE_Pos;
	if ((hcan1.Instance->ESR) & ERRORPUSSIVE_pos)
	{
	}
}

short CanBus::Send(unsigned long ID, unsigned char DLC, unsigned char *data)
{
	uint32_t mailbox_num;
	HAL_CAN_StateTypeDef state = hcan1.State;
	uint32_t TSR = hcan1.Instance->TSR;
	if ((state == HAL_CAN_STATE_READY) || (state == HAL_CAN_STATE_LISTENING))
	{
		if (((TSR & CAN_TSR_TME0) != 0U) || ((TSR & CAN_TSR_TME1) != 0U) || ((TSR & CAN_TSR_TME2) != 0U)) //�ǂꂩ�̃��[���{�b�N�X���󂢂Ă�����
		{

			mailbox_num = (TSR & CAN_TSR_CODE) >> CAN_TSR_CODE_Pos; //�󂫃��[���{�b�N�X�ԍ����擾
			if (mailbox_num > 2)
			{
				/* Update error code */
				hcan1.ErrorCode |= HAL_CAN_ERROR_INTERNAL;
				error_flag = true;
				this->SetError();
				return -3;
			}

			if (this->IDE == CAN_ID_STD)
			{
				hcan1.Instance->sTxMailBox[mailbox_num].TIR = ID << 21 | this->RTR;
			}
			else //ext id
			{
				hcan1.Instance->sTxMailBox[mailbox_num].TIR = ID << 3U | IDE | RTR;
			}
			hcan1.Instance->sTxMailBox[mailbox_num].TDTR = DLC;
			hcan1.Instance->sTxMailBox[mailbox_num].TDHR = (uint32_t)data[7] << 24 | (uint32_t)data[6] << 16 | (uint32_t)data[5] << 8 | (uint32_t)data[4]; //���[���{�b�N�X��ʃ��W�X�^�ɃZ�b�g
			hcan1.Instance->sTxMailBox[mailbox_num].TDLR = (uint32_t)data[3] << 24 | (uint32_t)data[2] << 16 | (uint32_t)data[1] << 8 | (uint32_t)data[0];
			hcan1.Instance->sTxMailBox[mailbox_num].TIR |= 1; //���M�r�b�g�Z�b�g
			return 0;
		}
		else
		{ //���[���{�b�N�X�̂ǂ���󂢂ĂȂ�
			hcan1.ErrorCode |= HAL_CAN_ERROR_PARAM;
			error_flag = true;
			this->SetError();
			return -1;
		}
	}
	else
	{
		hcan1.ErrorCode |= HAL_CAN_ERROR_NOT_INITIALIZED;
		error_flag = true;
		this->SetError();
		return -2;
	}
}
