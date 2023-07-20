#include "Navi_Rockman.h"

#include "KeyMgr.h"
#include "ObjMgr.h"
#include "BmpMgr.h"
#include "CollisionMgr.h"
#include "ScrollMgr.h"
#include <SoundMgr.h>
#include <VecCollisionMgr.h>
#include "Player/PlayerData.h"

#include "Manager/AnimationTable.h"
#include "Battle/BattleSpell_Factory.h"
#include "Spell/Spell_Buster.h"
#include "Spell/Spell_Cannon.h"

#include "AbstractFactory.h"
#include <Spell/Spell_ChargeBuster.h>
#include <Spell/Spell_AirShot.h>
#include <Spell/Spell_Sword.h>
#include <Spell/Spell_LongSword.h>
#include <Spell/Spell_WideSword.h>


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
	m_iAttack = 1;

#pragma region 이미지 추가
	wstring sText = L"./RockmanEXE/Resource/battle/navi/rockman_exe/normal/";
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"idle.png").c_str(), L"NBT_Rockman_EXE_Normal_Idle");
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"hit.png").c_str(), L"NBT_Rockman_EXE_Normal_Hit");
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"paralyze.png").c_str(), L"NBT_Rockman_EXE_Normal_Paralyze");
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"move_end.png").c_str(), L"NBT_Rockman_EXE_Normal_Move_End");
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"move_ready.png").c_str(), L"NBT_Rockman_EXE_Normal_Move_Ready");
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"sword.png").c_str(), L"NBT_Rockman_EXE_Normal_Sword");
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"throw.png").c_str(), L"NBT_Rockman_EXE_Normal_Throw");
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"crouch.png").c_str(), L"NBT_Rockman_EXE_Normal_Crouch");
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"shoot_cannon.png").c_str(), L"NBT_Rockman_EXE_Normal_Shoot_Cannon");
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"shoot_buster.png").c_str(), L"NBT_Rockman_EXE_Normal_Shoot_Buster");
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"shoot_duration.png").c_str(), L"NBT_Rockman_EXE_Normal_Shoot_Duration");
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"throw_disk.png").c_str(), L"NBT_Rockman_EXE_Normal_Throw_Disk");
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"shoot_1.png").c_str(), L"NBT_Rockman_EXE_Normal_Shoot_1");
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"ready_crouch_1.png").c_str(), L"NBT_Rockman_EXE_Normal_Ready_Crouch_1");
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"shoot_2.png").c_str(), L"NBT_Rockman_EXE_Normal_Shoot_2");
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"ready_crouch_2.png").c_str(), L"NBT_Rockman_EXE_Normal_Ready_Crouch_2");
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"ready_swing.png").c_str(), L"NBT_Rockman_EXE_Normal_Ready_Swing");
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"swing.png").c_str(), L"NBT_Rockman_EXE_Normal_Swing");
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"crouch.png").c_str(), L"NBT_Rockman_EXE_Normal_Crouch");
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"jump.png").c_str(), L"NBT_Rockman_EXE_Normal_Jump");
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"landing.png").c_str(), L"NBT_Rockman_EXE_Normal_Landing");
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

	m_fInvicibleTime.ReAdjust(1.5f);

	m_tState.Set_State(STATE::IDLE);
	m_tState.Add_Func(STATE::IDLE, &CNavi_Rockman::Idle);
	m_tState.Add_Func(STATE::MOVE_READY, &CNavi_Rockman::MoveReady);
	m_tState.Add_Func(STATE::MOVE_END, &CNavi_Rockman::MoveEnd);
	m_tState.Add_Func(STATE::SHOOT_BUSTER, &CNavi_Rockman::ShootBuster);
	m_tState.Add_Func(STATE::CHARGE_BUSTER, &CNavi_Rockman::ChargeBuster);
	m_tState.Add_Func(STATE::JUMP, &CNavi_Rockman::Jump);
	m_tState.Add_Func(STATE::JUMP_SHOOT_BUSTER, &CNavi_Rockman::JumpShootBuster);
	m_tState.Add_Func(STATE::LANDING, &CNavi_Rockman::Landing);
	m_tState.Add_Func(STATE::HIT, &CNavi_Rockman::Hit);
	m_tState.Add_Func(STATE::CANNON, &CNavi_Rockman::Cannon);
	m_tState.Add_Func(STATE::AIR_SHOT, &CNavi_Rockman::AirShot);
	m_tState.Add_Func(STATE::VALCAN, &CNavi_Rockman::Valcan);
	m_tState.Add_Func(STATE::BOMB, &CNavi_Rockman::Bomb);
	m_tState.Add_Func(STATE::SWORD, &CNavi_Rockman::Sword);
	m_tState.Add_Func(STATE::WIDE_SWORD, &CNavi_Rockman::WideSword);
	m_tState.Add_Func(STATE::CRACK_SHOT, &CNavi_Rockman::CrackShot);
	m_tState.Add_Func(STATE::CHIP, &CNavi_Rockman::Chip);

	m_tState_Blink.Set_State(STATE_BLINK::NONE);
	m_tState_Blink.Add_Func(STATE_BLINK::NONE, &CNavi_Rockman::Blink_None);
	m_tState_Blink.Add_Func(STATE_BLINK::BLINK, &CNavi_Rockman::Blink_Blink);

	m_tState_Charge.Set_State(STATE_CHARGE::NONE);
	m_tState_Charge.Add_Func(STATE_CHARGE::NONE, &CNavi_Rockman::Charge_None);
	m_tState_Charge.Add_Func(STATE_CHARGE::CHARGING, &CNavi_Rockman::Charge_Charging);

	CBattleUI::Get_Instance()->Set_PlayerHP(m_iHP.Cur);
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

	CCharacter_NetBattle::Info_Update();

	CBattleUI::Get_Instance()->Set_PlayerHP(m_iHP.Cur);
}

