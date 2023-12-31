#include "Scene_TitleScreen.h"

#include "KeyMgr.h"
#include "BmpMgr.h"
#include "SoundMgr.h"
#include "Manager/AnimationTable.h"
#include "SceneMgr.h"

void CScene_TitleScreen::Initialize()
{
	wstring sText = L"./RockmanEXE/Resource/background/";
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"title_gregar.png").c_str(), L"Title_Gregar");
	CBmpMgr::Get_Instance()->Insert_Bmp((sText + L"title_gregar.bmp").c_str(), L"BMP_Title_Gregar");

	Add_Frame(L"BMP_Title_Gregar");
	CAnimationTable::Get_Instance()->Load_AnimData(L"1", *Get_Frame());

	CSoundMgr::Get_Instance()->Play_BGM(const_cast<TCHAR*>(L"loop_theme.mp3"), 1.f);
}

void CScene_TitleScreen::Update(float fDeltaTime)
{
	if (CKeyMgr::Get_Instance()->Key_Down(VK_SPACE))
	{
		CSoundMgr::Get_Instance()->Play_Sound(const_cast<TCHAR*>(L"new_game.wav"), SYSTEM_EFFECT, 1.f);
		CSceneMgr::Get_Instance()->Scene_Change(SC_WORLD1);
	}

	Move_Frame();
}

void CScene_TitleScreen::Late_Update(float fDeltaTime)
{
}

void CScene_TitleScreen::Render(HDC hDC)
{
	CVector3<float> tVecPos = CVector3<float>();
	tVecPos.x = (float)(ROCKMAN_EXECX / 2 - 1);
	tVecPos.y = (float)(ROCKMAN_EXECY / 2);
	CBmpMgr::Get_Instance()->Draw_BMP_Strip(hDC, Get_FrameKey(), Get_FrameData(), tVecPos, false);
}

void CScene_TitleScreen::Release()
{
}

void CScene_TitleScreen::Move_Frame()
{
	auto& tFrame = m_pairFrame.second;
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
