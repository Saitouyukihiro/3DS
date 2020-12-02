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
#define MAX_FIELD (4)		//���b�V���t�B�[���h�̐�
#define MAX_TEX (1)			//�e�N�X�`���̐�
#define MS_FLOO_X (1.0f)	//���̔��aX
#define MS_FLOO_Z (1.0f)	//���̔��aZ
#define MAX_VTX_X (4)		//���u���b�N�̐�
#define MAX_VTX_Z (4)		//�c�u���b�N�̐�
#define VTX_NUM_MAX ((MAX_VTX_X + 1) * (MAX_VTX_Z + 1))				//�S�̒��_�̐�
#define POLY_NUM (2 * MAX_VTX_X * MAX_VTX_Z + (MAX_VTX_Z * 4) - 4))	//���̐�
#define IDX_NUM ((MAX_VTX_X + 1) * (MAX_VTX_Z + 1) + (MAX_VTX_Z - 1) * (MAX_VTX_X + 3))	//�C���f�b�N�X�̐�

//---------------------------
//�񋓌^
//---------------------------
typedef enum
{
	STATE_FLOO = 0,		//���`
	STATE_MAX			//���X�g�̐�
} MESH_STATE;

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
	float fDepht;			//���s
	MESH_STATE aState;		//�ǂ�Ȍ`
	int nTex;				//�e�N�X�`��
	bool bUse;				//�g���Ă邩
} Field;
//---------------------------
//�v���g�^�C�v�錾
//---------------------------
HRESULT InitMeshfield(void);
void UninitMeshfield(void);
void UpdateMeshfield(void);
void DrawMeshfield(void);
void SetField(D3DXVECTOR3 rot, D3DXVECTOR3 pos, float fWidth, float fHeight, float fDepht, int nTex, MESH_STATE aState);	//�����A�ʒu�A���A�����A���s�A�e�N�X�`���A�`
bool ColisionFeild(D3DXVECTOR3 *pos, D3DXVECTOR3 *posold, D3DXVECTOR3 *move, float fWidth, float fHeight, float fDepht, int nType);	//�ʒu�A�O��̈ʒu�A�ړ��ʁA���A�����A���s�A���
#endif