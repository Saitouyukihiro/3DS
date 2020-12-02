#pragma once
#ifndef _MAIN_H_
#define _MAIN_H_


//---------------------------
//�C���N���[�h�t�@�C��
//---------------------------
#include <windows.h>
#include "d3dx9.h"

#define DIRECTINPUT_VERSION (0x0800) //�r���h���̌x���Ώ��p�}�N��
#include "dinput.h"	//���͏����ɕK�v
#include "xaudio2.h"

//---------------------------
//���C�u�����̃����N
//---------------------------
#pragma comment(lib,"d3d9.lib")		//�`��ɕK�v
#pragma comment(lib,"d3dx9.lib")	//[d3d9.lib]�̊g�����C�u����
#pragma comment(lib,"dxguid.lib")	//DirectX�R���|�[�l���g�i���i�j�g�p�ɕK�v
#pragma comment (lib, "winmm.lib")	//FPS�̕`��
#pragma comment(lib,"dinput8.lib")	//���͏����ɕK�v

//---------------------------
//�}�N����`
//---------------------------
#define SCREEN_WIDTH (1920) //�E�B���h�E�̕�
#define SCREEN_HEIGHT (1080) //�E�B���h�E�̍���
#define FVF_VERTEX_3D (D3DFVF_XYZ|D3DFVF_NORMAL|D3DFVF_DIFFUSE|D3DFVF_TEX1) //2D�̏_��Ȓ��_�t�H�[�}�b�g

//---------------------------
//�񋓌^.���[�h�̎��
//---------------------------
typedef enum
{
	MODE_TEST = 0,		//�^�C�g��
	MODE_MAX			//���X�g�̐�
} MODE;

//---------------------------
//�\���̂̒�`
//---------------------------
typedef struct
{
	D3DXVECTOR3 pos;	//���_���W
	D3DXVECTOR3 nor;	//�x�N�g��
	D3DCOLOR col;		//���_�J���[
	D3DXVECTOR2 tex;	//�e�N�X�`�����W
} VERTEX_3D;

//---------------------------
//�v���g�^�C�v�錾
//---------------------------
LPDIRECT3DDEVICE9 GetDevice(void);
void SetMode(MODE mode);
MODE GetMode(void);
MODE GetMode2(void);
#endif 