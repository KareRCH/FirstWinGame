#include "Battle/BattleUI.h"

#include "SoundMgr.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"
#include "KeyMgr.h"

#include "Manager/BattleMng.h"
#include <Manager/AnimationTable.h>

CBattleUI* CBattleUI::m_pInstance = nullptr;

void CBattleUI::Initialize()
{
	// 펫 위치
	{
		m_tInfo.fX = -160.f;
		m_tInfo.fY = 0.f;
	}

	// 칩 아이콘 위치
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (m_tChip_Info.size() - 1 < i * 5 + j)
				break;

			m_tChip_Info[j + i * 5].fX = 5.f + (float)j * 16.f;
			m_tChip_Info[j + i * 5].fY = 105.f + (float)i * 23.f;
			m_tChip_Info[j + i * 5].fCX = 22.f;
			m_tChip_Info[j + i * 5].fCY = 22.f;
		}
	}

	// 장비 칩 아이콘 위치
	{
		m_tChipEquip_Info.fX = 97.f;
		m_tChipEquip_Info.fY = 29.f;
		m_tChipPortray_Info.fCX = 14.f;
		m_tChipPortray_Info.fCY = 14.f;
	}

	// 칩 초상
	{
		m_tChipPortray_Info.fX = 16.f;
		m_tChipPortray_Info.fY = 28.f;
		m_tChipPortray_Info.fCX = 56.f;
		m_tChipPortray_Info.fCY = 48.f;
	}

	// 커스텀 게이지
	{
		m_tCustom_Info.fX = (float)(ROCKMAN_EXECX / 2) - 73.f;
		m_tCustom_Info.fY = 1.f;
		m_tCustom_Info.fCX = 146.f;
		m_tCustom_Info.fCY = 17.f;
	}

	// 배틀 시작, 끝 메시지
	{
		m_tBattleStart_Info.fCX = 136.f;
		m_tBattleStart_Info.fCY = 16.f;
		m_tBattleStart_Info.fX = (float)ROCKMAN_EXECX * 0.5f - m_tBattleStart_Info.fCX * 0.5f;
		m_tBattleStart_Info.fY = (float)ROCKMAN_EXECY * 0.5f - m_tBattleStart_Info.fCY * 0.5f;

		m_tBattleEnd_Info.fCX = 136.f;
		m_tBattleEnd_Info.fCY = 16.f;
		m_tBattleEnd_Info.fX = (float)ROCKMAN_EXECX * 0.5f - m_tBattleStart_Info.fCX * 0.5f;
		m_tBattleEnd_Info.fY = (float)ROCKMAN_EXECY * 0.5f - m_tBattleStart_Info.fCY * 0.5f;
	}

	// OK 좌표 정보
	{
		m_tOK_Info.fX = 91.f;
		m_tOK_Info.fY = 116.f;
		m_tOK_Info.fCX = 25.f;
		m_tOK_Info.fCY = 20.f;
	}

	TCHAR sText[100];
	const TCHAR* sDir = L"./RockmanEXE/Resource/battle/ui/";
	// 기본
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"ui_enemy_info.png"), L"NBT_UI_Enemy_Info");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"ui_hp_bg.png"), L"NBT_UI_Hp");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"ui_pet.png"), L"NBT_UI_Pet");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"card_senddata.png"), L"NBT_UI_Send_Data");
	
	// 커스텀바
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"custom.png"), L"NBT_UI_Custom_Bar");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"custom_bar_white.png"), L"NBT_UI_Custom_White");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"custom_bar_green.png"), L"NBT_UI_Custom_Green");

	// 커서
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"card_cursor_big.png"), L"NBT_UI_Cursor_Big");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"card_cursor_small.png"), L"NBT_UI_Cursor_Small");

	// 메시지 UI
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"battle_start.png"), L"NBT_UI_Battle_Start");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"enemy_deleted.png"), L"NBT_UI_Enemy_Deleted");


	m_tState.Set_State(STATE::CLOSED);
	m_tState_Cross.Set_State(STATE_CROSS::CLOSED);
	m_tState_Cursor.Set_State(STATE_CURSOR::NONE);
	m_tState_Custom.Set_State(STATE_CUSTOM::INVISIBLE);
	m_tState_BattleStart.Set_State(STATE_BATTLE_START::INVISIBLE);
	m_tState_BattlEnd.Set_State(STATE_BATTLE_END::INVISIBLE);

	Add_Frame(ANIM_KEY::CURSOR, L"NBT_UI_Cursor_Small");
	CAnimationTable::Get_Instance()->Load_AnimData(L"1", m_mapFrame[ANIM_KEY::CURSOR]);
}

