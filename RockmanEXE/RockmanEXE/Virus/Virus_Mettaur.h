#pragma once

#include "Virus.h"

class CVirus_Mettaur : public CVirus
{
public:
	// ���� �ൿ�� ����
	enum class STATE_ACT;
	enum class STATE_OBJ;
	enum class STATE_APR;
	// �׼�Ű
	enum class ACTION_KEY;

public:
	CVirus_Mettaur();
	virtual ~CVirus_Mettaur();

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
	enum class STATE_ACT { IDLE, PRE_ATTACK, ATTACK, HIDING, HID, SHOWING, JUMP, LANDING };
private: 
	STATE_SET<STATE_ACT, void(CVirus_Mettaur*, float)> m_tState_Act;

	void Idle(float fDeltaTime);
	void Prepare_Atk(float fDeltaTime);
	void Attack(float fDeltaTime);
	void Hiding(float fDeltaTime);
	void Hid(float fDeltaTime);
	void Showing(float fDeltaTime);
	void Jump(float fDeltaTime);
	void Landing(float fDeltaTime);



public: // ��ǥ ���¸ӽ�(AI)
	enum class STATE_OBJ { IDLE, CHASE, ATTACK, HIDE, WAITING, JUMP };
private: 
	STATE_SET<STATE_OBJ, void(CVirus_Mettaur*, float)> m_tState_Obj;
	DELAY<float>	m_fAction_Delay = DELAY<float>(1.f);

	void Obj_Idle(float fDeltaTime);
	void Obj_Chase(float fDeltaTime);
	void Obj_Attack(float fDeltaTime);
	void Obj_Hide(float fDeltaTime);
	void Obj_Waiting(float fDeltaTime);
	void Obj_Jump(float fDeltaTime);



public: // ���� ���¸ӽ� 
	enum class STATE_APR { NONE, APPEAR, DISAPPEAR, VISIBLE };
private: 
	STATE_SET<STATE_APR, void(CVirus_Mettaur*, float)> m_tState_Apr;
	DELAY<float>	m_fAppear_Delay = DELAY<float>(10.f);

	void Apr_None(float fDeltaTime);
	void Apr_Appear(float fDeltaTime);
	void Apr_Disappear(float fDeltaTime);
	void Apr_Visible(float fDeltaTime);

};