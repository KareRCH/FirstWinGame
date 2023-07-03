#pragma once

#include "Character/Character_NetBattle.h"

template<typename T>
class CBattleUnit_Factory
{
private:
	CBattleUnit_Factory() {}
	~CBattleUnit_Factory() {}

public:
	static T* Create()
	{
		CCharacter_NetBattle* pObj = new T;
		pObj->Initialize();

		return static_cast<T*>(pObj);
	}

	static T* Create(float _fX, float _fY)
	{
		CCharacter_NetBattle* pObj = new T;
		pObj->Set_Pos(_fX, _fY);
		pObj->Initialize();

		return static_cast<T*>(pObj);
	}

	static T* Create(float _fX, float _fY, float _fCX, float _fCY)
	{
		CCharacter_NetBattle* pObj = new T;
		pObj->Set_Pos(_fX, _fY);
		pObj->Set_Size(_fCX, _fCY);
		pObj->Initialize();

		return static_cast<T*>(pObj);
	}

	static T* Create(INFO tInfo)
	{
		CCharacter_NetBattle* pObj = new T;
		pObj->Set_Pos(tInfo.fX, tInfo.fY);
		pObj->Set_Size(tInfo.fCX, tInfo.fCY);
		pObj->Initialize();

		return static_cast<T*>(pObj);
	}

	static T* Create(INFO tInfo, CVector2<int> vecDir)
	{
		CCharacter_NetBattle* pObj = new T;
		pObj->Set_Pos(tInfo.fX, tInfo.fY);
		pObj->Set_Size(tInfo.fCX, tInfo.fCY);
		pObj->Set_Direction(vecDir);
		pObj->Initialize();

		return static_cast<T*>(pObj);
	}
};

