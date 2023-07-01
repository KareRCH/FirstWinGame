#pragma once

#include "Character.h"

/*
* 쿼터뷰로 구성된 월드를 돌아다닐 수 있는 캐릭터에 대한 추상클래스
*/

class CCharacter_QuaterView abstract : public CCharacter
{
public:
	CCharacter_QuaterView() {}
	virtual ~CCharacter_QuaterView() {}
public:
	virtual void Initialize(void)					PURE;
	virtual int	 Update(float fDeltaTime)			PURE;
	virtual void Late_Update(float fDeltaTime)		PURE;
	virtual void Render(HDC hDC)					PURE;
	virtual void Release(void)						PURE;
	virtual void Collide(CObj* _pDst)				PURE;
};

