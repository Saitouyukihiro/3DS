//---------------------------
//インクルードファイル
//---------------------------
#include "meshfield.h"

//---------------------------
//グローバル変数
//---------------------------
LPDIRECT3DTEXTURE9		g_pTextureField = NULL;	//テクスチャへのポインタ
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffField = NULL;	//頂点バッファへのポインタ
D3DXVECTOR3				g_PosField;				//位置
D3DXVECTOR3				g_RotField;				//向き
D3DXMATRIX				g_mtxWoldField;			//ワールドマトリックス

//---------------------------
//グローバル変数
//---------------------------
HRESULT InitMeshfield(void)
{
	LPDIRECT3DDEVICE9	pDevice;	//デバイスへのポインタ

	pDevice = GetDevice();			//デバイスの取得

	g_PosField = (D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	g_RotField = (D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(	pDevice,
								"data/Texture/field002.jpg",			//テクスチャ
								&g_pTextureField);
	//頂点バッファの生成
	pDevice->CreateVertexBuffer(	sizeof(VERTEX_3D) * 14,
									D3DUSAGE_WRITEONLY,
									FVF_VERTEX_3D,
									D3DPOOL_MANAGED,
									&g_pVtxBuffField,
									NULL);
	//---------------------------
	//頂点情報
	//---------------------------
	VERTEX_3D			*pVtx;		//頂点情報へのポインタ

	//頂点バッファをロックし、頂点データへのポインタを取得
	g_pVtxBuffField->Lock(0, 0, (void**)&pVtx, 0);

	//頂点座標の設定
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

	//頂点バッファをアンロックする
	g_pVtxBuffField->Unlock();

	return S_OK;
}

//---------------------------
//終了処理
//---------------------------
void UninitMeshfield(void)
{
	//---------------------------
	//テクスチャ破棄
	//---------------------------
	if (g_pTextureField != NULL)
	{
		g_pTextureField->Release();
		g_pTextureField = NULL;
	}

	//---------------------------
	//バッファ破棄
	//---------------------------
	if (g_pVtxBuffField != NULL)
	{
		g_pVtxBuffField->Release();
		g_pVtxBuffField = NULL;
	}
}

//---------------------------
//更新処理
//---------------------------
void UpdateMeshfield(void)
{

}

//---------------------------
//描画処理
//---------------------------
void DrawMeshfield(void)
{
	LPDIRECT3DDEVICE9	pDevice;			//デバイスのポインタ

	pDevice = GetDevice();					//デバイスを取得する

	//---------------------------
	//マトリックスの設定
	//---------------------------
	D3DXMATRIX			mtxRot, mtxTrans;	//計算用マトリックス

											//カリング有
	pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);

	D3DXMatrixIdentity(&g_mtxWoldField);	//マトリックス初期化

	//向きの設定
	D3DXMatrixRotationYawPitchRoll(	&mtxRot,
									g_RotField.y,
									g_RotField.x,
									g_RotField.z);

	D3DXMatrixMultiply(	&g_mtxWoldField,
						&g_mtxWoldField,
						&mtxRot);
	//位置
	D3DXMatrixTranslation(	&mtxTrans,
							g_PosField.x,
							g_PosField.y,
							g_PosField.z);

	D3DXMatrixMultiply(	&g_mtxWoldField,
						&g_mtxWoldField,
						&mtxTrans);
	//マトリックスの設定
	pDevice->SetTransform(	D3DTS_WORLD,
							&g_mtxWoldField);
	//---------------------------
	//描画処理
	//---------------------------
	//バッファの設定
	pDevice->SetStreamSource(	0,
								g_pVtxBuffField,
								0,
								sizeof(VERTEX_3D));
	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_3D);

	//テクスチャの設定
	pDevice->SetTexture(	0,
							g_pTextureField);
	//ポリゴンの描画
	pDevice->DrawPrimitive(	D3DPT_TRIANGLESTRIP,	//プリミティブの種類
							0,						//何番目から描画するか
							14);					//△の数
}