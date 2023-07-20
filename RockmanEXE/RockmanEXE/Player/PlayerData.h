#pragma once

#include "Define.h"

#include "Data/ChipData.h"
#include "Data/EncountDataTable.h"
/*
* �÷��̾� ������ Ŭ������ �������� �÷��̾��� �����͸� �����ϴ� Ŭ�����Դϴ�.
* Ĩ ����, ���� �� ��ġ�� ���� ���� �����鼭 ����� �� �ֵ��� �����͸� �׾ƵӴϴ�.
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

private: // �κ��丮
	vector<FChipData_ForFolder>		m_Folder_List;		// [Ĩ ����]
	list<FChipData_ForPack>			m_Pack_List;		// [Ĩ �κ��丮]
	// [���� ������]
	
public:
	void FolderChip_Create(int iID, ECHIP_CODE eCode);
	vector<FChipData_ForFolder>* Get_FolderDataList() { return &m_Folder_List; }

	list<FChipData_ForPack>* Get_PackDataList() { return &m_Pack_List; }

private:
	// [�÷��̾� ��ġ]
	CVector3<float>	m_vecPlayerPos;
	// [�÷��̾� ����]
	CVector2<int> m_vecPlayerDir;
	// [�÷��̾ ��ġ�ϴ� �� ����]
	SCENEID m_eScene = SC_WORLD1;

	// HP, ��
	GAUGE<int>		m_iHP = GAUGE<int>(100, true);
	int				m_iMoney = 3000;

public:
	GAUGE<int> Get_HP() { return m_iHP; }
	int Get_CurHP() { return m_iHP.Cur; }
	void Set_CurHP(int value) { m_iHP.Cur = value; }

	void Set_PlayerMoeny(int value) { m_iMoney = value; }
	int Get_PlayerMoney() { return m_iMoney; }

private: // ��ī��Ʈ ������
	FEncountData_ForTable m_EncountData;
	GAUGE<float>		m_fEncountGauge = GAUGE<float>(10.f);

public:
	void Set_PlayerPos(CVector3<float> value) { m_vecPlayerPos = value; }
	CVector3<float> Get_PlayerPos() { return m_vecPlayerPos; }

	void Set_PlayerDir(CVector2<int> value) { m_vecPlayerDir = value; }
	CVector2<int> Get_PlayerDir() { return m_vecPlayerDir; }

	void Set_PlayerScene(SCENEID value) { m_eScene = value; }
	SCENEID Get_PlayerScene() { return m_eScene; }

	void Set_EncountData(FEncountData_ForTable value) { m_EncountData = value; }
	FEncountData_ForTable* Get_EncountData() { return &m_EncountData; }

	void Update_EncountGauge(float value) { m_fEncountGauge.Update(value); }
	GAUGE<float>* Get_EncountGauge() { return &m_fEncountGauge; }
};

