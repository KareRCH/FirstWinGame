#pragma once


#include "Character/Character_QuaterView.h"

template<typename T>
class CQuaterViewUnit_Factory
{
private:
	CQuaterViewUnit_Factory() {}
	~CQuaterViewUnit_Factory() {}

public:
	static T* Create(CVector3<float> vecPos, CVector2<int> vecDir)
	{
		CCharacter_QuaterView* pObj = new T;
		pObj->Set_VecPos(vecPos);
		pObj->Set_Direction(vecDir);
		pObj->Initialize();

		return static_cast<T*>(pObj);
	}

	static T* Create(CVector3<float> vecPos, CVector2<int> vecDir, CVector3<float> vecBox)
	{
		CCharacter_QuaterView* pObj = new T;
		pObj->Set_VecPos(vecPos);
		pObj->Set_Box(vecBox);
		pObj->Set_Direction(vecDir);
		pObj->Initialize();

		return static_cast<T*>(pObj);
	}

	static T* Create(CVector3<float> vecPos, CVector2<int> vecDir, CVector3<float> vecBox, CVector3<float> vecBoxPos)
	{
		CCharacter_QuaterView* pObj = new T;
		pObj->Set_VecPos(vecPos);
		pObj->Set_Box(vecBox);
		pObj->Set_Direction(vecDir);
		pObj->Initialize();

		return static_cast<T*>(pObj);
	}
};

