#pragma once

#include "Character/Character_NetBattle.h"
#include "ObjMgr.h"

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

	// ���� Ŭ������ �������� �ʱ�ȭ
	void Initialize_Navi()
	{
		CCharacter_NetBattle::Initialize_Gravity();
		CObjMgr::Get_Instance()->Add_Object(UNIT, this);
	}

#pragma region �׺�� �κ��丮(Ĩ �����)
protected:


public:

#pragma endregion
};

