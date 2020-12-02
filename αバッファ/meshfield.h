#pragma once
#ifndef _MESHFIELD_H_
#define _MESHFIELD_H_
//---------------------------
//インクルードファイル
//---------------------------
#include "main.h"

//---------------------------
//マクロ定義
//---------------------------
#define MAX_FIELD (4)		//メッシュフィールドの数
#define MAX_TEX (1)			//テクスチャの数
#define MS_FLOO_X (1.0f)	//床の半径X
#define MS_FLOO_Z (1.0f)	//床の半径Z
#define MAX_VTX_X (4)		//横ブロックの数
#define MAX_VTX_Z (4)		//縦ブロックの数
#define VTX_NUM_MAX ((MAX_VTX_X + 1) * (MAX_VTX_Z + 1))				//全体頂点の数
#define POLY_NUM (2 * MAX_VTX_X * MAX_VTX_Z + (MAX_VTX_Z * 4) - 4))	//△の数
#define IDX_NUM ((MAX_VTX_X + 1) * (MAX_VTX_Z + 1) + (MAX_VTX_Z - 1) * (MAX_VTX_X + 3))	//インデックスの数

//---------------------------
//列挙型
//---------------------------
typedef enum
{
	STATE_FLOO = 0,		//床形
	STATE_MAX			//リストの数
} MESH_STATE;

//---------------------------
//構造体
//---------------------------
typedef struct
{
	D3DXVECTOR3	Pos;		//位置
	D3DXVECTOR3 Rot;		//向き
	D3DXMATRIX mtxWold;		//ワールドマトリックス
	float fWidth;			//幅
	float fHeiht;			//高さ
	float fDepht;			//奥行
	MESH_STATE aState;		//どんな形
	int nTex;				//テクスチャ
	bool bUse;				//使ってるか
} Field;
//---------------------------
//プロトタイプ宣言
//---------------------------
HRESULT InitMeshfield(void);
void UninitMeshfield(void);
void UpdateMeshfield(void);
void DrawMeshfield(void);
void SetField(D3DXVECTOR3 rot, D3DXVECTOR3 pos, float fWidth, float fHeight, float fDepht, int nTex, MESH_STATE aState);	//向き、位置、幅、高さ、奥行、テクスチャ、形
bool ColisionFeild(D3DXVECTOR3 *pos, D3DXVECTOR3 *posold, D3DXVECTOR3 *move, float fWidth, float fHeight, float fDepht, int nType);	//位置、前回の位置、移動量、幅、高さ、奥行、種類
#endif