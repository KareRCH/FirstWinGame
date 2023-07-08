#pragma once

#include "Character/Character_NetBattle.h"
#include "ObjMgr.h"

/*
* �� ������ ���̷��� ĳ���Ϳ� ���� �Ӽ� ���� Ŭ�����Դϴ�.
*/

class CVirus abstract : public CCharacter_NetBattle
{
public:
	// ���̷����� ����
	enum class VERSION { V1, V2, V3, EX };
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


public:
	// ���� Ŭ������ �������� �ʱ�ȭ
	void Initialize_Virus()
	{
		CCharacter_NetBattle::Initialize_Gravity();
		CObjMgr::Get_Instance()->Add_Object(UNIT, this);
	}
};

