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
	float	fX;		// ���� X
	float	fY;		// ���� Y
	float	fCX;	// ���� ����
	float	fCY;	// ���� ����	

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


// �̹����� ǥ���ϱ� ���� ���׷��̵� �� FRAME ����ü
typedef struct tagFrame
{
	tagFrame() : bLoop(true), iFrameStart(), iFrameEnd(), iFrameCur(), iMotion(),
		iFrameWidth(), iFrameHeight(), iOffsetX(), iOffsetY(), ulSpeed(), ulTime(GetTickCount64()), ulCurTime(GetTickCount64()){}

	bool			bLoop;

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
	ULONGLONG		ulCurTime;		// ���� �ð�

	void Set_Loop(bool value) { bLoop = value; }
	bool IsFrameEnd() { return (iFrameCur >= iFrameEnd); }
	bool IsFrameTick(int value) { return ((iFrameCur == value) && (ulTime == ulCurTime)); }
	bool IsFrameStart() { return (iFrameCur == 0); }
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
		if (bIsEnter)
		{
			bIsEnter = false;
			bIsExit = false;		// ���� ���Խ� Ż�� ���� �ڵ� ��Ȱ��ȭ
			return true;
		}
		return false;
	}

	bool IsState_Exit()
	{
		// �̹� Entered �Լ��� �ҷ����� �� Ż�� ������ OFF ��Ų��.
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

// ������ �뵵�� ���� ����ü
template<typename T = float>
struct _DELAY
{
	static_assert(std::is_arithmetic<T>::value, "T�� ���� Ÿ���̾�߸� �մϴ�.");

	T Max;
	T Cur;

	_DELAY() : Max(T()), Cur(T()) {}
	_DELAY(T _Max, bool bMax = false) : Max(_Max), Cur(T(T(bMax) * T(_Max))) {}
	~_DELAY() {}

	// �� ������Ʈ �� �ƽ��� ���޽� ��ȯ
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

	// ���簪 �ʱ�ȭ
	void Reset()
	{
		Cur = T();
	}

	// Max �� �缳�� �� ���簪 �ʱ�ȭ
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


// �ܼ��ϰ� ���� ���� ���ø�
template <typename Key, typename Func>
using MAP_FUNC = map<Key, function<Func>>;

extern HWND g_hWnd;
extern bool g_bWinActivate;
