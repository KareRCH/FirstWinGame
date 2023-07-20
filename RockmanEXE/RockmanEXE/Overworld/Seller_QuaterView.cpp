#include "Seller_QuaterView.h"

#include <BmpMgr.h>
#include <Manager/AnimationTable.h>
#include <AbstractFactory.h>
#include "TextBox.h"
#include "ChipShop.h"

void CSeller_QuaterView::Initialize(void)
{
	CCharacter_QuaterView::Initialize_QuaterChr();

	// 현재 좌표 박스로 조정하기
	m_vecBox = CVector3<float>(10.f, 10.f, 16.f);
	m_vecBoxPos = CVector3<float>(0.f, 0.f, 0.f);
	m_vecPos.z = (m_vecBox.z - m_vecBoxPos.z);

	m_vecDirection = CVector2<int>(0, -1);
	m_vecSpeed = CVector3<float>(3.f, 1.5f, 0.f);
	m_vecAccel = CVector3<float>(0.f, 0.f, -12.f);

#pragma region 이미지 추가
	wstring sText = L"./RockmanEXE/Resource/overworld/npc/seller/";
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"stand_1.png").c_str(), L"OVW_Seller_Stand_1");
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"stand_3.png").c_str(), L"OVW_Seller_Stand_3");
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"stand_5.png").c_str(), L"OVW_Seller_Stand_5");
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"stand_7.png").c_str(), L"OVW_Seller_Stand_7");
#pragma endregion

	//m_sDirection = L"4";
	//m_sAnimName = L"OVW_Rockman_Stand_4";
	Set_FrameKey(0, L"OVW_Seller_Stand_5");
	CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
}

int CSeller_QuaterView::Update(float fDeltaTime)
{

	CCharacter_QuaterView::Info_Update();
	return 0;
}

void CSeller_QuaterView::Late_Update(float fDeltaTime)
{
	Gravity(fDeltaTime);
	CObj::Move_Frame();
}

void CSeller_QuaterView::Render(HDC hDC)
{
	CBmpMgr::Get_Instance()->Draw_PNG_Strip(hDC, Get_FrameKey(0), Get_Frame(0), m_vecPos, CVector2<int>(1, 1));
}

void CSeller_QuaterView::Release(void)
{

}

void CSeller_QuaterView::Collide(CObj* _pDst)
{

}

void CSeller_QuaterView::Commnication(CCharacter_QuaterView* pCommunicator)
{
	CTextBox* pTextBox = CAbstractFactory<CTextBox>::Create();
	PORTRAY_TEXT tString;
	tString.Add_PortrayText(L"PTR_Normal", L"칩 상점인데 좀 보고 가시게 ");
	pTextBox->Set_OriginText(tString);
	m_pCommunicator = pCommunicator;
	pTextBox->Set_Func_SendResult([this]() { this->Load_ChipShot(); });
}

void CSeller_QuaterView::Listen_Communication_End()
{
	if (m_pCommunicator)
	{
		m_pCommunicator->Listen_Communication_End();
	}
}

void CSeller_QuaterView::Load_ChipShot()
{
	CChipShop* pChipShop = CAbstractFactory<CChipShop>::Create();
	FChipData_ForShop tChip;
	tChip.iID = 11;
	tChip.eCode = ECHIP_CODE::WILD_CARD;
	tChip.iCost = 1000;
	pChipShop->Get_Chip_List()->push_back(tChip);

	tChip.iID = 156;
	tChip.eCode = ECHIP_CODE::WILD_CARD;
	tChip.iCost = 1000;
	pChipShop->Get_Chip_List()->push_back(tChip);

	pChipShop->Set_Func_SendResult([this]() { this->Listen_Communication_End(); });
}
