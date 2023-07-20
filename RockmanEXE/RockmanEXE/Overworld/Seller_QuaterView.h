#pragma once

#include "Character/Character_QuaterView.h"

class CSeller_QuaterView : public CCharacter_QuaterView
{
public:
	CSeller_QuaterView() {}
	virtual ~CSeller_QuaterView() {}
public:
	virtual void Initialize(void)					override;
	virtual int	 Update(float fDeltaTime)			override;
	virtual void Late_Update(float fDeltaTime)		override;
	virtual void Render(HDC hDC)					override;
	virtual void Release(void)						override;
	virtual void Collide(CObj* _pDst)				override;

protected:
	// CCharacter_QuaterView을(를) 통해 상속됨
	virtual void Commnication(CCharacter_QuaterView* pCommunicator) override;
	virtual void Listen_Communication_End() override;

private:
	void Load_ChipShot();
};

