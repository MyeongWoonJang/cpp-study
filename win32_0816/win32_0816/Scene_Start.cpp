#include "pch.h"
#include "Scene_Start.h"

#include "CObject.h"

#include "CPlayer.h"
#include "CMonster.h"

#include "CCore.h"

#include "CPathMgr.h"
#include "CTexture.h"

#include "CCollisionMgr.h"

#include "CResMgr.h"
#include "CKeyMgr.h"
#include "CSceneMgr.h"
#include "CCamera.h"

#include "AI.h"
#include "CIdleState.h"
#include "CTraceState.h"
#include "CRigidBody.h"
#include "SelectGDI.h"
#include "CTimeMgr.h"
#include "CGround.h"
#include "CBackGround.h"

Scene_Start::Scene_Start()
	: m_bUseForce(false)
	, m_fForceRadius(500.f)
	, m_fCurRadius(0.f)
	, m_fForce(500.f)
{
}

Scene_Start::~Scene_Start()
{
}

void Scene_Start::update()
{
	if (KEY_HOLD(KEY::LBTN))
	{
		m_bUseForce = true;
		CreateForce();
	}
	else
	{
		m_bUseForce = false;
	}

	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
	{
		const vector<CObject*>& vecObj = GetGroupObject((GROUP_TYPE)i);

		for (size_t j = 0; j < vecObj.size(); ++j)
		{
			if (!vecObj[j]->IsDead())
			{
				if (m_bUseForce && vecObj[j]->GetRigidBody())
				{					
					Vec2 vDiff = vecObj[j]->GetPos() - m_vForcePos;
					float fLen = vDiff.Length();
					if (fLen < m_fForceRadius)
					{
						float fRatio = 1.f - (fLen / m_fForceRadius);
						float fForce = m_fForce* fRatio;

						vecObj[j]->GetRigidBody()->AddForce(vDiff.Normalize() * fForce);
					}
				}

				vecObj[j]->update();
			}
		}

	}



	/*if (KEY_TAP(KEY::ENTER))
	{
		ChangeScene(SCENE_TYPE::TOOL);
	}*/

	/*if (KEY_TAP(KEY::LBTN))
	{
		Vec2 LookAt = CCamera::GetInst()->GetRealPos(MOUSE_POS);
		CCamera::GetInst()->SetLookAt(LookAt);
	}*/

}

void Scene_Start::render(HDC _dc)
{
	CScene::render(_dc);

	if (!m_bUseForce)
		return;

	SelectGDI gdi(_dc, BRUSH_TYPE::HOLLOW);
	SelectGDI gdi2(_dc, PEN_TYPE::GREEN);

	m_fCurRadius += m_fForceRadius * 3.f * fDT;
	if (m_fCurRadius > m_fForceRadius)
	{
		m_fCurRadius = 0.f;
	}

	Vec2 vRenderPos = CCamera::GetInst()->GetRenderPos(m_vForcePos);

	Ellipse(_dc
		, (int)(vRenderPos.x - m_fCurRadius)
		, (int)(vRenderPos.y - m_fCurRadius)
		, (int)(vRenderPos.x + m_fCurRadius)
		, (int)(vRenderPos.y + m_fCurRadius));
}

void Scene_Start::Enter()
{
	// ���
	CreateBackGround();

	// Object �߰� 
	CObject* pObj = new CPlayer;
	pObj->SetName(L"Player");
	pObj->SetPos(Vec2(640.f, 384.f));
	pObj->SetScale(Vec2(100.f, 100.f));
	AddObject(pObj, GROUP_TYPE::PLAYER);

	RegisterPlayer(pObj);
	
	//CCamera::GetInst()->SetTarget(pObj);

	/*CObject* pOtherPlayer = pObj->Clone();
	pOtherPlayer->SetPos(Vec2(740.f, 384.f));
	AddObject(pOtherPlayer, GROUP_TYPE::PLAYER);*/

	// Monster Object �߰�
	Vec2 vResolution = CCore::GetInst()->GetResolution();
	CMonster* pMon = CMonFactory::CreateMonster(MON_TYPE::NORMAL, vResolution / 2.f - Vec2(0.f, 300.f));
	AddObject(pMon, GROUP_TYPE::MONSTER);

	// �� ��ü ��ġ
	CObject* pGround = new CGround;
	pGround->SetPos(Vec2(640.f, 584.f));
	pGround->SetScale(Vec2(200.f, 60.f));
	AddObject(pGround, GROUP_TYPE::GROUND);

	// Ÿ�� �ε�
	// LoadTile(L"tile\\Start.tile");

	// �浹 ����
	// Player �׷�� Monster �׷� ���� �浹üũ
	CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::MONSTER);
	CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::MONSTER, GROUP_TYPE::PROJ_PLAYER);
	CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::GROUND);


	// Camera
	CCamera::GetInst()->SetLookAt(vResolution / 2.f);

	// Camera ȿ�� ����
	CCamera::GetInst()->FadeOut(1.5f);
	CCamera::GetInst()->FadeIn(1.5f);

	start();
}

void Scene_Start::Exit() 
{
	DeleteAll();

	CCollisionMgr::GetInst()->Reset();
}

void Scene_Start::CreateForce()
{
	m_vForcePos = CCamera::GetInst()->GetRealPos(MOUSE_POS);
}

void Scene_Start::CreateBackGround()
{
	CObject* pBackGround = new CBackGround;
	CTexture* pTileTex = CResMgr::GetInst()->LoadTexture(L"Tile", L"texture\\background.bmp");


	AddObject(pBackGround, GROUP_TYPE::BACK_GROUND);
}

