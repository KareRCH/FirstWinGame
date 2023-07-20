#pragma once

#include "Navi.h"


#include "Battle/Panel.h"


class CNavi_Rockman : public CNavi
{
public:
	enum class STATE;
	enum class STATE_BLINK;
	enum class STATE_CHARGE;

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

private: // 인풋
	bool Input_Move();
	bool Input_Jump();
	bool Input_Shot(float fDeltaTime);
	bool Input_Chip();

private:
	void State_Update(float fDeltaTime);

public: // 행동 상태
	enum class STATE {
		IDLE, MOVE_READY, MOVE_END, SHOOT_BUSTER, CHARGE_BUSTER, JUMP, JUMP_SHOOT_BUSTER, LANDING, HIT,
		CANNON, AIR_SHOT, VALCAN, BOMB, SWORD, WIDE_SWORD, CRACK_SHOT, CHIP
	};
private:
	STATE_SET<STATE, void(CNavi_Rockman*, float)> m_tState;
	
	void Idle(float fDeltaTime);
	void MoveReady(float fDeltaTime);
	void MoveEnd(float fDeltaTime);
	void ShootBuster(float fDeltaTime);
	void ChargeBuster(float fDeltaTime);
	void Jump(float fDeltaTime);
	void JumpShootBuster(float fDeltaTime);
	void Landing(float fDeltaTime);
	void Hit(float fDeltaTime);

	void Cannon(float fDeltaTime);
	void AirShot(float fDeltaTime);
	void Valcan(float fDeltaTime);
	void Bomb(float fDeltaTime);
	void Sword(float fDeltaTime);
	void WideSword(float fDeltaTime);
	void CrackShot(float fDeltaTime);
	void Chip(float fDeltaTime);

public: // 블링크 상태
	enum class STATE_BLINK { NONE, BLINK };
private:
	STATE_SET<STATE_BLINK, void(CNavi_Rockman*, float)> m_tState_Blink;
	GAUGE<float>			m_fBlink = GAUGE<float>(0.05f);

	void Blink_None(float fDeltaTime);
	void Blink_Blink(float fDeltaTime);

public: // 차지 상태
	enum class STATE_CHARGE { NONE, CHARGING };
private:
	STATE_SET<STATE_CHARGE, void(CNavi_Rockman*, float)> m_tState_Charge;
	GAUGE<float> m_fBusterCharge = GAUGE<float>(2.f);

	void Charge_None(float fDeltaTime);
	void Charge_Charging(float fDeltaTime);
};

