/**
* @file TrialLib.h
* @brief DirectX9�y��XInput�̃��C�u����
* @author Toshiya Matsuoka
* @date 2018/7/7
*/



#ifndef TRIALLIB_H
#define TRIALLIB_H

#include <Windows.h>
#include <d3dx9.h>
#include <dinput.h>
#include <D3dx9core.h>
#include <time.h>
#include <stdio.h>
#include<Xinput.h>

#include "TrialEnums.h"//������sln�t�H���_�ɓ���Ă�������

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "Xinput.lib")


enum PADSTATE
{
	PadOn,
	PadOff,
	PadPush,
	PadRelease
};
enum KEYSTATE
{
	KeyOff,
	KeyOn,
	KeyPush,
	KeyRelease
};

enum ButtonIndex
{
	ButtonA,
	ButtonB,
	ButtonX,
	ButtonY,
	ButtonRB,
	ButtonLB,
	ButtonStart,
	ButtonBack,
	ButtonUP,
	ButtonDOWN,
	ButtonLEFT,
	ButtonRIGHT,
	buttomindexMAX
};

enum Analog
{
	ANALOGUP,
	ANALOGDOWN,
	ANALOGLEFT,
	ANALOGRIGHT,
	ANALOGMAX
};



typedef struct CUSTOMVERTEX
{
	FLOAT	x, y, z, rhw;
	DWORD	color;
	FLOAT	tu, tv;
}CUSTOMVERTEX;

struct CENTRAL_STATE
{
	float x, y, scaleX, scaleY;
};
struct CIRCLE_STATE{
	int x, y, r;//���SX���W�A���SY���W�A���a

};

extern LPDIRECT3D9 g_pDirect3D;		//	Direct3D�̃C���^�[�t�F�C�X
extern LPDIRECT3DTEXTURE9	  g_pTexture[128];	//	�摜�̏������Ă����ׂ̃|�C���^�z��
extern IDirect3DDevice9*	  g_pD3Device;		//	Direct3D�̃f�o�C�X
extern D3DDISPLAYMODE		  g_D3DdisplayMode;
extern D3DPRESENT_PARAMETERS g_D3dPresentParameters;
extern LPDIRECTINPUT8 g_pDinput;
extern LPDIRECTINPUTDEVICE8 g_pKeyDevice;
extern LPD3DXFONT g_pFont[128];
extern PADSTATE PadState[buttomindexMAX];
extern PADSTATE PadOldState[buttomindexMAX];
extern BYTE KeyState[256];
extern BYTE KeyOldState[256];



LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//DirecrtXInitialize

/**
* @brief DirecrtX��Initialize
* @param hWnd�@�E�B���h�E�n���h��
* @param pSrcFile�@�摜�t�@�C����
* @return ���������S_OK�A���s��E_FAIL
*/
HRESULT InitD3d(HWND hWnd, LPCSTR pSrcFile);
/**
* @brief �t���X�N���[���pDirecrtX��Initialize
* @param hWnd�@�E�B���h�E�n���h��
* @param pSrcFile�@�摜�t�@�C����
* @return ���������S_OK�A���s��E_FAIL
*/
HRESULT InitD3dFullscreen(HWND hWnd, LPCSTR pSrcFile, int ResolutionWidth, int ResolutionHeight);
/**
* @brief DirecrtInput��Initialize
* @param hWnd�@�E�B���h�E�n���h��
* @return ���������S_OK�A���s��E_FAIL
*/
HRESULT InitDinput(HWND hWnd);
/**
* @brief DirecrtXDevice��Initialize
* @param hWnd�@�E�B���h�E�n���h��
* @param pSrcFile�@�摜�t�@�C����
* @return ���������S_OK�A���s��E_FAIL
*/
HRESULT InitDirectX(HWND hWnd, LPCSTR pSrcFile);
/**
* @brief �t���X�N���[���pDirecrtXDevice��Initialize
* @param hWnd�@�E�B���h�E�n���h��
* @param pSrcFile�@�摜�t�@�C����
* @return ���������S_OK�A���s��E_FAIL
*/
HRESULT InitDirectXFullscreen(HWND hWnd, LPCSTR pSrcFile, int ResolutionWidth, int ResolutionHeight);

