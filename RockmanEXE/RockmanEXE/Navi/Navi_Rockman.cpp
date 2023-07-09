#include "Navi_Rockman.h"

#include "KeyMgr.h"
#include "ObjMgr.h"
#include "BmpMgr.h"
#include "CollisionMgr.h"
#include "ScrollMgr.h"
#include <SoundMgr.h>
#include <VecCollisionMgr.h>

#include "Manager/AnimationTable.h"
#include "Battle/BattleSpell_Factory.h"
#include "Spell/Spell_Buster.h"
#include "Spell/Spell_Cannon.h"

#include "AbstractFactory.h"


CNavi_Rockman::CNavi_Rockman()
{

}

CNavi_Rockman::~CNavi_Rockman()
{

}

void CNavi_Rockman::Initialize(void)
{
	CNavi::Initialize_Navi();

	// 현재 좌표 박스로 조정하기
	m_vecBox = CVector3<float>(15.f, 10.f, 16.f);
	m_vecBoxPos = CVector3<float>(0.f, 0.f, 0.f);
	m_vecPos.z += (m_vecBox.z - m_vecBoxPos.z);

	m_iHP = GAUGE<int>(100, true);

#pragma region 이미지 추가
	TCHAR sText[100];
	const TCHAR* sCharacterDir = L"./RockmanEXE/Resource/battle/navi/rockman_exe/normal/";
	lstrcpy(sText, sCharacterDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"idle.png"), L"NBT_Rockman_EXE_Normal_Idle");
	lstrcpy(sText, sCharacterDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"hit.png"), L"NBT_Rockman_EXE_Normal_Hit");
	lstrcpy(sText, sCharacterDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"paralyze.png"), L"NBT_Rockman_EXE_Normal_Paralyze");
	lstrcpy(sText, sCharacterDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"move_end.png"), L"NBT_Rockman_EXE_Normal_Move_End");
	lstrcpy(sText, sCharacterDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"move_ready.png"), L"NBT_Rockman_EXE_Normal_Move_Ready");
	lstrcpy(sText, sCharacterDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"sword.png"), L"NBT_Rockman_EXE_Normal_Sword");
	lstrcpy(sText, sCharacterDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"throw.png"), L"NBT_Rockman_EXE_Normal_Throw");
	lstrcpy(sText, sCharacterDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"crouch.png"), L"NBT_Rockman_EXE_Normal_Crouch");
	lstrcpy(sText, sCharacterDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"shoot_cannon.png"), L"NBT_Rockman_EXE_Normal_Shoot_Cannon");
	lstrcpy(sText, sCharacterDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"shoot_buster.png"), L"NBT_Rockman_EXE_Normal_Shoot_Buster");
	lstrcpy(sText, sCharacterDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"shoot_duration.png"), L"NBT_Rockman_EXE_Normal_Shoot_Duration");
	lstrcpy(sText, sCharacterDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"throw_disk.png"), L"NBT_Rockman_EXE_Normal_Throw_Disk");
	lstrcpy(sText, sCharacterDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"shoot_1.png"), L"NBT_Rockman_EXE_Normal_Shoot_1");
	lstrcpy(sText, sCharacterDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"ready_crouch_1.png"), L"NBT_Rockman_EXE_Normal_Ready_Crouch_1");
	lstrcpy(sText, sCharacterDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"shoot_2.png"), L"NBT_Rockman_EXE_Normal_Shoot_2");
	lstrcpy(sText, sCharacterDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"ready_crouch_2.png"), L"NBT_Rockman_EXE_Normal_Ready_Crouch_2");
	lstrcpy(sText, sCharacterDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"ready_swing.png"), L"NBT_Rockman_EXE_Normal_Ready_Swing");
	lstrcpy(sText, sCharacterDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"swing.png"), L"NBT_Rockman_EXE_Normal_Swing");
	lstrcpy(sText, sCharacterDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"crouch.png"), L"NBT_Rockman_EXE_Normal_Crouch");
	/*lstrcpy(sText, sCharacterDir);
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
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"cross_tomahawk.png"), L"NBT_Rockman_EXE_Tomahawk_Cross");*/
#pragma endregion

	Set_FrameKey(0, L"NBT_Rockman_EXE_Normal_Idle");
	CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);

	m_tState.Set_State(STATE::IDLE);

	m_fInvicibleTime.ReAdjust(1.5f);
}

