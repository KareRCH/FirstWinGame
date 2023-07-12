#pragma once

#include "Define.h"

#include "Battle/Panel.h"
#include "Battle/BattleUI.h"
#include "Manager/ChipDataTable.h"

#define MAX_CHIP_COUNT 8

/*
* ��Ʋ�� ���� ���������� �����ϴ� Ŭ����
* �÷��̾��� ������ �޾ƿ��� �� ����� �ǽð� ���� ����, �� ����� �����Ѵ�.
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
		// ó�� ���� �غ� ���� ��
		READY_FOR_GAME, 
		// Ĩ �������� �Ѿ ��
		CHIP_SELECT,
		// ���� ���� ��, ����, ���� Ǯ���� ���� ��
		PRE_BATTLE,
		// �ǽð� ���� ����
		BATTLE_START, 
		// ������
		BATTLE_PROCESS,
		// ���� ��� ��ǥ
		BATTLE_RESULT,
		// ���� ����, 
		BATTLE_END, 
		// ���� ����
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

private: // ���������� ���̴� ����
	MAP_FUNC<STATE, void(CBattleMng*, float)>		m_fnState_Map;

	STATE_INFO<STATE>		m_tState = STATE_INFO<STATE>();

public:
	void Set_State(STATE eState) { m_tState.Reserve_State(eState); }

private: // ���� �غ� ����
	// �г� ���帮��Ʈ
	vector<vector<CPanel*>>			m_vvPanel_List;					// �г� ���� ����Ʈ
	list<FChipData_ForBattle>		m_ChipData_List;				// �÷��̾��� Ĩ ������ ����
	vector<FChipData_ForBattle>		m_LoadedChip_List;				// �Ͽ� �ε�� Ĩ ����Ʈ
	int								m_iLoadedChip_Count;			// ���� �ε��� �� �ִ� Ĩ�� ����

	DELAY<float>	m_fBattle_Pre_Delay = DELAY<float>(0.5f);
	DELAY<float>	m_fBattle_Start_Delay = DELAY<float>(1.5f);		// ��Ʋ ���۽� ������
	DELAY<float>	m_fEnemy_Appear_Delay = DELAY<float>(0.5f);

private: // �� ����
	int				m_iTurn = 1;								// ���� 1���� �����Ѵ�.
	DELAY<float>	m_fTurn_Gauge = DELAY<float>(10.f);			// ���� �⺻�� 10�ʷ� ��´�.
	bool			m_bTurnGauge_Sound = false;					//

public:
	DELAY<float>	Get_TurnGauge() { return m_fTurn_Gauge; }

private: // ���� ��� ����
	bool			m_bBusting_Success = false;					// ���� ���� �� ������ ���� ����
	DELAY<float>	m_fBattleEnd_Delay = DELAY<float>(2.f);		// ���� ������ ��� ��� ������

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
	// �׽�Ʈ�� Ĩ �ε� �Լ�
	void Test_LoadChip();
	void Test_CreateChip(int iID, int iDamage, EATTRIBUTE eAttribute, ECHIP_CODE eCode);
	void Chip_LoadByFolder();
	void Chip_Shuffle();
	void Chip_LoadCount();
	void Chip_Equip();
};

