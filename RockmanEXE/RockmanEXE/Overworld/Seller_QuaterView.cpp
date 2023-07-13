#include "Seller_QuaterView.h"

#include <BmpMgr.h>
#include <Manager/AnimationTable.h>

void CSeller_QuaterView::Initialize(void)
{
	CCharacter_QuaterView::Initialize_QuaterChr();

	// ���� ��ǥ �ڽ��� �����ϱ�
	m_vecBox = CVector3<float>(8.f, 8.f, 16.f);
	m_vecBoxPos = CVector3<float>(0.f, 0.f, 0.f);
	m_vecPos.z = (m_vecBox.z - m_vecBoxPos.z);

	m_vecDirection = CVector2<int>(0, -1);
	m_vecSpeed = CVector3<float>(3.f, 1.5f, 0.f);
	m_vecAccel = CVector3<float>(0.f, 0.f, -12.f);

#pragma region �̹��� �߰�
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
