#pragma once

#include "Define.h"

/*
* 팀을 식별할 수 있게 지원하는 인터페이스
* 인터페이스이지만 왠만한 것들은 구현을 해놓고 쓴다.
*/

class ITeamAgent abstract
{
private:
	static ULONGLONG ID_COUNT;						// 고유 ID 제공용

public:
	static const BYTE TEAM_END = (BYTE)255U;		// 마지막 팀 ID

	enum class ERELATION
	{
		HOSTILE,
		NUETRAL,
		FRIEND
	};

public:
	ITeamAgent() : m_ulPrivID(InitID()) {}
	ITeamAgent(const ITeamAgent& _rhs) = delete;
	virtual ~ITeamAgent() {}
	
private:
	BYTE						m_bTeamID = (BYTE)0U;		// 자신의 팀ID
	map<BYTE, ERELATION>		m_iTeamRelation_Map;		// 팀별 관계

	ULONGLONG					m_ulPrivID;					// 자신의 ID
	map<ULONGLONG, ERELATION>	m_iPrivRelation_Map;		// 개별 관계, 우선도 높음

public:
	const BYTE& Get_TeamID() { return m_bTeamID; }
	void Set_TeamID(int value) { m_bTeamID = value; }

private:
	// 
	ULONGLONG InitID() { return ID_COUNT++; }

public:
};

ULONGLONG ITeamAgent::ID_COUNT = 0;

using ERELATION_STATE = ITeamAgent::ERELATION;