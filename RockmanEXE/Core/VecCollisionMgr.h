#pragma once

#include "Define.h"

#include "Character/Character_NetBattle.h"

/*
* ���͸� Ȱ���� �浹ó���� ���� �ٷ�� Ŭ�����Դϴ�.
* �浹������ ���� ���� ��ü���� �޾� ������ݴϴ�.
*/

class CVecCollisionMgr
{
private:
	CVecCollisionMgr() = delete;
	CVecCollisionMgr(const CVecCollisionMgr& rhs) = delete;
	~CVecCollisionMgr() = delete;

public: // ��ü ����Ʈ�� ���� �浹 ������ �ϴ� �Լ�
	// Src�� ���� ������ ���ϴ� ��� ���� CObj ����Ʈ�� ���� �浹 ������ �Ѵ�.
	static list<CObj*> Collision_Box(list<CObj*>* Dst, CObj* Src);
};

template <typename T>
class CVecCollisionMgr_Check
{
private:
	CVecCollisionMgr_Check() = delete;
	CVecCollisionMgr_Check(const CVecCollisionMgr_Check& rhs) = delete;
	~CVecCollisionMgr_Check() = delete;

public: // �� ����� �־� �浹������ �ϴ� �Լ�
	static bool Check_LineToBox(CVecBox<T> Dst, CVecLine3<T> Src);			// ���� �ڽ� �浹�Դϴ�.
	static bool Check_Box(CVecBox<T> Dst, CVecBox<T> Src);					// AABB ����Դϴ�.
	static bool Check_OrientedBox(CVecBox<T> Dst, CVecBox<T> Src);			// OBB ����Դϴ�.
	static bool Check_Sphere(CVecSphere<T> DstPos, CVecSphere<T> SrcPos);	// �� �浹�Դϴ�.
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
	// Scr�� Dst
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