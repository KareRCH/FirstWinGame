#pragma once

#include "Define.h"

#include "Obj.h"

class CScrollMgr
{
private:
	CScrollMgr();
	~CScrollMgr();

public:
	static CScrollMgr*		Get_Instance()
	{
		if (!m_pInstance)
		{
			m_pInstance = new CScrollMgr;
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

public: 
	float		Get_ScollX() { return m_fScrollX; }
	float		Get_ScollY() { return m_fScrollY; }

	void		Set_ScrollX(float _fX) { m_fScrollX += _fX; }
	void		Set_ScrollY(float _fY) { m_fScrollY += _fY; }

	void		Set_Scroll(float _fX, float _fY) { m_fScrollX = _fX; m_fScrollY = _fY; }

	void		Set_LockSize(int _iX, int _iY)
	{
		m_iLockX = _iX;
		m_iLockY = _iY;
	}

	int		Get_LockX() { return m_iLockX; }
	int		Get_LockY() { return m_iLockY; }

	void		Scroll_Lock();

private:
	static CScrollMgr*		m_pInstance;

	float					m_fScrollX;
	float					m_fScrollY;

	int						m_iLockX;
	int						m_iLockY;

private:
	CObj* m_pLockOn_Obj = nullptr;

public:
	void	Set_LockOn_Obj(CObj* value) { m_pLockOn_Obj = value;  }

};

