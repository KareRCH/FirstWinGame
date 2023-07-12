#pragma once

#include "Scene.h"

#include "Data/EncountDataTable.h"

class CScene_Net_Area abstract : public CScene
{
public:
	CScene_Net_Area() {}
	virtual ~CScene_Net_Area() {}

public:
	virtual void		Initialize()					PURE;
	virtual void		Update(float fDeltaTime)	    PURE;
	virtual void		Late_Update(float fDeltaTime)	PURE;
	virtual void		Render(HDC hDC)					PURE;
	virtual void		Release()						PURE;

protected: // 애니메이션
	pair<const TCHAR*, FRAME>	m_pairFrame;	// 애니메이션 키 용 map
public:
	void						Add_Frame(const TCHAR* sKey) { m_pairFrame = pair<const TCHAR*, FRAME>(sKey, FRAME()); }
	pair<const TCHAR*, FRAME>*	Get_Frame() { return &m_pairFrame; }
	void						Set_FrameKey(const TCHAR* sKey) { m_pairFrame.first = sKey; }
	const TCHAR*				Get_FrameKey() { return m_pairFrame.first; }
	FRAME						Get_FrameData() { return m_pairFrame.second; }

public:
	void Move_Frame()
	{
		auto& tFrame = m_pairFrame.second;
		tFrame.ulCurTime = GetTickCount64();
		if (tFrame.ulTime + tFrame.ulSpeed < tFrame.ulCurTime)
		{
			++tFrame.iFrameCur;

			if (tFrame.iFrameCur > tFrame.iFrameEnd)
			{
				if (tFrame.bLoop)
					tFrame.iFrameCur = 0;
				else
					tFrame.iFrameCur = tFrame.iFrameEnd;
			}

			tFrame.ulTime = tFrame.ulCurTime;
		}
	}

protected: // 엔카운트 데이터
	vector<FEncountData_ForTable> m_vEncountData;

public:
	vector<FEncountData_ForTable>* Get_EncountData() { return &m_vEncountData; }
	FEncountData_ForTable	Get_RandomEncount() 
	{ 
		if (m_vEncountData.empty())
			return FEncountData_ForTable();

		return m_vEncountData[rand() % (int)m_vEncountData.size()];
	}
};

