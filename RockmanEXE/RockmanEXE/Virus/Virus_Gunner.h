#pragma once
#include "Virus/Virus.h"
class CVirus_Gunner : public CVirus
{
public:
	// 현재 행동의 상태
	enum class STATE_ACT;
	enum class STATE_OBJ;
	// 액션키
	enum class ACTION_KEY;

public:
	CVirus_Gunner() {}
	virtual ~CVirus_Gunner() {}

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

public: // 행동키
	enum class ACTION_KEY { LEFT, RIGHT, UP, DOWN, ATTACK };
private: // 가상 조작키
	ACTION_SET<ACTION_KEY> m_mapActionKey;



public:	// 행동 상태머신
	enum class STATE_ACT { IDLE, DETECTED, SHOOT, SHOOT_TO_IDLE };
private:
	STATE_SET<STATE_ACT, void(CVirus_Gunner*, float)> m_tState_Act;

	void Idle(float fDeltaTime);
	void Detected(float fDeltaTime);
	void Shoot(float fDeltaTime);
	void ShootToIdle(float fDeltaTime);



public: // 목표 상태머신(AI)
	enum class STATE_OBJ { IDLE, WATCH, ATK };
private:
	STATE_SET<STATE_OBJ, void(CVirus_Gunner*, float)> m_tState_Obj;

	void Obj_Idle(float fDeltaTime);
	void Obj_Watch(float fDeltaTime);
	void Obj_Atk(float fDeltaTime);
};

