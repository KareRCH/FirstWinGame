#include "Battle/BattleUI.h"

#include "BmpMgr.h"
#include "ScrollMgr.h"
#include "KeyMgr.h"

#include "Manager/BattleMng.h"

CBattleUI* CBattleUI::m_pInstance = nullptr;

void CBattleUI::Initialize()
{
	m_tInfo.fX = -160.f;
	m_tInfo.fY = 0.f;

	TCHAR sText[100];
	const TCHAR* sDir = L"./RockmanEXE/Resource/battle/ui/";
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"ui_enemy_info.png"), L"NBT_UI_Enemy_Info");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"ui_hp_bg.png"), L"NBT_UI_Hp");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"ui_pet.png"), L"NBT_UI_Pet");

	m_tState.Set_State(CLOSED);
	m_tState_Cross.Set_State(CROSS_CLOSED);
}

void CBattleUI::Release()
{
}

void CBattleUI::Update(float fDeltaTime)
{
	State_Update(fDeltaTime);
}

void CBattleUI::Late_Update(float fDeltaTime)
{
}

void CBattleUI::Render(HDC hDC)
{
	FRAME tFrame = {};
	INFO tInfo = m_tInfo;


	tFrame.iFrameWidth = 120; tFrame.iFrameHeight = 164;
	CBmpMgr::Get_Instance()->Draw_PNG(hDC, L"NBT_UI_Pet", tInfo, tFrame, false);

	
	tInfo.fX = max(m_tInfo.fX + 124.f, 4.f); tInfo.fY = 4.f;
	tFrame.iFrameWidth = 64; tFrame.iFrameHeight = 11;
	CBmpMgr::Get_Instance()->Draw_PNG(hDC, L"NBT_UI_Hp", tInfo, tFrame, false);
	
	if (m_bInitBattle)
	{
		tInfo.fX = (float)ROCKMAN_EXECX - 40.f; tInfo.fY = 16.f;
		tFrame.iFrameWidth = 40; tFrame.iFrameHeight = 14;
		CBmpMgr::Get_Instance()->Draw_PNG(hDC, L"NBT_UI_Enemy_Info", tInfo, tFrame, false);
	}

	wstring swString = L"UI_Chip_Icon_";
	
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (m_LoadedChip_List.size() < i * 5 + j + 1)
				break;

			tInfo.fX = m_tInfo.fX + 9.f + (float)j * 16.f; 
			tInfo.fY = m_tInfo.fY + 109.f + (float)i * 23.f;
			tFrame.iFrameWidth = 14; tFrame.iFrameHeight = 14;
			wstringstream ssInt;
			ssInt << m_LoadedChip_List[i * 5 + j].iID + 1;
			wstring swString2 = (swString + ssInt.str());

			CBmpMgr::Get_Instance()->Draw_PNG(hDC, swString2.c_str(), tInfo, tFrame, 1, 1, false);
		}
	}
}

void CBattleUI::State_Update(float fDeltaTime)
{
	switch (m_tState.eState)
	{
	case STATE::OPENING:
		if (m_tState.IsState_Entered())
		{

		}

		m_tInfo.fX += 20.f;
		if (0.f < m_tInfo.fX)
		{
			m_tInfo.fX = 0.f;
			m_tState.Set_State(OPENED);
		}

		if (m_tState.IsState_Exit())
		{
			
		}
		break;
	case STATE::OPENED:
		if (m_tState.IsState_Entered())
		{

		}

		if (CKeyMgr::Get_Instance()->Key_Down('E'))
		{
			m_tState.Set_State(CLOSING);
		}

		if (m_tState.IsState_Exit())
		{
			
		}
		break;
	case STATE::CLOSING:
		if (m_tState.IsState_Entered())
		{
			m_bInitBattle = false;
		}

		m_tInfo.fX -= 20.f;
		if (-160.f > m_tInfo.fX)
		{
			m_tInfo.fX = -160.f;
			m_tState.Set_State(CLOSED);
		}


		if (m_tState.IsState_Exit())
		{

		}
		break;
	case STATE::CLOSED:
		if (m_tState.IsState_Entered())
		{
			
		}

		if (CKeyMgr::Get_Instance()->Key_Down('E'))
		{
			m_tState.Set_State(OPENING);
		}

		if (m_tState.IsState_Exit())
		{

		}
		break;
	}


	switch (m_tState_Cross.eState)
	{
	case CROSS_OPENING:

		break;
	case CROSS_CLOSING:

		break;
	case CROSS_OPENED:
		// 크로스 UI 출력중입니다.

		break;
	case CROSS_CLOSED:

		break;
	}
}
