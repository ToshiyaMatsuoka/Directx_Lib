/**
* @file TrialLib.h
* @brief DirectX9及びXInputのライブラリ
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

#include "TrialEnums.h"//自分のslnフォルダに入れておくこと

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
	int x, y, r;//中心X座標、中心Y座標、半径

};

extern LPDIRECT3D9 g_pDirect3D;		//	Direct3Dのインターフェイス
extern LPDIRECT3DTEXTURE9	  g_pTexture[128];	//	画像の情報を入れておく為のポインタ配列
extern IDirect3DDevice9*	  g_pD3Device;		//	Direct3Dのデバイス
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
* @brief DirecrtXのInitialize
* @param hWnd　ウィンドウハンドル
* @param pSrcFile　画像ファイル名
* @return 成功すればS_OK、失敗でE_FAIL
*/
HRESULT InitD3d(HWND hWnd, LPCSTR pSrcFile);
/**
* @brief フルスクリーン用DirecrtXのInitialize
* @param hWnd　ウィンドウハンドル
* @param pSrcFile　画像ファイル名
* @return 成功すればS_OK、失敗でE_FAIL
*/
HRESULT InitD3dFullscreen(HWND hWnd, LPCSTR pSrcFile, int ResolutionWidth, int ResolutionHeight);
/**
* @brief DirecrtInputのInitialize
* @param hWnd　ウィンドウハンドル
* @return 成功すればS_OK、失敗でE_FAIL
*/
HRESULT InitDinput(HWND hWnd);
/**
* @brief DirecrtXDeviceのInitialize
* @param hWnd　ウィンドウハンドル
* @param pSrcFile　画像ファイル名
* @return 成功すればS_OK、失敗でE_FAIL
*/
HRESULT InitDirectX(HWND hWnd, LPCSTR pSrcFile);
/**
* @brief フルスクリーン用DirecrtXDeviceのInitialize
* @param hWnd　ウィンドウハンドル
* @param pSrcFile　画像ファイル名
* @return 成功すればS_OK、失敗でE_FAIL
*/
HRESULT InitDirectXFullscreen(HWND hWnd, LPCSTR pSrcFile, int ResolutionWidth, int ResolutionHeight);

void FreeDx();

//WINAPIの空ウィンドウ生成

/**
* @brief ウィンドウ生成
* @param WndName ウィンドウタイトル及びクラスの名称
* @param WIDTH 画面幅
* @param HEIGHT 画面高さ
* @param hInst APIインスタンスのハンドル
* @param hInstance APIインスタンスのハンドル
* @param  IconIDI　IconのID　不要ならNULL
* @param pSrcFile　画像ファイル名
* @return NULL返すとウィンドウを閉じる
*/
int InitWindow(LPCSTR WndName, int WIDTH, int HEIGHT, HINSTANCE hInst, HINSTANCE hInstance, int IconIDI, LPCSTR pSrcFile);

/**
* @brief ウィンドウ生成
* @param WndName ウィンドウタイトル及びクラスの名称
* @param hWnd　ウィンドウハンドル
* @param WIDTH 画面幅
* @param HEIGHT 画面高さ
* @param hInst APIインスタンスのハンドル
* @param hInstance APIインスタンスのハンドル
* @param  IconIDI　IconのID　不要ならNULL
* @param pSrcFile　画像ファイル名
* @return NULL返すとウィンドウを閉じる
*/
int InitWindowEx(LPCSTR WndName, HWND* hWnd, int WIDTH, int HEIGHT, HINSTANCE hInst, HINSTANCE hInstance, int IconIDI, LPCSTR pSrcFile);

/**
* @brief フルスクリーン用ウィンドウ生成
* @param WndName ウィンドウタイトル及びクラスの名称
* @param hWnd　ウィンドウハンドル
* @param WIDTH 画面幅
* @param HEIGHT 画面高さ
* @param hInst APIインスタンスのハンドル
* @param hInstance APIインスタンスのハンドル
* @param  IconIDI　IconのID　不要ならNULL
* @param pSrcFile　画像ファイル名
* @return NULL返すとウィンドウを閉じる
*/
int InitWindowFullscreenEx(LPCSTR WndName, HWND* hWnd, int WIDTH, int HEIGHT, HINSTANCE hInst, HINSTANCE hInstance, int IconIDI, LPCSTR pSrcFile);

