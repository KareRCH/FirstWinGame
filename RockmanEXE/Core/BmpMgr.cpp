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

void CBmpMgr::Draw_BMP_Strip(HDC hDC, const TCHAR* pImgKey, FRAME tFrame, CVector3<float> vecPos, bool bAllowScroll)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(pImgKey);

	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScollY();

	GdiTransparentBlt(hDC,
		(int)vecPos.x - (int)tFrame.iOffsetX - iScrollX * (int)bAllowScroll,
		(int)vecPos.y - (int)tFrame.iOffsetY - iScrollY * (int)bAllowScroll,
		tFrame.iFrameWidth, tFrame.iFrameHeight,
		hMemDC,			// 비트맵 이미지를 담고 있는 DC
		(tFrame.iFrameStart + tFrame.iFrameCur) * tFrame.iFrameWidth, 0,
		tFrame.iFrameWidth, tFrame.iFrameHeight,
		RGB(255, 255, 255)); // 제거하고자 하는 색상
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

	g.TranslateTransform(tInfo.fX - fScrollX * (float)bAllowScroll, tInfo.fY - fScrollY * (float)bAllowScroll);

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

	g.TranslateTransform(float(int(vecPos.x - fScrollX * (float)bAllowScroll)), 
		float(int(vecPos.y - vecPos.z - fScrollY * (float)bAllowScroll)));
	g.ScaleTransform((float)vecDir.x, (float)vecDir.y);

	// 쉽샵 버그 땜에 복잡한 식으로 잡은 모습이다.
	g.DrawImage(
		pImage, (-(tFrame.iOffsetX)), (-(tFrame.iOffsetY)),
		((tFrame.iFrameStart + tFrame.iFrameCur) * tFrame.iFrameWidth - 1),
		((tFrame.iMotion * tFrame.iFrameHeight)),
		tFrame.iFrameWidth, tFrame.iFrameHeight,
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

	g.TranslateTransform(float(int(vecPos.x - fScrollX * (float)bAllowScroll)),
		float(int(vecPos.y - vecPos.z - fScrollY * (float)bAllowScroll)));
	g.ScaleTransform(vecSize.x, vecSize.y);

	// 쉽샵 버그 땜에 복잡한 식으로 잡은 모습이다.
	g.DrawImage(
		pImage, (float)(-(tFrame.iOffsetX)), (float)(-(tFrame.iOffsetY)),
		(float)((tFrame.iFrameStart + tFrame.iFrameCur) * tFrame.iFrameWidth - 1),
		(float)((tFrame.iMotion * tFrame.iFrameHeight)),
		(float)tFrame.iFrameWidth, (float)tFrame.iFrameHeight,
		Gdp::UnitPixel
	);
}

void CBmpMgr::Draw_PNG_StripAlpha(HDC hDC, const TCHAR* pImgKey, FRAME tFrame, CVector3<float> vecPos, CVector2<int> vecDir, float fOpacity, bool bAllowScroll)
{
	// Strip 형태의 PNG를 표시하는데 쓰인다.
	// 단일용 PNG는 따로 관리한다.

	CBitMap* pBitMap = CBmpMgr::Get_Instance()->Find_CBitMap(pImgKey);
	if (!pBitMap) return;
	Gdp::Bitmap* pImage = pBitMap->Get_Image();
	Gdp::Graphics g(hDC);

	float fScrollX = CScrollMgr::Get_Instance()->Get_ScollX();
	float fScrollY = CScrollMgr::Get_Instance()->Get_ScollY();

	g.TranslateTransform(float(int(vecPos.x - fScrollX * (float)bAllowScroll)),
		float(int(vecPos.y - vecPos.z - fScrollY * (float)bAllowScroll)));
	g.ScaleTransform((float)vecDir.x, (float)vecDir.y);

	if (fOpacity < 1.f)
	{
		Gdp::ColorMatrix colorMatrix = {
			1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f, fOpacity, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f, 1.0f
		};

		Gdp::ImageAttributes attr;
		attr.SetColorMatrix(&colorMatrix, Gdp::ColorMatrixFlagsDefault, Gdp::ColorAdjustTypeBitmap);

		Gdp::Rect rc = {
			-(tFrame.iOffsetX), -(tFrame.iOffsetY),
			tFrame.iFrameWidth, tFrame.iFrameHeight
		};

		// 쉽샵 버그 땜에 복잡한 식으로 잡은 모습이다.
		g.DrawImage(
			pImage, rc,
			(tFrame.iFrameStart + tFrame.iFrameCur) * tFrame.iFrameWidth - 1,
			(tFrame.iMotion * tFrame.iFrameHeight),
			tFrame.iFrameWidth,
			tFrame.iFrameHeight,
			Gdp::UnitPixel,
			&attr
		);
	}
	else
	{
		// 쉽샵 버그 땜에 복잡한 식으로 잡은 모습이다.
		g.DrawImage(
			pImage, -(tFrame.iOffsetX), -(tFrame.iOffsetY),
			(tFrame.iFrameStart + tFrame.iFrameCur) * tFrame.iFrameWidth - 1,
			tFrame.iMotion * tFrame.iFrameHeight,
			tFrame.iFrameWidth, tFrame.iFrameHeight,
			Gdp::UnitPixel
		);
	}
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

	g.TranslateTransform(tInfo.fX - fScrollX * (float)bAllowScroll, tInfo.fY - fScrollY * (float)bAllowScroll);

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

	g.TranslateTransform(tInfo.fX - fScrollX * (float)bAllowScroll, tInfo.fY - fScrollY * (float)bAllowScroll);

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

	g.TranslateTransform(tInfo.fX - fScrollX * (float)bAllowScroll, tInfo.fY - fScrollY * (float)bAllowScroll);

	g.DrawImage(
		pImage, -(tFrame.iOffsetX), -(tFrame.iOffsetY),
		srcx, srcy, src_width, src_height,
		Gdp::UnitPixel
	);
}

