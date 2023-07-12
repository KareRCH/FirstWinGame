#include "BattleMng.h"

#include "KeyMgr.h"
#include "SoundMgr.h"
#include "SceneMgr.h"

#include "Navi/Navi_Rockman.h"
#include <Virus/Virus_Mettaur.h>
#include "Battle/BattleUnit_Factory.h"
#include <BmpMgr.h>
#include "Scene/Scene_Net_Area.h"
#include "Player/PlayerData.h"
#include "Data/EncountDataTable.h"
#include <Data/EnemyDataTable.h>



CBattleMng* CBattleMng::m_pInstance = nullptr;

void CBattleMng::Initialize()
{

#pragma region 이미지
	TCHAR sText[100];
	const TCHAR* sCharacterDir = L"./RockmanEXE/Resource/battle/ui/";
	lstrcpy(sText, sCharacterDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"hp_numset.png"), L"NBT_Hp_Numset");
#pragma endregion

#pragma region 상태 머신
	m_fnState_Map.emplace(STATE::READY_FOR_GAME, &CBattleMng::ReadyForGame);
	m_fnState_Map.emplace(STATE::CHIP_SELECT, &CBattleMng::ChipSelect);
	m_fnState_Map.emplace(STATE::PRE_BATTLE, &CBattleMng::PreBattle);
	m_fnState_Map.emplace(STATE::BATTLE_PROCESS, &CBattleMng::BattleProcess);
	m_fnState_Map.emplace(STATE::BATTLE_START, &CBattleMng::BattleStart);
	m_fnState_Map.emplace(STATE::BATTLE_RESULT, &CBattleMng::BattleResult);
	m_fnState_Map.emplace(STATE::BATTLE_END, &CBattleMng::BattleEnd);
#pragma endregion

	m_tState.Set_State(STATE::READY_FOR_GAME);

	m_pBattleUI = CBattleUI::Get_Instance();

	m_LoadedChip_List.reserve(MAX_CHIP_COUNT);

	CSoundMgr::Get_Instance()->Play_BGM(const_cast<TCHAR*>(L"loop_battle.mp3"), 1.f);

	m_LoadedChip_List.reserve(8);
}

void CBattleMng::Release()
{
}

void CBattleMng::Update(float fDeltaTime)
{
	m_fnState_Map[m_tState.eState](this, fDeltaTime);
}

void CBattleMng::Late_Update(float fDeltaTime)
{

}

void CBattleMng::Render(HDC hDC)
{

}



void CBattleMng::Transfer_EquipChip(vector<FChipData_ForBattle*>* vChipData)
{
	// 플레이어에게 칩 전달
	if (m_pPlayer)
	{
		auto listChipData = m_pPlayer->Get_ChipData_List();
		listChipData->clear();
		for (auto pChip : *vChipData)
		{
			listChipData->push_back(*pChip);
		}
	}

	for (auto pChip : *vChipData)
	{
		for (auto iter = m_LoadedChip_List.begin(); iter != m_LoadedChip_List.end();)
		{
			if (pChip == &(*iter))
			{
				iter = m_LoadedChip_List.erase(iter);
				break;
			}
			else
				++iter;
		}
	}
}