void CNavi_Rockman::Render(HDC hDC)
{
	CBmpMgr::Get_Instance()->Draw_PNG_StripAlpha(hDC, Get_FrameKey(0), Get_Frame(0), m_vecPos, m_vecDirection, m_fOpacity);
	//CBmpMgr::Get_Instance()->Draw_Text_Circle_Vec3(hDC, m_vecPos);

	int iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScollX();
	int iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScollY();
	
	INFO tInfo = {};
	FRAME tFrame = {};

	// 칩 아이콘
	if (!m_ChipData_List.empty())
	{
		wstring swString = L"UI_Chip_Icon_";
		int i = (int)m_ChipData_List.size() - 1;
		for (auto iter = m_ChipData_List.rbegin(); iter != m_ChipData_List.rend(); ++iter)
		{
			tInfo.fX = m_vecPos.x - 3.f - (float)i * 2.f;
			tInfo.fY = m_vecPos.y - m_vecPos.z - 40.f - (float)i * 2.f;
			tFrame.iFrameWidth = 14; tFrame.iFrameHeight = 14;
			wstringstream ssInt;
			ssInt << (*iter).iID + 1;
			wstring swString2 = (swString + ssInt.str());

			CBmpMgr::Get_Instance()->Draw_PNG(hDC, swString2.c_str(), tInfo, tFrame, 1, 1, false);
			--i;
		}


		tInfo.fX = 4.f; tInfo.fY = (float)ROCKMAN_EXECY - 17.f;
		SelectObject(hDC, g_hFonts[0]);

		SetTextColor(hDC, DWORD(0x00000000));

		wstring sName = CChipDataTable::Get_Instance()->Get_ChipData_ForFolder(m_ChipData_List.front().iID).sName;
		
		WCHAR text[40];
		_stprintf_s(text, L"%s", sName.c_str());
		TextOutW(hDC, (int)tInfo.fX + 2 + 1, (int)tInfo.fY + 1, text, lstrlen(text));

		SetTextColor(hDC, DWORD(0x00FFFFFF));

		_stprintf_s(text, L"%s", sName.c_str());
		TextOutW(hDC, (int)tInfo.fX + 2, (int)tInfo.fY, text, lstrlen(text));

		int iTxtLength = (int)lstrlen(text);

		{
			SetTextColor(hDC, DWORD(0x00000000));

			wstringstream ssInt;
			ssInt << m_ChipData_List.front().iDamage;

			_stprintf_s(text, L"%s", ssInt.str().c_str());
			TextOutW(hDC, (int)tInfo.fX + 6 + 1 + iTxtLength * 16, (int)tInfo.fY + 1, text, lstrlen(text));

			SetTextColor(hDC, DWORD(0x0000AADD));

			_stprintf_s(text, L"%s", ssInt.str().c_str());
			TextOutW(hDC, (int)tInfo.fX + 6 + iTxtLength * 16, (int)tInfo.fY, text, lstrlen(text));
		}
	}

	/*WCHAR text[100];
	_stprintf_s(text, L"%i", m_iHP.Cur);
	TextOutW(hDC, (int)m_vecPos.x - iScrollX, (int)m_vecPos.y - (int)m_vecPos.z - iScrollY, text, lstrlen(text));*/
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
		m_tState.Set_State(STATE::HIT);
		m_bInvincible = true;
		CPlayerData::Get_Instance()->Set_CurHP(m_iHP.Cur);
	}
}

