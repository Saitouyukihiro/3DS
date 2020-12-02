#pragma once
#ifndef _MODEL_H_
#define _MODEL_H_
//---------------------------
//�C���N���[�h�t�@�C��
//---------------------------
#include "main.h"

//---------------------------
//�}�N����`
//---------------------------
#define MAX_MODEL (1)

//---------------------------
//�\����
//---------------------------
typedef struct
{
	DWORD pnNumMatModel;		//�}�e���A���̐�
	D3DXVECTOR3 PosModel;			//�ʒu
	D3DXVECTOR3 RotModel;			//����
	D3DXMATRIX mtxWoldModel;		//���[���h�}�g���b�N�X
	int nIdex;						//�e�̔ԍ�
} Model;
//---------------------------
//�v���g�^�C�v�錾
//---------------------------
HRESULT InitModel(void);
void UninitModel(void);
void UpdateModel(void);
void DrawModel(void);
void ModelInfo(void);
Model *GetModel(void);
#endif