//---------------------------
//�C���N���[�h�t�@�C��
//---------------------------
#include <stdio.h>
#include "camara.h"
#include "keyinput.h"
#include "mouseinput.h"
#include "model.h"

//---------------------------
//�O���[�o���ϐ�
//---------------------------
Camera	g_Camera[MAX_CAMERA];	//�J����

//--------------------------- 
//����������
//---------------------------
HRESULT InitCamera(void)
{
	g_Camera[0].PosV = (D3DXVECTOR3(0.0f, 25.0f, 2.0f));
	g_Camera[0].PosR = (D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	g_Camera[0].Rot = (D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	g_Camera[0].VecU = (D3DXVECTOR3(0.0f, 1.0f, 0.0f));
	g_Camera[0].bUse = true;

	g_Camera[1].PosV = (D3DXVECTOR3(0.0f, 1000.0f, -1000.0f));
	g_Camera[1].PosR = (D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	g_Camera[1].Rot = (D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	g_Camera[1].VecU = (D3DXVECTOR3(0.0f, 1.0f, 0.0f));
	g_Camera[1].bUse = false;

	g_Camera[2].PosV = (D3DXVECTOR3(3000.0f, 2000.0f, -3000.0f));
	g_Camera[2].PosR = (D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	g_Camera[2].Rot = (D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	g_Camera[2].VecU = (D3DXVECTOR3(0.0f, 1.0f, 0.0f));
	g_Camera[2].bUse = false;

	return S_OK;
}

//---------------------------
//�I������
//---------------------------
void UninitCamera(void)
{
	
}

//---------------------------
//�X�V����
//---------------------------
void UpdateCamera(void)
{
	for (int nCntCm = 0; nCntCm < MAX_CAMERA; nCntCm++)
	{
		if (g_Camera[nCntCm].bUse == true)
		{
			//�O��̈ʒu��ۑ�
			g_Camera[nCntCm].Poiold = g_Camera[nCntCm].Pointer;

			//�}�E�X���W�̎擾
			GetCursorPos(&g_Camera[nCntCm].Pointer);
		}
	}
	//---------------------------
	//�}�E�X�̍��W�̈ʒu���ǂ���
	//---------------------------
	for (int nCntCm = 0; nCntCm < MAX_CAMERA; nCntCm++)
	{
		if (g_Camera[nCntCm].bUse == true)
		{
			if (g_Camera[nCntCm].Poiold.x > g_Camera[nCntCm].Pointer.x)
			{
				g_Camera[nCntCm].Poimove.x = g_Camera[nCntCm].Poiold.x - g_Camera[nCntCm].Pointer.x - 1;
			}
			else if (g_Camera[nCntCm].Poiold.x < g_Camera[nCntCm].Pointer.x)
			{
				g_Camera[nCntCm].Poimove.x = g_Camera[nCntCm].Poiold.x - g_Camera[nCntCm].Pointer.x + 1;
			}
			if (g_Camera[nCntCm].Poiold.y > g_Camera[nCntCm].Pointer.y)
			{
				g_Camera[nCntCm].Poimove.y = g_Camera[nCntCm].Poiold.y - g_Camera[nCntCm].Pointer.y - 1;
			}
			else if (g_Camera[nCntCm].Poiold.y < g_Camera[nCntCm].Pointer.y)
			{
				g_Camera[nCntCm].Poimove.y = g_Camera[nCntCm].Poiold.y - g_Camera[nCntCm].Pointer.y + 1;
			}
		}
	}

	for (int nCntCm = 0; nCntCm < MAX_CAMERA; nCntCm++)
	{
		//�J�����ƒ����_�̋���
		g_Camera[nCntCm].Long = CAMERA_DESTAANCE;
	}
	//---------------------------
	//���_�����_�ړ�
	//---------------------------
	for (int nCntCm = 0; nCntCm < MAX_CAMERA; nCntCm++)
	{
		if (g_Camera[nCntCm].bUse == true)
		{
			if (GetKeyboardPress(DIK_W) == true)
			{
				g_Camera[nCntCm].PosV.x = g_Camera[nCntCm].PosV.x + sinf(g_Camera[nCntCm].Rot.y) * CAMERA_MOVE_SPEED;
				g_Camera[nCntCm].PosV.z = g_Camera[nCntCm].PosV.z + cosf(g_Camera[nCntCm].Rot.y) * CAMERA_MOVE_SPEED;

				g_Camera[nCntCm].PosR.x = g_Camera[nCntCm].PosR.x + sinf(g_Camera[nCntCm].Rot.y) * CAMERA_MOVE_SPEED;
				g_Camera[nCntCm].PosR.z = g_Camera[nCntCm].PosR.z + cosf(g_Camera[nCntCm].Rot.y) * CAMERA_MOVE_SPEED;
			}
			if (GetKeyboardPress(DIK_S) == true)
			{
				g_Camera[nCntCm].PosV.x = g_Camera[nCntCm].PosV.x - sinf(g_Camera[nCntCm].Rot.y) * CAMERA_MOVE_SPEED;
				g_Camera[nCntCm].PosV.z = g_Camera[nCntCm].PosV.z - cosf(g_Camera[nCntCm].Rot.y) * CAMERA_MOVE_SPEED;

				g_Camera[nCntCm].PosR.x = g_Camera[nCntCm].PosR.x - sinf(g_Camera[nCntCm].Rot.y) * CAMERA_MOVE_SPEED;
				g_Camera[nCntCm].PosR.z = g_Camera[nCntCm].PosR.z - cosf(g_Camera[nCntCm].Rot.y) * CAMERA_MOVE_SPEED;
			}
			if (GetKeyboardPress(DIK_A) == true)
			{
				g_Camera[nCntCm].PosV.x = g_Camera[nCntCm].PosV.x - cosf(g_Camera[nCntCm].Rot.y) * CAMERA_MOVE_SPEED;
				g_Camera[nCntCm].PosV.z = g_Camera[nCntCm].PosV.z + sinf(g_Camera[nCntCm].Rot.y) * CAMERA_MOVE_SPEED;

				g_Camera[nCntCm].PosR.x = g_Camera[nCntCm].PosR.x - cosf(g_Camera[nCntCm].Rot.y) * CAMERA_MOVE_SPEED;
				g_Camera[nCntCm].PosR.z = g_Camera[nCntCm].PosR.z + sinf(g_Camera[nCntCm].Rot.y) * CAMERA_MOVE_SPEED;
			}
			if (GetKeyboardPress(DIK_D) == true)
			{
				g_Camera[nCntCm].PosV.x = g_Camera[nCntCm].PosV.x + cosf(g_Camera[nCntCm].Rot.y) * CAMERA_MOVE_SPEED;
				g_Camera[nCntCm].PosV.z = g_Camera[nCntCm].PosV.z - sinf(g_Camera[nCntCm].Rot.y) * CAMERA_MOVE_SPEED;

				g_Camera[nCntCm].PosR.x = g_Camera[nCntCm].PosR.x + cosf(g_Camera[nCntCm].Rot.y) * CAMERA_MOVE_SPEED;
				g_Camera[nCntCm].PosR.z = g_Camera[nCntCm].PosR.z - sinf(g_Camera[nCntCm].Rot.y) * CAMERA_MOVE_SPEED;
			}
			//---------------------------
			//�����_���ړ�
			//---------------------------
			if (g_Camera[nCntCm].Poimove.x > 0 && MouseDowan(MOUSE_LEFT_BOTTON) == true)
			{
				g_Camera[nCntCm].Rot.y -= g_Camera[nCntCm].Poimove.x * 0.01;
				g_Camera[nCntCm].PosR.x = g_Camera[nCntCm].PosV.x + sinf(g_Camera[nCntCm].Rot.y) * g_Camera[nCntCm].Long;
				g_Camera[nCntCm].PosR.z = g_Camera[nCntCm].PosV.z + cosf(g_Camera[nCntCm].Rot.y) * g_Camera[nCntCm].Long;
			}
			else if (g_Camera[nCntCm].Poimove.x < 0 && MouseDowan(MOUSE_LEFT_BOTTON) == true)
			{
				g_Camera[nCntCm].Rot.y += g_Camera[nCntCm].Poimove.x * -0.01;
				g_Camera[nCntCm].PosR.x = g_Camera[nCntCm].PosV.x + sinf(g_Camera[nCntCm].Rot.y) * g_Camera[nCntCm].Long;
				g_Camera[nCntCm].PosR.z = g_Camera[nCntCm].PosV.z + cosf(g_Camera[nCntCm].Rot.y) * g_Camera[nCntCm].Long;
			}
			else if (g_Camera[nCntCm].Poimove.x == 0)
			{
				g_Camera[nCntCm].Rot.y += 0.0;
				g_Camera[nCntCm].PosR.x = g_Camera[nCntCm].PosV.x + sinf(g_Camera[nCntCm].Rot.y) * g_Camera[nCntCm].Long;
				g_Camera[nCntCm].PosR.z = g_Camera[nCntCm].PosV.z + cosf(g_Camera[nCntCm].Rot.y) * g_Camera[nCntCm].Long;
			}
			//---------------------------
			//�����_�c�ړ�
			//---------------------------
			if (g_Camera[nCntCm].Poimove.y > 0 && MouseDowan(MOUSE_LEFT_BOTTON) == true)
			{
				g_Camera[nCntCm].PosR.y += g_Camera[nCntCm].Poimove.y * 1.0f;
			}
			else if (g_Camera[nCntCm].Poimove.y < 0 && MouseDowan(MOUSE_LEFT_BOTTON) == true)
			{
				g_Camera[nCntCm].PosR.y -= g_Camera[nCntCm].Poimove.y * -1.0f;
			}
			else if (g_Camera[nCntCm].Poimove.y == 0)
			{
				g_Camera[nCntCm].PosR.y += 0.0;
			}
			//---------------------------
			//���_���ړ�
			//---------------------------
			if (g_Camera[nCntCm].Poimove.x > 0 && MouseDowan(MOUSE_WHEEL_BOTTON) == true)
			{
				g_Camera[nCntCm].Rot.y += g_Camera[nCntCm].Poimove.x * 0.01f;
				g_Camera[nCntCm].PosV.x = g_Camera[nCntCm].PosR.x - sinf(g_Camera[nCntCm].Rot.y) * g_Camera[nCntCm].Long;
				g_Camera[nCntCm].PosV.z = g_Camera[nCntCm].PosR.z - cosf(g_Camera[nCntCm].Rot.y) * g_Camera[nCntCm].Long;
			}
			else if (g_Camera[nCntCm].Poimove.x < 0 && MouseDowan(MOUSE_WHEEL_BOTTON) == true)
			{
				g_Camera[nCntCm].Rot.y -= g_Camera[nCntCm].Poimove.x * -0.01f;
				g_Camera[nCntCm].PosV.x = g_Camera[nCntCm].PosR.x - sinf(g_Camera[nCntCm].Rot.y) * g_Camera[nCntCm].Long;
				g_Camera[nCntCm].PosV.z = g_Camera[nCntCm].PosR.z - cosf(g_Camera[nCntCm].Rot.y) * g_Camera[nCntCm].Long;
			}
			//---------------------------
			//���_�c�ړ�
			//---------------------------
			if (g_Camera[nCntCm].Poimove.y > 0 && MouseDowan(MOUSE_RIGHT_BOTTON) == true)
			{
				g_Camera[nCntCm].PosV.y += g_Camera[nCntCm].Poimove.y * 1.0f;
			}
			else if (g_Camera[nCntCm].Poimove.y < 0 && MouseDowan(MOUSE_RIGHT_BOTTON) == true)
			{
				g_Camera[nCntCm].PosV.y -= g_Camera[nCntCm].Poimove.y * -1.0f;
			}
		}
	}
	//---------------------------
	//�J����0�������f���ɕt��
	//---------------------------



	//---------------------------
	//���Z�b�g
	//---------------------------
	if (GetKeyboardPress(DIK_RETURN) == true)
	{
		g_Camera[0].PosV = (D3DXVECTOR3(0.0f, 25.0f, -5.0f));
		g_Camera[0].PosR = (D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		g_Camera[0].Rot = (D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		g_Camera[0].VecU = (D3DXVECTOR3(0.0f, 1.0f, 0.0f));

		g_Camera[1].PosV = (D3DXVECTOR3(0.0f, 1000.0f, -1000.0f));
		g_Camera[1].PosR = (D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		g_Camera[1].Rot = (D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		g_Camera[1].VecU = (D3DXVECTOR3(0.0f, 1.0f, 0.0f));

		g_Camera[2].PosV = (D3DXVECTOR3(3000.0f, 2000.0f, -3000.0f));
		g_Camera[2].PosR = (D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		g_Camera[2].Rot = (D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		g_Camera[2].VecU = (D3DXVECTOR3(0.0f, 1.0f, 0.0f));
	}
	//---------------------------
	//�J�����̐؂�ւ�
	//---------------------------
	if (GetKeyboardTrigger(DIK_1) == true)
	{
		if (g_Camera[0].bUse == true)
		{
			g_Camera[2].bUse = true;
			g_Camera[0].bUse = false;
		}
		else if (g_Camera[1].bUse == true)
		{
			g_Camera[0].bUse = true;
			g_Camera[1].bUse = false;
		}
		else if (g_Camera[2].bUse == true)
		{
			g_Camera[1].bUse = true;
			g_Camera[2].bUse = false;
		}
	}
	else if (GetKeyboardTrigger(DIK_2) == true)
	{
		if (g_Camera[0].bUse == true)
		{
			g_Camera[1].bUse = true;
			g_Camera[0].bUse = false;
		}
		else if (g_Camera[1].bUse == true)
		{
			g_Camera[2].bUse = true;
			g_Camera[1].bUse = false;
		}
		else if (g_Camera[2].bUse == true)
		{
			g_Camera[0].bUse = true;
			g_Camera[2].bUse = false;
		}
	}
}

//---------------------------
//�`�揈��
//---------------------------
void SetCamera(void)
{
	LPDIRECT3DDEVICE9	pDevice;			//�f�o�C�X�̃|�C���^

	pDevice = GetDevice();					//�f�o�C�X���擾����
	for (int nCntCamera = 0; nCntCamera < MAX_CAMERA; nCntCamera++)
	{
		if (g_Camera[nCntCamera].bUse == true)
		{
			//---------------------------
			//�}�g���b�N�X�̐ݒ�
			//---------------------------
			D3DXMatrixIdentity(&g_Camera[nCntCamera].mtxProjection);	//�}�g���b�N�X������

															//�}�g���b�N�X�̍쐬
			D3DXMatrixPerspectiveFovLH(	&g_Camera[nCntCamera].mtxProjection,
										D3DXToRadian(90.0f),	//����p
										(float)SCREEN_WIDTH / (float)SCREEN_HEIGHT,
										10.0f,		//�J�����̍ŏ��`�拗��
										30000.0f);	//�J�����̍ő�`�拗��

							//�v���W�F�N�V�����}�g���b�N�X�ݒ�
			pDevice->SetTransform(	D3DTS_PROJECTION,
									&g_Camera[nCntCamera].mtxProjection);

			//�r���[�}�g���b�N�X�̏�����
			D3DXMatrixIdentity(&g_Camera[nCntCamera].mtxView);

			//�r���[�}�g���b�N�X�̍쐬
			D3DXMatrixLookAtLH(	&g_Camera[nCntCamera].mtxView,
								&g_Camera[nCntCamera].PosV,
								&g_Camera[nCntCamera].PosR,
								&g_Camera[nCntCamera].VecU);

			//�r���[�}�g���b�N�X�̐ݒ�
			pDevice->SetTransform(	D3DTS_VIEW,
									&g_Camera[nCntCamera].mtxView);
		}
	}
}

//---------------------------
//�J�����̏��
//---------------------------
Camera *GetCamera(void)
{
	return &g_Camera[0];
}