bool CNavi_Rockman::Input_Move()
{
	auto vecTemp = m_vecPos;
	bool bIsCanMove = false;

	
	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_RIGHT))
	{
		m_vecMoveDir.x = 1;
		bIsCanMove = true;
	}
	else if (CKeyMgr::Get_Instance()->Key_Pressing(VK_LEFT))
	{
		m_vecMoveDir.x = -1;
		bIsCanMove = true;
	}
	else if (CKeyMgr::Get_Instance()->Key_Pressing(VK_UP))
	{
		m_vecMoveDir.y = 1;
		bIsCanMove = true;
	}
	else if (CKeyMgr::Get_Instance()->Key_Pressing(VK_DOWN))
	{
		m_vecMoveDir.y = -1;
		bIsCanMove = true;
	}
	else
		m_vecMoveDir = CVector2<int>::Zero();

	if (IsOnGround())
	{
		if (m_vecMoveDir.x != 0.f || m_vecMoveDir.y != 0.f)
		{
			m_vecPos.x += (float)PANEL_CROW * (float)m_vecMoveDir.x;
			m_vecPos.y -= (float)PANEL_CCOL * (float)m_vecMoveDir.y;
		}

		// 다음 프레임의 판넬처리를 만든다.
		auto tPanels = CVecCollisionMgr::Collision_Box(CObjMgr::Get_Instance()->Get_ObjList(PANEL), this);

		if (!tPanels.empty())
		{
			CPanel* tPanel = dynamic_cast<CPanel*>(tPanels.front());
			if (tPanel)
			{
				if (ERELATION_STATE::HOSTILE == Check_Relation(tPanel, this))
				{
					m_vecPos = vecTemp;
					bIsCanMove = false;
				}
			}
		}
		else
		{
			bIsCanMove = false;
		}
	}

	m_vecPos = vecTemp;

	if (bIsCanMove)
		return true;

	return false;
}

bool CNavi_Rockman::Input_Jump()
{
	if (m_bIsOnGround && CKeyMgr::Get_Instance()->Key_Down('S'))
		return true;

	return false;
}

bool CNavi_Rockman::Input_Shot(float fDeltaTime)
{
	if (CKeyMgr::Get_Instance()->Key_Pressing('D'))
	{
		m_fBusterCharge.Update(fDeltaTime);
		return true;
	}

	return false;
}

bool CNavi_Rockman::Input_Chip()
{
	if (!m_ChipData_List.empty() && CKeyMgr::Get_Instance()->Key_Down('A'))
	{
		return true;
	}
	return false;
}

void CNavi_Rockman::State_Update(float fDeltaTime)
{
	if (m_fInvicibleTime.Update(fDeltaTime))
	{
		m_bInvincible = false;
	}

	m_tState_Blink.Get_StateFunc()(this, fDeltaTime);
	m_tState_Charge.Get_StateFunc()(this, fDeltaTime);
	m_tState.Get_StateFunc()(this, fDeltaTime);
}


#pragma region 행동 상태

