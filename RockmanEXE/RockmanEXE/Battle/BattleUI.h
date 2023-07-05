#pragma once

#include "Define.h"

#include "Manager/ChipDataTable.h"

class CBattleUI
{
public:
	enum STATE { OPENING, OPENED, CLOSING, CLOSED };
	enum STATE_CROSS { CROSS_OPENING, CROSS_CLOSING, CROSS_OPENED, CROSS_CLOSED };

private:
	CBattleUI() {}
	~CBattleUI() {}
	CBattleUI(const CBattleUI& _rhs) = delete;

private:
	void Initialize();
	void Release();

public:
	void Update(float fDeltaTime);
	void Late_Update(float fDeltaTime);
	void Render(HDC hDC);
	

private:
	static CBattleUI* m_pInstance;

public:
	static CBattleUI* Get_Instance()
	{
		if (!m_pInstance)
		{
			m_pInstance = new CBattleUI;
			m_pInstance->Initialize();
		}

		return m_pInstance;
	}
	static void		Destroy_Instance()
	{
		if (m_pInstance)
		{
			m_pInstance->Release();
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

private:
	// pet�� ��ġ�� �����ϱ� ���� ����
	INFO	m_tInfo = {};

private:
	STATE_INFO<STATE>	m_tState;
	STATE_INFO<STATE_CROSS>	m_tState_Cross;
	bool m_bInitBattle = true;	// ó�� �������� �� ���� UI�� �־� ����Ѵ�.

private:
	void State_Update(float fDeltaTime);

public:
	// ��Ʋ�Ŵ�����
	void Set_PetUI_State(STATE eState)
	{
		m_tState.Set_State(eState);
	}

private:
	vector<FChipData_ForBattle>		m_LoadedChip_List;

public:
	void Set_LoadedChip_List(vector<FChipData_ForBattle>* value) { m_LoadedChip_List =  *value; }
};

