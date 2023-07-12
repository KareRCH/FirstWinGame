#pragma once

#include "Define.h"

/*
* Ĩ�� ���� ������ ����ϱ� ���� ��ü�� ����� ����Դϴ�.
* F�� ����ü ó�� ���� Ŭ������� ��.
* �𸮾� ü�迡�� ����
* �밡���� ǥ����� ����ü�� ���� �����ϴ�.
*/

enum class EATTRIBUTE : int
{
	// ���Ӽ�
	NONE, 
	// �Ӽ�(�� ���� ����)
	FIRE, AQUA, ELEC, WOOD,
	// ����(��ƿ��)
	CRACKING, RECOVERY, INVISIBLE, PLUS, OBSTACLE, 
	// ����(�� ���� ����)
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

// ���̺� ���� ������ Ŭ����
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

// ��Ʋ�� Ĩ������, �淮ȭ �Ǿ� �ִ�.
class FChipData_ForBattle final
{
public:
	FChipData_ForBattle()
		: iID(), iDamage(), eAttribute(), eCode()
	{}
	~FChipData_ForBattle() {}

public:
	// ������ ���̺��� �̸��� ������ �ҷ����� ���� ����
	int						iID;
	// Ĩ�� �����
	int						iDamage;
	// Ĩ�� �Ӽ�
	EATTRIBUTE				eAttribute;
	// PA, Ĩ ���տ� ����
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
	int						iID;			// ������ ���̺��� Ĩ�� �����͸� �ҷ����� ���� ����
	const TCHAR*			sName;			// �̸������� ���� ������
	const TCHAR*			sDescription;	// ���� ���� ������
	int						iDamage;		// Ĩ�� �����
	EATTRIBUTE				eAttribute;		// Ĩ�� �Ӽ�
	ECHIP_CODE				eCode;			// PA, Ĩ ���տ� ����
	int						iCapacity;		// Ĩ�� �뷮
};

class FChipData_ForPack final
{
public:
	FChipData_ForPack()
		: iID(), sName(), sDescription(), iDamage(), eAttribute(), eCode(), iCapacity(), iQuantity()
	{}
	~FChipData_ForPack() {}
public:
	int						iID;			// ������ ���̺��� Ĩ�� �����͸� �ҷ����� ���� ����
	const TCHAR*			sName;			// �̸������� ���� ������
	const TCHAR*			sDescription;	// ���� ���� ������
	int						iDamage;		// Ĩ�� �����
	EATTRIBUTE				eAttribute;		// Ĩ�� �Ӽ�
	ECHIP_CODE				eCode;			// PA, Ĩ ���տ� ����
	int						iCapacity;		// Ĩ�� �뷮
	int						iQuantity;		// �ش� Ĩ�� �ڵ忡 ���� ���� ����
};