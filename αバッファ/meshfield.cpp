//---------------------------
//�C���N���[�h�t�@�C��
//---------------------------
#include "meshfield.h"

//---------------------------
//�O���[�o���ϐ�
//---------------------------
LPDIRECT3DTEXTURE9		g_pTextureField[MAX_TEX] = {};	//�e�N�X�`���ւ̃|�C���^
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffField = NULL;	//���_�o�b�t�@�ւ̃|�C���^
LPDIRECT3DINDEXBUFFER9	g_pIdxBuffFoeld = NULL;	//�C���f�b�N�X�o�b�t�@�ւ̃|�C���^
Field					g_Field[MAX_FIELD];		//���b�V���t�B�[���h�̍\����

//---------------------------
//�O���[�o���ϐ�
//---------------------------
HRESULT InitMeshfield(void)
{
	LPDIRECT3DDEVICE9	pDevice;	//�f�o�C�X�ւ̃|�C���^

	pDevice = GetDevice();			//�f�o�C�X�̎擾

	for (int nCntField = 0; nCntField < MAX_FIELD; nCntField++)
	{
		g_Field[nCntField].Pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_Field[nCntField].Rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_Field[nCntField].fWidth = 1.0f;
		g_Field[nCntField].fHeiht = 1.0f;
		g_Field[nCntField].fDepht = 1.0f;
		g_Field[nCntField].nTex = 0;
		g_Field[nCntField].bUse = false;
	}

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(	pDevice,
								"data/Texture/field002.jpg",			//�e�N�X�`��
								&g_pTextureField[0]);
	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(	sizeof(VERTEX_3D) * VTX_NUM_MAX * MAX_FIELD,
									D3DUSAGE_WRITEONLY,
									FVF_VERTEX_3D,
									D3DPOOL_MANAGED,
									&g_pVtxBuffField,
									NULL);
	//�C���f�b�N�X�o�b�t�@�̐���
	pDevice->CreateIndexBuffer(	sizeof(WORD) * IDX_NUM * MAX_FIELD,
								D3DUSAGE_WRITEONLY,
								D3DFMT_INDEX16,
								D3DPOOL_MANAGED,
								&g_pIdxBuffFoeld,
								NULL);
	//---------------------------
	//���_���
	//---------------------------
	VERTEX_3D *pVtx;		//���_���ւ̃|�C���^

	//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	g_pVtxBuffField->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCntField = 0; nCntField < MAX_FIELD; nCntField++)
	{
		/*int nVtxNum = 0;
		for (int nCntZ = 0; nCntZ < MAX_VTX_Z + 1; nCntZ++)
		{
			for (int nCntX = 0; nCntX < MAX_VTX_X + 1; nCntX++, nVtxNum++)
			{
				pVtx[nVtxNum].pos = D3DXVECTOR3(-MS_FLOO_X + ((MS_FLOO_X * 2) / MAX_VTX_X) * nCntX, 0.0f, MS_FLOO_Z - ((MS_FLOO_Z * 2) / MAX_VTX_Z) * nCntZ);
				pVtx[nVtxNum].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
				pVtx[nVtxNum].col = D3DCOLOR_RGBA(255, 255, 255, 255);
				pVtx[nVtxNum].tex = D3DXVECTOR2(0.0f + (1.0f * nCntX), 0.0f + (1.0f * nCntZ));
			}
		}
		nVtxNum = 0;*/
		//���_���W�̐ݒ�
		pVtx[0].pos = D3DXVECTOR3(-MS_FLOO_X, 0.0f, MS_FLOO_Z);
		pVtx[1].pos = D3DXVECTOR3(-0.5f, 0.0f, MS_FLOO_Z);
		pVtx[2].pos = D3DXVECTOR3(0.0f, 0.0f, MS_FLOO_Z);
		pVtx[3].pos = D3DXVECTOR3(0.5f, 0.0f, MS_FLOO_Z);
		pVtx[4].pos = D3DXVECTOR3(MS_FLOO_X, 0.0f, MS_FLOO_Z);

		pVtx[5].pos = D3DXVECTOR3(-MS_FLOO_X, 0.0f, 0.5f);
		pVtx[6].pos = D3DXVECTOR3(-0.5f, 0.0f, 0.5f);
		pVtx[7].pos = D3DXVECTOR3(0.0f, 0.0f, 0.5f);
		pVtx[8].pos = D3DXVECTOR3(0.5f, 0.0f, 0.5f);
		pVtx[9].pos = D3DXVECTOR3(MS_FLOO_X, 0.0f, 0.5f);

		pVtx[10].pos = D3DXVECTOR3(-MS_FLOO_X, 0.0f, 0.0f);
		pVtx[11].pos = D3DXVECTOR3(-0.5f, 0.0f, 0.0f);
		pVtx[12].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[13].pos = D3DXVECTOR3(0.5f, 0.0f, 0.0f);
		pVtx[14].pos = D3DXVECTOR3(MS_FLOO_X, 0.0f, 0.0f);

		pVtx[15].pos = D3DXVECTOR3(-MS_FLOO_X, 0.0f, -0.5f);
		pVtx[16].pos = D3DXVECTOR3(-0.5f, 0.0f, -0.5f);
		pVtx[17].pos = D3DXVECTOR3(0.0f, 0.0f, -0.5f);
		pVtx[18].pos = D3DXVECTOR3(0.5f, 0.0f, -0.5f);
		pVtx[19].pos = D3DXVECTOR3(MS_FLOO_X, 0.0f, -0.5f);

		pVtx[20].pos = D3DXVECTOR3(-MS_FLOO_X, 0.0f, -MS_FLOO_Z);
		pVtx[21].pos = D3DXVECTOR3(-0.5f, 0.0f, -MS_FLOO_Z);
		pVtx[22].pos = D3DXVECTOR3(0.0f, 0.0f, -MS_FLOO_Z);
		pVtx[23].pos = D3DXVECTOR3(0.5f, 0.0f, -MS_FLOO_Z);
		pVtx[24].pos = D3DXVECTOR3(MS_FLOO_X, 0.0f, -MS_FLOO_Z);

		int nVtxNum = 0;
		for (int nCntZ = 0; nCntZ < MAX_VTX_Z + 1; nCntZ++)
		{
			for (int nCntX = 0; nCntX < MAX_VTX_X + 1; nCntX++, nVtxNum++)
			{
				pVtx[nVtxNum].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
				pVtx[nVtxNum].col = D3DCOLOR_RGBA(255, 255, 255, 255);
				pVtx[nVtxNum].tex = D3DXVECTOR2(0.0f + (1.0f * nCntX), 0.0f + (1.0f * nCntZ));
			}
		}
		nVtxNum = 0;
	}

	//���_�o�b�t�@���A�����b�N����
	g_pVtxBuffField->Unlock();

	//---------------------------
	//�C���f�b�N�X���
	//---------------------------
	WORD	  *pIdx;		//�C���f�b�N�X���ւ̃|�C���^

	//�C���f�b�N�X�o�b�t�@�����b�N���A�ԍ��f�[�^�ւ̃|�C���^���擾
	g_pIdxBuffFoeld->Lock(0, 0, (void**)&pIdx, 0);

	for (int nCntField = 0; nCntField < MAX_FIELD; nCntField++)
	{
		//�p�킳��ȊO�̒��_
		for (int nCntZ = 0; nCntZ < MAX_VTX_Z; nCntZ++)
		{
			for (int nCntX = 0; nCntX < MAX_VTX_X + 1; nCntX++)
			{
				pIdx[(nCntX * 2) + 0 + ((MAX_VTX_X + 6) * nCntZ)] = ((MAX_VTX_X + 1) + nCntX) + ((MAX_VTX_X + 1) * nCntZ);
				pIdx[(nCntX * 2) + 1 + ((MAX_VTX_X + 6) * nCntZ)] = (0 + nCntX) + ((MAX_VTX_X + 1) * nCntZ);
			}
		}
		//�p�킳��̒��_
		for (int nCntZ = 0; nCntZ < MAX_VTX_Z - 1; nCntZ++)
		{
			pIdx[((MAX_VTX_X + 1) * 2 + 0) + ((MAX_VTX_Z - 2) * 2)] = MAX_VTX_X + ((MAX_VTX_X + 1) * nCntZ);
			pIdx[((MAX_VTX_X + 1) * 2 + 1) + ((MAX_VTX_Z - 2) * 2)] = (MAX_VTX_X * 2 + 2) + ((MAX_VTX_X + 1) * nCntZ);
		}
	}

	//�C���f�b�N�X�o�b�t�@���A�����b�N����
	g_pIdxBuffFoeld->Unlock();

	return S_OK;
}

