#include "Data/EncountDataTable.h"

CEncountDataTable* CEncountDataTable::g_pInstance = nullptr;
int CEncountDataTable::iID_Count = 0;

void CEncountDataTable::Initialize()
{
	int iCount = -1;
#pragma region ��Ʈ�� ����� ������ �� �ִ� ��Ʈ
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
