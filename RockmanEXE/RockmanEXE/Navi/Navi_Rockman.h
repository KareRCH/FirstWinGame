#pragma once

#include "Navi.h"


#include "Battle/Panel.h"


class CNavi_Rockman : public CNavi
{
public:
	enum STATE { IDLE, MOVE_READY, MOVE_END, SHOOT_BUSTER, CHARGE_BUSTER, JUMP, JUMP_SHOOT_BUSTER };
public:
	CNavi_Rockman();
	virtual ~CNavi_Rockman();

public:
	// CNavi을(를) 통해 상속됨
	virtual void Initialize(void) override;
	virtual int Update(float fDeltaTime) override;
	virtual void Late_Update(float fDeltaTime) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	virtual void Collide(CObj* _pDst) override;

private:
	void State_Update(float fDeltaTime);

private:
	STATE_INFO<STATE>	m_tState;
};

