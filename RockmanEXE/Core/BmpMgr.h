#pragma once

#include "Define.h"
#include "BitMap.h"

class CBmpMgr
{
private:
	CBmpMgr() {}
	~CBmpMgr() { Release(); }

public:
	void		Release();
	void		Insert_Bmp(const TCHAR* pFilePath, const TCHAR* pImgKey);
	void		Insert_PNG(const TCHAR* pFilePath, const TCHAR* pImgKey);

	HDC			Find_Img(const TCHAR* pImgKey);
	CBitMap*	Find_CBitMap(const TCHAR* pImgKey);

	void		Draw_BMP_Strip(HDC hDC, const TCHAR* pImgKey, FRAME tFrame, CVector3<float> vecPos, bool bAllowScroll = true);

	void		Draw_PNG_Strip(HDC hDC, const TCHAR* pImgKey, INFO tInfo, FRAME tFrame, bool bAllowScroll = true);
	void		Draw_PNG_Strip(HDC hDC, const TCHAR* pImgKey, FRAME tFrame, CVector3<float> vecPos, CVector2<int> vecDir, bool bAllowScroll = true);
	void		Draw_PNG_StripScale(HDC hDC, const TCHAR* pImgKey, FRAME tFrame, CVector3<float> vecPos, CVector2<float> vecSize, bool bAllowScroll = true);
	void		Draw_PNG_StripAlpha(HDC hDC, const TCHAR* pImgKey, FRAME tFrame, CVector3<float> vecPos, CVector2<int> vecDir, float fOpacity, bool bAllowScroll = true);

	void		Draw_PNG(HDC hDC, const TCHAR* pImgKey, INFO tInfo, FRAME tFrame, bool bAllowScroll = true);
	void		Draw_PNG(HDC hDC, const TCHAR* pImgKey, INFO tInfo, FRAME tFrame, int srcx, int srcy, bool bAllowScroll = true);
	void		Draw_PNG(HDC hDC, const TCHAR* pImgKey, INFO tInfo, FRAME tFrame, int srcx, int srcy, int src_width, int src_height, bool bAllowScroll);

	void		Draw_PNG_Alpha(HDC hDC, const TCHAR* pImgKey, INFO tInfo, FRAME tFrame, int srcx, int srcy, float fOpacity, bool bAllowScroll = true);

	void		Draw_Test_Circle(HDC hDC, INFO tInfo, int iSize = 3);
	void		Draw_Text_Circle_Vec3(HDC hDC, CVector3<float> vecPos, int iSize = 3, bool bAllowScroll = true);
	
private: // �̱���
	static CBmpMgr* m_pInstance;
public:
	static CBmpMgr*		Get_Instance()
	{
		if (!m_pInstance)
		{
			m_pInstance = new CBmpMgr;
		}

		return m_pInstance;
	}
	static void		Destroy_Instance()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

private: // ��Ʈ�� ����
	map<const TCHAR*, CBitMap*>			m_mapBit;

};

