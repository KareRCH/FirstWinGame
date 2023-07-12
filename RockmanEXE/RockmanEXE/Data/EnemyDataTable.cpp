#include "EnemyDataTable.h"

CEnemyDataTable* CEnemyDataTable::g_pInstance = nullptr;
int CEnemyDataTable::iID_Count = 0;

void CEnemyDataTable::Initialize()
{
	Add_Enemy(L"����", 40, 10);
	Add_Enemy(L"���� V2", 80, 30);
	Add_Enemy(L"���� V3", 120, 50);
	Add_Enemy(L"���� SP", 160, 70);

	Add_Enemy(L"�ų�", 60, 10);
	Add_Enemy(L"�ų� V2", 120, 30);
	Add_Enemy(L"�ų� V3", 180, 50);
	Add_Enemy(L"�ų� SP", 240, 70);

	Add_Enemy(L"ī��", 100, 30);
	Add_Enemy(L"ī�� V2", 200, 50);
	Add_Enemy(L"ī�� V3", 300, 90);
	Add_Enemy(L"ī�� SP", 400, 130);
}

void CEnemyDataTable::Release()
{

}
