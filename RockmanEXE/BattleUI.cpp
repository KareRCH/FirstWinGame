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

	// ���� ǥ�� ��ǥ
	g.TranslateTransform(m_tInfo.fX + fScrollX, m_tInfo.fY + fScrollY);
	g.ScaleTransform(1.f, 1.f);
	// ��ο�
	g.DrawImage(
		pImage, 
		0, 0,	// �̹��� ������
		0, 0,	// ���� �̹��� �ڸ��� ������ ����
		pImage->GetWidth(), pImage->GetHeight(),	// �������� �ڸ� ������
		Gdp::UnitPixel
	);

	MoveToEx(hDC, (int)m_tInfo.fX, (int)m_tInfo.fY, NULL);
	Ellipse(hDC, (int)m_tInfo.fX - 3, (int)m_tInfo.fY - 3, (int)m_tInfo.fX + 3, (int)m_tInfo.fY + 3);
}
