#pragma once

#include "Obj.h"

class CTextBox : public CObj
{
public:
	enum class ESTATE;
public:
	CTextBox() {}
	virtual ~CTextBox() {}

public:
	// CObj을(를) 통해 상속됨
	virtual void Initialize(void) override;
	virtual int Update(float fDeltaTime) override;
	virtual void Late_Update(float fDeltaTime) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	virtual void Collide(CObj* _pDst) override;

private:
	vector<wstring> m_sOriginText;
	wstring m_sFlowText;

public:
	void Set_OriginText(vector<wstring> value) { m_sOriginText = value; }
	vector<wstring>* Get_OriginText() { return &m_sOriginText; }

	void Set_FlowText(wstring value) { m_sFlowText = value; }
	wstring* Get_FlowText() { return &m_sFlowText; }

public:
	enum class ESTATE { OPEN, OPEND, CLOSE, START, FLOW, END };
private: // 상태
	STATE_SET<ESTATE, void(CTextBox*, float)> m_tState;
	GAUGE<float>	m_fOpenSpeed = GAUGE<float>(0.5f);

	void OpenTextBox(float fDeltaTime);
	void OpendTextBox(float fDeltaTime);
	void CloseTextBox(float fDeltaTime);
	void FlowStart(float fDeltaTime);
	void FlowText(float fDeltaTime);
	void FlowEnd(float fDeltaTime);

};

