#include "ChipDataTable.h"


CChipDataTable* CChipDataTable::g_pInstance = nullptr;
int	CChipDataTable::iID_Count = 0;

void CChipDataTable::Initialize()
{
#ifdef CHIP_TEMPLATE
#pragma region ���ø�

	Create_ChipData(
		L"1", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"2", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"3", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion
#pragma region ���� ���ø�

	Create_ChipData(
		L"1", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::, ECHIP_CODE::, ECHIP_CODE:: },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"2", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::, ECHIP_CODE::, ECHIP_CODE:: },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"3", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::, ECHIP_CODE::, ECHIP_CODE:: },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion
#endif

#pragma region ���Ĵٵ� Ĩ
#pragma region No.1~50
#pragma region ĳ��
	Create_ChipData(
		L"ĳ��", L"���� �ϳ��� ���� ����!", 
		40, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = {ECHIP_CODE::A, ECHIP_CODE::B, ECHIP_CODE::C, ECHIP_CODE::WILD_CARD}, 
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"���� ĳ��", L"���� �ϳ��� ���� ����!",
		80, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::D, ECHIP_CODE::E, ECHIP_CODE::F, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"�ް� ĳ��", L"���� �ϳ��� ���� ����!",
		120, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::R, ECHIP_CODE::S, ECHIP_CODE::T, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region ���
	Create_ChipData(
		L"���", L"���� �ϳ��� ���� ���� �о��!",
		20, EATTRIBUTE::WIND,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region ��ĭ
	Create_ChipData(
		L"��ĭ1", L"3���� �߻��Ͽ� ���� ��ĭ �ڱ��� ����!",
		10, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::A, ECHIP_CODE::B, ECHIP_CODE::C, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"��ĭ2", L"4���� �߻��Ͽ� ���� ��ĭ �ڱ��� ����!",
		15, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::D, ECHIP_CODE::E, ECHIP_CODE::F, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"��ĭ3", L"5���� �߻��Ͽ� ���� ��ĭ �ڱ��� ����!",
		20, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::G, ECHIP_CODE::H, ECHIP_CODE::I, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"���۹�ĭ", L"10���� �߻��Ͽ� ���� ��ĭ �ڱ��� ����!",
		20, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::V },
		ECHIP_RARITY::STAR4, ECHIP_CLASS::MEGA
	);
#pragma endregion

#pragma region ���������
	Create_ChipData(
		L"���������1", L"���� �����κ��� �ֺ��� ���� ����!",
		30, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::L, ECHIP_CODE::M, ECHIP_CODE::N, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"���������2", L"���� �����κ��� �ֺ��� ���� ����!",
		60, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::A, ECHIP_CODE::B, ECHIP_CODE::C, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"���������3", L"���� �����κ��� �ֺ��� ���� ����!",
		90, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::Q, ECHIP_CODE::R, ECHIP_CODE::S, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region ������
	
	Create_ChipData(
		L"������1", L"���� ��ġ�� �߰� ���� ����!",
		120, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::A, ECHIP_CODE::G, ECHIP_CODE::R },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"������2", L"���� ��ġ�� �߰� ���� ����!",
		160, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::L, ECHIP_CODE::S, ECHIP_CODE::V },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"������3", L"���� ��ġ�� �߰� ���� ����!",
		200, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::B, ECHIP_CODE::M, ECHIP_CODE::P },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region �ǵ���

	Create_ChipData(
		L"�ǵ���1", L"������ ������ ������ ���� ������� �ش�",
		1, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::C, ECHIP_CODE::M, ECHIP_CODE::T, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"�ǵ���2", L"������ ������ ������ ���� ������� �ش�",
		1, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::B, ECHIP_CODE::E, ECHIP_CODE::R },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"�ǵ���3", L"������ ������ ������ ���� ������� �ش�",
		1, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::N, ECHIP_CODE::Q, ECHIP_CODE::W },
		ECHIP_RARITY::STAR4, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region ���
	Create_ChipData(
		L"���", L"3ĭ ���� ���� ���� �����ϰ� ���ƿ´�",
		50, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::L, ECHIP_CODE::M, ECHIP_CODE::N, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region ���� ����

	Create_ChipData(
		L"�������1", L"3ĭ �տ� �ִ� ������ �ҷ� �¿��!",
		70, EATTRIBUTE::FIRE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::F, ECHIP_CODE::G, ECHIP_CODE::H, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"�������2", L"3ĭ �տ� �ִ� ������ �ҷ� �¿��!",
		110, EATTRIBUTE::FIRE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::S, ECHIP_CODE::T, ECHIP_CODE::U },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"�������3", L"3ĭ �տ� �ִ� ������ �ҷ� �¿��!",
		150, EATTRIBUTE::FIRE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::C, ECHIP_CODE::D, ECHIP_CODE::E },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region ���̵弦

	Create_ChipData(
		L"���̵弦", L"���� ������ �������� ���Ѵ�",
		100, EATTRIBUTE::AQUA,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::P, ECHIP_CODE::Q, ECHIP_CODE::R },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region Ʈ���ξַο�

	Create_ChipData(
		L"Ʈ���ξַο�1", L"�������� ȭ���� ����ó�� ������ ȭ���� �߻��Ѵ�",
		30, EATTRIBUTE::AQUA,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::A, ECHIP_CODE::F, ECHIP_CODE::K },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"Ʈ���ξַο�2", L"�������� ȭ���� ����ó�� ������ ȭ���� �߻��Ѵ�",
		40, EATTRIBUTE::AQUA,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::G, ECHIP_CODE::M, ECHIP_CODE::Z },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"Ʈ���ξַο�3", L"�������� ȭ���� ����ó�� ������ ȭ���� �߻��Ѵ�",
		50, EATTRIBUTE::AQUA,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::M, ECHIP_CODE::S, ECHIP_CODE::Y },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region ����Ÿ

	Create_ChipData(
		L"����Ÿ1", L"���Ʒ��� �̵��ϸ� �����ϴ� �Ұ��縮",
		60, EATTRIBUTE::AQUA,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::B, ECHIP_CODE::E, ECHIP_CODE::T },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"����Ÿ2", L"���Ʒ��� �̵��ϸ� �����ϴ� �Ұ��縮",
		80, EATTRIBUTE::AQUA,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::C, ECHIP_CODE::L, ECHIP_CODE::V },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"����Ÿ3", L"���Ʒ��� �̵��ϸ� �����ϴ� �Ұ��縮",
		100, EATTRIBUTE::AQUA,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::G, ECHIP_CODE::R, ECHIP_CODE::S },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region �����

	Create_ChipData(
		L"�����", L"������ ���ⱸü�� ��� ���� �����ϰ� �����Ų��",
		40, EATTRIBUTE::ELEC,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::B, ECHIP_CODE::R, ECHIP_CODE::S, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region �����

	Create_ChipData(
		L"�����1", L"������ ������ ������ ���Ѵ�",
		120, EATTRIBUTE::ELEC,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::A, ECHIP_CODE::E, ECHIP_CODE::Q },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"�����2", L"������ ������ ������ ���Ѵ�",
		150, EATTRIBUTE::ELEC,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::C, ECHIP_CODE::L, ECHIP_CODE::P },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"�����3", L"������ ������ ������ ���Ѵ�",
		180, EATTRIBUTE::ELEC,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::B, ECHIP_CODE::R, ECHIP_CODE::V },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region �Ϸ��޽�

	Create_ChipData(
		L"�Ϸ��޽�1", L"������ ��ä�� ������� ���� �޽��� ���",
		100, EATTRIBUTE::ELEC,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::J, ECHIP_CODE::L, ECHIP_CODE::S },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"�Ϸ��޽�2", L"������ ��ä�� ������� ���� �޽��� ���",
		120, EATTRIBUTE::ELEC,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::A, ECHIP_CODE::E, ECHIP_CODE::J },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"�Ϸ��޽�3", L"������ ��ä�� ������� ���� �޽��� ���",
		140, EATTRIBUTE::ELEC,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::A, ECHIP_CODE::J, ECHIP_CODE::S },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region �ܼ�

	Create_ChipData(
		L"�ܼ�1", L"3ĭ ������ ������ ��ź�� ������ 3���� ������ ����Ų��",
		50, EATTRIBUTE::WOOD,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::J, ECHIP_CODE::K, ECHIP_CODE::L },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"�ܼ�2", L"3ĭ ������ ������ ��ź�� ������ 3���� ������ ����Ų��",
		60, EATTRIBUTE::WOOD,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::C, ECHIP_CODE::D, ECHIP_CODE::E },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"�ܼ�3", L"3ĭ ������ ������ ��ź�� ������ 3���� ������ ����Ų��",
		70, EATTRIBUTE::WOOD,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::P, ECHIP_CODE::Q, ECHIP_CODE::R },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region ����Ű���

	Create_ChipData(
		L"����Ű���1", L"������ ���� ���� ���� 5�� �����Ѵ�",
		10, EATTRIBUTE::WOOD,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::B, ECHIP_CODE::G, ECHIP_CODE::S },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"����Ű���2", L"������ ���� ���� ���� 5�� �����Ѵ�",
		15, EATTRIBUTE::WOOD,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::C, ECHIP_CODE::R, ECHIP_CODE::V },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"����Ű���3", L"������ ���� ���� ���� 5�� �����Ѵ�",
		20, EATTRIBUTE::WOOD,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::A, ECHIP_CODE::D, ECHIP_CODE::M },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region �Ѹ��α�

	Create_ChipData(
		L"�Ѹ��α�1", L"2ĭ�� �����ϴ� �볪���� 2�� �߻��Ͽ� ������",
		50, EATTRIBUTE::WOOD,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::I, ECHIP_CODE::K, ECHIP_CODE::P },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"�Ѹ��α�2", L"2ĭ�� �����ϴ� �볪���� 2�� �߻��Ͽ� ������",
		70, EATTRIBUTE::WOOD,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::E, ECHIP_CODE::Q, ECHIP_CODE::Z },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"�Ѹ��α�3", L"2ĭ�� �����ϴ� �볪���� 2�� �߻��Ͽ� ������",
		90, EATTRIBUTE::WOOD,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::F, ECHIP_CODE::N, ECHIP_CODE::W },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region ���̾�

	Create_ChipData(
		L"���̾�1", L"�������� �����ϸ� ������ ���̾� ���� �߻��Ѵ�",
		70, EATTRIBUTE::BREAKING,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::J, ECHIP_CODE::K, ECHIP_CODE::L },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"���̾�2", L"�������� �����ϸ� ������ ���̾� ���� �߻��Ѵ�",
		100, EATTRIBUTE::BREAKING,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::C, ECHIP_CODE::D, ECHIP_CODE::E },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"���̾�3", L"�������� �����ϸ� ������ ���̾� ���� �߻��Ѵ�",
		130, EATTRIBUTE::BREAKING,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::L, ECHIP_CODE::M, ECHIP_CODE::N },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region �������

	Create_ChipData(
		L"�������1", L"��ġ�⸦ ���ϴ� ������带 ��ȯ�Ѵ�",
		130, EATTRIBUTE::BREAKING,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::B, ECHIP_CODE::C, ECHIP_CODE::D },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"�������2", L"��ġ�⸦ ���ϴ� ������带 ��ȯ�Ѵ�",
		150, EATTRIBUTE::BREAKING,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::D, ECHIP_CODE::E, ECHIP_CODE::F },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"�������3", L"��ġ�⸦ ���ϴ� ������带 ��ȯ�Ѵ�",
		170, EATTRIBUTE::BREAKING,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::F, ECHIP_CODE::G, ECHIP_CODE::H },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion
