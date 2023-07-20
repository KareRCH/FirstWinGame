#include "Spell_AirShot.h"

#include "ObjMgr.h"
#include "BmpMgr.h"
#include "SoundMgr.h"
#include "VecCollisionMgr.h"

#include "Character/Character_NetBattle.h"
#include "Battle/BattleUnit_Factory.h"
#include <VFX/Vfx_ExplosionVector.h>
#include <VFX/Vfx_ExplosionNormal.h>

void CSpell_AirShot::Initialize(void)
{
	CSpell::Initialize_Spell();

	// 현재 좌표 박스로 조정하기
	m_vecBox = CVector3<float>(8.f, 8.f, 4.f);
	m_vecBoxPos = CVector3<float>(0.f, 0.f, 0.f);
	m_vecSpeed = CVector3<float>(39.f, 0.f, 0.f);

	CSoundMgr::Get_Instance()->Play_Sound(const_cast<TCHAR*>(L"spreader.wav"), SOUND_VFX, 1.f);
}

int CSpell_AirShot::Update(float fDeltaTime)
{

	return 0;
}

void CSpell_AirShot::Late_Update(float fDeltaTime)
{
	m_vecPos.x += (float)m_vecDirection.x * m_vecSpeed.x;

	// 충돌 처리
	CVecCollisionMgr::Collision_Box(CObjMgr::Get_Instance()->Get_ObjList(UNIT), this);

	CCharacter_NetBattle::Info_Update();
}

void CSpell_AirShot::Render(HDC hDC)
{
	//CBmpMgr::Get_Instance()->Draw_Text_Circle_Vec3(hDC, m_vecPos, 10);
}

void CSpell_AirShot::Release(void)
{

}

void CSpell_AirShot::Collide(CObj* _pDst)
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
			Set_Dead();

			CBattleUnit_Factory<CVfx_ExplosionNormal>::Create(TEAM_GAMMA, (m_vecPos + CVector3<float>(float(rand() % 8) - 4.f, float(rand() % 8) - 4.f, 0.f)), CVector2<int>(1, 1));
		}
	}
}
