#include "SceneMgr.h"

CSceneMgr*	CSceneMgr::m_pInstance = nullptr;

CSceneMgr::CSceneMgr()
	: m_eCurScene(SC_LOGO), m_ePreScene(SC_END), m_pScene(nullptr)
{
}

CSceneMgr::~CSceneMgr()
{
	Release();
}

void CSceneMgr::Scene_Change(SCENEID eScene)
{
	return;
	m_eCurScene = eScene;

	if (m_ePreScene != m_eCurScene)
	{
		Safe_Delete(m_pScene);

		switch (m_eCurScene)
		{
		case SC_LOGO:
			//m_pScene = new CLogo;
			break;

		case SC_MENU:
			//m_pScene = new CMyMenu;
			break;

		case SC_EDIT:
			break;

		case SC_STAGE:
			//m_pScene = new CStage;
			break;
		}

		m_pScene->Initialize();

		m_ePreScene = m_eCurScene;
	}

}

void CSceneMgr::Update(float fDeltaTime)
{
	if (m_pScene)
		m_pScene->Update(fDeltaTime);
}

void CSceneMgr::Late_Update(float fDeltaTime)
{
	if (m_pScene)
		m_pScene->Late_Update(fDeltaTime);
}

void CSceneMgr::Render(HDC hDC)
{
	if (m_pScene)
		m_pScene->Render(hDC);
}

void CSceneMgr::Release()
{
	Safe_Delete(m_pScene);
}
