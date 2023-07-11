#include "Virus_Mettaur.h"

#include "BmpMgr.h"
#include "Manager/AnimationTable.h"
#include "ScrollMgr.h"

#include "Spell/Spell_Shockwave.h"

CVirus_Mettaur::CVirus_Mettaur()
{
}

CVirus_Mettaur::~CVirus_Mettaur()
{
}

void CVirus_Mettaur::Initialize(void)
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
	wstring sText = L"./RockmanEXE/Resource/battle/virus/mettaur/";
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"idle.png").c_str(), L"NBT_Mettaur_Idle");
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"prepare_atk.png").c_str(), L"NBT_Mettaur_Prepare_Atk");
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"attack.png").c_str(), L"NBT_Mettaur_Attack");
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"hiding.png").c_str(), L"NBT_Mettaur_Hiding");
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"hid.png").c_str(), L"NBT_Mettaur_Hid");
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"showing.png").c_str(), L"NBT_Mettaur_Showing");
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"jump.png").c_str(), L"NBT_Mettaur_Jump");
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"landing.png").c_str(), L"NBT_Mettaur_Landing");
#pragma endregion

	Set_FrameKey(0, L"NBT_Mettaur_Idle");
	CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);

#pragma region 행동 상태머신 등록
	m_tState_Act.Set_State(STATE_ACT::IDLE);
	m_tState_Act.Add_Func(STATE_ACT::IDLE, &CVirus_Mettaur::Idle);
	m_tState_Act.Add_Func(STATE_ACT::PRE_ATTACK, &CVirus_Mettaur::Prepare_Atk);
	m_tState_Act.Add_Func(STATE_ACT::ATTACK, &CVirus_Mettaur::Attack);
	m_tState_Act.Add_Func(STATE_ACT::HIDING, &CVirus_Mettaur::Hiding);
	m_tState_Act.Add_Func(STATE_ACT::HID, &CVirus_Mettaur::Hid);
	m_tState_Act.Add_Func(STATE_ACT::SHOWING, &CVirus_Mettaur::Showing);
	m_tState_Act.Add_Func(STATE_ACT::JUMP, &CVirus_Mettaur::Jump);
	m_tState_Act.Add_Func(STATE_ACT::LANDING, &CVirus_Mettaur::Landing);
#pragma endregion

#pragma region 목표 상태머신 등록
	m_tState_Obj.Set_State(STATE_OBJ::IDLE);
	m_tState_Obj.Add_Func(STATE_OBJ::IDLE, &CVirus_Mettaur::Obj_Idle);
	m_tState_Obj.Add_Func(STATE_OBJ::CHASE, &CVirus_Mettaur::Obj_Chase);
	m_tState_Obj.Add_Func(STATE_OBJ::HIDE, &CVirus_Mettaur::Obj_Hide);
	m_tState_Obj.Add_Func(STATE_OBJ::ATTACK, &CVirus_Mettaur::Obj_Attack);
	m_tState_Obj.Add_Func(STATE_OBJ::WAITING, &CVirus_Mettaur::Obj_Waiting);
	m_tState_Obj.Add_Func(STATE_OBJ::JUMP, &CVirus_Mettaur::Obj_Jump);
#pragma endregion

#pragma region 등장 상태머신 등록
	m_tState_Apr.Set_State(STATE_APR::NONE);
	m_tState_Apr.Add_Func(STATE_APR::NONE, &CVirus_Mettaur::Apr_None);
	m_tState_Apr.Add_Func(STATE_APR::APPEAR, &CVirus_Mettaur::Apr_Appear);
	m_tState_Apr.Add_Func(STATE_APR::DISAPPEAR, &CVirus_Mettaur::Apr_Disappear);
	m_tState_Apr.Add_Func(STATE_APR::VISIBLE, &CVirus_Mettaur::Apr_Visible);
#pragma endregion

#pragma region 액션 키 등록
	m_mapActionKey.Add_Action(ACTION_KEY::LEFT);
	m_mapActionKey.Add_Action(ACTION_KEY::RIGHT);
	m_mapActionKey.Add_Action(ACTION_KEY::UP);
	m_mapActionKey.Add_Action(ACTION_KEY::DOWN);
	m_mapActionKey.Add_Action(ACTION_KEY::ATTACK);
	m_mapActionKey.Add_Action(ACTION_KEY::HIDE);
	m_mapActionKey.Add_Action(ACTION_KEY::JUMP);
#pragma endregion

}

