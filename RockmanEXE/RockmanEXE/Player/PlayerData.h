#pragma once

/*
* �÷��̾� ������ Ŭ������ �������� �÷��̾��� �����͸� �����ϴ� Ŭ�����Դϴ�.
* Ĩ ����, ���� �� ��ġ�� ���� ���� �����鼭 ����� �� �ֵ��� �����͸� �׾ƵӴϴ�.
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

private: // �κ��丮
	// [Ĩ ����]
	// [Ĩ �κ��丮]
};

