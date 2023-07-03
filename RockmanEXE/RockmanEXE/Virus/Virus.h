#pragma once

#include "Character/Character_NetBattle.h"

/*
* 적 종류중 바이러스 캐릭터에 대한 속성 정의 클래스입니다.
*/

class CVirus : public CCharacter_NetBattle
{
public:
	CVirus() {}
	CVirus(const CVirus& _rhs) = delete;
	virtual ~CVirus() {}

	// CCharacter_NetBattle을(를) 통해 상속됨
	virtual int Update(float fDeltaTime) override;
	virtual void Late_Update(float fDeltaTime) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	virtual void Collide(CObj* _pDst) override;

};

