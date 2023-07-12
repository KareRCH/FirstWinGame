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

private: // UI 배치용 좌표
	INFO			m_tInfo = {};							// pet의 위치를 조정하기 위해 쓰임, 기준 좌표
	array<INFO, 8>	m_tChip_Info = array<INFO, 8>();		// 칩 아이콘의 위치를 조정하기 위해 쓰임
	INFO			m_tChipPortray_Info = {};				// 칩의 초상화 위치를 조정하기 위해 쓰임
	INFO			m_tChipEquip_Info = {};
	INFO			m_tOK_Info = {};						// OK 좌표 정보

	INFO			m_tCustom_Info = {};					// 커스텀
	GAUGE<float>	m_fCustom_Gauge = GAUGE<float>();		// 커스텀 게이지

	INFO			m_tCursor_Info = {};					// 선택 커서 위치, 크기 조정용
	INFO			m_tBattleStart_Info = {};				// 배틀 시작 메시지 위치
	GAUGE<float>	m_fBattleStart_Time = GAUGE<float>(1.f);	// 
	INFO			m_tBattleEnd_Info = {};
	GAUGE<float>	m_fBattleEnd_Time = GAUGE<float>(1.f);


	bool m_bInitBattle = true;								// 처음 진입했을 때 띄우는 UI가 있어 사용한다.

private: // 상태머신
	STATE_INFO<STATE>				m_tState;
	STATE_INFO<STATE_CROSS>			m_tState_Cross;
	STATE_INFO<STATE_CUSTOM>		m_tState_Custom;		// 커스텀 게이지 보이기 보이지 않기
	STATE_INFO<STATE_BATTLE_START>	m_tState_BattleStart;	// 배틀 시작 UI 띄우기 용
	STATE_INFO<STATE_BATTLE_END>	m_tState_BattlEnd;		// 배틀 끝 UI 띄우기 용
	STATE_INFO<STATE_CURSOR>		m_tState_Cursor;		// 커서 UI

private:


private: // 애니메이션
	map<ANIM_KEY, pair<const TCHAR*, FRAME>>	m_mapFrame;	// 애니메이션 키 용 map
public:
	bool						Add_Frame(ANIM_KEY eAnim, const TCHAR* sKey) { return m_mapFrame.emplace(eAnim, pair<const TCHAR*, FRAME>(sKey, FRAME())).second; }
	pair<const TCHAR*, FRAME>*	Get_Frame(ANIM_KEY eAnim) { return &m_mapFrame[eAnim]; }
	void						Set_FrameKey(ANIM_KEY eAnim, const TCHAR* sKey) { m_mapFrame[eAnim].first = sKey; }
	const TCHAR*				Get_FrameKey(ANIM_KEY eAnim) { return m_mapFrame[eAnim].first; }
	FRAME						Get_FrameData(ANIM_KEY eAnim) { return m_mapFrame[eAnim].second; }

private:
	void State_Update(float fDeltaTime);

public:
	// 배틀매니저용
	void Set_State_PetUI(STATE eState) { m_tState.Reserve_State(eState); }
	void Set_State_BattleStartUI(STATE_BATTLE_START eState) { m_tState_BattleStart.Set_State(eState); }
	void Set_State_BattleEndUI(STATE_BATTLE_END eState) { m_tState_BattlEnd.Set_State(eState); }
	void Set_State_Custom(STATE_CUSTOM eState) { m_tState_Custom.Set_State(eState); }

private:
	vector<pair<FChipData_ForBattle, CHIP_SELECT>>		m_LoadedChip_List;			// 로드된 칩, bool은 선택되었는지
	vector<FChipData_ForBattle*>						m_EquipChip_List;			// 장착 칩
	const int											m_iMax_EquipChip = 5;		// 최대 장작가능 칩 개수
	int													m_iCursorChip = 0;			// 현재 선택중인 칩

public:
	void Set_LoadedChip_List(vector<FChipData_ForBattle>* value) 
	{
		for (auto item : *value)
		{
			m_LoadedChip_List.push_back(pair<FChipData_ForBattle, CHIP_SELECT>(item, CHIP_SELECT::ABLE));
		}
	}

private:
	int		m_iPlayerHP = 0;	// 플레이어 현재 HP 표시

public:
	void Set_PlayerHP(int value) { m_iPlayerHP = value; }
};

