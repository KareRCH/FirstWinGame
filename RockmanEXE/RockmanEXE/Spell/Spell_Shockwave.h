#pragma once

#include "Spell/Spell.h"

#include "Manager/BattleMng.h"

class CSpell_Shockwave : public CSpell
{
public:
	enum class ACTION_KEY : int { MOVED, DIE, MAX };
public:
	CSpell_Shockwave() {}
	virtual ~CSpell_Shockwave() {}

public:
	// CSpell을(를) 통해 상속됨
	virtual void Initialize(void) override;
	virtual int Update(float fDeltaTime) override;
	virtual void Late_Update(float fDeltaTime) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	virtual void Collide(CObj* _pDst) override;

private:
	DELAY<float>	m_tMove_Delay;

public:
	void Set_MoveDelay(DELAY<float> value) { m_tMove_Delay = value; }

private:
	MAP_ACTION<ACTION_KEY>	m_mapAction;
};

// CSpell_Shockwave_Factory::Create((TEAM_ID)Get_TeamID(), m_vecPos, m_vecDirection, 5.f, 0.75f);
class CSpell_Shockwave_Factory
{
private:
	CSpell_Shockwave_Factory() = delete;
	CSpell_Shockwave_Factory(const CSpell_Shockwave_Factory& rhs) = delete;
	~CSpell_Shockwave_Factory() = delete;

public:
	static CSpell_Shockwave* Create(TEAM_ID iTeam, CVector3<float> vecPos, CVector2<int> vecDir, float fSpeed, float fDelay, int iDamage)
	{
		CSpell_Shockwave* pObj = new CSpell_Shockwave;
		pObj->Set_VecPos(vecPos);
		pObj->Set_Direction(vecDir);
		pObj->Set_Speed(CVector3<float>(fSpeed, 0.f, 0.f));
		pObj->Set_MoveDelay(DELAY<float>(fDelay));
		pObj->Set_TeamID(iTeam);
		pObj->Set_Attack(iDamage);
		pObj->Initialize();

		CBattleMng::Get_Instance()->Add_BattleObject(pObj);

		return static_cast<CSpell_Shockwave*>(pObj);
	}
};