void CNavi_Rockman::Idle(float fDeltaTime)
{
	if (m_tState.IsState_Entered())
	{
		Set_FrameKey(0, L"NBT_Rockman_EXE_Normal_Idle");
		CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
	}

	if (m_tState.Can_Update())
	{
		if (Input_Chip())
		{
			m_tState.Set_State(STATE::CHIP);
		}

		if (Input_Move())
		{
			m_tState.Set_State(STATE::MOVE_READY);
		}

		if (Input_Jump())
		{
			m_tState.Set_State(STATE::JUMP);
		}
	}

	if (m_tState.IsState_Exit())
	{

	}
}

void CNavi_Rockman::MoveReady(float fDeltaTime)
{
	if (m_tState.IsState_Entered())
	{
		Set_FrameKey(0, L"NBT_Rockman_EXE_Normal_Move_Ready");
		CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
	}

	if (m_tState.Can_Update())
	{
		if (Get_Frame(0).iFrameCur >= Get_Frame(0).iFrameEnd)
		{
			m_tState.Set_State(STATE::MOVE_END);
		}
	}

	if (m_tState.IsState_Exit())
	{

	}
}

void CNavi_Rockman::MoveEnd(float fDeltaTime)
{
	if (m_tState.IsState_Entered())
	{
		Set_FrameKey(0, L"NBT_Rockman_EXE_Normal_Move_End");
		CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);

		m_vecSpeed.x = (float)PANEL_CROW * (float)m_vecMoveDir.x;
		m_vecSpeed.y = (float)PANEL_CCOL * (float)m_vecMoveDir.y;

		m_vecMoveDir = CVector2<int>::Zero();
	}

	if (m_tState.Can_Update())
	{
		if (Get_Frame(0).iFrameCur >= Get_Frame(0).iFrameEnd)
		{
			m_tState.Set_State(STATE::IDLE);
		}
	}

	if (m_tState.IsState_Exit())
	{

	}
}

void CNavi_Rockman::ShootBuster(float fDeltaTime)
{
	if (m_tState.IsState_Entered())
	{
		Set_FrameKey(0, L"NBT_Rockman_EXE_Normal_Shoot_Buster");
		CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);

		CBattleSpell_Factory<CSpell_Buster>::Create(this, m_vecPos, CVector2<int>(m_vecDirection.x, m_vecDirection.y), m_iAttack);
	}

	if (m_tState.Can_Update())
	{
		if (Get_Frame(0).iFrameCur >= Get_Frame(0).iFrameEnd)
		{
			m_tState.Set_State(STATE::IDLE);
		}
	}

	if (m_tState.IsState_Exit())
	{

	}
}

void CNavi_Rockman::ChargeBuster(float fDeltaTime)
{
	if (m_tState.IsState_Entered())
	{
		Set_FrameKey(0, L"NBT_Rockman_EXE_Normal_Shoot_Buster");
		CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);

		CBattleSpell_Factory<CSpell_ChargeBuster>::Create(this, m_vecPos, CVector2<int>(m_vecDirection.x, m_vecDirection.y), m_iAttack * 10);
	}

	if (m_tState.Can_Update())
	{
		if (Get_Frame(0).iFrameCur >= Get_Frame(0).iFrameEnd)
		{
			m_tState.Set_State(STATE::IDLE);
		}
	}

	if (m_tState.IsState_Exit())
	{

	}
}

void CNavi_Rockman::Jump(float fDeltaTime)
{
	if (m_tState.IsState_Entered())
	{
		Set_FrameKey(0, L"NBT_Rockman_EXE_Normal_Jump");
		CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
		Get_Frame(0).Set_Loop(false);

		if (m_bIsOnGround)
		{
			CSoundMgr::Get_Instance()->Play_Sound(const_cast<TCHAR*>(L"toss_item.wav"), SOUND_EFFECT, 1.f);
			m_vecSpeed.z = 5.f;
		}
	}

	if (m_tState.Can_Update())
	{
		// 실행식

		// 조건식
		if (m_bIsOnGround && m_vecSpeed.z <= 0.f)
		{
			m_tState.Set_State(STATE::LANDING);
		}
	}

	if (m_tState.IsState_Exit())
	{

	}
}

