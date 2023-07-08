#pragma once

#include "Spell/Spell.h"
#include "Manager/BattleMng.h"

template<typename T>
class CBattleSpell_Factory
{
private:
	CBattleSpell_Factory() {}
	~CBattleSpell_Factory() {}

public:
	inline static T* Create()
	{
		CSpell* pObj = new T();

		CBattleMng::Get_Instance()->Add_BattleObject(pObj);

		return static_cast<T*>(pObj);
	}

	inline static T* Create(TEAM_ID iTeam, CVector3<float> vecPos, CVector2<int> vecDir)
	{
		CSpell* pObj = new T();
		pObj->Set_VecPos(vecPos);
		pObj->Set_Direction(vecDir);
		pObj->Set_TeamID((int)iTeam);
		pObj->Initialize();

		CBattleMng::Get_Instance()->Add_BattleObject(pObj);

		return static_cast<T*>(pObj);
	}

};
