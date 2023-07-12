#pragma once

#include "Define.h"

class FItemData_ForTable
{
public:
	FItemData_ForTable();
	~FItemData_ForTable();

public:
	int iID;
	
};

class CItemDataTable
{
private:
	CItemDataTable() {}
	~CItemDataTable() {}
	CItemDataTable(const CItemDataTable& _rhs) = delete;

private:
	void Initialize();
	void Release();

private:
	static CItemDataTable* g_pInstance;
	static int iID_Count;

public:
	static CItemDataTable* Get_Instance()
	{
		if (!g_pInstance)
		{
			g_pInstance = new CItemDataTable;
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
	map<const TCHAR*, FItemData_ForTable>	m_mapTable;

	void Add_Item()
	{

	}
};