int CNavi_Rockman::Update(float fDeltaTime)
{
	State_Update(fDeltaTime);

	CObj::Move_Frame();

	return 0;
}

void CNavi_Rockman::Late_Update(float fDeltaTime)
{
	auto vecTemp = m_vecPos;
	Gravity(fDeltaTime);		// 중력
	Move(fDeltaTime);			// 이동에 대한 처리를 수행하기
	// 충돌 처리
	
	// 다음 프레임의 판넬처리를 만든다.
	auto tPanels = CVecCollisionMgr::Collision_Box(CObjMgr::Get_Instance()->Get_ObjList(PANEL), this);
	
	if (!tPanels.empty())
	{
		CPanel* tPanel = dynamic_cast<CPanel*>(tPanels.front());
		if (tPanel)
		{
			if (ERELATION_STATE::HOSTILE == Check_Relation(tPanel, this))
			{
				m_vecPos.x = vecTemp.x;
				m_vecPos.y = vecTemp.y;
			}
		}
	}
	else
	{
		m_vecPos.x = vecTemp.x;
		m_vecPos.y = vecTemp.y;
	}
}

void CNavi_Rockman::Render(HDC hDC)
{
	CBmpMgr::Get_Instance()->Draw_PNG_Strip(hDC, Get_FrameKey(0), Get_Frame(0), m_vecPos, m_vecDirection);
	CBmpMgr::Get_Instance()->Draw_Text_Circle_Vec3(hDC, m_vecPos);

	//g.DrawImage(
	//	pImage, -(Get_Frame(0).iOffsetX), -(Get_Frame(0).iOffsetY),	// 이미지 오프셋
	//	Get_Frame(0).iFrameCur * Get_Frame(0).iFrameWidth, Get_Frame(0).iMotion * Get_Frame(0).iFrameHeight,
	//	Get_Frame(0).iFrameWidth, Get_Frame(0).iFrameHeight,				// 이미지 조각 크기로 대체
	//	Gdp::UnitPixel
	//);

	int iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScollX();
	int iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScollY();


	WCHAR text[100];
	//_stprintf_s(text, L"%i", (int)m_tState_Act.eState);
	_stprintf_s(text, L"%i", m_iHP.Cur);
	TextOutW(hDC, (int)m_vecPos.x - iScrollX, (int)m_vecPos.y - (int)m_vecPos.z - iScrollY, text, lstrlen(text));
}

void CNavi_Rockman::Release(void)
{

}

void CNavi_Rockman::Collide(CObj* _pDst)
{
	// 공격을 받는다.
	CSpell* pSrc = dynamic_cast<CSpell*>(_pDst);
	if (pSrc && Get_Owner() != pSrc
		&& ERELATION_STATE::HOSTILE == ITeamAgent::Check_Relation(pSrc, this))
	{
		CSoundMgr::Get_Instance()->Play_Sound(const_cast<TCHAR*>(L"hurt.wav"), SOUND_EFFECT, 1.f);
		m_fInvicibleTime.Reset();
		m_tState.Set_State(HIT);
		m_bInvincible = true;
	}
}

