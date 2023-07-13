#pragma once

#include "Obj.h"

class COverworld_MenuUI : public CObj
{
public:
	COverworld_MenuUI(){}
	virtual ~COverworld_MenuUI() {}

public:
	// CObj을(를) 통해 상속됨
	virtual void Initialize(void) override;
	virtual int Update(float fDeltaTime) override;
	virtual void Late_Update(float fDeltaTime) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	virtual void Collide(CObj* _pDst) override;

private:

};

