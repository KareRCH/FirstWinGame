#pragma once

#include "Character/Character_NetBattle.h"
#include "ObjMgr.h"

/*
* 넷 배틀용 캐릭터 중 내비의 속성을 상속받는 클래스
*/

class CNavi : public CCharacter_NetBattle
{
public:
	CNavi() {}
	virtual ~CNavi() {}

public:
	// CCharacter_NetBattle을(를) 통해 상속됨
	virtual void Initialize(void)				PURE;
	virtual int Update(float fDeltaTime)		PURE;
	virtual void Late_Update(float fDeltaTime)	PURE;
	virtual void Render(HDC hDC)				PURE;
	virtual void Release(void)					PURE;
	virtual void Collide(CObj* _pDst)			PURE;

	// 내비 클래스의 기초적인 초기화
	void Initialize_Navi()
	{
		CCharacter_NetBattle::Initialize_Gravity();
		CObjMgr::Get_Instance()->Add_Object(UNIT, this);
	}

#pragma region 네비용 인벤토리(칩 저장용)
protected:


public:

#pragma endregion
};

