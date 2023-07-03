#pragma once

#include "Define.h"

#include "Battle/Panel.h"

/*
* 배틀에 관해 여러가지를 관리하는 클래스
* 플레이어의 정보를 받아오고 턴 진행과 실시간 전투 진행, 및 결과를 전달한다.
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
		// 처음 게임 준비 중일 때
		READY_FOR_GAME, 
		// 칩 선택으로 넘어갈 때
		CHIP_SELECT,
		// 사전 전투 턴, 변신, 변신 풀림과 같은 턴
		PRE_BATTLE,
		// 실시간 전투 시작
		BATTLE_START, 
		// 전투 결과 발표
		BATTLE_RESULT,
		// 전투 종료, 
		BATTLE_END, 
		// 끝의 숫자
		STATE_END
	};

public:
	void Initialize();
	void Update(float fDeltaTime);
	void Late_Update(float fDeltaTime);
	void Render(HDC hDC);
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

private: // 전역적으로 쓰이는 변수
	map<STATE, function<void(CBattleMng*, float)>>		m_fnState_Map;

	STATE_INFO<STATE>		m_tState = STATE_INFO<STATE>();

private: // 게임 준비 관련
	vector<vector<CPanel*>>		m_vvPanel_List;

private: // 턴 관련
	int				m_iTurn = 1;								// 턴은 1부터 시작한다.
	DELAY<float>	m_fTurn_Gauge = DELAY<float>(10.f);			// 턴의 기본을 10초로 잡는다.

private: // 게임 결과 관련
	bool			m_bBusting_Success = false;					// 게임 종료 후 버스팅 성공 유무
	DELAY<float>	m_fBattleEnd_Delay = DELAY<float>(10.f);	// 턴이 끝나고


private:
	void ReadyForGame(float fDeltaTime);
	void ChipSelect(float fDeltaTime);
	void PreBattle(float fDeltaTime);
	void BattleStart(float fDeltaTime);
	void BattleResult(float fDeltaTime);
	void BattleEnd(float fDeltaTime);
};