void CBattleUI::Release()
{

}

void CBattleUI::Update(float fDeltaTime)
{
	State_Update(fDeltaTime);

	Move_Frame();
}

void CBattleUI::Late_Update(float fDeltaTime)
{
}

void CBattleUI::Render(HDC hDC)
{
	FRAME tFrame = {};
	INFO tInfo = m_tInfo;

	// 커스텀 게이지
	if (m_tState_Custom.IsOnState(STATE_CUSTOM::VISIBLE))
	{
		tFrame.iFrameWidth = (int)m_tCustom_Info.fCX;
		tFrame.iFrameHeight = (int)m_tCustom_Info.fCY;
		CBmpMgr::Get_Instance()->Draw_PNG(hDC, L"NBT_UI_Custom_Bar", m_tCustom_Info, tFrame, false);

		tInfo.fX = m_tCustom_Info.fX + 9.f;
		tInfo.fY = m_tCustom_Info.fY + 8.f;
		tFrame.iFrameWidth = 128;
		tFrame.iFrameHeight = 6;
		m_fCustom_Gauge = CBattleMng::Get_Instance()->Get_TurnGauge();
		if (m_fCustom_Gauge.Cur < m_fCustom_Gauge.Max)
		{
			CBmpMgr::Get_Instance()->Draw_PNG(hDC, L"NBT_UI_Custom_White", tInfo, tFrame, 0, 0,
				(int)(128.f * m_fCustom_Gauge.Get_Percent()), 8 , false);
		}
		else
		{
			CBmpMgr::Get_Instance()->Draw_PNG(hDC, L"NBT_UI_Custom_Green", tInfo, tFrame, 0, 0,
				(int)(128.f * m_fCustom_Gauge.Get_Percent()), 8, false);
		}
	}

	// 펫
	{
		tFrame.iFrameWidth = 120; tFrame.iFrameHeight = 164;
		CBmpMgr::Get_Instance()->Draw_PNG(hDC, L"NBT_UI_Pet", m_tInfo, tFrame, false);
	}

	// 체력
	{
		tInfo.fX = max(m_tInfo.fX + 124.f, 2.f); tInfo.fY = 2.f;
		tFrame.iFrameWidth = 64; tFrame.iFrameHeight = 11;
		CBmpMgr::Get_Instance()->Draw_PNG(hDC, L"NBT_UI_Hp", tInfo, tFrame, false);
	}
	
	// 적 이름 정보
	if (m_bInitBattle)
	{
		tInfo.fX = (float)ROCKMAN_EXECX - 40.f; tInfo.fY = 16.f;
		tFrame.iFrameWidth = 40; tFrame.iFrameHeight = 14;
		CBmpMgr::Get_Instance()->Draw_PNG(hDC, L"NBT_UI_Enemy_Info", tInfo, tFrame, false);
	}

	// 로드된 칩 아이콘
	if (!m_LoadedChip_List.empty())
	{
		wstring swString = L"UI_Chip_Icon_";
		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (m_LoadedChip_List.size() - 1 < i * 5 + j)
					break;

				if (m_LoadedChip_List[i * 5 + j].second == CHIP_SELECT::ABLE)
				{
					tInfo.fX = m_tInfo.fX + 9.f + (float)j * 16.f;
					tInfo.fY = m_tInfo.fY + 109.f + (float)i * 23.f;
					tFrame.iFrameWidth = 14; tFrame.iFrameHeight = 14;
					wstringstream ssInt;
					ssInt << m_LoadedChip_List[i * 5 + j].first.iID + 1;
					wstring swString2 = (swString + ssInt.str());

					CBmpMgr::Get_Instance()->Draw_PNG(hDC, swString2.c_str(), tInfo, tFrame, 1, 1, false);
				}
			}
		}
	}

	// 장비할 칩 아이콘
	if (!m_EquipChip_List.empty())
	{
		wstring swString = L"UI_Chip_Icon_";
		for (int i = 0; i < m_EquipChip_List.size(); ++i)
		{
			tInfo.fX = m_tInfo.fX + m_tChipEquip_Info.fX;
			tInfo.fY = m_tInfo.fY + m_tChipEquip_Info.fY + (float)i * 16.f;
			tFrame.iFrameWidth = 14; tFrame.iFrameHeight = 14;
			wstringstream ssInt;
			ssInt << m_LoadedChip_List[i].first.iID + 1;
			wstring swString2 = (swString + ssInt.str());

			CBmpMgr::Get_Instance()->Draw_PNG(hDC, swString2.c_str(), tInfo, tFrame, 1, 1, false);
		}
	}

	// 칩 초상
	if (m_tState_Cursor.IsOnState(STATE_CURSOR::CHIP))
	{
		if (!m_LoadedChip_List.empty() && m_LoadedChip_List.size() > m_iCursorChip)
		{
			wstring swString = L"UI_Chip_Portray_";
			tInfo.fX = m_tInfo.fX + m_tChipPortray_Info.fX;
			tInfo.fY = m_tInfo.fY + m_tChipPortray_Info.fY;
			tFrame.iFrameWidth = (int)m_tChipPortray_Info.fCX;
			tFrame.iFrameHeight = (int)m_tChipPortray_Info.fCY;
			wstringstream ssInt;
			ssInt << m_LoadedChip_List[m_iCursorChip].first.iID + 1;
			wstring swString2 = (swString + ssInt.str());

			CBmpMgr::Get_Instance()->Draw_PNG(hDC, swString2.c_str(), tInfo, tFrame, 0, 0, false);
		}
	}

	if (m_tState_Cursor.IsOnState(STATE_CURSOR::OK))
	{
		tInfo.fX = m_tInfo.fX + m_tChipPortray_Info.fX;
		tInfo.fY = m_tInfo.fY + m_tChipPortray_Info.fY;
		tFrame.iFrameWidth = (int)m_tChipPortray_Info.fCX;
		tFrame.iFrameHeight = (int)m_tChipPortray_Info.fCY;
		CBmpMgr::Get_Instance()->Draw_PNG(hDC, L"NBT_UI_Send_Data", tInfo, tFrame, false);
	}

	// 커서 위치
	{
		auto& tState = m_tState_Cursor;
		switch (tState.eState)
		{
		case STATE_CURSOR::CHIP:
			// CHIP UI에 커서가 가있는 상태입니다.
			m_tCursor_Info.fX = m_tChip_Info[m_iCursorChip].fX;
			m_tCursor_Info.fY = m_tChip_Info[m_iCursorChip].fY;
			tInfo.fX = m_tInfo.fX + m_tCursor_Info.fX;
			tInfo.fY = m_tInfo.fY + m_tCursor_Info.fY;
			CBmpMgr::Get_Instance()->Draw_PNG_Strip(hDC, Get_FrameKey(ANIM_KEY::CURSOR), tInfo, Get_FrameData(ANIM_KEY::CURSOR), false);
			break;
		case STATE_CURSOR::OK:
			// OK UI에 커서가 가있는 상태입니다.
			tInfo.fX = m_tInfo.fX + m_tOK_Info.fX;
			tInfo.fY = m_tInfo.fY + m_tOK_Info.fY;
			CBmpMgr::Get_Instance()->Draw_PNG_Strip(hDC, Get_FrameKey(ANIM_KEY::CURSOR), tInfo, Get_FrameData(ANIM_KEY::CURSOR), false);
			break;
		case STATE_CURSOR::CROSS:
			// 크로스 UI에 커서가 가있는 상태입니다.

			break;
		case STATE_CURSOR::BEAST:
			// 비스트에 커서가 가있는 상태입니다.

			break;
		}
	}

	// 배틀 시작 메시지
	if (m_tState_BattleStart.IsOnState(STATE_BATTLE_START::VISIBLE))
	{
		tFrame.iFrameWidth = (int)m_tBattleStart_Info.fCX; 
		tFrame.iFrameHeight = (int)m_tBattleStart_Info.fCY;
		CBmpMgr::Get_Instance()->Draw_PNG(hDC, L"NBT_UI_Battle_Start", m_tBattleStart_Info, tFrame, false);
	}

	if (m_tState_BattlEnd.IsOnState(STATE_BATTLE_END::VISIBLE))
	{
		tFrame.iFrameWidth = (int)m_tBattleEnd_Info.fCX;
		tFrame.iFrameHeight = (int)m_tBattleEnd_Info.fCY;
		CBmpMgr::Get_Instance()->Draw_PNG(hDC, L"NBT_UI_Enemy_Deleted", m_tBattleEnd_Info, tFrame, false);
	}
}

