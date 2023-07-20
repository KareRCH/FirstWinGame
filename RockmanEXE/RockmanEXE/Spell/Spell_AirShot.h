#pragma once
#include "Spell/Spell.h"
class CSpell_AirShot : public CSpell
{
public:
	CSpell_AirShot() {}
	virtual ~CSpell_AirShot() {}

public:
	// CSpell을(를) 통해 상속됨
	virtual void Initialize(void) override;
	virtual int Update(float fDeltaTime) override;
	virtual void Late_Update(float fDeltaTime) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	virtual void Collide(CObj* _pDst) override;
};

