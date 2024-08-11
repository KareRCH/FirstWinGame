#include "Spell_ChargeBuster.h"

#include "BmpMgr.h"
#include "Battle/Panel.h"
#include "VecCollisionMgr.h"
#include "ObjMgr.h"

#include "SoundMgr.h"

#include "Character/Character_NetBattle.h"
#include "Battle/BattleUnit_Factory.h"
#include "VFX/Vfx_BusterHit.h"
#include "VFX/Vfx_ChargeShotHit.h"

void CSpell_ChargeBuster::Initialize(void)
{
	CSpell::Initialize_Spell();

	// ���� ��ǥ �ڽ��� �����ϱ�
	m_vecBox = CVector3<float>(8.f, 8.f, 4.f);
	m_vecBoxPos = CVector3<float>(0.f, 0.f, 0.f);
	m_vecSpeed = CVector3<float>(39.f, 0.f, 0.f);
	
	CSoundMgr::Get_Instance()->Play_Sound(const_cast<TCHAR*>(L"pew.wav"), SOUND_VFX, 1.f);
}

int CSpell_ChargeBuster::Update(float fDeltaTime)
{

	return 0;
}

void CSpell_ChargeBuster::Late_Update(float fDeltaTime)
{
	m_vecPos.x += (float)m_vecDirection.x * m_vecSpeed.x;

	// �浹 ó��
	CVecCollisionMgr::Collision_Box(CObjMgr::Get_Instance()->Get_ObjList(UNIT), this);

	CCharacter_NetBattle::Info_Update();
}

void CSpell_ChargeBuster::Render(HDC hDC)
{
	//CBmpMgr::Get_Instance()->Draw_Text_Circle_Vec3(hDC, m_vecPos);
}

void CSpell_ChargeBuster::Release(void)
{
}

void CSpell_ChargeBuster::Collide(CObj* _pDst)
{
	// ���ݿ� ������ ������� �ش�.
	CCharacter_NetBattle* pChr = dynamic_cast<CCharacter_NetBattle*>(_pDst);
	if (pChr && Get_Owner() != pChr
		&& ERELATION_STATE::HOSTILE == ITeamAgent::Check_Relation(pChr, this))
	{
		if (!pChr->Get_Invincible())
		{
			pChr->Set_HP(pChr->Get_HP().Cur - m_iAttack);
			pChr->Collide(this);
			Set_Dead();

			CBattleUnit_Factory<CVfx_ChargeShotHit>::Create(TEAM_GAMMA, (m_vecPos + CVector3<float>(float(rand() % 4), float(rand() % 4), 0.f)), CVector2<int>(1, 1));
		}
	}
}