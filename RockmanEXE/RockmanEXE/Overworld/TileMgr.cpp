
#include "TileMgr.h"
#include "AbstractFactory.h"
#include "ScrollMgr.h"

CTileMgr* CTileMgr::m_pInstance = nullptr;

CTileMgr::CTileMgr() : m_tPos()
{
	m_tPos.fX = -55.f;
	m_tPos.fY = 489.f;
	m_vecTile.reserve(TILEX * TILEY);
}

CTileMgr::~CTileMgr()
{
	Release();
}

void CTileMgr::Initialize()
{
	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			// 타일 생성 좌표
			//float	fX = (float)(TILECX >> 1) + (TILECX * j) + m_tPos.fX;
			//float	fY = (float)(TILECY >> 1) + (TILECY * i) + m_tPos.fY;

			// 쿼터뷰 변환
			float fX = (j + i) * (float)(TILECX >> 1) + m_tPos.fX;
			float fY = (-1.f) * (j - i) * (float)(TILECY >> 1) + m_tPos.fY;

			CObj*		pObj = CTile_Factory::Create(CVector3<float>(fX, fY, 0.f));
			m_vecTile.push_back(pObj);
		}
	}
}

void CTileMgr::Update(float fDeltaTime)
{
	for (auto& iter : m_vecTile)
		iter->Update(fDeltaTime);
}

void CTileMgr::Late_Update(float fDeltaTime)
{
	for (auto& iter : m_vecTile)
		iter->Late_Update(fDeltaTime);
}

void CTileMgr::Render(HDC hDC)
{
	/*int iCullX = (int)abs((CScrollMgr::Get_Instance()->Get_ScollX()) / TILECX);
	int iCullY = (int)abs((CScrollMgr::Get_Instance()->Get_ScollY()) / TILECY);

	int	iMaxX = iCullX + (ROCKMAN_EXECX / TILECX) + 2;
	int	iMaxY = iCullY + (ROCKMAN_EXECY / TILECY) + 2;

	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			int iIndex = i * TILEX + j;

			if(0 > iIndex || size_t(iIndex) >= m_vecTile.size())
				continue;

			m_vecTile[iIndex]->Render(hDC);
		}
	}*/

	//POINT	pt;
	//GetCursorPos(&pt);
	//ScreenToClient(g_hWnd, &pt);

	//RECT	rc;
	//GetClientRect(g_hWnd, &rc);

	//// 클라이언트 to 게임 좌표
	//pt.x = LONG((float)pt.x * ((float)ROCKMAN_EXECX / (float)rc.right));
	//pt.y = LONG((float)pt.y * ((float)ROCKMAN_EXECY / (float)rc.bottom));

	//// 타일 시작 좌표
	//pt.x += (int)CScrollMgr::Get_Instance()->Get_ScollX() - m_tPos.fX;
	//pt.y += (int)CScrollMgr::Get_Instance()->Get_ScollY() - m_tPos.fY;

	//int tileX = (pt.x / (TILECX >> 1) - pt.y / (TILECY >> 1)) * (TILECX >> 1) / TILECX;
	//int tileY = (pt.y / (TILECY >> 1) + pt.x / (TILECX >> 1)) * (TILECY >> 1) / TILECY;

	//WCHAR text[100];
	//_stprintf_s(text, L"%d %d", tileX, tileY);
	//TextOutW(hDC, 10, 10, text, lstrlen(text));
}

void CTileMgr::Release()
{
	for_each(m_vecTile.begin(), m_vecTile.end(), 
		[](CObj* pTemp)
		{
			if (pTemp)
			{ 
				delete pTemp; 
				pTemp = nullptr; 
			}
		});

	m_vecTile.clear();
	m_vecTile.shrink_to_fit();
}

void CTileMgr::Picking_Tile(POINT pt, int _iDrawID, int _iOption)
{
	RECT	rc;
	GetClientRect(g_hWnd, &rc);

	pt.x = LONG((float)pt.x * ((float)ROCKMAN_EXECX / (float)rc.right));
	pt.y = LONG((float)pt.y * ((float)ROCKMAN_EXECY / (float)rc.bottom));

	pt.x += (int)CScrollMgr::Get_Instance()->Get_ScollX() - (int)m_tPos.fX;
	pt.y += (int)CScrollMgr::Get_Instance()->Get_ScollY() - (int)m_tPos.fY;

	int		x = (pt.x / (TILECX >> 1) - pt.y / (TILECY >> 1)) * (TILECX >> 1) / TILECX;
	int		y = (pt.y / (TILECY >> 1) + pt.x / (TILECX >> 1)) * (TILECY >> 1) / TILECY;

	int		iIndex = y * TILEX + x;

	if (0 > iIndex || (size_t)iIndex >= m_vecTile.size())
		return;

	dynamic_cast<CTile*>(m_vecTile[iIndex])->Set_ID(_iDrawID, _iOption);

}

void CTileMgr::Reset()
{
	for (auto& item : m_vecTile)
	{
		dynamic_cast<CTile*>(item)->Set_ID(0, 0);
	}
}

void CTileMgr::Save_Tile()
{
	HANDLE		hFile = CreateFile(L"./RockmanEXE/Resource/data/Tile.dat", GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if (INVALID_HANDLE_VALUE == hFile)
		return;

	int		iDrawID = 0, iOption = 0;
	DWORD	dwByte = 0;

	// 원점 저장
	WriteFile(hFile, &m_tPos, sizeof(INFO), &dwByte, NULL);

	// 타일 저장
	for (auto& iter : m_vecTile)
	{
		iDrawID = dynamic_cast<CTile*>(iter)->Get_DrawID();
		iOption = dynamic_cast<CTile*>(iter)->Get_Option();

		WriteFile(hFile, &(iter->Get_Info()), sizeof(INFO), &dwByte, NULL);
		WriteFile(hFile, &iDrawID, sizeof(int), &dwByte, NULL);
		WriteFile(hFile, &iOption, sizeof(int), &dwByte, NULL);
	}

	CloseHandle(hFile);

	//MessageBox(g_hWnd, L"Tile Save", L"성공", MB_OK);
}

void CTileMgr::Load_Tile()
{
	HANDLE		hFile = CreateFile(L"./RockmanEXE/Resource/data/Tile.dat", GENERIC_READ, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (INVALID_HANDLE_VALUE == hFile)
		return;

	INFO	tInfo{};
	int		iDrawID = 0, iOption = 0;
	DWORD	dwByte = 0;

	Release();

	// 원점 불러오기
	ReadFile(hFile, &m_tPos, sizeof(INFO), &dwByte, NULL);
	while(true)
	{
		ReadFile(hFile, &tInfo, sizeof(INFO), &dwByte, NULL);
		ReadFile(hFile, &iDrawID, sizeof(int), &dwByte, NULL);
		ReadFile(hFile, &iOption, sizeof(int), &dwByte, NULL);

		if (0 == dwByte)
			break;

		CObj*	pObj = CTile_Factory::Create(CVector3<float>(tInfo.fX, tInfo.fY, 0.f));
		dynamic_cast<CTile*>(pObj)->Set_ID(iDrawID, iOption);

		m_vecTile.push_back(pObj);
	}

	CloseHandle(hFile);

	//MessageBox(g_hWnd, L"Tile Load", L"성공", MB_OK);
}
