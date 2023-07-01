#pragma once

#include "Character.h"

/*
* ���ͺ�� ������ ���带 ���ƴٴ� �� �ִ� ĳ���Ϳ� ���� �߻�Ŭ����
*/

class CCharacter_QuaterView abstract : public CCharacter
{
public:
	CCharacter_QuaterView() {}
	virtual ~CCharacter_QuaterView() {}
public:
	virtual void Initialize(void)					PURE;
	virtual int	 Update(float fDeltaTime)			PURE;
	virtual void Late_Update(float fDeltaTime)		PURE;
	virtual void Render(HDC hDC)					PURE;
	virtual void Release(void)						PURE;
	virtual void Collide(CObj* _pDst)				PURE;
};