void CNavi_Rockman::JumpShootBuster(float fDeltaTime)
{
	if (m_tState.IsState_Entered())
	{
		Set_FrameKey(0, L"NBT_Rockman_EXE_Normal_Shoot_Buster");
		CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);

		CBattleSpell_Factory<CSpell_Buster>::Create(this, m_vecPos, CVector2<int>(m_vecDirection.x, m_vecDirection.y));
	}

	if (m_tState.Can_Update())
	{
		// 실행식

		// 조건식
		if (m_bIsOnGround && m_vecSpeed.z <= 0.f)
		{
			m_tState.Set_State(STATE::IDLE);
		}
		else if (Get_Frame(0).IsFrameEnd())
		{
			m_tState.Set_State(STATE::JUMP);
		}
	}

	if (m_tState.IsState_Exit())
	{

	}
}

void CNavi_Rockman::Landing(float fDeltaTime)
{
	if (m_tState.IsState_Entered())
	{
		Set_FrameKey(0, L"NBT_Rockman_EXE_Normal_Landing");
		CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
	}

	if (m_tState.Can_Update())
	{
		// 실행식

		// 조건식
		if (Get_Frame(0).IsFrameEnd())
		{
			m_tState.Set_State(STATE::IDLE);
		}
	}

	if (m_tState.IsState_Exit())
	{

	}
}

