#pragma once

#include "Character/Character_NetBattle.h"

/*
* �� ��Ʋ�� ĳ���� �� ������ �Ӽ��� ��ӹ޴� Ŭ����
*/

class CNavi : public CCharacter_NetBattle
{
public:
	CNavi() {}
	virtual ~CNavi() {}

public:
	// CCharacter_NetBattle��(��) ���� ��ӵ�
	virtual void Initialize(void)				PURE;
	virtual int Update(float fDeltaTime)		PURE;
	virtual void Late_Update(float fDeltaTime)	PURE;
	virtual void Render(HDC hDC)				PURE;
	virtual void Release(void)					PURE;
	virtual void Collide(CObj* _pDst)			PURE;
};

