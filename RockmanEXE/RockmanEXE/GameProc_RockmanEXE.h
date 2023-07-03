#pragma once

#include "Define.h"

#include "GameProcess.h"

/*
* 록맨 에그제의 메인 게임은 여기서 실행됩니다.
* 이 클래스는 CMainGame 위에서 실행되도록 만들어 줍니다.
*/

class CGameProc_RockmanEXE : public CGameProcess
{
public:
	CGameProc_RockmanEXE() {}
	virtual ~CGameProc_RockmanEXE() {}

public:
	// CGameProcess을(를) 통해 상속됨
	virtual void Initialize()					override;
	virtual void Update(float fDeltaTime)		override;
	virtual void Late_Update(float fDeltaTime)	override;
	virtual void Render(HDC hDC)				override;
	virtual void Release()						override;
};

