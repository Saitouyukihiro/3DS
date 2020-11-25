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
#define MS_FLOO_X (1000)	//床のX
#define MS_FLOO_Z (1000)	//床のZ

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
} Field;
//---------------------------
//プロトタイプ宣言
//---------------------------
HRESULT InitMeshfield(void);
void UninitMeshfield(void);
void UpdateMeshfield(void);
void DrawMeshfield(void);
void SetField(D3DXVECTOR3 pos, float fWidth, float fHeight);	//位置、幅、高さ
#endif