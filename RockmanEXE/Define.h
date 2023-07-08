#pragma once

#include "framework.h"

#include "CustomMath.h"

#define		WINCX		800
#define		WINCY		600

#define		ROCKMAN_EXECX 264
#define		ROCKMAN_EXECY 198

#define		PURE		= 0
#define		PI			3.141592f

#define		OBJ_DEAD	 1
#define		OBJ_NOEVENT	 0

#define		VK_MAX		0xff

#define		_TEST_CONSOLE	1

#define		FRAME_DELAY		10

typedef struct tagInfo
{
	float	fX;		// 중점 X
	float	fY;		// 중점 Y
	float	fCX;	// 가로 길이
	float	fCY;	// 세로 길이	

}INFO;

enum DIRECTION { LEFT, RIGHT, UP, DOWN, DIR_END };

enum OBJID { SYSTEM, PANEL, PLAYER, BULLET, MONSTER, UNIT, SPELL, MOUSE, SHIELD, BUTTON, OBJID_END };

enum SCENEID { SC_LOGO, SC_MENU, SC_EDIT, SC_STAGE, SC_END };

enum CHANNELID { SOUND_EFFECT, SOUND_BGM, SYSTEM_EFFECT, SOUND_EFFECT3, MAXCHANNEL };

enum CHANNEL_GROUP_ID { BGM_GROUP, SND1_GROUP, SND2_GROUP, MAX_CHANNEL_GROUP };

enum TEAM_ID { TEAM_ALPHA, TEAM_BETA, TEAM_GAMMA };

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
	tagFrame() : bLoop(true), iFrameStart(), iFrameEnd(), iFrameCur(), iMotion(),
		iFrameWidth(), iFrameHeight(), iOffsetX(), iOffsetY(), ulSpeed(), ulTime(GetTickCount64()), ulCurTime(GetTickCount64()){}

	bool			bLoop;

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
	ULONGLONG		ulCurTime;		// 현재 시간

	void Set_Loop(bool value) { bLoop = value; }
	bool IsFrameEnd() { return (iFrameCur >= iFrameEnd); }
	bool IsFrameTick(int value) { return ((iFrameCur == value) && (ulTime == ulCurTime)); }
	bool IsFrameStart() { return (iFrameCur == 0); }
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
		if (bIsEnter)
		{
			bIsEnter = false;
			bIsExit = false;		// 상태 진입시 탈출 조건 자동 비활성화
			return true;
		}
		return false;
	}

	bool IsState_Exit()
	{
		// 이미 Entered 함수를 불러왔을 때 탈출 조건을 OFF 시킨다.
		if (!bIsEnter)
			bIsExit = false;

		if (bIsExit)
		{
			bIsExit = false;
			return true;
		}
		return false;
	}

	bool IsOnState(T _eState)
	{
		return (eState == _eState);
	}
#pragma endregion
};

template <typename T>
using STATE_INFO = tagState<T>;

// 딜레이 용도로 만든 구조체
template<typename T = float>
struct _DELAY
{
	static_assert(std::is_arithmetic<T>::value, "T는 원시 타입이어야만 합니다.");

	T Max;
	T Cur;

	_DELAY() : Max(T()), Cur(T()) {}
	_DELAY(T _Max, bool bMax = false) : Max(_Max), Cur(T(T(bMax) * T(_Max))) {}
	~_DELAY() {}

	// 값 업데이트 및 맥스값 도달시 반환
	bool Update(T increase, bool bAutoReset = false)
	{
		Cur += increase;
		if (Cur >= Max)
		{
			if (bAutoReset)
				Cur = T();
			return true;
		}

		return false;
	}

	bool Update(T increase, T point, bool bAutoReset = false)
	{
		Cur += increase;
		if (Cur >= point)
		{
			if (bAutoReset)
				Cur = T();
			return true;
		}

		return false;
	}

	// 현재값 초기화
	void Reset()
	{
		Cur = T();
	}

	// Max 값 재설정 및 현재값 초기화
	void ReAdjust(T max)
	{
		Max = max;
		Cur = T();
	}
};

template <typename T = float>
using DELAY = _DELAY<T>;

template <typename T = float>
using GAUGE = _DELAY<T>;


typedef struct _ACTION
{
	_ACTION() : bAction() {}
	~_ACTION() {}

	bool bAction;

	void Act()
	{
		bAction = true;
	}

	void Update()
	{
		bAction = false;
	}

	bool Sync()
	{
		if (bAction)
		{
			bAction = false;
			return true;
		}
		return false;
	}

	bool IsOnAct()
	{
		return bAction;
	}
}ACTION;

template<typename Key>
using MAP_ACTION = map<Key, ACTION>;

template<typename Key>
class CMapAction_Updator
{
public:
	void operator() (pair<Key, ACTION> Action)
	{
		Action.second.Update();
	}
};


// 단순하게 쓰기 위한 템플릿
template <typename Key, typename Func>
using MAP_FUNC = map<Key, function<Func>>;

extern HWND g_hWnd;
extern bool g_bWinActivate;
