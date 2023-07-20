#include "Spell_Sword.h"

#include "ObjMgr.h"
#include "BmpMgr.h"
#include "SoundMgr.h"
#include "VecCollisionMgr.h"

#include "Character/Character_NetBattle.h"
#include "Battle/BattleUnit_Factory.h"
#include <VFX/Vfx_ExplosionVector.h>
#include <VFX/Vfx_ExplosionNormal.h>
#include <Manager/AnimationTable.h>

void CSpell_Sword::Initialize(void)
{
	CSpell::Initialize_Spell();

	// 현재 좌표 박스로 조정하기
	m_vecBox = CVector3<float>(8.f, 8.f, 16.f);
	m_vecBoxPos = CVector3<float>(0.f, 0.f, 0.f);
	m_vecSpeed = CVector3<float>(0.f, 0.f, 0.f);

#pragma region 이미지 추가
	wstring sText = L"./RockmanEXE/Resource/battle/navi/spell/sword/";
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"basic_sword.png").c_str(), L"NBT_Spell_Sword");

	Set_FrameKey(0, L"NBT_Spell_Sword");
	CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
#pragma endregion

	CSoundMgr::Get_Instance()->Play_Sound(const_cast<TCHAR*>(L"wave.wav"), SOUND_VFX, 1.f);
}

int CSpell_Sword::Update(float fDeltaTime)
{
	if (Get_Frame(0).IsFrameEnd())
		Set_Dead();

	Move_Frame();
	return 0;
}

void CSpell_Sword::Late_Update(float fDeltaTime)
{
	// 충돌 처리
	if (!m_bHit)
	{
		auto list = CVecCollisionMgr::Collision_Box(CObjMgr::Get_Instance()->Get_ObjList(UNIT), this);

		if (!list.empty())
		{
			m_bHit = true;
		}
	}

	CCharacter_NetBattle::Info_Update();
}

void CSpell_Sword::Render(HDC hDC)
{
	CBmpMgr::Get_Instance()->Draw_PNG_Strip(hDC, Get_FrameKey(0), Get_Frame(0), m_vecPos, m_vecDirection);
}

void CSpell_Sword::Release(void)
{

}

void CSpell_Sword::Collide(CObj* _pDst)
{
	// 공격용 유닛은 대미지를 준다.
	CCharacter_NetBattle* pChr = dynamic_cast<CCharacter_NetBattle*>(_pDst);
	if (pChr && Get_Owner() != pChr
		&& ERELATION_STATE::HOSTILE == ITeamAgent::Check_Relation(pChr, this))
	{
		if (!pChr->Get_Invincible())
		{
			pChr->Set_HP(pChr->Get_HP().Cur - m_iAttack);
			pChr->Collide(this);
		}
	}
}