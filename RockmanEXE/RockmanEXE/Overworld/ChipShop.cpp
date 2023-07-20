#include "ChipShop.h"

#include "ObjMgr.h"
#include "KeyMgr.h"
#include "BmpMgr.h"
#include "Manager/AnimationTable.h"
#include <SoundMgr.h>
#include <Manager/ChipDataTable.h>
#include <Player/PlayerData.h>

void CChipShop::Initialize(void)
{
	CObjMgr::Get_Instance()->Add_Object(UI, this);
	m_iRenderDepth = 1;

#pragma region 이미지 표시
	wstring sText = L"./RockmanEXE/Resource/ui/shop/";
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"list.png").c_str(), L"UI_Shop_List");
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"zenny.png").c_str(), L"UI_Shop_Zenny");
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"cursor.png").c_str(), L"UI_Shop_Cursor");
#pragma endregion

	m_tState.Set_State(ESTATE::OPEN);
	m_tState.Add_Func(ESTATE::OPEN, &CChipShop::OpenShop);
	m_tState.Add_Func(ESTATE::SELECTING, &CChipShop::Selecting);
	m_tState.Add_Func(ESTATE::CLOSE, &CChipShop::CloseShop);
}

int CChipShop::Update(float fDeltaTime)
{
	m_tState.Get_StateFunc()(this, fDeltaTime);

	return 0;
}

void CChipShop::Late_Update(float fDeltaTime)
{
}

void CChipShop::Render(HDC hDC)
{
	m_tInfo.fX = 0.f;
	m_tInfo.fY = 40.f;
	FRAME tFrame = {};
	tFrame.iFrameWidth = 183; tFrame.iFrameHeight = 96;
	CBmpMgr::Get_Instance()->Draw_PNG(hDC, L"UI_Shop_List", m_tInfo, tFrame, false);

	m_tInfo.fX = 189.f;
	m_tInfo.fY = 40.f;
	tFrame.iFrameWidth = 70; tFrame.iFrameHeight = 33;
	CBmpMgr::Get_Instance()->Draw_PNG(hDC, L"UI_Shop_Zenny", m_tInfo, tFrame, false);

	{
		SetTextColor(hDC, DWORD(0x00111111));
		SelectObject(hDC, g_hFonts[6]);

		wstringstream ssInt;
		ssInt << CPlayerData::Get_Instance()->Get_PlayerMoney();
		TextOutW(hDC, (int)m_tInfo.fX + 80 - lstrlen(ssInt.str().c_str()) * 16, (int)m_tInfo.fY + 15,
			ssInt.str().c_str(), lstrlen(ssInt.str().c_str()));
	}


	for (int i = 0; i < m_vChip_List.size(); ++i)
	{
		m_tInfo.fX = 0.f;
		m_tInfo.fY = 40.f;

		SetTextColor(hDC, DWORD(0x00111111));
		SelectObject(hDC, g_hFonts[6]);

		// 칩이름
		WCHAR text[40];
		_stprintf_s(text, L"%s", CChipDataTable::Get_Instance()->Get_ChipData_ForFolder(m_vChip_List[i].iID).sName);
		TextOutW(hDC, (int)m_tInfo.fX + 4, (int)m_tInfo.fY + 6 + i * 18, text, lstrlen(text));

		// 칩코드
		wstring sCode = L"";
		int iCode = (int)m_vChip_List[i].eCode + 64;
		if (iCode - 64 != (int)ECHIP_CODE::WILD_CARD)
		{
			sCode = TCHAR(iCode);
		}
		else
			sCode = L"*";


		_stprintf_s(text, L"%s", sCode.c_str());
		TextOutW(hDC, (int)m_tInfo.fX + 100, (int)m_tInfo.fY + 6 + i * 18, text, lstrlen(text));

		// 칩가격
		wstringstream ssInt;
		int iPrize = (int)m_vChip_List[i].iCost;
		ssInt << iPrize;

		_stprintf_s(text, L"%s", ssInt.str().c_str());
		TextOutW(hDC, (int)m_tInfo.fX + 180 - lstrlen(text) * 16, (int)m_tInfo.fY + 6 + i * 18, text, lstrlen(text));
	}

	m_tInfo.fX = 0.f;
	m_tInfo.fY = 48.f + m_iCursor * 16.f;
	tFrame.iFrameWidth = 9; tFrame.iFrameHeight = 14;
	CBmpMgr::Get_Instance()->Draw_PNG(hDC, L"UI_Shop_Cursor", m_tInfo, tFrame, false);
}

void CChipShop::Release(void)
{
}

void CChipShop::Collide(CObj* _pDst)
{
}

void CChipShop::OpenShop(float fDeltaTime)
{
	// 진입부
	if (m_tState.IsState_Entered())
	{

	}

	// 실행부
	if (m_tState.Can_Update())
	{
		m_tState.Set_State(ESTATE::SELECTING);
	}

	// 탈출부
	if (m_tState.IsState_Exit())
	{

	}
}

void CChipShop::Selecting(float fDeltaTime)
{
	// 진입부
	if (m_tState.IsState_Entered())
	{

	}

	// 실행부
	if (m_tState.Can_Update())
	{
		if (CKeyMgr::Get_Instance()->Key_Down('A'))
		{
			if (0 <= CPlayerData::Get_Instance()->Get_PlayerMoney() - m_vChip_List[m_iCursor].iCost)
			{
				FChipData_ForPack tChip;
				tChip.iID = m_vChip_List[m_iCursor].iID;
				CPlayerData::Get_Instance()->Get_PackDataList()->push_back(tChip);

				CPlayerData::Get_Instance()->Set_PlayerMoeny(CPlayerData::Get_Instance()->Get_PlayerMoney() - m_vChip_List[m_iCursor].iCost);
				CSoundMgr::Get_Instance()->Play_Sound(const_cast<TCHAR*>(L"item_get.wav"), SYSTEM_EFFECT, 1.f);
			}
			else
				CSoundMgr::Get_Instance()->Play_Sound(const_cast<TCHAR*>(L"card_error.wav"), SYSTEM_EFFECT, 1.f);
		}
		else if (CKeyMgr::Get_Instance()->Key_Down('S'))
		{
			m_tState.Set_State(ESTATE::CLOSE);
		}
		else if (CKeyMgr::Get_Instance()->Key_Down(VK_UP))
		{
			--m_iCursor;
			if (m_iCursor < 0)
				m_iCursor = 0;
		}
		else if (CKeyMgr::Get_Instance()->Key_Down(VK_DOWN))
		{
			++m_iCursor;
			if (m_iCursor > (int)m_vChip_List.size() - 1)
				m_iCursor = (int)m_vChip_List.size() - 1;
		}
	}

	// 탈출부
	if (m_tState.IsState_Exit())
	{

	}
}

void CChipShop::CloseShop(float fDeltaTime)
{
	// 진입부
	if (m_tState.IsState_Entered())
	{

	}

	// 실행부
	if (m_tState.Can_Update())
	{
		Call_Func_SendResult();

		Set_Dead();
	}

	// 탈출부
	if (m_tState.IsState_Exit())
	{

	}
}
