#pragma once

#include "Character/Character_NetBattle.h"
#include "Manager/BattleMng.h"

template<typename T>
class CBattleUnit_Factory
{
private:
	CBattleUnit_Factory() {}
	~CBattleUnit_Factory() {}

public:
	static T* Create(TEAM_ID iTeam, CVector3<float> vecPos, CVector2<int> vecDir)
	{
		CCharacter_NetBattle* pObj = new T;
		pObj->Set_VecPos(vecPos);
		pObj->Set_Direction(vecDir);
		pObj->Set_TeamID(iTeam);
		pObj->Initialize();

		CBattleMng::Get_Instance()->Add_BattleObject(pObj);

		return static_cast<T*>(pObj);
	}

	static T* Create(TEAM_ID iTeam, CVector3<float> vecPos, CVector2<int> vecDir, CVector3<float> vecBox)
	{
		CCharacter_NetBattle* pObj = new T;
		pObj->Set_VecPos(vecPos);
		pObj->Set_Box(vecBox);
		pObj->Set_Direction(vecDir);
		pObj->Set_TeamID(iTeam);
		pObj->Initialize();

		CBattleMng::Get_Instance()->Add_BattleObject(pObj);

		return static_cast<T*>(pObj);
	}

	static T* Create(TEAM_ID iTeam, CVector3<float> vecPos, CVector2<int> vecDir, CVector3<float> vecBox, CVector3<float> vecBoxPos)
	{
		CCharacter_NetBattle* pObj = new T;
		pObj->Set_VecPos(vecPos);
		pObj->Set_Box(vecBox);
		pObj->Set_Direction(vecDir);
		pObj->Set_TeamID(iTeam);
		pObj->Initialize();

		CBattleMng::Get_Instance()->Add_BattleObject(pObj);

		return static_cast<T*>(pObj);
	}
};

