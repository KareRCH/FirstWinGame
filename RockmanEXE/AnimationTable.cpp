#include "Manager/AnimationTable.h"

CAnimationTable* CAnimationTable::g_pInstance = nullptr;

void CAnimationTable::Initialize()
{
	int iID = 0;
#pragma region 록맨 애니메이션 데이터

#pragma region 노멀
	Create_Animation(
		L"NBT_Rockman_EXE_Normal_Idle", L"1",
		0, 0, 1,
		64, 64,
		32, 32, 0.f
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal_Hit", L"1",
		0, 0, 8, 
		64, 64,
		32, 32, 0.25f
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal_Paralyze", L"1",
		0, 0, 1, 
		64, 64,
		32, 32, 0.25f
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal_Move_End", L"1",
		0, 0, 4, 
		64, 64,
		32, 32, 1.f
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal_Move_Ready", L"1",
		0, 0, 4, 
		64, 64,
		32, 32, 1.f
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal_Sword", L"1",
		0, 0, 1, 
		64, 64,
		32, 32, 0.25f
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal_Throw", L"1",
		0, 0, 1, 
		64, 64,
		32, 32, 0.25f
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal_Crouch", L"1",
		0, 0, 1, 
		64, 64,
		32, 32, 0.25f
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal_Shoot_Cannon", L"1",
		0, 0, 12, 
		64, 64,
		32, 32, 0.5f
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal_Shoot_Buster", L"1",
		0, 0, 4, 
		64, 64,
		32, 32, 0.85f
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal_Shoot_Duration", L"1",
		0, 0, 1, 
		64, 64,
		32, 32, 0.5f
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal_Throw_Disk", L"1",
		0, 0, 1, 
		64, 64,
		32, 32, 0.5f
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal_Shoot_1", L"1",
		0, 0, 1, 
		64, 64,
		32, 32, 0.25f
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal_Ready_Crouch_1", L"1",
		0, 0, 1, 
		64, 64,
		32, 32, 0.25f
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal_Shoot_2", L"1",
		0, 0, 1, 
		64, 64,
		32, 32, 0.25f
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal_Ready_Crouch_2", L"1",
		0, 0, 1, 
		64, 64,
		32, 32, 0.25f
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal_Ready_Swing", L"1",
		0, 0, 1, 
		64, 64,
		32, 32, 0.25f
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal_Swing", L"1",
		0, 0, 1, 
		64, 64,
		32, 32, 0.25f
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal_Crouch", L"1",
		0, 0, 1, 
		64, 64,
		32, 32, 0.25f
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
#pragma endregion
#pragma region 레드 판넬 애니메이션 데이터
	iID = 0;
	Create_Animation(
		L"BG_Red_Panel_Normal", L"1",
		0, 0, 1,
		40, 30,
		20, 11, 0.f
	);
	Create_Animation(
		L"BG_Red_Panel_Normal", L"2",
		1, 0, 1,
		40, 30,
		20, 11, 0.f
	);
	Create_Animation(
		L"BG_Red_Panel_Normal", L"3",
		2, 0, 1,
		40, 30,
		20, 11, 0.f
	);

	Create_Animation(
		L"BG_Red_Panel_Blank", L"1",
		0, 0, 1,
		40, 30,
		20, 11, 0.f
	);
	Create_Animation(
		L"BG_Red_Panel_Blank", L"2",
		1, 0, 1,
		40, 30,
		20, 11, 0.f
	);
	Create_Animation(
		L"BG_Red_Panel_Blank", L"3",
		2, 0, 1,
		40, 30,
		20, 11, 0.f
	);

	Create_Animation(
		L"BG_Red_Panel_Broken", L"1",
		0, 0, 1,
		40, 30,
		20, 11, 0.f
	);
	Create_Animation(
		L"BG_Red_Panel_Broken", L"2",
		1, 0, 1,
		40, 30,
		20, 11, 0.f
	);
	Create_Animation(
		L"BG_Red_Panel_Broken", L"3",
		2, 0, 1,
		40, 30,
		20, 11, 0.f
	);

	Create_Animation(
		L"BG_Red_Panel_Crack", L"1",
		0, 0, 1,
		40, 30,
		20, 11, 0.f
	);
	Create_Animation(
		L"BG_Red_Panel_Crack", L"2",
		1, 0, 1,
		40, 30,
		20, 11, 0.f
	);
	Create_Animation(
		L"BG_Red_Panel_Crack", L"3",
		2, 0, 1,
		40, 30,
		20, 11, 0.f
	);

	Create_Animation(
		L"BG_Red_Panel_Ice", L"1",
		0, 0, 1,
		40, 30,
		20, 11, 0.f
	);
	Create_Animation(
		L"BG_Red_Panel_Ice", L"2",
		1, 0, 1,
		40, 30,
		20, 11, 0.f
	);
	Create_Animation(
		L"BG_Red_Panel_Ice", L"3",
		2, 0, 1,
		40, 30,
		20, 11, 0.f
	);

	Create_Animation(
		L"BG_Red_Panel_Grass", L"1",
		0, 0, 1,
		40, 30,
		20, 11, 0.f
	);
	Create_Animation(
		L"BG_Red_Panel_Grass", L"2",
		1, 0, 1,
		40, 30,
		20, 11, 0.f
	);
	Create_Animation(
		L"BG_Red_Panel_Grass", L"3",
		2, 0, 1,
		40, 30,
		20, 11, 0.f
	);

	Create_Animation(
		L"BG_Red_Panel_Magma", L"1",
		0, 0, 1,
		40, 30,
		20, 11, 0.f
	);
	Create_Animation(
		L"BG_Red_Panel_Magma", L"2",
		1, 0, 1,
		40, 30,
		20, 11, 0.f
	);
	Create_Animation(
		L"BG_Red_Panel_Magma", L"3",
		2, 0, 1,
		40, 30,
		20, 11, 0.f
	);

	Create_Animation(
		L"BG_Red_Panel_Sand", L"1",
		0, 0, 1,
		40, 30,
		20, 11, 0.f
	);
	Create_Animation(
		L"BG_Red_Panel_Sand", L"2",
		1, 0, 1,
		40, 30,
		20, 11, 0.f
	);
	Create_Animation(
		L"BG_Red_Panel_Sand", L"3",
		2, 0, 1,
		40, 30,
		20, 11, 0.f
	);

	Create_Animation(
		L"BG_Red_Panel_Poison", L"1",
		0, 0, 10,
		40, 30,
		20, 11, 0.5f
	);
	Create_Animation(
		L"BG_Red_Panel_Poison", L"2",
		1*10, 0, 10,
		40, 30,
		20, 11, 0.5f
	);
	Create_Animation(
		L"BG_Red_Panel_Poison", L"3",
		2 * 10, 0, 10,
		40, 30,
		20, 11, 0.5f
	);

	Create_Animation(
		L"BG_Red_Panel_Holy", L"1",
		0, 0, 7,
		40, 30,
		20, 11, 0.5f
	);
	Create_Animation(
		L"BG_Red_Panel_Holy", L"2",
		1 * 7, 0, 7,
		40, 30,
		20, 11, 0.5f
	);
	Create_Animation(
		L"BG_Red_Panel_Holy", L"3",
		2 * 7, 0, 7,
		40, 30,
		20, 11, 0.5f
	);

	Create_Animation(
		L"BG_Red_Panel_Right", L"1",
		0, 0, 4,
		40, 30,
		20, 11, 0.5f
	);
	Create_Animation(
		L"BG_Red_Panel_Right", L"2",
		1 * 4, 0, 4,
		40, 30,
		20, 11, 0.5f
	);
	Create_Animation(
		L"BG_Red_Panel_Right", L"3",
		2 * 4, 0, 4,
		40, 30,
		20, 11, 0.5f
	);

	Create_Animation(
		L"BG_Red_Panel_Left", L"1",
		0, 0, 4,
		40, 30,
		20, 11, 0.5f
	);
	Create_Animation(
		L"BG_Red_Panel_Left", L"2",
		1 *4, 0, 4,
		40, 30,
		20, 11, 0.5f
	);
	Create_Animation(
		L"BG_Red_Panel_Left", L"3",
		2 *4, 0, 4,
		40, 30,
		20, 11, 0.5f
	);

	Create_Animation(
		L"BG_Red_Panel_Up", L"1",
		0, 0, 4,
		40, 30,
		20, 11, 0.5f
	);
	Create_Animation(
		L"BG_Red_Panel_Up", L"2",
		1 *4, 0, 4,
		40, 30,
		20, 11, 0.5f
	);
	Create_Animation(
		L"BG_Red_Panel_Up", L"3",
		2 *4, 0, 4,
		40, 30,
		20, 11, 0.5f
	);

	Create_Animation(
		L"BG_Red_Panel_Down", L"1",
		0, 0, 4,
		40, 30,
		20, 11, 0.5f
	);
	Create_Animation(
		L"BG_Red_Panel_Down", L"2",
		1 *4, 0, 4,
		40, 30,
		20, 11, 0.5f
	);
	Create_Animation(
		L"BG_Red_Panel_Down", L"3",
		2 *4, 0, 4,
		40, 30,
		20, 11, 0.5f
	);
#pragma endregion
#pragma region 블루 판넬 애니메이션 데이터
	iID = 0;
	Create_Animation(
		L"BG_Blue_Panel_Normal", L"1",
		0, 0, 1,
		40, 30,
		20, 11, 0.f
	);
	Create_Animation(
		L"BG_Blue_Panel_Normal", L"2",
		1, 0, 1,
		40, 30,
		20, 11, 0.f
	);
	Create_Animation(
		L"BG_Blue_Panel_Normal", L"3",
		2, 0, 1,
		40, 30,
		20, 11, 0.f
	);

	Create_Animation(
		L"BG_Blue_Panel_Blank", L"1",
		0, 0, 1,
		40, 30,
		20, 11, 0.f
	);
	Create_Animation(
		L"BG_Blue_Panel_Blank", L"2",
		1, 0, 1,
		40, 30,
		20, 11, 0.f
	);
	Create_Animation(
		L"BG_Blue_Panel_Blank", L"3",
		2, 0, 1,
		40, 30,
		20, 11, 0.f
	);

	Create_Animation(
		L"BG_Blue_Panel_Broken", L"1",
		0, 0, 1,
		40, 30,
		20, 11, 0.f
	);
	Create_Animation(
		L"BG_Blue_Panel_Broken", L"2",
		1, 0, 1,
		40, 30,
		20, 11, 0.f
	);
	Create_Animation(
		L"BG_Blue_Panel_Broken", L"3",
		2, 0, 1,
		40, 30,
		20, 11, 0.f
	);

	Create_Animation(
		L"BG_Blue_Panel_Crack", L"1",
		0, 0, 1,
		40, 30,
		20, 11, 0.f
	);
	Create_Animation(
		L"BG_Blue_Panel_Crack", L"2",
		1, 0, 1,
		40, 30,
		20, 11, 0.f
	);
	Create_Animation(
		L"BG_Blue_Panel_Crack", L"3",
		2, 0, 1,
		40, 30,
		20, 11, 0.f
	);

	Create_Animation(
		L"BG_Blue_Panel_Ice", L"1",
		0, 0, 1,
		40, 30,
		20, 11, 0.f
	);
	Create_Animation(
		L"BG_Blue_Panel_Ice", L"2",
		1, 0, 1,
		40, 30,
		20, 11, 0.f
	);
	Create_Animation(
		L"BG_Blue_Panel_Ice", L"3",
		2, 0, 1,
		40, 30,
		20, 11, 0.f
	);

	Create_Animation(
		L"BG_Blue_Panel_Grass", L"1",
		0, 0, 1,
		40, 30,
		20, 11, 0.f
	);
	Create_Animation(
		L"BG_Blue_Panel_Grass", L"2",
		1, 0, 1,
		40, 30,
		20, 11, 0.f
	);
	Create_Animation(
		L"BG_Blue_Panel_Grass", L"3",
		2, 0, 1,
		40, 30,
		20, 11, 0.f
	);

	Create_Animation(
		L"BG_Blue_Panel_Magma", L"1",
		0, 0, 1,
		40, 30,
		20, 11, 0.f
	);
	Create_Animation(
		L"BG_Blue_Panel_Magma", L"2",
		1, 0, 1,
		40, 30,
		20, 11, 0.f
	);
	Create_Animation(
		L"BG_Blue_Panel_Magma", L"3",
		2, 0, 1,
		40, 30,
		20, 11, 0.f
	);

	Create_Animation(
		L"BG_Blue_Panel_Sand", L"1",
		0, 0, 1,
		40, 30,
		20, 11, 0.f
	);
	Create_Animation(
		L"BG_Blue_Panel_Sand", L"2",
		1, 0, 1,
		40, 30,
		20, 11, 0.f
	);
	Create_Animation(
		L"BG_Blue_Panel_Sand", L"3",
		2, 0, 1,
		40, 30,
		20, 11, 0.f
	);

	Create_Animation(
		L"BG_Blue_Panel_Poison", L"1",
		0, 0, 10,
		40, 30,
		20, 11, 0.5f
	);
	Create_Animation(
		L"BG_Blue_Panel_Poison", L"2",
		1 *10, 0, 10,
		40, 30,
		20, 11, 0.5f
	);
	Create_Animation(
		L"BG_Blue_Panel_Poison", L"3",
		2 *10, 0, 10,
		40, 30,
		20, 11, 0.5f
	);

	Create_Animation(
		L"BG_Blue_Panel_Holy", L"1",
		0, 0, 7,
		40, 30,
		20, 11, 0.5f
	);
	Create_Animation(
		L"BG_Blue_Panel_Holy", L"2",
		1 *7, 0, 7,
		40, 30,
		20, 11, 0.5f
	);
	Create_Animation(
		L"BG_Blue_Panel_Holy", L"3",
		2 *7, 0, 7,
		40, 30,
		20, 11, 0.5f
	);

	Create_Animation(
		L"BG_Blue_Panel_Right", L"1",
		0, 0, 4,
		40, 30,
		20, 11, 0.5f
	);
	Create_Animation(
		L"BG_Blue_Panel_Right", L"2",
		1 *4, 0, 4,
		40, 30,
		20, 11, 0.5f
	);
	Create_Animation(
		L"BG_Blue_Panel_Right", L"3",
		2 *4, 0, 4,
		40, 30,
		20, 11, 0.5f
	);

	Create_Animation(
		L"BG_Blue_Panel_Left", L"1",
		0, 0, 4,
		40, 30,
		20, 11, 0.5f
	);
	Create_Animation(
		L"BG_Blue_Panel_Left", L"2",
		1 *4, 0, 4,
		40, 30,
		20, 11, 0.5f
	);
	Create_Animation(
		L"BG_Blue_Panel_Left", L"3",
		2 *4, 0, 4,
		40, 30,
		20, 11, 0.5f
	);

	Create_Animation(
		L"BG_Blue_Panel_Up", L"1",
		0, 0, 4,
		40, 30,
		20, 11, 0.5f
	);
	Create_Animation(
		L"BG_Blue_Panel_Up", L"2",
		1 *4, 0, 4,
		40, 30,
		20, 11, 0.5f
	);
	Create_Animation(
		L"BG_Blue_Panel_Up", L"3",
		2 *4, 0, 4,
		40, 30,
		20, 11, 0.5f
	);

	Create_Animation(
		L"BG_Blue_Panel_Down", L"1",
		0, 0, 4,
		40, 30,
		20, 11, 0.5f
	);
	Create_Animation(
		L"BG_Blue_Panel_Down", L"2",
		1 *4, 0, 4,
		40, 30,
		20, 11, 0.5f
	);
	Create_Animation(
		L"BG_Blue_Panel_Down", L"3",
		2 *4, 0, 4,
		40, 30,
		20, 11, 0.5f
	);
#pragma endregion
}

void CAnimationTable::Release()
{

}