//---------------------------
//�I������
//---------------------------
void UninitMeshfield(void)
{
	//---------------------------
	//�e�N�X�`���j��
	//---------------------------
	for (int nCntTex = 0; nCntTex < MAX_TEX; nCntTex++)
	{
		if (g_pTextureField[nCntTex] != NULL)
		{
			g_pTextureField[nCntTex]->Release();
			g_pTextureField[nCntTex] = NULL;
		}
	}

	//---------------------------
	//�o�b�t�@�j��
	//---------------------------
	if (g_pVtxBuffField != NULL)
	{
		g_pVtxBuffField->Release();
		g_pVtxBuffField = NULL;
	}

	//---------------------------
	//�C���f�b�N�X�o�b�t�@�j��
	//---------------------------
	if (g_pIdxBuffFoeld != NULL)
	{
		g_pIdxBuffFoeld->Release();
		g_pIdxBuffFoeld = NULL;
	}
}

//---------------------------
//�X�V����
//---------------------------
void UpdateMeshfield(void)
{

}

//---------------------------
//�`�揈��
//---------------------------
void DrawMeshfield(void)
{
	LPDIRECT3DDEVICE9	pDevice;			//�f�o�C�X�̃|�C���^

	pDevice = GetDevice();					//�f�o�C�X���擾����

	//---------------------------
	//�}�g���b�N�X�̐ݒ�
	//---------------------------
	D3DXMATRIX			mtxRot, mtxTrans;	//�v�Z�p�}�g���b�N�X

	for (int nCntField = 0; nCntField < MAX_FIELD; nCntField++)
	{
		if (g_Field[nCntField].bUse == true)
		{
			//�J�����O�L
			pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);

			D3DXMatrixIdentity(&g_Field[nCntField].mtxWold);	//�}�g���b�N�X������

			//�X�P�[��
			g_Field[nCntField].mtxWold._11 = g_Field[nCntField].fWidth;
			g_Field[nCntField].mtxWold._22 = g_Field[nCntField].fHeiht;
			g_Field[nCntField].mtxWold._33 = g_Field[nCntField].fDepht;

			//�����̐ݒ�
			D3DXMatrixRotationYawPitchRoll(	&mtxRot,
											g_Field[nCntField].Rot.y,
											g_Field[nCntField].Rot.x,
											g_Field[nCntField].Rot.z);

			D3DXMatrixMultiply(	&g_Field[nCntField].mtxWold,
								&g_Field[nCntField].mtxWold,
								&mtxRot);
			//�ʒu
			D3DXMatrixTranslation(	&mtxTrans,
									g_Field[nCntField].Pos.x,
									g_Field[nCntField].Pos.y,
									g_Field[nCntField].Pos.z);

			D3DXMatrixMultiply(	&g_Field[nCntField].mtxWold,
								&g_Field[nCntField].mtxWold,
								&mtxTrans);
			//�}�g���b�N�X�̐ݒ�
			pDevice->SetTransform(	D3DTS_WORLD,
									&g_Field[nCntField].mtxWold);
			//---------------------------
			//�`�揈��
			//---------------------------
			//�o�b�t�@�̐ݒ���f�[�^�X�g���[���ɐݒ�
			pDevice->SetStreamSource(	0,
										g_pVtxBuffField,
										0,
										sizeof(VERTEX_3D));
			//�C���f�b�N�X�o�b�t�@���f�[�^�X�g���[���ɐݒ�
			pDevice->SetIndices(g_pIdxBuffFoeld);

			//���_�t�H�[�}�b�g�̐ݒ�
			pDevice->SetFVF(FVF_VERTEX_3D);

			//�e�N�X�`���̐ݒ�
			pDevice->SetTexture(	0,
									g_pTextureField[g_Field[nCntField].nTex]);
			//�|���S���̕`��
			pDevice->DrawIndexedPrimitive(	D3DPT_TRIANGLESTRIP,	//�v���~�e�B�u�̎��
											0,						//���Ԗڂ���`�悷�邩
											0,
											IDX_NUM,						//���_�̐�
											0,
											POLY_NUM;				//���̐�
		}
	}
}

//---------------------------
//�Z�b�g
//---------------------------
void SetField(D3DXVECTOR3 rot, D3DXVECTOR3 pos, float fWidth, float fHeight, float fDepht, int nTex, MESH_STATE aState)
{
	for (int nCntField = 0; nCntField < MAX_FIELD; nCntField++)
	{
		if (g_Field[nCntField].bUse == false)
		{
			g_Field[nCntField].Pos = pos;			//�ʒu
			g_Field[nCntField].Rot = rot;			//����
			g_Field[nCntField].fWidth = fWidth;		//��
			g_Field[nCntField].fHeiht = fHeight;	//����
			g_Field[nCntField].fDepht = fDepht;	//���s
			g_Field[nCntField].nTex = nTex;			//���
			g_Field[nCntField].aState = aState;		//�`

			g_Field[nCntField].bUse = true;
			break;
		}
	}
}

//---------------------------
//�����蔻��
//---------------------------
bool ColisionFeild(D3DXVECTOR3 *pos, D3DXVECTOR3 *posold, D3DXVECTOR3 *move, float fWidth, float fHeight, float fDepht, int nType)
{
	bool bLand = false;

	return bLand;
}