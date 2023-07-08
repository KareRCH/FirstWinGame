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
	TCHAR sText[100];
	const TCHAR* sCharacterDir = L"./RockmanEXE/Resource/battle/virus/mettaur/";
	lstrcpy(sText, sCharacterDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"idle.png"), L"NBT_Mettaur_Idle");
	lstrcpy(sText, sCharacterDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"prepare_atk.png"), L"NBT_Mettaur_Prepare_Atk");
	lstrcpy(sText, sCharacterDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"attack.png"), L"NBT_Mettaur_Attack");
	lstrcpy(sText, sCharacterDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"hiding.png"), L"NBT_Mettaur_Hiding");
	lstrcpy(sText, sCharacterDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"hid.png"), L"NBT_Mettaur_Hid");
	lstrcpy(sText, sCharacterDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"showing.png"), L"NBT_Mettaur_Showing");
	lstrcpy(sText, sCharacterDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"jump.png"), L"NBT_Mettaur_Jump");
	lstrcpy(sText, sCharacterDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"landing.png"), L"NBT_Mettaur_Landing");
#pragma endregion

	Set_FrameKey(0, L"NBT_Mettaur_Idle");
	CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);

#pragma region 행동 상태머신 등록
	m_fnActState.emplace(ACT_STATE::IDLE, &CVirus_Mettaur::Idle);
	m_fnActState.emplace(ACT_STATE::PRE_ATTACK, &CVirus_Mettaur::Prepare_Atk);
	m_fnActState.emplace(ACT_STATE::ATTACK, &CVirus_Mettaur::Attack);
	m_fnActState.emplace(ACT_STATE::HIDING, &CVirus_Mettaur::Hiding);
	m_fnActState.emplace(ACT_STATE::HID, &CVirus_Mettaur::Hid);
	m_fnActState.emplace(ACT_STATE::SHOWING, &CVirus_Mettaur::Showing);
	m_fnActState.emplace(ACT_STATE::JUMP, &CVirus_Mettaur::Jump);
	m_fnActState.emplace(ACT_STATE::LANDING, &CVirus_Mettaur::Landing);
#pragma endregion

#pragma region 목표 상태머신 등록
	m_fnObjState.emplace(OBJ_STATE::IDLE, &CVirus_Mettaur::Obj_Idle);
	m_fnObjState.emplace(OBJ_STATE::CHASE, &CVirus_Mettaur::Obj_Chase);
	m_fnObjState.emplace(OBJ_STATE::HIDE, &CVirus_Mettaur::Obj_Hide);
	m_fnObjState.emplace(OBJ_STATE::ATTACK, &CVirus_Mettaur::Obj_Attack);
	m_fnObjState.emplace(OBJ_STATE::WAITING, &CVirus_Mettaur::Obj_Waiting);
	m_fnObjState.emplace(OBJ_STATE::JUMP, &CVirus_Mettaur::Obj_Jump);
#pragma endregion

	m_tState_Act.Set_State(ACT_STATE::IDLE);
	m_tState_Obj.Set_State(OBJ_STATE::IDLE);

#pragma region 액션 키 등록
	m_mapActionKey.emplace(ACTION_KEY::LEFT, ACTION());
	m_mapActionKey.emplace(ACTION_KEY::RIGHT, ACTION());
	m_mapActionKey.emplace(ACTION_KEY::UP, ACTION());
	m_mapActionKey.emplace(ACTION_KEY::DOWN, ACTION());
	m_mapActionKey.emplace(ACTION_KEY::ATTACK, ACTION());
	m_mapActionKey.emplace(ACTION_KEY::HIDE, ACTION());
	m_mapActionKey.emplace(ACTION_KEY::JUMP, ACTION());
#pragma endregion

}

int CVirus_Mettaur::Update(float fDeltaTime)
{
	m_fnObjState[m_tState_Obj.eState](this, fDeltaTime);	// AI
	m_fnActState[m_tState_Act.eState](this, fDeltaTime);	// 행동

	for_each(m_mapActionKey.begin(), m_mapActionKey.end(), CMapAction_Updator<ACTION_KEY>());	// 액션키 초기화

	__super::Move_Frame();

	return 0;
}

void CVirus_Mettaur::Late_Update(float fDeltaTime)
{
	Gravity(fDeltaTime);		// 중력
	Move(fDeltaTime);			// 이동에 대한 처리를 수행하기
}

void CVirus_Mettaur::Render(HDC hDC)
{
	CBmpMgr::Get_Instance()->Draw_PNG_Strip(hDC, Get_FrameKey(0), Get_Frame(0), m_vecPos, m_vecDirection);
	CBmpMgr::Get_Instance()->Draw_Text_Circle_Vec3(hDC, m_vecPos);

	int iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScollX();
	int iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScollY();

	WCHAR text[100];
	//_stprintf_s(text, L"%i", (int)m_tState_Act.eState);
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
			m_tState_Act.Set_State(ACT_STATE::PRE_ATTACK);
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
			m_tState_Act.Set_State(ACT_STATE::ATTACK);
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
			m_tState_Act.Set_State(ACT_STATE::IDLE);
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
		m_tState_Obj.Set_State(OBJ_STATE::ATTACK);
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
		if (m_tState_Act.IsOnState(ACT_STATE::ATTACK) && Get_Frame(0).IsFrameEnd())
			m_tState_Obj.Set_State(OBJ_STATE::IDLE);
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
}
