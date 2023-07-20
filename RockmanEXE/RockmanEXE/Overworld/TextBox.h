#pragma once

#include "Obj.h"

struct PORTRAY_TEXT
{
	list<pair<wstring, wstring>> sTextList;

	void Add_PortrayText(wstring sPortray, wstring sText)
	{
		sTextList.push_back(pair<wstring, wstring>(sPortray, sText));
	}
	void Add_Text(wstring sText)
	{
		sTextList.push_back(pair<wstring, wstring>(L"", sText));
	}
	

	wstring Get_PortrayStr()
	{
		return sTextList.front().first;
	}
	wstring Get_TextStr()
	{
		return sTextList.front().second;
	}

	void Pop_Text()
	{
		sTextList.pop_front();
	}

	bool IsEmpty()
	{
		return sTextList.empty();
	}
};

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
	PORTRAY_TEXT m_OriginText_List;
	wstring m_sFlowText;
	wstring m_sFlowText_Part;
	wstring m_sPortray;
	int m_iFlowIndex = 0;

public:
	void Set_OriginText(PORTRAY_TEXT value) { m_OriginText_List = value; }
	PORTRAY_TEXT* Get_OriginText() { return &m_OriginText_List; }

	void Set_FlowText(wstring value) { m_sFlowText = value; }
	wstring* Get_FlowText() { return &m_sFlowText; }

public:
	enum class ESTATE { OPEN, OPENED, CLOSE, START, FLOW, END };
private: // 상태
	STATE_SET<ESTATE, void(CTextBox*, float)> m_tState;
	GAUGE<float>	m_fOpenSpeed = GAUGE<float>(0.5f);
	DELAY<float>	m_fFlowDelay = DELAY<float>(0.03f);

	void OpenTextBox(float fDeltaTime);
	void OpenedTextBox(float fDeltaTime);
	void CloseTextBox(float fDeltaTime);
	void FlowStart(float fDeltaTime);
	void FlowText(float fDeltaTime);
	void FlowEnd(float fDeltaTime);

private:
	function<void(void)> m_fnSendResult;

public:
	void Set_Func_SendResult(function<void(void)> _Func) { m_fnSendResult = _Func; }
	void Call_Func_SendResult() { if (m_fnSendResult) m_fnSendResult(); }
	function<void(void)> Get_Func_SendResult() { return m_fnSendResult; }
};

