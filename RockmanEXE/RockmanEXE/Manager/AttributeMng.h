#pragma once

#include "Define.h"
#include "Data/ChipData.h"

/*
* static 함수 로드 전용 클래스 입니다.
*/

enum class EATTRIBUTE_COMPATIBILITY_VALUE
{
	// 이건 잘 안쓰임
	NONE, 
	// 약함
	WEAK, 
	// 강함
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
	// 공격시 속성에 대한 피격체의 상성을 저장한다. 
	// 상성관계 외에도 속성 체크를 하지 않는 객체에 대해 공격 타입을 체크할 때 쓰인다.
	static map<EATTRIBUTE, pair<EATTRIBUTE, ECOMPATIBILITY>> g_Attribute_Attack_Map;
	// 피격체에 대한 공상성을 저장한다. 주로 공격을 받을 때 쓰인다.
	static map<EATTRIBUTE, pair<EATTRIBUTE, ECOMPATIBILITY>> g_Attribute_Body_Map;

public:
	static void Initialize()
	{
		if (g_bInitialized)
			return;

		// 너무길어 ㅋ
		auto& rAttackMap = g_Attribute_Attack_Map;
		auto& rBodyMap = g_Attribute_Body_Map;

		// 공격에 대한 설정
		Emplace_AttributeMap(rAttackMap, EATTRIBUTE::FIRE, EATTRIBUTE::WOOD, ECOMPATIBILITY::STRONG);
		Emplace_AttributeMap(rAttackMap, EATTRIBUTE::AQUA, EATTRIBUTE::FIRE, ECOMPATIBILITY::STRONG);
		Emplace_AttributeMap(rAttackMap, EATTRIBUTE::ELEC, EATTRIBUTE::AQUA, ECOMPATIBILITY::STRONG);
		Emplace_AttributeMap(rAttackMap, EATTRIBUTE::WOOD, EATTRIBUTE::ELEC, ECOMPATIBILITY::STRONG);

		Emplace_AttributeMap(rAttackMap, EATTRIBUTE::WIND, EATTRIBUTE::CURSOR, ECOMPATIBILITY::STRONG);
		Emplace_AttributeMap(rAttackMap, EATTRIBUTE::SWORD, EATTRIBUTE::WIND, ECOMPATIBILITY::STRONG);
		Emplace_AttributeMap(rAttackMap, EATTRIBUTE::BREAKING, EATTRIBUTE::SWORD, ECOMPATIBILITY::STRONG);
		Emplace_AttributeMap(rAttackMap, EATTRIBUTE::CURSOR, EATTRIBUTE::BREAKING, ECOMPATIBILITY::STRONG);

		// 방어에 대한 설정
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

	// 두 상성 확인하기, 보통 공격기반으로 확인
	static const EATTRIBUTE_CPT Check_Compatibility(EATTRIBUTE _eDst, EATTRIBUTE _eSrc)
	{
		auto& rAttackMap = g_Attribute_Attack_Map;

		auto iter = rAttackMap.find(_eSrc);

		// 찾았을 때 속성에 대한 상성을 확인한다.
		if (iter != rAttackMap.end())
		{
			auto& rPair = (*iter).second;
			if (rPair.first == _eDst)
				return rPair.second;
		}
		
		return ECOMPATIBILITY::NONE;
	}
};

