#include "pch.h"
#include "CMonster.h"

#include "CSceneMgr.h"
#include "CScene.h"

#include "AI.h"

#include "CTimeMgr.h"

#include "CTexture.h"
#include "CResMgr.h"
#include "CCollider.h"

CMonster::CMonster()
	: m_tInfo{}
	, m_pTex(nullptr)
	, m_pAI(nullptr)
{
	// Texture 로딩하기
	// m_pTex = CResMgr::GetInst()->LoadTexture(L"Monster", L"texture\\Monster.bmp");

	CreateCollider();
	GetCollider()->SetScale(Vec2(40.f, 40.f));
}

CMonster::~CMonster()
{
	if (nullptr != m_pAI)
		delete m_pAI;
}

void CMonster::update()
{
	if(nullptr != m_pAI)
		m_pAI->update();
}

//void CMonster::render(HDC _dc)
//{
//	int iWidth = (int)m_pTex->Width();
//	int iHeight = (int)m_pTex->Heigth();
//
//	Vec2 vPos = GetPos();
//
//	TransparentBlt(_dc
//		, int(vPos.x - (float)(iWidth / 2))
//		, int(vPos.y - (float)(iHeight / 2))
//		, iWidth, iHeight
//		, m_pTex->GetDC()
//		, 0, 0, iWidth, iHeight
//		, RGB(120, 182, 255));
//
//	component_render(_dc);
//}

void CMonster::SetAI(AI* _AI)
{
	m_pAI = _AI;
	m_pAI->m_pOwner = this;
}

void CMonster::OnCollisionEnter(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();

	if (pOtherObj->GetName() == L"Missile_Player") 
	{

	}
}