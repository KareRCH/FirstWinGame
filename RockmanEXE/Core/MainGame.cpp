#include "MainGame.h"

#include "Define.h"
//#include "Player.h"
//#include "Bullet.h"
//#include "Monster.h"
//#include "Mouse.h"
#include "ObjMgr.h"
#include "KeyMgr.h"
#include "BmpMgr.h"
#include "SceneMgr.h"
#include "ScrollMgr.h"
#include "SoundMgr.h"
#include "Manager/AnimationTable.h"
#include "Manager/ChipDataTable.h"
#include "ITeamAgent.h"

CMainGame::CMainGame() : m_hDC(nullptr), m_ulTime(GetTickCount64()), m_iFPS(0), m_gdiplusToken()
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

	// Gdiplus 초기화
	//ULONG_PTR gdiplusToken;
	Gdp::GdiplusStartupInput gdiplusStartupInput;
	gdiplusStartupInput.GdiplusVersion = 1;
	gdiplusStartupInput.SuppressBackgroundThread = FALSE;
	Gdp::GdiplusStartup(&m_gdiplusToken, &gdiplusStartupInput, NULL);

	CSoundMgr::Get_Instance()->Initialize();

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Back.bmp", L"Back");

	CSceneMgr::Get_Instance()->Scene_Change(SC_EDIT);

	CAnimationTable::Get_Instance();
	CChipDataTable::Get_Instance();

	ITeamAgent::Add_TeamRelation(TEAM_ALPHA, TEAM_BETA, ERELATION_STATE::HOSTILE);
	ITeamAgent::Add_TeamRelation(TEAM_BETA, TEAM_ALPHA, ERELATION_STATE::HOSTILE);
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

	int iClientCX = (int)rcClient.right;
	int iClientCY = (int)rcClient.bottom;
	float fClientRatioX = ((float)iClientCY / (float)iClientCX);
	float fClientRatioY = ((float)iClientCX / (float)iClientCY);

	float fRatioX = ((float)WINCY / (float)WINCX);
	float fRatioY = ((float)WINCX / (float)WINCY);
	int iTargetCX = ROCKMAN_EXECX;
	int iTargetCY = ROCKMAN_EXECY;

	int iDstCX = (fClientRatioX >= fRatioX) ? iClientCX : (int)((float)iClientCY * fRatioY);
	int iDstCY = (fClientRatioY >= fRatioY) ? iClientCY : (int)((float)iClientCX * fRatioX);
	int iDstX = (iClientCY >= fRatioY) ? max(0, (iClientCX - iDstCX) / 2) : (iClientCX - iDstCX) / 2;
	int iDstY = (iClientCX >= fRatioX) ? max(0, (iClientCY - iDstCY) / 2) : (iClientCY - iDstCY) / 2;

	//Gdp::Graphics g(m_hDC);
	//Gdp::Graphics g(m_hDC);
	//g.DrawImage(
	//	pImage, -26, -30,	// 이미지 오프셋으로 대체
	//	Get_Frame(0).iFrameCur * 67, Get_Frame(0).iMotion * 55,
	//	67, 55,				// 이미지 조각 크기로 대체
	//	Gdp::UnitPixel
	//);

	
	// 종횡 유지
	StretchBlt(
		m_hDC,				// 복사 받을 DC(최종적으로 그림을 그릴 DC공간)
		iDstX, iDstY, iDstCX, iDstCY,
		hMemDC,				// 비트맵 이미지를 담고 있는 DC
		0, 0, iTargetCX, iTargetCY,
		SRCCOPY
	);
}

void CMainGame::Release()
{	

	CSoundMgr::Destroy_Instance();
	CBmpMgr::Destroy_Instance();
	CScrollMgr::Destroy_Instance();
	CKeyMgr::Destroy_Instance();
	CObjMgr::Destroy_Instance();
	CSceneMgr::Destroy_Instance();
	CAnimationTable::Destroy_Instance();
	CChipDataTable::Destroy_Instance();

	Gdp::GdiplusShutdown(m_gdiplusToken);
	ReleaseDC(g_hWnd, m_hDC);	
}
