#include "Scene_NetBattle.h"

#include "ObjMgr.h"
#include "SceneMgr.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"
#include "KeyMgr.h"

#include "Manager/BattleMng.h"

#include "AbstractFactory.h"
#include "Battle/BattleUnit_Factory.h"
#include "Navi/Navi_Rockman.h"


void CScene_NetBattle::Initialize()
{
	CBattleMng::Get_Instance()->Initialize();

	CBmpMgr::Get_Instance()->Insert_PNG(L"./RockmanEXE/Resource/battle/background/bg_dog_comp.png", L"BG_Dog_Comp");

	CNavi_Rockman* pCreated = CBattleUnit_Factory<CNavi_Rockman>::Create({ 50.f, 50.f, 66.f, 54.f }, CVector2<int>(1, 1));
}

void CScene_NetBattle::Update(float fDeltaTime)
{
	CObjMgr::Get_Instance()->Update(fDeltaTime);

	CBattleMng::Get_Instance()->Update(fDeltaTime);
}

void CScene_NetBattle::Late_Update(float fDeltaTime)
{
	CObjMgr::Get_Instance()->Late_Update(fDeltaTime);

	CBattleMng::Get_Instance()->Late_Update(fDeltaTime);
}

void CScene_NetBattle::Render(HDC hDC)
{
	//HDC		hGoundDC = CBmpMgr::Get_Instance()->Find_Img(L"BG_Dog_Comp");
	CBitMap* pBitMap = CBmpMgr::Get_Instance()->Find_CBitMap(L"BG_Dog_Comp");
	Gdp::Bitmap* pImage = pBitMap->Get_Image();
	Gdp::Graphics g(hDC);

	// 캔버스 크기 설정
	//Gdp::Rect rcCanvas = Gdp::Rect(
	//	0,	// 오프셋
	//	0,	// 오프셋
	//	pImage->GetWidth(), 
	//	pImage->GetHeight() 
	//);

	g.DrawImage(
		pImage, 0, 0,
		0, 0,
		pImage->GetWidth(), pImage->GetHeight(),
		Gdp::UnitPixel
	);

	float	iScrollX = CScrollMgr::Get_Instance()->Get_ScollX();
	float	iScrollY = CScrollMgr::Get_Instance()->Get_ScollY();

	/*if (CKeyMgr::Get_Instance()->Key_Pressing(VK_RIGHT))
		CScrollMgr::Get_Instance()->Set_ScrollX(-5.f);
	else if (CKeyMgr::Get_Instance()->Key_Pressing(VK_LEFT))
		CScrollMgr::Get_Instance()->Set_ScrollX(5.f);

	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_DOWN))
		CScrollMgr::Get_Instance()->Set_ScrollY(-5.f);
	else if (CKeyMgr::Get_Instance()->Key_Pressing(VK_UP))
		CScrollMgr::Get_Instance()->Set_ScrollY(5.f);*/

	CScrollMgr::Get_Instance()->Scroll_Lock();

	iScrollX = CScrollMgr::Get_Instance()->Get_ScollX();
	iScrollY = CScrollMgr::Get_Instance()->Get_ScollY();

	//BitBlt(hDC,	// 복사 받을 DC(최종적으로 그림을 그릴 DC공간)
	//	(int)iScrollX, (int)iScrollY, 1920, 1280,
	//	hGoundDC,			// 비트맵 이미지를 담고 있는 DC
	//	0,					// 비트맵을 출력할 시작 X,Y좌표
	//	0,
	//	SRCCOPY);

	CBattleMng::Get_Instance()->Render(hDC);

	// 오브젝트 그리기
	CObjMgr::Get_Instance()->Render(hDC);

	
}

void CScene_NetBattle::Release()
{
	CBattleMng::Get_Instance()->Destroy_Instance();
}
