#include "VecCollisionMgr.h"

list<CObj*> CVecCollisionMgr::Collision_Box(list<CObj*>* Dst, CObj* Src)
{
	CCharacter_NetBattle* pSrc = dynamic_cast<CCharacter_NetBattle*>(Src);
	if (!pSrc) { return list<CObj*>(); }

	list<CObj*> resultList = list<CObj*>();

	for (auto pObj : *Dst)
	{
		CCharacter_NetBattle* pDst = dynamic_cast<CCharacter_NetBattle*>(pObj);

		if (!pDst) { continue; }

		if (CVecCollisionMgr_Check<float>::Check_Box(pDst->Get_BoxArea(), pSrc->Get_BoxArea()))
		{
			resultList.push_back(pDst);
		}
	}

	for (auto& pDst : resultList)
	{
		pSrc->Collide(pDst);
	}

	return resultList;
}


