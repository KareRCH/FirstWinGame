#include "Scene_NetBattle.h"

#include "ObjMgr.h"
#include "SceneMgr.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"
#include "KeyMgr.h"

#include "Manager/BattleMng.h"

#include "AbstractFactory.h"



void CScene_NetBattle::Initialize()
{
	CBattleMng::Get_Instance();

	CBmpMgr::Get_Instance()->Insert_PNG(L"./RockmanEXE/Resource/battle/background/bg_dog_comp.png", L"BG_Dog_Comp");
	CBmpMgr::Get_Instance()->Insert_PNG(L"./RockmanEXE/Resource/battle/background/overlay.png", L"BG_Overlay");
	CBmpMgr::Get_Instance()->Insert_PNG(L"./RockmanEXE/Resource/battle/background/bg_back.png", L"BG_Back_1");

	CBattleUI::Get_Instance();
}

void CScene_NetBattle::Update(float fDeltaTime)
{
	CObjMgr::Get_Instance()->Update(fDeltaTime);

	CBattleMng::Get_Instance()->Update(fDeltaTime);

	CBattleUI::Get_Instance()->Update(fDeltaTime);
}

void CScene_NetBattle::Late_Update(float fDeltaTime)
{
	CObjMgr::Get_Instance()->Late_Update(fDeltaTime);

	CBattleMng::Get_Instance()->Late_Update(fDeltaTime);

	CBattleUI::Get_Instance()->Late_Update(fDeltaTime);
}

void CScene_NetBattle::Render(HDC hDC)
{
	//HDC		hGoundDC = CBmpMgr::Get_Instance()->Find_Img(L"BG_Dog_Comp");
	CBitMap* pBitMap = CBmpMgr::Get_Instance()->Find_CBitMap(L"BG_Back_1");
	Gdp::Bitmap* pImage = pBitMap->Get_Image();
	Gdp::Graphics g(hDC);

	// ĵ���� ũ�� ����
	//Gdp::Rect rcCanvas = Gdp::Rect(
	//	0,	// ������
	//	0,	// ������
	//	pImage->GetWidth(), 
	//	pImage->GetHeight() 
	//);

	g.DrawImage(
		pImage, 0, 0,
		0, 0,
		ROCKMAN_EXECX, ROCKMAN_EXECY,
		Gdp::UnitPixel
	);

	pBitMap = CBmpMgr::Get_Instance()->Find_CBitMap(L"BG_Overlay");
	pImage = pBitMap->Get_Image();

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

	//BitBlt(hDC,	// ���� ���� DC(���������� �׸��� �׸� DC����)
	//	(int)iScrollX, (int)iScrollY, 1920, 1280,
	//	hGoundDC,			// ��Ʈ�� �̹����� ��� �ִ� DC
	//	0,					// ��Ʈ���� ����� ���� X,Y��ǥ
	//	0,
	//	SRCCOPY);

	// �ǳ��̱��ѵ�. ���߿� �ٲ���� ��
	CBattleMng::Get_Instance()->Render(hDC);

	// ������Ʈ �׸���
	CObjMgr::Get_Instance()->Render(hDC);

	// UI �׸���
	CBattleUI::Get_Instance()->Render(hDC);
}

void CScene_NetBattle::Release()
{
	CBattleMng::Get_Instance()->Destroy_Instance();
	CBattleUI::Get_Instance()->Destroy_Instance();
}
