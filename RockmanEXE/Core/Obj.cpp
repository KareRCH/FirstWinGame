#include "Obj.h"

CObj::CObj() : m_eDir(DIR_END), m_bDead(false)
{
	ZeroMemory(&m_tInfo, sizeof(m_tInfo));
	ZeroMemory(&m_tRect, sizeof(m_tRect));
}

CObj::~CObj()
{
}

void CObj::Update_Rect()
{
	m_tRect.left = LONG(m_tInfo.fX - (m_tInfo.fCX * 0.5f));
	m_tRect.top = LONG(m_tInfo.fY - (m_tInfo.fCY * 0.5f));
	m_tRect.right = LONG(m_tInfo.fX + (m_tInfo.fCX * 0.5f));
	m_tRect.bottom = LONG(m_tInfo.fY + (m_tInfo.fCY * 0.5f));
}

void CObj::Move_Frame()
{
	for (auto iter = m_vFrame.begin(); iter != m_vFrame.end(); ++iter)
	{
		auto& tFrame = (*iter).second;
		if (tFrame.ulTime + tFrame.ulSpeed < GetTickCount64())
		{
			++tFrame.iFrameCur;

			if (tFrame.iFrameCur > tFrame.iFrameEnd)
				tFrame.iFrameCur = tFrame.iFrameStart;

			tFrame.ulTime = GetTickCount64();
		}
	}
}
