#pragma once

#include "Character/Character_NetBattle.h"

class CSpell : public CCharacter_NetBattle
{
public:
	CSpell() : m_bCanHit(true) {}
	virtual ~CSpell() {}

public:
	// CCharacter_NetBattle을(를) 통해 상속됨
	virtual void Initialize(void)				PURE;
	virtual int Update(float fDeltaTime)		PURE;
	virtual void Late_Update(float fDeltaTime)	PURE;
	virtual void Render(HDC hDC)				PURE;
	virtual void Release(void)					PURE;
	virtual void Collide(CObj* _pDst)			PURE;

public:
	void Initialize_Spell()
	{
		CObjMgr::Get_Instance()->Add_Object(SPELL, this);
	}

protected:
	DELAY<float>	m_fHitDelay;			// 히트 딜레이, 딜레이 도중에는 딜이 들어가지 않는다.
	bool			m_bCanHit;				// 대미지를 줄 수 있는 상태
};

