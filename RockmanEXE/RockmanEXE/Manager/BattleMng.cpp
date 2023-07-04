#include "BattleMng.h"

#include "Battle/BattleUnit_Factory.h"
#include "Navi/Navi_Rockman.h"

CBattleMng* CBattleMng::m_pInstance = nullptr;

void CBattleMng::Initialize()
{
#pragma region 상태 머신
	m_fnState_Map.emplace(STATE::READY_FOR_GAME, &CBattleMng::ReadyForGame);
	m_fnState_Map.emplace(STATE::CHIP_SELECT, &CBattleMng::ChipSelect);
	m_fnState_Map.emplace(STATE::PRE_BATTLE, &CBattleMng::PreBattle);
	m_fnState_Map.emplace(STATE::BATTLE_START, &CBattleMng::BattleStart);
	m_fnState_Map.emplace(STATE::BATTLE_RESULT, &CBattleMng::BattleResult);
	m_fnState_Map.emplace(STATE::BATTLE_END, &CBattleMng::BattleEnd);
#pragma endregion

	m_tState.Set_State(STATE::READY_FOR_GAME);

	
}

void CBattleMng::Release()
{
	// 판넬 데이터를 해제한다.
	for (auto iterVector = m_vvPanel_List.begin(); iterVector != m_vvPanel_List.end();)
	{
		for (auto iterPanel = (*iterVector).begin(); iterPanel != (*iterVector).end();)
		{
			Safe_Delete(*iterPanel);
			iterPanel = (*iterVector).erase(iterPanel);
		}
		iterVector = m_vvPanel_List.erase(iterVector);
	}
}

void CBattleMng::Update(float fDeltaTime)
{
	m_fnState_Map[m_tState.eState](this, fDeltaTime);

	// 판넬
	for (auto& row : m_vvPanel_List)
	{
		for (auto& col : row)
			col->Update(fDeltaTime);
	}
}

void CBattleMng::Late_Update(float fDeltaTime)
{
	// 판넬
	for (auto& row : m_vvPanel_List)
	{
		for (auto& col : row)
			col->Late_Update(fDeltaTime);
	}
}

void CBattleMng::Render(HDC hDC)
{
	// 판넬
	for (auto& row : m_vvPanel_List)
	{
		for (auto& col : row)
			col->Render(hDC);
	}
}



void CBattleMng::ReadyForGame(float fDeltaTime)
{
	// 배틀 시작시 플레이어의 데이터, 적의 데이터 등을 받아 생성하는 작업을 한다.
	
	// 단 한번만 이뤄진다.
	if (m_tState.IsState_Entered())
	{
		// 판넬 생성
		m_vvPanel_List.resize(BATTLE_PANEL_ROW);
		for (int row = 0; row < BATTLE_PANEL_ROW; ++row)
		{
			m_vvPanel_List.resize(BATTLE_PANEL_COL);
			for (int col = 0; col < BATTLE_PANEL_COL; ++col)
			{
				INFO t = { 
					(float)(47 + (PANEL_CROW * col)), 
					(float)(134 + (PANEL_CCOL * row)), 
					(float)PANEL_CROW, 
					(float)PANEL_CCOL 
				};
				m_vvPanel_List[row].push_back(CPanelFactory::Create(t));
			}
		}

		// 플레이어 생성
		CNavi_Rockman* pCreated = CBattleUnit_Factory<CNavi_Rockman>::Create(
			{ m_vvPanel_List[1][1]->Get_Info().fX, m_vvPanel_List[1][1]->Get_Info().fY - 23.f, 30.f, 20.f},
			CVector2<int>(1, 1)
		);
	}
	
	m_tState.Set_State(STATE::CHIP_SELECT);

	if (m_tState.IsState_Exit())
	{

	}
}

void CBattleMng::ChipSelect(float fDeltaTime)
{
	// 플레이어가 칩을 선택하는, 턴에 해당하는 상태이다.
	if (m_tState.IsState_Entered())
	{

	}


	if (m_tState.IsState_Exit())
	{

	}
}

void CBattleMng::PreBattle(float fDeltaTime)
{
	// 턴이 시작하면 선택한 칩이나, 크로스, 유니온에 따라 사전 준비를 한다.
	if (m_tState.IsState_Entered())
	{

	}

	if (m_tState.IsState_Exit())
	{

	}
}

void CBattleMng::BattleStart(float fDeltaTime)
{
	// 배틀을 시작한다. 게이지를 차오르도록 만든다.
	if (m_tState.IsState_Entered())
	{

	}

	if (m_tState.IsState_Exit())
	{

	}
}

void CBattleMng::BattleResult(float fDeltaTime)
{
	// 배틀 종료 후 결과 표시
	if (m_tState.IsState_Entered())
	{

	}

	if (m_tState.IsState_Exit())
	{

	}
}

void CBattleMng::BattleEnd(float fDeltaTime)
{
	// 모든걸 종료하고 원래 있던 곳으로 돌아간다.
	if (m_tState.IsState_Entered())
	{

	}

	if (m_tState.IsState_Exit())
	{

	}
}
