#include "PlayerData.h"

#include "Manager/ChipDataTable.h"

CPlayerData* CPlayerData::g_pInstance = nullptr;

void CPlayerData::Initialize()
{
	m_Folder_List.reserve(30);

	FolderChip_Create(0, ECHIP_CODE::A);
	FolderChip_Create(0, ECHIP_CODE::A);
	FolderChip_Create(0, ECHIP_CODE::B);
	FolderChip_Create(0, ECHIP_CODE::B);

	FolderChip_Create(3, ECHIP_CODE::WILD_CARD);
	FolderChip_Create(3, ECHIP_CODE::WILD_CARD);

	FolderChip_Create(4, ECHIP_CODE::D);
	FolderChip_Create(4, ECHIP_CODE::D);
	FolderChip_Create(4, ECHIP_CODE::D);

	FolderChip_Create(1, ECHIP_CODE::A);
	FolderChip_Create(1, ECHIP_CODE::B);
	FolderChip_Create(2, ECHIP_CODE::B);
	FolderChip_Create(2, ECHIP_CODE::A);

	FolderChip_Create(69, ECHIP_CODE::S);
	FolderChip_Create(69, ECHIP_CODE::S);
	FolderChip_Create(70, ECHIP_CODE::S);
	FolderChip_Create(70, ECHIP_CODE::S);
	FolderChip_Create(71, ECHIP_CODE::S);
	FolderChip_Create(71, ECHIP_CODE::S);

	FolderChip_Create(176, ECHIP_CODE::WILD_CARD);

	FolderChip_Create(87, ECHIP_CODE::WILD_CARD);
	FolderChip_Create(87, ECHIP_CODE::WILD_CARD);

	FolderChip_Create(155, ECHIP_CODE::A);
	FolderChip_Create(155, ECHIP_CODE::A);
	FolderChip_Create(156, ECHIP_CODE::WILD_CARD);
	FolderChip_Create(156, ECHIP_CODE::WILD_CARD);

	FolderChip_Create(164, ECHIP_CODE::S);
	FolderChip_Create(195, ECHIP_CODE::WILD_CARD);
	FolderChip_Create(195, ECHIP_CODE::WILD_CARD);
	FolderChip_Create(195, ECHIP_CODE::WILD_CARD);
}

void CPlayerData::Release()
{
}

void CPlayerData::FolderChip_Create(int iID, ECHIP_CODE eCode)
{
	if (m_Folder_List.size() > 30)
		return;

	m_Folder_List.push_back(CChipDataTable::Get_Instance()->Get_ChipData_ForFolder(iID));
	m_Folder_List.back().eCode = eCode;
}
