#include "Data/EncountDataTable.h"

CEncountDataTable* CEncountDataTable::g_pInstance = nullptr;
int CEncountDataTable::iID_Count = 0;

void CEncountDataTable::Initialize()
{
	int iCount = -1;
#pragma region 센트럴 에리어에 등장할 수 있는 세트
	Add_Data(++iCount);
	//Add_Object(iCount, 0, CVector2<int>());
	Add_Enemy(iCount, 0, CVector2<int>(3, 0));
	Add_Enemy(iCount, 0, CVector2<int>(4, 1));
	Add_Enemy(iCount, 0, CVector2<int>(5, 2));
	Add_Panel_Preset1(iCount);


	Add_Data(++iCount);
	//Add_Object(iCount, 0, CVector2<int>());
	Add_Enemy(iCount, 0, CVector2<int>(4, 1));
	Add_Enemy(iCount, 0, CVector2<int>(5, 0));
	Add_Panel_Preset1(iCount);


	Add_Data(++iCount);
	//Add_Object(iCount, 0, CVector2<int>());
	Add_Enemy(iCount, 0, CVector2<int>(4, 1));
	Add_Enemy(iCount, 0, CVector2<int>(5, 0));
	Add_Enemy(iCount, 0, CVector2<int>(5, 2));
	Add_Panel_Preset1(iCount);


	Add_Data(++iCount);
	//Add_Object(iCount, 0, CVector2<int>());
	Add_Enemy(iCount, 0, CVector2<int>(3, 1));
	Add_Enemy(iCount, 1, CVector2<int>(5, 2));
	Add_Panel_Preset1(iCount);
#pragma endregion

}

void CEncountDataTable::Release()
{

}
