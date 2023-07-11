#include "Manager/AnimationTable.h"

CAnimationTable* CAnimationTable::g_pInstance = nullptr;

void CAnimationTable::Initialize()
{
	int iID = 0;
#pragma region 록맨 애니메이션 데이터

#pragma region 노멀
	Create_Animation(
		L"NBT_Rockman_EXE_Normal_Idle", L"1",
		0, 0, 1, 0.f,
		32, 32, 64, 64
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal_Hit", L"1",
		0, 0, 8, 0.75f,
		32, 32, 64, 64
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal_Paralyze", L"1",
		0, 0, 1, 0.25f,
		32, 32, 64, 64
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal_Move_End", L"1",
		0, 0, 4, 1.f,
		32, 32, 64, 64
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal_Move_Ready", L"1",
		0, 0, 4, 1.f,
		32, 32, 64, 64
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal_Sword", L"1",
		0, 0, 1, 0.25f,
		32, 32, 64, 64
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal_Throw", L"1",
		0, 0, 1, 0.25f,
		32, 32, 64, 64
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal_Crouch", L"1",
		0, 0, 1, 0.25f,
		32, 32, 64, 64
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal_Shoot_Cannon", L"1",
		0, 0, 12, 0.5f,
		32, 32, 64, 64
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal_Shoot_Buster", L"1",
		0, 0, 4, 0.85f,
		32, 32, 64, 64
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal_Shoot_Duration", L"1",
		0, 0, 1, 0.5f,
		32, 32, 64, 64
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal_Throw_Disk", L"1",
		0, 0, 1, 0.5f,
		32, 32, 64, 64
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal_Shoot_1", L"1",
		0, 0, 1, 0.25f,
		32, 32, 64, 64
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal_Ready_Crouch_1", L"1",
		0, 0, 1, 0.25f,
		32, 32, 64, 64
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal_Shoot_2", L"1",
		0, 0, 1, 0.25f,
		32, 32, 64, 64
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal_Ready_Crouch_2", L"1",
		0, 0, 1, 0.25f,
		32, 32, 64, 64
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal_Ready_Swing", L"1",
		0, 0, 1, 0.25f,
		32, 32, 64, 64
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal_Swing", L"1",
		0, 0, 1, 0.25f,
		32, 32, 64, 64
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal_Crouch", L"1",
		0, 0, 1, 0.25f,
		32, 32, 64, 64
	);
#pragma endregion
	/*Create_Animation(
		L"NBT_Rockman_EXE_Aqua_Cross",
		FRAME() = {}
	);

	Create_Animation(
		L"NBT_Rockman_EXE_Charge_Cross", L""
		FRAME() = {}
	);

	Create_Animation(
		L"NBT_Rockman_EXE_Death_Cross",
		FRAME() = {}
	);

	Create_Animation(
		L"NBT_Rockman_EXE_Dust_Cross",
		FRAME() = {}
	);

	Create_Animation(
		L"NBT_Rockman_EXE_Death_Cross",
		FRAME() = {}
	);

	Create_Animation(
		L"NBT_Rockman_EXE_Elec_Cross",
		FRAME() = {}
	);

	Create_Animation(
		L"NBT_Rockman_EXE_Ground_Cross",
		FRAME() = {}
	);

	Create_Animation(
		L"NBT_Rockman_EXE_Heat_Cross",
		FRAME() = {}
	);

	Create_Animation(
		L"NBT_Rockman_EXE_Slash_Cross",
		FRAME() = {}
	);

	Create_Animation(
		L"NBT_Rockman_EXE_Tomahawk_Cross",
		FRAME() = {}
	);*/

#pragma region 오버월드
	Create_Animation(
		L"OVW_Rockman_Stand_0", L"1",
		0, 0, 1, 0.f,
		23, 30, 46, 46
	);
	Create_Animation(
		L"OVW_Rockman_Stand_1", L"1",
		0, 0, 1, 0.f,
		23, 30, 46, 46
	);
	Create_Animation(
		L"OVW_Rockman_Stand_2", L"1",
		0, 0, 1, 0.f,
		23, 30, 46, 46
	);
	Create_Animation(
		L"OVW_Rockman_Stand_3", L"1",
		0, 0, 1, 0.f,
		23, 30, 46, 46
	);
	Create_Animation(
		L"OVW_Rockman_Stand_4", L"1",
		0, 0, 1, 0.f,
		23, 30, 46, 46
	);
	Create_Animation(
		L"OVW_Rockman_Stand_5", L"1",
		0, 0, 1, 0.f,
		23, 30, 46, 46
	);
	Create_Animation(
		L"OVW_Rockman_Stand_6", L"1",
		0, 0, 1, 0.f,
		23, 30, 46, 46
	);
	Create_Animation(
		L"OVW_Rockman_Stand_7", L"1",
		0, 0, 1, 0.f,
		23, 30, 46, 46
	);

	Create_Animation(
		L"OVW_Rockman_Run_0", L"1",
		0, 0, 6, 0.8f,
		23, 30, 46, 46
	);
	Create_Animation(
		L"OVW_Rockman_Run_1", L"1",
		0, 0, 6, 0.8f,
		23, 30, 46, 46
	);
	Create_Animation(
		L"OVW_Rockman_Run_2", L"1",
		0, 0, 6, 0.8f,
		23, 30, 46, 46
	);
	Create_Animation(
		L"OVW_Rockman_Run_3", L"1",
		0, 0, 6, 0.8f,
		23, 30, 46, 46
	);
	Create_Animation(
		L"OVW_Rockman_Run_4", L"1",
		0, 0, 6, 0.8f,
		23, 30, 46, 46
	);
	Create_Animation(
		L"OVW_Rockman_Run_5", L"1",
		0, 0, 6, 0.8f,
		23, 30, 46, 46
	);
	Create_Animation(
		L"OVW_Rockman_Run_6", L"1",
		0, 0, 6, 0.8f,
		23, 30, 46, 46
	);
	Create_Animation(
		L"OVW_Rockman_Run_7", L"1",
		0, 0, 6, 0.8f,
		23, 30, 46, 46
	);

	Create_Animation(
		L"OVW_Rockman_Get", L"1",
		0, 0, 3, 0.7f,
		23, 30, 46, 46
	);

	Create_Animation(
		L"OVW_Rockman_Flash1_0", L"1",
		0, 0, 2, 0.8f,
		23, 30, 46, 46
	);
	Create_Animation(
		L"OVW_Rockman_Flash1_1", L"1",
		0, 0, 2, 0.8f,
		23, 30, 46, 46
	);
	Create_Animation(
		L"OVW_Rockman_Flash1_2", L"1",
		0, 0, 2, 0.8f,
		23, 30, 46, 46
	);
	Create_Animation(
		L"OVW_Rockman_Flash1_3", L"1",
		0, 0, 2, 0.8f,
		23, 30, 46, 46
	);
	Create_Animation(
		L"OVW_Rockman_Flash1_4", L"1",
		0, 0, 2, 0.8f,
		23, 30, 46, 46
	);
	Create_Animation(
		L"OVW_Rockman_Flash1_5", L"1",
		0, 0, 2, 0.8f,
		23, 30, 46, 46
	);
	Create_Animation(
		L"OVW_Rockman_Flash1_6", L"1",
		0, 0, 2, 0.8f,
		23, 30, 46, 46
	);
	Create_Animation(
		L"OVW_Rockman_Flash1_7", L"1",
		0, 0, 2, 0.8f,
		23, 30, 46, 46
	);

	Create_Animation(
		L"OVW_Rockman_Flash2_0", L"1",
		0, 0, 2, 0.8f,
		23, 30, 46, 46
	);
	Create_Animation(
		L"OVW_Rockman_Flash2_1", L"1",
		0, 0, 2, 0.8f,
		23, 30, 46, 46
	);
	Create_Animation(
		L"OVW_Rockman_Flash2_2", L"1",
		0, 0, 2, 0.8f,
		23, 30, 46, 46
	);
	Create_Animation(
		L"OVW_Rockman_Flash2_3", L"1",
		0, 0, 2, 0.8f,
		23, 30, 46, 46
	);
	Create_Animation(
		L"OVW_Rockman_Flash2_4", L"1",
		0, 0, 2, 0.8f,
		23, 30, 46, 46
	);
	Create_Animation(
		L"OVW_Rockman_Flash2_5", L"1",
		0, 0, 2, 0.8f,
		23, 30, 46, 46
	);
	Create_Animation(
		L"OVW_Rockman_Flash2_6", L"1",
		0, 0, 2, 0.8f,
		23, 30, 46, 46
	);
	Create_Animation(
		L"OVW_Rockman_Flash2_7", L"1",
		0, 0, 2, 0.8f,
		23, 30, 46, 46
	);

	Create_Animation(
		L"OVW_Rockman_Battle_0", L"1",
		0, 0, 2, 0.8f,
		23, 30, 46, 46
	);
	Create_Animation(
		L"OVW_Rockman_Battle_2", L"1",
		0, 0, 2, 0.8f,
		23, 30, 46, 46
	);
	Create_Animation(
		L"OVW_Rockman_Battle_4", L"1",
		0, 0, 2, 0.8f,
		23, 30, 46, 46
	);
	Create_Animation(
		L"OVW_Rockman_Battle_6", L"1",
		0, 0, 2, 0.8f,
		23, 30, 46, 46
	);
#pragma endregion

#pragma endregion
#pragma region 레드 판넬 애니메이션 데이터
	iID = 0;
	Create_Animation(
		L"BG_Red_Panel_Normal", L"1",
		0, 0, 1, 0.f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Red_Panel_Normal", L"2",
		1, 0, 1, 0.f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Red_Panel_Normal", L"3",
		2, 0, 1, 0.f,
		24, 12, 48, 32
	);

	Create_Animation(
		L"BG_Red_Panel_Blank", L"1",
		0, 0, 1, 0.f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Red_Panel_Blank", L"2",
		1, 0, 1, 0.f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Red_Panel_Blank", L"3",
		2, 0, 1, 0.f,
		24, 12, 48, 32
	);

	Create_Animation(
		L"BG_Red_Panel_Broken", L"1",
		0, 0, 1, 0.f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Red_Panel_Broken", L"2",
		1, 0, 1, 0.f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Red_Panel_Broken", L"3",
		2, 0, 1, 0.f,
		24, 12, 48, 32
	);

	Create_Animation(
		L"BG_Red_Panel_Crack", L"1",
		0, 0, 1, 0.f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Red_Panel_Crack", L"2",
		1, 0, 1, 0.f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Red_Panel_Crack", L"3",
		2, 0, 1, 0.f,
		24, 12, 48, 32
	);

	Create_Animation(
		L"BG_Red_Panel_Ice", L"1",
		0, 0, 1, 0.f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Red_Panel_Ice", L"2",
		1, 0, 1, 0.f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Red_Panel_Ice", L"3",
		2, 0, 1, 0.f,
		24, 12, 48, 32
	);

	Create_Animation(
		L"BG_Red_Panel_Grass", L"1",
		0, 0, 1, 0.f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Red_Panel_Grass", L"2",
		1, 0, 1, 0.f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Red_Panel_Grass", L"3",
		2, 0, 1, 0.f,
		24, 12, 48, 32
	);

	Create_Animation(
		L"BG_Red_Panel_Magma", L"1",
		0, 0, 1, 0.f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Red_Panel_Magma", L"2",
		1, 0, 1, 0.f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Red_Panel_Magma", L"3",
		2, 0, 1, 0.f,
		24, 12, 48, 32
	);

	Create_Animation(
		L"BG_Red_Panel_Sand", L"1",
		0, 0, 1, 0.f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Red_Panel_Sand", L"2",
		1, 0, 1, 0.f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Red_Panel_Sand", L"3",
		2, 0, 1, 0.f,
		24, 12, 48, 32
	);

	Create_Animation(
		L"BG_Red_Panel_Poison", L"1",
		0, 0, 10, 0.5f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Red_Panel_Poison", L"2",
		1 * 10, 0, 10, 0.5f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Red_Panel_Poison", L"3",
		2 * 10, 0, 10, 0.5f,
		24, 12, 48, 32
	);

	Create_Animation(
		L"BG_Red_Panel_Holy", L"1",
		0, 0, 7, 0.5f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Red_Panel_Holy", L"2",
		1 * 7, 0, 7, 0.5f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Red_Panel_Holy", L"3",
		2 * 7, 0, 7, 0.5f,
		24, 12, 48, 32
	);

	Create_Animation(
		L"BG_Red_Panel_Right", L"1",
		0, 0, 4, 0.5f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Red_Panel_Right", L"2",
		1 * 4, 0, 4, 0.5f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Red_Panel_Right", L"3",
		2 * 4, 0, 4, 0.5f,
		24, 12, 48, 32
	);

	Create_Animation(
		L"BG_Red_Panel_Left", L"1",
		0, 0, 4, 0.5f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Red_Panel_Left", L"2",
		1 * 4, 0, 4, 0.5f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Red_Panel_Left", L"3",
		2 * 4, 0, 4, 0.5f,
		24, 12, 48, 32
	);

	Create_Animation(
		L"BG_Red_Panel_Up", L"1",
		0, 0, 4, 0.5f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Red_Panel_Up", L"2",
		1 * 4, 0, 4, 0.5f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Red_Panel_Up", L"3",
		2 * 4, 0, 4, 0.5f,
		24, 12, 48, 32
	);

	Create_Animation(
		L"BG_Red_Panel_Down", L"1",
		0, 0, 4, 0.5f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Red_Panel_Down", L"2",
		1 * 4, 0, 4, 0.5f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Red_Panel_Down", L"3",
		2 * 4, 0, 4, 0.5f,
		24, 12, 48, 32
	);
#pragma endregion
#pragma region 블루 판넬 애니메이션 데이터
	iID = 0;
	Create_Animation(
		L"BG_Blue_Panel_Normal", L"1",
		0, 0, 1, 0.f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Blue_Panel_Normal", L"2",
		1, 0, 1, 0.f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Blue_Panel_Normal", L"3",
		2, 0, 1, 0.f,
		24, 12, 48, 32
	);

	Create_Animation(
		L"BG_Blue_Panel_Blank", L"1",
		0, 0, 1, 0.f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Blue_Panel_Blank", L"2",
		1, 0, 1, 0.f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Blue_Panel_Blank", L"3",
		2, 0, 1, 0.f,
		24, 12, 48, 32
	);

	Create_Animation(
		L"BG_Blue_Panel_Broken", L"1",
		0, 0, 1, 0.f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Blue_Panel_Broken", L"2",
		1, 0, 1, 0.f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Blue_Panel_Broken", L"3",
		2, 0, 1, 0.f,
		24, 12, 48, 32
	);

	Create_Animation(
		L"BG_Blue_Panel_Crack", L"1",
		0, 0, 1, 0.f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Blue_Panel_Crack", L"2",
		1, 0, 1, 0.f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Blue_Panel_Crack", L"3",
		2, 0, 1, 0.f,
		24, 12, 48, 32
	);

	Create_Animation(
		L"BG_Blue_Panel_Ice", L"1",
		0, 0, 1, 0.f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Blue_Panel_Ice", L"2",
		1, 0, 1, 0.f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Blue_Panel_Ice", L"3",
		2, 0, 1, 0.f,
		24, 12, 48, 32
	);

	Create_Animation(
		L"BG_Blue_Panel_Grass", L"1",
		0, 0, 1, 0.f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Blue_Panel_Grass", L"2",
		1, 0, 1, 0.f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Blue_Panel_Grass", L"3",
		2, 0, 1, 0.f,
		24, 12, 48, 32
	);

	Create_Animation(
		L"BG_Blue_Panel_Magma", L"1",
		0, 0, 1, 0.f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Blue_Panel_Magma", L"2",
		1, 0, 1, 0.f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Blue_Panel_Magma", L"3",
		2, 0, 1, 0.f,
		24, 12, 48, 32
	);

	Create_Animation(
		L"BG_Blue_Panel_Sand", L"1",
		0, 0, 1, 0.f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Blue_Panel_Sand", L"2",
		1, 0, 1, 0.f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Blue_Panel_Sand", L"3",
		2, 0, 1, 0.f,
		24, 12, 48, 32
	);

	Create_Animation(
		L"BG_Blue_Panel_Poison", L"1",
		0, 0, 10, 0.5f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Blue_Panel_Poison", L"2",
		1 *10, 0, 10, 0.5f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Blue_Panel_Poison", L"3",
		2 *10, 0, 10, 0.5f,
		24, 12, 48, 32
	);

	Create_Animation(
		L"BG_Blue_Panel_Holy", L"1",
		0, 0, 7, 0.5f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Blue_Panel_Holy", L"2",
		1 *7, 0, 7, 0.5f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Blue_Panel_Holy", L"3",
		2 *7, 0, 7, 0.5f,
		24, 12, 48, 32
	);

	Create_Animation(
		L"BG_Blue_Panel_Right", L"1",
		0, 0, 4, 0.5f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Blue_Panel_Right", L"2",
		1 *4, 0, 4, 0.5f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Blue_Panel_Right", L"3",
		2 *4, 0, 4, 0.5f,
		24, 12, 48, 32
	);

	Create_Animation(
		L"BG_Blue_Panel_Left", L"1",
		0, 0, 4, 0.5f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Blue_Panel_Left", L"2",
		1 *4, 0, 4, 0.5f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Blue_Panel_Left", L"3",
		2 *4, 0, 4, 0.5f,
		24, 12, 48, 32
	);

	Create_Animation(
		L"BG_Blue_Panel_Up", L"1",
		0, 0, 4, 0.5f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Blue_Panel_Up", L"2",
		1 *4, 0, 4, 0.5f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Blue_Panel_Up", L"3",
		2 *4, 0, 4, 0.5f,
		24, 12, 48, 32
	);

	Create_Animation(
		L"BG_Blue_Panel_Down", L"1",
		0, 0, 4, 0.5f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Blue_Panel_Down", L"2",
		1 *4, 0, 4, 0.5f,
		24, 12, 48, 32
	);
	Create_Animation(
		L"BG_Blue_Panel_Down", L"3",
		2 *4, 0, 4, 0.5f,
		24, 12, 48, 32
	);
#pragma endregion

#pragma region 멧툴
	Create_Animation(
		L"NBT_Mettaur_Idle", L"1",
		0, 0, 1, 0.f,
		33, 53, 64, 64
	); 
	Create_Animation(
		L"NBT_Mettaur_Prepare_Atk", L"1",
		0, 0, 5, 0.8f,
		33, 53, 64, 64
	);
	Create_Animation(
		L"NBT_Mettaur_Attack", L"1",
		0, 0, 11, 0.8f,
		33, 53, 64, 64
	);
	Create_Animation(
		L"NBT_Mettaur_Hiding", L"1",
		0, 0, 6, 0.8f,
		33, 53, 64, 64
	);
	Create_Animation(
		L"NBT_Mettaur_Hid", L"1",
		0, 0, 1, 0.f,
		33, 53, 64, 64
	);
	Create_Animation(
		L"NBT_Mettaur_Showing", L"1",
		0, 0, 6, 0.8f,
		33, 53, 64, 64
	);
	Create_Animation(
		L"NBT_Mettaur_Jump", L"1",
		0, 0, 2, 0.8f,
		33, 53, 64, 64
	);
	Create_Animation(
		L"NBT_Mettaur_Landing", L"1",
		0, 0, 3, 0.8f,
		33, 53, 64, 64
	);
#pragma endregion
#pragma region 쇼크웨이브
	Create_Animation(
		L"NBT_Spell_Shockwave", L"1",
		0, 0, 5, 0.7f,
		27, 44, 50, 50
	);
#pragma endregion

#pragma region UI
	Create_Animation(
		L"NBT_UI_Cursor_Small", L"1",
		0, 0, 2, 0.25f,
		0, 0, 22, 22
	);
	Create_Animation(
		L"NBT_UI_Cursor_Big", L"1",
		0, 0, 2, 0.25f,
		0, 0, 25, 25
	);
#pragma endregion
#pragma region 타이틀
	Create_Animation(
		L"Title_Gregar", L"1",
		0, 0, 10, 0.5f,
		132, 99, 264, 198
	);
	Create_Animation(
		L"BMP_Title_Gregar", L"1",
		0, 0, 10, 0.5f,
		131, 99, 264, 198
	);

	Create_Animation(
		L"BG_Central_Area", L"1",
		0, 0, 7, 0.5f,
		2, 1, 130, 66
	);
	Create_Animation(
		L"BMP_BG_Central_Area", L"1",
		0, 0, 7, 0.5f,
		2, 1, 130, 66
	);
#pragma endregion


}

void CAnimationTable::Release()
{

}
