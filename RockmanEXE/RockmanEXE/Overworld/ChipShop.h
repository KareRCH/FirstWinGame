#pragma once

#include "Obj.h"
#include "Data/ChipData.h"

class CChipShop : public CObj
{
public:
	enum class ESTATE;
public:
	CChipShop() {}
	virtual ~CChipShop() {}

public:
	// CObj을(를) 통해 상속됨
	virtual void Initialize(void) override;
	virtual int Update(float fDeltaTime) override;
	virtual void Late_Update(float fDeltaTime) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	virtual void Collide(CObj* _pDst) override;

public:
	enum class ESTATE { OPEN, SELECTING, CLOSE };
private: // 상태
	STATE_SET<ESTATE, void(CChipShop*, float)> m_tState;

	void OpenShop(float fDeltaTime);
	void Selecting(float fDeltaTime);
	void CloseShop(float fDeltaTime);

private:
	vector<FChipData_ForShop> m_vChip_List;
	int m_iCursor = 0;

public:
	vector<FChipData_ForShop>* Get_Chip_List() { return &m_vChip_List; }

private:
	function<void(void)> m_fnSendResult;

public:
	void Set_Func_SendResult(function<void(void)> _Func) { m_fnSendResult = _Func; }
	void Call_Func_SendResult() { if (m_fnSendResult) m_fnSendResult(); }
	function<void(void)> Get_Func_SendResult() { return m_fnSendResult; }
};

