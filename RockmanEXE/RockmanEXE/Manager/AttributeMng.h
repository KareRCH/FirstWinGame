#pragma once

#include "Define.h"
#include "Data/ChipData.h"

/*
* static �Լ� �ε� ���� Ŭ���� �Դϴ�.
*/

enum class EATTRIBUTE_COMPATIBILITY_VALUE
{
	// �̰� �� �Ⱦ���
	NONE, 
	// ����
	WEAK, 
	// ����
	STRONG
};

using EATTRIBUTE_CPT = EATTRIBUTE_COMPATIBILITY_VALUE;

class CAttributeMng
{
	using ECOMPATIBILITY = EATTRIBUTE_COMPATIBILITY_VALUE;
private:
	CAttributeMng() = delete;
	~CAttributeMng() = delete;
	CAttributeMng(const CAttributeMng& _rhs) = delete;

private:
	static bool g_bInitialized;
	// ���ݽ� �Ӽ��� ���� �ǰ�ü�� ���� �����Ѵ�. 
	// �󼺰��� �ܿ��� �Ӽ� üũ�� ���� �ʴ� ��ü�� ���� ���� Ÿ���� üũ�� �� ���δ�.
	static map<EATTRIBUTE, pair<EATTRIBUTE, ECOMPATIBILITY>> g_Attribute_Attack_Map;
	// �ǰ�ü�� ���� ������ �����Ѵ�. �ַ� ������ ���� �� ���δ�.
	static map<EATTRIBUTE, pair<EATTRIBUTE, ECOMPATIBILITY>> g_Attribute_Body_Map;

public:
	static void Initialize()
	{
		if (g_bInitialized)
			return;

		// �ʹ���� ��
		auto& rAttackMap = g_Attribute_Attack_Map;
		auto& rBodyMap = g_Attribute_Body_Map;

		// ���ݿ� ���� ����
		Emplace_AttributeMap(rAttackMap, EATTRIBUTE::FIRE, EATTRIBUTE::WOOD, ECOMPATIBILITY::STRONG);
		Emplace_AttributeMap(rAttackMap, EATTRIBUTE::AQUA, EATTRIBUTE::FIRE, ECOMPATIBILITY::STRONG);
		Emplace_AttributeMap(rAttackMap, EATTRIBUTE::ELEC, EATTRIBUTE::AQUA, ECOMPATIBILITY::STRONG);
		Emplace_AttributeMap(rAttackMap, EATTRIBUTE::WOOD, EATTRIBUTE::ELEC, ECOMPATIBILITY::STRONG);

		Emplace_AttributeMap(rAttackMap, EATTRIBUTE::WIND, EATTRIBUTE::CURSOR, ECOMPATIBILITY::STRONG);
		Emplace_AttributeMap(rAttackMap, EATTRIBUTE::SWORD, EATTRIBUTE::WIND, ECOMPATIBILITY::STRONG);
		Emplace_AttributeMap(rAttackMap, EATTRIBUTE::BREAKING, EATTRIBUTE::SWORD, ECOMPATIBILITY::STRONG);
		Emplace_AttributeMap(rAttackMap, EATTRIBUTE::CURSOR, EATTRIBUTE::BREAKING, ECOMPATIBILITY::STRONG);

		// �� ���� ����
		Emplace_AttributeMap(rBodyMap, EATTRIBUTE::FIRE, EATTRIBUTE::AQUA, ECOMPATIBILITY::WEAK);
		Emplace_AttributeMap(rBodyMap, EATTRIBUTE::AQUA, EATTRIBUTE::ELEC, ECOMPATIBILITY::WEAK);
		Emplace_AttributeMap(rBodyMap, EATTRIBUTE::ELEC, EATTRIBUTE::WOOD, ECOMPATIBILITY::WEAK);
		Emplace_AttributeMap(rBodyMap, EATTRIBUTE::WOOD, EATTRIBUTE::FIRE, ECOMPATIBILITY::WEAK);

		Emplace_AttributeMap(rBodyMap, EATTRIBUTE::WIND, EATTRIBUTE::SWORD, ECOMPATIBILITY::WEAK);
		Emplace_AttributeMap(rBodyMap, EATTRIBUTE::SWORD, EATTRIBUTE::BREAKING, ECOMPATIBILITY::WEAK);
		Emplace_AttributeMap(rBodyMap, EATTRIBUTE::BREAKING, EATTRIBUTE::CURSOR, ECOMPATIBILITY::WEAK);
		Emplace_AttributeMap(rBodyMap, EATTRIBUTE::CURSOR, EATTRIBUTE::WIND, ECOMPATIBILITY::WEAK);

		g_bInitialized = true;
	}

	static void Emplace_AttributeMap(map<EATTRIBUTE, pair<EATTRIBUTE, ECOMPATIBILITY>>& _rMap,
										EATTRIBUTE&& _Base, EATTRIBUTE&& _Target, ECOMPATIBILITY&& _Comp)
	{
		_rMap.emplace(_Base, pair< EATTRIBUTE, ECOMPATIBILITY>(_Target, _Comp));
	}

	// �� �� Ȯ���ϱ�, ���� ���ݱ������ Ȯ��
	static const EATTRIBUTE_CPT Check_Compatibility(EATTRIBUTE _eDst, EATTRIBUTE _eSrc)
	{
		auto& rAttackMap = g_Attribute_Attack_Map;

		auto iter = rAttackMap.find(_eSrc);

		// ã���� �� �Ӽ��� ���� ���� Ȯ���Ѵ�.
		if (iter != rAttackMap.end())
		{
			auto& rPair = (*iter).second;
			if (rPair.first == _eDst)
				return rPair.second;
		}
		
		return ECOMPATIBILITY::NONE;
	}
};

