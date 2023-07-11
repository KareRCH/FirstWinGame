#pragma once

#include "Define.h"

class CObj abstract {
public:
	CObj();
	virtual ~CObj();

public:
	RECT&			Get_Rect() { return m_tRect; }
	INFO&			Get_Info() { return m_tInfo; }

	void			Set_PosY(float _fY) { m_tInfo.fY += _fY; }
	void			Set_PosX(float _fX) { m_tInfo.fX += _fX; }
	void			Set_Pos(float _fX, float _fY) { m_tInfo.fX = _fX; m_tInfo.fY = _fY; }

	void			Set_Size(float _fCX, float _fCY) { m_tInfo.fCX = _fCX; m_tInfo.fCY = _fCY; }


	void			Set_Dir(DIRECTION eDir) { m_eDir = eDir; }

	void			Set_Dead() { m_bDead = true; }
	bool			Get_Dead() { return m_bDead; }

	void			Set_Pause() { m_bPause = true; }
	void			Set_Resume() { m_bPause = false; }
	bool			Get_IsPaused() { return m_bPause; }

	void			Set_Visible(bool value) { m_bIsVisible = value; }
	bool			Get_Visible() { return m_bIsVisible; }

	void			Set_FrameKey(int iIndex, const TCHAR* pFrameKey)
	{
		if (m_vFrame.size() > iIndex)
			m_vFrame[iIndex].first = pFrameKey;
		else
		{
			m_vFrame.resize(iIndex + 1);
			m_vFrame[iIndex].first = pFrameKey;
		}
	}

	const TCHAR*	Get_FrameKey(int iIndex)
	{
		if (m_vFrame.size() > iIndex)
			return m_vFrame[iIndex].first;
		else
		{
			m_vFrame.resize(iIndex + 1);
			return m_vFrame[iIndex].first;
		}
	}

	FRAME&	Get_Frame(int iIndex)
	{
		if (m_vFrame.size() > iIndex)
			return m_vFrame[iIndex].second;
		else
		{
			m_vFrame.resize(iIndex + 1);
			return m_vFrame[iIndex].second;
		}
	}

public:
	virtual void		Initialize(void)					PURE;
	virtual int			Update(float fDeltaTime)			PURE;
	virtual void		Late_Update(float fDeltaTime)		PURE;
	virtual void		Render(HDC hDC)						PURE;
	virtual void		Release(void)						PURE;
public:
	virtual void		Collide(CObj* _pDst)				PURE;

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

	bool		m_bDead;			// ������Ʈ ������
	bool		m_bPause;			// ������Ʈ Ȱ������
	bool		m_bIsVisible;		// ������Ʈ ���� ����
	float		m_fOpacity;			// ������Ʈ ������

	int			m_iRenderDepth;		// ���� ���� (���ڰ� Ŭ ���� �� ���� ������ ������ ��)

	CObj*		m_pOwner;			// �� ��ü�� ����

	// �̹����� �ε��ϰ� �������� ������Ʈ �ϱ� ���� ���͸���Ʈ
	// �� ��ü�� ���� �������� �̹����� �ε��� �� �ֽ��ϴ�.
	vector<pair<const TCHAR*, FRAME>> m_vFrame;	

public:
	vector<pair<const TCHAR*, FRAME>>& Get_FrameList() { return m_vFrame; }
	int	Get_RenderDepth() { return m_iRenderDepth; }

public:
	CObj* Get_Owner() { return m_pOwner; }
	void Set_Owner(CObj* value) { m_pOwner = value; }

	float Get_Opacity() { return m_fOpacity; }
	void Set_Opacity(float value) { m_fOpacity = value; }
};

