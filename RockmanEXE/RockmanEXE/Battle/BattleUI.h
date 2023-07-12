#pragma once

#include "Define.h"

#include "Manager/ChipDataTable.h"

class CBattleUI
{
public:
	enum class STATE { OPENING, OPENED, CLOSING, CLOSED };
	enum class STATE_CROSS { OPENING, CLOSING, OPENED, CLOSED };
	enum class STATE_CUSTOM { VISIBLE, INVISIBLE };
	enum class STATE_BATTLE_START { VISIBLE, INVISIBLE };
	enum class STATE_BATTLE_END { VISIBLE, INVISIBLE };
	enum class STATE_CURSOR { NONE, CHIP, OK, CROSS, BEAST };

	enum class ANIM_KEY { CURSOR };

	enum class CHIP_SELECT { NONE, ABLE, SELECTED, DISABLED };

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
	
	void Move_Frame();
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

private: // UI ��ġ�� ��ǥ
	INFO			m_tInfo = {};							// pet�� ��ġ�� �����ϱ� ���� ����, ���� ��ǥ
	array<INFO, 8>	m_tChip_Info = array<INFO, 8>();		// Ĩ �������� ��ġ�� �����ϱ� ���� ����
	INFO			m_tChipPortray_Info = {};				// Ĩ�� �ʻ�ȭ ��ġ�� �����ϱ� ���� ����
	INFO			m_tChipEquip_Info = {};
	INFO			m_tOK_Info = {};						// OK ��ǥ ����

	INFO			m_tCustom_Info = {};					// Ŀ����
	GAUGE<float>	m_fCustom_Gauge = GAUGE<float>();		// Ŀ���� ������

	INFO			m_tCursor_Info = {};					// ���� Ŀ�� ��ġ, ũ�� ������
	INFO			m_tBattleStart_Info = {};				// ��Ʋ ���� �޽��� ��ġ
	GAUGE<float>	m_fBattleStart_Time = GAUGE<float>(1.f);	// 
	INFO			m_tBattleEnd_Info = {};
	GAUGE<float>	m_fBattleEnd_Time = GAUGE<float>(1.f);


	bool m_bInitBattle = true;								// ó�� �������� �� ���� UI�� �־� ����Ѵ�.

private: // ���¸ӽ�
	STATE_INFO<STATE>				m_tState;
	STATE_INFO<STATE_CROSS>			m_tState_Cross;
	STATE_INFO<STATE_CUSTOM>		m_tState_Custom;		// Ŀ���� ������ ���̱� ������ �ʱ�
	STATE_INFO<STATE_BATTLE_START>	m_tState_BattleStart;	// ��Ʋ ���� UI ���� ��
	STATE_INFO<STATE_BATTLE_END>	m_tState_BattlEnd;		// ��Ʋ �� UI ���� ��
	STATE_INFO<STATE_CURSOR>		m_tState_Cursor;		// Ŀ�� UI

private:


private: // �ִϸ��̼�
	map<ANIM_KEY, pair<const TCHAR*, FRAME>>	m_mapFrame;	// �ִϸ��̼� Ű �� map
public:
	bool						Add_Frame(ANIM_KEY eAnim, const TCHAR* sKey) { return m_mapFrame.emplace(eAnim, pair<const TCHAR*, FRAME>(sKey, FRAME())).second; }
	pair<const TCHAR*, FRAME>*	Get_Frame(ANIM_KEY eAnim) { return &m_mapFrame[eAnim]; }
	void						Set_FrameKey(ANIM_KEY eAnim, const TCHAR* sKey) { m_mapFrame[eAnim].first = sKey; }
	const TCHAR*				Get_FrameKey(ANIM_KEY eAnim) { return m_mapFrame[eAnim].first; }
	FRAME						Get_FrameData(ANIM_KEY eAnim) { return m_mapFrame[eAnim].second; }

private:
	void State_Update(float fDeltaTime);

public:
	// ��Ʋ�Ŵ�����
	void Set_State_PetUI(STATE eState) { m_tState.Reserve_State(eState); }
	void Set_State_BattleStartUI(STATE_BATTLE_START eState) { m_tState_BattleStart.Set_State(eState); }
	void Set_State_BattleEndUI(STATE_BATTLE_END eState) { m_tState_BattlEnd.Set_State(eState); }
	void Set_State_Custom(STATE_CUSTOM eState) { m_tState_Custom.Set_State(eState); }

private:
	vector<pair<FChipData_ForBattle, CHIP_SELECT>>		m_LoadedChip_List;			// �ε�� Ĩ, bool�� ���õǾ�����
	vector<FChipData_ForBattle*>						m_EquipChip_List;			// ���� Ĩ
	const int											m_iMax_EquipChip = 5;		// �ִ� ���۰��� Ĩ ����
	int													m_iCursorChip = 0;			// ���� �������� Ĩ

public:
	void Set_LoadedChip_List(vector<FChipData_ForBattle>* value) 
	{
		for (auto item : *value)
		{
			m_LoadedChip_List.push_back(pair<FChipData_ForBattle, CHIP_SELECT>(item, CHIP_SELECT::ABLE));
		}
	}

private:
	int		m_iPlayerHP = 0;	// �÷��̾� ���� HP ǥ��

public:
	void Set_PlayerHP(int value) { m_iPlayerHP = value; }
};

