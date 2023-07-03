#include "Manager/AnimationTable.h"

CAnimationTable* CAnimationTable::g_pInstance = nullptr;

void CAnimationTable::Initialize()
{
	int iID = 0;
#pragma region 록맨 애니메이션 데이터

#pragma region 노멀
	Create_Animation(
		L"NBT_Rockman_EXE_Normal", L"Idle",
		iID++, 0, 67, 55,
		26, 30, 0.f
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal", L"Hit",
		iID++, 8, 67, 55,
		26, 30, 0.25f
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal", L"Paralyze",
		iID++, 1, 67, 55,
		26, 30, 0.25f
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal", L"Move_End",
		iID++, 1, 67, 55,
		26, 30, 0.5f
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal", L"Move_Ready",
		iID++, 1, 67, 55,
		26, 30, 0.5f
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal", L"Sword",
		iID++, 1, 67, 55,
		26, 30, 0.25f
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal", L"Throw",
		iID++, 1, 67, 55,
		26, 30, 0.25f
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal", L"Crouch",
		iID++, 1, 67, 55,
		26, 30, 0.25f
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal", L"Shoot_Cannon",
		iID++, 1, 67, 55,
		26, 30, 0.25f
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal", L"Shoot_Buster",
		iID++, 1, 67, 55,
		26, 30, 0.25f
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal", L"Shoot_Duration",
		iID++, 1, 67, 55,
		26, 30, 0.25f
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal", L"Throw_Disk",
		iID++, 1, 67, 55,
		26, 30, 0.25f
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal", L"Shoot_1",
		iID++, 1, 67, 55,
		26, 30, 0.25f
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal", L"Ready_Crouch_1",
		iID++, 1, 67, 55,
		26, 30, 0.25f
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal", L"Shoot_2",
		iID++, 1, 67, 55,
		26, 30, 0.25f
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal", L"Ready_Crouch_2",
		iID++, 1, 67, 55,
		26, 30, 0.25f
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal", L"Ready_Swing",
		iID++, 1, 67, 55,
		26, 30, 0.25f
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal", L"Swing",
		iID++, 1, 67, 55,
		26, 30, 0.25f
	);
	Create_Animation(
		L"NBT_Rockman_EXE_Normal", L"Crouch",
		iID++, 1, 67, 55,
		26, 30, 0.25f
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
#pragma region 판넬 애니메이션 데이터

#pragma endregion

}

void CAnimationTable::Release()
{

}
