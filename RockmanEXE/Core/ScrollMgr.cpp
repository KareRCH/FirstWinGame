#include "ScrollMgr.h"

#include "ObjMgr.h"
#include "Character/Character_QuaterView.h"

CScrollMgr*	CScrollMgr::m_pInstance = nullptr;

CScrollMgr::CScrollMgr()
	: m_fScrollX(0.f), m_fScrollY(0.f), m_iLockX(0), m_iLockY(0)
{
}


CScrollMgr::~CScrollMgr()
{

}

void CScrollMgr::Scroll_Lock()
{
	auto pList = CObjMgr::Get_Instance()->Get_ObjListAll();
	bool bIsTarget_Exits = false;
	for (int i = 0; i < OBJID_END; ++i)
	{
		auto& item = pList[i];
		auto iter = find_if(item.begin(), item.end(), [this] (CObj* pObj) {
			return (pObj == m_pLockOn_Obj);
			});

		if (iter != item.end())
			bIsTarget_Exits = true;
	}
	if (!bIsTarget_Exits)
		m_pLockOn_Obj = nullptr;

	if (m_pLockOn_Obj)
	{
		CCharacter_QuaterView* pObjDy = dynamic_cast<CCharacter_QuaterView*>(m_pLockOn_Obj);
		if (pObjDy)
		{
			m_fScrollX = pObjDy->Get_VecPos().x - (float)(ROCKMAN_EXECX / 2);
			m_fScrollY = pObjDy->Get_VecPos().y - (float)(ROCKMAN_EXECY / 2);
		}
	}

	if (0.f > m_fScrollX)
		m_fScrollX = 0.f;

	if (0.f > m_fScrollY)
		m_fScrollY = 0.f;


	if (m_fScrollX > m_iLockX - ROCKMAN_EXECX)
		m_fScrollX = (float)(m_iLockX - ROCKMAN_EXECX);
	
	if (m_fScrollY > m_iLockY - ROCKMAN_EXECY)
		m_fScrollY = (float)(m_iLockY - ROCKMAN_EXECY);


	if (!m_fShaking.Update(0.06f))
	{
		m_fScrollX = float((rand() % 10)) - 5.f;
		m_fScrollY = float((rand() % 10)) - 5.f;
	}
}
