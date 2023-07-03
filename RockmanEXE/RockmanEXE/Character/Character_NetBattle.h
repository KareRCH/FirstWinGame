#pragma once

#include "Character.h"

#include "ObjMgr.h"

#define GRAVITY_NETBATTLE 9.8f * 1.3f;

/*
* 넷 배틀에 쓰이는 캐릭터에 대한 추상클래스
* 록맨, 내비, 바이러스, 각종 오브젝트, 무기와 같이
* 넷 배틀 시스템에 적용되는 요소가 있을 때 이 클래스를 상속받도록 한다.
*/

class CCharacter_NetBattle abstract : public CCharacter
{
public:
	CCharacter_NetBattle() {}
	virtual ~CCharacter_NetBattle() {}

public:
	// CCharacter을(를) 통해 상속됨
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

protected: // 범용 내부 변수
	vector<ULONGLONG>	m_ulTimers;				// 정해진 시간을 체킹하는 타이머
	vector<float>		m_fTimers;				// 시간값 

#pragma region 물리관련 

protected: // 물리 관련
	CVector3<float>				m_vecPosition;			// z축의 존재로 3차원 벡터를 사용합니다.
	list<list<CVector3<float>>>	m_vecSavedPos_List2D;	// 좌표 저장하는데 쓰이는 리스트, 정해진 좌표 이동이나 이전 좌표 이동과 같은 곳에 사용이 가능합니다.
														// 첫번째리스트는 목표 이동 좌표로 쓰입니다.
	CVector2<float>				m_vecFootPos;			// 패널을 밟기 위해 존재하는 벡터, Position에 더해씁니다.


	CVector3<float>			m_vecSpeed;					// 이동속도, 타일 범위로 이동하기 때문에 밀리는 효과에 사용합니다. z는 중력 적용
	CVector3<float>			m_vecAccel;					// 가속, 잘 안쓰이지만 z는 중력을 적용합니다.
	CVector3<float>			m_vecDamping;				// 감쇗값

	CVector3<float>			m_vecBox;					// 충돌박스의 크기를 저장하는 벡터, 가운데를 원점으로 둡니다.
	CVector3<float>			m_vecBoxPos;				// 충돌박스의 가운데를 기준으로 좌표이동을 할 수 있는 벡터

	bool					m_bLimit_Z = true;			// 중력에 대한 Z값 제한					

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
	// 넷 배틀 캐릭터에게 적용되는 중력 규칙
	void Gravity(float fDeltaTime)
	{
		m_vecSpeed.z += m_vecAccel.z * fDeltaTime;

		if (m_bLimit_Z && m_vecPosition.z < 0)
			m_vecPosition.z = 0;
	}

	// 캐릭터에게 적용되는 패널에 대한 일반 이동 규칙
	void Move_Panel()
	{
		// 목표 패널이 있을 때 순간이동으로 이동합니다.
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
	CVector2<int>		m_vecMoveDirection;		// 움직이는 방향을 설정할 때 사용됩니다.

public:
	CVector2<int> Get_Direction() { return m_vecDirection; }
	void Set_Direction(CVector2<int> value) { m_vecDirection = value; }
	void Set_Direction(int x, int y) { m_vecDirection.x = x; m_vecDirection.y = y; }

	CVector2<int> Get_MoveDirection() { return m_vecDirection; }
	void Set_MoveDirection(CVector2<int> value) { m_vecDirection = value; }
	void Set_MoveDirection(int x, int y) { m_vecDirection.x = x; m_vecDirection.y = y; }
#pragma endregion

#pragma region 네비용 인벤토리(칩 저장용)
protected:
	

public:

#pragma endregion

};

