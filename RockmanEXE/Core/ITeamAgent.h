#pragma once

#include "Define.h"

/*
* ���� �ĺ��� �� �ְ� �����ϴ� �������̽�
* �������̽������� �ظ��� �͵��� ������ �س��� ����.
*/

class ITeamAgent abstract
{
private:
	static ULONGLONG ID_COUNT;						// ���� ID ������

public:
	static const BYTE TEAM_END = (BYTE)255U;		// ������ �� ID

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
	BYTE						m_bTeamID = (BYTE)0U;		// �ڽ��� ��ID
	map<BYTE, ERELATION>		m_iTeamRelation_Map;		// ���� ����

	ULONGLONG					m_ulPrivID;					// �ڽ��� ID
	map<ULONGLONG, ERELATION>	m_iPrivRelation_Map;		// ���� ����, �켱�� ����

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