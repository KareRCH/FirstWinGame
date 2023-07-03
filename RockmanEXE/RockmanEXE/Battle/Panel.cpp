#include "Panel.h"

#include "BmpMgr.h"
#include "ScrollMgr.h"

void CPanel::Initialize()
{
#pragma region �̹��� �߰�
	TCHAR sText[100];
	const TCHAR* sDir = L"./RockmanEXE/Resource/battle/background/";
	lstrcpy(sText, sDir);
	CBmpMgr::Get_Instance()->Insert_PNG(lstrcat(sText, L"bg_panel.png"), L"BG_Panel");
#pragma endregion
}

void CPanel::Update(float fDeltaTime)
{

}

void CPanel::Late_Update(float fDeltaTime)
{

}

void CPanel::Render(HDC hDC)
{
	CBitMap* pBitMap = CBmpMgr::Get_Instance()->Find_CBitMap(L"BG_Panel");
	Gdp::Bitmap* pImage = pBitMap->Get_Image();
	Gdp::Graphics g(hDC);

	float fScrollX = CScrollMgr::Get_Instance()->Get_ScollX();
	float fScrollY = CScrollMgr::Get_Instance()->Get_ScollY();

	g.SetInterpolationMode(Gdp::InterpolationModeBicubic);
	g.TranslateTransform(m_tInfo.fX + fScrollX, m_tInfo.fY + fScrollY);

	g.DrawImage(
		pImage, -20, -15,	// �̹��� ���������� ��ü
		0, 0,
		40, 30,				// �̹��� ���� ũ��� ��ü
		Gdp::UnitPixel
	);
}

void CPanel::Release()
{

}
