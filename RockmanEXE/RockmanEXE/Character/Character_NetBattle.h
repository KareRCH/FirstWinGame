#pragma once

#include "Character.h"

#include "ObjMgr.h"

#define GRAVITY_NETBATTLE 9.8f * 1.3f;

/*
* �� ��Ʋ�� ���̴� ĳ���Ϳ� ���� �߻�Ŭ����
* �ϸ�, ����, ���̷���, ���� ������Ʈ, ����� ����
* �� ��Ʋ �ý��ۿ� ����Ǵ� ��Ұ� ���� �� �� Ŭ������ ��ӹ޵��� �Ѵ�.
*/

class CCharacter_NetBattle abstract : public CCharacter
{
public:
	CCharacter_NetBattle() {}
	virtual ~CCharacter_NetBattle() {}

public:
	// CCharacter��(��) ���� ��ӵ�
	virtual void Initialize(void) override
	{
		m_vecAccel.z = (-1.f) * GRAVITY_NETBATTLE;
		CObjMgr::Get_Instance()->Add_Object(UNIT, this);
	}
	virtual int	 Update(float fDeltaTime)			PURE;
	virtual void Late_Update(float fDeltaTime)		PURE;
	virtual void Render(HDC hDC)					PURE;
	virtual void Release(void)						PURE;
	virtual void Collide(CObj* _pDst)				PURE;

protected: // ���� ���� ����
	vector<ULONGLONG>	m_ulTimers;				// ������ �ð��� üŷ�ϴ� Ÿ�̸�
	vector<float>		m_fTimers;				// �ð��� 

#pragma region �������� 

protected: // ���� ����
	CVector3<float>				m_vecPosition;			// z���� ����� 3���� ���͸� ����մϴ�.
	list<list<CVector3<float>>>	m_vecSavedPos_List2D;	// ��ǥ �����ϴµ� ���̴� ����Ʈ, ������ ��ǥ �̵��̳� ���� ��ǥ �̵��� ���� ���� ����� �����մϴ�.
														// ù��°����Ʈ�� ��ǥ �̵� ��ǥ�� ���Դϴ�.
	CVector2<float>				m_vecFootPos;			// �г��� ��� ���� �����ϴ� ����, Position�� ���ؾ��ϴ�.


	CVector3<float>			m_vecSpeed;					// �̵��ӵ�, Ÿ�� ������ �̵��ϱ� ������ �и��� ȿ���� ����մϴ�. z�� �߷� ����
	CVector3<float>			m_vecAccel;					// ����, �� �Ⱦ������� z�� �߷��� �����մϴ�.
	CVector3<float>			m_vecDamping;				// ���氪

	CVector3<float>			m_vecBox;					// �浹�ڽ��� ũ�⸦ �����ϴ� ����, ����� �������� �Ӵϴ�.
	CVector3<float>			m_vecBoxPos;				// �浹�ڽ��� ����� �������� ��ǥ�̵��� �� �� �ִ� ����

	bool					m_bLimit_Z = true;			// �߷¿� ���� Z�� ����					

public:
	void			Set_Position(CVector3<float>& value) { m_vecPosition = value; }
	CVector3<float> Get_Position() { return m_vecPosition; }

	void			Set_Box(CVector3<float>& value) { m_vecBox = value; }
	CVector3<float> Get_Box() { return m_vecBox; }

	void			Set_FootPos(CVector2<float>& value) { m_vecFootPos = value; }
	CVector2<float> Get_FootPos() { return m_vecFootPos; }

	void			Set_BoxPos(CVector3<float>& value) { m_vecBoxPos = value; }
	CVector3<float> Get_BoxPos() { return m_vecBoxPos; }

	void			Set_Speed(CVector3<float>& value) { m_vecSpeed = value; }
	CVector3<float> Get_Speed() { return m_vecSpeed; }

	void			Set_Accel(CVector3<float>& value) { m_vecAccel = value; }
	CVector3<float> Get_Accel() { return m_vecAccel; }

	void			Set_Damping(CVector3<float>& value) { m_vecDamping = value; }
	CVector3<float> Get_Damping() { return m_vecDamping; }

public:
	// �� ��Ʋ ĳ���Ϳ��� ����Ǵ� �߷� ��Ģ
	void Gravity(float fDeltaTime)
	{
		m_vecSpeed.z += m_vecAccel.z * fDeltaTime;

		if (m_bLimit_Z && m_vecPosition.z < 0)
			m_vecPosition.z = 0;
	}

	// ĳ���Ϳ��� ����Ǵ� �гο� ���� �Ϲ� �̵� ��Ģ
	void Move_Panel()
	{
		// ��ǥ �г��� ���� �� �����̵����� �̵��մϴ�.
	}

	// ĳ���Ϳ��� ����Ǵ� �гο� ���� ���ӵ� �̵� ��Ģ
	void Move_Panel_Smooth()
	{
		// ��ǥ �г��� ���� �� ������ �ӵ��� ���� �̵��մϴ�.
	}

	void Move_Panel_()
	{
		// 
	}

#pragma endregion

#pragma region ���°��� 

protected:	// ���� ����
	CVector2<int>		m_vecDirection;			// �ַ� �¿� ���⿡ ���˴ϴ�. y�� �뵵�� ���� ����.
	CVector2<int>		m_vecMoveDirection;		// �����̴� ������ ������ �� ���˴ϴ�.

public:
	CVector2<int> Get_Direction() { return m_vecDirection; }
	void Set_Direction(CVector2<int> value) { m_vecDirection = value; }
	void Set_Direction(int x, int y) { m_vecDirection.x = x; m_vecDirection.y = y; }

	CVector2<int> Get_MoveDirection() { return m_vecDirection; }
	void Set_MoveDirection(CVector2<int> value) { m_vecDirection = value; }
	void Set_MoveDirection(int x, int y) { m_vecDirection.x = x; m_vecDirection.y = y; }
#pragma endregion

#pragma region �׺�� �κ��丮(Ĩ �����)
protected:
	

public:

#pragma endregion

};

