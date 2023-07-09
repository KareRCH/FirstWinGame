#pragma once

#include "Character/Character_QuaterView.h"

class CPlayer_QuaterView : public CCharacter_QuaterView
{
public:
	enum class STATE { STAND, RUN, WARP, WARPED, SHOOT, BATTLE, BURN, DEFEND };
	enum class ACTION_KEY { LEFT, RIGHT, UP, DOWN };
public:
	CPlayer_QuaterView() {}
	virtual ~CPlayer_QuaterView() {}
public:
	// CCharacter_QuaterView��(��) ���� ��ӵ�
	virtual void Initialize(void) override;
	virtual int Update(float fDeltaTime) override;
	virtual void Late_Update(float fDeltaTime) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	virtual void Collide(CObj* _pDst) override;

#pragma region ��ǲ ����
private:
	bool Input_Move();
#pragma endregion


#pragma region ���� ����
private:
	void Move();
#pragma endregion

#pragma region �������ͽ� ����
protected:
	GAUGE<int>		m_iHP;				// ü��

public:
	GAUGE<int>  Get_HP() { return m_iHP; }
	void		Set_HP(int value) { m_iHP.Cur = value; }
	void		Set_ResetHP(int value) { m_iHP = GAUGE<int>(value, true); }
#pragma endregion

#pragma region ���� ����
protected:
	wstring		m_sDirection;
	wstring		m_sAnimName;

	MAP_ACTION<ACTION_KEY>								m_mapActionKey;

	STATE_INFO<STATE>									m_tState;
	MAP_FUNC<STATE, void(CPlayer_QuaterView*, float)>	m_fnState;

public:
	void		Set_DirectionStr(int value)
	{
		wstringstream ssInt;
		ssInt << value;
		m_sDirection = ssInt.str();
	}

public:
	void		State_Update(float fDeltaTime);

private:
	void		Stand(float fDeltaTime);
	void		Run(float fDeltaTime);
	void		Warped(float fDeltaTime);
	void		Warp(float fDeltaTime);
	void		Shoot(float fDeltaTime);
	void		Burn(float fDeltaTime);
	void		Defend(float fDeltaTime);
#pragma endregion

};

