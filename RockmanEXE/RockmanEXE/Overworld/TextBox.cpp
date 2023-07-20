#include "TextBox.h"

#include "ObjMgr.h"
#include "KeyMgr.h"
#include "BmpMgr.h"
#include "Manager/AnimationTable.h"
#include <SoundMgr.h>

void CTextBox::Initialize(void)
{
	CObjMgr::Get_Instance()->Add_Object(UI, this);
	m_iRenderDepth = 1;

#pragma region 이미지 표시
	wstring sText = L"./RockmanEXE/Resource/ui/";
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"textbox_opening.png").c_str(), L"UI_TextBox_Opening");
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"textbox_closing.png").c_str(), L"UI_TextBox_Closing");
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"textbox_opend.png").c_str(), L"UI_TextBox_Opend");

	sText = L"./RockmanEXE/Resource/ui/portray/";
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"lan.png").c_str(), L"PTR_Lan");
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"rockman.png").c_str(), L"PTR_Rockman");
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"normal.png").c_str(), L"PTR_Normal");
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"famous.png").c_str(), L"PTR_Famous");
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"blastman.png").c_str(), L"PTR_Blastman");

	Set_FrameKey(0, L"UI_TextBox_Opening");
	CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);

	Set_FrameKey(1, L"");
#pragma endregion

	m_tState.Set_State(ESTATE::OPEN);
	m_tState.Add_Func(ESTATE::OPEN, &CTextBox::OpenTextBox);
	m_tState.Add_Func(ESTATE::OPENED, &CTextBox::OpenedTextBox);
	m_tState.Add_Func(ESTATE::CLOSE, &CTextBox::CloseTextBox);
	m_tState.Add_Func(ESTATE::START, &CTextBox::FlowStart);
	m_tState.Add_Func(ESTATE::FLOW, &CTextBox::FlowText);
	m_tState.Add_Func(ESTATE::END, &CTextBox::FlowEnd);
}

int CTextBox::Update(float fDeltaTime)
{
	m_tState.Get_StateFunc()(this, fDeltaTime);


	Move_Frame();
	return 0;
}

void CTextBox::Late_Update(float fDeltaTime)
{

}

void CTextBox::Render(HDC hDC)
{
	m_tInfo.fX = 20.f; m_tInfo.fY = 137.f;
	// 텍스트 박스 출력
	CBmpMgr::Get_Instance()->Draw_PNG_Strip(hDC, Get_FrameKey(0), Get_Frame(0), 
		CVector3<float>(m_tInfo.fX - 20.f, m_tInfo.fY - 17.f, 0.f), CVector2<int>(1, 1), false);

	// 텍스트 출력
	if (m_tState.IsOnState(ESTATE::FLOW) || m_tState.IsOnState(ESTATE::END) || m_tState.IsOnState(ESTATE::START))
	{
		if (m_sPortray.empty())
		{
			SetTextColor(hDC, DWORD(0x00111111));
			SelectObject(hDC, g_hFonts[6]);

			WCHAR text[200];
			RECT rc = {
				(int)m_tInfo.fX, (int)m_tInfo.fY,
				(int)m_tInfo.fX + 220, (int)m_tInfo.fY + 64
			};
			_stprintf_s(text, L"%s", m_sFlowText_Part.c_str());
			DrawText(hDC, text, -1, &rc, DT_LEFT | DT_WORDBREAK | DT_EDITCONTROL);
		}
		// 초상 있음
		else
		{
			CBmpMgr::Get_Instance()->Draw_PNG_Strip(hDC, Get_FrameKey(1), Get_Frame(1),
				CVector3<float>(m_tInfo.fX - 6.f, m_tInfo.fY - 7.f, 0.f), CVector2<int>(1, 1), false);

			SetTextColor(hDC, DWORD(0x00111111));
			SelectObject(hDC, g_hFonts[6]);

			WCHAR text[200];
			RECT rc = {
				(int)m_tInfo.fX + 38, (int)m_tInfo.fY,
				(int)m_tInfo.fX + 200, (int)m_tInfo.fY + 64
			};
			_stprintf_s(text, L"%s", m_sFlowText_Part.c_str());
			DrawTextW(hDC, text, -1, &rc, DT_LEFT | DT_WORDBREAK | DT_EDITCONTROL);
		}
	}
}

