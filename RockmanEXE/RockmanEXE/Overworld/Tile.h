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

#pragma region �������� 

protected: // ���� ����
	CVector3<float>				m_vecPos;				// z���� ����� 3���� ���͸� ����մϴ�. �̹��� ǥ�ÿ� �����մϴ�. z������ �� �Ʒ��� �����մϴ�.
	CVector3<float>				m_vecBoxPos;			// �浹�ڽ��� ����� �������� ��ǥ�̵��� �� �� �ִ� ����
	CVector3<float>				m_vecBox;				// �浹�ڽ��� ũ�⸦ �����ϴ� ����, ����� �������� �Ӵϴ�.

public:
	void			Set_VecPos(CVector3<float> value) { m_vecPos = value; }
	CVector3<float> Get_VecPos() { return m_vecPos; }

	void			Set_Box(CVector3<float> value) { m_vecBox = value; }
	CVector3<float> Get_Box() { return m_vecBox; }

	void			Set_BoxPos(CVector3<float>& value) { m_vecBoxPos = value; }
	CVector3<float> Get_BoxPos() { return m_vecBoxPos; }

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