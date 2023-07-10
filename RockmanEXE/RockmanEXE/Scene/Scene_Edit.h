#pragma once
#include "Scene.h"
class CScene_Edit :	public CScene
{
public:
	CScene_Edit();
	virtual ~CScene_Edit();

public:
	// CScene을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual void Update(float) override;
	virtual void Late_Update(float) override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

public:
	void		Save_Tile(void);

private:
	void	Key_Input(void);
};

