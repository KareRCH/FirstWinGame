#pragma once

#include "framework.h"

#include "CustomMath.h"

#define		WINCX		800
#define		WINCY		600

#define		ROCKMAN_EXECX 288
#define		ROCKMAN_EXECY 216

#define		PURE		= 0
#define		PI			3.141592f

#define		OBJ_DEAD	 1
#define		OBJ_NOEVENT	 0

#define		VK_MAX		0xff

#define		_TEST_CONSOLE	0

#define		FRAME_DELAY		10

typedef struct tagInfo
{
	float	fX;		// 중점 X
	float	fY;		// 중점 Y
	float	fCX;	// 가로 길이
	float	fCY;	// 세로 길이	

}INFO;

enum DIRECTION { LEFT, RIGHT, UP, DOWN, DIR_END };

enum OBJID { SYSTEM, PLAYER, BULLET, MONSTER, UNIT, MOUSE, SHIELD, BUTTON, OBJID_END };

enum SCENEID { SC_LOGO, SC_MENU, SC_EDIT, SC_STAGE, SC_END };

enum CHANNELID { SOUND_EFFECT, SOUND_BGM, MAXCHANNEL };

template<typename T>
void Safe_Delete(T& Temp)
{
	if (Temp)
	{
		delete Temp;
		Temp = nullptr;
	}
}

class CDeleteObj
{
public:
	template<typename T>
	void operator()(T& Temp)
	{
		if (Temp)
		{
			delete Temp;
			Temp = nullptr;
		}
	}
};
class CDeleteMap
{
public:
	template<typename T>
	void operator()(T& Pair)
	{
		if (Pair.second)
		{
			delete Pair.second;
			Pair.second = nullptr;
		}
	}
};

class CTag_Finder
{
public:
	CTag_Finder(const TCHAR* pString) : m_pString(pString) {}
public:
	template<typename T>
	bool operator()(T& Pair)
	{
		return !lstrcmp(m_pString, Pair.first);
	}

private:
	const TCHAR* m_pString;
};


typedef	struct tagLinePoint
{
	tagLinePoint() { ZeroMemory(this, sizeof(tagLinePoint)); }
	tagLinePoint(float _fX, float _fY) : fX(_fX), fY(_fY) {}

	float	fX;
	float	fY;

}LINEPOINT;


typedef struct tagLine
{
	tagLine() { ZeroMemory(this, sizeof(tagLine)); }
	tagLine(LINEPOINT& _tLpoint, LINEPOINT& _tRpoint)
		: tLpoint(_tLpoint), tRpoint(_tRpoint) { }

	LINEPOINT	tLpoint;
	LINEPOINT	tRpoint;

}LINE;


// 이미지를 표시하기 위해 업그레이드 된 FRAME 구조체
typedef struct tagFrame
{
	int				iFrameStart;	// 시작 프레임
	int				iFrameEnd;		// 끝 프레임
	int				iFrameCur;		// 현재 프레임
	int				iMotion;		// 애니메이션 종류(스프라이트 시트용)

	int				iFrameWidth;	// 이미지 너비
	int				iFrameHeight;	// 이미지 높이
	int				iOffsetX;		// 이미지 원점 X
	int				iOffsetY;		// 이미지 원점 Y

	ULONGLONG		ulSpeed;		// 딜레이
	ULONGLONG		ulTime;			// 시간 체크

}FRAME;

// 대충 아무때나 쓸 수 있는 상태머신 구조체
template <typename T>
struct tagState
{
	tagState() : eState(T()), ePrevState(T()) 
	{
		bIsEnter = false;
		bIsExit = false;
	}
	~tagState() {}

	bool	bIsEnter;
	bool	bIsExit;
	T		eState;
	T		ePrevState;

#pragma region 상태머신 함수
	void Set_State(T _eState)
	{
		ePrevState = eState;
		eState = _eState;
		bIsExit = true;
		bIsEnter = true;
	}

	bool IsState_Entered()
	{
		// 탈출 변수 자동 비활성화
		if (bIsExit)
			bIsExit = !bIsExit;

		if (bIsEnter)
		{
			bIsEnter = !bIsEnter;
			return true;
		}
		return false;
	}

	bool IsState_Exit()
	{
		// bIsEnter가 true가 아니면
		// 탈출 조건을 충족하지 못함.
		if (!bIsEnter)
			bIsExit = !bIsExit;

		if (bIsExit)
		{
			bIsExit = !bIsExit;
			return true;
		}
		return false;
	}
#pragma endregion
};

template <typename T>
using STATE_INFO = tagState<T>;

// 딜레이 용도로 만든 구조체
template<typename T = float>
struct _DELAY
{
	T Max;
	T Cur;

	_DELAY(T _Max) : Max(_Max), Cur(T()) {}
};
template <typename T = float>
using DELAY = _DELAY<T>;

extern HWND g_hWnd;
extern bool g_bWinActivate;
