#include "Virus_Gunner.h"

#include <Manager/AnimationTable.h>
#include <BmpMgr.h>
#include <ScrollMgr.h>

#include "Spell/Spell.h"

void CVirus_Gunner::Initialize(void)
{
	CVirus::Initialize_Virus();

	// 현재 좌표 박스로 조정하기
	m_vecBox = CVector3<float>(15.f, 10.f, 16.f);
	m_vecBoxPos = CVector3<float>(0.f, 0.f, 10.f);
	m_vecPos.z += (m_vecBox.z - m_vecBoxPos.z);

	// 체력, 공격력 설정
	m_iHP = GAUGE<int>(40, true);
	m_iAttack = 10;

#pragma region 이미지 추가
	wstring sText = L"./RockmanEXE/Resource/battle/virus/gunner/";
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"idle.png").c_str(), L"NBT_Gunner_Idle");
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"detected.png").c_str(), L"NBT_Gunner_Detected");
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"shoot.png").c_str(), L"NBT_Gunner_Shoot");
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"shoot_to_idle.png").c_str(), L"NBT_Gunner_Shoot_To_Idle");
#pragma endregion

	Set_FrameKey(0, L"NBT_Gunner_Idle");
	CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);

#pragma region 행동 상태머신 등록
	m_tState_Act.Set_State(STATE_ACT::IDLE);
	m_tState_Act.Add_Func(STATE_ACT::IDLE, &CVirus_Gunner::Idle);
	m_tState_Act.Add_Func(STATE_ACT::DETECTED, &CVirus_Gunner::Detected);
	m_tState_Act.Add_Func(STATE_ACT::SHOOT, &CVirus_Gunner::Shoot);
	m_tState_Act.Add_Func(STATE_ACT::SHOOT_TO_IDLE, &CVirus_Gunner::ShootToIdle);
#pragma endregion

#pragma region 목표 상태머신 등록
	m_tState_Obj.Set_State(STATE_OBJ::IDLE);
	m_tState_Obj.Add_Func(STATE_OBJ::IDLE, &CVirus_Gunner::Obj_Idle);
	m_tState_Obj.Add_Func(STATE_OBJ::WATCH, &CVirus_Gunner::Obj_Watch);
	m_tState_Obj.Add_Func(STATE_OBJ::ATK, &CVirus_Gunner::Obj_Atk);
#pragma endregion

#pragma region 액션 키 등록
	m_mapActionKey.Add_Action(ACTION_KEY::LEFT);
	m_mapActionKey.Add_Action(ACTION_KEY::RIGHT);
	m_mapActionKey.Add_Action(ACTION_KEY::UP);
	m_mapActionKey.Add_Action(ACTION_KEY::DOWN);
	m_mapActionKey.Add_Action(ACTION_KEY::ATTACK);
#pragma endregion
}

int CVirus_Gunner::Update(float fDeltaTime)
{
	m_tState_Act.Get_StateFunc()(this, fDeltaTime);	// AI
	m_tState_Obj.Get_StateFunc()(this, fDeltaTime);	// 행동

	m_mapActionKey.Update();	// 액션키 초기화

	__super::Move_Frame();

	return 0;
}

void CVirus_Gunner::Late_Update(float fDeltaTime)
{
	Gravity(fDeltaTime);		// 중력
	Move(fDeltaTime);			// 이동에 대한 처리를 수행하기

	CCharacter_NetBattle::Info_Update();
}

void CVirus_Gunner::Render(HDC hDC)
{
	CBmpMgr::Get_Instance()->Draw_PNG_StripAlpha(hDC, Get_FrameKey(0), Get_Frame(0), m_vecPos, m_vecDirection, m_fOpacity);
	//CBmpMgr::Get_Instance()->Draw_Text_Circle_Vec3(hDC, m_vecPos);

	int iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScollX();
	int iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScollY();

	WCHAR text[100];
	_stprintf_s(text, L"%i", m_iHP.Cur);
	TextOutW(hDC, (int)m_vecPos.x - iScrollX, (int)m_vecPos.y - (int)m_vecPos.z - iScrollY, text, lstrlen(text));
}

void CVirus_Gunner::Release(void)
{
}

void CVirus_Gunner::Collide(CObj* _pDst)
{
	CSpell* pChr = dynamic_cast<CSpell*>(_pDst);
	if (pChr
		&& Get_Owner() != pChr
		&& ERELATION_STATE::HOSTILE == ITeamAgent::Check_Relation(pChr, this))
	{
		if (m_iHP.Cur <= 0)
			Set_Dead();
	}
}

#pragma region 행동 상태

void CVirus_Gunner::Idle(float fDeltaTime)
{
	if (m_tState_Act.IsState_Entered())
	{
		Set_FrameKey(0, L"NBT_Gunner_Idle");
		CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
	}

	if (m_tState_Act.Can_Update())
	{

	}

	if (m_tState_Act.IsState_Exit())
	{

	}
}

void CVirus_Gunner::Detected(float fDeltaTime)
{
	if (m_tState_Act.IsState_Entered())
	{
		Set_FrameKey(0, L"NBT_Gunner_Detected");
		CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
	}

	if (m_tState_Act.Can_Update())
	{

	}

	if (m_tState_Act.IsState_Exit())
	{

	}
}

void CVirus_Gunner::Shoot(float fDeltaTime)
{
	if (m_tState_Act.IsState_Entered())
	{
		Set_FrameKey(0, L"NBT_Gunner_Shoot");
		CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
	}

	if (m_tState_Act.Can_Update())
	{

	}

	if (m_tState_Act.IsState_Exit())
	{

	}
}

void CVirus_Gunner::ShootToIdle(float fDeltaTime)
{
	if (m_tState_Act.IsState_Entered())
	{
		Set_FrameKey(0, L"NBT_Gunner_Shoot_To_Idle");
		CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
	}

	if (m_tState_Act.Can_Update())
	{

	}

	if (m_tState_Act.IsState_Exit())
	{

	}
}
#pragma endregion




#pragma region 목표 상태

void CVirus_Gunner::Obj_Idle(float fDeltaTime)
{
}

void CVirus_Gunner::Obj_Watch(float fDeltaTime)
{
}

void CVirus_Gunner::Obj_Atk(float fDeltaTime)
{
}
#pragma endregion