//---------------------------
//�C���N���[�h�t�@�C��
//---------------------------
#include "meshfield.h"

//---------------------------
//�O���[�o���ϐ�
//---------------------------
LPDIRECT3DTEXTURE9		g_pTextureField = NULL;	//�e�N�X�`���ւ̃|�C���^
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffField = NULL;	//���_�o�b�t�@�ւ̃|�C���^
D3DXVECTOR3				g_PosField;				//�ʒu
D3DXVECTOR3				g_RotField;				//����
D3DXMATRIX				g_mtxWoldField;			//���[���h�}�g���b�N�X

//---------------------------
//�O���[�o���ϐ�
//---------------------------
HRESULT InitMeshfield(void)
{
	LPDIRECT3DDEVICE9	pDevice;	//�f�o�C�X�ւ̃|�C���^

	pDevice = GetDevice();			//�f�o�C�X�̎擾

	g_PosField = (D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	g_RotField = (D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(	pDevice,
								"data/Texture/field002.jpg",			//�e�N�X�`��
								&g_pTextureField);
	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(	sizeof(VERTEX_3D) * 14,
									D3DUSAGE_WRITEONLY,
									FVF_VERTEX_3D,
									D3DPOOL_MANAGED,
									&g_pVtxBuffField,
									NULL);
	//---------------------------
	//���_���
	//---------------------------
	VERTEX_3D			*pVtx;		//���_���ւ̃|�C���^

	//���_�o�b�t�@�����b�N���A���_�f�[�^�ւ̃|�C���^���擾
	g_pVtxBuffField->Lock(0, 0, (void**)&pVtx, 0);

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(-MS_FLOO_X, 0.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(-MS_FLOO_X, 0.0f, MS_FLOO_Z);
	pVtx[2].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(0.0f, 0.0f, MS_FLOO_Z);
	pVtx[4].pos = D3DXVECTOR3(MS_FLOO_X, 0.0f, 0.0f);
	pVtx[5].pos = D3DXVECTOR3(MS_FLOO_X, 0.0f, MS_FLOO_Z);
	pVtx[6].pos = D3DXVECTOR3(MS_FLOO_X, 0.0f, MS_FLOO_Z);
	pVtx[7].pos = D3DXVECTOR3(-MS_FLOO_X, 0.0f, -MS_FLOO_Z);
	pVtx[8].pos = D3DXVECTOR3(-MS_FLOO_X, 0.0f, -MS_FLOO_Z);
	pVtx[9].pos = D3DXVECTOR3(-MS_FLOO_X, 0.0f, 0.0f);
	pVtx[10].pos = D3DXVECTOR3(0.0f, 0.0f, -MS_FLOO_Z);
	pVtx[11].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[12].pos = D3DXVECTOR3(MS_FLOO_X, 0.0f, -MS_FLOO_Z);
	pVtx[13].pos = D3DXVECTOR3(MS_FLOO_X, 0.0f, 0.0f);

	pVtx[0].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[1].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[2].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[3].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[4].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[5].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[6].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[7].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[8].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[9].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[10].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[11].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[12].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[13].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

	pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[4].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[5].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[6].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[7].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[8].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[9].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[10].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[11].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[12].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[13].col = D3DCOLOR_RGBA(255, 255, 255, 255);

	pVtx[0].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[1].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(1.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[4].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[5].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[6].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[7].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[8].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[9].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[10].tex = D3DXVECTOR2(1.0f, 1.0f);
	pVtx[11].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[12].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[13].tex = D3DXVECTOR2(0.0f, 0.0f);

	//���_�o�b�t�@���A�����b�N����
	g_pVtxBuffField->Unlock();

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
	if (g_pTextureField != NULL)
	{
		g_pTextureField->Release();
		g_pTextureField = NULL;
	}

	//---------------------------
	//�o�b�t�@�j��
	//---------------------------
	if (g_pVtxBuffField != NULL)
	{
		g_pVtxBuffField->Release();
		g_pVtxBuffField = NULL;
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

											//�J�����O�L
	pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);

	D3DXMatrixIdentity(&g_mtxWoldField);	//�}�g���b�N�X������

	//�����̐ݒ�
	D3DXMatrixRotationYawPitchRoll(	&mtxRot,
									g_RotField.y,
									g_RotField.x,
									g_RotField.z);

	D3DXMatrixMultiply(	&g_mtxWoldField,
						&g_mtxWoldField,
						&mtxRot);
	//�ʒu
	D3DXMatrixTranslation(	&mtxTrans,
							g_PosField.x,
							g_PosField.y,
							g_PosField.z);

	D3DXMatrixMultiply(	&g_mtxWoldField,
						&g_mtxWoldField,
						&mtxTrans);
	//�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(	D3DTS_WORLD,
							&g_mtxWoldField);
	//---------------------------
	//�`�揈��
	//---------------------------
	//�o�b�t�@�̐ݒ�
	pDevice->SetStreamSource(	0,
								g_pVtxBuffField,
								0,
								sizeof(VERTEX_3D));
	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_3D);

	//�e�N�X�`���̐ݒ�
	pDevice->SetTexture(	0,
							g_pTextureField);
	//�|���S���̕`��
	pDevice->DrawPrimitive(	D3DPT_TRIANGLESTRIP,	//�v���~�e�B�u�̎��
							0,						//���Ԗڂ���`�悷�邩
							14);					//���̐�
}