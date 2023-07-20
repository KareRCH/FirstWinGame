#pragma once
#include "Character/Character_NetBattle.h"

#include "ObjMgr.h"
class CVisualFX : public CCharacter_NetBattle
{
public:
	CVisualFX() {}
	virtual ~CVisualFX() {}

public:
	// CCharacter_NetBattle을(를) 통해 상속됨
	virtual void Initialize(void)				PURE;
	virtual int Update(float fDeltaTime)		PURE;
	virtual void Late_Update(float fDeltaTime)	PURE;
	virtual void Render(HDC hDC)				PURE;
	virtual void Release(void)					PURE;
	virtual void Collide(CObj* _pDst)			PURE;

protected:
	void Initialize_VFX()
	{
		CObjMgr::Get_Instance()->Add_Object(VFX, this);
		m_iRenderDepth = 1;
	}
};

