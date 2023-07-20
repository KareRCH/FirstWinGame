#include "Vfx_ExplosionVector.h"

#include <BmpMgr.h>
#include <Manager/AnimationTable.h>
#include <SoundMgr.h>


void CVfx_ExplosionVector::Initialize(void)
{
	CVisualFX::Initialize_VFX();

#pragma region 이미지 추가
	wstring sText = L"./RockmanEXE/Resource/battle/vfx/explosion/";
	CBmpMgr::Get_Instance()->Insert_PNG((sText + L"explosion_vector.png").c_str(), L"VFX_Explosion_Vector");

	Set_FrameKey(0, L"VFX_Explosion_Vector");
	CAnimationTable::Get_Instance()->Load_AnimData(L"1", Get_FrameList()[0]);
#pragma endregion

	CSoundMgr::Get_Instance()->Play_Sound(const_cast<TCHAR*>(L"explode_once.wav"), SOUND_VFX, 1.f);
}

int CVfx_ExplosionVector::Update(float fDeltaTime)
{
	if (Get_Frame(0).IsFrameEnd())
		Set_Dead();

	Move_Frame();
	return 0;
}

void CVfx_ExplosionVector::Late_Update(float fDeltaTime)
{
}

void CVfx_ExplosionVector::Render(HDC hDC)
{
	CBmpMgr::Get_Instance()->Draw_PNG_Strip(hDC, Get_FrameKey(0), Get_Frame(0), m_vecPos, CVector2<int>(1, 1));
}

void CVfx_ExplosionVector::Release(void)
{
}

void CVfx_ExplosionVector::Collide(CObj* _pDst)
{
}
