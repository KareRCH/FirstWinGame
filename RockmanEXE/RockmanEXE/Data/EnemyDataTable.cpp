#include "EnemyDataTable.h"

CEnemyDataTable* CEnemyDataTable::g_pInstance = nullptr;
int CEnemyDataTable::iID_Count = 0;

void CEnemyDataTable::Initialize()
{
	Add_Enemy(L"¸äÅø", 40, 10);
	Add_Enemy(L"¸äÅø V2", 80, 30);
	Add_Enemy(L"¸äÅø V3", 120, 50);
	Add_Enemy(L"¸äÅø SP", 160, 70);

	Add_Enemy(L"°Å³Ê", 60, 10);
	Add_Enemy(L"°Å³Ê V2", 120, 30);
	Add_Enemy(L"°Å³Ê V3", 180, 50);
	Add_Enemy(L"°Å³Ê SP", 240, 70);

	Add_Enemy(L"Ä«ÅÊ", 100, 30);
	Add_Enemy(L"Ä«ÅÊ V2", 200, 50);
	Add_Enemy(L"Ä«ÅÊ V3", 300, 90);
	Add_Enemy(L"Ä«ÅÊ SP", 400, 130);
}

void CEnemyDataTable::Release()
{

}
