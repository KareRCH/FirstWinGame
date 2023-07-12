#pragma once

#include "Define.h"

#include "Battle/Panel.h"
#include "Battle/BattleUI.h"
#include "Manager/ChipDataTable.h"

#define MAX_CHIP_COUNT 8

/*
* 배틀에 관해 여러가지를 관리하는 클래스
* 플레이어의 정보를 받아오고 턴 진행과 실시간 전투 진행, 및 결과를 전달한다.
*/

class CBattleMng
{
private:
	CBattleMng() : m_iLoadedChip_Count(5){}
	~CBattleMng() {}
	CBattleMng(const CBattleMng& _rhs) = delete;

public:
	enum STATE 
	{ 
		// 처음 게임 준비 중일 때
		READY_FOR_GAME, 
		// 칩 선택으로 넘어갈 때
		CHIP_SELECT,
		// 사전 전투 턴, 변신, 변신 풀림과 같은 턴
		PRE_BATTLE,
		// 실시간 전투 시작
		BATTLE_START, 
		// 전투중
		BATTLE_PROCESS,
		// 전투 결과 발표
		BATTLE_RESULT,
		// 전투 종료, 
		BATTLE_END, 
		// 끝의 숫자
		STATE_END
	};

private:
	void Initialize();
	void Release();

public:
	void Update(float fDeltaTime);
	void Late_Update(float fDeltaTime);
	void Render(HDC hDC);
	

private:
	static CBattleMng* m_pInstance;

public:
	static CBattleMng* Get_Instance()
	{
		if (!m_pInstance)
		{
			m_pInstance = new CBattleMng;
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

private: // 전역적으로 쓰이는 변수
	MAP_FUNC<STATE, void(CBattleMng*, float)>		m_fnState_Map;

	STATE_INFO<STATE>		m_tState = STATE_INFO<STATE>();

public:
	void Set_State(STATE eState) { m_tState.Reserve_State(eState); }

private: // 게임 준비 관련
	// 패널 저장리스트
	vector<vector<CPanel*>>			m_vvPanel_List;					// 패널 저장 리스트
	list<FChipData_ForBattle>		m_ChipData_List;				// 플레이어의 칩 정보를 저장
	vector<FChipData_ForBattle>		m_LoadedChip_List;				// 턴에 로드된 칩 리스트
	int								m_iLoadedChip_Count;			// 현재 로드할 수 있는 칩의 개수

	DELAY<float>	m_fBattle_Pre_Delay = DELAY<float>(0.5f);
	DELAY<float>	m_fBattle_Start_Delay = DELAY<float>(1.5f);		// 배틀 시작시 딜레이
	DELAY<float>	m_fEnemy_Appear_Delay = DELAY<float>(0.5f);

private: // 턴 관련
	int				m_iTurn = 1;								// 턴은 1부터 시작한다.
	DELAY<float>	m_fTurn_Gauge = DELAY<float>(10.f);			// 턴의 기본을 10초로 잡는다.
	bool			m_bTurnGauge_Sound = false;					//

public:
	DELAY<float>	Get_TurnGauge() { return m_fTurn_Gauge; }

private: // 게임 결과 관련
	bool			m_bBusting_Success = false;					// 게임 종료 후 버스팅 성공 유무
	DELAY<float>	m_fBattleEnd_Delay = DELAY<float>(2.f);		// 턴이 끝나고 결과 출력 딜레이

private:
	void ReadyForGame(float fDeltaTime);
	void ChipSelect(float fDeltaTime);
	void PreBattle(float fDeltaTime);
	void BattleStart(float fDeltaTime);
	void BattleProcess(float fDeltaTime);
	void BattleResult(float fDeltaTime);
	void BattleEnd(float fDeltaTime);


private:
	list<CCharacter_NetBattle*>		m_BattleObjList;
	list<CCharacter_NetBattle*>		m_EnemyList;
	vector<wstring>					m_EnemyNameList;
	CBattleUI*						m_pBattleUI = nullptr;

	bool m_bAll_Enemy_Created = false;

public:
	void Add_BattleObject(CCharacter_NetBattle* pObj)
	{
		m_BattleObjList.push_back(pObj);
	}

public:
	void Enemy_Deleted(CCharacter_NetBattle* pSrc)
	{
		auto iter = find_if(m_EnemyList.begin(), m_EnemyList.end(), [&pSrc](CCharacter_NetBattle* pDst) {
			return (pSrc == pDst);
			});

		if (iter != m_EnemyList.end())
			m_EnemyList.erase(iter);
	}

	vector<wstring>* Get_EnemyNameList()
	{
		return &m_EnemyNameList;
	}


private:
	// 테스트용 칩 로드 함수
	void Test_LoadChip();
	void Test_CreateChip(int iID, int iDamage, EATTRIBUTE eAttribute, ECHIP_CODE eCode);
	void Chip_LoadByFolder();
	void Chip_Shuffle();
	void Chip_LoadCount();
	void Chip_Equip();
};

