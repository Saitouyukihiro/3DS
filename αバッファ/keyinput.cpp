#include "keyinput.h"

//---------------------------
//�}�N����`
//---------------------------
#define NUM_KEY_MAX (256)//�L�[�̍ő吔

//---------------------------
//�O���[�o���ϐ�
//---------------------------
LPDIRECTINPUT8 g_pKeyInput = NULL;				//DirectInput�I�u�W�F�N�g�̃|�C���^
LPDIRECTINPUTDEVICE8 g_pDevKeyboard = NULL; //���̓f�o�C�X�i�L�[�{�[�h�j�ւ̃|�C���^
BYTE g_aKeyState[NUM_KEY_MAX];				//�L�[�{�[�h�̓��͏��i�v���X���j
BYTE g_aKeyStateTrigger[NUM_KEY_MAX];		//�L�[�{�[�h�̓��͏�� (�g���K�[)
BYTE g_aKeyStateRelease[NUM_KEY_MAX];		//�L�[�{�[�h�̓��͏�� (�����[�X)

//---------------------------
//����������
//---------------------------
HRESULT InitKeyboard(HINSTANCE hInstance, HWND hWnd)
{
	//DirectInput�I�u�W�F�N�g�̍쐬
	if (FAILED(DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&g_pKeyInput, NULL)))
	{
		return E_FAIL;
	}
	if (FAILED(g_pKeyInput->CreateDevice(GUID_SysKeyboard, &g_pDevKeyboard, NULL)))
	{
		return E_FAIL;
	}

	//�ȗ�
	// �f�[�^�t�H�[�}�b�g��ݒ�
	if (FAILED(g_pDevKeyboard->SetDataFormat(&c_dfDIKeyboard)))
	{
		return E_FAIL;
	}

	// �������[�h��ݒ�
	if (FAILED(g_pDevKeyboard->SetCooperativeLevel(hWnd, (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE))))
	{
		return E_FAIL;
	}

	// �L�[�{�[�h�ւ̃A�N�Z�X�����l��(���͐���J�n)
	g_pDevKeyboard->Acquire();

	return S_OK;
}

//---------------------------
//�I������
//---------------------------
void UninitKeyboard(void)
{
	//���̓f�o�C�X�̊J��
	if (g_pDevKeyboard != NULL)
	{
		g_pDevKeyboard->Unacquire();
		g_pDevKeyboard->Release();
		g_pDevKeyboard = NULL;
	}
	//DirectInput�I�u�W�F�N�g�̊J��
	if (g_pKeyInput != NULL)
	{
		g_pKeyInput->Release();
		g_pKeyInput = NULL;
	}
}

//---------------------------
//�X�V����
//---------------------------
void UpdateKeyboard(void)
{
	BYTE aKeyState[NUM_KEY_MAX];
	int nCntKey;

	//���̓f�o�C�X����f�[�^�擾
	if (SUCCEEDED(g_pDevKeyboard->GetDeviceState(sizeof(aKeyState), &aKeyState[0])))
	{
		for (nCntKey = 0; nCntKey < NUM_KEY_MAX; nCntKey++)
		{
			g_aKeyStateTrigger[nCntKey] = (g_aKeyState[nCntKey] ^ aKeyState[nCntKey]) & aKeyState[nCntKey];
			g_aKeyStateRelease[nCntKey] = (g_aKeyState[nCntKey] & aKeyState[nCntKey]) ^ aKeyState[nCntKey];
			g_aKeyState[nCntKey] = aKeyState[nCntKey];	//�L�[�{�[�h�̓��͏��ۑ�
		}
	}
	else
	{
		g_pDevKeyboard->Acquire();
	}
}

//---------------------------
//�L�[�{�[�[�h�̏����擾
//---------------------------
bool GetKeyboardPress(int nKey)
{
	return (g_aKeyState[nKey] & 0x80) ? true : false;
}

bool GetKeyboardTrigger(int nKey)
{
	return (g_aKeyStateTrigger[nKey] & 0x80) ? true : false;
}

bool GetKeyboardRelease(int nKey)
{
	return (g_aKeyStateRelease[nKey] & 0x80) ? true : false;
}