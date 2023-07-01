#include "MainGame.h"

#include "Define.h"
#include "AbstractFactory.h"
//#include "Player.h"
//#include "Bullet.h"
//#include "Monster.h"
//#include "Mouse.h"
#include "ObjMgr.h"
#include "KeyMgr.h"
#include "BmpMgr.h"
#include "SceneMgr.h"
#include "ScrollMgr.h"

CMainGame::CMainGame() : m_hDC(nullptr), m_ulTime(GetTickCount64()), m_iFPS(0)
{
	ZeroMemory(m_szFPS, sizeof(m_szFPS));
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	m_hDC = GetDC(g_hWnd);

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Back.bmp", L"Back");

	CSceneMgr::Get_Instance()->Scene_Change(SC_STAGE);

#ifdef _DEBUG
#if _TEST_CONSOLE
	// 디버그용 콘솔창
	if (::AllocConsole() == TRUE)
	{
		FILE* nfp[3];
		freopen_s(nfp + 0, "CONOUT$", "rb", stdin);
		freopen_s(nfp + 1, "CONOUT$", "wb", stdout);
		freopen_s(nfp + 2, "CONOUT$", "wb", stderr);
		std::ios::sync_with_stdio();
	}
#endif
#endif // _DEBUG
}

void CMainGame::Update(float fDeltaTime)
{
	CSceneMgr::Get_Instance()->Update(fDeltaTime);
}


void CMainGame::Late_Update(float fDeltaTime)
{
	CScrollMgr::Get_Instance()->Scroll_Lock();

	CSceneMgr::Get_Instance()->Late_Update(fDeltaTime);

	CKeyMgr::Get_Instance()->Late_Update();
}

void CMainGame::Render()
{
	++m_iFPS;

	// 타이틀에 fps 출력
	if (m_ulTime + 1000 < GetTickCount64())
	{
		swprintf_s(m_szFPS, L"FPS : %d", m_iFPS);
		SetWindowText(g_hWnd, m_szFPS);

		m_iFPS = 0;
		m_ulTime = GetTickCount64();
	}

	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Back");

	CSceneMgr::Get_Instance()->Render(hMemDC);

	RECT rcClient;
	GetClientRect(g_hWnd, &rcClient);

	//BitBlt(
	//	m_hDC,				// 복사 받을 DC(최종적으로 그림을 그릴 DC공간)
	//	0, 0, WINCX, WINCY,
	//	hMemDC,				// 비트맵 이미지를 담고 있는 DC
	//	0, 0,
	//	SRCCOPY);
	StretchBlt(
		m_hDC,				// 복사 받을 DC(최종적으로 그림을 그릴 DC공간)
		0, 0, rcClient.right, rcClient.bottom,
		hMemDC,				// 비트맵 이미지를 담고 있는 DC
		0, 0, WINCX, WINCY,
		SRCCOPY);
}

void CMainGame::Release()
{	
#ifdef _DEBUG
#if _TEST_CONSOLE
	// 콘솔 사용 해제
	FreeConsole();
#endif
#endif // _DEBUG
	CBmpMgr::Destroy_Instance();
	CScrollMgr::Destroy_Instance();
	CKeyMgr::Destroy_Instance();
	CObjMgr::Destroy_Instance();
	CSceneMgr::Destroy_Instance();

	ReleaseDC(g_hWnd, m_hDC);	
}
