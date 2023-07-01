#pragma once

#include "Character.h"

class CCharacter_SideView : public CCharacter
{
public:
	CCharacter_SideView() {}
	virtual ~CCharacter_SideView() {}
public:
	virtual void Initialize(void)					PURE;
	virtual int	 Update(float fDeltaTime)			PURE;
	virtual void Late_Update(float fDeltaTime)		PURE;
	virtual void Render(HDC hDC)					PURE;
	virtual void Release(void)						PURE;
	virtual void Collide(CObj* _pDst)				PURE;
};

