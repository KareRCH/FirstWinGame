#include "BattleMng.h"

void CBattleMng::Initialize()
{
	m_fnState_Map.emplace(STATE::READY_FOR_GAME, &CBattleMng::ReadyForGame);
	m_fnState_Map.emplace(STATE::CHIP_SELECT, &CBattleMng::ChipSelect);
	m_fnState_Map.emplace(STATE::PRE_BATTLE, &CBattleMng::PreBattle);
	m_fnState_Map.emplace(STATE::BATTLE_START, &CBattleMng::BattleStart);
	m_fnState_Map.emplace(STATE::BATTLE_RESULT, &CBattleMng::BattleResult);
	m_fnState_Map.emplace(STATE::BATTLE_END, &CBattleMng::BattleEnd);
}

void CBattleMng::Update(float fDeltaTime)
{
	m_fnState_Map[m_eState];
}

void CBattleMng::Late_Update(float fDeltaTime)
{

}

void CBattleMng::Release()
{

}

void CBattleMng::ReadyForGame(float fDeltaTime)
{

}

void CBattleMng::ChipSelect(float fDeltaTime)
{

}

void CBattleMng::PreBattle(float fDeltaTime)
{

}

void CBattleMng::BattleStart(float fDeltaTime)
{

}

void CBattleMng::BattleResult(float fDeltaTime)
{

}

void CBattleMng::BattleEnd(float fDeltaTime)
{

}
