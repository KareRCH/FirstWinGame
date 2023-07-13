#pragma once

#include "framework.h"

#include "CustomMath.h"

#define		WINCX		800
#define		WINCY		600

#define		TILEX		30
#define		TILEY		20

#define		TILECX		64
#define		TILECY		32

#define		ROCKMAN_EXECX 264
#define		ROCKMAN_EXECY 198

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

enum OBJID { SYSTEM, PANEL, TILE, PLAYER, BULLET, MONSTER, UNIT, SPELL, MOUSE, SHIELD, BUTTON, UI, OBJID_END };

enum RENDERID { RENDER_BACKGROUND, RENDER_GAMEOBJECT, RENDER_EFFECT, RENDER_UI, RENDER_END };

enum SCENEID { SC_LOGO, SC_MENU, SC_WORLD1, SC_EDIT, SC_STAGE, SC_END };

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
		iFrameWidth(), iFrameHeight(), iOffsetX(), iOffsetY(), ulSpeed(), 
		ulTime(GetTickCount64()), ulCurTime(GetTickCount64()), ulDelayTime(GetTickCount64()){}

	bool			bLoop;

	int				iFrameStart;	// 시작 프레임
	int				iFrameEnd;		// 끝 프레임
	int				iFrameCur;		// 현재 프레임
	int				iMotion;		// 애니메이션 종류(스프라이트 시트용)

	int				iFrameWidth;	// 이미지 너비
	int				iFrameHeight;	// 이미지 높이
	int				iOffsetX;		// 이미지 원점 X
	int				iOffsetY;		// 이미지 원점 Y

	ULONGLONG		ulSpeed;		// 속도
	ULONGLONG		ulTime;			// 시간 체크
	ULONGLONG		ulCurTime;		// 현재 시간
	ULONGLONG		ulDelayTime;	// 딜레이 주는 시간

	void Set_Loop(bool value) { bLoop = value; }
	bool IsFrameEnd() { return (iFrameCur >= iFrameEnd); }
	bool IsFrameTick(int value) { return ((iFrameCur == value) && (ulTime == ulCurTime)); }
	bool IsFrameStart() { return (iFrameCur == 0); }
}FRAME;

// 대충 아무때나 쓸 수 있는 상태머신 구조체
template <typename T>
struct tagState
{
	tagState() : eState(T()), ePrevState(T()), eNextState(T()) 
	{
		bIsEnter = false;
		bIsExit = false;
		bIsReserved = false;
	}
	~tagState() {}

	bool	bIsEnter;
	bool	bIsExit;
	bool	bIsReserved;
	T		eState;
	T		ePrevState;
	T		eNextState;

#pragma region 상태머신 함수
	void Set_State(T _eState)
	{
		ePrevState = eState;
		eState = _eState;
		bIsExit = true;
		bIsEnter = true;
	}

	void Reserve_State(T _eState)
	{
		eNextState = _eState;
		bIsReserved = true;
	}

	// 진입할 때
	bool IsState_Entered()
	{
		if (bIsEnter && !bIsReserved)
		{
			bIsEnter = false;
			bIsExit = false;		// 상태 진입시 탈출 조건 자동 비활성화
			return true;
		}
		return false;
	}

	// 빠져나갈 때
	bool IsState_Exit()
	{
		// 예약 상태에서는 하나의 
		if (bIsReserved)
		{
			Set_State(eNextState);
			bIsReserved = false;
			bIsExit = false;
			return true;
		}

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
	
	// 예약이 없는 상태에서만 업데이트를 할 수 있다.
	bool Can_Update()
	{
		return !bIsReserved;
	}

	bool IsOnState(T _eState)
	{
		return (eState == _eState);
	}
#pragma endregion
};

template <typename T>
using STATE_INFO = tagState<T>;

// 단순하게 쓰기 위한 템플릿
template <typename Key, typename Func>
using MAP_FUNC = map<Key, function<Func>>;

// 상태머신 세트
template<typename Key, typename Func>
struct STATE_SET
{
	STATE_SET() {}
	~STATE_SET() {}

public:
	STATE_INFO<Key> tState;
	MAP_FUNC<Key, Func> mapFunc;

public:
#pragma region 상태머신
	void Set_State(Key _eState)
	{
		tState.Set_State(_eState);
	}

	void Reserve_State(Key _eState)
	{
		tState.Reserve_State();
	}

	// 진입할 때
	bool IsState_Entered()
	{
		return tState.IsState_Entered();
	}

	// 빠져나갈 때
	bool IsState_Exit()
	{
		return tState.IsState_Exit();
	}

	// 예약이 없는 상태에서만 업데이트를 할 수 있다.
	bool Can_Update()
	{
		return tState.Can_Update();
	}

	bool IsOnState(Key _eState)
	{
		return tState.IsOnState(_eState);
	}
#pragma endregion
#pragma region 함수 맵
	void Add_Func(Key eState, function<Func>&& fn)
	{
		mapFunc.emplace(eState, fn);
	}

	function<Func> Get_StateFunc()
	{
		return mapFunc[tState.eState];
	}
#pragma endregion

};

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
			else
				Cur = Max;
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
			else
				Cur = Max;
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

	float Get_Percent()
	{
		return (static_cast<float>(Cur) / static_cast<float>(Max));
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

template<typename Key>
struct ACTION_SET
{
	ACTION_SET() {}
	~ACTION_SET() {}

public:
	map<Key, ACTION> mapAction;

	void Add_Action(Key&& tKey)
	{
		mapAction.emplace(tKey, ACTION());
	}

	ACTION& operator[] (Key&& tKey)
	{
		return mapAction[tKey];
	}

	void Update()
	{
		for_each(mapAction.begin(), mapAction.end(), CMapAction_Updator<Key>());
	}
};

extern HWND g_hWnd;
extern vector<HFONT> g_hFonts;
extern bool g_bWinActivate;