void FreeDx();

//WINAPI�̋�E�B���h�E����

/**
* @brief �E�B���h�E����
* @param WndName �E�B���h�E�^�C�g���y�уN���X�̖���
* @param WIDTH ��ʕ�
* @param HEIGHT ��ʍ���
* @param hInst API�C���X�^���X�̃n���h��
* @param hInstance API�C���X�^���X�̃n���h��
* @param  IconIDI�@Icon��ID�@�s�v�Ȃ�NULL
* @param pSrcFile�@�摜�t�@�C����
* @return NULL�Ԃ��ƃE�B���h�E�����
*/
int InitWindow(LPCSTR WndName, int WIDTH, int HEIGHT, HINSTANCE hInst, HINSTANCE hInstance, int IconIDI, LPCSTR pSrcFile);

/**
* @brief �E�B���h�E����
* @param WndName �E�B���h�E�^�C�g���y�уN���X�̖���
* @param hWnd�@�E�B���h�E�n���h��
* @param WIDTH ��ʕ�
* @param HEIGHT ��ʍ���
* @param hInst API�C���X�^���X�̃n���h��
* @param hInstance API�C���X�^���X�̃n���h��
* @param  IconIDI�@Icon��ID�@�s�v�Ȃ�NULL
* @param pSrcFile�@�摜�t�@�C����
* @return NULL�Ԃ��ƃE�B���h�E�����
*/
int InitWindowEx(LPCSTR WndName, HWND* hWnd, int WIDTH, int HEIGHT, HINSTANCE hInst, HINSTANCE hInstance, int IconIDI, LPCSTR pSrcFile);

/**
* @brief �t���X�N���[���p�E�B���h�E����
* @param WndName �E�B���h�E�^�C�g���y�уN���X�̖���
* @param hWnd�@�E�B���h�E�n���h��
* @param WIDTH ��ʕ�
* @param HEIGHT ��ʍ���
* @param hInst API�C���X�^���X�̃n���h��
* @param hInstance API�C���X�^���X�̃n���h��
* @param  IconIDI�@Icon��ID�@�s�v�Ȃ�NULL
* @param pSrcFile�@�摜�t�@�C����
* @return NULL�Ԃ��ƃE�B���h�E�����
*/
int InitWindowFullscreenEx(LPCSTR WndName, HWND* hWnd, int WIDTH, int HEIGHT, HINSTANCE hInst, HINSTANCE hInstance, int IconIDI, LPCSTR pSrcFile);

/**
* @brief �b��60�t���[�����[�v������
* @param gameroop(void) �����̍쐬�����Q�[�������֐������邱��
* @return �v���O�����I������(int)msg.wParam
*/
int FlameRoop(void gameroop(void));

//�`��

/**
* @brief �`��J�n�֐�
* @sa EndSetTexture()
* @detail ��L�֐��ƃZ�b�g�Ŏg������
*/
void BeginSetTexture();
/**
* @brief �`��I���֐�
* @sa BeginSetTexture()
* @detail ��L�֐��ƃZ�b�g�Ŏg������
*/
void EndSetTexture();


/**
* @brief �摜�ǂݍ���
* @param pTextureName �ǂݍ��މ摜�t�@�C����
* @param TexNum �摜�̊i�[��z��ԍ�
*/
void ReadInTexture(LPCSTR pTextureName, int TexNum);


/**
* @brief �摜�\��
* @param Vertex �`�悷��4���_���
* @param TexNum �摜�̊i�[�z��ԍ�
* @detail CUSTOMVERTEX�ϐ��͎����ŗp�ӂ��邱��
*/
void SetUpTexture(CUSTOMVERTEX* Vertex, int TexNum);

