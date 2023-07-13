#include "TextBox.h"

#include "ObjMgr.h"
#include "KeyMgr.h"
#include "BmpMgr.h"
#include "Manager/AnimationTable.h"
#include <SoundMgr.h>

void CTextBox::Initialize(void)
{
	CObjMgr::Get_Instance()->Add_Object(UI, this);

#pragma region �̹��� ǥ��

#pragma endregion


	m_tState.Set_State(ESTATE::OPEN);
	m_tState.Add_Func(ESTATE::OPEN, &CTextBox::OpenTextBox);
	m_tState.Add_Func(ESTATE::OPEND, &CTextBox::OpendTextBox);
	m_tState.Add_Func(ESTATE::CLOSE, &CTextBox::CloseTextBox);
	m_tState.Add_Func(ESTATE::START, &CTextBox::FlowStart);
	m_tState.Add_Func(ESTATE::FLOW, &CTextBox::FlowText);
	m_tState.Add_Func(ESTATE::END, &CTextBox::FlowEnd);
}

int CTextBox::Update(float fDeltaTime)
{
	m_tState.Get_StateFunc()(this, fDeltaTime);

	return 0;
}

void CTextBox::Late_Update(float fDeltaTime)
{

}

void CTextBox::Render(HDC hDC)
{
	// �ؽ�Ʈ �ڽ� ���

	// �ؽ�Ʈ ���
}

void CTextBox::Release(void)
{

}

void CTextBox::Collide(CObj* _pDst)
{

}

void CTextBox::OpenTextBox(float fDeltaTime)
{
	// ���Ժ�
	if (m_tState.IsState_Entered())
	{
		//Set_FrameKey(0, L"OVW_Rockman_Warped");
		//CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
	}

	// �����
	if (m_tState.Can_Update())
	{

	}

	// Ż���
	if (m_tState.IsState_Exit())
	{

	}
}

void CTextBox::OpendTextBox(float fDeltaTime)
{
	// ���Ժ�
	if (m_tState.IsState_Entered())
	{
		//Set_FrameKey(0, L"OVW_Rockman_Warped");
		//CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
	}

	// �����
	if (m_tState.Can_Update())
	{

	}

	// Ż���
	if (m_tState.IsState_Exit())
	{

	}
}

void CTextBox::CloseTextBox(float fDeltaTime)
{
	// ���Ժ�
	if (m_tState.IsState_Entered())
	{
		//Set_FrameKey(0, L"OVW_Rockman_Warped");
		//CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
	}

	// �����
	if (m_tState.Can_Update())
	{

	}

	// Ż���
	if (m_tState.IsState_Exit())
	{

	}
}

void CTextBox::FlowStart(float fDeltaTime)
{
	// ���Ժ�
	if (m_tState.IsState_Entered())
	{
		//Set_FrameKey(0, L"OVW_Rockman_Warped");
		//CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
	}

	// �����
	if (m_tState.Can_Update())
	{

	}

	// Ż���
	if (m_tState.IsState_Exit())
	{

	}
}

void CTextBox::FlowText(float fDeltaTime)
{
	// ���Ժ�
	if (m_tState.IsState_Entered())
	{
		//Set_FrameKey(0, L"OVW_Rockman_Warped");
		//CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
	}

	// �����
	if (m_tState.Can_Update())
	{

	}

	// Ż���
	if (m_tState.IsState_Exit())
	{

	}
}

void CTextBox::FlowEnd(float fDeltaTime)
{
	// ���Ժ�
	if (m_tState.IsState_Entered())
	{
		//Set_FrameKey(0, L"OVW_Rockman_Warped");
		//CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
	}

	// �����
	if (m_tState.Can_Update())
	{

	}

	// Ż���
	if (m_tState.IsState_Exit())
	{

	}
}
