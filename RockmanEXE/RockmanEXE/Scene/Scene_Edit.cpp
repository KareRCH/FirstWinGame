#include "Scene_Edit.h"

#include "Overworld/TileMgr.h"
#include "KeyMgr.h"
#include "ScrollMgr.h"

CScene_Edit::CScene_Edit()
{
}

CScene_Edit::~CScene_Edit()
{
	Release();
}

void CScene_Edit::Initialize()
{
	CTileMgr::Get_Instance()->Initialize();
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
	CTileMgr::Get_Instance()->Render(hDC);
}

void CScene_Edit::Release()
{
	CTileMgr::Get_Instance()->Destroy_Instance();
}

void CScene_Edit::Key_Input(void)
{
	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_LEFT))
		CScrollMgr::Get_Instance()->Set_ScrollX(5.f);

	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_RIGHT))
		CScrollMgr::Get_Instance()->Set_ScrollX(-5.f);

	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_UP))
		CScrollMgr::Get_Instance()->Set_ScrollY(5.f);

	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_DOWN))
		CScrollMgr::Get_Instance()->Set_ScrollY(-5.f);

	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_LBUTTON))
	{
		POINT	pt;
		GetCursorPos(&pt);
		ScreenToClient(g_hWnd, &pt);

		pt.x -= (int)CScrollMgr::Get_Instance()->Get_ScollX();
		pt.y -= (int)CScrollMgr::Get_Instance()->Get_ScollY();

		CTileMgr::Get_Instance()->Picking_Tile(pt, 1, 0);
	}

	if (CKeyMgr::Get_Instance()->Key_Down('S'))
		CTileMgr::Get_Instance()->Save_Tile();

	if (CKeyMgr::Get_Instance()->Key_Down('B'))
		CTileMgr::Get_Instance()->Load_Tile();


}
