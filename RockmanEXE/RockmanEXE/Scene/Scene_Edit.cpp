#include "Scene_Edit.h"

#include "Overworld/TileMgr.h"
#include "KeyMgr.h"
#include "ScrollMgr.h"
#include <BmpMgr.h>
#include <Manager/AnimationTable.h>

CScene_Edit::CScene_Edit()
{
}

CScene_Edit::~CScene_Edit()
{
	Release();
}

void CScene_Edit::Initialize()
{
	wstring sText = L"./RockmanEXE/Resource/overworld/background/";
	CBmpMgr::Get_Instance()->Insert_Bmp((sText + L"central_area_1.bmp").c_str(), L"BMP_Central_Area");
	CBmpMgr::Get_Instance()->Insert_Bmp((sText + L"bg_central_area.bmp").c_str(), L"BMP_BG_Central_Area");

	CTileMgr::Get_Instance()->Initialize();
	CScrollMgr::Get_Instance()->Set_LockSize(1300, 900);

	Add_Frame(L"BMP_BG_Central_Area");
	CAnimationTable::Get_Instance()->Load_AnimData(L"1", *Get_Frame());
}

void CScene_Edit::Update(float fDeltaTime)
{
	Key_Input();

	CTileMgr::Get_Instance()->Update(fDeltaTime);

	Move_Frame();
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

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 3; ++j)
			CBmpMgr::Get_Instance()->Draw_BMP_Strip(hDC, Get_FrameKey(), Get_FrameData(),
				CVector3<float>(128.f * (float)j, 64 * (float)i, 0.f), false);
	}

	tFrame.iFrameWidth = 1300;
	tFrame.iFrameHeight = 900;
	CBmpMgr::Get_Instance()->Draw_BMP_Strip(hDC, L"BMP_Central_Area", tFrame, CVector3<float>(0.f, 0.f, 0.f));

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
