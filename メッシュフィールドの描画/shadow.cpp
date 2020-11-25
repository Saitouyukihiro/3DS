//---------------------------
//�C���N���[�h�t�@�C��
//---------------------------
#include "shadow.h"

//---------------------------
//�O���[�o���ϐ�
//---------------------------
LPDIRECT3DTEXTURE9		g_pTextureShadow = NULL;	//�e�N�X�`���ւ̃|�C���^
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffShadow = NULL;	//���_�o�b�t�@�ւ̃|�C���^
Shadow					g_aShadow[MAX_SHADOW];		//�e�̍\����			

//---------------------------
//�O���[�o���ϐ�
//---------------------------
HRESULT InitShadow(void)
{
	LPDIRECT3DDEVICE9	pDevice;	//�f�o�C�X�ւ̃|�C���^

	pDevice = GetDevice();			//�f�o�C�X�̎擾

	//�l�̏�����
	for (int nCntShadow = 0; nCntShadow < MAX_SHADOW; nCntShadow++)
	{
		g_aShadow[nCntShadow].pos = (D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		g_aShadow[nCntShadow].rot = (D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		g_aShadow[nCntShadow].fHeiht = 0.0f;
		g_aShadow[nCntShadow].fWhith = SHADOW_X;
		g_aShadow[nCntShadow].fDepht = SHADOW_Z;
		g_aShadow[nCntShadow].fAlpha = 255.0f;
		g_aShadow[nCntShadow].bUse = false;
	}

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(	pDevice,
								"data/Texture/shadow000.jpg",			//�e�N�X�`��
								&g_pTextureShadow);
	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(	sizeof(VERTEX_3D) * 4 * MAX_SHADOW,
									D3DUSAGE_WRITEONLY,
									FVF_VERTEX_3D,
									D3DPOOL_MANAGED,
									&g_pVtxBuffShadow,
									NULL);
	//---------------------------
	//���_���
	//---------------------------
	VERTEX_3D			*pVtx;		//���_���ւ̃|�C���^

	//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	g_pVtxBuffShadow->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCntShadow = 0; nCntShadow < MAX_SHADOW; nCntShadow++)
	{
		//���_���W�̐ݒ�
		pVtx[0].pos = D3DXVECTOR3(-g_aShadow[nCntShadow].fWhith / 2, 0.0f, g_aShadow[nCntShadow].fDepht / 2);
		pVtx[1].pos = D3DXVECTOR3(g_aShadow[nCntShadow].fWhith / 2, 0.0f, g_aShadow[nCntShadow].fDepht / 2);
		pVtx[2].pos = D3DXVECTOR3(-g_aShadow[nCntShadow].fWhith / 2, 0.0f, -g_aShadow[nCntShadow].fDepht / 2);
		pVtx[3].pos = D3DXVECTOR3(g_aShadow[nCntShadow].fWhith / 2, 0.0f, -g_aShadow[nCntShadow].fDepht / 2);

		pVtx[0].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		pVtx[1].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		pVtx[2].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		pVtx[3].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

		pVtx[0].col = D3DXCOLOR(255, 255, 255, g_aShadow[nCntShadow].fAlpha);
		pVtx[1].col = D3DXCOLOR(255, 255, 255, g_aShadow[nCntShadow].fAlpha);
		pVtx[2].col = D3DXCOLOR(255, 255, 255, g_aShadow[nCntShadow].fAlpha);
		pVtx[3].col = D3DXCOLOR(255, 255, 255, g_aShadow[nCntShadow].fAlpha);

		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

		pVtx += 4;	//���_��i�߂�
	}

	//���_�o�b�t�@���A�����b�N����
	g_pVtxBuffShadow->Unlock();

	return S_OK;
}

//---------------------------
//�I������
//---------------------------
void UninitShadow(void)
{
	//---------------------------
	//�e�N�X�`���j��
	//---------------------------
	if (g_pTextureShadow != NULL)
	{
		g_pTextureShadow->Release();
		g_pTextureShadow = NULL;
	}

	//---------------------------
	//�o�b�t�@�j��
	//---------------------------
	if (g_pVtxBuffShadow != NULL)
	{
		g_pVtxBuffShadow->Release();
		g_pVtxBuffShadow = NULL;
	}
}

//---------------------------
//�X�V����
//---------------------------
void UpdateShadow(void)
{
	
}

//---------------------------
//�`�揈��
//---------------------------
void DrawShadow(void)
{
	LPDIRECT3DDEVICE9	pDevice;			//�f�o�C�X�̃|�C���^

	pDevice = GetDevice();					//�f�o�C�X���擾����

	//---------------------------
	//�}�g���b�N�X�̐ݒ�
	//---------------------------
	D3DXMATRIX			mtxRot, mtxTrans;	//�v�Z�p�}�g���b�N�X

	//���Z����
	pDevice->SetRenderState(	D3DRS_BLENDOP,
								D3DBLENDOP_REVSUBTRACT);
	//���Z����
	pDevice->SetRenderState(	D3DRS_SRCBLEND,
								D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(	D3DRS_DESTBLEND,
								D3DBLEND_ONE);

	for (int nCntShadow = 0; nCntShadow < MAX_SHADOW; nCntShadow++)
	{
		if (g_aShadow[nCntShadow].bUse == true)
		{
			//�J�����O�L
			pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);
			// �}�g���b�N�X������
			D3DXMatrixIdentity(&g_aShadow[nCntShadow].mtxWorld);

			//�X�P�[��
			g_aShadow[nCntShadow].mtxWorld._11 = g_aShadow[nCntShadow].fWhith;
			g_aShadow[nCntShadow].mtxWorld._33 = g_aShadow[nCntShadow].fDepht;

			//�����̐ݒ�
			D3DXMatrixRotationYawPitchRoll(	&mtxRot,
											g_aShadow[nCntShadow].rot.y,
											g_aShadow[nCntShadow].rot.x,
											g_aShadow[nCntShadow].rot.z);

			D3DXMatrixMultiply(	&g_aShadow[nCntShadow].mtxWorld,
								&g_aShadow[nCntShadow].mtxWorld,
								&mtxRot);
			//�ʒu
			D3DXMatrixTranslation(	&mtxTrans,
									g_aShadow[nCntShadow].pos.x,
									g_aShadow[nCntShadow].pos.y,
									g_aShadow[nCntShadow].pos.z);

			D3DXMatrixMultiply(	&g_aShadow[nCntShadow].mtxWorld,
								&g_aShadow[nCntShadow].mtxWorld,
								&mtxTrans);
			//�}�g���b�N�X�̐ݒ�
			pDevice->SetTransform(	D3DTS_WORLD,
									&g_aShadow[nCntShadow].mtxWorld);

			//---------------------------
			//�`�揈��
			//---------------------------
			//�o�b�t�@�̐ݒ�
			pDevice->SetStreamSource(	0,
										g_pVtxBuffShadow,
										0,
										sizeof(VERTEX_3D));
			//���_�t�H�[�}�b�g�̐ݒ�
			pDevice->SetFVF(FVF_VERTEX_3D);

			//�e�N�X�`���̐ݒ�
			pDevice->SetTexture(	0,
									g_pTextureShadow);
			//�|���S���̕`��
			pDevice->DrawPrimitive(	D3DPT_TRIANGLESTRIP,	//�v���~�e�B�u�̎��
									nCntShadow * 4,			//���Ԗڂ���`�悷�邩
									2);						//���̐�
		}
	}
	//�ʏ�̐ݒ�ɖ߂�
	pDevice->SetRenderState(	D3DRS_BLENDOP,
								D3DBLENDOP_ADD);
	pDevice->SetRenderState(	D3DRS_SRCBLEND,
								D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(	D3DRS_DESTBLEND,
								D3DBLEND_INVSRCALPHA);
}

//---------------------------
//�e�̏��
//---------------------------
int SetShadow(D3DXVECTOR3 pos, float fWhith, float fDepht)
{
	int Index = -1;

	for (int nCntShadow = 0; nCntShadow < MAX_SHADOW; nCntShadow++)
	{
		if (g_aShadow[nCntShadow].bUse == false)
		{
			g_aShadow[nCntShadow].pos.x = pos.x;	//�ʒu����
			g_aShadow[nCntShadow].pos.z = pos.z;	//�ʒu����
			g_aShadow[nCntShadow].fWhith = fWhith;	//������
			g_aShadow[nCntShadow].fDepht = fDepht;	//��������

			g_aShadow[nCntShadow].bUse = true;
			Index = nCntShadow;
			break;
		}
	}
	return Index;	//�g���Ă�e��n��
}

//---------------------------
//�w��̉e���Z�b�g
//---------------------------
void SetPointShadow(int nIdx, D3DXVECTOR3 pos, float fWhith, float fDepht)
{
	VERTEX_3D			*pVtx;		//���_���ւ̃|�C���^

	g_aShadow[nIdx].pos.x = pos.x;	//�w�肵���e���t���Ă���
	g_aShadow[nIdx].pos.z = pos.z;	//�w�肵���e���t���Ă���

	g_aShadow[nIdx].fWhith = fWhith + (pos.y / 3.0f);
	g_aShadow[nIdx].fDepht = fDepht + (pos.y / 3.0f);
	g_aShadow[nIdx].fAlpha = 1.0f - pos.y / 400.0f;

	if (g_aShadow[nIdx].fAlpha <= 0.0f)
	{
		g_aShadow[nIdx].fAlpha = 0.0f;
	}
	//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	g_pVtxBuffShadow->Lock(0, 0, (void**)&pVtx, 0);

	pVtx += nIdx * 4;	//���_��i�߂�

	pVtx[0].col = D3DXCOLOR(255, 255, 255, g_aShadow[nIdx].fAlpha);
	pVtx[1].col = D3DXCOLOR(255, 255, 255, g_aShadow[nIdx].fAlpha);
	pVtx[2].col = D3DXCOLOR(255, 255, 255, g_aShadow[nIdx].fAlpha);
	pVtx[3].col = D3DXCOLOR(255, 255, 255, g_aShadow[nIdx].fAlpha);

	//���_�o�b�t�@���A�����b�N����
	g_pVtxBuffShadow->Unlock();
}