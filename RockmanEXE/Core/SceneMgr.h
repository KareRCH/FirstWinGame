#pragma once

#include "Define.h"
#include "Scene.h"
//#include "Logo.h"
//#include "MyMenu.h"
//
//#include "Stage.h"
#include "Scene/Scene_NetBattle.h"

/*
* 게임이 실행되는 씬을 실행시키는 매니저
* 이 매니저는 
*/

class CSceneMgr
{
private:
	CSceneMgr();
	~CSceneMgr();

public:
	void		Scene_Change(SCENEID eScene);
	void		Update(float fDeltaTime);
	void		Late_Update(float fDeltaTime);
	void		Render(HDC hDC);
	void		Release();

public:
	static CSceneMgr*		Get_Instance()
	{
		if (!m_pInstance)
		{
			m_pInstance = new CSceneMgr;
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

private:
	static CSceneMgr*		m_pInstance;
	CScene*					m_pScene;

	SCENEID					m_eCurScene;
	SCENEID					m_ePreScene;
};

// state 패턴 : 객체는 자신이 취할 수 있는 유한한 개수를 갖고, 그 중 반드시 단 하나의 상태만을 취한다는 의미의 패턴

