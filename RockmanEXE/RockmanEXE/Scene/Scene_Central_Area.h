#pragma once

#include "Scene/Scene_Net_Area.h"

class CScene_Central_Area : public CScene_Net_Area
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

