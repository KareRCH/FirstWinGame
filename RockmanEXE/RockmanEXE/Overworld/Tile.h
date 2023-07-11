#pragma once

#include "Obj.h"
#include "ObjMgr.h"

class CTile : public CObj
{
public:
	CTile();
	virtual ~CTile();

public:
	void		Set_ID(int _iDrawID, int _iOption)
	{
		m_iDrawID = _iDrawID;
		m_iOption = _iOption;
	}

	int			Get_DrawID() { return m_iDrawID; }
	int			Get_Option() { return m_iOption; }

public:
	virtual void Initialize(void) override;
	virtual int Update(float) override;
	virtual void Late_Update(float) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	virtual void Collide(CObj* _pDst) override;

private:
	int			m_iDrawID = 0;
	int			m_iOption = 0;

#pragma region 물리관련 

protected: // 물리 관련
	CVector3<float>				m_vecPos;				// z축의 존재로 3차원 벡터를 사용합니다. 이미지 표시에 관여합니다. z축으로 위 아래를 조정합니다.
	CVector3<float>				m_vecBoxPos;			// 충돌박스의 가운데를 기준으로 좌표이동을 할 수 있는 벡터
	CVector3<float>				m_vecBox;				// 충돌박스의 크기를 저장하는 벡터, 가운데를 원점으로 둡니다.

public:
	void			Set_VecPos(CVector3<float> value) { m_vecPos = value; }
	CVector3<float> Get_VecPos() { return m_vecPos; }

	void			Set_Box(CVector3<float> value) { m_vecBox = value; }
	CVector3<float> Get_Box() { return m_vecBox; }

	void			Set_BoxPos(CVector3<float>& value) { m_vecBoxPos = value; }
	CVector3<float> Get_BoxPos() { return m_vecBoxPos; }

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

#pragma endregion
};

// CSpell_Shockwave_Factory::Create((TEAM_ID)Get_TeamID(), m_vecPos, m_vecDirection, 5.f, 0.75f);
class CTile_Factory
{
private:
	CTile_Factory() = delete;
	CTile_Factory(const CTile_Factory& rhs) = delete;
	~CTile_Factory() = delete;

public:
	static CTile* Create(CVector3<float> vecPos)
	{
		CTile* pObj = new CTile;
		pObj->Initialize();
		pObj->Set_VecPos(vecPos);

		//CObjMgr::Get_Instance()->Add_Object(OBJID::TILE, pObj);

		return static_cast<CTile*>(pObj);
	}
};