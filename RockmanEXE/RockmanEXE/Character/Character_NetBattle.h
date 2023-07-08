#pragma once

#include "Character.h"
#include "ITeamAgent.h"

#include "ObjMgr.h"

#define GRAVITY_NETBATTLE 9.8f * 1.3f;



/*
* �� ��Ʋ�� ���̴� ĳ���Ϳ� ���� �߻�Ŭ����
* �ϸ�, ����, ���̷���, ���� ������Ʈ, ����� ����
* �� ��Ʋ �ý��ۿ� ����Ǵ� ��Ұ� ���� �� �� Ŭ������ ��ӹ޵��� �Ѵ�.
*/

class CCharacter_NetBattle abstract : public CCharacter, public ITeamAgent
{
public:
	CCharacter_NetBattle() : m_iAttack(), m_bInvincible() {}
	virtual ~CCharacter_NetBattle() {}

public:
	// CCharacter��(��) ���� ��ӵ�
	virtual void Initialize(void)					PURE;
	virtual int	 Update(float fDeltaTime)			PURE;
	virtual void Late_Update(float fDeltaTime)		PURE;
	virtual void Render(HDC hDC)					PURE;
	virtual void Release(void)						PURE;
	virtual void Collide(CObj* _pDst)				PURE;

protected:
	void Initialize_Gravity()
	{
		m_vecAccel.z = (-1.f) * GRAVITY_NETBATTLE;
	}

protected: // ���� ���� ����
	vector<ULONGLONG>	m_ulTimers;				// ������ �ð��� üŷ�ϴ� Ÿ�̸�
	vector<float>		m_fTimers;				// �ð��� 

#pragma region �������� 

protected: // ���� ����
	CVector3<float>				m_vecPos;				// z���� ����� 3���� ���͸� ����մϴ�. �̹��� ǥ�ÿ� �����մϴ�. z������ �� �Ʒ��� �����մϴ�.
	CVector3<float>				m_vecBoxPos;			// �浹�ڽ��� ����� �������� ��ǥ�̵��� �� �� �ִ� ����
	CVector3<float>				m_vecBox;				// �浹�ڽ��� ũ�⸦ �����ϴ� ����, ����� �������� �Ӵϴ�.

	list<list<CVector3<float>>>	m_vecSavedPos_List2D;	// ��ǥ �����ϴµ� ���̴� ����Ʈ, ������ ��ǥ �̵��̳� ���� ��ǥ �̵��� ���� ���� ����� �����մϴ�.
														// ù��°����Ʈ�� ��ǥ �̵� ��ǥ�� ���Դϴ�.

	CVector3<float>			m_vecSpeed;					// �̵��ӵ�, Ÿ�� ������ �̵��ϱ� ������ �и��� ȿ���� ����մϴ�. z�� �߷� ����
	CVector3<float>			m_vecAccel;					// ����, �� �Ⱦ������� z�� �߷��� �����մϴ�.
	CVector3<float>			m_vecDamping;				// ���氪

	bool					m_bLimit_Z = true;			// �߷¿� ���� Z�� ����		
	bool					m_bIsOnGround = true;		// ���� ���� ��

public:
	void			Set_VecPos(CVector3<float> value) { m_vecPos = value; }
	CVector3<float> Get_VecPos() { return m_vecPos; }

	void			Set_Box(CVector3<float> value) { m_vecBox = value; }
	CVector3<float> Get_Box() { return m_vecBox; }

	void			Set_BoxPos(CVector3<float>& value) { m_vecBoxPos = value; }
	CVector3<float> Get_BoxPos() { return m_vecBoxPos; }

	void			Set_Speed(CVector3<float> value) { m_vecSpeed = value; }
	CVector3<float> Get_Speed() { return m_vecSpeed; }

	void			Set_Accel(CVector3<float> value) { m_vecAccel = value; }
	CVector3<float> Get_Accel() { return m_vecAccel; }

	void			Set_Damping(CVector3<float> value) { m_vecDamping = value; }
	CVector3<float> Get_Damping() { return m_vecDamping; }

