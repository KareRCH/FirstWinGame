#pragma once

#include "Scene.h"

class CScene_NetBattle : public CScene
{
public:
	CScene_NetBattle() {}
	virtual ~CScene_NetBattle() { Release(); }

public:
	// CScene��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Update(float fDeltaTime) override;
	virtual void Late_Update(float fDeltaTime) override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
};

