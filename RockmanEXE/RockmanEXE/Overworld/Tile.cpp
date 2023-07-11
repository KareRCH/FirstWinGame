
#include "Define.h"
#include "Tile.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"


CTile::CTile()
{
}


CTile::~CTile()
{
	Release();
}

void CTile::Initialize(void)
{
	m_tInfo.fCX = TILECX;
	m_tInfo.fCY = TILECY;

	m_vecBox = CVector3<float>(32.f, 16.f, 1.f);

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Edit/QuaterTile.bmp", L"Tile");
}

int CTile::Update(float fDeltaTime)
{

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CTile::Late_Update(float fDeltaTime)
{
}

void CTile::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScollY();

	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Tile");
	
	GdiTransparentBlt(hDC,
		(int)m_vecPos.x - (int)m_vecBox.x - iScrollX,
		(int)m_vecPos.y - (int)m_vecBox.y - iScrollY,
		TILECX, TILECY,
		hMemDC,			// 비트맵 이미지를 담고 있는 DC
		TILECX * m_iDrawID, 0,
		TILECX, TILECY,
		RGB(255, 255, 255)); // 제거하고자 하는 색상
}

void CTile::Release(void)
{
}

void CTile::Collide(CObj* _pDst)
{
}