void CBmpMgr::Draw_PNG_Alpha(HDC hDC, const TCHAR* pImgKey, INFO tInfo, FRAME tFrame, int srcx, int srcy, float fOpacity, bool bAllowScroll)
{
	CBitMap* pBitMap = CBmpMgr::Get_Instance()->Find_CBitMap(pImgKey);
	if (!pBitMap) return;
	Gdp::Bitmap* pImage = pBitMap->Get_Image();
	Gdp::Graphics g(hDC);

	float fScrollX = CScrollMgr::Get_Instance()->Get_ScollX();
	float fScrollY = CScrollMgr::Get_Instance()->Get_ScollY();

	g.TranslateTransform(float(int(tInfo.fX - fScrollX * (float)bAllowScroll)),
		float(int(tInfo.fY - fScrollY * (float)bAllowScroll)));

	if (fOpacity < 1.f)
	{
		Gdp::ColorMatrix colorMatrix = {
			1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f, fOpacity, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f, 1.0f
		};

		Gdp::ImageAttributes attr;
		attr.SetColorMatrix(&colorMatrix, Gdp::ColorMatrixFlagsDefault, Gdp::ColorAdjustTypeBitmap);

		Gdp::Rect rc = {
			-(tFrame.iOffsetX), -(tFrame.iOffsetY),
			tFrame.iFrameWidth, tFrame.iFrameHeight
		};

		// 쉽샵 버그 땜에 복잡한 식으로 잡은 모습이다.
		g.DrawImage(
			pImage, rc,
			srcx, srcy,
			tFrame.iFrameWidth, tFrame.iFrameHeight,
			Gdp::UnitPixel,
			&attr
		);
	}
	else
	{
		// 쉽샵 버그 땜에 복잡한 식으로 잡은 모습이다.
		g.DrawImage(
			pImage, -(tFrame.iOffsetX), -(tFrame.iOffsetY),
			srcx, srcy, tFrame.iFrameWidth, tFrame.iFrameHeight,
			Gdp::UnitPixel
		);
	}
}

void CBmpMgr::Draw_Test_Circle(HDC hDC, INFO tInfo, int iSize)
{
	MoveToEx(hDC, (int)tInfo.fX, (int)tInfo.fY, NULL);
	Ellipse(hDC, (int)tInfo.fX - iSize, (int)tInfo.fY - iSize, (int)tInfo.fX + iSize, (int)tInfo.fY + iSize);
}

void CBmpMgr::Draw_Text_Circle_Vec3(HDC hDC, CVector3<float> vecPos, int iSize, bool bAllowScroll)
{
	float fScrollX = CScrollMgr::Get_Instance()->Get_ScollX();
	float fScrollY = CScrollMgr::Get_Instance()->Get_ScollY();

	MoveToEx(hDC, (int)vecPos.x - (int)fScrollX * (int)bAllowScroll, 
		(int)vecPos.y + (int)vecPos.z - (int)fScrollY * (int)bAllowScroll, 
		NULL);
	Ellipse(hDC, 
		(int)vecPos.x - iSize - (int)fScrollX * (int)bAllowScroll, 
		(int)vecPos.y - (int)vecPos.z - iSize - (int)fScrollY * (int)bAllowScroll, 
		(int)vecPos.x + iSize - (int)fScrollX * (int)bAllowScroll,
		(int)vecPos.y - (int)vecPos.z + iSize - (int)fScrollY * (int)bAllowScroll);
}
