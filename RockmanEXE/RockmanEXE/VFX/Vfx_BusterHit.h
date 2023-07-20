#pragma once
#include "VFX/VisualFX.h"

class CVfx_BusterHit : public CVisualFX
{
public:
	CVfx_BusterHit() {}
	virtual ~CVfx_BusterHit() {}
public:
	// CVisualFX을(를) 통해 상속됨
	virtual void Initialize(void) override;
	virtual int Update(float fDeltaTime) override;
	virtual void Late_Update(float fDeltaTime) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	virtual void Collide(CObj* _pDst) override;
};

