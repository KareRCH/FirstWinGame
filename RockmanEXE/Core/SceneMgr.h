#pragma once

#include "Define.h"
#include "Scene.h"
//#include "Logo.h"
//#include "MyMenu.h"
//
//#include "Stage.h"
#include "Scene/Scene_NetBattle.h"

/*
* ������ ����Ǵ� ���� �����Ű�� �Ŵ���
* �� �Ŵ����� 
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

// state ���� : ��ü�� �ڽ��� ���� �� �ִ� ������ ������ ����, �� �� �ݵ�� �� �ϳ��� ���¸��� ���Ѵٴ� �ǹ��� ����

