#pragma once

#include "Spell/Spell.h"

class CSpell_ChargeBuster : public CSpell
{
public:
	CSpell_ChargeBuster() {}
	virtual ~CSpell_ChargeBuster() {}

public:
	// CSpell��(��) ���� ��ӵ�
	virtual void Initialize(void) override;
	virtual int Update(float fDeltaTime) override;
	virtual void Late_Update(float fDeltaTime) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	virtual void Collide(CObj* _pDst) override;
};

