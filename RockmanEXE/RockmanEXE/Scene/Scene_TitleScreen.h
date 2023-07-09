#pragma once

#include "Scene.h"

class CScene_TitleScreen : public CScene
{
public:
	CScene_TitleScreen() {}
	virtual ~CScene_TitleScreen() {}
public:
	// CScene을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual void Update(float fDeltaTime) override;
	virtual void Late_Update(float fDeltaTime) override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

private: // 애니메이션
	pair<const TCHAR*, FRAME>	m_pairFrame;	// 애니메이션 키 용 map
public:
	void						Add_Frame(const TCHAR* sKey) { m_pairFrame = pair<const TCHAR*, FRAME>(sKey, FRAME()); }
	pair<const TCHAR*, FRAME>*	Get_Frame() { return &m_pairFrame; }
	void						Set_FrameKey(const TCHAR* sKey) { m_pairFrame.first = sKey; }
	const TCHAR*				Get_FrameKey() { return m_pairFrame.first; }
	FRAME						Get_FrameData() { return m_pairFrame.second; }

public:
	void Move_Frame();
};

