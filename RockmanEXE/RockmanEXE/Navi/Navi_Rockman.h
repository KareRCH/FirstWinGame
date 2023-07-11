#pragma once

#include "Navi.h"


#include "Battle/Panel.h"


class CNavi_Rockman : public CNavi
{
public:
	enum class STATE { IDLE, MOVE_READY, MOVE_END, SHOOT_BUSTER, CHARGE_BUSTER, JUMP, JUMP_SHOOT_BUSTER, HIT };
	enum class STATE_BLINK { NONE, BLINK };
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
	STATE_SET<STATE, void(CNavi_Rockman*, float)> m_tState;

private:
	void Idle(float fDeltaTime);
	void MoveReady(float fDeltaTime);
	void MoveEnd(float fDeltaTime);
	void ShootBuster(float fDeltaTime);
	void ChargeBuster(float fDeltaTime);
	void Jump(float fDeltaTime);
	void JumpShootBuster(float fDeltaTime);
	void Hit(float fDeltaTime);

private:
	STATE_SET<STATE_BLINK, void(CNavi_Rockman*, float)> m_tState_Blink;
	GAUGE<float>			m_fBlink = GAUGE<float>(0.05f);

private:
	void Blink_None(float fDeltaTime);
	void Blink_Blink(float fDeltaTime);
};

