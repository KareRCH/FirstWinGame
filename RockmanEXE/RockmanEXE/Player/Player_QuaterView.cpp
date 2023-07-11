#include "Player_QuaterView.h"

#include "KeyMgr.h"
#include "BmpMgr.h"
#include "Manager/AnimationTable.h"
#include <VecCollisionMgr.h>
#include <Overworld/Tile.h>
#include <Overworld/TileMgr.h>

void CPlayer_QuaterView::Initialize(void)
{
	CCharacter_QuaterView::Initialize_QuaterChr();

	// 현재 좌표 박스로 조정하기
	m_vecBox = CVector3<float>(4.f, 4.f, 16.f);
	m_vecBoxPos = CVector3<float>(0.f, 0.f, 0.f);
	m_vecPos.z += (m_vecBox.z - m_vecBoxPos.z);

	m_vecDirection = CVector2<int>(0, -1);
	m_vecSpeed = CVector3<float>(3.f, 1.5f, 0.f);

#pragma region 이미지
	TCHAR sText[100];
	const TCHAR* sDir = L"./RockmanEXE/Resource/overworld/player/rockman/";
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"stand_0.png"), L"OVW_Rockman_Stand_0");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"stand_1.png"), L"OVW_Rockman_Stand_1");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"stand_2.png"), L"OVW_Rockman_Stand_2");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"stand_3.png"), L"OVW_Rockman_Stand_3");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"stand_4.png"), L"OVW_Rockman_Stand_4");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"stand_5.png"), L"OVW_Rockman_Stand_5");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"stand_6.png"), L"OVW_Rockman_Stand_6");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"stand_7.png"), L"OVW_Rockman_Stand_7");

	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"run_0.png"), L"OVW_Rockman_Run_0");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"run_1.png"), L"OVW_Rockman_Run_1");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"run_2.png"), L"OVW_Rockman_Run_2");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"run_3.png"), L"OVW_Rockman_Run_3");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"run_4.png"), L"OVW_Rockman_Run_4");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"run_5.png"), L"OVW_Rockman_Run_5");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"run_6.png"), L"OVW_Rockman_Run_6");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"run_7.png"), L"OVW_Rockman_Run_7");

	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"get.png"), L"OVW_Rockman_Get");

	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"flash1_0.png"), L"OVW_Rockman_Flash1_0");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"flash1_1.png"), L"OVW_Rockman_Flash1_1");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"flash1_2.png"), L"OVW_Rockman_Flash1_2");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"flash1_3.png"), L"OVW_Rockman_Flash1_3");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"flash1_4.png"), L"OVW_Rockman_Flash1_4");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"flash1_5.png"), L"OVW_Rockman_Flash1_5");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"flash1_6.png"), L"OVW_Rockman_Flash1_6");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"flash1_7.png"), L"OVW_Rockman_Flash1_7");

	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"flash2_0.png"), L"OVW_Rockman_Flash1_0");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"flash2_1.png"), L"OVW_Rockman_Flash1_1");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"flash2_2.png"), L"OVW_Rockman_Flash1_2");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"flash2_3.png"), L"OVW_Rockman_Flash1_3");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"flash2_4.png"), L"OVW_Rockman_Flash1_4");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"flash2_5.png"), L"OVW_Rockman_Flash1_5");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"flash2_6.png"), L"OVW_Rockman_Flash1_6");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"flash2_7.png"), L"OVW_Rockman_Flash1_7");

	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"battle_0.png"), L"OVW_Rockman_Battle_0");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"battle_2.png"), L"OVW_Rockman_Battle_2");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"battle_4.png"), L"OVW_Rockman_Battle_4");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"battle_6.png"), L"OVW_Rockman_Battle_6");

	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"warped.png"), L"OVW_Rockman_Warped");

	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"defend_0.png"), L"OVW_Rockman_Defend_0");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"defend_2.png"), L"OVW_Rockman_Defend_2");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"defend_4.png"), L"OVW_Rockman_Defend_4");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"defend_6.png"), L"OVW_Rockman_Defend_6");

	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"burn.png"), L"OVW_Rockman_Burn");

	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"shoot_0.png"), L"OVW_Rockman_Shoot_0");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"shoot_2.png"), L"OVW_Rockman_Shoot_2");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"shoot_4.png"), L"OVW_Rockman_Shoot_4");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"shoot_6.png"), L"OVW_Rockman_Shoot_6");
