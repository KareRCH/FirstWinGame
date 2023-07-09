#include "BmpMgr.h"

#include "ScrollMgr.h"

CBmpMgr*	CBmpMgr::m_pInstance = nullptr;

void CBmpMgr::Release()
{
	for_each(m_mapBit.begin(), m_mapBit.end(), [](pair<const TCHAR*, CBitMap*> Pair) {
		Safe_Delete(Pair.first);
		});
	for_each(m_mapBit.begin(), m_mapBit.end(), CDeleteMap());
	m_mapBit.clear();
}

void CBmpMgr::Insert_Bmp(const TCHAR * pFilePath, const TCHAR * pImgKey)
{
	auto iter = find_if(m_mapBit.begin(), m_mapBit.end(), CTag_Finder(pImgKey));

	if (iter == m_mapBit.end())
	{
		CBitMap*		pBmp = new CBitMap;
		pBmp->Load_BMP(pFilePath);

		TCHAR* sText = new TCHAR[100];
		lstrcpy(sText, pImgKey);
		m_mapBit.insert({ sText, pBmp });
	}
}

void CBmpMgr::Insert_PNG(const TCHAR* pFilePath, const TCHAR* pImgKey)
{
	auto iter = find_if(m_mapBit.begin(), m_mapBit.end(), CTag_Finder(pImgKey));

	if (iter == m_mapBit.end())
	{
		CBitMap* pBmp = new CBitMap;
		pBmp->Load_PNG(pFilePath);

		TCHAR* sText = new TCHAR[100];
		lstrcpy(sText, pImgKey);
		m_mapBit.insert({ sText, pBmp });
	}
}

HDC CBmpMgr::Find_Img(const TCHAR * pImgKey)
{
	auto iter = find_if(m_mapBit.begin(), m_mapBit.end(), CTag_Finder(pImgKey));

	if (iter == m_mapBit.end())
		return nullptr;

	return iter->second->Get_MemDC();
}

CBitMap* CBmpMgr::Find_CBitMap(const TCHAR* pImgKey)
{
	auto iter = find_if(m_mapBit.begin(), m_mapBit.end(), CTag_Finder(pImgKey));

	if (iter == m_mapBit.end())
		return nullptr;

	return iter->second;
}

void CBmpMgr::Draw_PNG_Strip(HDC hDC, const TCHAR* pImgKey, INFO tInfo, FRAME tFrame, bool bAllowScroll)
{
	// Strip 형태의 PNG를 표시하는데 쓰인다.
	// 단일용 PNG는 따로 관리한다.

	CBitMap* pBitMap = CBmpMgr::Get_Instance()->Find_CBitMap(pImgKey);
	if (!pBitMap) return;
	Gdp::Bitmap* pImage = pBitMap->Get_Image();
	Gdp::Graphics g(hDC);

	float fScrollX = CScrollMgr::Get_Instance()->Get_ScollX();
	float fScrollY = CScrollMgr::Get_Instance()->Get_ScollY();

	g.TranslateTransform(tInfo.fX + fScrollX * (float)bAllowScroll, tInfo.fY + fScrollY * (float)bAllowScroll);

	// 쉽샵 버그 땜에 복잡한 식으로 잡은 모습이다.
	g.DrawImage(
		pImage, -(tFrame.iOffsetX) - ((tFrame.iFrameStart + tFrame.iFrameCur) > 0), -(tFrame.iOffsetY) - (tFrame.iMotion > 0),
		(tFrame.iFrameStart + tFrame.iFrameCur) * tFrame.iFrameWidth - ((tFrame.iFrameStart + tFrame.iFrameCur) > 0),
		(tFrame.iMotion * tFrame.iFrameHeight) - (tFrame.iMotion > 0),
		tFrame.iFrameWidth, tFrame.iFrameHeight,
		Gdp::UnitPixel
	);
}

void CBmpMgr::Draw_PNG_Strip(HDC hDC, const TCHAR* pImgKey, FRAME tFrame, CVector3<float> vecPos, CVector2<int> vecDir, bool bAllowScroll)
{
	// Strip 형태의 PNG를 표시하는데 쓰인다.
	// 단일용 PNG는 따로 관리한다.

	CBitMap* pBitMap = CBmpMgr::Get_Instance()->Find_CBitMap(pImgKey);
	if (!pBitMap) return;
	Gdp::Bitmap* pImage = pBitMap->Get_Image();
	Gdp::Graphics g(hDC);

	float fScrollX = CScrollMgr::Get_Instance()->Get_ScollX();
	float fScrollY = CScrollMgr::Get_Instance()->Get_ScollY();

	g.TranslateTransform(vecPos.x + fScrollX * (float)bAllowScroll, vecPos.y - vecPos.z + fScrollY * (float)bAllowScroll);
	g.ScaleTransform((float)vecDir.x, (float)vecDir.y);
	//g.SetSmoothingMode(Gdp::SmoothingModeAntiAlias);
	g.SetInterpolationMode(Gdp::InterpolationModeNearestNeighbor);

	// 쉽샵 버그 땜에 복잡한 식으로 잡은 모습이다.
	g.DrawImage(
		pImage, (float)(-(tFrame.iOffsetX)), (float)(-(tFrame.iOffsetY)),
		(float)((tFrame.iFrameStart + tFrame.iFrameCur) * tFrame.iFrameWidth - 1),
		(float)((tFrame.iMotion * tFrame.iFrameHeight)),
		(float)tFrame.iFrameWidth, (float)tFrame.iFrameHeight,
		Gdp::UnitPixel
	);
}

