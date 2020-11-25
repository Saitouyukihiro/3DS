#pragma once
#ifndef _MESHFIELD_H_
#define _MESHFIELD_H_
//---------------------------
//�C���N���[�h�t�@�C��
//---------------------------
#include "main.h"

//---------------------------
//�}�N����`
//---------------------------
#define MS_FLOO_X (1000)	//����X
#define MS_FLOO_Z (1000)	//����Z

//---------------------------
//�\����
//---------------------------
typedef struct
{
	D3DXVECTOR3	Pos;		//�ʒu
	D3DXVECTOR3 Rot;		//����
	D3DXMATRIX mtxWold;		//���[���h�}�g���b�N�X
	float fWidth;			//��
	float fHeiht;			//����
} Field;
//---------------------------
//�v���g�^�C�v�錾
//---------------------------
HRESULT InitMeshfield(void);
void UninitMeshfield(void);
void UpdateMeshfield(void);
void DrawMeshfield(void);
void SetField(D3DXVECTOR3 pos, float fWidth, float fHeight);	//�ʒu�A���A����
#endif