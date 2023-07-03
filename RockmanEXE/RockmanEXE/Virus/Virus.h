#pragma once

#include "Character/Character_NetBattle.h"

/*
* �� ������ ���̷��� ĳ���Ϳ� ���� �Ӽ� ���� Ŭ�����Դϴ�.
*/

class CVirus : public CCharacter_NetBattle
{
public:
	CVirus() {}
	CVirus(const CVirus& _rhs) = delete;
	virtual ~CVirus() {}

	// CCharacter_NetBattle��(��) ���� ��ӵ�
	virtual int Update(float fDeltaTime) override;
	virtual void Late_Update(float fDeltaTime) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	virtual void Collide(CObj* _pDst) override;

};

