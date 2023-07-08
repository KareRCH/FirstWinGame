#pragma once

#include "Character/Character_NetBattle.h"

class CSpell : public CCharacter_NetBattle
{
public:
	CSpell() : m_bCanHit(true) {}
	virtual ~CSpell() {}

public:
	// CCharacter_NetBattle��(��) ���� ��ӵ�
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
	DELAY<float>	m_fHitDelay;			// ��Ʈ ������, ������ ���߿��� ���� ���� �ʴ´�.
	bool			m_bCanHit;				// ������� �� �� �ִ� ����
};

