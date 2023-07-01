#pragma once

#include "Define.h"

class CObj abstract {
public:
	CObj();
	virtual ~CObj();

public:
	RECT&			Get_Rect() { return m_tRect; }
	INFO			Get_Info() { return m_tInfo; }

	void			Set_PosY(float _fY) { m_tInfo.fY += _fY; }
	void			Set_PosX(float _fX) { m_tInfo.fX += _fX; }
	void			Set_Pos(float _fX, float _fY) { m_tInfo.fX = _fX; m_tInfo.fY = _fY; }


	void			Set_Dir(DIRECTION eDir) { m_eDir = eDir; }

	void			Set_Dead() { m_bDead = true; }
	bool			Get_Dead() { return m_bDead; }

	void			Set_FrameKey(TCHAR* pFrameKey) { m_pFrameKey = pFrameKey; }

public:
	virtual void		Initialize(void)					PURE;
	virtual int			Update(float fDeltaTime)			PURE;
	virtual void		Late_Update(float fDeltaTime)		PURE;
	virtual void		Render(HDC hDC)						PURE;
	virtual void		Release(void)						PURE;
public:
	virtual void		Collide(CObj* _pDst)	PURE;

protected:
	// Update_Rect�� z�� ��뿡 ���� ���� �и��� ���� ������� �ʽ��ϴ�.
	void		Update_Rect();
	void		Move_Frame();

protected:
	// �Ʒ� 3���� ���� �и��� ���� ������� �ʽ��ϴ�.
	// [Deprecated]
	INFO		m_tInfo;
	RECT		m_tRect;
	DIRECTION	m_eDir;
	
	const TCHAR* m_pFrameKey;		// �̹����� �ε��ϱ� ���� �ؽ�Ʈ ������
	FRAME		m_tFrame;			// �̹����� �������� ������Ʈ �ϱ����� ����

	bool		m_bDead;			// ������Ʈ ������
};

