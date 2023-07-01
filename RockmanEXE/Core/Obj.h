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
	// Update_Rect는 z축 사용에 따른 개념 분리에 따라 사용하지 않습니다.
	void		Update_Rect();
	void		Move_Frame();

protected:
	// 아래 3개는 개념 분리에 따라 사용하지 않습니다.
	// [Deprecated]
	INFO		m_tInfo;
	RECT		m_tRect;
	DIRECTION	m_eDir;
	
	const TCHAR* m_pFrameKey;		// 이미지를 로드하기 위한 텍스트 포인터
	FRAME		m_tFrame;			// 이미지의 프레임을 업데이트 하기위한 정보

	bool		m_bDead;			// 오브젝트 삭제용
};

