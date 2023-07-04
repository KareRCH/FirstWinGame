#include "Battle/BattleUI.h"

#include "BmpMgr.h"
#include "ScrollMgr.h"

CBattleUI* CBattleUI::m_pInstance = nullptr;

void CBattleUI::Initialize()
{
	TCHAR sText[100];
	const TCHAR* sDir = L"./RockmanEXE/Resource/battle/ui/";
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"ui_enemy_info.png"), L"NBT_UI_Enemy_Info_BG");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"ui_hp_bg.png"), L"NBT_UI_Hp_BG");
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"ui_pet.png"), L"NBT_UI_Pet");
}

void CBattleUI::Release()
{
}

void CBattleUI::Update(float fDeltaTime)
{
}

void CBattleUI::Late_Update(float fDeltaTime)
{
}

void CBattleUI::Render(HDC hDC)
{
	CBitMap* pBitMap = CBmpMgr::Get_Instance()->Find_CBitMap(L"NBT_UI_Pet");
	if (!pBitMap) return;

	Gdp::Bitmap* pImage = pBitMap->Get_Image();
	Gdp::Graphics g(hDC);

	float fScrollX = CScrollMgr::Get_Instance()->Get_ScollX();
	float fScrollY = CScrollMgr::Get_Instance()->Get_ScollY();

	// 실제 표시 좌표
	g.TranslateTransform(m_tInfo.fX + fScrollX, m_tInfo.fY + fScrollY);
	g.ScaleTransform(1.f, 1.f);
	// 드로우
	g.DrawImage(
		pImage, 
		0, 0,	// 이미지 오프셋
		0, 0,	// 원본 이미지 자르기 시작할 원점
		pImage->GetWidth(), pImage->GetHeight(),	// 원본에서 자를 사이즈
		Gdp::UnitPixel
	);

	MoveToEx(hDC, (int)m_tInfo.fX, (int)m_tInfo.fY, NULL);
	Ellipse(hDC, (int)m_tInfo.fX - 3, (int)m_tInfo.fY - 3, (int)m_tInfo.fX + 3, (int)m_tInfo.fY + 3);
}