void CBmpMgr::Draw_PNG_StripScale(HDC hDC, const TCHAR* pImgKey, FRAME tFrame, CVector3<float> vecPos, CVector2<float> vecSize, bool bAllowScroll)
{
	// Strip 형태의 PNG를 표시하는데 쓰인다.
	// 단일용 PNG는 따로 관리한다.

	CBitMap* pBitMap = CBmpMgr::Get_Instance()->Find_CBitMap(pImgKey);
	if (!pBitMap) return;
	Gdp::Bitmap* pImage = pBitMap->Get_Image();
	Gdp::Graphics g(hDC);

	float fScrollX = CScrollMgr::Get_Instance()->Get_ScollX();
	float fScrollY = CScrollMgr::Get_Instance()->Get_ScollY();

	g.TranslateTransform(vecPos.x + fScrollX * (float)bAllowScroll, vecPos.y - vecPos.z + fScrollY * (float)bAllowScroll);
	g.ScaleTransform(vecSize.x, vecSize.y);
	//g.SetSmoothingMode(Gdp::SmoothingModeAntiAlias);
	g.SetInterpolationMode(Gdp::InterpolationModeNearestNeighbor);

	// 쉽샵 버그 땜에 복잡한 식으로 잡은 모습이다.
	g.DrawImage(
		pImage, (float)(-(tFrame.iOffsetX)), (float)(-(tFrame.iOffsetY)),
		(float)((tFrame.iFrameStart + tFrame.iFrameCur) * tFrame.iFrameWidth - 1),
		(float)((tFrame.iMotion * tFrame.iFrameHeight)),
		(float)tFrame.iFrameWidth, (float)tFrame.iFrameHeight,
		Gdp::UnitPixel
	);
}

void CBmpMgr::Draw_PNG(HDC hDC, const TCHAR* pImgKey, INFO tInfo, FRAME tFrame, bool bAllowScroll)
{
	// Strip 형태의 PNG를 표시하는데 쓰인다.
	// 단일용 PNG는 따로 관리한다.

	CBitMap* pBitMap = CBmpMgr::Get_Instance()->Find_CBitMap(pImgKey);
	if (!pBitMap) return;
	Gdp::Bitmap* pImage = pBitMap->Get_Image();
	Gdp::Graphics g(hDC);

	float fScrollX = CScrollMgr::Get_Instance()->Get_ScollX();
	float fScrollY = CScrollMgr::Get_Instance()->Get_ScollY();

	g.TranslateTransform(tInfo.fX + fScrollX * (float)bAllowScroll, tInfo.fY + fScrollY * (float)bAllowScroll);

	g.DrawImage(
		pImage, -(tFrame.iOffsetX), -(tFrame.iOffsetY),
		0, 0, pImage->GetWidth(), pImage->GetHeight(),
		Gdp::UnitPixel
	);
}

void CBmpMgr::Draw_PNG(HDC hDC, const TCHAR* pImgKey, INFO tInfo, FRAME tFrame, int srcx, int srcy, bool bAllowScroll)
{
	// 단일용 PNG는 따로 관리한다.

	CBitMap* pBitMap = CBmpMgr::Get_Instance()->Find_CBitMap(pImgKey);
	if (!pBitMap) return;
	Gdp::Bitmap* pImage = pBitMap->Get_Image();
	Gdp::Graphics g(hDC);

	float fScrollX = CScrollMgr::Get_Instance()->Get_ScollX();
	float fScrollY = CScrollMgr::Get_Instance()->Get_ScollY();

	g.TranslateTransform(tInfo.fX + fScrollX * (float)bAllowScroll, tInfo.fY + fScrollY * (float)bAllowScroll);

	g.DrawImage(
		pImage, -(tFrame.iOffsetX), -(tFrame.iOffsetY),
		srcx, srcy, tFrame.iFrameWidth, tFrame.iFrameHeight,
		Gdp::UnitPixel
	);
}

void CBmpMgr::Draw_PNG(HDC hDC, const TCHAR* pImgKey, INFO tInfo, FRAME tFrame, int srcx, int srcy, int src_width, int src_height, bool bAllowScroll)
{
	// 단일용 PNG는 따로 관리한다.

	CBitMap* pBitMap = CBmpMgr::Get_Instance()->Find_CBitMap(pImgKey);
	if (!pBitMap) return;
	Gdp::Bitmap* pImage = pBitMap->Get_Image();
	Gdp::Graphics g(hDC);

	float fScrollX = CScrollMgr::Get_Instance()->Get_ScollX();
	float fScrollY = CScrollMgr::Get_Instance()->Get_ScollY();

	g.TranslateTransform(tInfo.fX + fScrollX * (float)bAllowScroll, tInfo.fY + fScrollY * (float)bAllowScroll);

	g.DrawImage(
		pImage, -(tFrame.iOffsetX), -(tFrame.iOffsetY),
		srcx, srcy, src_width, src_height,
		Gdp::UnitPixel
	);
}

void CBmpMgr::Draw_Test_Circle(HDC hDC, INFO tInfo, int iSize)
{
	MoveToEx(hDC, (int)tInfo.fX, (int)tInfo.fY, NULL);
	Ellipse(hDC, (int)tInfo.fX - iSize, (int)tInfo.fY - iSize, (int)tInfo.fX + iSize, (int)tInfo.fY + iSize);
}

void CBmpMgr::Draw_Text_Circle_Vec3(HDC hDC, CVector3<float> vecPos, int iSize)
{
	MoveToEx(hDC, (int)vecPos.x, (int)vecPos.y + (int)vecPos.z, NULL);
	Ellipse(hDC, (int)vecPos.x - iSize, (int)vecPos.y - (int)vecPos.z - iSize, (int)vecPos.x + iSize, (int)vecPos.y - (int)vecPos.z + iSize);
}