void CNavi_Rockman::Hit(float fDeltaTime)
{
	if (m_tState.IsState_Entered())
	{
		Set_FrameKey(0, L"NBT_Rockman_EXE_Normal_Hit");
		CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
		m_tState_Blink.Set_State(STATE_BLINK::BLINK);
	}

	if (m_tState.Can_Update())
	{
		// 실행식
		m_vecMoveDir = CVector2<int>::Zero();

		// 조건식
		if (Get_Frame(0).IsFrameEnd())
		{
			m_tState.Set_State(STATE::IDLE);
		}
	}

	if (m_tState.IsState_Exit())
	{

	}
}
void CNavi_Rockman::Cannon(float fDeltaTime)
{
	if (m_tState.IsState_Entered())
	{
		Set_FrameKey(0, L"NBT_Rockman_EXE_Normal_Shoot_Cannon");
		CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
	}

	if (m_tState.Can_Update())
	{
		if (Get_Frame(0).IsFrameTick(5))
		{
			if (m_UseChipData.iID == 0)
			{
				CSpell_Cannon_Factory::Create(this, m_vecPos, CVector2<int>(m_vecDirection.x, m_vecDirection.y), m_UseChipData.iDamage);
			}
			else if (m_UseChipData.iID == 1)
			{
				CSpell_Cannon_Factory::Create(this, m_vecPos, CVector2<int>(m_vecDirection.x, m_vecDirection.y), m_UseChipData.iDamage);
			}
			else if (m_UseChipData.iID == 2)
			{
				CSpell_Cannon_Factory::Create(this, m_vecPos, CVector2<int>(m_vecDirection.x, m_vecDirection.y), m_UseChipData.iDamage);
			}
		}
		if (Get_Frame(0).IsFrameEnd())
		{
			m_tState.Set_State(STATE::IDLE);
		}
	}

	if (m_tState.IsState_Exit())
	{

	}
}
void CNavi_Rockman::AirShot(float fDeltaTime)
{
	if (m_tState.IsState_Entered())
	{
		Set_FrameKey(0, L"NBT_Rockman_EXE_Normal_Shoot_1");
		CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
	}

	if (m_tState.Can_Update())
	{
		if (Get_Frame(0).IsFrameTick(1))
		{
			CBattleSpell_Factory<CSpell_AirShot>::Create(this, m_vecPos, CVector2<int>(m_vecDirection.x, m_vecDirection.y), m_UseChipData.iDamage);
		}
		if (Get_Frame(0).IsFrameEnd())
		{
			m_tState.Set_State(STATE::IDLE);
		}
	}

	if (m_tState.IsState_Exit())
	{

	}
}
void CNavi_Rockman::Valcan(float fDeltaTime)
{
	if (m_tState.IsState_Entered())
	{
		Set_FrameKey(0, L"NBT_Rockman_EXE_Normal_Hit");
		CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
	}

	if (m_tState.Can_Update())
	{

	}

	if (m_tState.IsState_Exit())
	{

	}
}
void CNavi_Rockman::Bomb(float fDeltaTime)
{
	if (m_tState.IsState_Entered())
	{
		Set_FrameKey(0, L"NBT_Rockman_EXE_Normal_Hit");
		CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
	}

	if (m_tState.Can_Update())
	{
		if (Get_Frame(0).IsFrameTick(1))
		{
			CBattleSpell_Factory<CSpell_Sword>::Create(this, m_vecPos, CVector2<int>(m_vecDirection.x, m_vecDirection.y), m_UseChipData.iDamage);
		}

		if (Get_Frame(0).IsFrameEnd())
		{
			m_tState.Set_State(STATE::IDLE);
		}
	}

	if (m_tState.IsState_Exit())
	{

	}
}
void CNavi_Rockman::Sword(float fDeltaTime)
{
	if (m_tState.IsState_Entered())
	{
		Set_FrameKey(0, L"NBT_Rockman_EXE_Normal_Sword");
		CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
	}

	if (m_tState.Can_Update())
	{
		if (Get_Frame(0).IsFrameTick(1))
		{
			CVector2<int> vecDir = CVector2<int>(m_vecDirection.x, m_vecDirection.y);
			if (m_UseChipData.iID == 69)
			{
				CBattleSpell_Factory<CSpell_Sword>::Create(this, m_vecPos + CVector3<float>(vecDir.x * (float)PANEL_CROW, 0.f, 0.f),
					vecDir, m_UseChipData.iDamage);
			}
			else if (m_UseChipData.iID == 70)
			{
				CBattleSpell_Factory<CSpell_WideSword>::Create(this, m_vecPos + CVector3<float>(vecDir.x * (float)PANEL_CROW, 0.f, 0.f),
					vecDir, m_UseChipData.iDamage);
			}
			else if (m_UseChipData.iID == 71)
			{
				CBattleSpell_Factory<CSpell_LongSword>::Create(this, m_vecPos + CVector3<float>(vecDir.x * (float)PANEL_CROW, 0.f, 0.f),
					vecDir, m_UseChipData.iDamage);
			}
		}

		if (Get_Frame(0).IsFrameEnd())
		{
			m_tState.Set_State(STATE::IDLE);
		}
	}

	if (m_tState.IsState_Exit())
	{

	}
}
void CNavi_Rockman::WideSword(float fDeltaTime)
{
	if (m_tState.IsState_Entered())
	{
		Set_FrameKey(0, L"NBT_Rockman_EXE_Normal_Hit");
		CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
	}

	if (m_tState.Can_Update())
	{

	}

	if (m_tState.IsState_Exit())
	{

	}
}
void CNavi_Rockman::CrackShot(float fDeltaTime)
{
	if (m_tState.IsState_Entered())
	{
		Set_FrameKey(0, L"NBT_Rockman_EXE_Normal_Hit");
		CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
	}

	if (m_tState.Can_Update())
	{

	}

	if (m_tState.IsState_Exit())
	{

	}
}
void CNavi_Rockman::Chip(float fDeltaTime)
{
	if (m_tState.IsState_Entered())
	{
		Set_FrameKey(0, L"NBT_Rockman_EXE_Normal_Idle");
		CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
	}

	if (m_tState.Can_Update())
	{
		// 여기서 가장 앞에 있는 칩의 정보를 토대로 적절한 공격을 취하는 상태를 만든다.
		m_UseChipData = m_ChipData_List.front();
		m_ChipData_List.pop_front();
		switch (m_UseChipData.iID)
		{
		case 0:
		case 1:
		case 2: // 캐논
			m_tState.Set_State(STATE::CANNON);
			break;
		case 3: // 에어샷
			m_tState.Set_State(STATE::AIR_SHOT);
			break;
		case 69:
			m_tState.Set_State(STATE::SWORD);
			break;
		case 70:
			m_tState.Set_State(STATE::SWORD);
			break;
		case 71:
			m_tState.Set_State(STATE::SWORD);
			break;
		case 155: // 리커버리 10
			m_iHP.Update(10);
			CSoundMgr::Get_Instance()->Play_Sound(const_cast<TCHAR*>(L"recover.wav"), SOUND_VFX, 1.f);
			m_tState.Set_State(STATE::IDLE);
			break;
		case 156: // 리커버리 30
			m_iHP.Update(30);
			CSoundMgr::Get_Instance()->Play_Sound(const_cast<TCHAR*>(L"recover.wav"), SOUND_VFX, 1.f);
			m_tState.Set_State(STATE::IDLE);
			break;
		case 176: // 버스터 업
			if (++m_iAttack > 5)
				m_iAttack = 5;
			CSoundMgr::Get_Instance()->Play_Sound(const_cast<TCHAR*>(L"recover.wav"), SOUND_VFX, 1.f);
			m_tState.Set_State(STATE::IDLE);
			break;
		default:
			m_tState.Set_State(STATE::IDLE);
		}
	}

	if (m_tState.IsState_Exit())
	{

	}
}
#pragma endregion