#pragma endregion

#pragma region No.51~102
#pragma region ������Ű

	Create_ChipData(
		L"������Ű", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::L, ECHIP_CODE::M, ECHIP_CODE::N },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region �帱��

	Create_ChipData(
		L"�帱��", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::G, ECHIP_CODE::M, ECHIP_CODE::N },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region ����̵�

	Create_ChipData(
		L"����̵�", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::L, ECHIP_CODE::R, ECHIP_CODE::T },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region �������

	Create_ChipData(
		L"�������", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::G, ECHIP_CODE::S, ECHIP_CODE::V },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region �ӽŰ�

	Create_ChipData(
		L"�ӽŰ�1", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::A, ECHIP_CODE::R, ECHIP_CODE::T, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"�ӽŰ�2", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::E, ECHIP_CODE::G, ECHIP_CODE::S },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"�ӽŰ�3", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::B, ECHIP_CODE::F, ECHIP_CODE::M },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region ��

	Create_ChipData(
		L"�̴Ϻ�", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::B, ECHIP_CODE::L, ECHIP_CODE::R, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"��", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::O, ECHIP_CODE::P, ECHIP_CODE::V },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"��������", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::C, ECHIP_CODE::K, ECHIP_CODE::V, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"�ް� ��������", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::G, ECHIP_CODE::M, ECHIP_CODE::O, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region �÷��� ��

	Create_ChipData(
		L"�÷��� ��1", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::J, ECHIP_CODE::L, ECHIP_CODE::Q, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"�÷��� ��2", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::G, ECHIP_CODE::K, ECHIP_CODE::R },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"�÷��� ��3", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::H, ECHIP_CODE::P, ECHIP_CODE::S },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region Ư�� ��

	Create_ChipData(
		L"�� ��", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::B, ECHIP_CODE::F, ECHIP_CODE::O },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"���� ��", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::G, ECHIP_CODE::S, ECHIP_CODE::V },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region �õ�

	Create_ChipData(
		L"�׷��� �õ�", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::A, ECHIP_CODE::F, ECHIP_CODE::S, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"���̽� �õ�", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::A, ECHIP_CODE::L, ECHIP_CODE::R, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"������ �õ�", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::H, ECHIP_CODE::N, ECHIP_CODE::P },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region �ҵ�

	Create_ChipData(
		L"�ҵ�", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::H, ECHIP_CODE::L, ECHIP_CODE::S, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"���̵� �ҵ�", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::H, ECHIP_CODE::L, ECHIP_CODE::S, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"�� �ҵ�", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::H, ECHIP_CODE::L, ECHIP_CODE::S, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region ���̵�

	Create_ChipData(
		L"���̵� ���̵�", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::B, ECHIP_CODE::R, ECHIP_CODE::W },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"�� ���̵�", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::B, ECHIP_CODE::M, ECHIP_CODE::V },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region �Ӽ� �ҵ�

	Create_ChipData(
		L"�÷��� �ҵ�", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::F, ECHIP_CODE::O, ECHIP_CODE::Z },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"����� �ҵ�", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::A, ECHIP_CODE::I, ECHIP_CODE::Y },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"�Ϸ� �ҵ�", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::E, ECHIP_CODE::K, ECHIP_CODE::N },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"��� �ҵ�", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::H, ECHIP_CODE::S, ECHIP_CODE::W },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"���� ����", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::F, ECHIP_CODE::J, ECHIP_CODE::R, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"���� �ҵ�", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::B, ECHIP_CODE::L, ECHIP_CODE::P },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"�踮��� �ҵ�", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::K, ECHIP_CODE::V, ECHIP_CODE::W },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"�׿� �踮���", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::N },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"�� ���̵�", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::A, ECHIP_CODE::M, ECHIP_CODE::T },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"���󸶻�", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::M },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"�ӽ� �ҵ�", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::H, ECHIP_CODE::L, ECHIP_CODE::Q },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"������Ʈ �ҵ�", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::J, ECHIP_CODE::M, ECHIP_CODE::U },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"��ؽ� �ҵ�", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::N, ECHIP_CODE::R, ECHIP_CODE::Y },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region ��

	Create_ChipData(
		L"ũ�� ��", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::A, ECHIP_CODE::G, ECHIP_CODE::T, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"���� ��", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::C, ECHIP_CODE::R, ECHIP_CODE::U, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"Ʈ���� ��", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::J, ECHIP_CODE::L, ECHIP_CODE::V, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region ���÷�Ʈ ��

	Create_ChipData(
		L"���÷�Ʈ ��1", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::A, ECHIP_CODE::C, ECHIP_CODE::P, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"���÷�Ʈ ��2", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::B, ECHIP_CODE::G, ECHIP_CODE::Y, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"���÷�Ʈ ��3", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::E, ECHIP_CODE::F, ECHIP_CODE::O, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region ���̺� ��

	Create_ChipData(
		L"���̺� ��1", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::E, ECHIP_CODE::F, ECHIP_CODE::G },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"���̺� ��2", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::L, ECHIP_CODE::M, ECHIP_CODE::N },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"���̺� ��3", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::R, ECHIP_CODE::S, ECHIP_CODE::T },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region ���� ��

	Create_ChipData(
		L"���� ��1", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::A, ECHIP_CODE::G, ECHIP_CODE::L },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"���� ��2", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::B, ECHIP_CODE::R, ECHIP_CODE::Y },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"���� ��3", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::H, ECHIP_CODE::J, ECHIP_CODE::S },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region ���� ��

	Create_ChipData(
		L"���� ��1", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::E, ECHIP_CODE::I, ECHIP_CODE::P },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"���� ��2", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::H, ECHIP_CODE::O, ECHIP_CODE::V },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"���� ��3", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::W, ECHIP_CODE::Y, ECHIP_CODE::Z },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion
#pragma endregion

#pragma region No.103~150
#pragma region ������ũ, �ѹ���
	Create_ChipData(
		L"������ũ", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::H, ECHIP_CODE::L, ECHIP_CODE::M },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"�ѹ���", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::N},
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region ���̾� ��ġ

	Create_ChipData(
		L"���̾� ��ġ1", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"���̾� ��ġ2", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"���̾� ��ġ3", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region �� ������

	Create_ChipData(
		L"�� ������1", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"�� ������2", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"�� ������3", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region ������

	Create_ChipData(
		L"������", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region ����� �ϵ�

	Create_ChipData(
		L"����� �ϵ�1", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"����� �ϵ�2", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"����� �ϵ�3", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region ���ڵ� ��

	Create_ChipData(
		L"���ڵ� ��", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region ų�� ����

	Create_ChipData(
		L"ų�� ����1", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"ų�� ����2", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"ų�� ����3", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region �θ޶�

	Create_ChipData(
		L"�θ޶�", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"���� �θ޶�", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"�ް� �θ޶�", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region ����

	Create_ChipData(
		L"����", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region ������Ʈ �巡��

	Create_ChipData(
		L"��Ʈ �巡��", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"�Ϸ� �巡��", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"����� �巡��", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"��� �巡��", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region �� ��ġ

	Create_ChipData(
		L"�� ��ġ 1", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"�� ��ġ 2", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"�� ��ġ 3", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region ����Ƽ�� ��

	Create_ChipData(
		L"����Ƽ�� ��", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region ���� ��

	Create_ChipData(
		L"���� �� 1", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"���� �� 2", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"���� �� 3", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region ��ǳ��

	Create_ChipData(
		L"��ǳ�߻���", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"���Ա�", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region �ű׳�, ��Ŭ ��, ����ť��

	Create_ChipData(
		L"�ű׳�", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"��Ŭ ��", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"����ť��", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region ��Ʋ ���Ϸ�

	Create_ChipData(
		L"��Ʋ ���Ϸ� 1", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"��Ʋ ���Ϸ� 2", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"��Ʋ ���Ϸ� 3", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region ����̵�

	Create_ChipData(
		L"����̵� 1", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"����̵� 2", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"����̵� 3", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region ī��Ʈ ��, ���ڽ� ����

	Create_ChipData(
		L"ī��Ʈ �� 1", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"ī��Ʈ �� 2", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"ī��Ʈ �� 3", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"���ڽ� ����", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region ������, ���ڵ�, ���Ĵ�, ���Ϸ���, ��ġ ����, �������

	Create_ChipData(
		L"������", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"���ڵ�", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"���Ĵ�", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"���Ϸ���", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion
#pragma endregion

#pragma region No.153~200
#pragma region ¤����, ���庸��, ������ �ƴ���

	Create_ChipData(
		L"¤����", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"���庸��", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"������ �ƴ���", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region ��Ŀ������

	Create_ChipData(
		L"��Ŀ���� 10", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"��Ŀ���� 30", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"��Ŀ���� 50", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"��Ŀ���� 80", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"��Ŀ���� 120", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"��Ŀ���� 150", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"��Ŀ���� 200", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"��Ŀ���� 300", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region ������ ��ƿ��

	Create_ChipData(
		L"�г� ��ƿ", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"������ ��ƿ", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"��ƿ �۴Ͻ�", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"��ƿ ������", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region �г� ���۷�

	Create_ChipData(
		L"�г� ����", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"������ġ", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"Ȧ�� �г�", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"����", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"Ŀ�ַε�", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"���׷ε�", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region Ŀ���� ������ ���۷�

	Create_ChipData(
		L"��������", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"��������", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"ǮĿ����", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region ��ƿ��

	Create_ChipData(
		L"�����;�", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"���׼���", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"�κ�����", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region �踮���

	Create_ChipData(
		L"�踮��", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"�踮�� 100", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"�踮�� 200", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"����", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"�帲����", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region ���׳� ����, Ŀ�ھƹ�

	Create_ChipData(
		L"���׳�����", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"Ŀ�ھƹ�", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region ī���ͷ�

	Create_ChipData(
		L"������ƮƮ��", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"�׺� ��ī��Ʈ", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"�ٲ�ġ��", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"Į�����", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"���޵�", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"ȭ��Ʈĸ��", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"���ν���", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region ��ũ�η�

	Create_ChipData(
		L"ī�ǵ�����", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"��������ũ��", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region ������ ������

	Create_ChipData(
		L"���� +10", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"���� +30", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"�׺� +20", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"�÷�����Ʈ", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"��������Ʈ", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion
#pragma endregion
#pragma endregion

#pragma region �ް� Ŭ���� Ĩ

#pragma endregion


#pragma region �Ⱑ Ŭ���� Ĩ

#pragma endregion


}

void CChipDataTable::Release()
{
	for (auto iter = m_StandardTable_Map.begin(); iter != m_StandardTable_Map.end(); )
	{
		Safe_Delete((*iter).second);
		iter = m_StandardTable_Map.erase(iter);
	}

	for (auto iter = m_MegaTable_Map.begin(); iter != m_MegaTable_Map.end(); )
	{
		Safe_Delete((*iter).second);
		iter = m_MegaTable_Map.erase(iter);
	}

	for (auto iter = m_GigaTable_Map.begin(); iter != m_GigaTable_Map.end(); )
	{
		Safe_Delete((*iter).second);
		iter = m_GigaTable_Map.erase(iter);
	}
}
