#pragma once

#include "Obj.h"

/*
* ĳ���ʹ� ��� ������ ������ ĳ���� ������Ʈ�� �����Դϴ�.
* ���� Ŭ������ ���� Ư���� �°� �Լ��� �����Ͽ� ����մϴ�.
* �� �÷��� ����� �°� �������� �����Ͽ��� �մϴ�.
*/

class CCharacter abstract : public CObj
{
public:
	CCharacter() {}
	virtual ~CCharacter() {}

public:
	// CObj��(��) ���� ��ӵ�
	virtual void Initialize(void)					PURE;
	virtual int	 Update(float fDeltaTime)			PURE;
	virtual void Late_Update(float fDeltaTime)		PURE;
	virtual void Render(HDC hDC)					PURE;
	virtual void Release(void)						PURE;
	virtual void Collide(CObj* _pDst)				PURE;
};

