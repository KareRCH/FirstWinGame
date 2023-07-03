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
	float	fX;		// ���� X
	float	fY;		// ���� Y
	float	fCX;	// ���� ����
	float	fCY;	// ���� ����	

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


// �̹����� ǥ���ϱ� ���� ���׷��̵� �� FRAME ����ü
typedef struct tagFrame
{
	int				iFrameStart;	// ���� ������
	int				iFrameEnd;		// �� ������
	int				iFrameCur;		// ���� ������
	int				iMotion;		// �ִϸ��̼� ����(��������Ʈ ��Ʈ��)

	int				iFrameWidth;	// �̹��� �ʺ�
	int				iFrameHeight;	// �̹��� ����
	int				iOffsetX;		// �̹��� ���� X
	int				iOffsetY;		// �̹��� ���� Y

	ULONGLONG		ulSpeed;		// ������
	ULONGLONG		ulTime;			// �ð� üũ

}FRAME;

// ���� �ƹ����� �� �� �ִ� ���¸ӽ� ����ü
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

#pragma region ���¸ӽ� �Լ�
	void Set_State(T _eState)
	{
		ePrevState = eState;
		eState = _eState;
		bIsExit = true;
		bIsEnter = true;
	}

	bool IsState_Entered()
	{
		// Ż�� ���� �ڵ� ��Ȱ��ȭ
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
		// bIsEnter�� true�� �ƴϸ�
		// Ż�� ������ �������� ����.
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

// ������ �뵵�� ���� ����ü
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
