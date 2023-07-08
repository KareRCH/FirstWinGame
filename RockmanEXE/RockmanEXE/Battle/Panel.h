#pragma once

#include "Character/Character_NetBattle.h"

#define BATTLE_PANEL_ROW 3
#define BATTLE_PANEL_COL 6

#define PANEL_CROW 39
#define PANEL_CCOL 24

class CPanel : public CCharacter_NetBattle
{
public:
	enum class ACT_STATE : int { IDLE, RIGHT, LEFT, UP, DOWN, TOP, BOTTOM };
	enum class PNL_STATE : int { NORMAL, BLANK, CRACK, BROCKEN, ICE, GRASS, MAGMA, SAND, POISON, HOLY, RIGHT, LEFT, UP, DOWN };
	enum PNL_COLOR { PNL_RED, PNL_BLUE, PNL_NONE };
	enum PNL_BRIGHTNESS { BLIGHT, MIDDLE, DARK };
public:
	CPanel() {}
	virtual ~CPanel() { Release(); }

public:
	void Initialize();
	int Update(float fDeltaTime);
	void Late_Update(float fDeltaTime);
	void Render(HDC hDC);
	void Release();
	void Collide(CObj* _Dst);

private:
	STATE_INFO<ACT_STATE>	m_tState_Act;
	STATE_INFO<PNL_STATE>	m_tState_Panel;

	// √÷√  ªˆ±Ú
	PNL_COLOR				m_eColor_Init = PNL_RED;
	PNL_COLOR				m_eColor_Cur = PNL_RED;
	PNL_BRIGHTNESS			m_eBrightness = MIDDLE;

public:
	STATE_INFO<ACT_STATE>& Get_ActState() { return m_tState_Act; }

	STATE_INFO<PNL_STATE>& Get_PanelState() { return m_tState_Panel; }

	void Set_Color(PNL_COLOR value) { m_eColor_Cur = value; }
	PNL_COLOR Get_Color() { return m_eColor_Cur; }

	void Set_Color_Init(PNL_COLOR value) { m_eColor_Init = value; }
	PNL_COLOR Get_Color_Init() { return m_eColor_Init; }

	void Set_Brightness(PNL_BRIGHTNESS value) { m_eBrightness = value; }
	PNL_BRIGHTNESS Get_Brightness() { return m_eBrightness; }

public:
	void State_Update(float fDeltaTime);
};

class CPanelFactory
{
private:
	CPanelFactory() = delete;
	CPanelFactory(const CPanelFactory& rhs) = delete;
	~CPanelFactory() = delete;

public:
	static CPanel* Create(CVector3<float> vecPos, CPanel::PNL_COLOR eColor, CPanel::PNL_BRIGHTNESS eBrightness,
		CPanel::PNL_STATE ePanelState)
	{
		CPanel* pObj = new CPanel;
		pObj->Set_VecPos(vecPos);
		pObj->Set_Color_Init(eColor);
		pObj->Set_Color(eColor);
		pObj->Set_Brightness(eBrightness);
		pObj->Get_PanelState().Set_State(ePanelState);
		pObj->Initialize();

		return pObj;
	}
};