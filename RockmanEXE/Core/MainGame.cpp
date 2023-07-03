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
#include "Manager/AnimationTable.h"
#include "Manager/ChipDataTable.h"

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

	// Gdiplus �ʱ�ȭ
	//ULONG_PTR gdiplusToken;
	Gdp::GdiplusStartupInput gdiplusStartupInput;
	gdiplusStartupInput.GdiplusVersion = 1;
	gdiplusStartupInput.SuppressBackgroundThread = FALSE;
	Gdp::GdiplusStartup(&m_gdiplusToken, &gdiplusStartupInput, NULL);

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Back.bmp", L"Back");

	CSceneMgr::Get_Instance()->Scene_Change(SC_STAGE);

	CAnimationTable::Get_Instance();
	CChipDataTable::Get_Instance();

#ifdef _DEBUG
#if _TEST_CONSOLE
	// ����׿� �ܼ�â
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

	// Ÿ��Ʋ�� fps ���
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
	//	m_hDC,				// ���� ���� DC(���������� �׸��� �׸� DC����)
	//	0, 0, WINCX, WINCY,
	//	hMemDC,				// ��Ʈ�� �̹����� ��� �ִ� DC
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
	//	pImage, -26, -30,	// �̹��� ���������� ��ü
	//	Get_Frame(0).iFrameCur * 67, Get_Frame(0).iMotion * 55,
	//	67, 55,				// �̹��� ���� ũ��� ��ü
	//	Gdp::UnitPixel
	//);

	
	// ��Ⱦ ����
	StretchBlt(
		m_hDC,				// ���� ���� DC(���������� �׸��� �׸� DC����)
		iDstX, iDstY, iDstCX, iDstCY,
		hMemDC,				// ��Ʈ�� �̹����� ��� �ִ� DC
		0, 0, iTargetCX, iTargetCY,
		SRCCOPY
	);
}

void CMainGame::Release()
{	
#ifdef _DEBUG
#if _TEST_CONSOLE
	// �ܼ� ��� ����
	FreeConsole();
#endif
#endif // _DEBUG

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