#pragma endregion

	m_sDirection = L"4";
	m_sAnimName = L"OVW_Rockman_Stand_4";
	Set_FrameKey(0, L"OVW_Rockman_Stand_4");
	CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);

#pragma region 상태머신
	m_fnState.emplace(STATE::STAND, &CPlayer_QuaterView::Stand);
	m_fnState.emplace(STATE::RUN, &CPlayer_QuaterView::Run);
	m_fnState.emplace(STATE::WARP, &CPlayer_QuaterView::Warped);
	m_fnState.emplace(STATE::WARPED, &CPlayer_QuaterView::Warp);
	m_fnState.emplace(STATE::SHOOT, &CPlayer_QuaterView::Shoot);
	m_fnState.emplace(STATE::BATTLE, &CPlayer_QuaterView::Burn);
	m_fnState.emplace(STATE::DEFEND, &CPlayer_QuaterView::Defend);

	m_tState.Set_State(STATE::STAND);
#pragma endregion

}

int CPlayer_QuaterView::Update(float fDeltaTime)
{
	State_Update(fDeltaTime);

	CObj::Move_Frame();
	for_each(m_mapActionKey.begin(), m_mapActionKey.end(), CMapAction_Updator<ACTION_KEY>());	// 액션키 초기화

	return 0;
}

void CPlayer_QuaterView::Late_Update(float fDeltaTime)
{
	auto tVecPos = m_vecPos;
	Move();

	auto tileList = CVecCollisionMgr::Collision_Box_Tile(CTileMgr::Get_Instance()->Get_Tiles(), this);
	if (!tileList.empty())
	{
		bool bIsBlock = false;
		for (auto& item : tileList)
		{
			if (dynamic_cast<CTile*>(item)->Get_DrawID() == 1)
			{
				bIsBlock = true;
				break;
			}
		}

		if (bIsBlock)
		{
			m_vecPos = tVecPos;
			// 막혀있을 때 진행방향에 따라 이동 방향을 바꿔주는 기능
			// 오른, 왼
			if (m_vecMoveDir.x != 0 && m_vecMoveDir.y == 0)
			{
				m_vecMoveDir.y = 1;
				Move();

				auto tileList2 = CVecCollisionMgr::Collision_Box_Tile(CTileMgr::Get_Instance()->Get_Tiles(), this);
				bool bIsBlock2 = false;
				if (!tileList2.empty())
				{
					for (auto& item : tileList2)
					{
						if (dynamic_cast<CTile*>(item)->Get_DrawID() == 1)
						{
							bIsBlock2 = true;
							break;
						}
					}
				}
				m_vecPos = tVecPos;

				m_vecMoveDir.y = -1;
				Move();

				auto tileList3 = CVecCollisionMgr::Collision_Box_Tile(CTileMgr::Get_Instance()->Get_Tiles(), this);
				bool bIsBlock3 = false;
				if (!tileList3.empty())
				{
					for (auto& item : tileList3)
					{
						if (dynamic_cast<CTile*>(item)->Get_DrawID() == 1)
						{
							bIsBlock3 = true;
							break;
						}
					}
				}
				m_vecPos = tVecPos;

				if (bIsBlock2 && bIsBlock3)
				{
					m_vecMoveDir.x = 0;
					m_vecMoveDir.y = 0;
				}
				else
				{
					if (!bIsBlock2)
					{
						m_vecMoveDir.y = 1;
					}
					if (!bIsBlock3)
					{
						m_vecMoveDir.y = -1;
					}
				}
				Move();
			}
			// 위, 아래
			else if (m_vecMoveDir.y != 0 && m_vecMoveDir.x == 0)
			{
				m_vecMoveDir.x = 1;
				Move();

				auto tileList2 = CVecCollisionMgr::Collision_Box_Tile(CTileMgr::Get_Instance()->Get_Tiles(), this);
				bool bIsBlock2 = false;
				if (!tileList2.empty())
				{
					for (auto& item : tileList2)
					{
						if (dynamic_cast<CTile*>(item)->Get_DrawID() == 1)
						{
							bIsBlock2 = true;
							break;
						}
					}
				}
				m_vecPos = tVecPos;

				m_vecMoveDir.x = -1;
				Move();

				auto tileList3 = CVecCollisionMgr::Collision_Box_Tile(CTileMgr::Get_Instance()->Get_Tiles(), this);
				bool bIsBlock3 = false;
				if (!tileList3.empty())
				{
					for (auto& item : tileList3)
					{
						if (dynamic_cast<CTile*>(item)->Get_DrawID() == 1)
						{
							bIsBlock3 = true;
							break;
						}
					}
				}
				m_vecPos = tVecPos;

				if (bIsBlock2 && bIsBlock3)
				{
					m_vecMoveDir.x = 0;
					m_vecMoveDir.y = 0;
				}
				else
				{
					if (!bIsBlock2)
					{
						m_vecMoveDir.x = 1;
					}
					if (!bIsBlock3)
					{
						m_vecMoveDir.x = -1;
					}
				}
				Move();
			}
		}
	}
	else
		m_vecPos = tVecPos;
}