void CBattleMng::ReadyForGame(float fDeltaTime)
{
	// 배틀 시작시 플레이어의 데이터, 적의 데이터 등을 받아 생성하는 작업을 한다.
	
	// 단 한번만 이뤄진다.
	if (m_tState.IsState_Entered())
	{
		m_fEnemy_Appear_Delay.Reset();
		m_fBattle_Pre_Delay.Reset();


		// 판넬 생성
		m_vvPanel_List.resize(BATTLE_PANEL_ROW);
		for (int row = 0; row < BATTLE_PANEL_ROW; ++row)
		{
			m_vvPanel_List.resize(BATTLE_PANEL_COL);
			for (int col = 0; col < BATTLE_PANEL_COL; ++col)
			{
				CVector3<float> t = CVector3<float>(
					(float)((ROCKMAN_EXECX / 2) - (int)((float)PANEL_CROW * 2.5f) + (PANEL_CROW * col)),
					(float)(118 + (PANEL_CCOL * row)), 0.f
				);
				CPanel* pCreated = CPanelFactory::Create((col < (BATTLE_PANEL_COL / 2)) ? TEAM_ALPHA : TEAM_BETA, t,
					(col < (BATTLE_PANEL_COL / 2)) ? CPanel::PNL_RED : CPanel::PNL_BLUE, 
					(CPanel::PNL_BRIGHTNESS)max((int)CPanel::DARK - row, 0),
					(CPanel::PNL_STATE)(0)
					);
				m_vvPanel_List[row].push_back(pCreated);
				m_BattleObjList.push_back(pCreated);
			}
		}


		// 플레이어 생성
		CVector3<float> vecCreatePos;
		vecCreatePos.x = m_vvPanel_List[1][1]->Get_VecPos().x;
		vecCreatePos.y = m_vvPanel_List[1][1]->Get_VecPos().y;
		CNavi_Rockman* pCreated = CBattleUnit_Factory<CNavi_Rockman>::Create(TEAM_ALPHA, vecCreatePos, CVector2<int>(1, 1));
		m_pPlayer = pCreated;


		// [여기에 로드된 플레이어의 칩 카운트를 넣어주세요]
		if (m_iLoadedChip_Count > MAX_CHIP_COUNT)
			m_iLoadedChip_Count = MAX_CHIP_COUNT;

		// 플레이어 칩 폴더로부터 칩을 로드
		Chip_LoadByFolder();

		// 칩 셔플
		Chip_Shuffle();

		// 엔카운트 데이터 로드 및, UI에 적 이름 전달
		m_EnemyNameList.clear();
		FEncountData_ForTable Encount = *CPlayerData::Get_Instance()->Get_EncountData();

		// 적 생성
		for (int i = 0; i < Encount.vEnemy.size(); ++i)
		{
			vecCreatePos.x = m_vvPanel_List[Encount.vEnemy[i].vecPanel.y][Encount.vEnemy[i].vecPanel.x]->Get_VecPos().x;
			vecCreatePos.y = m_vvPanel_List[Encount.vEnemy[i].vecPanel.y][Encount.vEnemy[i].vecPanel.x]->Get_VecPos().y;
			m_EnemyNameList.push_back(CEnemyDataTable::Get_Instance()->Get_EnemyData(0).sName);
			CCharacter_NetBattle* pEnemy = CBattleUnit_Factory<CVirus_Mettaur>::Create(TEAM_BETA, vecCreatePos, CVector2<int>(-1, 1));
			m_EnemyList.push_back(pEnemy);
			pEnemy->Set_Opacity(0.f);
		}

		// 모든 오브젝트 정지
		for (auto& rObj : m_BattleObjList)
		{
			rObj->Set_Pause();
		}
	}

	// 딜레이를 주며 적을 소환한다.

	if (!m_EnemyList.empty())
	{
		auto iter = m_EnemyList.begin();
		m_fEnemy_Appear_Delay.Reset();

		for (; iter != m_EnemyList.end(); ++iter)
		{
			if ((*iter)->Get_Opacity() < 1.f)
			{
				if ((*iter)->Get_Opacity() == 0.f)
					CSoundMgr::Get_Instance()->Play_Sound(const_cast<TCHAR*>(L"appear.wav"), SYSTEM_EFFECT, 1.f);

				(*iter)->Set_Opacity((*iter)->Get_Opacity() + 0.025f);
				if ((*iter)->Get_Opacity() > 1.f)
					(*iter)->Set_Opacity(1.f);
				
				break;
			}
		}

		if (iter == m_EnemyList.end())
			m_bAll_Enemy_Created = true;
	}

	// 전부 소환함
	if (m_bAll_Enemy_Created)
	{
		if (m_fBattle_Pre_Delay.Update(fDeltaTime))
			m_tState.Set_State(STATE::CHIP_SELECT);
	}

	if (m_tState.IsState_Exit())
	{

	}
}

