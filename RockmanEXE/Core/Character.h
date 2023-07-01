#pragma once

#include "Obj.h"

/*
* 캐릭터는 모든 조종이 가능한 캐릭터 오브젝트의 집합입니다.
* 하위 클래스는 각자 특성에 맞게 함수를 구현하여 사용합니다.
* 각 플레이 방법에 맞게 다형성을 구상하여야 합니다.
*/

class CCharacter abstract : public CObj
{
public:
	CCharacter() {}
	virtual ~CCharacter() {}

public:
	// CObj을(를) 통해 상속됨
	virtual void Initialize(void)					PURE;
	virtual int	 Update(float fDeltaTime)			PURE;
	virtual void Late_Update(float fDeltaTime)		PURE;
	virtual void Render(HDC hDC)					PURE;
	virtual void Release(void)						PURE;
	virtual void Collide(CObj* _pDst)				PURE;
};

