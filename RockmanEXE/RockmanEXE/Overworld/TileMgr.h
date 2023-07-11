#pragma once

#include "Tile.h"

class CTileMgr
{
private:
	CTileMgr();
	~CTileMgr();

public:
	void Initialize();
	void Update(float fDeltaTime);
	void Late_Update(float fDeltaTime);
	void Render(HDC hDC);
	void Release();

	void	Picking_Tile(POINT pt, int _iDrawID, int _iOption);
	void	Reset();
	
	void	Save_Tile();
	void	Load_Tile();
public:
	static CTileMgr*		Get_Instance()
	{
		if (!m_pInstance)
		{
			m_pInstance = new CTileMgr;
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
	static CTileMgr*		m_pInstance;			// 
	INFO					m_tPos;					// 타일 표시 시작 위치
	vector<CObj*>			m_vecTile;

public:
	vector<CObj*>* Get_Tiles() { return &m_vecTile; }

};

