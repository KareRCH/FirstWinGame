#pragma once
#include "Scene.h"
class CScene_Edit :	public CScene
{
public:
	CScene_Edit();
	virtual ~CScene_Edit();

public:
	// CScene��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Update(float) override;
	virtual void Late_Update(float) override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

public:
	void		Save_Tile(void);

private:
	void	Key_Input(void);

protected: // �ִϸ��̼�
	pair<const TCHAR*, FRAME>	m_pairFrame;	// �ִϸ��̼� Ű �� map
public:
	void						Add_Frame(const TCHAR* sKey) { m_pairFrame = pair<const TCHAR*, FRAME>(sKey, FRAME()); }
	pair<const TCHAR*, FRAME>* Get_Frame() { return &m_pairFrame; }
	void						Set_FrameKey(const TCHAR* sKey) { m_pairFrame.first = sKey; }
	const TCHAR* Get_FrameKey() { return m_pairFrame.first; }
	FRAME						Get_FrameData() { return m_pairFrame.second; }

public:
	void Move_Frame()
	{
		auto& tFrame = m_pairFrame.second;
		tFrame.ulCurTime = GetTickCount64();
		if (tFrame.ulTime + tFrame.ulSpeed < tFrame.ulCurTime)
		{
			++tFrame.iFrameCur;

			if (tFrame.iFrameCur > tFrame.iFrameEnd)
			{
				if (tFrame.bLoop)
					tFrame.iFrameCur = 0;
				else
					tFrame.iFrameCur = tFrame.iFrameEnd;
			}

			tFrame.ulTime = tFrame.ulCurTime;
		}
	}
};