//2���_�ݒ�`��

/**
* @brief 2���_���w�肵�摜��`�悷��
* @param Left ���[
* @param Top ��[
* @param Right �E�[
* @param Bottom ���[
* @param TexNum �摜�̊i�[�z��ԍ�
*/
void EasyCreateSquareVertex(float Left, float Top, float Right, float Bottom, int TexNum);
/**
* @brief 2���_���w�肵�摜��`�悷��
* @param Left ���[
* @param Top ��[
* @param Right �E�[
* @param Bottom ���[
* @param color �F
* @param TexNum �摜�̊i�[�z��ԍ�
*/
void EasyCreateSquareVertexColor(float Left, float Top, float Right, float Bottom, DWORD color, int TexNum);

/**
* @brief 2���_���w�肵�摜��`�悷��
* @param Left ���[
* @param Top ��[
* @param Right �E�[
* @param Bottom ���[
* @param color �F
* @param tu �摜�؂��荶�[
* @param tv �摜�؂����[
* @param scaleTu �摜�̐؂��蕝
* @param scaleTv �摜�̐؂��荂��
* @param TexNum �摜�̊i�[�z��ԍ�
*/
void EasyCreateSquareVertexEx( float Left, float Top, float Right, float Bottom, DWORD  color, float tu, float tv, float scaleTu, float scaleTv, int TexNum);

//RECT����2���_�ݒ�`��

/**
* @brief 2���_���w�肵�摜��`�悷��
* @param Vertex RECT�\���̂Œ��_���w�肷��
* @param TexNum �摜�̊i�[�z��ԍ�
*/
void EasyCreateRECTVertex(RECT Vertex, int TexNum);
/**
* @brief 2���_���w�肵�摜��`�悷��
* @param Vertex RECT�\���̂Œ��_���w�肷��
* @param color �F
* @param TexNum �摜�̊i�[�z��ԍ�
*/
void EasyCreateRECTVertexColor(RECT Vertex, DWORD color, int TexNum);
/**
* @brief 2���_���w�肵�摜��`�悷��
* @param Vertex RECT�\���̂Œ��_���w�肷��
* @param color �F
* @param tu �摜�؂��荶�[
* @param tv �摜�؂����[
* @param scaleTu �摜�̐؂��蕝
* @param scaleTv �摜�̐؂��荂��
* @param TexNum �摜�̊i�[�z��ԍ�
*/
void EasyCreateRECTVertexEx(RECT Vertex, DWORD color, float tu, float tv, float scaleTu, float scaleTv, int TexNum);

//4���_�ݒ�

/**
* @brief CUSTOMVERTEX�ϐ��ɒl������
* @param Vertex ���ꕨ
* @param Central ����钆�S���
*/
void CreateSquareVertex(CUSTOMVERTEX* Vertex, CENTRAL_STATE Central);
/**
* @brief CUSTOMVERTEX�ϐ��ɒl������
* @param Vertex ���ꕨ
* @param Central ����钆�S���
* @param color �F
* @param tu �摜�؂��荶�[
* @param tv �摜�؂����[
* @param scaleTu �摜�̐؂��蕝
* @param scaleTv �摜�̐؂��荂��
*/
void CreateSquareVertexEx(CUSTOMVERTEX* Vertex, CENTRAL_STATE Central, float tu, float tv, float scaleTu, float scaleTv);
/**
* @brief CUSTOMVERTEX�ϐ��ɒl������
* @param Vertex ���ꕨ
* @param Central ����钆�S���
* @param color �F
* @param tu �摜�؂��荶�[
* @param tv �摜�؂����[
* @param scaleTu �摜�̐؂��蕝
* @param scaleTv �摜�̐؂��荂��
*/
void CreateSquareVertexColorEx(CUSTOMVERTEX* Vertex, CENTRAL_STATE Central, DWORD  color, float tu, float tv, float scaleTu, float scaleTv);
/**
* @brief CUSTOMVERTEX�ϐ��ɒl������
* @param Vertex ���ꕨ
* @param Central ����钆�S���
* @param color �F
*/
void CreateSquareVertexColor(CUSTOMVERTEX* Vertex, CENTRAL_STATE Central, DWORD  color);


