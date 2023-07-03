#include "Navi_Rockman.h"

#include "KeyMgr.h"
#include "ObjMgr.h"
#include "BmpMgr.h"
#include "CollisionMgr.h"
#include "ScrollMgr.h"
#include "Manager/AnimationTable.h"

#include "AbstractFactory.h"

CNavi_Rockman::CNavi_Rockman()
{

}

CNavi_Rockman::~CNavi_Rockman()
{

}

void CNavi_Rockman::Initialize(void)
{
	CCharacter_NetBattle::Initialize();

#pragma region 이미지 추가
	TCHAR sText[100];
	const TCHAR* sCharacterDir = L"./RockmanEXE/Resource/battle/navi/rockman_exe/";
	lstrcpy(sText, sCharacterDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"normal.png"), L"NBT_Rockman_EXE_Normal");
	lstrcpy(sText, sCharacterDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"cross_aqua.png"), L"NBT_Rockman_EXE_Aqua_Cross");
	lstrcpy(sText, sCharacterDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"cross_charge.png"), L"NBT_Rockman_EXE_Charge_Cross");
	lstrcpy(sText, sCharacterDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"cross_death.png"), L"NBT_Rockman_EXE_Death_Cross");
	lstrcpy(sText, sCharacterDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"cross_dust.png"), L"NBT_Rockman_EXE_Dust_Cross");
	lstrcpy(sText, sCharacterDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"cross_elec.png"), L"NBT_Rockman_EXE_Elec_Cross");
	lstrcpy(sText, sCharacterDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"cross_ground.png"), L"NBT_Rockman_EXE_Ground_Cross");
	lstrcpy(sText, sCharacterDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"cross_heat.png"), L"NBT_Rockman_EXE_Heat_Cross");
	lstrcpy(sText, sCharacterDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"cross_slash.png"), L"NBT_Rockman_EXE_Slash_Cross");
	lstrcpy(sText, sCharacterDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"cross_tengu.png"), L"NBT_Rockman_EXE_Tengu_Cross");
	lstrcpy(sText, sCharacterDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"cross_tomahawk.png"), L"NBT_Rockman_EXE_Tomahawk_Cross");
#pragma endregion

	Set_FrameKey(0, L"NBT_Rockman_EXE_Normal");
	CAnimationTable::Get_Instance()->Load_AnimData(L"Idle", Get_FrameList()[0]);

	m_tState.Set_State(STATE::IDLE);
}

int CNavi_Rockman::Update(float fDeltaTime)
{
	

	State_Update(fDeltaTime);

	CObj::Update_Rect();
	CObj::Move_Frame();
	return 0;
}

void CNavi_Rockman::Late_Update(float fDeltaTime)
{
	
}

void CNavi_Rockman::Render(HDC hDC)
{
	CBitMap* pBitMap = CBmpMgr::Get_Instance()->Find_CBitMap(Get_FrameKey(0));
	Gdp::Bitmap* pImage = pBitMap->Get_Image();
	Gdp::Graphics g(hDC);

	// 캔버스 크기 설정
	//Gdp::Rect rcCanvas = Gdp::Rect(
	//	Get_Frame(0).iFrameCur * 67,	// 오프셋
	//	Get_Frame(0).iMotion * 55,	// 오프셋
	//	67,
	//	55
	//);
	float fScrollX = CScrollMgr::Get_Instance()->Get_ScollX();
	float fScrollY = CScrollMgr::Get_Instance()->Get_ScollY();

	g.TranslateTransform(m_tInfo.fX + fScrollX, m_tInfo.fY + fScrollY);
	g.ScaleTransform((float)m_vecDirection.x, (float)m_vecDirection.y);

	g.DrawImage(
		pImage, -(Get_Frame(0).iOffsetX), -(Get_Frame(0).iOffsetY),	// 이미지 오프셋
		Get_Frame(0).iFrameCur * Get_Frame(0).iFrameWidth, Get_Frame(0).iMotion * Get_Frame(0).iFrameHeight,
		Get_Frame(0).iFrameWidth, Get_Frame(0).iFrameHeight,				// 이미지 조각 크기로 대체
		Gdp::UnitPixel
	);

	MoveToEx(hDC, (int)m_tInfo.fX, (int)m_tInfo.fY, NULL);
	Ellipse(hDC, (int)m_tInfo.fX - 3, (int)m_tInfo.fY - 3, (int)m_tInfo.fX + 3, (int)m_tInfo.fY + 3);

}

void CNavi_Rockman::Release(void)
{
}

void CNavi_Rockman::Collide(CObj* _pDst)
{
}

void CNavi_Rockman::State_Update(float fDeltaTime)
{
	switch (m_tState.eState)
	{
	case IDLE:
		if (m_tState.IsState_Entered())
		{
			CAnimationTable::Get_Instance()->Load_AnimData(L"Idle", Get_FrameList()[0]);
		}

		if (CKeyMgr::Get_Instance()->Key_Down(VK_RIGHT))
		{
			m_vecMoveDirection.x = 1;
		}
		else if (CKeyMgr::Get_Instance()->Key_Down(VK_LEFT))
		{
			m_vecMoveDirection.x = -1;
		}
		else if (CKeyMgr::Get_Instance()->Key_Down(VK_UP))
		{
			m_vecMoveDirection.y = 1;
		}
		else if (CKeyMgr::Get_Instance()->Key_Down(VK_DOWN))
		{
			m_vecMoveDirection.y = -1;
		}

		if (CKeyMgr::Get_Instance()->Key_Down(VK_RIGHT) || CKeyMgr::Get_Instance()->Key_Down(VK_LEFT)
			|| CKeyMgr::Get_Instance()->Key_Down(VK_UP) || CKeyMgr::Get_Instance()->Key_Down(VK_DOWN))
		{
			m_tState.Set_State(MOVE_READY);
		}
		break;

	case MOVE_READY:
		if (m_tState.IsState_Entered())
		{
			CAnimationTable::Get_Instance()->Load_AnimData(L"Move_Ready", Get_FrameList()[0]);
		}


		if (Get_Frame(0).iFrameCur >= Get_Frame(0).iFrameEnd)
		{
			m_tState.Set_State(MOVE_END);
		}
		break;

	case MOVE_END:
		if (m_tState.IsState_Entered())
		{
			CAnimationTable::Get_Instance()->Load_AnimData(L"Move_End", Get_FrameList()[0]);

			m_tInfo.fX += (float)PANEL_CROW * (float)m_vecMoveDirection.x;
			m_tInfo.fY -= (float)PANEL_CCOL * (float)m_vecMoveDirection.y;

			m_vecMoveDirection = CVector2<int>::Zero();
		}



		if (Get_Frame(0).iFrameCur >= Get_Frame(0).iFrameEnd)
		{
			m_tState.Set_State(IDLE);
		}
		break;
	}
}


