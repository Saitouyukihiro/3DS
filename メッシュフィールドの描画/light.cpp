//---------------------------
//�C���N���[�h�t�@�C��
//---------------------------
#include "light.h"
#include "keyinput.h"
#include "camara.h"

//---------------------------
//�O���[�o���ϐ�
//---------------------------
D3DLIGHT9		g_Ligt[MAX_LIGHT];	//���C�g
LightSelect		g_bUse[MAX_LIGHT];	//�I�����Ă邩

//---------------------------
//����������
//---------------------------
HRESULT InitLight(void)
{
	LPDIRECT3DDEVICE9	pDevice;				//�f�o�C�X�̃|�C���^
	D3DXVECTOR3			VecDir[MAX_LIGHT];		//�x�N�g��

	pDevice = GetDevice();			//�f�o�C�X���擾����

	g_bUse[0].bUse = true;
	g_bUse[1].bUse = false;
	g_bUse[2].bUse = false;
	for (int nCntLihgt = 0; nCntLihgt < MAX_LIGHT; nCntLihgt++)
	{
		g_bUse[nCntLihgt].bSelect = TRUE;
		g_bUse[nCntLihgt].Rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	}
	//---------------------------
	//���C�g�̐ݒ�
	//---------------------------

	for (int nCntLihgt = 0; nCntLihgt < MAX_LIGHT; nCntLihgt++)
	{
		//���C�g�̃N���A
		ZeroMemory(	&g_Ligt[nCntLihgt],
					sizeof(D3DLIGHT9));

		//���C�g�̎��
		g_Ligt[nCntLihgt].Type = D3DLIGHT_DIRECTIONAL;	//���

		//���C�g�̊g�U��
		g_Ligt[nCntLihgt].Diffuse = (D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));	//�F

		if (nCntLihgt == 0)
		{
			//���C�g�̏ꏊ
			g_Ligt[nCntLihgt].Position = (D3DXVECTOR3(-100.0f, 100.0f, 100.0f));

			//���C�g�̕���
			VecDir[nCntLihgt] = (D3DXVECTOR3(0.2f, -0.8f, 0.4f));

			//���K������
			D3DXVec3Normalize(	&VecDir[nCntLihgt],
								&VecDir[nCntLihgt]);

			//���C�g�̕���������
			g_Ligt[nCntLihgt].Direction = VecDir[nCntLihgt];

			//���C�g�̐ݒ�
			pDevice->SetLight(nCntLihgt, &g_Ligt[nCntLihgt]);	//0�Ԗڂ̃��C�g�ɐݒ肵���ݒ������

			//���C�g��L���ɂ���
			pDevice->LightEnable(nCntLihgt, TRUE);	//0�Ԗڂ̃��C�g��t����
		}
		else if (nCntLihgt == 1)
		{
			//���C�g�̏ꏊ
			g_Ligt[nCntLihgt].Position = (D3DXVECTOR3(0.0f, 500.0f, 0.0f));

			//���C�g�̕���
			VecDir[nCntLihgt] = (D3DXVECTOR3(0.0f, -1.0f, 0.0f));

			//���K������
			D3DXVec3Normalize(	&VecDir[nCntLihgt],
								&VecDir[nCntLihgt]);

			//���C�g�̕���������
			g_Ligt[nCntLihgt].Direction = VecDir[nCntLihgt];

			//���C�g�̐ݒ�
			pDevice->SetLight(nCntLihgt, &g_Ligt[nCntLihgt]);	//1�Ԗڂ̃��C�g�ɐݒ肵���ݒ������

			//���C�g��L���ɂ���
			pDevice->LightEnable(nCntLihgt, TRUE);	//1�Ԗڂ̃��C�g��t����
		}
		else if (nCntLihgt == 2)
		{
			//���C�g�̏ꏊ
			g_Ligt[nCntLihgt].Position = (D3DXVECTOR3(100.0f, -100.0f, -100.0f));

			//���C�g�̕���
			VecDir[nCntLihgt] = (D3DXVECTOR3(-0.2f, 0.8f, -0.4f));

			//���K������
			D3DXVec3Normalize(	&VecDir[nCntLihgt],
								&VecDir[nCntLihgt]);

			//���C�g�̕���������
			g_Ligt[nCntLihgt].Direction = VecDir[nCntLihgt];

			//���C�g�̐ݒ�
			pDevice->SetLight(nCntLihgt, &g_Ligt[nCntLihgt]);	//2�Ԗڂ̃��C�g�ɐݒ肵���ݒ������

			//���C�g��L���ɂ���
			pDevice->LightEnable(nCntLihgt, TRUE);	//2�Ԗڂ̃��C�g��t����
		}
	}
	return S_OK;
}

//---------------------------
//�I������
//---------------------------
void UninitLight(void)
{

}