void CBattleUI::Move_Frame()
{
	for (auto iter = m_mapFrame.begin(); iter != m_mapFrame.end(); ++iter)
	{
		auto& tFrame = (*iter).second.second;
		tFrame.ulCurTime = GetTickCount64();
		if (tFrame.ulTime + tFrame.ulSpeed < tFrame.ulCurTime)
		{
			++tFrame.iFrameCur;

			if (tFrame.iFrameCur > tFrame.iFrameEnd)
			{
				if (tFrame.bLoop)
					tFrame.iFrameCur = 0;
				else
					tFrame.iFrameCur = tFrame.iFrameEnd;
			}

			tFrame.ulTime = tFrame.ulCurTime;
		}
	}
}

void CBattleUI::State_Update(float fDeltaTime)
{
	switch (m_tState.eState)
	{
	case STATE::OPENING:
		if (m_tState.IsState_Entered())
		{
			// 커서 초기화
			m_iCursorChip = 0;
			m_tState_Cursor.Set_State(STATE_CURSOR::CHIP);

			m_tState_Custom.Set_State(STATE_CUSTOM::INVISIBLE);
			CSoundMgr::Get_Instance()->Play_Sound(const_cast<TCHAR*>(L"card_screen_open.wav"), SYSTEM_EFFECT, 1.f);
		}

		if (m_tState.Can_Update())
		{
			m_tInfo.fX += 20.f;
			if (0.f < m_tInfo.fX)
			{
				m_tInfo.fX = 0.f;
				m_tState.Set_State(STATE::OPENED);
			}
		}

		if (m_tState.IsState_Exit())
		{
			
		}
		break;
	case STATE::OPENED:
		if (m_tState.IsState_Entered())
		{

		}

		if (m_tState.Can_Update())
		{
			
		}

		if (m_tState.IsState_Exit())
		{
			
		}
		break;
	case STATE::CLOSING:
		if (m_tState.IsState_Entered())
		{
			
			m_bInitBattle = false;
		}

		if (m_tState.Can_Update())
		{
			m_tInfo.fX -= 20.f;
			if (-160.f > m_tInfo.fX)
			{
				m_tInfo.fX = -160.f;
				m_tState.Set_State(STATE::CLOSED);
			}
		}


		if (m_tState.IsState_Exit())
		{
			CBattleMng::Get_Instance()->Set_State(CBattleMng::BATTLE_START);
			m_tState_Custom.Set_State(STATE_CUSTOM::VISIBLE);
			m_tState_BattleStart.Set_State(STATE_BATTLE_START::VISIBLE);
		}
		break;
	case STATE::CLOSED:
		if (m_tState.IsState_Entered())
		{
			m_fBattleStart_Time.Reset();
		}

		if (m_tState.Can_Update())
		{
			if (m_fBattleStart_Time.Update(fDeltaTime))
			{
				m_tState_BattleStart.Set_State(STATE_BATTLE_START::INVISIBLE);
			}
		}

		if (m_tState.IsState_Exit())
		{

		}
		break;
	}


	switch (m_tState_Cross.eState)
	{
	case STATE_CROSS::OPENING:

		break;
	case STATE_CROSS::CLOSING:

		break;
	case STATE_CROSS::OPENED:
		// 크로스 UI 출력중입니다.

		break;
	case STATE_CROSS::CLOSED:

		break;
	}

	
	auto& tState = m_tState_Cursor;
	switch (tState.eState)
	{
	case STATE_CURSOR::CHIP:
		// CHIP UI에 커서가 가있는 상태입니다.
		if (tState.IsState_Entered())
		{
			Set_FrameKey(ANIM_KEY::CURSOR, L"NBT_UI_Cursor_Small");
			CAnimationTable::Get_Instance()->Load_AnimData(L"1", *Get_Frame(ANIM_KEY::CURSOR));
		}

		if (m_tState.Can_Update())
		{
			if (CKeyMgr::Get_Instance()->Key_Down(VK_RIGHT))
			{
				if (4 != m_iCursorChip && m_LoadedChip_List.size() - 1 > m_iCursorChip)
				{
					++m_iCursorChip;
					CSoundMgr::Get_Instance()->Play_Sound(const_cast<TCHAR*>(L"card_choose.wav"), SYSTEM_EFFECT, 1.f);
				}
				else if (4 == m_iCursorChip || (m_LoadedChip_List.size() - 1 > 4 == m_iCursorChip))
				{
					tState.Set_State(STATE_CURSOR::OK);
					CSoundMgr::Get_Instance()->Play_Sound(const_cast<TCHAR*>(L"card_choose.wav"), SYSTEM_EFFECT, 1.f);
				}
			}
			else if (CKeyMgr::Get_Instance()->Key_Down(VK_LEFT))
			{
				if (4 < m_iCursorChip && 5 != m_iCursorChip)
				{
					--m_iCursorChip;
					CSoundMgr::Get_Instance()->Play_Sound(const_cast<TCHAR*>(L"card_choose.wav"), SYSTEM_EFFECT, 1.f);
				}
				else if (0 < m_iCursorChip)
				{
					--m_iCursorChip;
					CSoundMgr::Get_Instance()->Play_Sound(const_cast<TCHAR*>(L"card_choose.wav"), SYSTEM_EFFECT, 1.f);
				}
			}
			else if (CKeyMgr::Get_Instance()->Key_Down(VK_UP))
			{
				if (4 < m_iCursorChip)
				{
					m_iCursorChip -= 5;
					if (m_iCursorChip < 0)
						m_iCursorChip = 0;
					CSoundMgr::Get_Instance()->Play_Sound(const_cast<TCHAR*>(L"card_choose.wav"), SYSTEM_EFFECT, 1.f);
				}
			}
			else if (CKeyMgr::Get_Instance()->Key_Down(VK_DOWN))
			{
				if (3 > m_iCursorChip && m_LoadedChip_List.size() > m_iCursorChip + 5)
				{
					m_iCursorChip += 5;
					CSoundMgr::Get_Instance()->Play_Sound(const_cast<TCHAR*>(L"card_choose.wav"), SYSTEM_EFFECT, 1.f);
				}
			}
			// 선택 키를 눌렀을 때
			else if (CKeyMgr::Get_Instance()->Key_Down('A'))
			{
				// 선택되지 않았을 때 추가 가능, 사이즈 넘어가지 않으면 추가가능
				if (CHIP_SELECT::ABLE == m_LoadedChip_List[m_iCursorChip].second)
				{
					// 슬롯이 남아있을 때
					if (m_iMax_EquipChip > m_EquipChip_List.size())
					{
						m_LoadedChip_List[m_iCursorChip].second = CHIP_SELECT::SELECTED;
						m_EquipChip_List.push_back(&m_LoadedChip_List[m_iCursorChip].first);
						CSoundMgr::Get_Instance()->Play_Sound(const_cast<TCHAR*>(L"card_select.wav"), SYSTEM_EFFECT, 1.f);
					}
				}
				else if (CHIP_SELECT::SELECTED == m_LoadedChip_List[m_iCursorChip].second)
				{
					CSoundMgr::Get_Instance()->Play_Sound(const_cast<TCHAR*>(L"card_error.wav"), SYSTEM_EFFECT, 1.f);
				}
			}
			else if (CKeyMgr::Get_Instance()->Key_Down('S'))
			{
				// 취소
				if (!m_EquipChip_List.empty())
				{
					auto iter = find_if(m_LoadedChip_List.begin(), m_LoadedChip_List.end(),
						[&](pair<FChipData_ForBattle, CHIP_SELECT>& pairChip) {
							return (&pairChip.first == m_EquipChip_List.back());
						});

					if (iter != m_LoadedChip_List.end())
					{
						m_EquipChip_List.pop_back();
						(*iter).second = CHIP_SELECT::ABLE;
						CSoundMgr::Get_Instance()->Play_Sound(const_cast<TCHAR*>(L"card_cancel.wav"), SYSTEM_EFFECT, 1.f);
					}
				}
			}
		}
		

		if (tState.IsState_Exit())
		{

		}
		break;
	case STATE_CURSOR::OK:
		// OK UI에 커서가 가있는 상태입니다.
		if (tState.IsState_Entered())
		{
			Set_FrameKey(ANIM_KEY::CURSOR, L"NBT_UI_Cursor_Big");
			CAnimationTable::Get_Instance()->Load_AnimData(L"1", *Get_Frame(ANIM_KEY::CURSOR));
		}

		
		if (m_tState.Can_Update())
		{
			if (CKeyMgr::Get_Instance()->Key_Down(VK_LEFT))
			{
				m_iCursorChip = 4;
				if (4 > m_LoadedChip_List.size() - 1)
					m_iCursorChip = (int)m_LoadedChip_List.size() - 1;
				else if (0 == m_LoadedChip_List.size())
					m_iCursorChip = 0;

				CSoundMgr::Get_Instance()->Play_Sound(const_cast<TCHAR*>(L"card_choose.wav"), SYSTEM_EFFECT, 1.f);
				tState.Set_State(STATE_CURSOR::CHIP);
			}
			else if (CKeyMgr::Get_Instance()->Key_Down('A'))
			{
				m_tState.Reserve_State(STATE::CLOSING);
				tState.Set_State(STATE_CURSOR::NONE);
				CSoundMgr::Get_Instance()->Play_Sound(const_cast<TCHAR*>(L"card_confirm.wav"), SYSTEM_EFFECT, 1.f);
			}
		}


		if (tState.IsState_Exit())
		{

		}
		break;
	case STATE_CURSOR::CROSS:
		// 크로스 UI에 커서가 가있는 상태입니다.
		if (tState.IsState_Entered())
		{

		}

		if (m_tState.Can_Update())
		{

		}

		if (tState.IsState_Exit())
		{

		}
		break;
	case STATE_CURSOR::BEAST:
		// 비스트에 커서가 가있는 상태입니다.
		if (tState.IsState_Entered())
		{

		}

		if (m_tState.Can_Update())
		{

		}

		if (tState.IsState_Exit())
		{

		}
		break;
	case STATE_CURSOR::NONE:

		break;
	}
}
