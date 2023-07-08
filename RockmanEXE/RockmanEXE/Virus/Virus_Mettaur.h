#pragma once

#include "Virus.h"

class CVirus_Mettaur : public CVirus
{
public:
	// ���� �ൿ�� ����
	enum class ACT_STATE { IDLE, PRE_ATTACK, ATTACK, HIDING, HID, SHOWING, JUMP, LANDING };
	// ��ǥ ����(AI)
	enum class OBJ_STATE { IDLE, CHASE, ATTACK, HIDE, WAITING, JUMP };
	// �ൿŰ
	enum class ACTION_KEY { LEFT, RIGHT, UP, DOWN, ATTACK, HIDE, JUMP, ATTACKED };

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

private:
	STATE_INFO<ACT_STATE>	m_tState_Act;
	STATE_INFO<OBJ_STATE>	m_tState_Obj;
	MAP_ACTION<ACTION_KEY>	m_mapActionKey;

private:
	MAP_FUNC<ACT_STATE, void(CVirus_Mettaur*, float)> m_fnActState;

	// �ൿ ���¸ӽ�
	void Idle(float fDeltaTime);
	void Prepare_Atk(float fDeltaTime);
	void Attack(float fDeltaTime);
	void Hiding(float fDeltaTime);
	void Hid(float fDeltaTime);
	void Showing(float fDeltaTime);
	void Jump(float fDeltaTime);
	void Landing(float fDeltaTime);

private:
	MAP_FUNC<OBJ_STATE, void(CVirus_Mettaur*, float)> m_fnObjState;

	// ��ǥ ���¸ӽ�
	void Obj_Idle(float fDeltaTime);
	void Obj_Chase(float fDeltaTime);
	void Obj_Attack(float fDeltaTime);
	void Obj_Hide(float fDeltaTime);
	void Obj_Waiting(float fDeltaTime);
	void Obj_Jump(float fDeltaTime);
};

