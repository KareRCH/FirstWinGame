#pragma once
#include "Character/Character_NetBattle.h"


class CSpell : public CCharacter_NetBattle
{
public:
	CSpell() {}
	virtual ~CSpell() {}

public:
	// CCharacter_NetBattle��(��) ���� ��ӵ�
	virtual int Update(float fDeltaTime) PURE;
	virtual void Late_Update(float fDeltaTime) PURE;
	virtual void Render(HDC hDC) PURE;
	virtual void Release(void) PURE;
	virtual void Collide(CObj* _pDst) PURE;
};

