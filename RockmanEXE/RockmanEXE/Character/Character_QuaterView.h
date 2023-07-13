#pragma once

#include "Character.h"

#include "ObjMgr.h"

/*
* 쿼터뷰로 구성된 월드를 돌아다닐 수 있는 캐릭터에 대한 추상클래스
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

protected: // 범용 내부 변수
	vector<ULONGLONG>			m_ulTimers;				// CPU 기반으로 정해진 시간을 체킹하는 타이머
	vector<GAUGE<float>>		m_fTimers;				// DeltaTime 기반 타이머 

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
		vecBoxArea.right = m_vecPos.x + m_vecBoxPos.x + m_vecBox.x;
		vecBoxArea.left = m_vecPos.x + m_vecBoxPos.x - m_vecBox.x;
		vecBoxArea.up = m_vecPos.y + m_vecBoxPos.y + m_vecBox.y;
		vecBoxArea.down = m_vecPos.y + m_vecBoxPos.y - m_vecBox.y;
		vecBoxArea.top = m_vecPos.z + m_vecBoxPos.z + m_vecBox.z;
		vecBoxArea.bottom = m_vecPos.z + m_vecBoxPos.z - m_vecBox.z;

		return vecBoxArea;
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

#pragma endregion

#pragma region 상태관련 

protected:	// 상태 관련
	CVector2<int>		m_vecDirection;			// 주로 좌우 방향에 사용됩니다. y의 용도는 아직 없음.
	CVector2<int>		m_vecMoveDir;			// 움직이는 방향을 설정할 때 사용됩니다.
	bool m_bCommunication = false;

public:
	CVector2<int> Get_Direction() { return m_vecDirection; }
	void Set_Direction(CVector2<int> value) { m_vecDirection = value; }
	void Set_Direction(int x, int y) { m_vecDirection.x = x; m_vecDirection.y = y; }

	CVector2<int> Get_MoveDirection() { return m_vecMoveDir; }
	void Set_MoveDirection(CVector2<int> value) { m_vecMoveDir = value; }
	void Set_MoveDirection(int x, int y) { m_vecMoveDir.x = x; m_vecMoveDir.y = y; }

	// 말을 걸때 실행할 함수
	virtual void Commnication() {}
#pragma endregion


};

