#pragma once

#include "Obj.h"

class CObjMgr
{
private:
	CObjMgr();
	~CObjMgr();

public:
	CObj*		Get_Player() { return m_ObjList[PLAYER].front();  }
	CObj*		Get_Target(OBJID eID, CObj* pInstance);

public:
	void		Add_Object(OBJID eID, CObj* pInstance);
	int			Update(float fDeltaTime);
	void		Late_Update(float fDeltaTime);
	void		Render(HDC hDC);
	void		Release();

	void		Delete_ID(OBJID eID);

public:
	static CObjMgr*		Get_Instance()
	{
		if (!m_pInstance)
		{
			m_pInstance = new CObjMgr;
		}

		return m_pInstance;
	}
	static void		Destroy_Instance()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

private:
	list<CObj*>	m_ObjList[OBJID_END];

	static CObjMgr*		m_pInstance;

public:
	list<CObj*>* Get_ObjList(OBJID eID)
	{
		return &m_ObjList[eID];
	}

	list<CObj*>* Get_ObjListAll()
	{
		return m_ObjList;
	}
};