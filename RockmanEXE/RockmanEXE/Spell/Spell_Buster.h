#pragma once

#include "Spell.h"



/*
* ������, �� ������, �ٶ󺸴� �������� ������ ũ�⸸ŭ �̵��Ѵ�.
*/

class CSpell_Buster : public CSpell
{
public:
	CSpell_Buster() {}
	virtual ~CSpell_Buster() {}

public:
	// CSpell��(��) ���� ��ӵ�
	virtual void Initialize(void) override;
	virtual int Update(float fDeltaTime) override;
	virtual void Late_Update(float fDeltaTime) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	virtual void Collide(CObj* _pDst) override;

public:
};

