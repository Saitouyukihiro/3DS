#include "mouseinput.h"

//---------------------------
//�}�N����`
//---------------------------
#define NUM_BOTTON_MAX (4)	//�{�^���̍ő吔

//---------------------------
//�O���[�o���ϐ�
//---------------------------
LPDIRECTINPUT8 g_pMouseInput = NULL;				//DirectInput�I�u�W�F�N�g�̃|�C���^
LPDIRECTINPUTDEVICE8 g_pDevMouse = NULL;			//���̓f�o�C�X�i�}�E�X�j�ւ̃|�C���^
DIMOUSESTATE g_aMouseold;							//�O��̃}�E�X
DIMOUSESTATE g_aMouse;								//�}�E�X

//---------------------------
//����������
//---------------------------
HRESULT InitMouse(HINSTANCE hInstance, HWND hWnd)
{
	//DirectInput�I�u�W�F�N�g�̍쐬
	if (FAILED(DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&g_pMouseInput, NULL)))
	{
		return E_FAIL;
	}
	if (FAILED(g_pMouseInput->CreateDevice(GUID_SysMouse, &g_pDevMouse, NULL)))
	{
		return E_FAIL;
	}

	//�ȗ�
	// �f�[�^�t�H�[�}�b�g��ݒ�
	if (FAILED(g_pDevMouse->SetDataFormat(&c_dfDIMouse)))
	{
		return E_FAIL;
	}

	// �������[�h��ݒ�
	if (FAILED(g_pDevMouse->SetCooperativeLevel(hWnd, (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE))))
	{
		return E_FAIL;
	}

	// �}�E�X�ւ̃A�N�Z�X�����l��(���͐���J�n)
	g_pDevMouse->Acquire();

	return S_OK;
}

//---------------------------
//�I������
//---------------------------
void UninitMouse(void)
{
	//���̓f�o�C�X�̊J��
	if (g_pDevMouse != NULL)
	{
		g_pDevMouse->Unacquire();
		g_pDevMouse->Release();
		g_pDevMouse = NULL;
	}
	//DirectInput�I�u�W�F�N�g�̊J��
	if (g_pMouseInput != NULL)
	{
		g_pMouseInput->Release();
		g_pMouseInput = NULL;
	}
}

//---------------------------
//�X�V����
//---------------------------
void UpdateMouse(void)
{
	//�O��̃}�E�X�̏��
	g_aMouseold = g_aMouse;

	// �ŐV�̃}�E�X�̏�Ԃ��X�V
	HRESULT	hr = g_pDevMouse->GetDeviceState(sizeof(DIMOUSESTATE), &g_aMouse);
	if (FAILED(hr))
	{
		g_pDevMouse->Acquire();
		hr = g_pDevMouse->GetDeviceState(sizeof(DIMOUSESTATE), &g_aMouse);
	}
}

//---------------------------
//�{�^��������
//---------------------------
bool MouseDowan(int Botton_Type)
{
	return (g_aMouse.rgbButtons[Botton_Type] & 0x80) ? true : false;
}