	bool			IsOnGround() { return m_bIsOnGround; }

public:
	// �浹�ڽ��� ���� ���� ������ ���ϴ� �Լ��Դϴ�.
	// �ʿ��� �� �� �� �ֵ��� ������ �Ǿ����ϴ�.
	CVecBox<float> Get_BoxArea()
	{
		CVecBox<float> vecBoxArea = CVecBox<float>();
		vecBoxArea.right	= m_vecPos.x + m_vecBoxPos.x + m_vecBox.x;
		vecBoxArea.left		= m_vecPos.x + m_vecBoxPos.x - m_vecBox.x;
		vecBoxArea.up		= m_vecPos.y + m_vecBoxPos.y + m_vecBox.y;
		vecBoxArea.down		= m_vecPos.y + m_vecBoxPos.y - m_vecBox.y;
		vecBoxArea.top		= m_vecPos.z + m_vecBoxPos.z + m_vecBox.z;
		vecBoxArea.bottom	= m_vecPos.z + m_vecBoxPos.z - m_vecBox.z;

		return vecBoxArea;
	}

	// �� ��Ʋ ĳ���Ϳ��� ����Ǵ� �̵� ��Ģ.
	// �̵����⿡ ���� �ǳڰ� �浹�� ���ǿ� ���� �̵��մϴ�.
	void Move(float fDeltaTime)
	{
		if (IsOnGround())
		{
			if (m_vecSpeed.x != 0.f || m_vecSpeed.y != 0.f)
			{
				m_vecPos.x += m_vecSpeed.x;
				m_vecPos.y -= m_vecSpeed.y;

				m_vecSpeed.x = 0.f;
				m_vecSpeed.y = 0.f;
			}
		}
	}
	// �� ��Ʋ ĳ���Ϳ��� ����Ǵ� �߷� ��Ģ
	void Gravity(float fDeltaTime)
	{
		m_vecSpeed.z += m_vecAccel.z * fDeltaTime;

		float	fNextZ;
		fNextZ = m_vecPos.z - (m_vecBox.z - m_vecBoxPos.z) + m_vecSpeed.z;
		if (m_bLimit_Z && (fNextZ < 0.f))
		{
			m_vecPos.z = (m_vecBox.z - m_vecBoxPos.z);
			m_vecSpeed.z = 0;
			m_bIsOnGround = true;
		}
		else
		{
			m_vecPos.z += m_vecSpeed.z;
			m_bIsOnGround = false;
		}
	}

	// ĳ���Ϳ��� ����Ǵ� �гο� ���� �Ϲ� �̵� ��Ģ
	void Move_Panel(CVector3<float> objPos)
	{
		// ��ǥ �г��� ���� �� �����̵����� �̵��մϴ�.
		CVector3<float>	tVec3;
		tVec3.z = (m_vecPos.z - m_vecBox.z * 0.5f);
		
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
	CVector2<int>		m_vecMoveDir;			// �����̴� ������ ������ �� ���˴ϴ�.

public:
	CVector2<int> Get_Direction() { return m_vecDirection; }
	void Set_Direction(CVector2<int> value) { m_vecDirection = value; }
	void Set_Direction(int x, int y) { m_vecDirection.x = x; m_vecDirection.y = y; }

	CVector2<int> Get_MoveDirection() { return m_vecMoveDir; }
	void Set_MoveDirection(CVector2<int> value) { m_vecMoveDir = value; }
	void Set_MoveDirection(int x, int y) { m_vecMoveDir.x = x; m_vecMoveDir.y = y; }
#pragma endregion

#pragma region �������ͽ� ����
protected:
	GAUGE<int>	m_iHP;			// ü��
	int			m_iAttack;		// ���ݷ�

	bool		m_bInvincible;	// ����

	bool		m_bHit;			// ����
	bool		m_bParalyze;	// ����

public:
	GAUGE<int>  Get_HP() { return m_iHP; }
	void		Set_HP(int value) { m_iHP.Cur = value; }
	void		Set_ResetHP(int value) { m_iHP = GAUGE<int>(value, true); }

	int			Get_Attack() { return m_iAttack; }
	void		Set_Attack(int value) { m_iAttack = value; }

	bool		Get_Invincible() { return m_bInvincible; }
	void		Set_Invincible(bool value) { m_bInvincible = value; }
#pragma endregion


};

