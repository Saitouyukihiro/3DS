//---------------------------
//インクルードファイル
//---------------------------
#include "meshfield.h"

//---------------------------
//グローバル変数
//---------------------------
LPDIRECT3DTEXTURE9		g_pTextureField[MAX_TEX] = {};	//テクスチャへのポインタ
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffField = NULL;	//頂点バッファへのポインタ
LPDIRECT3DINDEXBUFFER9	g_pIdxBuffFoeld = NULL;	//インデックスバッファへのポインタ
Field					g_Field[MAX_FIELD];		//メッシュフィールドの構造体

//---------------------------
//グローバル変数
//---------------------------
HRESULT InitMeshfield(void)
{
	LPDIRECT3DDEVICE9	pDevice;	//デバイスへのポインタ

	pDevice = GetDevice();			//デバイスの取得

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

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(	pDevice,
								"data/Texture/field002.jpg",			//テクスチャ
								&g_pTextureField[0]);
	//頂点バッファの生成
	pDevice->CreateVertexBuffer(	sizeof(VERTEX_3D) * VTX_NUM_MAX * MAX_FIELD,
									D3DUSAGE_WRITEONLY,
									FVF_VERTEX_3D,
									D3DPOOL_MANAGED,
									&g_pVtxBuffField,
									NULL);
	//インデックスバッファの生成
	pDevice->CreateIndexBuffer(	sizeof(WORD) * IDX_NUM * MAX_FIELD,
								D3DUSAGE_WRITEONLY,
								D3DFMT_INDEX16,
								D3DPOOL_MANAGED,
								&g_pIdxBuffFoeld,
								NULL);
	//---------------------------
	//頂点情報
	//---------------------------
	VERTEX_3D *pVtx;		//頂点情報へのポインタ

	//頂点バッファをロックし、頂点データへのポインタを取得
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
		//頂点座標の設定
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

	//頂点バッファをアンロックする
	g_pVtxBuffField->Unlock();

	//---------------------------
	//インデックス情報
	//---------------------------
	WORD	  *pIdx;		//インデックス情報へのポインタ

	//インデックスバッファをロックし、番号データへのポインタを取得
	g_pIdxBuffFoeld->Lock(0, 0, (void**)&pIdx, 0);

	for (int nCntField = 0; nCntField < MAX_FIELD; nCntField++)
	{
		//角被さり以外の頂点
		for (int nCntZ = 0; nCntZ < MAX_VTX_Z; nCntZ++)
		{
			for (int nCntX = 0; nCntX < MAX_VTX_X + 1; nCntX++)
			{
				pIdx[(nCntX * 2) + 0 + ((MAX_VTX_X + 6) * nCntZ)] = ((MAX_VTX_X + 1) + nCntX) + ((MAX_VTX_X + 1) * nCntZ);
				pIdx[(nCntX * 2) + 1 + ((MAX_VTX_X + 6) * nCntZ)] = (0 + nCntX) + ((MAX_VTX_X + 1) * nCntZ);
			}
		}
		//角被さりの頂点
		for (int nCntZ = 0; nCntZ < MAX_VTX_Z - 1; nCntZ++)
		{
			pIdx[((MAX_VTX_X + 1) * 2 + 0) + ((MAX_VTX_Z - 2) * 2)] = MAX_VTX_X + ((MAX_VTX_X + 1) * nCntZ);
			pIdx[((MAX_VTX_X + 1) * 2 + 1) + ((MAX_VTX_Z - 2) * 2)] = (MAX_VTX_X * 2 + 2) + ((MAX_VTX_X + 1) * nCntZ);
		}
	}

	//インデックスバッファをアンロックする
	g_pIdxBuffFoeld->Unlock();

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
	for (int nCntTex = 0; nCntTex < MAX_TEX; nCntTex++)
	{
		if (g_pTextureField[nCntTex] != NULL)
		{
			g_pTextureField[nCntTex]->Release();
			g_pTextureField[nCntTex] = NULL;
		}
	}

	//---------------------------
	//バッファ破棄
	//---------------------------
	if (g_pVtxBuffField != NULL)
	{
		g_pVtxBuffField->Release();
		g_pVtxBuffField = NULL;
	}

	//---------------------------
	//インデックスバッファ破棄
	//---------------------------
	if (g_pIdxBuffFoeld != NULL)
	{
		g_pIdxBuffFoeld->Release();
		g_pIdxBuffFoeld = NULL;
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

	for (int nCntField = 0; nCntField < MAX_FIELD; nCntField++)
	{
		if (g_Field[nCntField].bUse == true)
		{
			//カリング有
			pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);

			D3DXMatrixIdentity(&g_Field[nCntField].mtxWold);	//マトリックス初期化

			//スケール
			g_Field[nCntField].mtxWold._11 = g_Field[nCntField].fWidth;
			g_Field[nCntField].mtxWold._22 = g_Field[nCntField].fHeiht;
			g_Field[nCntField].mtxWold._33 = g_Field[nCntField].fDepht;

			//向きの設定
			D3DXMatrixRotationYawPitchRoll(	&mtxRot,
											g_Field[nCntField].Rot.y,
											g_Field[nCntField].Rot.x,
											g_Field[nCntField].Rot.z);

			D3DXMatrixMultiply(	&g_Field[nCntField].mtxWold,
								&g_Field[nCntField].mtxWold,
								&mtxRot);
			//位置
			D3DXMatrixTranslation(	&mtxTrans,
									g_Field[nCntField].Pos.x,
									g_Field[nCntField].Pos.y,
									g_Field[nCntField].Pos.z);

			D3DXMatrixMultiply(	&g_Field[nCntField].mtxWold,
								&g_Field[nCntField].mtxWold,
								&mtxTrans);
			//マトリックスの設定
			pDevice->SetTransform(	D3DTS_WORLD,
									&g_Field[nCntField].mtxWold);
			//---------------------------
			//描画処理
			//---------------------------
			//バッファの設定をデータストリームに設定
			pDevice->SetStreamSource(	0,
										g_pVtxBuffField,
										0,
										sizeof(VERTEX_3D));
			//インデックスバッファをデータストリームに設定
			pDevice->SetIndices(g_pIdxBuffFoeld);

			//頂点フォーマットの設定
			pDevice->SetFVF(FVF_VERTEX_3D);

			//テクスチャの設定
			pDevice->SetTexture(	0,
									g_pTextureField[g_Field[nCntField].nTex]);
			//ポリゴンの描画
			pDevice->DrawIndexedPrimitive(	D3DPT_TRIANGLESTRIP,	//プリミティブの種類
											0,						//何番目から描画するか
											0,
											IDX_NUM,						//頂点の数
											0,
											POLY_NUM;				//△の数
		}
	}
}

//---------------------------
//セット
//---------------------------
void SetField(D3DXVECTOR3 rot, D3DXVECTOR3 pos, float fWidth, float fHeight, float fDepht, int nTex, MESH_STATE aState)
{
	for (int nCntField = 0; nCntField < MAX_FIELD; nCntField++)
	{
		if (g_Field[nCntField].bUse == false)
		{
			g_Field[nCntField].Pos = pos;			//位置
			g_Field[nCntField].Rot = rot;			//向き
			g_Field[nCntField].fWidth = fWidth;		//幅
			g_Field[nCntField].fHeiht = fHeight;	//高さ
			g_Field[nCntField].fDepht = fDepht;	//奥行
			g_Field[nCntField].nTex = nTex;			//種類
			g_Field[nCntField].aState = aState;		//形

			g_Field[nCntField].bUse = true;
			break;
		}
	}
}

//---------------------------
//当たり判定
//---------------------------
bool ColisionFeild(D3DXVECTOR3 *pos, D3DXVECTOR3 *posold, D3DXVECTOR3 *move, float fWidth, float fHeight, float fDepht, int nType)
{
	bool bLand = false;

	return bLand;
}