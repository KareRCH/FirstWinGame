#include "Scene_NetBattle.h"

#include "ObjMgr.h"
#include "SceneMgr.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"
#include "KeyMgr.h"

#include "Manager/BattleMng.h"

#include "AbstractFactory.h"
#include <Manager/AnimationTable.h>




void CScene_NetBattle::Initialize()
{
	CBattleMng::Get_Instance();

	CBmpMgr::Get_Instance()->Insert_PNG(L"./RockmanEXE/Resource/battle/background/bg_dog_comp.png", L"BG_Dog_Comp");
	CBmpMgr::Get_Instance()->Insert_PNG(L"./RockmanEXE/Resource/battle/background/overlay.png", L"BG_Overlay");
	CBmpMgr::Get_Instance()->Insert_PNG(L"./RockmanEXE/Resource/battle/background/bg_back.png", L"BG_Back_1");

	CBmpMgr::Get_Instance()->Insert_PNG(L"./RockmanEXE/Resource/battle/background/bg_central_comp.png", L"BG_Central_Area");
	

	Add_Frame(L"BG_Central_Area");
	CAnimationTable::Get_Instance()->Load_AnimData(L"1", *Get_Frame());

	CBattleUI::Get_Instance();

	CScrollMgr::Get_Instance()->Set_LockSize(ROCKMAN_EXECX, ROCKMAN_EXECY);
	CScrollMgr::Get_Instance()->Set_Scroll(0.f, 0.f);
}

void CScene_NetBattle::Update(float fDeltaTime)
{
	CObjMgr::Get_Instance()->Update(fDeltaTime);

	CBattleUI::Get_Instance()->Update(fDeltaTime);

	CBattleMng::Get_Instance()->Update(fDeltaTime);

	Move_Frame();
}

void CScene_NetBattle::Late_Update(float fDeltaTime)
{
	CObjMgr::Get_Instance()->Late_Update(fDeltaTime);

	CBattleMng::Get_Instance()->Late_Update(fDeltaTime);

	CBattleUI::Get_Instance()->Late_Update(fDeltaTime);
}

void CScene_NetBattle::Render(HDC hDC)
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 3; ++j)
			CBmpMgr::Get_Instance()->Draw_PNG_Strip(hDC, Get_FrameKey(), Get_FrameData(),
				CVector3<float>(128.f * (float)j, 64 * (float)i, 0.f), CVector2<int>(1, 1), false);
	}

	float	iScrollX = CScrollMgr::Get_Instance()->Get_ScollX();
	float	iScrollY = CScrollMgr::Get_Instance()->Get_ScollY();

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
	CObjMgr::Get_Instance()->Release();
}
