#include "SteelCube_QuaterView.h"

#include <BmpMgr.h>
#include <Manager/AnimationTable.h>
#include "TextBox.h"
#include <AbstractFactory.h>

void CSteelCube_QuaterView::Initialize(void)
{
	CCharacter_QuaterView::Initialize_QuaterChr();

	// 현재 좌표 박스로 조정하기
	m_vecBox = CVector3<float>(32.f, 16.f, 32.f);
	m_vecBoxPos = CVector3<float>(0.f, 0.f, 22.f);
	m_vecPos.z = (m_vecBox.z - m_vecBoxPos.z);

	m_vecDirection = CVector2<int>(0, -1);
	m_vecSpeed = CVector3<float>(3.f, 1.5f, 0.f);
	m_vecAccel = CVector3<float>(0.f, 0.f, -12.f);

#pragma region 이미지
	wstring sText = L"./RockmanEXE/Resource/overworld/obj/";
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"steel_cube.png").c_str(), L"OVW_Steel_Cube");

	Set_FrameKey(0, L"OVW_Steel_Cube");
	CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
#pragma endregion
}

int CSteelCube_QuaterView::Update(float fDeltaTime)
{
	CObj::Move_Frame();

	CCharacter_QuaterView::Info_Update();
	return 0;
}

void CSteelCube_QuaterView::Late_Update(float fDeltaTime)
{
}

void CSteelCube_QuaterView::Render(HDC hDC)
{
	CBmpMgr::Get_Instance()->Draw_PNG_Strip(hDC, Get_FrameKey(0), Get_Frame(0), m_vecPos, CVector2<int>(1, 1));
	//CBmpMgr::Get_Instance()->Draw_Text_Circle_Vec3(hDC, m_vecPos);
}

void CSteelCube_QuaterView::Release(void)
{
}

void CSteelCube_QuaterView::Collide(CObj* _pDst)
{
}

void CSteelCube_QuaterView::Commnication(CCharacter_QuaterView* pCommunicator)
{
	CTextBox* pTextBox = CAbstractFactory<CTextBox>::Create();
	PORTRAY_TEXT tString;
	tString.Add_Text(L"어이어이~ 여긴 못 지나간다~ 날 열고 싶으면...");
	tString.Add_PortrayText(L"PTR_Lan", L"록맨 ! 점프로 간다 !");
	tString.Add_PortrayText(L"PTR_Rockman", L"라져 !");
	tString.Add_Text(L"뭐...뭣 !");
	pTextBox->Set_OriginText(tString);
	m_pCommunicator = pCommunicator;
	pTextBox->Set_Func_SendResult([this]() { this->Listen_Communication_End(); });
}

void CSteelCube_QuaterView::Listen_Communication_End()
{
	if (m_pCommunicator)
	{
		m_pCommunicator->Listen_Communication_End();
	}
}
