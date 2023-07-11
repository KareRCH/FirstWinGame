#include "Scene_Edit.h"

#include "Overworld/TileMgr.h"
#include "KeyMgr.h"
#include "ScrollMgr.h"
#include <BmpMgr.h>

CScene_Edit::CScene_Edit()
{
}

CScene_Edit::~CScene_Edit()
{
	Release();
}

void CScene_Edit::Initialize()
{
	TCHAR sText[100];
	const TCHAR* sDir = L"./RockmanEXE/Resource/overworld/background/";
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"central_area_1.png"), L"Central_Area");
	CBmpMgr::Get_Instance()->Insert_PNG(L"./RockmanEXE/Resource/battle/background/bg_dog_comp.png", L"BG_Dog_Comp");

	CTileMgr::Get_Instance()->Initialize();
	CScrollMgr::Get_Instance()->Set_LockSize(1300, 900);
}

void CScene_Edit::Update(float fDeltaTime)
{
	Key_Input();

	CTileMgr::Get_Instance()->Update(fDeltaTime);
}

void CScene_Edit::Late_Update(float fDeltaTime)
{
	CTileMgr::Get_Instance()->Late_Update(fDeltaTime);
}

void CScene_Edit::Render(HDC hDC)
{
	INFO tInfo = {};
	FRAME tFrame = {};

	CScrollMgr::Get_Instance()->Scroll_Lock();

	float	iScrollX = CScrollMgr::Get_Instance()->Get_ScollX();
	float	iScrollY = CScrollMgr::Get_Instance()->Get_ScollY();

	CBmpMgr::Get_Instance()->Draw_PNG(hDC, L"BG_Dog_Comp", tInfo, tFrame, false);

	tFrame.iFrameWidth = 1300;
	tFrame.iFrameHeight = 900;
	CBmpMgr::Get_Instance()->Draw_PNG(hDC, L"Central_Area", tInfo, tFrame);

	CTileMgr::Get_Instance()->Render(hDC);
}

void CScene_Edit::Release()
{
	CTileMgr::Get_Instance()->Destroy_Instance();
}

void CScene_Edit::Key_Input(void)
{
	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_LEFT))
		CScrollMgr::Get_Instance()->Set_ScrollX(-5.f);

	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_RIGHT))
		CScrollMgr::Get_Instance()->Set_ScrollX(5.f);

	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_UP))
		CScrollMgr::Get_Instance()->Set_ScrollY(-5.f);

	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_DOWN))
		CScrollMgr::Get_Instance()->Set_ScrollY(5.f);

	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_LBUTTON))
	{
		POINT	pt;
		GetCursorPos(&pt);
		ScreenToClient(g_hWnd, &pt);

		CTileMgr::Get_Instance()->Picking_Tile(pt, 1, 0);
	}

	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_RBUTTON))
	{
		POINT	pt;
		GetCursorPos(&pt);
		ScreenToClient(g_hWnd, &pt);

		CTileMgr::Get_Instance()->Picking_Tile(pt, 0, 0);
	}

	if (CKeyMgr::Get_Instance()->Key_Down('R'))
	{
		CTileMgr::Get_Instance()->Reset();
	}

	if (CKeyMgr::Get_Instance()->Key_Down('S'))
		CTileMgr::Get_Instance()->Save_Tile();

	if (CKeyMgr::Get_Instance()->Key_Down('B'))
		CTileMgr::Get_Instance()->Load_Tile();
}
