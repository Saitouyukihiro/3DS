#pragma once
#ifndef _SHADOW_H_
#define _SHADOW_H_
//---------------------------
//�C���N���[�h�t�@�C��
//---------------------------
#include "main.h"

//---------------------------
//�}�N����`
//---------------------------
#define MAX_SHADOW (256)	//�e�̍ő吔
#define SHADOW_X (1.0f)		//�e��X
#define SHADOW_Z (1.0f)		//�e��Y

//---------------------------
//�\����
//---------------------------
typedef struct
{
	D3DXMATRIX mtxWorld;	//���[���h�}�g���b�N�X
	D3DXVECTOR3 pos;		//�ʒu
	D3DXVECTOR3 rot;		//����
	float fWhith;			//��
	float fHeiht;			//����
	float fDepht;			//���s
	float fAlpha;			//��
	int Index;				//�e�̔ԍ�
	bool bUse;				//�g���Ă邩�ǂ���
} Shadow;

//---------------------------
//�v���g�^�C�v�錾
//---------------------------
HRESULT InitShadow(void);
void UninitShadow(void);
void UpdateShadow(void);
void DrawShadow(void);
int SetShadow(D3DXVECTOR3 pos, float fWhith, float fDepht);	//�ʒu�A���A����
void SetPointShadow(int nIdx, D3DXVECTOR3 pos, float fWhith, float fDepht);	//�g���Ă�e�̔ԍ��A�ʒu
#endif