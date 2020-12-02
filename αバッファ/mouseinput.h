#pragma once
#ifndef _MOUSE_INPUT_H_
#define _MOUSE_INPUT_H_

//---------------------------
//�C���N���[�h�t�@�C��
//---------------------------
#include "main.h"

//---------------------------
//�}�N����`
//---------------------------
#define MOUSE_LEFT_BOTTON (0) //���N���b�N
#define MOUSE_RIGHT_BOTTON (1) //�E�N���b�N
#define MOUSE_WHEEL_BOTTON (2) //�z�C�[���N���b�N

//---------------------------
//�v���g�^�C�v�錾
//---------------------------
HRESULT InitMouse(HINSTANCE hInstance, HWND hWnd);
void UninitMouse(void);
void UpdateMouse(void);
bool MouseDowan(int Botton_Type);
#endif