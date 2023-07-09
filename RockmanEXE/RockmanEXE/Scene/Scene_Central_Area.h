#pragma once
#include "Scene.h"

class CScene_Central_Area : public CScene
{
public:
	CScene_Central_Area() {}
	virtual ~CScene_Central_Area() { Release(); }

public:
	// CScene��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Update(float fDeltaTime) override;
	virtual void Late_Update(float fDeltaTime) override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
};

