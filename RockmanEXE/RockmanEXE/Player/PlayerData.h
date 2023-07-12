#pragma once

#include "Define.h"

#include "Data/ChipData.h"
#include "Data/EncountDataTable.h"
/*
* 플레이어 데이터 클래스는 전역적인 플레이어의 데이터를 저장하는 클래스입니다.
* 칩 폴더, 월드 맵 위치와 같이 씬을 오가면서 사용할 수 있도록 데이터를 쌓아둡니다.
*/

class CPlayerData final
{
private:
	CPlayerData() { m_vecPlayerPos = CVector3<float>(232.f, 602.f, 0.f); }
	~CPlayerData() {}
	CPlayerData(const CPlayerData& _rhs) = delete;

private:
	void Initialize();
	void Release();

private:
	static CPlayerData* g_pInstance;

public:
	static CPlayerData* Get_Instance()
	{
		if (!g_pInstance)
		{
			g_pInstance = new CPlayerData;
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
	}

private: // 인벤토리
	vector<FChipData_ForFolder>		m_Folder_List;		// [칩 폴더]
	list<FChipData_ForPack>			m_Pack_List;		// [칩 인벤토리]
	// [저장 데이터]
	
public:
	void FolderChip_Create(int iID, ECHIP_CODE eCode);
	vector<FChipData_ForFolder>* Get_FolderDataList() { return &m_Folder_List; }

private:
	// [플레이어 위치]
	CVector3<float>	m_vecPlayerPos;
	// [플레이어 방향]
	CVector2<int> m_vecPlayerDir;
	// [플레이어가 위치하는 씬 정보]
	SCENEID m_eScene = SC_WORLD1;

private: // 엔카운트 데이터
	FEncountData_ForTable m_EncountData;

public:
	void Set_PlayerPos(CVector3<float> value) { m_vecPlayerPos = value; }
	CVector3<float> Get_PlayerPos() { return m_vecPlayerPos; }

	void Set_PlayerDir(CVector2<int> value) { m_vecPlayerDir = value; }
	CVector2<int> Get_PlayerDir() { return m_vecPlayerDir; }

	void Set_PlayerScene(SCENEID value) { m_eScene = value; }
	SCENEID Get_PlayerScene() { return m_eScene; }

	void Set_EncountData(FEncountData_ForTable value) { m_EncountData = value; }
	FEncountData_ForTable* Get_EncountData() { return &m_EncountData; }
};

