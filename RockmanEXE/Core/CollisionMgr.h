#pragma once

#include "Obj.h"

/*
* INFO ����ü�� ���� �浹ó���� �մϴ�.
*/

class CCollisionMgr
{
private:
	CCollisionMgr() = delete;
	CCollisionMgr(const CCollisionMgr& rhs) = delete;
	~CCollisionMgr() = delete;

public:
	static void	Collision_Rect(list<CObj*> _Dst, list<CObj*> _Src);
	static void	Collision_RectEx(list<CObj*> _Dst, list<CObj*> _Src);
	static bool	Check_Rect(CObj* _Dst, CObj* _Src, float* _pX, float* _pY);


	static void	Collision_Sphere(list<CObj*> _Dst, list<CObj*> _Src);
	static bool	Check_Sphere(CObj* _Dst, CObj* _Src);
};