int CVirus_Mettaur::Update(float fDeltaTime)
{
	m_tState_Act.Get_StateFunc()(this, fDeltaTime);	// AI
	m_tState_Obj.Get_StateFunc()(this, fDeltaTime);	// 행동
	//m_tState_Apr.Get_StateFunc()(this, fDeltaTime);	// 등장

	m_mapActionKey.Update();	// 액션키 초기화

	__super::Move_Frame();

	return 0;
}

void CVirus_Mettaur::Late_Update(float fDeltaTime)
{
	Gravity(fDeltaTime);		// 중력
	Move(fDeltaTime);			// 이동에 대한 처리를 수행하기

	CCharacter_NetBattle::Info_Update();
}

void CVirus_Mettaur::Render(HDC hDC)
{
	if (m_fOpacity >= 1.f)
		CBmpMgr::Get_Instance()->Draw_PNG_Strip(hDC, Get_FrameKey(0), Get_Frame(0), m_vecPos, m_vecDirection);
	else
		CBmpMgr::Get_Instance()->Draw_PNG_StripAlpha(hDC, Get_FrameKey(0), Get_Frame(0), m_vecPos, m_vecDirection, m_fOpacity);
	//CBmpMgr::Get_Instance()->Draw_Text_Circle_Vec3(hDC, m_vecPos);

	int iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScollX();
	int iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScollY();

	WCHAR text[100];
	_stprintf_s(text, L"%i", m_iHP.Cur);
	TextOutW(hDC, (int)m_vecPos.x - iScrollX, (int)m_vecPos.y - (int)m_vecPos.z - iScrollY, text, lstrlen(text));
}

void CVirus_Mettaur::Release(void)
{

}

void CVirus_Mettaur::Collide(CObj* _pDst)
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



void CVirus_Mettaur::Idle(float fDeltaTime)
{
	if (m_tState_Act.IsState_Entered())
	{
		Set_FrameKey(0, L"NBT_Mettaur_Idle");
		CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
	}

	// 실행
	{

	}

	// 조건
	{
		if (m_mapActionKey[ACTION_KEY::ATTACK].IsOnAct())
			m_tState_Act.Set_State(STATE_ACT::PRE_ATTACK);
	}

	if (m_tState_Act.IsState_Exit())
	{

	}
}

void CVirus_Mettaur::Prepare_Atk(float fDeltaTime)
{
	if (m_tState_Act.IsState_Entered())
	{
		Set_FrameKey(0, L"NBT_Mettaur_Prepare_Atk");
		CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
	}

	// 실행
	{

	}

	// 조건
	{
		if (Get_Frame(0).IsFrameEnd())
			m_tState_Act.Set_State(STATE_ACT::ATTACK);
	}

	if (m_tState_Act.IsState_Exit())
	{

	}
}

void CVirus_Mettaur::Attack(float fDeltaTime)
{
	if (m_tState_Act.IsState_Entered())
	{
		Set_FrameKey(0, L"NBT_Mettaur_Attack");
		CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
		m_mapActionKey[ACTION_KEY::ATTACKED].Act();
	}

	// 실행
	{
		if (Get_Frame(0).iFrameCur == 6 && m_mapActionKey[ACTION_KEY::ATTACKED].IsOnAct())
		{
			m_mapActionKey[ACTION_KEY::ATTACKED].Update();
			auto vecTemp = m_vecPos;
			vecTemp.x += (float)m_vecDirection.x * 39.f;
			CSpell_Shockwave_Factory::Create((TEAM_ID)Get_TeamID(), vecTemp, m_vecDirection, 5.f, 1.f, 10);
		}
	}

	// 조건
	{
		if (Get_Frame(0).IsFrameEnd())
			m_tState_Act.Set_State(STATE_ACT::IDLE);
	}

	if (m_tState_Act.IsState_Exit())
	{

	}
}

void CVirus_Mettaur::Hiding(float fDeltaTime)
{
	if (m_tState_Act.IsState_Entered())
	{
		Set_FrameKey(0, L"NBT_Mettaur_Hiding");
		CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
	}

	if (m_tState_Act.IsState_Exit())
	{

	}
}

void CVirus_Mettaur::Hid(float fDeltaTime)
{
	if (m_tState_Act.IsState_Entered())
	{
		Set_FrameKey(0, L"NBT_Mettaur_Hid");
		CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
	}

	// 실행
	{

	}

	// 조건
	{

	}

	if (m_tState_Act.IsState_Exit())
	{

	}
}

