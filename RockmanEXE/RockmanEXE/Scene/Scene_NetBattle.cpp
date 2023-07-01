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

	BitBlt(hDC,	// ���� ���� DC(���������� �׸��� �׸� DC����)
		(int)iScrollX, (int)iScrollY, 1920, 1280,
		hGoundDC,			// ��Ʈ�� �̹����� ��� �ִ� DC
		0,					// ��Ʈ���� ����� ���� X,Y��ǥ
		0,
		SRCCOPY);

	// ������Ʈ �׸���
	CObjMgr::Get_Instance()->Render(hDC);
}

void CScene_NetBattle::Release()
{

}
