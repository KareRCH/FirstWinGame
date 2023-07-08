#pragma once

#include "Define.h"

class CSoundMgr
{
public:
	static CSoundMgr* Get_Instance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new CSoundMgr; 

		return m_pInstance; 
	}
	static void Destroy_Instance()
	{
		if (m_pInstance)
		{
			delete m_pInstance; 
			m_pInstance = nullptr; 
		}
	}

private:
	CSoundMgr();
	~CSoundMgr();

public:
	void Initialize(); 
	void Release(); 

public:
	void Play_Sound(TCHAR* pSoundKey, CHANNELID eID, float fVolume);
	void Play_BGM(TCHAR* pSoundKey, float fVolume);
	void Stop_Sound(CHANNELID eID);
	void StopAll();
	void SetChannelVolume(CHANNELID eID, float fVolume);

private:
	void LoadSoundFile(const char* pPath);

private:
	static CSoundMgr* m_pInstance; 

	// ���� ���ҽ� ������ ���� ��ü 
	map<TCHAR*, FMOD_SOUND*> m_mapSound; 
	
	// FMOD_CHANNEL : ����ϰ� �ִ� ���带 ������ ��ü 
	FMOD_CHANNEL* m_pChannelArr[MAXCHANNEL]; 

	// ���� ,ä�� ��ü �� ��ġ�� �����ϴ� ��ü 
	FMOD_SYSTEM* m_pSystem; 

	FMOD_CHANNELGROUP* m_pChannelGroup[MAX_CHANNEL_GROUP];
	FMOD_CHANNELGROUP* m_pMasterChanelGroup;

	
};

