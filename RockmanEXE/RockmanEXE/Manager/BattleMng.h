#pragma once

#include "Define.h"

/*
* ��Ʋ�� ���� ���������� �����ϴ� Ŭ����
* �÷��̾��� ������ �޾ƿ��� �� ����� �ǽð� ���� ����, �� ����� �����Ѵ�.
*/

class CBattleMng
{
private:
	CBattleMng() {}
	~CBattleMng() { Release(); }
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
		// ���� ��� ��ǥ
		BATTLE_RESULT,
		// ���� ����, 
		BATTLE_END, 
		// ���� ����
		STATE_END
	};

public:
	void Initialize();
	void Update(float fDeltaTime);
	void Late_Update(float fDeltaTime);
	void Release();

private:
	static CBattleMng* m_pInstance;

public:
	static CBattleMng* Get_Instance()
	{
		if (!m_pInstance)
		{
			m_pInstance = new CBattleMng;
		}

		return m_pInstance;
	}
	static void		Destroy_Instance()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

private: // ���������� ���̴� ����
	map<STATE, function<void(CBattleMng&, float)>>		m_fnState_Map;

	bool							m_bIsEnterdState = false;
	STATE							m_eState = STATE::READY_FOR_GAME;

public:
	void Set_State(STATE _eState)
	{
		m_eState = _eState;
		m_bIsEnterdState = true;
	}

private: // ���� �غ� ����
	

private: // �� ����
	int				m_iTurn = 1;								// ���� 1���� �����Ѵ�.
	DELAY<float>	m_fTurn_Gauge = DELAY<float>(10.f);			// ���� �⺻�� 10�ʷ� ��´�.

private: // ���� ��� ����
	bool			m_bBusting_Success = false;					// ���� ���� �� ������ ���� ����
	DELAY<float>	m_fBattleEnd_Delay = DELAY<float>(10.f);	// ���� ������


private:
	void ReadyForGame(float fDeltaTime);
	void ChipSelect(float fDeltaTime);
	void PreBattle(float fDeltaTime);
	void BattleStart(float fDeltaTime);
	void BattleResult(float fDeltaTime);
	void BattleEnd(float fDeltaTime);
};

