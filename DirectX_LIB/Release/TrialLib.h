#ifndef TRIALLIB_H
#define TRIALLIB_H

#include <Windows.h>
#include <d3dx9.h>
#include <dinput.h>
#include <D3dx9core.h>
#include <time.h>
#include <stdio.h>
#include<Xinput.h>

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "Xinput.lib")


enum TEXTURE
{
	HOGE_TEX,
	BOO_TEX,
	TEXMAX
};

enum FONT {
	FONT,
	FONTMAX
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
extern LPDIRECT3DTEXTURE9	  g_pTexture[TEXMAX];	//	�摜�̏������Ă����ׂ̃|�C���^�z��
extern IDirect3DDevice9*	  g_pD3Device;		//	Direct3D�̃f�o�C�X
extern D3DDISPLAYMODE		  g_D3DdisplayMode;
extern D3DPRESENT_PARAMETERS g_D3dPresentParameters;
extern LPDIRECTINPUT8 g_pDinput;
extern LPDIRECTINPUTDEVICE8 g_pKeyDevice;
extern LPD3DXFONT g_pFont[FONTMAX];

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HRESULT InitD3d(HWND);
HRESULT InitDinput(HWND);

void FreeDx();
//WINAPI�̋�E�B���h�E����
int InitWindow(LPCSTR WndName, int WIDTH, int HEIGHT, HINSTANCE hInst, HINSTANCE hInstance, int IconIDI, LPCSTR pSrcFile);

//�摜�ǂݍ���
void ReadInTexture(LPCSTR pTextureName, int TexNum);

//�摜�\��
void SetUpTexture(CUSTOMVERTEX* Vertex, int TexNum);

//2���_�ݒ�`��
void EasyCreateSquareVertex(float Left, float Top, float Right, float Bottom, int TexNum);
void EasyCreateSquareVertexColor(float Left, float Top, float Right, float Bottom, DWORD color, int TexNum);
void EasyCreateSquareVertexEx( float Left, float Top, float Right, float Bottom, DWORD  color, float tu, float tv, float scaleTu, float scaleTv, int TexNum);

//RECT����2���_�ݒ�`��
void EasyCreateRECTVertex(RECT Vertex, int TexNum);
void EasyCreateRECTVertexColor(RECT Vertex, DWORD color, int TexNum);
void EasyCreateRECTVertexEx(RECT Vertex, DWORD color, float tu, float tv, float scaleTu, float scaleTv, int TexNum);

//4���_�ݒ�
void CreateSquareVertex(CUSTOMVERTEX* Vertex, CENTRAL_STATE Central);
void CreateSquareVertexEx(CUSTOMVERTEX* Vertex, CENTRAL_STATE Central, float tu, float tv, float scaleTu, float scaleTv);
void CreateSquareVertexColorEx(CUSTOMVERTEX* Vertex, CENTRAL_STATE Central, DWORD  color, float tu, float tv, float scaleTu, float scaleTv);
void CreateSquareVertexColor(CUSTOMVERTEX* Vertex, CENTRAL_STATE Central, DWORD  color);

//DX�t�H���g
//�����ݒ�
void SetUpFont(int WordHeight, int WordWidth, int CharSet, LPCSTR FontName, int FontNum);
//�`��ݒ�
void WriteWord(LPCSTR Texts, RECT Vertex, int TextFormat, int color, int FontNum);

//��]�A�~�^���֐�
void RevolveAndCircularMotion(CUSTOMVERTEX* Vertex, float Rad, CENTRAL_STATE Central, float motionRadius);
//Z����]
void RevolveZ(CUSTOMVERTEX* Vertex, float Rad, CENTRAL_STATE Central);
//Y����]
void RevolveY(CUSTOMVERTEX* Vertex, float Rad, CENTRAL_STATE Central);
//X����]
void RevolveX(CUSTOMVERTEX* Vertex, float Rad, CENTRAL_STATE Central);
//�~�^��
void CircularMotion(CUSTOMVERTEX* Vertex, float Rad, CENTRAL_STATE Central, float motionRadius);
//Dinput�L�[�{�[�h
bool InputKEY(int KeyName);

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