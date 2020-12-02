//---------------------------
//�C���N���[�h�t�@�C��
//---------------------------
#include "bullet.h"
#include "shadow.h"

//---------------------------
//�O���[�o���ϐ�
//---------------------------
LPDIRECT3DTEXTURE9		g_pTextureBullet = NULL;		//�e�N�X�`���ւ̃|�C���^
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffBullet = NULL;		//���_�o�b�t�@�ւ̃|�C���^
Bullet					g_aBullet[MAX_BULLET];			//�r���{�[�h�̃|�C���^

//---------------------------
//�O���[�o���ϐ�
//---------------------------
HRESULT InitBullet(void)
{
	LPDIRECT3DDEVICE9	pDevice;	//�f�o�C�X�ւ̃|�C���^

	pDevice = GetDevice();			//�f�o�C�X�̎擾

	//�l�̏�����
	for (int nCntBullet = 0; nCntBullet < MAX_BULLET; nCntBullet++)
	{
		g_aBullet[nCntBullet].Pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aBullet[nCntBullet].Move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aBullet[nCntBullet].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aBullet[nCntBullet].fWidth = BULLET_X;
		g_aBullet[nCntBullet].fHeight = BULLET_Y;
		g_aBullet[nCntBullet].nIdex = 0;
		g_aBullet[nCntBullet].nType = 0;
		g_aBullet[nCntBullet].bUse = false;
	}

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(	pDevice,
								"data/Texture/bullet01.png",			//�e�N�X�`��
								&g_pTextureBullet);
	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(	sizeof(VERTEX_3D) * 4 * MAX_BULLET,
									D3DUSAGE_WRITEONLY,
									FVF_VERTEX_3D,
									D3DPOOL_MANAGED,
									&g_pVtxBuffBullet,
									NULL);
	//---------------------------
	//���_���
	//---------------------------
	VERTEX_3D *pVtx;		//���_���ւ̃|�C���^

	//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	g_pVtxBuffBullet->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCntBullet = 0; nCntBullet < MAX_BULLET; nCntBullet++)
	{
		//���_���W�̐ݒ�
		pVtx[0].pos = D3DXVECTOR3(-g_aBullet[nCntBullet].fWidth / 2, -g_aBullet[nCntBullet].fHeight / 2, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(g_aBullet[nCntBullet].fWidth / 2, -g_aBullet[nCntBullet].fHeight / 2, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(-g_aBullet[nCntBullet].fWidth / 2, g_aBullet[nCntBullet].fHeight / 2, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(g_aBullet[nCntBullet].fWidth / 2, g_aBullet[nCntBullet].fHeight / 2, 0.0f);

		pVtx[0].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		pVtx[1].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		pVtx[2].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		pVtx[3].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);

		pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

		pVtx[0].tex = D3DXVECTOR2(1.0f, 1.0f);
		pVtx[1].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[2].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[3].tex = D3DXVECTOR2(0.0f, 0.0f);

		pVtx += 4;	//���_��i�߂�
	}

	//���_�o�b�t�@���A�����b�N����
	g_pVtxBuffBullet->Unlock();

	return S_OK;
}

//---------------------------
//�I������
//---------------------------
void UninitBullet(void)
{
	//---------------------------
	//�e�N�X�`���j��
	//---------------------------
	if (g_pTextureBullet != NULL)
	{
		g_pTextureBullet->Release();
		g_pTextureBullet = NULL;
	}

	//---------------------------
	//�o�b�t�@�j��
	//---------------------------
	if (g_pVtxBuffBullet != NULL)
	{
		g_pVtxBuffBullet->Release();
		g_pVtxBuffBullet = NULL;
	}
}

//---------------------------
//�X�V����
//---------------------------
void UpdateBullet(void)
{
	for (int nCntBullet = 0; nCntBullet < MAX_BULLET; nCntBullet++)
	{
		if (g_aBullet[nCntBullet].bUse == true)
		{
			g_aBullet[nCntBullet].Move.x = g_aBullet[nCntBullet].Move.x + sinf(g_aBullet[nCntBullet].rot.y) * BULLET_MOVE_SPEED;
			g_aBullet[nCntBullet].Move.z = g_aBullet[nCntBullet].Move.z + cosf(g_aBullet[nCntBullet].rot.y) * BULLET_MOVE_SPEED;

			g_aBullet[nCntBullet].Pos += g_aBullet[nCntBullet].Move;

			//�����̉e
			SetPointShadow(g_aBullet[nCntBullet].nIdex, g_aBullet[nCntBullet].Pos, g_aBullet[nCntBullet].fWidth, g_aBullet[nCntBullet].fHeight);
		}
	}
}

//---------------------------
//�`�揈��
//---------------------------
void DrawBullet(void)
{
	LPDIRECT3DDEVICE9	pDevice;			//�f�o�C�X�̃|�C���^

	pDevice = GetDevice();					//�f�o�C�X���擾����

	//---------------------------
	//�}�g���b�N�X�̐ݒ�
	//---------------------------
	D3DXMATRIX			 mtxTrans;	//�v�Z�p�}�g���b�N�X

	for (int nCntBullet = 0; nCntBullet < MAX_BULLET; nCntBullet++)
	{
		if (g_aBullet[nCntBullet].bUse == true)
		{
			//�J�����O�L��
			pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CW);

			//Z�e�X�g
			pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_ALWAYS);
			pDevice->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);

			//�}�g���b�N�X������
			D3DXMatrixIdentity(	&g_aBullet[nCntBullet].mtxWold);

			//�J�����̌������擾
			pDevice->GetTransform(	D3DTS_VIEW,
									&g_aBullet[nCntBullet].mtxView);
			//�J�����̏������āA�X�P�[���𔽉f
			g_aBullet[nCntBullet].mtxWold._11 = g_aBullet[nCntBullet].mtxView._11 * g_aBullet[nCntBullet].fWidth;
			g_aBullet[nCntBullet].mtxWold._12 = g_aBullet[nCntBullet].mtxView._21 * g_aBullet[nCntBullet].fWidth;
			g_aBullet[nCntBullet].mtxWold._13 = g_aBullet[nCntBullet].mtxView._31 * g_aBullet[nCntBullet].fWidth;
			g_aBullet[nCntBullet].mtxWold._21 = g_aBullet[nCntBullet].mtxView._12 * g_aBullet[nCntBullet].fHeight;
			g_aBullet[nCntBullet].mtxWold._22 = g_aBullet[nCntBullet].mtxView._22 * g_aBullet[nCntBullet].fHeight;
			g_aBullet[nCntBullet].mtxWold._23 = g_aBullet[nCntBullet].mtxView._32 * g_aBullet[nCntBullet].fHeight;
			g_aBullet[nCntBullet].mtxWold._31 = g_aBullet[nCntBullet].mtxView._13;
			g_aBullet[nCntBullet].mtxWold._32 = g_aBullet[nCntBullet].mtxView._23;
			g_aBullet[nCntBullet].mtxWold._33 = g_aBullet[nCntBullet].mtxView._33;

			//�ʒu
			D3DXMatrixTranslation(	&mtxTrans,
									g_aBullet[nCntBullet].Pos.x,
									g_aBullet[nCntBullet].Pos.y,
									g_aBullet[nCntBullet].Pos.z);

			D3DXMatrixMultiply(	&g_aBullet[nCntBullet].mtxWold,
								&g_aBullet[nCntBullet].mtxWold,
								&mtxTrans);
			//�}�g���b�N�X�̐ݒ�
			pDevice->SetTransform(	D3DTS_WORLD,
									&g_aBullet[nCntBullet].mtxWold);
			//---------------------------
			//�`�揈��
			//---------------------------
			//�o�b�t�@�̐ݒ���f�[�^�X�g���[���ɐݒ�
			pDevice->SetStreamSource(	0,
										g_pVtxBuffBullet,
										0,
										sizeof(VERTEX_3D));
			//���_�t�H�[�}�b�g�̐ݒ�
			pDevice->SetFVF(FVF_VERTEX_3D);

			//�e�N�X�`���̐ݒ�
			pDevice->SetTexture(	0,
									g_pTextureBullet);
			//�|���S���̕`��
			pDevice->DrawPrimitive(	D3DPT_TRIANGLESTRIP,	//�v���~�e�B�u�̎��
									nCntBullet * 4,			//���Ԗڂ���`�悷�邩
									2);						//���̐�
			//Z�e�X�g
			pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
			pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);
		}
	}
}

//---------------------------
//�e�̃Z�b�g
//---------------------------
void SetBullet(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float fWidth, float fHeight, int nType)
{
	for (int nCntBullet = 0; nCntBullet < MAX_BULLET; nCntBullet++)
	{
		if (g_aBullet[nCntBullet].bUse == false)
		{
			g_aBullet[nCntBullet].Pos = pos;			//�����Ă����ʒu����
			g_aBullet[nCntBullet].rot = rot;			//�����Ă����ړ��ʂ���
			g_aBullet[nCntBullet].fWidth = fWidth;		//�����Ă���������
			g_aBullet[nCntBullet].fHeight = fHeight;	//�����Ă�����������
			g_aBullet[nCntBullet].nType = nType;		//�����Ă�����ނ���

			g_aBullet[nCntBullet].bUse = true;

			//�e�̃Z�b�g
			g_aBullet[nCntBullet].nIdex = SetShadow(pos, fWidth, fHeight);
			break;
		}
	}
}

//---------------------------
//�e�̏����擾
//---------------------------
Bullet *GetBullet(void)
{
	return &g_aBullet[0];
}