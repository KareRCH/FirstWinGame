#include "ChipDataTable.h"


CChipDataTable* CChipDataTable::g_pInstance = nullptr;
int	CChipDataTable::iID_Count = 0;

void CChipDataTable::Initialize()
{
#ifdef CHIP_TEMPLATE
#pragma region 템플릿

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
#pragma region 더미 템플릿

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

#pragma region No.1~50
#pragma region 캐논
	Create_ChipData(
		L"캐논1", L"전방 하나의 적을 포격!", 
		40, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = {ECHIP_CODE::A, ECHIP_CODE::B, ECHIP_CODE::C, ECHIP_CODE::WILD_CARD}, 
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"캐논2", L"전방 하나의 적을 포격!",
		80, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::D, ECHIP_CODE::E, ECHIP_CODE::F, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"캐논3", L"전방 하나의 적을 포격!",
		120, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::R, ECHIP_CODE::S, ECHIP_CODE::T, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 에어슛
	Create_ChipData(
		L"에어슛", L"전방 하나의 적을 맞춰 밀어낸다!",
		20, EATTRIBUTE::WIND,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 발칸
	Create_ChipData(
		L"발칸1", L"3발을 발사하여 적의 한칸 뒤까지 공격!",
		10, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::A, ECHIP_CODE::B, ECHIP_CODE::C, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"발칸2", L"4발을 발사하여 적의 한칸 뒤까지 공격!",
		15, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::D, ECHIP_CODE::E, ECHIP_CODE::F, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"발칸3", L"5발을 발사하여 적의 한칸 뒤까지 공격!",
		20, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::G, ECHIP_CODE::H, ECHIP_CODE::I, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"슈퍼발칸", L"10발을 발사하여 적의 한칸 뒤까지 공격!",
		20, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::V },
		ECHIP_RARITY::STAR4, ECHIP_CLASS::MEGA
	);
#pragma endregion

#pragma region 스프레드건
	Create_ChipData(
		L"스프레드건1", L"맞힌 적으로부터 주변을 같이 공격!",
		30, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::L, ECHIP_CODE::M, ECHIP_CODE::N, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"스프레드건2", L"맞힌 적으로부터 주변을 같이 공격!",
		60, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::A, ECHIP_CODE::B, ECHIP_CODE::C, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"스프레드건3", L"맞힌 적으로부터 주변을 같이 공격!",
		90, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::Q, ECHIP_CODE::R, ECHIP_CODE::S, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 전차포
	
	Create_ChipData(
		L"전차포1", L"포격 위치에 추가 상하 공격!",
		120, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::A, ECHIP_CODE::G, ECHIP_CODE::R },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"전차포2", L"포격 위치에 추가 상하 공격!",
		160, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::L, ECHIP_CODE::S, ECHIP_CODE::V },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"전차포3", L"포격 위치에 추가 상하 공격!",
		200, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::B, ECHIP_CODE::M, ECHIP_CODE::P },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 건델솔

	Create_ChipData(
		L"건델솔1", L"강력한 광선을 적에게 쐬어 대미지를 준다",
		1, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::C, ECHIP_CODE::M, ECHIP_CODE::T, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"건델솔2", L"강력한 광선을 적에게 쐬어 대미지를 준다",
		1, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::B, ECHIP_CODE::E, ECHIP_CODE::R },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"건델솔3", L"강력한 광선을 적에게 쐬어 대미지를 준다",
		1, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::N, ECHIP_CODE::Q, ECHIP_CODE::W },
		ECHIP_RARITY::STAR4, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 요요
	Create_ChipData(
		L"요요", L"3칸 앞의 적을 연속 공격하고 돌아온다",
		50, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::L, ECHIP_CODE::M, ECHIP_CODE::N, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 헬즈 버너

	Create_ChipData(
		L"헬즈버너1", L"3칸 앞에 있는 적까지 불로 태운다!",
		70, EATTRIBUTE::FIRE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::F, ECHIP_CODE::G, ECHIP_CODE::H, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"헬즈버너2", L"3칸 앞에 있는 적까지 불로 태운다!",
		110, EATTRIBUTE::FIRE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::S, ECHIP_CODE::T, ECHIP_CODE::U },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"헬즈버너3", L"3칸 앞에 있는 적까지 불로 태운다!",
		150, EATTRIBUTE::FIRE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::C, ECHIP_CODE::D, ECHIP_CODE::E },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 와이드샷

	Create_ChipData(
		L"와이드샷", L"넢은 범위의 물공격을 가한다",
		100, EATTRIBUTE::AQUA,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::P, ECHIP_CODE::Q, ECHIP_CODE::R },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 트레인애로우

	Create_ChipData(
		L"트레인애로우1", L"여러개의 화살을 열차처럼 줄줄이 화살을 발사한다",
		30, EATTRIBUTE::AQUA,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::A, ECHIP_CODE::F, ECHIP_CODE::K },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"트레인애로우2", L"여러개의 화살을 열차처럼 줄줄이 화살을 발사한다",
		40, EATTRIBUTE::AQUA,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::G, ECHIP_CODE::M, ECHIP_CODE::Z },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"트레인애로우3", L"여러개의 화살을 열차처럼 줄줄이 화살을 발사한다",
		50, EATTRIBUTE::AQUA,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::M, ECHIP_CODE::S, ECHIP_CODE::Y },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 버블스타

	Create_ChipData(
		L"버블스타1", L"위아래로 이동하며 전진하는 불가사리",
		60, EATTRIBUTE::AQUA,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::B, ECHIP_CODE::E, ECHIP_CODE::T },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"버블스타2", L"위아래로 이동하며 전진하는 불가사리",
		80, EATTRIBUTE::AQUA,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::C, ECHIP_CODE::L, ECHIP_CODE::V },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"버블스타3", L"위아래로 이동하며 전진하는 불가사리",
		100, EATTRIBUTE::AQUA,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::G, ECHIP_CODE::R, ECHIP_CODE::S },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 썬더볼

	Create_ChipData(
		L"썬더볼", L"느릿한 전기구체를 쏘아 적을 추적하고 마비시킨다",
		40, EATTRIBUTE::ELEC,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::B, ECHIP_CODE::R, ECHIP_CODE::S, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 돌썬더

	Create_ChipData(
		L"돌썬더1", L"전방의 적에게 전격을 가한다",
		120, EATTRIBUTE::ELEC,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::A, ECHIP_CODE::E, ECHIP_CODE::Q },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"돌썬더2", L"전방의 적에게 전격을 가한다",
		150, EATTRIBUTE::ELEC,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::C, ECHIP_CODE::L, ECHIP_CODE::P },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"돌썬더3", L"전방의 적에게 전격을 가한다",
		180, EATTRIBUTE::ELEC,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::B, ECHIP_CODE::R, ECHIP_CODE::V },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 일렉펄스

	Create_ChipData(
		L"일렉펄스1", L"전방의 부채꼴 모양으로 전기 펄스를 쏜다",
		100, EATTRIBUTE::ELEC,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::J, ECHIP_CODE::L, ECHIP_CODE::S },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"일렉펄스2", L"전방의 부채꼴 모양으로 전기 펄스를 쏜다",
		120, EATTRIBUTE::ELEC,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::A, ECHIP_CODE::E, ECHIP_CODE::J },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"일렉펄스3", L"전방의 부채꼴 모양으로 전기 펄스를 쏜다",
		140, EATTRIBUTE::ELEC,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::A, ECHIP_CODE::J, ECHIP_CODE::S },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 콘샷

	Create_ChipData(
		L"콘샷1", L"3칸 앞으로 던져서 착탄한 지점에 3번의 폭발을 일으킨다",
		50, EATTRIBUTE::WOOD,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::J, ECHIP_CODE::K, ECHIP_CODE::L },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"콘샷2", L"3칸 앞으로 던져서 착탄한 지점에 3번의 폭발을 일으킨다",
		60, EATTRIBUTE::WOOD,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::C, ECHIP_CODE::D, ECHIP_CODE::E },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"콘샷3", L"3칸 앞으로 던져서 착탄한 지점에 3번의 폭발을 일으킨다",
		70, EATTRIBUTE::WOOD,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::P, ECHIP_CODE::Q, ECHIP_CODE::R },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 리스키허니

	Create_ChipData(
		L"리스키허니1", L"벌들을 보내 맞은 적을 5번 공격한다",
		10, EATTRIBUTE::WOOD,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::B, ECHIP_CODE::G, ECHIP_CODE::S },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"리스키허니2", L"벌들을 보내 맞은 적을 5번 공격한다",
		15, EATTRIBUTE::WOOD,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::C, ECHIP_CODE::R, ECHIP_CODE::V },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"리스키허니3", L"벌들을 보내 맞은 적을 5번 공격한다",
		20, EATTRIBUTE::WOOD,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::A, ECHIP_CODE::D, ECHIP_CODE::M },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 롤링로그

	Create_ChipData(
		L"롤링로그1", L"2칸을 차지하는 통나무를 2개 발사하여 굴린다",
		50, EATTRIBUTE::WOOD,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::I, ECHIP_CODE::K, ECHIP_CODE::P },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"롤링로그2", L"2칸을 차지하는 통나무를 2개 발사하여 굴린다",
		70, EATTRIBUTE::WOOD,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::E, ECHIP_CODE::Q, ECHIP_CODE::Z },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"롤링로그3", L"2칸을 차지하는 통나무를 2개 발사하여 굴린다",
		90, EATTRIBUTE::WOOD,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::F, ECHIP_CODE::N, ECHIP_CODE::W },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 아이언쉘

	Create_ChipData(
		L"아이언쉘1", L"전방으로 관통하며 구르는 아이언 쉘을 발사한다",
		70, EATTRIBUTE::BREAKING,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::J, ECHIP_CODE::K, ECHIP_CODE::L },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"아이언쉘2", L"전방으로 관통하며 구르는 아이언 쉘을 발사한다",
		100, EATTRIBUTE::BREAKING,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::C, ECHIP_CODE::D, ECHIP_CODE::E },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"아이언쉘3", L"전방으로 관통하며 구르는 아이언 쉘을 발사한다",
		130, EATTRIBUTE::BREAKING,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::L, ECHIP_CODE::M, ECHIP_CODE::N },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 오라헤드

	Create_ChipData(
		L"오라헤드1", L"박치기를 가하는 오라헤드를 소환한다",
		130, EATTRIBUTE::BREAKING,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::B, ECHIP_CODE::C, ECHIP_CODE::D },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"오라헤드2", L"박치기를 가하는 오라헤드를 소환한다",
		150, EATTRIBUTE::BREAKING,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::D, ECHIP_CODE::E, ECHIP_CODE::F },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"오라헤드3", L"박치기를 가하는 오라헤드를 소환한다",
		170, EATTRIBUTE::BREAKING,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::F, ECHIP_CODE::G, ECHIP_CODE::H },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion
