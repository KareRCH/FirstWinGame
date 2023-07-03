#pragma once

#include "Define.h"

/*
* 모든 게임 프로세스는 여기에서 실행됩니다.
* 병렬적으로 게임을 실행하는 것도 가능합니다.
* 이에 대한 모든 자원은 여기서 관리합니다.
*/

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

	// Gdiplus 토큰
	ULONG_PTR m_gdiplusToken;
};