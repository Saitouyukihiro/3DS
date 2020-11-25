//---------------------------
//�C���N���[�h�t�@�C��
//---------------------------
#include "wall.h"
#include "shadow.h"

//---------------------------
//�O���[�o���ϐ�
//---------------------------
LPDIRECT3DTEXTURE9		g_pTextureWall = NULL;	//�e�N�X�`���ւ̃|�C���^
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffWall = NULL;	//���_�o�b�t�@�ւ̃|�C���^
Wall					g_aWall[MAX_WALL];		//�ǂ̃|�C���^

//---------------------------
//�O���[�o���ϐ�
//---------------------------
HRESULT InitWall(void)
{
	LPDIRECT3DDEVICE9	pDevice;	//�f�o�C�X�ւ̃|�C���^

	pDevice = GetDevice();			//�f�o�C�X�̎擾

	//�l�̏�����
	for (int nCntWall = 0; nCntWall < MAX_WALL; nCntWall++)
	{
		g_aWall[nCntWall].PosWall = (D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		g_aWall[nCntWall].RotWall = (D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		g_aWall[nCntWall].fWidth = WALL_X;
		g_aWall[nCntWall].fHeiht = WALL_Y;
		g_aWall[nCntWall].nIdex = 0;
		g_aWall[nCntWall].bUse = false;
	}

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(	pDevice,
								"data/Texture/field001.jpg",			//�e�N�X�`��
								&g_pTextureWall);
	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(	sizeof(VERTEX_3D) * 4 * MAX_WALL,
									D3DUSAGE_WRITEONLY,
									FVF_VERTEX_3D,
									D3DPOOL_MANAGED,
									&g_pVtxBuffWall,
									NULL);
	//---------------------------
	//���_���
	//---------------------------
	VERTEX_3D			*pVtx;		//���_���ւ̃|�C���^

	//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	g_pVtxBuffWall->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCntWall = 0; nCntWall < MAX_WALL; nCntWall++)
	{
		//���_���W�̐ݒ�
		pVtx[0].pos = D3DXVECTOR3(-g_aWall[nCntWall].fWidth / 2, g_aWall[nCntWall].fHeiht / 2, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(g_aWall[nCntWall].fWidth / 2, g_aWall[nCntWall].fHeiht / 2, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(-g_aWall[nCntWall].fWidth / 2, -g_aWall[nCntWall].fHeiht / 2, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(g_aWall[nCntWall].fWidth / 2, -g_aWall[nCntWall].fHeiht / 2, 0.0f);

		pVtx[0].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		pVtx[1].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		pVtx[2].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		pVtx[3].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);

		pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

		pVtx += 4;	//���_��i�߂�
	}

	//���_�o�b�t�@���A�����b�N����
	g_pVtxBuffWall->Unlock();

	return S_OK;
}

//---------------------------
//�I������
//---------------------------
void UninitWall(void)
{
	//---------------------------
	//�e�N�X�`���j��
	//---------------------------
	if (g_pTextureWall != NULL)
	{
		g_pTextureWall->Release();
		g_pTextureWall = NULL;
	}

	//---------------------------
	//�o�b�t�@�j��
	//---------------------------
	if (g_pVtxBuffWall != NULL)
	{
		g_pVtxBuffWall->Release();
		g_pVtxBuffWall = NULL;
	}
}

//---------------------------
//�X�V����
//---------------------------
void UpdateWall(void)
{
	
}

//---------------------------
//�`�揈��
//---------------------------
void DrawWall(void)
{
	LPDIRECT3DDEVICE9	pDevice;			//�f�o�C�X�̃|�C���^

	pDevice = GetDevice();					//�f�o�C�X���擾����

	//---------------------------
	//�}�g���b�N�X�̐ݒ�
	//---------------------------
	D3DXMATRIX			mtxRot, mtxTrans;	//�v�Z�p�}�g���b�N�X

	for (int nCntWall = 0; nCntWall < MAX_WALL; nCntWall++)
	{
		if (g_aWall[nCntWall].bUse == true)
		{
			//�J�����O�L
			pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);
			//�}�g���b�N�X������
			D3DXMatrixIdentity(&g_aWall[nCntWall].mtxWoldWall);

			//�X�P�[��
			g_aWall[nCntWall].mtxWoldWall._11 = g_aWall[nCntWall].fWidth;
			g_aWall[nCntWall].mtxWoldWall._22 = g_aWall[nCntWall].fHeiht;

			//�����̐ݒ�
			D3DXMatrixRotationYawPitchRoll(	&mtxRot,
											g_aWall[nCntWall].RotWall.y,
											g_aWall[nCntWall].RotWall.x,
											g_aWall[nCntWall].RotWall.z);

			D3DXMatrixMultiply(	&g_aWall[nCntWall].mtxWoldWall,
								&g_aWall[nCntWall].mtxWoldWall,
								&mtxRot);
			//�ʒu
			D3DXMatrixTranslation(	&mtxTrans,
									g_aWall[nCntWall].PosWall.x,
									g_aWall[nCntWall].PosWall.y,
									g_aWall[nCntWall].PosWall.z);

			D3DXMatrixMultiply(	&g_aWall[nCntWall].mtxWoldWall,
								&g_aWall[nCntWall].mtxWoldWall,
								&mtxTrans);
			//�}�g���b�N�X�̐ݒ�
			pDevice->SetTransform(	D3DTS_WORLD,
									&g_aWall[nCntWall].mtxWoldWall);
			//---------------------------
			//�`�揈��
			//---------------------------
			//�o�b�t�@�̐ݒ�
			pDevice->SetStreamSource(	0,
										g_pVtxBuffWall,
										0,
										sizeof(VERTEX_3D));
			//���_�t�H�[�}�b�g�̐ݒ�
			pDevice->SetFVF(FVF_VERTEX_3D);

			//�e�N�X�`���̐ݒ�
			pDevice->SetTexture(	0,
									g_pTextureWall);
			//�|���S���̕`��
			pDevice->DrawPrimitive(	D3DPT_TRIANGLESTRIP,	//�v���~�e�B�u�̎��
									nCntWall * 4,			//���Ԗڂ���`�悷�邩
									2);						//���̐�
		}
	}
}

//---------------------------
//�ǂ̃Z�b�g
//---------------------------
void SetWall(D3DXVECTOR3 RotWall, D3DXVECTOR3 PosWall, float fWith, float fHeight)
{
	for (int nCntWall = 0; nCntWall < MAX_WALL; nCntWall++)
	{
		if (g_aWall[nCntWall].bUse == false)
		{
			g_aWall[nCntWall].RotWall = RotWall;	//�ǂ̌���
			g_aWall[nCntWall].PosWall = PosWall;	//�ǂ̈ʒu
			g_aWall[nCntWall].fWidth = fWith;		//�ǂ̕�
			g_aWall[nCntWall].fHeiht = fHeight;		//�ǂ̍���

			g_aWall[nCntWall].bUse = true;
			break;
		}
	}
}