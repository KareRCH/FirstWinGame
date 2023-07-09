#pragma once

#include "Spell.h"

#include "Manager/BattleMng.h"

class CSpell_Cannon : public CSpell
{
public:
	CSpell_Cannon() {}
	virtual ~CSpell_Cannon() {}

public:
	// CSpell을(를) 통해 상속됨
	virtual void Initialize(void) override;
	virtual int Update(float fDeltaTime) override;
	virtual void Late_Update(float fDeltaTime) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	virtual void Collide(CObj* _pDst) override;
};

// CSpell_Shockwave_Factory::Create((TEAM_ID)Get_TeamID(), m_vecPos, m_vecDirection, 40);
class CSpell_Cannon_Factory
{
private:
	CSpell_Cannon_Factory() = delete;
	CSpell_Cannon_Factory(const CSpell_Cannon_Factory& rhs) = delete;
	~CSpell_Cannon_Factory() = delete;

public:
	static CSpell_Cannon* Create(CCharacter_NetBattle* pOwner, CVector3<float> vecPos, CVector2<int> vecDir, int iDamage)
	{
		CSpell_Cannon* pObj = new CSpell_Cannon;
		pObj->Set_Owner(pOwner);
		pObj->Set_TeamID((int)pOwner->Get_TeamID());
		pObj->Set_VecPos(vecPos);
		pObj->Set_Direction(vecDir);
		pObj->Set_Attack(iDamage);
		pObj->Initialize();

		CBattleMng::Get_Instance()->Add_BattleObject(pObj);

		return static_cast<CSpell_Cannon*>(pObj);
	}
};