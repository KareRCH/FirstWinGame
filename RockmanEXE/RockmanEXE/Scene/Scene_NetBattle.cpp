#include "Scene_NetBattle.h"

#include "ObjMgr.h"
#include "SceneMgr.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"
#include "KeyMgr.h"

#include "AbstractFactory.h"

void CScene_NetBattle::Initialize()
{

}

void CScene_NetBattle::Update(float fDeltaTime)
{
	CObjMgr::Get_Instance()->Update(fDeltaTime);

	CBmpMgr::Get_Instance()->Insert_Bmp(L"./RockmanEXE//Ground.bmp", L"Ground");
}

void CScene_NetBattle::Late_Update(float fDeltaTime)
{
	CObjMgr::Get_Instance()->Late_Update(fDeltaTime);
}

void CScene_NetBattle::Render(HDC hDC)
{
	HDC		hGoundDC = CBmpMgr::Get_Instance()->Find_Img(L"Ground");

	float	iScrollX = CScrollMgr::Get_Instance()->Get_ScollX();
	float	iScrollY = CScrollMgr::Get_Instance()->Get_ScollY();

	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_RIGHT))
		CScrollMgr::Get_Instance()->Set_ScrollX(-5.f);
	else if (CKeyMgr::Get_Instance()->Key_Pressing(VK_LEFT))
		CScrollMgr::Get_Instance()->Set_ScrollX(5.f);

	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_DOWN))
		CScrollMgr::Get_Instance()->Set_ScrollY(-5.f);
	else if (CKeyMgr::Get_Instance()->Key_Pressing(VK_UP))
		CScrollMgr::Get_Instance()->Set_ScrollY(5.f);

	CScrollMgr::Get_Instance()->Scroll_Lock();

	iScrollX = CScrollMgr::Get_Instance()->Get_ScollX();
	iScrollY = CScrollMgr::Get_Instance()->Get_ScollY();

	BitBlt(hDC,	// 복사 받을 DC(최종적으로 그림을 그릴 DC공간)
		(int)iScrollX, (int)iScrollY, 1920, 1280,
		hGoundDC,			// 비트맵 이미지를 담고 있는 DC
		0,					// 비트맵을 출력할 시작 X,Y좌표
		0,
		SRCCOPY);

	// 오브젝트 그리기
	CObjMgr::Get_Instance()->Render(hDC);
}

void CScene_NetBattle::Release()
{

}
