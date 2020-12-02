//---------------------------
//�C���N���[�h�t�@�C��
//---------------------------
#include "billboard.h"
#include "shadow.h"

//---------------------------
//�O���[�o���ϐ�
//---------------------------
LPDIRECT3DTEXTURE9		g_pTextureBillboard = NULL;		//�e�N�X�`���ւ̃|�C���^
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffBillboard = NULL;		//���_�o�b�t�@�ւ̃|�C���^
Billboard				g_aBillboard[MAX_BILLBOARD];	//�r���{�[�h�̃|�C���^

//---------------------------
//�O���[�o���ϐ�
//---------------------------
HRESULT InitBillboard(void)
{
	LPDIRECT3DDEVICE9	pDevice;	//�f�o�C�X�ւ̃|�C���^

	pDevice = GetDevice();			//�f�o�C�X�̎擾

	//�l�̏�����
	for (int nCntBill = 0; nCntBill < MAX_BILLBOARD; nCntBill++)
	{
		g_aBillboard[nCntBill].Pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aBillboard[nCntBill].Move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aBillboard[nCntBill].fWidth = BILLBOARD_X;
		g_aBillboard[nCntBill].fHeiht = BILLBOARD_Y;
		g_aBillboard[nCntBill].nIdex = 0;
		g_aBillboard[nCntBill].bUse = false;
	}

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(	pDevice,
								"data/Texture/cat01.png",			//�e�N�X�`��
								&g_pTextureBillboard);
	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(	sizeof(VERTEX_3D) * 4 * MAX_BILLBOARD,
									D3DUSAGE_WRITEONLY,
									FVF_VERTEX_3D,
									D3DPOOL_MANAGED,
									&g_pVtxBuffBillboard,
									NULL);
	//---------------------------
	//���_���
	//---------------------------
	VERTEX_3D *pVtx;		//���_���ւ̃|�C���^

	//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	g_pVtxBuffBillboard->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCntBill = 0; nCntBill < MAX_BILLBOARD; nCntBill++)
	{
		//���_���W�̐ݒ�
		pVtx[0].pos = D3DXVECTOR3(-g_aBillboard[nCntBill].fWidth / 2, - g_aBillboard[nCntBill].fHeiht / 2, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(g_aBillboard[nCntBill].fWidth / 2, - g_aBillboard[nCntBill].fHeiht / 2, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(-g_aBillboard[nCntBill].fWidth / 2, g_aBillboard[nCntBill].fHeiht / 2, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(g_aBillboard[nCntBill].fWidth / 2, g_aBillboard[nCntBill].fHeiht / 2, 0.0f);

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
	g_pVtxBuffBillboard->Unlock();

	return S_OK;
}

//---------------------------
//�I������
//---------------------------
void UninitBillboard(void)
{
	//---------------------------
	//�e�N�X�`���j��
	//---------------------------
	if (g_pTextureBillboard != NULL)
	{
		g_pTextureBillboard->Release();
		g_pTextureBillboard = NULL;
	}

	//---------------------------
	//�o�b�t�@�j��
	//---------------------------
	if (g_pVtxBuffBillboard != NULL)
	{
		g_pVtxBuffBillboard->Release();
		g_pVtxBuffBillboard = NULL;
	}
}

//---------------------------
//�X�V����
//---------------------------
void UpdateBillboard(void)
{
	
}

//---------------------------
//�`�揈��
//---------------------------
void DrawBillboard(void)
{
	LPDIRECT3DDEVICE9	pDevice;			//�f�o�C�X�̃|�C���^

	pDevice = GetDevice();					//�f�o�C�X���擾����

	//---------------------------
	//�}�g���b�N�X�̐ݒ�
	//---------------------------
	D3DXMATRIX			 mtxTrans;	//�v�Z�p�}�g���b�N�X

	for (int nCntBill = 0; nCntBill < MAX_BILLBOARD; nCntBill++)
	{
		if (g_aBillboard[nCntBill].bUse == true)
		{
			//�J�����O�L��
			pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CW);

			//���e�X�g
			pDevice->SetRenderState(	D3DRS_ALPHATESTENABLE, TRUE);
			pDevice->SetRenderState(	D3DRS_ALPHAFUNC, D3DCMP_GREATER);
			pDevice->SetRenderState(	D3DRS_ALPHAREF, 0);

			//�}�g���b�N�X������
			D3DXMatrixIdentity(&g_aBillboard[nCntBill].mtxWold);

			//�J�����̌������擾
			pDevice->GetTransform(	D3DTS_VIEW,
									&g_aBillboard[nCntBill].mtxView);
			//�J�����̏������āA�X�P�[���𔽉f
			g_aBillboard[nCntBill].mtxWold._11 = g_aBillboard[nCntBill].mtxView._11 * g_aBillboard[nCntBill].fWidth;
			g_aBillboard[nCntBill].mtxWold._12 = g_aBillboard[nCntBill].mtxView._21 * g_aBillboard[nCntBill].fWidth;
			g_aBillboard[nCntBill].mtxWold._13 = g_aBillboard[nCntBill].mtxView._31 * g_aBillboard[nCntBill].fWidth;
			g_aBillboard[nCntBill].mtxWold._21 = g_aBillboard[nCntBill].mtxView._12 * g_aBillboard[nCntBill].fHeiht;
			g_aBillboard[nCntBill].mtxWold._22 = g_aBillboard[nCntBill].mtxView._22 * g_aBillboard[nCntBill].fHeiht;
			g_aBillboard[nCntBill].mtxWold._23 = g_aBillboard[nCntBill].mtxView._32 * g_aBillboard[nCntBill].fHeiht;
			g_aBillboard[nCntBill].mtxWold._31 = g_aBillboard[nCntBill].mtxView._13;
			g_aBillboard[nCntBill].mtxWold._32 = g_aBillboard[nCntBill].mtxView._23;
			g_aBillboard[nCntBill].mtxWold._33 = g_aBillboard[nCntBill].mtxView._33;

			//�ʒu
			D3DXMatrixTranslation(	&mtxTrans,
									g_aBillboard[nCntBill].Pos.x,
									g_aBillboard[nCntBill].Pos.y,
									g_aBillboard[nCntBill].Pos.z);

			D3DXMatrixMultiply(	&g_aBillboard[nCntBill].mtxWold,
								&g_aBillboard[nCntBill].mtxWold,
								&mtxTrans);
			//�}�g���b�N�X�̐ݒ�
			pDevice->SetTransform(	D3DTS_WORLD,
									&g_aBillboard[nCntBill].mtxWold);
			//---------------------------
			//�`�揈��
			//---------------------------
			//�o�b�t�@�̐ݒ���f�[�^�X�g���[���ɐݒ�
			pDevice->SetStreamSource(	0,
										g_pVtxBuffBillboard,
										0,
										sizeof(VERTEX_3D));
			//���_�t�H�[�}�b�g�̐ݒ�
			pDevice->SetFVF(FVF_VERTEX_3D);

			//�e�N�X�`���̐ݒ�
			pDevice->SetTexture(	0,
									g_pTextureBillboard);
			//�|���S���̕`��
			pDevice->DrawPrimitive(	D3DPT_TRIANGLESTRIP,	//�v���~�e�B�u�̎��
									nCntBill * 4,			//���Ԗڂ���`�悷�邩
									2);						//���̐�
			//���e�X�g
			pDevice->SetRenderState(	D3DRS_ALPHATESTENABLE, FALSE);
			pDevice->SetRenderState(	D3DRS_ALPHAFUNC, D3DCMP_ALWAYS);
			pDevice->SetRenderState(	D3DRS_ALPHAREF, 0x00);
		}
	}
}

//---------------------------
//�r���{�[�h
//---------------------------
void SetBillboard(D3DXVECTOR3 Pos, float fWidth, float fHeight)
{
	for (int nCntBill = 0; nCntBill < MAX_BILLBOARD; nCntBill++)
	{
		if (g_aBillboard[nCntBill].bUse == false)
		{
			g_aBillboard[nCntBill].Pos = Pos;			//�r���{�[�h�̈ʒu
			g_aBillboard[nCntBill].fWidth = fWidth;		//�r���{�[�h�̕�
			g_aBillboard[nCntBill].fHeiht = fHeight;	//�r���{�[�h�̍���

			g_aBillboard[nCntBill].bUse = true;

			//�e�̃Z�b�g
			g_aBillboard[nCntBill].nIdex = SetShadow(g_aBillboard[nCntBill].Pos, fWidth, fHeight);
			break;
		}
	}
}