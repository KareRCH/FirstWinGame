#pragma once

#include "Define.h"

/*
* �� ������ ��ũ�� GameProcess�� ���� ��Ƽ ���μ����� �����մϴ�.
* ����� �����带 ������� ������, ���� �����带 �����Ͽ� ��Ƽ �ھ�� ������ ���� ������ �� �ֽ��ϴ�.
* ��, �����쿡 �Ҵ��Ͽ� ����ϴ� ���μ����� �ƴ� MainGame���� ���� �����Ǵ� ��ü�μ� �����մϴ�.
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

