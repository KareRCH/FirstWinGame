#include "Spell_Buster.h"

#include "BmpMgr.h"
#include "Battle/Panel.h"
#include "VecCollisionMgr.h"
#include "ObjMgr.h"

#include "SoundMgr.h"

#include "Character/Character_NetBattle.h"

void CSpell_Buster::Initialize(void)
{
	CSpell::Initialize_Spell();

	// 현재 좌표 박스로 조정하기
	m_vecBox = CVector3<float>(8.f, 8.f, 4.f);
	m_vecBoxPos = CVector3<float>(0.f, 0.f, 0.f);
	m_vecSpeed = CVector3<float>(39.f, 0.f, 0.f);

	m_iAttack = 1;

	CSoundMgr::Get_Instance()->Play_Sound(const_cast<TCHAR *>(L"pew.wav"), SOUND_EFFECT, 1.f);
}

int CSpell_Buster::Update(float fDeltaTime)
{
	
	return 0;
}

void CSpell_Buster::Late_Update(float fDeltaTime)
{
	m_vecPos.x += (float)m_vecDirection.x * m_vecSpeed.x;

	// 충돌 처리
	CVecCollisionMgr::Collision_Box(CObjMgr::Get_Instance()->Get_ObjList(UNIT), this);
}

void CSpell_Buster::Render(HDC hDC)
{
	CBmpMgr::Get_Instance()->Draw_Text_Circle_Vec3(hDC, m_vecPos);
}

void CSpell_Buster::Release(void)
{
}

void CSpell_Buster::Collide(CObj* _pDst)
{
	// 공격용 유닛은 대미지를 준다.
	CCharacter_NetBattle* pChr= dynamic_cast<CCharacter_NetBattle*>(_pDst);
	if (pChr && Get_Owner() != pChr 
		&& ERELATION_STATE::HOSTILE == ITeamAgent::Check_Relation(pChr, this))
	{
		if (!pChr->Get_Invincible())
		{
			pChr->Set_HP(pChr->Get_HP().Cur - m_iAttack);
			pChr->Collide(this);
			Set_Dead();
		}
	}
}