#pragma region 블링크 상태

void CNavi_Rockman::Blink_None(float fDelta)
{
	if (m_tState_Blink.IsState_Entered())
	{
		m_fOpacity = 1.0f;
	}

	if (m_tState_Blink.Can_Update())
	{

	}

	if (m_tState_Blink.IsState_Exit())
	{

	}
}

void CNavi_Rockman::Blink_Blink(float fDeltaTime)
{
	if (m_tState_Blink.IsState_Entered())
	{
		m_fBlink.Reset();
	}

	if (m_tState_Blink.Can_Update())
	{
		if (m_fBlink.Update(fDeltaTime, true))
		{
			m_fOpacity = !m_fOpacity;
		}

		if (!m_bInvincible)
			m_tState_Blink.Set_State(STATE_BLINK::NONE);
	}

	if (m_tState_Blink.IsState_Exit())
	{
		m_fOpacity = 1.0f;
	}
}

#pragma endregion

#pragma region 차지샷 상태
void CNavi_Rockman::Charge_None(float fDeltaTime)
{
	if (m_tState_Charge.IsState_Entered())
	{

	}

	if (m_tState_Charge.Can_Update())
	{
		if (Input_Shot(fDeltaTime))
		{
			m_tState_Charge.Set_State(STATE_CHARGE::CHARGING);
		}
	}

	if (m_tState_Charge.IsState_Exit())
	{

	}
}
void CNavi_Rockman::Charge_Charging(float fDeltaTime)
{
	if (m_tState_Charge.IsState_Entered())
	{

	}

	if (m_tState_Charge.Can_Update())
	{
		if (m_fBusterCharge.IsReach_Once(0.1f, fDeltaTime))
		{
			CSoundMgr::Get_Instance()->Play_Sound(const_cast<TCHAR*>(L"buster_charging.wav"), SOUND_PLAYER, 1.f);
		}
		if (m_fBusterCharge.IsMax_Once())
		{
			CSoundMgr::Get_Instance()->Play_Sound(const_cast<TCHAR*>(L"buster_charged.wav"), SOUND_PLAYER, 1.f);
		}

		if (!Input_Shot(fDeltaTime))
		{
			if (m_tState.IsOnState(STATE::IDLE) && m_bIsOnGround)
			{
				m_tState_Charge.Set_State(STATE_CHARGE::NONE);
				if (m_fBusterCharge.IsMax())
				{
					m_tState.Set_State(STATE::CHARGE_BUSTER);
				}
				else
					m_tState.Set_State(STATE::SHOOT_BUSTER);
			}
			else if (m_tState.IsOnState(STATE::HIT))
				m_tState_Charge.Set_State(STATE_CHARGE::NONE);
		}
		else
		{
			if (m_tState.IsOnState(STATE::CHIP))
				m_tState_Charge.Set_State(STATE_CHARGE::NONE);
		}
	}

	if (m_tState_Charge.IsState_Exit())
	{
		m_fBusterCharge.Reset();
	}
}
#pragma endregion
