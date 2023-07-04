#include "BattleMng.h"

#include "Battle/BattleUnit_Factory.h"
#include "Navi/Navi_Rockman.h"

CBattleMng* CBattleMng::m_pInstance = nullptr;

void CBattleMng::Initialize()
{
#pragma region ���� �ӽ�
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
	// �ǳ� �����͸� �����Ѵ�.
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

	// �ǳ�
	for (auto& row : m_vvPanel_List)
	{
		for (auto& col : row)
			col->Update(fDeltaTime);
	}
}

void CBattleMng::Late_Update(float fDeltaTime)
{
	// �ǳ�
	for (auto& row : m_vvPanel_List)
	{
		for (auto& col : row)
			col->Late_Update(fDeltaTime);
	}
}

void CBattleMng::Render(HDC hDC)
{
	// �ǳ�
	for (auto& row : m_vvPanel_List)
	{
		for (auto& col : row)
			col->Render(hDC);
	}
}



void CBattleMng::ReadyForGame(float fDeltaTime)
{
	// ��Ʋ ���۽� �÷��̾��� ������, ���� ������ ���� �޾� �����ϴ� �۾��� �Ѵ�.
	
	// �� �ѹ��� �̷�����.
	if (m_tState.IsState_Entered())
	{
		// �ǳ� ����
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

		// �÷��̾� ����
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
	// �÷��̾ Ĩ�� �����ϴ�, �Ͽ� �ش��ϴ� �����̴�.
	if (m_tState.IsState_Entered())
	{

	}


	if (m_tState.IsState_Exit())
	{

	}
}

void CBattleMng::PreBattle(float fDeltaTime)
{
	// ���� �����ϸ� ������ Ĩ�̳�, ũ�ν�, ���Ͽ¿� ���� ���� �غ� �Ѵ�.
	if (m_tState.IsState_Entered())
	{

	}

	if (m_tState.IsState_Exit())
	{

	}
}

void CBattleMng::BattleStart(float fDeltaTime)
{
	// ��Ʋ�� �����Ѵ�. �������� ���������� �����.
	if (m_tState.IsState_Entered())
	{

	}

	if (m_tState.IsState_Exit())
	{

	}
}

void CBattleMng::BattleResult(float fDeltaTime)
{
	// ��Ʋ ���� �� ��� ǥ��
	if (m_tState.IsState_Entered())
	{

	}

	if (m_tState.IsState_Exit())
	{

	}
}

void CBattleMng::BattleEnd(float fDeltaTime)
{
	// ���� �����ϰ� ���� �ִ� ������ ���ư���.
	if (m_tState.IsState_Entered())
	{

	}

	if (m_tState.IsState_Exit())
	{

	}
}
