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
#include <Overworld/TileMgr.h>
#include <Manager/AnimationTable.h>
#include "Player/PlayerData.h"
#include <Overworld/Seller_QuaterView.h>

void CScene_Central_Area::Initialize()
{
	wstring sText = L"./RockmanEXE/Resource/overworld/background/";
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"central_area_1.png").c_str(), L"Central_Area");
	CBmpMgr::Get_Instance()->Insert_PNG(L"./RockmanEXE/Resource/battle/background/bg_central_comp.png", L"BG_Central_Area");
	CBmpMgr::Get_Instance()->Insert_Bmp((sText + L"central_area_1.bmp").c_str(), L"BMP_Central_Area");
	CBmpMgr::Get_Instance()->Insert_Bmp((sText + L"bg_central_area.bmp").c_str(), L"BMP_BG_Central_Area");

	Add_Frame(L"BMP_BG_Central_Area");
	CAnimationTable::Get_Instance()->Load_AnimData(L"1", *Get_Frame());

	CSoundMgr::Get_Instance()->Play_BGM(const_cast<TCHAR*>(L"loop_overworld.mp3"), 1.f);

	CPlayer_QuaterView* pPlayer = 
		CQuaterViewUnit_Factory<CPlayer_QuaterView>::Create(CPlayerData::Get_Instance()->Get_PlayerPos(), 
															CPlayerData::Get_Instance()->Get_PlayerDir());
	CQuaterViewUnit_Factory<CSeller_QuaterView>::Create(CVector3<float>(1033.f, 291.f, 0.f), CVector2<int>(-1, -1));

	CScrollMgr::Get_Instance()->Set_Scroll(0.f, 0.f);
	CScrollMgr::Get_Instance()->Set_LockSize(1300, 900);
	CScrollMgr::Get_Instance()->Set_LockOn_Obj(pPlayer);

	CTileMgr::Get_Instance()->Initialize();
	CTileMgr::Get_Instance()->Load_Tile();

	m_vEncountData.push_back(CEncountDataTable::Get_Instance()->Get_Data(0));
	m_vEncountData.push_back(CEncountDataTable::Get_Instance()->Get_Data(1));
	m_vEncountData.push_back(CEncountDataTable::Get_Instance()->Get_Data(2));
	m_vEncountData.push_back(CEncountDataTable::Get_Instance()->Get_Data(3));
}

void CScene_Central_Area::Update(float fDeltaTime)
{
	CTileMgr::Get_Instance()->Update(fDeltaTime);

	CObjMgr::Get_Instance()->Update(fDeltaTime);

	if (CKeyMgr::Get_Instance()->Key_Down(VK_SPACE))
	{
		CPlayerData::Get_Instance()->Set_EncountData(Get_RandomEncount());

		CSoundMgr::Get_Instance()->Play_Sound(const_cast<TCHAR*>(L"pre_battle.wav"), SYSTEM_EFFECT, 1.f);
		for(int i = 0; i < OBJID::OBJID_END; ++i)
			CObjMgr::Get_Instance()->Delete_ID((OBJID)i);
		CSceneMgr::Get_Instance()->Scene_Change(SC_STAGE);
	}

	Move_Frame();
}

void CScene_Central_Area::Late_Update(float fDeltaTime)
{
	CTileMgr::Get_Instance()->Late_Update(fDeltaTime);

	CObjMgr::Get_Instance()->Late_Update(fDeltaTime);
}

void CScene_Central_Area::Render(HDC hDC)
{
	INFO tInfo = {};
	FRAME tFrame = {};

	CScrollMgr::Get_Instance()->Scroll_Lock();

	float	iScrollX = CScrollMgr::Get_Instance()->Get_ScollX();
	float	iScrollY = CScrollMgr::Get_Instance()->Get_ScollY();

	for (int i = 0; i < 4; ++i)
	{
		for(int j = 0; j < 3; ++j)
			CBmpMgr::Get_Instance()->Draw_BMP_Strip(hDC, Get_FrameKey(), Get_FrameData(),
				CVector3<float>(128.f * (float)j, 64 * (float)i, 0.f), false);
	}
	

	tFrame.iFrameWidth = 1300;
	tFrame.iFrameHeight = 900;
	CBmpMgr::Get_Instance()->Draw_BMP_Strip(hDC, L"BMP_Central_Area", tFrame, CVector3<float>(0.f, 0.f, 0.f));

	//WCHAR text[100];
	////_stprintf_s(text, L"%i", (int)m_tState_Act.eState);
	//_stprintf_s(text, L"%f, %f", iScrollX, iScrollY);
	//TextOutW(hDC, 10, 10, text, lstrlen(text));
	
	CTileMgr::Get_Instance()->Render(hDC);

	// 오브젝트 그리기
	CObjMgr::Get_Instance()->Render(hDC);

	

	WCHAR text[40];
	SetTextColor(hDC, DWORD(0x00222222));
	_stprintf_s(text, L"%s", L"센트랄 에리어 1");
	TextOutW(hDC, ROCKMAN_EXECX - ((int)lstrlen(text)) * 16 + 2 + 8, ROCKMAN_EXECY - 16+2, text, lstrlen(text));

	SetTextColor(hDC, DWORD(0x00BBBBBB));

	_stprintf_s(text, L"%s", L"센트랄 에리어 1");
	TextOutW(hDC, ROCKMAN_EXECX - ((int)lstrlen(text)) * 16 + 8, ROCKMAN_EXECY - 16, text, lstrlen(text));
}

void CScene_Central_Area::Release()
{
	CTileMgr::Get_Instance()->Destroy_Instance();
}