#pragma once
#include "VisualFX.h"
class CVfx_ExplosionNormal : public CVisualFX
{
public:
	CVfx_ExplosionNormal() {}
	virtual ~CVfx_ExplosionNormal() {}
public:
	// CVisualFX을(를) 통해 상속됨
	virtual void Initialize(void) override;
	virtual int Update(float fDeltaTime) override;
	virtual void Late_Update(float fDeltaTime) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	virtual void Collide(CObj* _pDst) override;
};

