#pragma once

#include "Define.h"

/*
* 칩에 대한 정보를 기록하기 위한 객체를 만드는 헤더입니다.
* F는 구조체 처럼 쓰는 클래스라는 뜻.
* 언리얼 체계에서 유래
* 헝가리안 표기법도 구조체의 것을 따릅니다.
*/

enum class EATTRIBUTE : int
{
	// 무속성
	NONE, 
	// 속성(상성 관계 있음)
	FIRE, AQUA, ELEC, WOOD,
	// 계통(유틸성)
	CRACKING, RECOVERY, INVISIBLE, PLUS, OBSTACLE, 
	// 계통(상성 관계 있음)
	WIND, SWORD, BREAKING, CURSOR
};

enum class ECHIP_RARITY : int
{
	STAR1, STAR2, STAR3, STAR4, STAR5
};

enum class ECHIP_CLASS : int
{
	STANDARD, MEGA, GIGA
};

enum class ECHIP_CODE : int
{
	NONE,
	A, B, C, D, E, F, G, H, I,
	J, K, L, M, N, O, P, Q, R,
	S, T, U, V, W, X, Y, Z, 
	WILD_CARD
};

// 테이블 전용 데이터 클래스
class FChipData_ForTable final
{
public:
	FChipData_ForTable()
		: iID(), sName(), sDescription(),
		iDamage(), eAttribute(), arrAppearingCode(),
		eRarity(), eClass()
	{}
	~FChipData_ForTable() {}

public:
	int					iID;
	const TCHAR*		sName;
	const TCHAR*		sDescription;

	int					iDamage;
	EATTRIBUTE			eAttribute;
	array<ECHIP_CODE,5>	arrAppearingCode;

	ECHIP_RARITY		eRarity;
	ECHIP_CLASS			eClass;
};

// 배틀용 칩데이터, 경량화 되어 있다.
class FChipData_ForBattle final
{
public:
	FChipData_ForBattle()
		: iID(), iDamage(), eAttribute(), eCode()
	{}
	~FChipData_ForBattle() {}

public:
	// 데이터 테이블에서 이름과 설명을 불러오기 위한 수단
	int						iID;
	// 칩의 대미지
	int						iDamage;
	// 칩의 속성
	EATTRIBUTE				eAttribute;
	// PA, 칩 조합에 사용됨
	ECHIP_CODE				eCode;
};

class FChipData_ForFolder final
{
public:
	FChipData_ForFolder()
		: iID(), sName(), sDescription(), iDamage(), eAttribute(), eCode(), iCapacity()
	{}
	~FChipData_ForFolder() {}
public:
	int						iID;			// 데이터 테이블에서 칩의 데이터를 불러오기 위한 수단
	const TCHAR*			sName;			// 이름정보에 대한 포인터
	const TCHAR*			sDescription;	// 설명에 대한 포인터
	int						iDamage;		// 칩의 대미지
	EATTRIBUTE				eAttribute;		// 칩의 속성
	ECHIP_CODE				eCode;			// PA, 칩 조합에 사용됨
	int						iCapacity;		// 칩의 용량
};

class FChipData_ForPack final
{
public:
	FChipData_ForPack()
		: iID(), sName(), sDescription(), iDamage(), eAttribute(), eCode(), iCapacity(), iQuantity()
	{}
	~FChipData_ForPack() {}
public:
	int						iID;			// 데이터 테이블에서 칩의 데이터를 불러오기 위한 수단
	const TCHAR*			sName;			// 이름정보에 대한 포인터
	const TCHAR*			sDescription;	// 설명에 대한 포인터
	int						iDamage;		// 칩의 대미지
	EATTRIBUTE				eAttribute;		// 칩의 속성
	ECHIP_CODE				eCode;			// PA, 칩 조합에 사용됨
	int						iCapacity;		// 칩의 용량
	int						iQuantity;		// 해당 칩과 코드에 대한 소지 개수
};