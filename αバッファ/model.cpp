//---------------------------
//インクルードファイル
//---------------------------
#include <stdio.h>
#include "model.h"
#include "keyinput.h"
#include "camara.h"
#include "mouseinput.h"
#include "shadow.h"
#include "bullet.h"

//---------------------------
//グローバル変数
//---------------------------
LPD3DXMESH				g_pMeshModel = NULL;		//メッシュのポインタ
LPD3DXBUFFER			g_pBuffMatModel = NULL;		//マテリアルのポインタ
DWORD					g_pnNumMatModel = 0;		//マテリアルの数
D3DXVECTOR3				g_PosModel;					//位置
D3DXVECTOR3				g_RotModel;					//向き
D3DXMATRIX				g_mtxWoldModel;				//ワールドマトリックス
int						g_nIdex;					//影の番号
Model					g_aModel;					//モデルの構造体

//---------------------------
//グローバル変数
//---------------------------
HRESULT InitModel(void)
{
	LPDIRECT3DDEVICE9	pDevice;	//デバイスへのポインタ

	pDevice = GetDevice();			//デバイスの取得

	//---------------------------
	//Xファイルの読み込み
	//---------------------------
	D3DXLoadMeshFromX(	"data/Model/guys.x",
						D3DXMESH_SYSTEMMEM,
						pDevice,
						NULL,
						&g_pBuffMatModel,
						NULL,
						&g_pnNumMatModel,
						&g_pMeshModel);
	//位置向き初期化
	g_PosModel = (D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	g_RotModel = (D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	g_nIdex = 0;

	g_nIdex = SetShadow(g_PosModel, 50.0f, 50.0f);

	return S_OK;
}

//---------------------------
//終了処理
//---------------------------
void UninitModel(void)
{
	//---------------------------
	//メッシュ破棄
	//---------------------------
	if (g_pMeshModel != NULL)
	{
		g_pMeshModel->Release();
		g_pMeshModel = NULL;
	}

	//---------------------------
	//マテリアル破棄
	//---------------------------
	if (g_pBuffMatModel != NULL)
	{
		g_pBuffMatModel->Release();
		g_pBuffMatModel = NULL;
	}
}

//---------------------------
//更新処理
//---------------------------
void UpdateModel(void)
{
	Camera *pCamera;		//カメラの構造体のポインタ
	Camera *p0Camera;		//0番カメラ
	static int nSpan;		//クールタイム

	pCamera = GetCamera();	//カメラの情報を取得
	p0Camera = GetCamera();	//0番カメラ

	//---------------------------
	//四方向移動量
	//---------------------------
	for (int nCntCamera = 0; nCntCamera < MAX_CAMERA; nCntCamera++, pCamera++)
	{
		if (pCamera->bUse == true)
		{
			if (GetKeyboardPress(DIK_W) == true)
			{
				g_PosModel.x = g_PosModel.x + sinf(pCamera->Rot.y) * CAMERA_MOVE_SPEED;
				g_PosModel.z = g_PosModel.z + cosf(pCamera->Rot.y) * CAMERA_MOVE_SPEED;

				//カメラの向きに転換
				g_RotModel.y = pCamera->Rot.y + -D3DX_PI;

				//0番のカメラ追尾
				p0Camera->PosV.x = g_PosModel.x;
				p0Camera->PosV.y = g_PosModel.y + 25.0f;
				p0Camera->PosV.z = g_PosModel.z + 2.0f;
			}
			if (GetKeyboardPress(DIK_S) == true)
			{
				g_PosModel.x = g_PosModel.x - sinf(pCamera->Rot.y) * CAMERA_MOVE_SPEED;
				g_PosModel.z = g_PosModel.z - cosf(pCamera->Rot.y) * CAMERA_MOVE_SPEED;

				//カメラの向きに転換
				g_RotModel.y = pCamera->Rot.y;

				//0番のカメラ追尾
				p0Camera->PosV.x = g_PosModel.x;
				p0Camera->PosV.y = g_PosModel.y + 25.0f;
				p0Camera->PosV.z = g_PosModel.z - 2.0f;
			}
			if (GetKeyboardPress(DIK_A) == true)
			{
				g_PosModel.x = g_PosModel.x - cosf(pCamera->Rot.y) * CAMERA_MOVE_SPEED;
				g_PosModel.z = g_PosModel.z + sinf(pCamera->Rot.y) * CAMERA_MOVE_SPEED;

				//カメラの向きに転換
				g_RotModel.y = pCamera->Rot.y + D3DX_PI / 2;

				//0番のカメラ追尾
				p0Camera->PosV.x = g_PosModel.x - 2.0f;
				p0Camera->PosV.y = g_PosModel.y + 25.0f;
				p0Camera->PosV.z = g_PosModel.z;
			}
			if (GetKeyboardPress(DIK_D) == true)
			{
				g_PosModel.x = g_PosModel.x + cosf(pCamera->Rot.y) * CAMERA_MOVE_SPEED;
				g_PosModel.z = g_PosModel.z - sinf(pCamera->Rot.y) * CAMERA_MOVE_SPEED;

				//カメラの向きに転換
				g_RotModel.y = pCamera->Rot.y + -D3DX_PI / 2;

				//0番のカメラ追尾
				p0Camera->PosV.x = g_PosModel.x + 2.0f;
				p0Camera->PosV.y = g_PosModel.y + 25.0f;
				p0Camera->PosV.z = g_PosModel.z;
			}
			if (GetKeyboardPress(DIK_I) == true)
			{
				g_PosModel.y += 1.0f;
			}
			if (GetKeyboardPress(DIK_K) == true)
			{
				g_PosModel.y -= 1.0f;
			}
		}
	}
	pCamera-= MAX_CAMERA;

	//---------------------------
	//リセット
	//---------------------------
	if (GetKeyboardPress(DIK_RETURN) == true)
	{
		g_PosModel = (D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		g_RotModel = (D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	}
	//---------------------------
	//弾の発射
	//---------------------------
	nSpan++;
	if (GetKeyboardPress(DIK_Q) == true && nSpan > BULLET_SPAN)
	{
		SetBullet(g_PosModel, D3DXVECTOR3(0.0f, p0Camera->Rot.y, 0.0f), 25.0f, 25.0f, 0);
		nSpan = 0;
	}

	//自分の影
	SetPointShadow(g_nIdex, g_PosModel, 50.0f, 50.0f);
}

//---------------------------
//描画処理
//---------------------------
void DrawModel(void)
{
	LPDIRECT3DDEVICE9	pDevice;			//デバイスのポインタ

	pDevice = GetDevice();					//デバイスを取得する

	//---------------------------
	//マトリックスの設定
	//---------------------------
	D3DXMATRIX			mtxRot, mtxTrans;	//計算用マトリックス

	D3DXMatrixIdentity(&g_mtxWoldModel);	//マトリックス初期化

	//向きの設定
	D3DXMatrixRotationYawPitchRoll(	&mtxRot,
									g_RotModel.y,
									g_RotModel.x,
									g_RotModel.z);

	D3DXMatrixMultiply(	&g_mtxWoldModel,
						&g_mtxWoldModel,
						&mtxRot);
	//位置
	D3DXMatrixTranslation(	&mtxTrans,
							g_PosModel.x,
							g_PosModel.y,
							g_PosModel.z);

	D3DXMatrixMultiply(	&g_mtxWoldModel,
						&g_mtxWoldModel,
						&mtxTrans);
	//マトリックスの設定
	pDevice->SetTransform(	D3DTS_WORLD,
							&g_mtxWoldModel);
	//---------------------------
	//描画処理
	//---------------------------
	D3DMATERIAL9		matDef;				//マテリアルの一時保存
	D3DXMATERIAL		*pMat;				//マテリアルデータのポインタ

	//現在のマテリアルを取得
	pDevice->GetMaterial(&matDef);

	//マテリアルデータのポインタ
	pMat = (D3DXMATERIAL*)g_pBuffMatModel->GetBufferPointer();

	for (int nCntMat = 0; nCntMat < (int)g_pnNumMatModel; nCntMat++)
	{
		//マテリアルの設定
		pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

		//テクスチャの設定
		pDevice->SetTexture(0,
							NULL);

		//モデルパーツの描画
		g_pMeshModel->DrawSubset(nCntMat);
	}
	//一時保存してたやつをもどす
	pDevice->SetMaterial(&matDef);
}

//---------------------------
//モデル情報取得
//---------------------------
Model *GetModel(void)
{
	return &g_aModel;
}