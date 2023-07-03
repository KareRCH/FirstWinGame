#pragma once

#include "Define.h"

#include "GameProcess.h"

/*
* �ϸ� �������� ���� ������ ���⼭ ����˴ϴ�.
* �� Ŭ������ CMainGame ������ ����ǵ��� ����� �ݴϴ�.
*/

class CGameProc_RockmanEXE : public CGameProcess
{
public:
	CGameProc_RockmanEXE() {}
	virtual ~CGameProc_RockmanEXE() {}

public:
	// CGameProcess��(��) ���� ��ӵ�
	virtual void Initialize()					override;
	virtual void Update(float fDeltaTime)		override;
	virtual void Late_Update(float fDeltaTime)	override;
	virtual void Render(HDC hDC)				override;
	virtual void Release()						override;
};

