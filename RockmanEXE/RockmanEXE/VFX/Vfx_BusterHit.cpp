#include "Vfx_BusterHit.h"

#include <BmpMgr.h>
#include <Manager/AnimationTable.h>
#include <SoundMgr.h>


void CVfx_BusterHit::Initialize(void)
{
	CVisualFX::Initialize_VFX();

#pragma region 이미지 추가
	wstring sText = L"./RockmanEXE/Resource/battle/vfx/hit/";
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"buster_hit.png").c_str(), L"NBT_Buster_Hit");

	Set_FrameKey(0, L"NBT_Buster_Hit");
	CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
#pragma endregion

	CSoundMgr::Get_Instance()->Play_Sound(const_cast<TCHAR*>(L"buster_hit.wav"), SOUND_VFX, 1.f);
}

int CVfx_BusterHit::Update(float fDeltaTime)
{
	if (Get_Frame(0).IsFrameEnd())
		Set_Dead();

	Move_Frame();
    return 0;
}

void CVfx_BusterHit::Late_Update(float fDeltaTime)
{
}

void CVfx_BusterHit::Render(HDC hDC)
{
	CBmpMgr::Get_Instance()->Draw_PNG_Strip(hDC, Get_FrameKey(0), Get_Frame(0), m_vecPos, CVector2<int>(1, 1));
}

void CVfx_BusterHit::Release(void)
{
}

void CVfx_BusterHit::Collide(CObj* _pDst)
{
}
