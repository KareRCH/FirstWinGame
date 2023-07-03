#pragma once

#include "Character/Character_NetBattle.h"

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
};