void CTextBox::Release(void)
{

}

void CTextBox::Collide(CObj* _pDst)
{

}

void CTextBox::OpenTextBox(float fDeltaTime)
{
	// 진입부
	if (m_tState.IsState_Entered())
	{
		Set_FrameKey(0, L"UI_TextBox_Opening");
		CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
	}

	// 실행부
	if (m_tState.Can_Update())
	{

		if (Get_Frame(0).IsFrameEnd())
		{
			m_tState.Set_State(ESTATE::OPENED);
		}
	}

	// 탈출부
	if (m_tState.IsState_Exit())
	{

	}
}

void CTextBox::OpenedTextBox(float fDeltaTime)
{
	// 진입부
	if (m_tState.IsState_Entered())
	{
		Set_FrameKey(0, L"UI_TextBox_Opend");
		CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
	}

	// 실행부
	if (m_tState.Can_Update())
	{

		if (Get_Frame(0).IsFrameEnd())
		{
			m_tState.Set_State(ESTATE::START);
		}
	}

	// 탈출부
	if (m_tState.IsState_Exit())
	{

	}
}

void CTextBox::CloseTextBox(float fDeltaTime)
{
	// 진입부
	if (m_tState.IsState_Entered())
	{
		Set_FrameKey(0, L"UI_TextBox_Closing");
		CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
	}

	// 실행부
	if (m_tState.Can_Update())
	{

		if (Get_Frame(0).IsFrameEnd())
		{
			Set_Dead();
		}
	}

	// 탈출부
	if (m_tState.IsState_Exit())
	{
		
	}
}

void CTextBox::FlowStart(float fDeltaTime)
{
	// 진입부
	if (m_tState.IsState_Entered())
	{
		Set_FrameKey(0, L"UI_TextBox_Opend");
		CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
	}

	// 실행부
	if (m_tState.Can_Update())
	{
		if (!m_OriginText_List.IsEmpty())
		{
			m_iFlowIndex = 0;
			m_sFlowText = m_OriginText_List.Get_TextStr();
			m_sPortray = m_OriginText_List.Get_PortrayStr();
			m_OriginText_List.Pop_Text();

			Set_FrameKey(1, m_sPortray.c_str());
			CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[1]);

			m_tState.Set_State(ESTATE::FLOW);
		}
		else
			m_tState.Set_State(ESTATE::CLOSE);
	}

	// 탈출부
	if (m_tState.IsState_Exit())
	{

	}
}

void CTextBox::FlowText(float fDeltaTime)
{
	// 진입부
	if (m_tState.IsState_Entered())
	{
		Set_FrameKey(0, L"UI_TextBox_Opend");
		CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
	}

	// 실행부
	if (m_tState.Can_Update())
	{
		if (m_fFlowDelay.Update(fDeltaTime, true))
		{
			++m_iFlowIndex;
			if (!m_fFlowDelay.IsMax())
				CSoundMgr::Get_Instance()->Play_Sound(const_cast<TCHAR*>(L"text.wav"), SYSTEM_EFFECT, 1.f);
		}
			

		if (m_iFlowIndex > m_sFlowText.length() - 1)
		{
			m_iFlowIndex = (int)(m_sFlowText.length() - 1);

			m_tState.Set_State(ESTATE::END);
		}

		m_sFlowText_Part = m_sFlowText.substr(0Ui64, (size_t)m_iFlowIndex);
	}

	// 탈출부
	if (m_tState.IsState_Exit())
	{

	}
}

void CTextBox::FlowEnd(float fDeltaTime)
{
	// 진입부
	if (m_tState.IsState_Entered())
	{
		Set_FrameKey(0, L"UI_TextBox_Opend");
		CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
	}

	// 실행부
	if (m_tState.Can_Update())
	{
		if (CKeyMgr::Get_Instance()->Key_Down('A'))
		{
			if (!m_OriginText_List.IsEmpty())
			{
				m_tState.Set_State(ESTATE::START);
			}
			else
			{
				m_tState.Set_State(ESTATE::CLOSE);
				// 외부에 연락
				Call_Func_SendResult();
			}
		}
	}

	// 탈출부
	if (m_tState.IsState_Exit())
	{

	}
}
