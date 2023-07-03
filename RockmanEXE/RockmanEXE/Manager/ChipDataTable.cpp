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

#pragma region 스탠다드 칩
#pragma region No.1~50
#pragma region 캐논
	Create_ChipData(
		L"캐논", L"전방 하나의 적을 포격!", 
		40, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = {ECHIP_CODE::A, ECHIP_CODE::B, ECHIP_CODE::C, ECHIP_CODE::WILD_CARD}, 
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"하이 캐논", L"전방 하나의 적을 포격!",
		80, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::D, ECHIP_CODE::E, ECHIP_CODE::F, ECHIP_CODE::WILD_CARD },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"메가 캐논", L"전방 하나의 적을 포격!",
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
#pragma region 스네이크, 넘버볼
	Create_ChipData(
		L"스네이크", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::H, ECHIP_CODE::L, ECHIP_CODE::M },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"넘버볼", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::N},
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 파이어 펀치

	Create_ChipData(
		L"파이어 펀치1", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"파이어 펀치2", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"파이어 펀치3", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 번 스퀘어

	Create_ChipData(
		L"번 스퀘어1", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"번 스퀘어2", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"번 스퀘어3", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 유성군

	Create_ChipData(
		L"유성군", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 아쿠아 니들

	Create_ChipData(
		L"아쿠아 니들1", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"아쿠아 니들2", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"아쿠아 니들3", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 블리자드 볼

	Create_ChipData(
		L"블리자드 볼", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 킬러 센서

	Create_ChipData(
		L"킬러 센서1", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"킬러 센서2", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"킬러 센서3", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 부메랑

	Create_ChipData(
		L"부메랑", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"하이 부메랑", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"메가 부메랑", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 랜스

	Create_ChipData(
		L"랜스", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 엘레멘트 드래곤

	Create_ChipData(
		L"히트 드래곤", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"일렉 드래곤", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"아쿠아 드래곤", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"우드 드래곤", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 골렘 펀치

	Create_ChipData(
		L"골렘 펀치 1", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"골렘 펀치 2", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"골렘 펀치 3", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 저스티스 원

	Create_ChipData(
		L"저스티스 원", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 에어 휠

	Create_ChipData(
		L"에어 휠 1", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"에어 휠 2", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"에어 휠 3", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 선풍기

	Create_ChipData(
		L"돌풍발생기", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"흡입기", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 매그넘, 서클 건, 스톤큐브

	Create_ChipData(
		L"매그넘", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"서클 건", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"스톤큐브", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 리틀 보일러

	Create_ChipData(
		L"리틀 보일러 1", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"리틀 보일러 2", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"리틀 보일러 3", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 에어레이드

	Create_ChipData(
		L"에어레이드 1", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"에어레이드 2", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"에어레이드 3", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 카운트 봄, 스텔스 마인

	Create_ChipData(
		L"카운트 봄 1", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"카운트 봄 2", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"카운트 봄 3", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"스텔스 마인", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 응원가, 디스코드, 팀파니, 사일런스, 설치 버프, 디버프류

	Create_ChipData(
		L"응원가", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"디스코드", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"팀파니", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"사일런스", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion
#pragma endregion

#pragma region No.153~200
#pragma region 짚인형, 지장보살, 포이즌 아누비스

	Create_ChipData(
		L"짚인형", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"지장보살", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"포이즌 아누비스", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 리커버리류

	Create_ChipData(
		L"리커버리 10", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"리커버리 30", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"리커버리 50", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"리커버리 80", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"리커버리 120", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"리커버리 150", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"리커버리 200", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"리커버리 300", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 에리어 스틸류

	Create_ChipData(
		L"패널 스틸", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"에리어 스틸", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"스틸 퍼니시", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"스틸 리벤지", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 패널 조작류

	Create_ChipData(
		L"패널 리턴", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"데스매치", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"홀리 패널", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"생츄어리", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"커밍로드", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"고잉로드", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 커스텀 게이지 조작류

	Create_ChipData(
		L"헤비게이지", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"퀵게이지", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"풀커스텀", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 유틸류

	Create_ChipData(
		L"버스터업", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"버그수정", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"인비지블", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 배리어류

	Create_ChipData(
		L"배리어", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"배리어 100", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"배리어 200", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"버블랩", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"드림오라", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 마그넷 코일, 커넬아미

	Create_ChipData(
		L"마그넷코일", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"커넬아미", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 카운터류

	Create_ChipData(
		L"엘리먼트트랩", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"네비 스카우트", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"바꿔치기", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"칼날잡기", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"배드메디슨", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"화이트캡슐", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"언인스톨", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 싱크로류

	Create_ChipData(
		L"카피데미지", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"라이프싱크로", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
#pragma endregion

#pragma region 데미지 증가류

	Create_ChipData(
		L"어택 +10", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR1, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"어택 +30", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR2, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"네비 +20", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"컬러포인트", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
	Create_ChipData(
		L"더블포인트", L"",
		0, EATTRIBUTE::NONE,
		array<ECHIP_CODE, 5>() = { ECHIP_CODE::NONE, ECHIP_CODE::NONE, ECHIP_CODE::NONE },
		ECHIP_RARITY::STAR3, ECHIP_CLASS::STANDARD
	);
#pragma endregion
#pragma endregion
#pragma endregion

#pragma region 메가 클래스 칩

#pragma endregion


#pragma region 기가 클래스 칩

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
