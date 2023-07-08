#pragma once

#include "Spell.h"



/*
* 버스터, 매 프레임, 바라보는 방향으로 본인의 크기만큼 이동한다.
*/

class CSpell_Buster : public CSpell
{
public:
	CSpell_Buster() {}
	virtual ~CSpell_Buster() {}

public:
	// CSpell을(를) 통해 상속됨
	virtual void Initialize(void) override;
	virtual int Update(float fDeltaTime) override;
	virtual void Late_Update(float fDeltaTime) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	virtual void Collide(CObj* _pDst) override;

public:
};

