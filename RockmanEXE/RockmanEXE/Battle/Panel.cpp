#include "Panel.h"

#include "ObjMgr.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"
#include "Manager/AnimationTable.h"

void CPanel::Initialize()
{
	m_vecBox = CVector3<float>(19.5f, 12.5f, 16.f);
	m_vecBoxPos = CVector3<float>(0.f, 0.f, -8.f);

#pragma region 이미지 추가
	TCHAR sText[100];
	const TCHAR* sDir = L"./RockmanEXE/Resource/battle/tiles/red_panel/";

#pragma region 레드 판넬
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"normal.png"), L"BG_Red_Panel_Normal");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"blank.png"), L"BG_Red_Panel_Blank");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"broken.png"), L"BG_Red_Panel_Broken");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"crack.png"), L"BG_Red_Panel_Crack");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"ice.png"), L"BG_Red_Panel_Ice");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"grass.png"), L"BG_Red_Panel_Grass");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"magma.png"), L"BG_Red_Panel_Magma");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"sand.png"), L"BG_Red_Panel_Sand");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"poison.png"), L"BG_Red_Panel_Poison");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"holy.png"), L"BG_Red_Panel_Holy");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"right.png"), L"BG_Red_Panel_Right");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"left.png"), L"BG_Red_Panel_Left");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"up.png"), L"BG_Red_Panel_Up");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"down.png"), L"BG_Red_Panel_Down");
#pragma endregion
#pragma region 블루 판넬
	sDir = L"./RockmanEXE/Resource/battle/tiles/blue_panel/";
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"normal.png"), L"BG_Blue_Panel_Normal");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"blank.png"), L"BG_Blue_Panel_Blank");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"broken.png"), L"BG_Blue_Panel_Broken");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"crack.png"), L"BG_Blue_Panel_Crack");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"ice.png"), L"BG_Blue_Panel_Ice");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"grass.png"), L"BG_Blue_Panel_Grass");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"magma.png"), L"BG_Blue_Panel_Magma");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"sand.png"), L"BG_Blue_Panel_Sand");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"poison.png"), L"BG_Blue_Panel_Poison");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"holy.png"), L"BG_Blue_Panel_Holy");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"right.png"), L"BG_Blue_Panel_Right");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"left.png"), L"BG_Blue_Panel_Left");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"up.png"), L"BG_Blue_Panel_Up");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"down.png"), L"BG_Blue_Panel_Down");
#pragma endregion
#pragma endregion

	CObjMgr::Get_Instance()->Add_Object(PANEL, this);
	
	if (m_eColor_Cur == PNL_RED)
	{
		switch (m_tState_Panel.eState)
		{
		case PNL_STATE::NORMAL:
			Set_FrameKey(0, L"BG_Red_Panel_Normal");
			break;
		case PNL_STATE::BLANK:
			Set_FrameKey(0, L"BG_Red_Panel_Blank");
			break;
		case PNL_STATE::CRACK:
			Set_FrameKey(0, L"BG_Red_Panel_Broken");
			break;
		case PNL_STATE::BROCKEN:
			Set_FrameKey(0, L"BG_Red_Panel_Crack");
			break;
		case PNL_STATE::ICE:
			Set_FrameKey(0, L"BG_Red_Panel_Ice");
			break;
		case PNL_STATE::GRASS:
			Set_FrameKey(0, L"BG_Red_Panel_Grass");
			break;
		case PNL_STATE::MAGMA:
			Set_FrameKey(0, L"BG_Red_Panel_Magma");
			break;
		case PNL_STATE::SAND:
			Set_FrameKey(0, L"BG_Red_Panel_Sand");
			break;
		case PNL_STATE::POISON:
			Set_FrameKey(0, L"BG_Red_Panel_Poison");
			break;
		case PNL_STATE::HOLY:
			Set_FrameKey(0, L"BG_Red_Panel_Holy");
			break;
		case PNL_STATE::RIGHT:
			Set_FrameKey(0, L"BG_Red_Panel_Right");
			break;
		case PNL_STATE::LEFT:
			Set_FrameKey(0, L"BG_Red_Panel_Left");
			break;
		case PNL_STATE::UP:
			Set_FrameKey(0, L"BG_Red_Panel_Up");
			break;
		case PNL_STATE::DOWN:
			Set_FrameKey(0, L"BG_Red_Panel_Down");
			break;
		}
	}
	else if (m_eColor_Cur == PNL_BLUE)
	{
		switch (m_tState_Panel.eState)
		{
		case PNL_STATE::NORMAL:
			Set_FrameKey(0, L"BG_Blue_Panel_Normal");
			break;
		case PNL_STATE::BLANK:
			Set_FrameKey(0, L"BG_Blue_Panel_Blank");
			break;
		case PNL_STATE::CRACK:
			Set_FrameKey(0, L"BG_Blue_Panel_Broken");
			break;
		case PNL_STATE::BROCKEN:
			Set_FrameKey(0, L"BG_Blue_Panel_Crack");
			break;
		case PNL_STATE::ICE:
			Set_FrameKey(0, L"BG_Blue_Panel_Ice");
			break;
		case PNL_STATE::GRASS:
			Set_FrameKey(0, L"BG_Blue_Panel_Grass");
			break;
		case PNL_STATE::MAGMA:
			Set_FrameKey(0, L"BG_Blue_Panel_Magma");
			break;
		case PNL_STATE::SAND:
			Set_FrameKey(0, L"BG_Blue_Panel_Sand");
			break;
		case PNL_STATE::POISON:
			Set_FrameKey(0, L"BG_Blue_Panel_Poison");
			break;
		case PNL_STATE::HOLY:
			Set_FrameKey(0, L"BG_Blue_Panel_Holy");
			break;
		case PNL_STATE::RIGHT:
			Set_FrameKey(0, L"BG_Blue_Panel_Right");
			break;
		case PNL_STATE::LEFT:
			Set_FrameKey(0, L"BG_Blue_Panel_Left");
			break;
		case PNL_STATE::UP:
			Set_FrameKey(0, L"BG_Blue_Panel_Up");
			break;
		case PNL_STATE::DOWN:
			Set_FrameKey(0, L"BG_Blue_Panel_Down");
			break;
		}
	}
	
	switch (m_eBrightness)
	{
	case BLIGHT:
		CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
		break;
	case MIDDLE:
		CAnimationTable::Get_Instance()->Load_AnimData(L"2", Get_FrameList()[0]);
		break;
	case DARK:
		CAnimationTable::Get_Instance()->Load_AnimData(L"3", Get_FrameList()[0]);
		break;
	}

	m_tState_Act.Set_State(ACT_STATE::IDLE);
}

int CPanel::Update(float fDeltaTime)
{
	State_Update(fDeltaTime);


	__super::Move_Frame();
	return 0;
}

void CPanel::Late_Update(float fDeltaTime)
{

}

void CPanel::Render(HDC hDC)
{
	CBmpMgr::Get_Instance()->Draw_PNG_Strip(hDC, Get_FrameKey(0), Get_Frame(0), m_vecPos, m_vecDirection);
}

void CPanel::Release()
{

}

void CPanel::Collide(CObj* _Dst)
{
}

void CPanel::State_Update(float fDeltaTime)
{

}
