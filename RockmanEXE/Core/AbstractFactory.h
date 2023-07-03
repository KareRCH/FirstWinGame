#pragma once

#include "Obj.h"

template<typename T>
class CAbstractFactory
{
private:
	CAbstractFactory(){}
	~CAbstractFactory(){}

public:
	static T*		Create()
	{
		T*		pObj = new T;
		pObj->Initialize();

		return static_cast<T*>(pObj);
	}

	static T*		Create(float _fX, float _fY)
	{
		T*		pObj = new T;
		pObj->Set_Pos(_fX, _fY);
		pObj->Initialize();

		return static_cast<T*>(pObj);
	}

	static T* Create(float _fX, float _fY, float _fCX, float _fCY)
	{
		T* pObj = new T;
		pObj->Set_Pos(_fX, _fY);
		pObj->Set_Size(_fCX, _fCY);
		pObj->Initialize();

		return static_cast<T*>(pObj);
	}

	static T* Create(INFO tInfo)
	{
		T* pObj = new T;
		pObj->Set_Pos(tInfo.fX, tInfo.fY);
		pObj->Set_Size(tInfo.fCX, tInfo.fCY);
		pObj->Initialize();

		return static_cast<T*>(pObj);
	}

};