//---------------------------
//�X�V����
//---------------------------
void UpdateLight(void)
{
	LPDIRECT3DDEVICE9 pDevice;		//�f�o�C�X�̃|�C���^
	D3DXVECTOR3	VecDir[MAX_LIGHT];	//�x�N�g��

	pDevice = GetDevice();			//�f�o�C�X���擾����

	//---------------------------
	//���C�g�̈ړ�
	//---------------------------
	for (int nCntLihgt = 0; nCntLihgt < MAX_LIGHT; nCntLihgt++)
	{
		if (g_bUse[nCntLihgt].bUse == true)
		{
			if (GetKeyboardPress(DIK_UP) == true)
			{
				g_bUse[nCntLihgt].Rot.x += 0.1f;

				//���C�g�̕���������
				g_Ligt[nCntLihgt].Direction.y = g_Ligt[nCntLihgt].Direction.y += sinf(g_bUse[nCntLihgt].Rot.x) * LIGHT_MOVE_SPEED;
				g_Ligt[nCntLihgt].Direction.z = g_Ligt[nCntLihgt].Direction.z += cosf(g_bUse[nCntLihgt].Rot.x) * LIGHT_MOVE_SPEED;

				//���C�g�̐ݒ�
				pDevice->SetLight(nCntLihgt, &g_Ligt[nCntLihgt]);	//2�Ԗڂ̃��C�g�ɐݒ肵���ݒ������
			}
			else if (GetKeyboardPress(DIK_DOWN) == true)
			{
				g_bUse[nCntLihgt].Rot.x -= 0.1f;

				//���C�g�̕���������
				g_Ligt[nCntLihgt].Direction.y = g_Ligt[nCntLihgt].Direction.y += sinf(g_bUse[nCntLihgt].Rot.x) * LIGHT_MOVE_SPEED;
				g_Ligt[nCntLihgt].Direction.z = g_Ligt[nCntLihgt].Direction.z += cosf(g_bUse[nCntLihgt].Rot.x) * LIGHT_MOVE_SPEED;

				//���C�g�̐ݒ�
				pDevice->SetLight(nCntLihgt, &g_Ligt[nCntLihgt]);	//2�Ԗڂ̃��C�g�ɐݒ肵���ݒ������
			}
			else if (GetKeyboardPress(DIK_LEFT) == true)
			{
				g_bUse[nCntLihgt].Rot.y -= 0.1f;

				//���C�g�̕���������
				g_Ligt[nCntLihgt].Direction.x = g_Ligt[nCntLihgt].Direction.x += sinf(g_bUse[nCntLihgt].Rot.y) * LIGHT_MOVE_SPEED;
				g_Ligt[nCntLihgt].Direction.z = g_Ligt[nCntLihgt].Direction.z += cosf(g_bUse[nCntLihgt].Rot.y) * LIGHT_MOVE_SPEED;

				//���C�g�̐ݒ�
				pDevice->SetLight(nCntLihgt, &g_Ligt[nCntLihgt]);	//2�Ԗڂ̃��C�g�ɐݒ肵���ݒ������
			}
			else if (GetKeyboardPress(DIK_RIGHT) == true)
			{

				g_bUse[nCntLihgt].Rot.y += 0.1f;

				//���C�g�̕���������
				g_Ligt[nCntLihgt].Direction.x = g_Ligt[nCntLihgt].Direction.x += sinf(g_bUse[nCntLihgt].Rot.y) * LIGHT_MOVE_SPEED;
				g_Ligt[nCntLihgt].Direction.z = g_Ligt[nCntLihgt].Direction.z += cosf(g_bUse[nCntLihgt].Rot.y) * LIGHT_MOVE_SPEED;

				//���C�g�̐ݒ�
				pDevice->SetLight(nCntLihgt, &g_Ligt[nCntLihgt]);	//2�Ԗڂ̃��C�g�ɐݒ肵���ݒ������
			}
			//---------------------------
			//���C�g�̐؂�ւ�
			//---------------------------
			if (GetKeyboardTrigger(DIK_F) == true)
			{
				//���Ă�������A�����Ă���t����
				g_bUse[nCntLihgt].bSelect = g_bUse[nCntLihgt].bSelect ? FALSE : TRUE;
				//���C�g�̐ݒ�
				pDevice->LightEnable(nCntLihgt, g_bUse[nCntLihgt].bSelect);	//�I��Ԗڂ̃��C�g
			}
		}
	}
	//---------------------------
	//���C�g�̐؂�ւ�
	//---------------------------
	if (GetKeyboardTrigger(DIK_3) == true)
	{
		if (g_bUse[0].bUse == true)
		{
			g_bUse[2].bUse = true;
			g_bUse[0].bUse = false;
		}
		else if (g_bUse[1].bUse == true)
		{
			g_bUse[0].bUse = true;
			g_bUse[1].bUse = false;
		}
		else if (g_bUse[2].bUse == true)
		{
			g_bUse[1].bUse = true;
			g_bUse[2].bUse = false;
		}
	}
	else if (GetKeyboardTrigger(DIK_4) == true)
	{
		if (g_bUse[0].bUse == true)
		{
			g_bUse[1].bUse = true;
			g_bUse[0].bUse = false;
		}
		else if (g_bUse[1].bUse == true)
		{
			g_bUse[2].bUse = true;
			g_bUse[1].bUse = false;
		}
		else if (g_bUse[2].bUse == true)
		{
			g_bUse[0].bUse = true;
			g_bUse[2].bUse = false;
		}
	}
}
//---------------------------
//���C�g�̏��
//---------------------------
D3DLIGHT9 *GetLight(void)
{
	return &g_Ligt[0];
}
//---------------------------
//���C�g�̏��
//---------------------------
LightSelect *GetLightSelect(void)
{
	return &g_bUse[0];
}