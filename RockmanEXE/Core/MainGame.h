#pragma once

#include "Define.h"

class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	void		Initialize();
	void		Update(float fDeltaTime);
	void		Late_Update(float fDeltaTime);
	void		Render();
	void		Release();

private:
	HDC			m_hDC;

	ULONGLONG	m_ulTime;
	int			m_iFPS;
	TCHAR		m_szFPS[32];
};