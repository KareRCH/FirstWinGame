#pragma once

#include "Navi/Navi.h"

class CNavi_Blastman : public CNavi
{
public:
	// ���� �ൿ�� ����
	enum class STATE_ACT;
	enum class STATE_OBJ;
	enum class STATE_APR;
	// �׼�Ű
	enum class ACTION_KEY;

public:
	CNavi_Blastman() {}
	virtual ~CNavi_Blastman() {}

public:
	// CNavi��(��) ���� ��ӵ�
	virtual void Initialize(void) override;
	virtual int Update(float fDeltaTime) override;
	virtual void Late_Update(float fDeltaTime) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	virtual void Collide(CObj* _pDst) override;

private:
	void State_Update(float fDeltaTime);

public: // �ൿŰ
	enum class ACTION_KEY { LEFT, RIGHT, UP, DOWN, ATTACK, HIDE, JUMP, ATTACKED };
private: // ���� ����Ű
	ACTION_SET<ACTION_KEY> m_mapActionKey;



public:	// �ൿ ���¸ӽ�
	enum class STATE_ACT { IDLE, HIT, PALARYZE, MOVE_END, MOVE_BEGIN, ATTACK_BLASS, CHARGE, CHARGE_BURNING
							, PRE_DISCHARGE_1, DISCHARGE_DOWNWARD, PRE_DISCHARGE_2, DISCHARGE_FORWARD, DISCHARGE_UPWARD };
private:
	STATE_SET<STATE_ACT, void(CNavi_Blastman*, float)> m_tState_Act;
	DELAY<float>		m_fDead_Delay = DELAY<float>(1.f);
	DELAY<float>		m_fExplosion_Delay = DELAY<float>(0.2f);

	void Idle(float fDeltaTime);




public: // ��ǥ ���¸ӽ�(AI)
	enum class STATE_OBJ { IDLE, CHASE, ATTACK, ATTACK_DOWNWARD, ATTACK_UPWARD, ATTACK_FORWARD };
private:
	STATE_SET<STATE_OBJ, void(CNavi_Blastman*, float)> m_tState_Obj;
	DELAY<float>	m_fAction_Delay = DELAY<float>(1.5f);

	void Obj_Idle(float fDeltaTime);
	void Obj_Chase(float fDeltaTime);
	void Obj_Attack(float fDeltaTime);

private:
	CCharacter_NetBattle* m_pTarget = nullptr;
};

