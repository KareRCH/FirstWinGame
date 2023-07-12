#pragma once

#include "Define.h"

class FEnemyData_ForTable
{
public:
	FEnemyData_ForTable() : sName(), iID(), iHP(), iAttack() {}
	~FEnemyData_ForTable() {}

public:
	const TCHAR* sName;
	int iID;
	// 체력
	int iHP;
	// 공격력
	int iAttack;
};

/*
* [문자열 검색 지원]
*/

class CEnemyDataTable
{
private:
	CEnemyDataTable() {}
	~CEnemyDataTable() {}
	CEnemyDataTable(const CEnemyDataTable& _rhs) = delete;

private:
	void Initialize();
	void Release();

private:
	static CEnemyDataTable* g_pInstance;
	static int iID_Count;

public:
	static CEnemyDataTable* Get_Instance()
	{
		if (!g_pInstance)
		{
			g_pInstance = new CEnemyDataTable;
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
	map<int, FEnemyData_ForTable>	m_mapTable;

public:
	void Add_Enemy(const TCHAR* sName, int&& iHP, int&& iAttack)
	{
		FEnemyData_ForTable tEnemy = FEnemyData_ForTable();
		tEnemy.iHP = iHP;
		tEnemy.iAttack = iAttack;
		tEnemy.iID = iID_Count;
		tEnemy.sName = sName;
		m_mapTable.emplace(iID_Count++, tEnemy);
	}

	/*FEnemyData_ForTable Get_EnemyData(const TCHAR* sName)
	{
		auto iter = find_if(m_mapTable.begin(), m_mapTable.end(), [&sName](auto& Pair) {
			return (!lstrcmp(Pair.first, sName));
			});

		if (iter != m_mapTable.end())
		{
			return (*iter).second;
		}
		return FEnemyData_ForTable();
	}*/

	FEnemyData_ForTable Get_EnemyData(int&& iID)
	{
		auto iter = find_if(m_mapTable.begin(), m_mapTable.end(), [&iID](auto& Pair) {
			return (Pair.first == iID);
			});

		if (iter != m_mapTable.end())
		{
			return (*iter).second;
		}

		return FEnemyData_ForTable();
	}
};

