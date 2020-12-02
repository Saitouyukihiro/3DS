#pragma once
#ifndef _BULLET_H_
#define _BULLET_H_

//---------------------------
//�C���N���[�h�t�@�C��
//---------------------------
#include "main.h"

//---------------------------
//�}�N����`
//---------------------------
#define BULLET_X (1.0f)	//�ʃT�C�YX���a
#define BULLET_Y (1.0f)	//�ʃT�C�YY���a
#define BULLET_MOVE_SPEED (5.0f)	//�e�̃X�s�[�h
#define MAX_BULLET (256)			//�ʂ̍ő吔
#define BULLET_SPAN (10)			//�e�̃N�[���^�C��
#define MAX_TEX (1)					//�e�N�X�`���̐�

//---------------------------
//�\���̂̒�`
//---------------------------
typedef struct
{
	D3DXVECTOR3	Pos;		//�ʒu
	D3DXVECTOR3 Move;		//�ړ���
	D3DXVECTOR3 rot;		//�e�̕���
	D3DXMATRIX mtxWold;		//���[���h�}�g���b�N�X
	D3DXMATRIX mtxView;		//�J�����̌���
	float fWidth;			//��
	float fHeight;			//����
	int nIdex;				//�e�̔ԍ�
	int nType;				//���
	bool bUse;				//�g���Ă邩�ǂ���
} Bullet;
//---------------------------
//�v���g�^�C�v�錾
//---------------------------
HRESULT InitBullet(void);
void UninitBullet(void);
void UpdateBullet(void);
void DrawBullet(void);
void SetBullet(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float fWidth, float fHeight, int nType);	//�ʒu�A�����Ă�����A���A�����A���
Bullet *GetBullet(void);
#endif 
