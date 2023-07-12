#pragma once

#include "Define.h"

#include "Battle/Panel.h"

/*
* 엔카운트시 등장하는 적에 대한 가장 작은 단위의 데이터
*/

class FEncountEnemy_ForTable final
{
public:
	FEncountEnemy_ForTable() : iID() {}
	~FEncountEnemy_ForTable() {}
public:
	int	iID;					// 적 ID
	CVector2<int>	vecPanel;	// 적의 등장 위치
};

/*
* 엔카운트시 배치되는 오브젝트 정보
*/

class FEncountObject_ForTable final
{
public:
	FEncountObject_ForTable() : iID() {}
	~FEncountObject_ForTable() {}
public:
	int iID;					// 오브젝트 ID
	CVector2<int>	vecPanel;	// 오브젝트 등장 위치
};

/*
* 판넬 정보
*/

class FEncountPanel_ForTable final
{
public:
	FEncountPanel_ForTable() : ePanel_Color(), ePanel_Type() {}
	~FEncountPanel_ForTable() {}
public:
	CPanel::PNL_STATE	ePanel_Type;	// 판넬 타입
	CPanel::PNL_COLOR	ePanel_Color;	// 판넬 색
};


class FEncountData_ForTable final
{
public:
	FEncountData_ForTable() {}
	~FEncountData_ForTable() {}
public:
	vector<FEncountEnemy_ForTable>		vEnemy;		// 맵에 배치될 적
	vector<FEncountObject_ForTable>		vObject;	// 맵에 배치될 오브젝트
	vector<FEncountPanel_ForTable>		vPanel;		// 맵에 배치될 판넬 정보, 행 단위로 만든다.
};

/*
* [int 인덱스 검색 지원]
*/
class CEncountDataTable
{
private:
	CEncountDataTable() {}
	~CEncountDataTable() {}
	CEncountDataTable(const CEncountDataTable& _rhs) = delete;

private:
	void Initialize();
	void Release();

private:
	static CEncountDataTable* g_pInstance;
	static int iID_Count;

public:
	static CEncountDataTable* Get_Instance()
	{
		if (!g_pInstance)
		{
			g_pInstance = new CEncountDataTable;
			g_pInstance->Initialize();
		}

		return g_pInstance;
	}
	static void		Destroy_Instance()
	{
		if (g_pInstance)
		{
			g_pInstance->Release();
			delete g_pInstance;
			g_pInstance = nullptr;
		}
		iID_Count = 0;
	}

private:
	map<int, FEncountData_ForTable>	m_mapTable;

public:
	int Add_Data(int iID)
	{
		auto iter = m_mapTable.find(iID);
		if (iter == m_mapTable.end())
			m_mapTable.emplace(iID, FEncountData_ForTable());

		return iID;
	}

	// 적 추가
	void Add_Enemy(int iID, int iEnemyID, CVector2<int> vecPanel)
	{
		FEncountEnemy_ForTable tTemp = FEncountEnemy_ForTable();
		tTemp.iID = iEnemyID;
		tTemp.vecPanel = vecPanel;
		m_mapTable[iID].vEnemy.push_back(tTemp);
	}

	void Add_Object(int iID, int iObjectID, CVector2<int> vecPanel)
	{
		FEncountObject_ForTable tTemp = FEncountObject_ForTable();
		tTemp.iID = iObjectID;
		tTemp.vecPanel = vecPanel;
		m_mapTable[iID].vObject.push_back(tTemp);
	}

	// 노멀로다가 때려박기
	void Add_Panel_Preset1(int iID)
	{
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 6; ++j)
			{
				FEncountPanel_ForTable tTemp = FEncountPanel_ForTable();
				if (j < 3)
					tTemp.ePanel_Color = CPanel::PNL_RED;
				else
					tTemp.ePanel_Color = CPanel::PNL_BLUE;
				tTemp.ePanel_Type = CPanel::PNL_STATE::NORMAL;
				m_mapTable[iID].vPanel.push_back(tTemp);
			}
		}
	}

	// 데이터 복사 받기
	FEncountData_ForTable Get_Data(int iID)
	{
		auto iter = find_if(m_mapTable.begin(), m_mapTable.end(), [&iID](auto Pair) {
			return (Pair.first == iID);
			});

		if (iter != m_mapTable.end())
			return (*iter).second;

		return FEncountData_ForTable();
	}
};