/**
* @brief 秒間60フレームループさせる
* @param gameroop(void) 自分の作成したゲーム処理関数を入れること
* @return プログラム終了時に(int)msg.wParam
*/
int FlameRoop(void gameroop(void));

//描画

/**
* @brief 描画開始関数
* @sa EndSetTexture()
* @detail 上記関数とセットで使うこと
*/
void BeginSetTexture();
/**
* @brief 描画終了関数
* @sa BeginSetTexture()
* @detail 上記関数とセットで使うこと
*/
void EndSetTexture();


/**
* @brief 画像読み込み
* @param pTextureName 読み込む画像ファイル名
* @param TexNum 画像の格納先配列番号
*/
void ReadInTexture(LPCSTR pTextureName, int TexNum);


/**
* @brief 画像表示
* @param Vertex 描画する4頂点情報
* @param TexNum 画像の格納配列番号
* @detail CUSTOMVERTEX変数は自分で用意すること
*/
void SetUpTexture(CUSTOMVERTEX* Vertex, int TexNum);

//2頂点設定描画

/**
* @brief 2頂点を指定し画像を描画する
* @param Left 左端
* @param Top 上端
* @param Right 右端
* @param Bottom 下端
* @param TexNum 画像の格納配列番号
*/
void EasyCreateSquareVertex(float Left, float Top, float Right, float Bottom, int TexNum);
/**
* @brief 2頂点を指定し画像を描画する
* @param Left 左端
* @param Top 上端
* @param Right 右端
* @param Bottom 下端
* @param color 色
* @param TexNum 画像の格納配列番号
*/
void EasyCreateSquareVertexColor(float Left, float Top, float Right, float Bottom, DWORD color, int TexNum);

/**
* @brief 2頂点を指定し画像を描画する
* @param Left 左端
* @param Top 上端
* @param Right 右端
* @param Bottom 下端
* @param color 色
* @param tu 画像切り取り左端
* @param tv 画像切り取り上端
* @param scaleTu 画像の切り取り幅
* @param scaleTv 画像の切り取り高さ
* @param TexNum 画像の格納配列番号
*/
void EasyCreateSquareVertexEx( float Left, float Top, float Right, float Bottom, DWORD  color, float tu, float tv, float scaleTu, float scaleTv, int TexNum);

//RECT引数2頂点設定描画

/**
* @brief 2頂点を指定し画像を描画する
* @param Vertex RECT構造体で頂点を指定する
* @param TexNum 画像の格納配列番号
*/
void EasyCreateRECTVertex(RECT Vertex, int TexNum);
/**
* @brief 2頂点を指定し画像を描画する
* @param Vertex RECT構造体で頂点を指定する
* @param color 色
* @param TexNum 画像の格納配列番号
*/
void EasyCreateRECTVertexColor(RECT Vertex, DWORD color, int TexNum);
/**
* @brief 2頂点を指定し画像を描画する
* @param Vertex RECT構造体で頂点を指定する
* @param color 色
* @param tu 画像切り取り左端
* @param tv 画像切り取り上端
* @param scaleTu 画像の切り取り幅
* @param scaleTv 画像の切り取り高さ
* @param TexNum 画像の格納配列番号
*/
void EasyCreateRECTVertexEx(RECT Vertex, DWORD color, float tu, float tv, float scaleTu, float scaleTv, int TexNum);

//4頂点設定

