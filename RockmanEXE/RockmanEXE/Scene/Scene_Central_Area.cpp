#include "Scene_Central_Area.h"

#include "ObjMgr.h"
#include "SceneMgr.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"
#include "KeyMgr.h"

#include "AbstractFactory.h"
#include <SoundMgr.h>
#include "Overworld/QuaterViewUnit_Factory.h"

#include "Player/Player_QuaterView.h"

void CScene_Central_Area::Initialize()
{
	TCHAR sText[100];
	const TCHAR* sDir = L"./RockmanEXE/Resource/overworld/background/";
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"central_area_1.png"), L"Central_Area");
	CBmpMgr::Get_Instance()->Insert_PNG(L"./RockmanEXE/Resource/battle/background/bg_dog_comp.png", L"BG_Dog_Comp");

	CSoundMgr::Get_Instance()->Play_BGM(const_cast<TCHAR*>(L"loop_overworld.mp3"), 1.f);

	CPlayer_QuaterView* pPlayer = CQuaterViewUnit_Factory<CPlayer_QuaterView>::Create(CVector3<float>(100.f, 100.f, 0.f), CVector2<int>(0, -1));

	CScrollMgr::Get_Instance()->Set_Scroll(0.f, 0.f);
	CScrollMgr::Get_Instance()->Set_LockSize(1300.f, 900.f);
	CScrollMgr::Get_Instance()->Set_LockOn_Obj(pPlayer);
}

void CScene_Central_Area::Update(float fDeltaTime)
{
	CObjMgr::Get_Instance()->Update(fDeltaTime);

	if (CKeyMgr::Get_Instance()->Key_Down(VK_SPACE))
	{
		CSoundMgr::Get_Instance()->Play_Sound(const_cast<TCHAR*>(L"pre_battle.wav"), SYSTEM_EFFECT, 1.f);
		CSceneMgr::Get_Instance()->Scene_Change(SC_STAGE);
	}
}

void CScene_Central_Area::Late_Update(float fDeltaTime)
{
	CObjMgr::Get_Instance()->Late_Update(fDeltaTime);
}

void CScene_Central_Area::Render(HDC hDC)
{
	INFO tInfo = {};
	FRAME tFrame = {};

	/*if (CKeyMgr::Get_Instance()->Key_Pressing(VK_RIGHT))
		CScrollMgr::Get_Instance()->Set_ScrollX(-5.f);
	else if (CKeyMgr::Get_Instance()->Key_Pressing(VK_LEFT))
		CScrollMgr::Get_Instance()->Set_ScrollX(5.f);

	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_DOWN))
		CScrollMgr::Get_Instance()->Set_ScrollY(-5.f);
	else if (CKeyMgr::Get_Instance()->Key_Pressing(VK_UP))
		CScrollMgr::Get_Instance()->Set_ScrollY(5.f);*/

	CScrollMgr::Get_Instance()->Scroll_Lock();

	float	iScrollX = CScrollMgr::Get_Instance()->Get_ScollX();
	float	iScrollY = CScrollMgr::Get_Instance()->Get_ScollY();

	CBmpMgr::Get_Instance()->Draw_PNG(hDC, L"BG_Dog_Comp", tInfo, tFrame, false);

	tFrame.iFrameWidth = 1300;
	tFrame.iFrameHeight = 900;
	CBmpMgr::Get_Instance()->Draw_PNG(hDC, L"Central_Area", tInfo, tFrame);

	WCHAR text[100];
	//_stprintf_s(text, L"%i", (int)m_tState_Act.eState);
	_stprintf_s(text, L"%f, %f", iScrollX, iScrollY);
	TextOutW(hDC, 10, 10, text, lstrlen(text));
	

	// 오브젝트 그리기
	CObjMgr::Get_Instance()->Render(hDC);

	
}

void CScene_Central_Area::Release()
{
}