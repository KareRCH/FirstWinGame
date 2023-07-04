#pragma once

#include "Define.h"

class CBattleUI
{
public:
	enum STATE { OPENING, OPENED, CLOSING, CLOSED };

private:
	CBattleUI() {}
	~CBattleUI() { Release(); }
	CBattleUI(const CBattleUI& _rhs) = delete;

private:
	void Initialize();
	void Release();

public:
	void Update(float fDeltaTime);
	void Late_Update(float fDeltaTime);
	void Render(HDC hDC);
	

private:
	static CBattleUI* m_pInstance;

public:
	static CBattleUI* Get_Instance()
	{
		if (!m_pInstance)
		{
			m_pInstance = new CBattleUI;
			m_pInstance->Initialize();
		}

		return m_pInstance;
	}
	static void		Destroy_Instance()
	{
		if (m_pInstance)
		{
			m_pInstance->Release();
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

private:
	// pet�� ��ġ�� �����ϱ� ���� ����
	INFO	m_tInfo = {};

private:
	STATE_INFO<STATE>	m_tState;
	bool bInitBattle = true;	// ó�� �������� �� ���� UI�� �־� ����Ѵ�.
};