/**
* @brief CUSTOMVERTEX変数に値を入れる
* @param Vertex 入れ物
* @param Central 入れる中心情報
*/
void CreateSquareVertex(CUSTOMVERTEX* Vertex, CENTRAL_STATE Central);
/**
* @brief CUSTOMVERTEX変数に値を入れる
* @param Vertex 入れ物
* @param Central 入れる中心情報
* @param color 色
* @param tu 画像切り取り左端
* @param tv 画像切り取り上端
* @param scaleTu 画像の切り取り幅
* @param scaleTv 画像の切り取り高さ
*/
void CreateSquareVertexEx(CUSTOMVERTEX* Vertex, CENTRAL_STATE Central, float tu, float tv, float scaleTu, float scaleTv);
/**
* @brief CUSTOMVERTEX変数に値を入れる
* @param Vertex 入れ物
* @param Central 入れる中心情報
* @param color 色
* @param tu 画像切り取り左端
* @param tv 画像切り取り上端
* @param scaleTu 画像の切り取り幅
* @param scaleTv 画像の切り取り高さ
*/
void CreateSquareVertexColorEx(CUSTOMVERTEX* Vertex, CENTRAL_STATE Central, DWORD  color, float tu, float tv, float scaleTu, float scaleTv);
/**
* @brief CUSTOMVERTEX変数に値を入れる
* @param Vertex 入れ物
* @param Central 入れる中心情報
* @param color 色
*/
void CreateSquareVertexColor(CUSTOMVERTEX* Vertex, CENTRAL_STATE Central, DWORD  color);


//DXフォント

/**
* @brief 文字設定
* @param WordHeight 文字の高さ
* @param WordWidth 文字の幅
* @param CharSet キャラセット（英字なら１，シフトJISなら128）
* @param FontName 使用するフォント名
* @param FontNum 表示文字設定の格納先配列番号
*/
void SetUpFont(int WordHeight, int WordWidth, int CharSet, LPCSTR FontName, int FontNum);
/**
* @brief 描画設定
* @param Texts 表示内容
* @param Vertex 表示範囲
* @param TextFormat フォーマット
* @param color 色
* @param FontNum 表示文字設定の格納配列番号
*/
void WriteWord(LPCSTR Texts, RECT Vertex, int TextFormat, int color, int FontNum);

//回転、円運動関数
void RevolveAndCircularMotion(CUSTOMVERTEX* Vertex, float Rad, CENTRAL_STATE Central, float motionRadius);
//回転、楕円運動関数
void RevolveAndOvalCircularMotion(CUSTOMVERTEX* Vertex, float Rad, CENTRAL_STATE Central, float motionRadiusX, float motionRadiusY);
//Z軸回転
void RevolveZ(CUSTOMVERTEX* Vertex, float Rad, CENTRAL_STATE Central);
void RevolveZEX(CUSTOMVERTEX* Vertex, float Rad, CENTRAL_STATE Central, float 	RevolvingShaftX, float 	RevolvingShaftY);
//Y軸回転
void RevolveY(CUSTOMVERTEX* Vertex, float Rad, CENTRAL_STATE Central);
void RevolveYEX(CUSTOMVERTEX* Vertex, float Rad, CENTRAL_STATE Central, float RevolvingShaftX, float RevolvingShaftZ);
//X軸回転
void RevolveX(CUSTOMVERTEX* Vertex, float Rad, CENTRAL_STATE Central);
void RevolveXEX(CUSTOMVERTEX* Vertex, float Rad, CENTRAL_STATE Central, float RevolvingShaftY, float RevolvingShaftZ);
//円運動
void CircularMotion(CUSTOMVERTEX* Vertex, float Rad, CENTRAL_STATE Central, float motionRadius);
//楕円運動
void OvalCircularMotion(CUSTOMVERTEX* Vertex, float Rad, CENTRAL_STATE Central, float motionRadiusX, float motionRadiusY);

//Dinputキーボード
bool InputKEY(int KeyName);
void CheckKeyState(int KeyName);
//XInput
void GetControl(int GamePadNumber);
PADSTATE GetButton(ButtonIndex index);
bool GetAnalogL(Analog analogstate);
bool GetAnalogR(Analog AnalogState);
void CheckButtonState(WORD, int);
void BottonCheck();
//当たり判定
////円と円の当たり判定
bool CtoCContact(float PosX1, float PosY1, float Radius1, float PosX2, float PosY2, float Radius2);
bool CtoCContact(CIRCLE_STATE* a, CIRCLE_STATE* b);
////矩形と矩形の当たり判定
bool BtoBContact(CENTRAL_STATE* central1, CENTRAL_STATE* central2);
//行動エリア制限
////矩形が指定範囲外に出ないようにする
void MoveInToErea(CENTRAL_STATE* central, float Left, float Top, float Right, float Bottom);

#endif TRIALLIB_H