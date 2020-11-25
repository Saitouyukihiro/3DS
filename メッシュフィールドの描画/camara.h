#pragma once
#ifndef _CAMERA_H_
#define _CAMERA_H_

//---------------------------
//�C���N���[�h�t�@�C��
//---------------------------
#include "main.h"

//---------------------------
//�}�N����`
//---------------------------
#define CAMERA_DESTAANCE (200)		//�J�����ƒ����_�̋���
#define CAMERA_MOVE_SPEED (10.0f)	//�J�����̈ړ���
#define MAX_CAMERA (3)				//�J�����̍ő吔

//---------------------------
//�\����
//---------------------------
typedef struct
{
	D3DXVECTOR3 PosV;			//���_
	D3DXVECTOR3 PosR;			//�����_
	D3DXVECTOR3 Rot;			//�J�����̌���
	D3DXVECTOR3 VecU;			//������x�N�g��
	D3DXMATRIX mtxProjection;	//�v���W�F�N�V�����}�g���b�N�X
	D3DXMATRIX mtxView;			//�r���[�}�g���b�N�X
	POINT Pointer;				//�}�E�X�̈ʒu
	POINT Poiold;				//�}�E�X�̑O��̈ʒu
	POINT Poimove;				//�}�E�X�̈ړ���
	float Long;					//��
	bool bUse;					//�ǂ̃J������
} Camera;

//---------------------------
//�v���g�^�C�v�錾
//---------------------------
HRESULT InitCamera(void);
void UninitCamera(void);
void UpdateCamera(void);
void SetCamera(void);
void DrawCmTxt(void);
void DrawCmInfo(void);
Camera *GetCamera(void);
#endif