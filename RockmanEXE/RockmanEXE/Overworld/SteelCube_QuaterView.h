#pragma once

#include "Character/Character_QuaterView.h"

class CSteelCube_QuaterView :  public CCharacter_QuaterView
{
public:
	CSteelCube_QuaterView() {}
	virtual ~CSteelCube_QuaterView() {}
public:
	virtual void Initialize(void)					override;
	virtual int	 Update(float fDeltaTime)			override;
	virtual void Late_Update(float fDeltaTime)		override;
	virtual void Render(HDC hDC)					override;
	virtual void Release(void)						override;
	virtual void Collide(CObj* _pDst)				override;
};

