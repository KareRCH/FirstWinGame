#pragma once

#include "Define.h"

#define BATTLE_PANEL_ROW 3
#define BATTLE_PANEL_COL 6

#define PANEL_CROW 39
#define PANEL_CCOL 23

class CPanel
{
public:
	CPanel() {}
	~CPanel() { Release(); }

public:
	void Initialize();
	void Update(float fDeltaTime);
	void Late_Update(float fDeltaTime);
	void Render(HDC hDC);
	void Release();

private:
	INFO	m_tInfo = {};
	RECT	m_tRect = {};

public:
	RECT			Get_Rect() { return m_tRect; }
	INFO			Get_Info() { return m_tInfo; }

	void			Set_PosY(float _fY) { m_tInfo.fY += _fY; }
	void			Set_PosX(float _fX) { m_tInfo.fX += _fX; }
	void			Set_Pos(float _fX, float _fY) { m_tInfo.fX = _fX; m_tInfo.fY = _fY; }

	void			Set_Size(float _fCX, float _fCY) { m_tInfo.fCX = _fCX; m_tInfo.fCY = _fCY; }
};

class CPanelFactory
{
private:
	CPanelFactory() = delete;
	CPanelFactory(const CPanelFactory& rhs) = delete;
	~CPanelFactory() = delete;

public:
	static CPanel* Create()
	{
		CPanel* pObj = new CPanel;
		pObj->Initialize();

		return pObj;
	}

	static CPanel* Create(float _fX, float _fY)
	{
		CPanel* pObj = new CPanel;
		pObj->Set_Pos(_fX, _fY);
		pObj->Initialize();

		return pObj;
	}

	static CPanel* Create(INFO tInfo)
	{
		CPanel* pObj = new CPanel;
		pObj->Set_Pos(tInfo.fX, tInfo.fY);
		pObj->Set_Size(tInfo.fCX, tInfo.fCY);
		pObj->Initialize();

		return pObj;
	}
};