#pragma once

#include "Define.h"

#include "Battle/Panel.h"

/*
* ��ī��Ʈ�� �����ϴ� ���� ���� ���� ���� ������ ������
*/

class FEncountEnemy_ForTable final
{
public:
	FEncountEnemy_ForTable() : iID() {}
	~FEncountEnemy_ForTable() {}
public:
	int	iID;					// �� ID
	CVector2<int>	vecPanel;	// ���� ���� ��ġ
};

/*
* ��ī��Ʈ�� ��ġ�Ǵ� ������Ʈ ����
*/

class FEncountObject_ForTable final
{
public:
	FEncountObject_ForTable() : iID() {}
	~FEncountObject_ForTable() {}
public:
	int iID;					// ������Ʈ ID
	CVector2<int>	vecPanel;	// ������Ʈ ���� ��ġ
};

/*
* �ǳ� ����
*/

class FEncountPanel_ForTable final
{
public:
	FEncountPanel_ForTable() : ePanel_Color(), ePanel_Type() {}
	~FEncountPanel_ForTable() {}
public:
	CPanel::PNL_STATE	ePanel_Type;	// �ǳ� Ÿ��
	CPanel::PNL_COLOR	ePanel_Color;	// �ǳ� ��
};


class FEncountData_ForTable final
{
public:
	FEncountData_ForTable() {}
	~FEncountData_ForTable() {}
public:
	vector<FEncountEnemy_ForTable>		vEnemy;		// �ʿ� ��ġ�� ��
	vector<FEncountObject_ForTable>		vObject;	// �ʿ� ��ġ�� ������Ʈ
	vector<FEncountPanel_ForTable>		vPanel;		// �ʿ� ��ġ�� �ǳ� ����, �� ������ �����.
};

/*
* [int �ε��� �˻� ����]
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

	// �� �߰�
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

	// ��ַδٰ� �����ڱ�
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

	// ������ ���� �ޱ�
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

