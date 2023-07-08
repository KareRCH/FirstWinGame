#include "ITeamAgent.h"

ULONGLONG ITeamAgent::ID_COUNT = 0;
map<BYTE, ERELATION_STATE>	ITeamAgent::m_mapTeamRelation = map<BYTE, ERELATION_STATE>();