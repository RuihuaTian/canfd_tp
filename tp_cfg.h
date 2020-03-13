#ifndef _TP_CFG_H
#define _TP_CFG_H

#include "can_tp.h"

typedef struct{
	int32_t timeout_as;
	int32_t timeout_ar;
	int32_t timeout_bs;
	int32_t timeout_br;
	int32_t timeout_cs;
	int32_t timeout_cr;
}tp_time_config;

typedef struct{
	uint8_t msg_type;//��Ϣ���ͣ���ϻ�Զ�����
	uint8_t address_type;//Ѱַ���ͣ���Ϣ����=��� normal��extend����Ϣ����=Զ������ǣ�ֻ��ֵΪmixed
	tp_address_info ai;//��ַ��Ϣ����ַ���ͣ�Դ��ַ��Ŀ�ĵ�ַ
	uint8_t broadcast_address;//�㲥��ַ��������Ѱַ�����TA
	uint8_t tx_dl;//������·�㳤�ȣ���CAN���ĵĳ��ȣ�������8 12 16 20 24 32 48 64
	uint8_t stmin_on_rx;//��������ʱ��CF֡�����С���ʱ�䣬�Ժ���Ϊ��λ
	uint8_t bs_on_rx;//��������ʱ��BS��С
	uint8_t enable_padding;//�Ƿ��������������䣬0:��ֹ��1��ʹ���������
	uint8_t padding_bytes;//ʹ���������ʱ�������ֽ�
	uint8_t max_fc_wait_times;//��������ʱ����������ΪWAIT��������֡�ĸ���
	tp_time_config timing;
}tp_config_type;

#define TP_TASK_PEROID			1//peroid in mill second

const tp_config_type tp_cfgs[] = {
	{
		DIAGNOSTIC,
		NORMAL_ADDRESS,
		{
			0x12,
			0x10,
			CANFD_PHY,
			0x00,
		},
		0xDF,
		32,
		1,
		8,
		1,
		0xAA,
		5,
		{
			1000,
			1000,
			1000,
			1000,
			1000,
			1000,
		},
	},
	{
		DIAGNOSTIC,
		NORMAL_ADDRESS,
		{
			0x10,
			0x12,
			CANFD_PHY,
			0x00,
		},
		0xDF,
		24,
		1,
		4,
		1,
		0xCC,
		5,
		{
			1000,
			1000,
			1000,
			1000,
			1000,
			1000,
		},
	},
};

#define TP_ENTITY_NUM			(sizeof(tp_cfgs)/sizeof(tp_config_type))//TP���ʾ����Ŀ

#define LOOP_BACK_TEST			1//�Ƿ�ʹ�ܲ��ԣ�1��ʹ�ܻ��ز��ԣ���ʱ���� λ������ʵ����һ������һ������

#define DATA_BUFFER_SIZE		5000//��󻺴��С����ʾUDS�������Ӧ����󳤶ȣ�ÿ��ʵ����һ��

/*==============================================================================*/

#endif