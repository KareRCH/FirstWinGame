#pragma once

#include "Define.h"

/*
* 이 프레임 워크는 GameProcess를 통해 멀티 프로세스를 지원합니다.
* 현재는 쓰레드를 사용하지 않지만, 추후 쓰레드를 지원하여 멀티 코어로 게임을 동시 실행할 수 있습니다.
* 단, 윈도우에 할당하여 사용하는 프로세스가 아닌 MainGame으로 부터 관리되는 객체로서 동작합니다.
*/

class CGameProcess abstract
{
public:
	CGameProcess() {}
	virtual ~CGameProcess() {}

public:
	virtual void		Initialize()					PURE;
	virtual void		Update(float fDeltaTime)	    PURE;
	virtual void		Late_Update(float fDeltaTime)	PURE;
	virtual void		Render(HDC hDC)					PURE;
	virtual void		Release()						PURE;
};

