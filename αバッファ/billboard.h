#pragma once
#ifndef _BILLBOARD_H_
#define _BILLBOARD_H_
//---------------------------
//�C���N���[�h�t�@�C��
//---------------------------
#include "main.h"

//---------------------------
//�}�N����`
//---------------------------
#define MAX_BILLBOARD (64)	//�r���{�[�h�̍ő吔
#define BILLBOARD_X (1.0f)		//�r���{�[�h�̕�
#define BILLBOARD_Y (1.0f)		//�r���{�[�h�̍���

//---------------------------
//�\����
//---------------------------
typedef struct
{
	D3DXVECTOR3	Pos;		//�ʒu
	D3DXVECTOR3 Move;		//�ړ���
	D3DXMATRIX mtxWold;		//���[���h�}�g���b�N�X
	D3DXMATRIX mtxView;		//�J�����̌���
	float fWidth;			//��
	float fHeiht;			//����
	int nIdex;				//�e�̔ԍ�
	bool bUse;				//�g���Ă邩�ǂ���
} Billboard;

//---------------------------
//�v���g�^�C�v�錾
//---------------------------
HRESULT InitBillboard(void);
void UninitBillboard(void);
void UpdateBillboard(void);
void DrawBillboard(void);
void SetBillboard(D3DXVECTOR3 pos, float fWidth, float fHeight);
#endif