void CPlayer_QuaterView::Render(HDC hDC)
{
	CBmpMgr::Get_Instance()->Draw_PNG_Strip(hDC, Get_FrameKey(0), Get_Frame(0), m_vecPos, CVector2<int>(1, 1));
	//CBmpMgr::Get_Instance()->Draw_Text_Circle_Vec3(hDC, m_vecPos);

	/*WCHAR text[100];
	_stprintf_s(text, L"%f, %f", m_vecPos.x, m_vecPos.y);
	TextOutW(hDC, 10, 10, text, lstrlen(text));*/
}

void CPlayer_QuaterView::Release(void)
{

}

void CPlayer_QuaterView::Collide(CObj* _pDst)
{

}

bool CPlayer_QuaterView::Input_Move()
{
	bool bIsPressed = false;
	m_vecMoveDir = CVector2<int>::Zero();
	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_RIGHT))
	{
		m_vecDirection.x = m_vecMoveDir.x = 1;
		bIsPressed = true;
	}
	else if (CKeyMgr::Get_Instance()->Key_Pressing(VK_LEFT))
	{
		m_vecDirection.x = m_vecMoveDir.x = -1;
		bIsPressed = true;
	}

	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_UP))
	{
		m_vecDirection.y = m_vecMoveDir.y = 1;
		bIsPressed = true;
	}
	else if (CKeyMgr::Get_Instance()->Key_Pressing(VK_DOWN))
	{
		m_vecDirection.y = m_vecMoveDir.y = -1;
		bIsPressed = true;
	}

	// 오른
	if (m_vecMoveDir.x > 0)
	{
		// 위
		if (m_vecMoveDir.y > 0)
		{
			Set_DirectionStr(1);
		}
		// 아래
		else if (m_vecMoveDir.y < 0)
		{
			Set_DirectionStr(3);
		}
		else
		{
			Set_DirectionStr(2);
		}
	}
	// 왼
	else if (m_vecMoveDir.x < 0)
	{
		// 위
		if (m_vecMoveDir.y > 0)
		{
			Set_DirectionStr(7);
		}
		// 아래
		else if (m_vecMoveDir.y < 0)
		{
			Set_DirectionStr(5);
		}
		else
		{
			Set_DirectionStr(6);
		}
	}
	// 위 아래만
	else
	{
		// 위
		if (m_vecMoveDir.y > 0)
		{
			Set_DirectionStr(0);
		}
		// 아래
		else if (m_vecMoveDir.y < 0)
		{
			Set_DirectionStr(4);
		}
	}

	return bIsPressed;
}