//DX�t�H���g

/**
* @brief �����ݒ�
* @param WordHeight �����̍���
* @param WordWidth �����̕�
* @param CharSet �L�����Z�b�g�i�p���Ȃ�P�C�V�t�gJIS�Ȃ�128�j
* @param FontName �g�p����t�H���g��
* @param FontNum �\�������ݒ�̊i�[��z��ԍ�
*/
void SetUpFont(int WordHeight, int WordWidth, int CharSet, LPCSTR FontName, int FontNum);
/**
* @brief �`��ݒ�
* @param Texts �\�����e
* @param Vertex �\���͈�
* @param TextFormat �t�H�[�}�b�g
* @param color �F
* @param FontNum �\�������ݒ�̊i�[�z��ԍ�
*/
void WriteWord(LPCSTR Texts, RECT Vertex, int TextFormat, int color, int FontNum);

//��]�A�~�^���֐�
void RevolveAndCircularMotion(CUSTOMVERTEX* Vertex, float Rad, CENTRAL_STATE Central, float motionRadius);
//��]�A�ȉ~�^���֐�
void RevolveAndOvalCircularMotion(CUSTOMVERTEX* Vertex, float Rad, CENTRAL_STATE Central, float motionRadiusX, float motionRadiusY);
//Z����]
void RevolveZ(CUSTOMVERTEX* Vertex, float Rad, CENTRAL_STATE Central);
void RevolveZEX(CUSTOMVERTEX* Vertex, float Rad, CENTRAL_STATE Central, float 	RevolvingShaftX, float 	RevolvingShaftY);
//Y����]
void RevolveY(CUSTOMVERTEX* Vertex, float Rad, CENTRAL_STATE Central);
void RevolveYEX(CUSTOMVERTEX* Vertex, float Rad, CENTRAL_STATE Central, float RevolvingShaftX, float RevolvingShaftZ);
//X����]
void RevolveX(CUSTOMVERTEX* Vertex, float Rad, CENTRAL_STATE Central);
void RevolveXEX(CUSTOMVERTEX* Vertex, float Rad, CENTRAL_STATE Central, float RevolvingShaftY, float RevolvingShaftZ);
//�~�^��
void CircularMotion(CUSTOMVERTEX* Vertex, float Rad, CENTRAL_STATE Central, float motionRadius);
//�ȉ~�^��
void OvalCircularMotion(CUSTOMVERTEX* Vertex, float Rad, CENTRAL_STATE Central, float motionRadiusX, float motionRadiusY);

//Dinput�L�[�{�[�h
bool InputKEY(int KeyName);
void CheckKeyState(int KeyName);
//XInput
void GetControl(int GamePadNumber);
PADSTATE GetButton(ButtonIndex index);
bool GetAnalogL(Analog analogstate);
bool GetAnalogR(Analog AnalogState);
void CheckButtonState(WORD, int);
void BottonCheck();
//�����蔻��
////�~�Ɖ~�̓����蔻��
bool CtoCContact(float PosX1, float PosY1, float Radius1, float PosX2, float PosY2, float Radius2);
bool CtoCContact(CIRCLE_STATE* a, CIRCLE_STATE* b);
////��`�Ƌ�`�̓����蔻��
bool BtoBContact(CENTRAL_STATE* central1, CENTRAL_STATE* central2);
//�s���G���A����
////��`���w��͈͊O�ɏo�Ȃ��悤�ɂ���
void MoveInToErea(CENTRAL_STATE* central, float Left, float Top, float Right, float Bottom);

#endif TRIALLIB_H