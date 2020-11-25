#pragma once
#ifndef _WALL_H_
#define _WALL_H_
//---------------------------
//�C���N���[�h�t�@�C��
//---------------------------
#include "main.h"

//---------------------------
//�}�N����`
//---------------------------
#define MAX_WALL (64)	//�ǂ̍ő吔
#define WALL_X (1.0f)	//�ǂ̕�
#define WALL_Y (1.0f)	//�ǂ̍���

//---------------------------
//�\����
//---------------------------
typedef struct 
{
	D3DXVECTOR3	PosWall;		//�ʒu
	D3DXVECTOR3 RotWall;		//����
	D3DXMATRIX mtxWoldWall;		//���[���h�}�g���b�N�X
	float fWidth;				//��
	float fHeiht;				//����
	int nIdex;					//�e�̔ԍ�
	bool bUse;					//�g���Ă邩�ǂ���
} Wall;

//---------------------------
//�v���g�^�C�v�錾
//---------------------------
HRESULT InitWall(void);
void UninitWall(void);
void UpdateWall(void);
void DrawWall(void);
void SetWall(D3DXVECTOR3 RotWall, D3DXVECTOR3 PosWall, float fWith, float fHeight);	//�ʒu�A����
#endif