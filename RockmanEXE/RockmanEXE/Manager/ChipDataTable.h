#pragma once

#include "Define.h"

#include "Data/ChipData.h"

/*
* int 인덱스 검색 지원
*/

class CChipDataTable final
{
private:
	CChipDataTable() {}
	~CChipDataTable() {}
	CChipDataTable(const CChipDataTable& _rhs) = delete;

private:
	void Initialize();
	void Release();

private:
	static CChipDataTable* g_pInstance;
	static int iID_Count;

public:
	static CChipDataTable* Get_Instance()
	{
		if (!g_pInstance)
		{
			g_pInstance = new CChipDataTable;
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
	map<int, FChipData_ForTable*> m_StandardTable_Map;
	map<int, FChipData_ForTable*> m_MegaTable_Map;
	map<int, FChipData_ForTable*> m_GigaTable_Map;

	void Create_ChipData(const TCHAR* sName, const TCHAR* sDescription,
						int iDamage, EATTRIBUTE eAttribute, 
						array<ECHIP_CODE, 5> arrAppearingCode,
						ECHIP_RARITY eRarity, ECHIP_CLASS eClass)
	{
		FChipData_ForTable* pNewData = new FChipData_ForTable();

		if (pNewData)
		{
			switch (eClass)
			{
			case ECHIP_CLASS::STANDARD:
				m_StandardTable_Map.emplace(iID_Count, pNewData);
				break;
			case ECHIP_CLASS::MEGA:
				m_MegaTable_Map.emplace(iID_Count, pNewData);
				break;
			case ECHIP_CLASS::GIGA:
				m_GigaTable_Map.emplace(iID_Count, pNewData);
				break;
			}
			
			pNewData->iID = iID_Count++;
			pNewData->sName = sName;
			pNewData->sDescription = sDescription;

			pNewData->iDamage = iDamage;
			pNewData->eAttribute = eAttribute;
			pNewData->arrAppearingCode = arrAppearingCode;

			pNewData->eRarity = eRarity;
			pNewData->eClass = eClass;
		}
	}

private:
	void Load_ChipImage();

public:
	FChipData_ForFolder Get_ChipData_ForFolder(int iID)
	{
		auto iter = find_if(m_StandardTable_Map.begin(), m_StandardTable_Map.end(), [&iID](auto& Pair) {
			return (Pair.first == iID);
			});

		if (iter != m_StandardTable_Map.end())
		{
			FChipData_ForFolder tChip;

			tChip.iID = (*iter).second->iID;
			tChip.iDamage = (*iter).second->iDamage;
			tChip.sName = (*iter).second->sName;
			tChip.sDescription = (*iter).second->sDescription;
			tChip.eAttribute = (*iter).second->eAttribute;

			return tChip;
		}

		return FChipData_ForFolder();
	}
};