void CVirus_Mettaur::Showing(float fDeltaTime)
{
	if (m_tState_Act.IsState_Entered())
	{
		Set_FrameKey(0, L"NBT_Mettaur_Showing");
		CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
	}

	// 실행
	{

	}

	// 조건
	{

	}

	if (m_tState_Act.IsState_Exit())
	{

	}
}

void CVirus_Mettaur::Jump(float fDeltaTime)
{
	if (m_tState_Act.IsState_Entered())
	{
		Set_FrameKey(0, L"NBT_Mettaur_Jump");
		CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
	}

	// 실행
	{

	}

	// 조건
	{

	}

	if (m_tState_Act.IsState_Exit())
	{

	}
}

void CVirus_Mettaur::Landing(float fDeltaTime)
{
	if (m_tState_Act.IsState_Entered())
	{
		Set_FrameKey(0, L"NBT_Mettaur_Landing");
		CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
	}

	// 실행
	{

	}

	// 조건
	{

	}

	if (m_tState_Act.IsState_Exit())
	{

	}
}



/*
* 여기부터 AI
*/


void CVirus_Mettaur::Obj_Idle(float fDeltaTime)
{
	if (m_tState_Obj.IsState_Entered())
	{

	}

	// 실행
	{
		
	}

	// 조건
	{
		// 공격 상태로 변경
		m_tState_Obj.Set_State(STATE_OBJ::ATTACK);
	}

	if (m_tState_Obj.IsState_Exit())
	{

	}
}

void CVirus_Mettaur::Obj_Chase(float fDeltaTime)
{
}

void CVirus_Mettaur::Obj_Attack(float fDeltaTime)
{
	if (m_tState_Obj.IsState_Entered())
	{

	}

	// 실행
	{
		// 공격 행동
		m_mapActionKey[ACTION_KEY::ATTACK].Act();
	}

	// 조건
	{
		if (m_tState_Act.IsOnState(STATE_ACT::ATTACK) && Get_Frame(0).IsFrameEnd())
			m_tState_Obj.Set_State(STATE_OBJ::IDLE);
	}

	if (m_tState_Obj.IsState_Exit())
	{

	}
}

void CVirus_Mettaur::Obj_Hide(float fDeltaTime)
{
}

void CVirus_Mettaur::Obj_Waiting(float fDeltaTime)
{
}



void CVirus_Mettaur::Obj_Jump(float fDeltaTime)
{
	if (m_tState_Obj.IsState_Entered())
	{

	}

	if (m_tState_Obj.Can_Update())
	{

	}

	if (m_tState_Obj.IsState_Exit())
	{

	}
}

#pragma region 등장 상태함수
void CVirus_Mettaur::Apr_None(float fDeltaTime)
{
	if (m_tState_Apr.IsState_Entered())
	{
		m_fOpacity = 0.f;
	}

	if (m_tState_Apr.Can_Update())
	{
		if (m_bAppearance)
		{
			m_tState_Apr.Set_State(STATE_APR::APPEAR);
		}
	}

	if (m_tState_Apr.IsState_Exit())
	{

	}
}
void CVirus_Mettaur::Apr_Appear(float fDeltaTime)
{
	if (m_tState_Apr.IsState_Entered())
	{

	}

	if (m_tState_Apr.Can_Update())
	{
		m_fOpacity += 0.05f;
		if (m_fOpacity > 1.f)
		{
			m_fOpacity = 1.f;
			m_tState_Apr.Set_State(STATE_APR::VISIBLE);
		}
	}

	if (m_tState_Apr.IsState_Exit())
	{
		m_bAppearance = false;
	}
}

void CVirus_Mettaur::Apr_Disappear(float fDeltaTime)
{
	if (m_tState_Apr.IsState_Entered())
	{

	}

	if (m_tState_Apr.Can_Update())
	{
		m_fOpacity -= 0.05f;
		if (m_fOpacity < 0.f)
		{
			m_fOpacity = 0.f;
			m_tState_Apr.Set_State(STATE_APR::NONE);
		}
	}

	if (m_tState_Apr.IsState_Exit())
	{

	}
}

void CVirus_Mettaur::Apr_Visible(float fDeltaTime)
{
	if (m_tState_Apr.IsState_Entered())
	{
		m_fOpacity = 1.f;
	}

	if (m_tState_Apr.Can_Update())
	{

	}

	if (m_tState_Apr.IsState_Exit())
	{

	}
}
#pragma endregion