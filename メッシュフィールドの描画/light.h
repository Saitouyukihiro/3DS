#pragma once
#ifndef _LIGHT_H_
#define _LIGHT_H_
//---------------------------
//�C���N���[�h�t�@�C��
//---------------------------
#include "main.h"

//---------------------------
//�}�N����`
//---------------------------
#define MAX_LIGHT (3)			//���C�g�̐�
#define LIGHT_MOVE_SPEED (1.0f)	//���C�g�̈ړ��X�s�[�h

//---------------------------
//�\����
//---------------------------
typedef struct 
{
	bool bUse;		//�ǂ���g���Ă邩
	bool bSelect;	//���Ă邩�����Ă邩
	D3DXVECTOR3 Rot;
} LightSelect;

//---------------------------
//�v���g�^�C�v�錾
//---------------------------
HRESULT InitLight(void);
void UninitLight(void);
void UpdateLight(void);
void LightInfo(void);
void LightTxt(void);
D3DLIGHT9 *GetLight(void);
LightSelect *GetLightSelect(void);
#endif