void CPlayer_QuaterView::Move()
{
	m_vecPos.x += (float)m_vecMoveDir.x * m_vecSpeed.x;
	m_vecPos.y -= (float)m_vecMoveDir.y * m_vecSpeed.y * (float)((m_vecMoveDir.x == 0) ? 2 : 1);
}

void CPlayer_QuaterView::State_Update(float fDeltaTime)
{
	m_fnState[m_tState.eState](this, fDeltaTime);
}

void CPlayer_QuaterView::Stand(float fDeltaTime)
{
	// 진입부
	if (m_tState.IsState_Entered())
	{
		
	}

	// 실행부
	if (m_tState.Can_Update())
	{
		m_sAnimName = L"OVW_Rockman_Stand_" + m_sDirection;
		Set_FrameKey(0, m_sAnimName.c_str());
		CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0], true);

		if (Input_Move())
		{
			m_tState.Set_State(STATE::RUN);
		}
	}

	// 탈출부
	if (m_tState.IsState_Exit())
	{

	}
}

void CPlayer_QuaterView::Run(float fDeltaTime)
{
	// 진입부
	if (m_tState.IsState_Entered())
	{

	}

	// 실행부
	if (m_tState.Can_Update())
	{
		m_sAnimName = L"OVW_Rockman_Run_" + m_sDirection;
		Set_FrameKey(0, m_sAnimName.c_str());
		CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0], true);

		if (!Input_Move())
		{
			m_tState.Set_State(STATE::STAND);
		}
	}

	// 탈출부
	if (m_tState.IsState_Exit())
	{

	}
}

void CPlayer_QuaterView::Warped(float fDeltaTime)
{
	// 진입부
	if (m_tState.IsState_Entered())
	{
		Set_FrameKey(0, L"OVW_Rockman_Warped");
		CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
	}

	// 실행부
	if (m_tState.Can_Update())
	{

	}

	// 탈출부
	if (m_tState.IsState_Exit())
	{

	}
}

void CPlayer_QuaterView::Warp(float fDeltaTime)
{
	// 진입부
	if (m_tState.IsState_Entered())
	{
		Set_FrameKey(0, (L"OVW_Rockman_Flash2_" + m_sDirection).c_str());
		CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
	}

	// 실행부
	if (m_tState.Can_Update())
	{

	}

	// 탈출부
	if (m_tState.IsState_Exit())
	{

	}
}

void CPlayer_QuaterView::Shoot(float fDeltaTime)
{
	// 진입부
	if (m_tState.IsState_Entered())
	{
		Set_FrameKey(0, (L"OVW_Rockman_Shoot_" + m_sDirection).c_str());
		CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
	}

	// 실행부
	if (m_tState.Can_Update())
	{

	}

	// 탈출부
	if (m_tState.IsState_Exit())
	{

	}
}

void CPlayer_QuaterView::Burn(float fDeltaTime)
{
	// 진입부
	if (m_tState.IsState_Entered())
	{
		Set_FrameKey(0, L"OVW_Rockman_Burn");
		CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
	}

	// 실행부
	if (m_tState.Can_Update())
	{

	}

	// 탈출부
	if (m_tState.IsState_Exit())
	{

	}
}

void CPlayer_QuaterView::Defend(float fDeltaTime)
{
	// 진입부
	if (m_tState.IsState_Entered())
	{
		Set_FrameKey(0, (L"OVW_Rockman_Defend_" + m_sDirection).c_str());
		CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
	}

	// 실행부
	if (m_tState.Can_Update())
	{

	}

	// 탈출부
	if (m_tState.IsState_Exit())
	{

	}
}