void CNavi_Rockman::State_Update(float fDeltaTime)
{
	if (m_fInvicibleTime.Update(fDeltaTime))
	{
		m_bInvincible = false;
	}

	switch (m_tState.eState)
	{
	case IDLE:
		if (m_tState.IsState_Entered())
		{
			Set_FrameKey(0, L"NBT_Rockman_EXE_Normal_Idle");
			CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
		}

		if (CKeyMgr::Get_Instance()->Key_Pressing(VK_RIGHT))
		{
			m_vecMoveDir.x = 1;
		}
		else if (CKeyMgr::Get_Instance()->Key_Pressing(VK_LEFT))
		{
			m_vecMoveDir.x = -1;
		}
		else if (CKeyMgr::Get_Instance()->Key_Pressing(VK_UP))
		{
			m_vecMoveDir.y = 1;
		}
		else if (CKeyMgr::Get_Instance()->Key_Pressing(VK_DOWN))
		{
			m_vecMoveDir.y = -1;
		}

		if (CKeyMgr::Get_Instance()->Key_Down('A'))
		{
			m_tState.Set_State(SHOOT_BUSTER);
		}

		if (CKeyMgr::Get_Instance()->Key_Pressing(VK_RIGHT) || CKeyMgr::Get_Instance()->Key_Pressing(VK_LEFT)
			|| CKeyMgr::Get_Instance()->Key_Pressing(VK_UP) || CKeyMgr::Get_Instance()->Key_Pressing(VK_DOWN))
		{
			m_tState.Set_State(MOVE_READY);
		}

		if (m_bIsOnGround && CKeyMgr::Get_Instance()->Key_Down('S'))
		{
			m_tState.Set_State(JUMP);
		}

		break;
	case MOVE_READY:
		if (m_tState.IsState_Entered())
		{
			Set_FrameKey(0, L"NBT_Rockman_EXE_Normal_Move_Ready");
			CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
		}


		if (Get_Frame(0).iFrameCur >= Get_Frame(0).iFrameEnd)
		{
			m_tState.Set_State(MOVE_END);
		}
		break;

	case MOVE_END:
		if (m_tState.IsState_Entered())
		{
			Set_FrameKey(0, L"NBT_Rockman_EXE_Normal_Move_End");
			CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);

			m_vecSpeed.x = (float)PANEL_CROW * (float)m_vecMoveDir.x;
			m_vecSpeed.y = (float)PANEL_CCOL * (float)m_vecMoveDir.y;

			m_vecMoveDir = CVector2<int>::Zero();
		}



		if (Get_Frame(0).iFrameCur >= Get_Frame(0).iFrameEnd)
		{
			m_tState.Set_State(IDLE);
		}
		break;
	case SHOOT_BUSTER:
		if (m_tState.IsState_Entered())
		{
			Set_FrameKey(0, L"NBT_Rockman_EXE_Normal_Shoot_Buster");
			CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);

			//CBattleSpell_Factory<CSpell_Buster>::Create(TEAM_ALPHA, m_vecPos, CVector2<int>(m_vecDirection.x, m_vecDirection.y));
			CSpell_Cannon_Factory::Create(this, m_vecPos, CVector2<int>(m_vecDirection.x, m_vecDirection.y), 40);
		}



		if (Get_Frame(0).iFrameCur >= Get_Frame(0).iFrameEnd)
		{
			m_tState.Set_State(IDLE);
		}
		break;
	case JUMP:
		if (m_tState.IsState_Entered())
		{
			Set_FrameKey(0, L"NBT_Rockman_EXE_Normal_Idle");
			CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);

			if (m_bIsOnGround)
			{
				CSoundMgr::Get_Instance()->Play_Sound(const_cast<TCHAR*>(L"jump_lite.wav"), SYSTEM_EFFECT, 1.f);
				m_vecSpeed.z = 5.f;
			}
		}

		// 실행식

		// 조건식
		if (m_bIsOnGround && m_vecSpeed.z <= 0.f)
		{
			m_tState.Set_State(IDLE);
		}
		if (CKeyMgr::Get_Instance()->Key_Down('A'))
		{
			m_tState.Set_State(JUMP_SHOOT_BUSTER);
		}
		break;
	case JUMP_SHOOT_BUSTER:
		if (m_tState.IsState_Entered())
		{
			Set_FrameKey(0, L"NBT_Rockman_EXE_Normal_Shoot_Buster");
			CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
			

			//CBattleSpell_Factory<CSpell_Buster>::Create((TEAM_ID)Get_TeamID(), m_vecPos, CVector2<int>(m_vecDirection.x, m_vecDirection.y));
			CSpell_Cannon_Factory::Create(this, m_vecPos, CVector2<int>(m_vecDirection.x, m_vecDirection.y), 40);
		}

		// 실행식

		// 조건식
		if (m_bIsOnGround && m_vecSpeed.z <= 0.f)
		{
			m_tState.Set_State(IDLE);
		}
		else if (Get_Frame(0).IsFrameEnd())
		{
			m_tState.Set_State(JUMP);
		}

		if (m_tState.IsState_Exit())
		{
			
		}
		break;
	case HIT:
		if (m_tState.IsState_Entered())
		{
			Set_FrameKey(0, L"NBT_Rockman_EXE_Normal_Hit");
			CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
		}

		// 실행식
		m_vecMoveDir = CVector2<int>::Zero();

		// 조건식
		if (Get_Frame(0).IsFrameEnd())
		{
			m_tState.Set_State(IDLE);
		}

		if (m_tState.IsState_Exit())
		{

		}
		break;
	}
}


