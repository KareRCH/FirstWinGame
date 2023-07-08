#pragma once

#include "Define.h"

#include "Character/Character_NetBattle.h"

/*
* 벡터를 활용한 충돌처리에 대해 다루는 클래스입니다.
* 충돌범위를 비교할 물리 객체만을 받아 계산해줍니다.
*/

class CVecCollisionMgr
{
private:
	CVecCollisionMgr() = delete;
	CVecCollisionMgr(const CVecCollisionMgr& rhs) = delete;
	~CVecCollisionMgr() = delete;

public: // 전체 리스트를 통해 충돌 판정을 하는 함수
	// Src로 부터 판정을 원하는 대상에 대한 CObj 리스트에 대해 충돌 판정을 한다.
	static list<CObj*> Collision_Box(list<CObj*>* Dst, CObj* Src);
};

template <typename T>
class CVecCollisionMgr_Check
{
private:
	CVecCollisionMgr_Check() = delete;
	CVecCollisionMgr_Check(const CVecCollisionMgr_Check& rhs) = delete;
	~CVecCollisionMgr_Check() = delete;

public: // 비교 대상을 넣어 충돌검출을 하는 함수
	static bool Check_LineToBox(CVecBox<T> Dst, CVecLine3<T> Src);			// 선과 박스 충돌입니다.
	static bool Check_Box(CVecBox<T> Dst, CVecBox<T> Src);					// AABB 방식입니다.
	static bool Check_OrientedBox(CVecBox<T> Dst, CVecBox<T> Src);			// OBB 방식입니다.
	static bool Check_Sphere(CVecSphere<T> DstPos, CVecSphere<T> SrcPos);	// 구 충돌입니다.
};

template<typename T>
inline bool CVecCollisionMgr_Check<T>::Check_LineToBox(CVecBox<T> Dst, CVecLine3<T> Src)
{

	return false;
}

template<typename T>
inline bool CVecCollisionMgr_Check<T>::Check_Box(CVecBox<T> Dst, CVecBox<T> Src)
{
	bool bX(false), bY(false), bZ(false);
	// Scr대 Dst
	if (Dst.left <= Src.right && Dst.right >= Src.left)
	{
		bX = true;
	}
	if (Dst.down <= Src.up && Dst.up >= Src.down)
	{
		bY = true;
	}
	if (Dst.bottom <= Src.top && Dst.top >= Src.bottom)
	{
		bZ = true;
	}

	return (bX && bY && bZ);
}

template<typename T>
bool CVecCollisionMgr_Check<T>::Check_OrientedBox(CVecBox<T> Dst, CVecBox<T> Src)
{

	return false;
}

template<typename T>
inline bool CVecCollisionMgr_Check<T>::Check_Sphere(CVecSphere<T> DstPos, CVecSphere<T> SrcPos)
{

	return false;
}