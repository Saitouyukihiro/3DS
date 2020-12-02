//---------------------------
//�C���N���[�h�t�@�C��
//---------------------------
#include <stdio.h>
#include "model.h"
#include "keyinput.h"
#include "camara.h"
#include "mouseinput.h"
#include "shadow.h"
#include "bullet.h"

//---------------------------
//�O���[�o���ϐ�
//---------------------------
LPD3DXMESH				g_pMeshModel = NULL;		//���b�V���̃|�C���^
LPD3DXBUFFER			g_pBuffMatModel = NULL;		//�}�e���A���̃|�C���^
DWORD					g_pnNumMatModel = 0;		//�}�e���A���̐�
D3DXVECTOR3				g_PosModel;					//�ʒu
D3DXVECTOR3				g_RotModel;					//����
D3DXMATRIX				g_mtxWoldModel;				//���[���h�}�g���b�N�X
int						g_nIdex;					//�e�̔ԍ�
Model					g_aModel;					//���f���̍\����

//---------------------------
//�O���[�o���ϐ�
//---------------------------
HRESULT InitModel(void)
{
	LPDIRECT3DDEVICE9	pDevice;	//�f�o�C�X�ւ̃|�C���^

	pDevice = GetDevice();			//�f�o�C�X�̎擾

	//---------------------------
	//X�t�@�C���̓ǂݍ���
	//---------------------------
	D3DXLoadMeshFromX(	"data/Model/guys.x",
						D3DXMESH_SYSTEMMEM,
						pDevice,
						NULL,
						&g_pBuffMatModel,
						NULL,
						&g_pnNumMatModel,
						&g_pMeshModel);
	//�ʒu����������
	g_PosModel = (D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	g_RotModel = (D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	g_nIdex = 0;

	g_nIdex = SetShadow(g_PosModel, 50.0f, 50.0f);

	return S_OK;
}

//---------------------------
//�I������
//---------------------------
void UninitModel(void)
{
	//---------------------------
	//���b�V���j��
	//---------------------------
	if (g_pMeshModel != NULL)
	{
		g_pMeshModel->Release();
		g_pMeshModel = NULL;
	}

	//---------------------------
	//�}�e���A���j��
	//---------------------------
	if (g_pBuffMatModel != NULL)
	{
		g_pBuffMatModel->Release();
		g_pBuffMatModel = NULL;
	}
}

//---------------------------
//�X�V����
//---------------------------
void UpdateModel(void)
{
	Camera *pCamera;		//�J�����̍\���̂̃|�C���^
	Camera *p0Camera;		//0�ԃJ����
	static int nSpan;		//�N�[���^�C��

	pCamera = GetCamera();	//�J�����̏����擾
	p0Camera = GetCamera();	//0�ԃJ����

	//---------------------------
	//�l�����ړ���
	//---------------------------
	for (int nCntCamera = 0; nCntCamera < MAX_CAMERA; nCntCamera++, pCamera++)
	{
		if (pCamera->bUse == true)
		{
			if (GetKeyboardPress(DIK_W) == true)
			{
				g_PosModel.x = g_PosModel.x + sinf(pCamera->Rot.y) * CAMERA_MOVE_SPEED;
				g_PosModel.z = g_PosModel.z + cosf(pCamera->Rot.y) * CAMERA_MOVE_SPEED;

				//�J�����̌����ɓ]��
				g_RotModel.y = pCamera->Rot.y + -D3DX_PI;

				//0�Ԃ̃J�����ǔ�
				p0Camera->PosV.x = g_PosModel.x;
				p0Camera->PosV.y = g_PosModel.y + 25.0f;
				p0Camera->PosV.z = g_PosModel.z + 2.0f;
			}
			if (GetKeyboardPress(DIK_S) == true)
			{
				g_PosModel.x = g_PosModel.x - sinf(pCamera->Rot.y) * CAMERA_MOVE_SPEED;
				g_PosModel.z = g_PosModel.z - cosf(pCamera->Rot.y) * CAMERA_MOVE_SPEED;

				//�J�����̌����ɓ]��
				g_RotModel.y = pCamera->Rot.y;

				//0�Ԃ̃J�����ǔ�
				p0Camera->PosV.x = g_PosModel.x;
				p0Camera->PosV.y = g_PosModel.y + 25.0f;
				p0Camera->PosV.z = g_PosModel.z - 2.0f;
			}
			if (GetKeyboardPress(DIK_A) == true)
			{
				g_PosModel.x = g_PosModel.x - cosf(pCamera->Rot.y) * CAMERA_MOVE_SPEED;
				g_PosModel.z = g_PosModel.z + sinf(pCamera->Rot.y) * CAMERA_MOVE_SPEED;

				//�J�����̌����ɓ]��
				g_RotModel.y = pCamera->Rot.y + D3DX_PI / 2;

				//0�Ԃ̃J�����ǔ�
				p0Camera->PosV.x = g_PosModel.x - 2.0f;
				p0Camera->PosV.y = g_PosModel.y + 25.0f;
				p0Camera->PosV.z = g_PosModel.z;
			}
			if (GetKeyboardPress(DIK_D) == true)
			{
				g_PosModel.x = g_PosModel.x + cosf(pCamera->Rot.y) * CAMERA_MOVE_SPEED;
				g_PosModel.z = g_PosModel.z - sinf(pCamera->Rot.y) * CAMERA_MOVE_SPEED;

				//�J�����̌����ɓ]��
				g_RotModel.y = pCamera->Rot.y + -D3DX_PI / 2;

				//0�Ԃ̃J�����ǔ�
				p0Camera->PosV.x = g_PosModel.x + 2.0f;
				p0Camera->PosV.y = g_PosModel.y + 25.0f;
				p0Camera->PosV.z = g_PosModel.z;
			}
			if (GetKeyboardPress(DIK_I) == true)
			{
				g_PosModel.y += 1.0f;
			}
			if (GetKeyboardPress(DIK_K) == true)
			{
				g_PosModel.y -= 1.0f;
			}
		}
	}
	pCamera-= MAX_CAMERA;

	//---------------------------
	//���Z�b�g
	//---------------------------
	if (GetKeyboardPress(DIK_RETURN) == true)
	{
		g_PosModel = (D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		g_RotModel = (D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	}
	//---------------------------
	//�e�̔���
	//---------------------------
	nSpan++;
	if (GetKeyboardPress(DIK_Q) == true && nSpan > BULLET_SPAN)
	{
		SetBullet(g_PosModel, D3DXVECTOR3(0.0f, p0Camera->Rot.y, 0.0f), 25.0f, 25.0f, 0);
		nSpan = 0;
	}

	//�����̉e
	SetPointShadow(g_nIdex, g_PosModel, 50.0f, 50.0f);
}

//---------------------------
//�`�揈��
//---------------------------
void DrawModel(void)
{
	LPDIRECT3DDEVICE9	pDevice;			//�f�o�C�X�̃|�C���^

	pDevice = GetDevice();					//�f�o�C�X���擾����

	//---------------------------
	//�}�g���b�N�X�̐ݒ�
	//---------------------------
	D3DXMATRIX			mtxRot, mtxTrans;	//�v�Z�p�}�g���b�N�X

	D3DXMatrixIdentity(&g_mtxWoldModel);	//�}�g���b�N�X������

	//�����̐ݒ�
	D3DXMatrixRotationYawPitchRoll(	&mtxRot,
									g_RotModel.y,
									g_RotModel.x,
									g_RotModel.z);

	D3DXMatrixMultiply(	&g_mtxWoldModel,
						&g_mtxWoldModel,
						&mtxRot);
	//�ʒu
	D3DXMatrixTranslation(	&mtxTrans,
							g_PosModel.x,
							g_PosModel.y,
							g_PosModel.z);

	D3DXMatrixMultiply(	&g_mtxWoldModel,
						&g_mtxWoldModel,
						&mtxTrans);
	//�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(	D3DTS_WORLD,
							&g_mtxWoldModel);
	//---------------------------
	//�`�揈��
	//---------------------------
	D3DMATERIAL9		matDef;				//�}�e���A���̈ꎞ�ۑ�
	D3DXMATERIAL		*pMat;				//�}�e���A���f�[�^�̃|�C���^

	//���݂̃}�e���A�����擾
	pDevice->GetMaterial(&matDef);

	//�}�e���A���f�[�^�̃|�C���^
	pMat = (D3DXMATERIAL*)g_pBuffMatModel->GetBufferPointer();

	for (int nCntMat = 0; nCntMat < (int)g_pnNumMatModel; nCntMat++)
	{
		//�}�e���A���̐ݒ�
		pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

		//�e�N�X�`���̐ݒ�
		pDevice->SetTexture(0,
							NULL);

		//���f���p�[�c�̕`��
		g_pMeshModel->DrawSubset(nCntMat);
	}
	//�ꎞ�ۑ����Ă�������ǂ�
	pDevice->SetMaterial(&matDef);
}

//---------------------------
//���f�����擾
//---------------------------
Model *GetModel(void)
{
	return &g_aModel;
}