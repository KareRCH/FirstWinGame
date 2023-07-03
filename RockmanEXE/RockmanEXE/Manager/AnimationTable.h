#pragma once

#include "Define.h"

class FAnimData final
{
public:
	FAnimData() {}
	~FAnimData() {}

public:
	// ��� ����, �ִ� �ִϸ��̼� ��
	int iMotion;
	int	iMotionSize;

	// ��Ʈ�� �����Ӻ� ������
	int	iFrameWidth;
	int iFrameHeight;

	// ����
	int iOffsetX;
	int iOffsetY;

	// �ʴ� �ӵ�
	float fSpeed;

public:
	ULONGLONG Get_Speed_ForFrame()
	{
		return static_cast<ULONGLONG>(round((1.f - fSpeed) * 1000.f / 65.f));
	}

	void Parse_Frame(FRAME& tFrame)
	{
		tFrame.iMotion = iMotion;
		tFrame.iFrameEnd = iMotionSize;
		tFrame.iFrameStart = 0;
		tFrame.ulSpeed = Get_Speed_ForFrame();
		tFrame.ulTime = GetTickCount64();
		
		tFrame.iOffsetX = iOffsetX;
		tFrame.iOffsetY = iOffsetY;

		tFrame.iFrameWidth = iFrameWidth;
		tFrame.iFrameHeight = iFrameHeight;
	}
};

class CAnimationTable final
{
private:
	CAnimationTable() {}
	~CAnimationTable() {}
	CAnimationTable(const CAnimationTable& _rhs) = delete;

private:
	void Initialize();
	void Release();

private:
	static CAnimationTable* g_pInstance;

public:
	static CAnimationTable* Get_Instance()
	{
		if (!g_pInstance)
		{
			g_pInstance = new CAnimationTable;
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

private:
	// 2���� ��, ��Ʈ�� ã��, �ִϸ��̼��� �̸����� �������� ������ ã�´�.
	map<const TCHAR*, map<const TCHAR*, FAnimData>> m_mapTable;

	void Create_Animation(const TCHAR* sName, const TCHAR* sAnimName,	
		int iMotion, int iMotionSize, 
		int iFrameWidth, int iFrameHeight,
		int iOffsetX, int iOffsetY, float fSpeed)
	{
		FAnimData pNewData = FAnimData();

		pNewData.iMotion = iMotion;
		pNewData.iMotionSize = iMotionSize;

		pNewData.iFrameWidth = iFrameWidth;
		pNewData.iFrameHeight = iFrameHeight;

		pNewData.iOffsetX = iOffsetX;
		pNewData.iOffsetY = iOffsetY;
		pNewData.fSpeed = fSpeed;

		if (m_mapTable.find(sName) == m_mapTable.end())
			m_mapTable.emplace(sName, map<const TCHAR*, FAnimData>());

		auto& mapAnim = m_mapTable[sName];
		mapAnim.emplace(sAnimName, pNewData);
	}

public:
	FAnimData Get_AnimData(const TCHAR* sName, const TCHAR* sAnimName)
	{
		if (m_mapTable.empty())
			return FAnimData();

		// �ִϸ��̼� ī�װ��� ���� ��
		auto iter = m_mapTable.find(sName);
		if (iter != m_mapTable.end())
		{
			auto& mapAnim = (*iter).second;
			auto iterAnim = mapAnim.find(sAnimName);

			// �ִϸ��̼��� ���� ��
			if (iterAnim != mapAnim.end())
			{
				auto& AnimData = (*iterAnim).second;
				return AnimData;
			}
		}

		return FAnimData();
	}

	FAnimData Load_AnimData(const TCHAR* sAnimName, pair<const TCHAR*, FRAME>& pairFrame)
	{
		if (m_mapTable.empty())
			return FAnimData();

		// �ִϸ��̼� ī�װ��� ���� ��
		auto iter = m_mapTable.find(pairFrame.first);
		if (iter != m_mapTable.end())
		{
			auto& mapAnim = (*iter).second;
			auto iterAnim = mapAnim.find(sAnimName);

			// �ִϸ��̼��� ���� ��
			if (iterAnim != mapAnim.end())
			{
				auto& AnimData = (*iterAnim).second;
				auto& tFrameData = pairFrame.second;

				// Frame ����ü�� ���� ��ȯ�۾�
				AnimData.Parse_Frame(tFrameData);
				
				return AnimData;
			}
		}

		return FAnimData();
	}
};

