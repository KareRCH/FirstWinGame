#include "Spell_Shockwave.h"

#include "BmpMgr.h"
#include "SoundMgr.h"
#include "Manager/AnimationTable.h"
#include <VecCollisionMgr.h>

void CSpell_Shockwave::Initialize(void)
{
	CSpell::Initialize_Spell();

	// ���� ��ǥ �ڽ��� �����ϱ�
	m_vecBox = CVector3<float>(15.f, 10.f, 16.f);
	m_vecBoxPos = CVector3<float>(0.f, 0.f, 0.f);
	m_vecSpeed = CVector3<float>(39.f, 0.f, 0.f);
	m_vecPos.z -= 8.f;

#pragma region �̹��� �߰�
	TCHAR sText[100];
	const TCHAR* sCharacterDir = L"./RockmanEXE/Resource/battle/navi/spell/shockwave/";
	lstrcpy(sText, sCharacterDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"vfx_shockwave.png"), L"NBT_Spell_Shockwave");

	Set_FrameKey(0, L"NBT_Spell_Shockwave");
	CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
	
	for (int i = 0; i < (int)ACTION_KEY::MAX; ++i)
		m_mapAction.emplace((ACTION_KEY)i, ACTION());
}

int CSpell_Shockwave::Update(float fDeltaTime)
{
	if (Get_Frame(0).IsFrameEnd() && m_mapAction[ACTION_KEY::DIE].IsOnAct())
	{
		Set_Dead();
	}

	for_each(m_mapAction.begin(), m_mapAction.end(), CMapAction_Updator<ACTION_KEY>());
	__super::Move_Frame();

	return 0;
}

void CSpell_Shockwave::Late_Update(float fDeltaTime)
{
	// �浹 ó��
	CVecCollisionMgr::Collision_Box(CObjMgr::Get_Instance()->Get_ObjList(UNIT), this);

	// ���� �������� �ǳ�ó���� �����.
	auto vecTemp = m_vecPos;
	m_vecPos.x += m_vecSpeed.x * (float)m_vecDirection.x;
	auto tPanel = CVecCollisionMgr::Collision_Box(CObjMgr::Get_Instance()->Get_ObjList(PANEL), this);
	m_vecPos = vecTemp;

	if (tPanel.empty() && Get_Frame(0).IsFrameTick(Get_Frame(0).iFrameEnd))
	{
		m_mapAction[ACTION_KEY::DIE].Act();
		m_bIsVisible = false;
	}
	
	// �����̿� ���� ������ �������� �̵��Ѵ�.
	if (Get_Frame(0).IsFrameTick(Get_Frame(0).iFrameEnd))
	{
		Get_Frame(0).iFrameCur = 0;
		m_vecPos.x += m_vecSpeed.x * (float)m_vecDirection.x;
		//CSoundMgr::Get_Instance()->Play_Sound(L"");
	}

	CCharacter_NetBattle::Info_Update();
}

void CSpell_Shockwave::Render(HDC hDC)
{
	CBmpMgr::Get_Instance()->Draw_PNG_Strip(hDC, Get_FrameKey(0), Get_Frame(0), m_vecPos, m_vecDirection);
	
}

void CSpell_Shockwave::Release(void)
{

}

void CSpell_Shockwave::Collide(CObj* _pDst)
{
	// ���ݿ� ������ ������� �ش�.
	CCharacter_NetBattle* pChr = dynamic_cast<CCharacter_NetBattle*>(_pDst);
	if (pChr
		&& Get_Owner() != pChr
		&& ERELATION_STATE::HOSTILE == ITeamAgent::Check_Relation(pChr, this))
	{
		if (!pChr->Get_Invincible())
		{
			pChr->Set_HP(pChr->Get_HP().Cur - m_iAttack);
			pChr->Collide(this);
		}
	}

	/*CCharacter_NetBattle* pChr = dynamic_cast<CCharacter_NetBattle*>(_pDst);
	if (pChr
		&& Get_Owner() != pChr
		&& ERELATION_STATE::HOSTILE == ITeamAgent::Check_Relation(pChr, this))
	{
		pChr->Set_HP(pChr->Get_HP().Cur - m_iAttack);
		pChr->Collide(this);
	}*/
}
