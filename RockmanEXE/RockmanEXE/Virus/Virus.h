#pragma once

#include "Character/Character_NetBattle.h"
#include "ObjMgr.h"
#include "Manager/BattleMng.h"

/*
* 적 종류중 바이러스 캐릭터에 대한 속성 정의 클래스입니다.
*/

class CVirus abstract : public CCharacter_NetBattle
{
public:
	// 바이러스의 버전
	enum class VERSION { V1, V2, V3, EX };
public:
	CVirus() {}
	CVirus(const CVirus& _rhs) = delete;
	virtual ~CVirus() { CBattleMng::Get_Instance()->Enemy_Deleted(this); }

	// CCharacter_NetBattle을(를) 통해 상속됨
	virtual int Update(float fDeltaTime) override;
	virtual void Late_Update(float fDeltaTime) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	virtual void Collide(CObj* _pDst) override;


public:
	// 내비 클래스의 기초적인 초기화
	void Initialize_Virus()
	{
		CCharacter_NetBattle::Initialize_Gravity();
		CObjMgr::Get_Instance()->Add_Object(UNIT, this);
	}
};


/*
* 배틀 바이러스 데이터 전송용
*/
class CVirus_Transfer final
{
public:
	CVirus_Transfer() : sVirus_Tag(L""), arrItem_Tag(array<wstring, 6>()) {}
	~CVirus_Transfer() {}

public:
	wstring				sVirus_Tag = L"";					// 바이러스 태그 정보
	array<wstring, 6>	arrItem_Tag;			// 획득 아이템 태그 정보
};