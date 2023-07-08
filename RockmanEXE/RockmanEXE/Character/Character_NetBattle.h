#pragma once

#include "Character.h"
#include "ITeamAgent.h"

#include "ObjMgr.h"

#define GRAVITY_NETBATTLE 9.8f * 1.3f;



/*
* 넷 배틀에 쓰이는 캐릭터에 대한 추상클래스
* 록맨, 내비, 바이러스, 각종 오브젝트, 무기와 같이
* 넷 배틀 시스템에 적용되는 요소가 있을 때 이 클래스를 상속받도록 한다.
*/

class CCharacter_NetBattle abstract : public CCharacter, public ITeamAgent
{
public:
	CCharacter_NetBattle() : m_iAttack(), m_bInvincible() {}
	virtual ~CCharacter_NetBattle() {}

public:
	// CCharacter을(를) 통해 상속됨
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

protected: // 범용 내부 변수
	vector<ULONGLONG>	m_ulTimers;				// 정해진 시간을 체킹하는 타이머
	vector<float>		m_fTimers;				// 시간값 

#pragma region 물리관련 

protected: // 물리 관련
	CVector3<float>				m_vecPos;				// z축의 존재로 3차원 벡터를 사용합니다. 이미지 표시에 관여합니다. z축으로 위 아래를 조정합니다.
	CVector3<float>				m_vecBoxPos;			// 충돌박스의 가운데를 기준으로 좌표이동을 할 수 있는 벡터
	CVector3<float>				m_vecBox;				// 충돌박스의 크기를 저장하는 벡터, 가운데를 원점으로 둡니다.

	list<list<CVector3<float>>>	m_vecSavedPos_List2D;	// 좌표 저장하는데 쓰이는 리스트, 정해진 좌표 이동이나 이전 좌표 이동과 같은 곳에 사용이 가능합니다.
														// 첫번째리스트는 목표 이동 좌표로 쓰입니다.

	CVector3<float>			m_vecSpeed;					// 이동속도, 타일 범위로 이동하기 때문에 밀리는 효과에 사용합니다. z는 중력 적용
	CVector3<float>			m_vecAccel;					// 가속, 잘 안쓰이지만 z는 중력을 적용합니다.
	CVector3<float>			m_vecDamping;				// 감쇗값

	bool					m_bLimit_Z = true;			// 중력에 대한 Z값 제한		
	bool					m_bIsOnGround = true;		// 땅에 있을 때

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
	// 충돌박스에 대한 실제 영역을 구하는 함수입니다.
	// 필요할 때 쓸 수 있도록 디자인 되었습니다.
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

	// 넷 배틀 캐릭터에게 적용되는 이동 규칙.
	// 이동방향에 대해 판넬과 충돌시 조건에 따라 이동합니다.
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
	// 넷 배틀 캐릭터에게 적용되는 중력 규칙
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

	// 캐릭터에게 적용되는 패널에 대한 일반 이동 규칙
	void Move_Panel(CVector3<float> objPos)
	{
		// 목표 패널이 있을 때 순간이동으로 이동합니다.
		CVector3<float>	tVec3;
		tVec3.z = (m_vecPos.z - m_vecBox.z * 0.5f);
		
	}

	// 캐릭터에게 적용되는 패널에 대한 가속도 이동 규칙
	void Move_Panel_Smooth()
	{
		// 목표 패널이 있을 때 정해진 속도에 따라 이동합니다.
	}

	void Move_Panel_()
	{
		// 
	}

#pragma endregion

#pragma region 상태관련 

protected:	// 상태 관련
	CVector2<int>		m_vecDirection;			// 주로 좌우 방향에 사용됩니다. y의 용도는 아직 없음.
	CVector2<int>		m_vecMoveDir;			// 움직이는 방향을 설정할 때 사용됩니다.

public:
	CVector2<int> Get_Direction() { return m_vecDirection; }
	void Set_Direction(CVector2<int> value) { m_vecDirection = value; }
	void Set_Direction(int x, int y) { m_vecDirection.x = x; m_vecDirection.y = y; }

	CVector2<int> Get_MoveDirection() { return m_vecMoveDir; }
	void Set_MoveDirection(CVector2<int> value) { m_vecMoveDir = value; }
	void Set_MoveDirection(int x, int y) { m_vecMoveDir.x = x; m_vecMoveDir.y = y; }
#pragma endregion

#pragma region 스테이터스 관련
protected:
	GAUGE<int>	m_iHP;			// 체력
	int			m_iAttack;		// 공격력

	bool		m_bInvincible;	// 무적

	bool		m_bHit;			// 맞음
	bool		m_bParalyze;	// 마비

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

