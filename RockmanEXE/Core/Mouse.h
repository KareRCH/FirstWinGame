#pragma once

#include "Obj.h"

class CMouse : public CObj
{
public:
	CMouse();
	virtual ~CMouse();

public:
	// CObj��(��) ���� ��ӵ�
	virtual void Initialize(void) override;
	virtual int Update(float fDeltaTime) override;
	virtual void Late_Update(float fDeltaTime) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

public:
	virtual void Collide(CObj* _pDst) override;
};

