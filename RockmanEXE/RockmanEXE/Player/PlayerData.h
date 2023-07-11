#pragma once

/*
* 플레이어 데이터 클래스는 전역적인 플레이어의 데이터를 저장하는 클래스입니다.
* 칩 폴더, 월드 맵 위치와 같이 씬을 오가면서 사용할 수 있도록 데이터를 쌓아둡니다.
*/

class CPlayerData final
{
private:
	CPlayerData() {}
	~CPlayerData() {}
	CPlayerData(const CPlayerData& _rhs) = delete;

private:
	void Initialize() {}
	void Release() {}

private:
	static CPlayerData* g_pInstance;

public:
	static CPlayerData* Get_Instance()
	{
		if (!g_pInstance)
		{
			g_pInstance = new CPlayerData;
			g_pInstance->Initialize();
		}

		return g_pInstance;
	}
	static void		Destroy_Instance()
	{
		if (g_pInstance)
		{
			g_pInstance->Release();
			delete g_pInstance;
			g_pInstance = nullptr;
		}
	}

private: // 인벤토리
	// [칩 폴더]
	// [칩 인벤토리]
};