void CBattleMng::ChipSelect(float fDeltaTime)
{
	// 플레이어가 칩을 선택하는, 턴에 해당하는 상태이다.
	if (m_tState.IsState_Entered())
	{
		for (auto& rObj : m_BattleObjList)
		{
			rObj->Set_Pause();
		}

		// 셔플된 칩 데이터중 Chip_Count만큼 벡터에 넣는다.
		Chip_LoadCount();

		m_fTurn_Gauge.Reset();

		m_pBattleUI->Set_LoadedChip_List(&m_LoadedChip_List);
		m_pBattleUI->Set_State_PetUI(CBattleUI::STATE::OPENING);
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

	m_tState.Set_State(STATE::BATTLE_START);

	if (m_tState.IsState_Exit())
	{

	}
}

void CBattleMng::BattleStart(float fDeltaTime)
{
	// 배틀을 시작한다. 게이지를 차오르도록 만든다.
	if (m_tState.IsState_Entered())
	{
		// 딜레이 초기화
		m_fBattle_Start_Delay.Reset();
		m_pBattleUI->Set_State_BattleStartUI(CBattleUI::STATE_BATTLE_START::VISIBLE);
	}

	if (m_fBattle_Start_Delay.Update(fDeltaTime))
	{
		m_tState.Set_State(STATE::BATTLE_PROCESS);
	}

	if (m_tState.IsState_Exit())
	{
		m_pBattleUI->Set_State_BattleStartUI(CBattleUI::STATE_BATTLE_START::INVISIBLE);
	}
}

void CBattleMng::BattleProcess(float fDeltaTime)
{
	// 배틀을 시작한다. 게이지를 차오르도록 만든다.
	if (m_tState.IsState_Entered())
	{
		for (auto& rObj : m_BattleObjList)
		{
			rObj->Set_Resume();
		}

		m_bTurnGauge_Sound = true;
	}

	
 	if (m_fTurn_Gauge.Update(fDeltaTime))
	{
		if (m_bTurnGauge_Sound)
		{
			CSoundMgr::Get_Instance()->Play_Sound(const_cast<TCHAR*>(L"custom_bar_full.wav"), SYSTEM_EFFECT, 1.f);
			m_bTurnGauge_Sound = false;
		}
		if (CKeyMgr::Get_Instance()->Key_Down(VK_SPACE))
			m_tState.Set_State(STATE::CHIP_SELECT);
	}
	if (m_EnemyList.empty())
	{
		m_tState.Set_State(STATE::BATTLE_RESULT);
	}

	if (m_tState.IsState_Exit())
	{
		m_fTurn_Gauge.Cur = 0.f;
	}
}

void CBattleMng::BattleResult(float fDeltaTime)
{
	// 배틀 종료 후 결과 표시
	if (m_tState.IsState_Entered())
	{
		m_fBattleEnd_Delay.Reset();
		m_pBattleUI->Set_State_BattleEndUI(CBattleUI::STATE_BATTLE_END::VISIBLE);
		m_pBattleUI->Set_State_Custom(CBattleUI::STATE_CUSTOM::INVISIBLE);
		CSoundMgr::Get_Instance()->Play_BGM(const_cast<TCHAR*>(L"enemy_deleted.mp3"), 1.f);
	}

	if (m_tState.Can_Update())
	{
		if (m_fBattleEnd_Delay.Update(fDeltaTime))
		{
			m_tState.Set_State(STATE::BATTLE_END);
		}
	}

	if (m_tState.IsState_Exit())
	{
		m_pBattleUI->Set_State_BattleEndUI(CBattleUI::STATE_BATTLE_END::INVISIBLE);
	}
}

void CBattleMng::BattleEnd(float fDeltaTime)
{
	// 모든걸 종료하고 원래 있던 곳으로 돌아간다.
	if (m_tState.IsState_Entered())
	{
		m_fBattleEnd_Delay.Reset();
	}

	if (m_tState.Can_Update())
	{
		if (m_fBattleEnd_Delay.Update(fDeltaTime))
		{
			CSceneMgr::Get_Instance()->Scene_Change(SC_WORLD1);
		}
	}

	if (m_tState.IsState_Exit())
	{

	}
}

void CBattleMng::Test_LoadChip()
{
	Test_CreateChip(0, 40, EATTRIBUTE::NONE, ECHIP_CODE::A);
	Test_CreateChip(0, 40, EATTRIBUTE::NONE, ECHIP_CODE::A);
	Test_CreateChip(0, 40, EATTRIBUTE::NONE, ECHIP_CODE::B);
	Test_CreateChip(0, 40, EATTRIBUTE::NONE, ECHIP_CODE::B);
	Test_CreateChip(0, 40, EATTRIBUTE::NONE, ECHIP_CODE::C);
	Test_CreateChip(0, 40, EATTRIBUTE::NONE, ECHIP_CODE::C);

	Test_CreateChip(1, 80, EATTRIBUTE::NONE, ECHIP_CODE::D);
	Test_CreateChip(1, 80, EATTRIBUTE::NONE, ECHIP_CODE::D);
	Test_CreateChip(1, 80, EATTRIBUTE::NONE, ECHIP_CODE::E);
	Test_CreateChip(1, 80, EATTRIBUTE::NONE, ECHIP_CODE::E);
	Test_CreateChip(1, 80, EATTRIBUTE::NONE, ECHIP_CODE::F);
	Test_CreateChip(1, 80, EATTRIBUTE::NONE, ECHIP_CODE::WILD_CARD);

	Test_CreateChip(90, 40, EATTRIBUTE::NONE, ECHIP_CODE::A);
	Test_CreateChip(90, 40, EATTRIBUTE::NONE, ECHIP_CODE::A);
	Test_CreateChip(90, 40, EATTRIBUTE::NONE, ECHIP_CODE::B);
	Test_CreateChip(90, 40, EATTRIBUTE::NONE, ECHIP_CODE::B);
	Test_CreateChip(90, 40, EATTRIBUTE::NONE, ECHIP_CODE::C);
	Test_CreateChip(90, 40, EATTRIBUTE::NONE, ECHIP_CODE::C);

	Test_CreateChip(91, 40, EATTRIBUTE::NONE, ECHIP_CODE::A);
	Test_CreateChip(91, 40, EATTRIBUTE::NONE, ECHIP_CODE::A);
	Test_CreateChip(91, 40, EATTRIBUTE::NONE, ECHIP_CODE::B);
	Test_CreateChip(91, 40, EATTRIBUTE::NONE, ECHIP_CODE::B);
	Test_CreateChip(91, 40, EATTRIBUTE::NONE, ECHIP_CODE::C);
	Test_CreateChip(91, 40, EATTRIBUTE::NONE, ECHIP_CODE::C);

	Test_CreateChip(89, 40, EATTRIBUTE::NONE, ECHIP_CODE::A);
	Test_CreateChip(89, 40, EATTRIBUTE::NONE, ECHIP_CODE::A);
	Test_CreateChip(89, 40, EATTRIBUTE::NONE, ECHIP_CODE::B);
	Test_CreateChip(89, 40, EATTRIBUTE::NONE, ECHIP_CODE::B);
	Test_CreateChip(89, 40, EATTRIBUTE::NONE, ECHIP_CODE::C);
	Test_CreateChip(89, 40, EATTRIBUTE::NONE, ECHIP_CODE::C);
}

void CBattleMng::Test_CreateChip(int iID, int iDamage, EATTRIBUTE eAttribute, ECHIP_CODE eCode)
{
	FChipData_ForBattle tChipData;

	tChipData.iID = iID;
	tChipData.iDamage = iDamage;
	tChipData.eAttribute = eAttribute;
	tChipData.eCode = eCode;

	m_ChipData_List.push_back(tChipData);
}

void CBattleMng::Chip_LoadByFolder()
{
	vector<FChipData_ForFolder>* pFolder = CPlayerData::Get_Instance()->Get_FolderDataList();
	if (pFolder->empty())
		return;

	for (int i = 0; i < pFolder->size(); ++i)
	{
		FChipData_ForBattle tChipData;
		FChipData_ForFolder tFolderData = (*pFolder)[i];

		tChipData.iID = tFolderData.iID;
		tChipData.iDamage = tFolderData.iDamage;
		tChipData.eAttribute = tFolderData.eAttribute;
		tChipData.eCode = tFolderData.eCode;

		m_ChipData_List.push_back(tChipData);
	}
}


void CBattleMng::Chip_Shuffle()
{
	// 칩 데이터 셔플
	for (int i = 0; i < 100; ++i)
	{
		auto cpyChipData_List = m_ChipData_List;
		m_ChipData_List.clear();
		// 정방향 혹은 역방향으로 요소를 빼내 집어 넣는다.
		for (auto& item : cpyChipData_List)
		{
			if (rand() % 2)
				m_ChipData_List.push_back(item);
			else
				m_ChipData_List.push_front(item);
		}
	}
}

void CBattleMng::Chip_LoadCount()
{
	for (int i = 0; i < m_iLoadedChip_Count; ++i)
	{
		// 로드중 리스트가 동나면 종료
		if (m_ChipData_List.size() - 1 < i)
			break;
		// 로드중 리스트가 최대 로드칩 개수를 넘어가지 못하게 함
		if (m_LoadedChip_List.size() >= m_iLoadedChip_Count)
			break;

		m_LoadedChip_List.push_back(m_ChipData_List.front());
		m_ChipData_List.pop_front();
	}
}