#pragma endregion

#pragma region No.51~102
#pragma region 에어하키

	Create_ChipData(
		L"에어하키", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::L, ECHIP_CODE::M, ECHIP_CODE::N },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 드릴암

	Create_ChipData(
		L"드릴암", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::G, ECHIP_CODE::M, ECHIP_CODE::N },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 토네이도

	Create_ChipData(
		L"토네이도", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::L, ECHIP_CODE::R, ECHIP_CODE::T },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 노이즈스톰

	Create_ChipData(
		L"노이즈스톰", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::G, ECHIP_CODE::S, ECHIP_CODE::V },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 머신건

	Create_ChipData(
		L"머신건1", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::A, ECHIP_CODE::R, ECHIP_CODE::T, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"머신건2", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::E, ECHIP_CODE::G, ECHIP_CODE::S },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"머신건3", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::B, ECHIP_CODE::F, ECHIP_CODE::M },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 봄

	Create_ChipData(
		L"미니봄", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::B, ECHIP_CODE::L, ECHIP_CODE::R, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"빅봄", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::O, ECHIP_CODE::P, ECHIP_CODE::V },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"에너지봄", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::C, ECHIP_CODE::K, ECHIP_CODE::V, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"메가 에너지봄", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::G, ECHIP_CODE::M, ECHIP_CODE::O, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 플래시 봄

	Create_ChipData(
		L"플래시 봄1", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::J, ECHIP_CODE::L, ECHIP_CODE::Q, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"플래시 봄2", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::G, ECHIP_CODE::K, ECHIP_CODE::R },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"플래시 봄3", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::H, ECHIP_CODE::P, ECHIP_CODE::S },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 특수 봄

	Create_ChipData(
		L"블랙 봄", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::B, ECHIP_CODE::F, ECHIP_CODE::O },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"버그 봄", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::G, ECHIP_CODE::S, ECHIP_CODE::V },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 시드

	Create_ChipData(
		L"그래스 시드", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::A, ECHIP_CODE::F, ECHIP_CODE::S, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"아이스 시드", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::A, ECHIP_CODE::L, ECHIP_CODE::R, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"포이즌 시드", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::H, ECHIP_CODE::N, ECHIP_CODE::P },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 소드

	Create_ChipData(
		L"소드", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::H, ECHIP_CODE::L, ECHIP_CODE::S, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"와이드 소드", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::H, ECHIP_CODE::L, ECHIP_CODE::S, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"롱 소드", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::H, ECHIP_CODE::L, ECHIP_CODE::S, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 블레이드

	Create_ChipData(
		L"와이드 블레이드", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::B, ECHIP_CODE::R, ECHIP_CODE::W },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"롱 블레이드", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::B, ECHIP_CODE::M, ECHIP_CODE::V },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 속성 소드

	Create_ChipData(
		L"플레임 소드", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::F, ECHIP_CODE::O, ECHIP_CODE::Z },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"아쿠아 소드", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::A, ECHIP_CODE::I, ECHIP_CODE::Y },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"일렉 소드", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::E, ECHIP_CODE::K, ECHIP_CODE::N },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"뱀브 소드", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::H, ECHIP_CODE::S, ECHIP_CODE::W },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"윈드 라켓", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::F, ECHIP_CODE::J, ECHIP_CODE::R, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"스텝 소드", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::B, ECHIP_CODE::L, ECHIP_CODE::P },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"배리어블 소드", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::K, ECHIP_CODE::V, ECHIP_CODE::W },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"네오 배리어블", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::N },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"문 블레이드", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::A, ECHIP_CODE::M, ECHIP_CODE::T },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"무라마사", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::M },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"머신 소드", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::H, ECHIP_CODE::L, ECHIP_CODE::Q },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"엘레멘트 소드", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::J, ECHIP_CODE::M, ECHIP_CODE::U },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"어쌔신 소드", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::N, ECHIP_CODE::R, ECHIP_CODE::Y },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 슛

	Create_ChipData(
		L"크랫 슛", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::A, ECHIP_CODE::G, ECHIP_CODE::T, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"더블 슛", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::C, ECHIP_CODE::R, ECHIP_CODE::U, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"트리플 슛", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::J, ECHIP_CODE::L, ECHIP_CODE::V, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 리플렉트 멧

	Create_ChipData(
		L"리플렉트 멧1", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::A, ECHIP_CODE::C, ECHIP_CODE::P, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"리플렉트 멧2", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::B, ECHIP_CODE::G, ECHIP_CODE::Y, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"리플렉트 멧3", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::E, ECHIP_CODE::F, ECHIP_CODE::O, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 웨이브 암

	Create_ChipData(
		L"웨이브 암1", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::E, ECHIP_CODE::F, ECHIP_CODE::G },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"웨이브 암2", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::L, ECHIP_CODE::M, ECHIP_CODE::N },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"웨이브 암3", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::R, ECHIP_CODE::S, ECHIP_CODE::T },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 샌드 웜

	Create_ChipData(
		L"샌드 웜1", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::A, ECHIP_CODE::G, ECHIP_CODE::L },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"샌드 웜2", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::B, ECHIP_CODE::R, ECHIP_CODE::Y },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"샌드 웜3", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::H, ECHIP_CODE::J, ECHIP_CODE::S },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 서먼 블랙

	Create_ChipData(
		L"서먼 블랙1", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::E, ECHIP_CODE::I, ECHIP_CODE::P },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"서먼 블랙2", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::H, ECHIP_CODE::O, ECHIP_CODE::V },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"서먼 블랙3", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::W, ECHIP_CODE::Y, ECHIP_CODE::Z },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion
#pragma endregion

#pragma region No.103~150

#pragma endregion


}

void CChipDataTable::Release()
{
	for_each(m_Table_Map.begin(), m_Table_Map.end(), [](FChipData_ForTable* item) {
		Safe_Delete(item);
		});
}
