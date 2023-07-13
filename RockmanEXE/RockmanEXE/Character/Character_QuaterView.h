#pragma once

#include "Character.h"

#include "ObjMgr.h"

/*
* ���ͺ�� ������ ���带 ���ƴٴ� �� �ִ� ĳ���Ϳ� ���� �߻�Ŭ����
*/

class CCharacter_QuaterView abstract : public CCharacter
{
public:
	CCharacter_QuaterView() {}
	virtual ~CCharacter_QuaterView() {}
public:
	virtual void Initialize(void)					PURE;
	virtual int	 Update(float fDeltaTime)			PURE;
	virtual void Late_Update(float fDeltaTime)		PURE;
	virtual void Render(HDC hDC)					PURE;
	virtual void Release(void)						PURE;
	virtual void Collide(CObj* _pDst)				PURE;

	void Initialize_QuaterChr()
	{
		CObjMgr::Get_Instance()->Add_Object(UNIT, this);
	}

	void Info_Update()
	{
		m_tInfo.fX = m_vecPos.x;
		m_tInfo.fY = m_vecPos.y;
	}

protected: // ���� ���� ����
	vector<ULONGLONG>			m_ulTimers;				// CPU ������� ������ �ð��� üŷ�ϴ� Ÿ�̸�
	vector<GAUGE<float>>		m_fTimers;				// DeltaTime ��� Ÿ�̸� 

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
		vecBoxArea.right = m_vecPos.x + m_vecBoxPos.x + m_vecBox.x;
		vecBoxArea.left = m_vecPos.x + m_vecBoxPos.x - m_vecBox.x;
		vecBoxArea.up = m_vecPos.y + m_vecBoxPos.y + m_vecBox.y;
		vecBoxArea.down = m_vecPos.y + m_vecBoxPos.y - m_vecBox.y;
		vecBoxArea.top = m_vecPos.z + m_vecBoxPos.z + m_vecBox.z;
		vecBoxArea.bottom = m_vecPos.z + m_vecBoxPos.z - m_vecBox.z;

		return vecBoxArea;
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

#pragma endregion

#pragma region ���°��� 

protected:	// ���� ����
	CVector2<int>		m_vecDirection;			// �ַ� �¿� ���⿡ ���˴ϴ�. y�� �뵵�� ���� ����.
	CVector2<int>		m_vecMoveDir;			// �����̴� ������ ������ �� ���˴ϴ�.
	bool m_bCommunication = false;

public:
	CVector2<int> Get_Direction() { return m_vecDirection; }
	void Set_Direction(CVector2<int> value) { m_vecDirection = value; }
	void Set_Direction(int x, int y) { m_vecDirection.x = x; m_vecDirection.y = y; }

	CVector2<int> Get_MoveDirection() { return m_vecMoveDir; }
	void Set_MoveDirection(CVector2<int> value) { m_vecMoveDir = value; }
	void Set_MoveDirection(int x, int y) { m_vecMoveDir.x = x; m_vecMoveDir.y = y; }

	// ���� �ɶ� ������ �Լ�
	virtual void Commnication() {}
#pragma endregion


};

