#include "pch.h"
#include "CPlayer.h"

#include "CSceneMgr.h"
#include "CScene.h"

#include "CKeyMgr.h"
#include "CTimeMgr.h"

#include "CMissile.h"

#include "CResMgr.h"
#include "CTexture.h"
#include "CCollider.h"
#include "CAnimator.h"
#include "CAnimation.h"
#include "CRigidBody.h"
#include "CGravity.h"

CPlayer::CPlayer()
	: m_eCurState(PLAYER_STATE::IDLE)
	, m_ePrevState(PLAYER_STATE::WALK)
	, m_iDir(1)
	, m_iPrevDir(1)
{
	// Texture 로딩하기
	// m_pTex = CResMgr::GetInst()->LoadTexture(L"PlayerTex", L"texture\\Player.bmp");

	CreateCollider();
	GetCollider()->SetOffsetPos(Vec2(8.f, 20.f));
	GetCollider()->SetScale(Vec2(25.f, 80.f));

	CreateRigidBody();

	// Texture 로딩하기	
	CTexture* pIdle_RightTex = CResMgr::GetInst()->LoadTexture(L"IDLE_RIGHT_TEX", L"texture\\Idle_R.bmp");
	CTexture* pIdle_LeftTex = CResMgr::GetInst()->LoadTexture(L"IDLE_LEFT_TEX", L"texture\\Idle_L.bmp");

	CTexture* pWalk_RightTex = CResMgr::GetInst()->LoadTexture(L"WALK_RIGHT_TEX", L"texture\\Walk_R.bmp");
	CTexture* pWalk_LeftTex = CResMgr::GetInst()->LoadTexture(L"WALK_LEFT_TEX", L"texture\\Walk_L.bmp");
	
	CTexture* pJump_RightTex = CResMgr::GetInst()->LoadTexture(L"JUMP_RIGHT_TEX", L"texture\\Jump_R.bmp");
	CTexture* pJump_LeftTex = CResMgr::GetInst()->LoadTexture(L"JUMP_LEFT_TEX", L"texture\\Jump_L.bmp");

	CreateAnimator();

	GetAnimator()->CreateAnimation(L"IDLE_RIGHT", pIdle_RightTex, Vec2(0.f, 0.f), Vec2(80.f, 120.f), Vec2(80.f, 0.f), 0.1f, 9);
	GetAnimator()->CreateAnimation(L"IDLE_LEFT", pIdle_LeftTex, Vec2(0.f, 0.f), Vec2(80.f, 120.f), Vec2(80.f, 0.f), 0.1f, 9);
	
	GetAnimator()->CreateAnimation(L"WALK_RIGHT", pWalk_RightTex, Vec2(0.f, 0.f), Vec2(80.f, 120.f), Vec2(80.f, 0.f), 0.1f, 8);
	GetAnimator()->CreateAnimation(L"WALK_LEFT", pWalk_LeftTex, Vec2(0.f, 0.f), Vec2(80.f, 120.f), Vec2(80.f, 0.f), 0.1f, 8);

	GetAnimator()->CreateAnimation(L"JUMP_RIGHT", pJump_RightTex, Vec2(0.f, 0.f), Vec2(90.f, 120.f), Vec2(90.f, 0.f), 0.1f, 12);
	GetAnimator()->CreateAnimation(L"JUMP_LEFT", pJump_LeftTex, Vec2(0.f, 0.f), Vec2(90.f, 120.f), Vec2(90.f, 0.f), 0.1f, 12);

	CreateGravity();

	/*CAnimation* pAnim = GetAnimator()->FindAnimation(L"WALK_DOWN");
	for (UINT i = 0; i < pAnim->GetMaxFrame(); ++i)
		pAnim->GetFrame(i).vOffset = Vec2(0.f, -20.f);*/


}

CPlayer::~CPlayer()
{
}


void CPlayer::update()
{
	update_move();

	update_state();

	update_animation();

	if (KEY_TAP(KEY::ENTER))
	{
		SetPos(Vec2(640.f, 384.f));
	}

	GetAnimator()->update();

	m_ePrevState = m_eCurState;
	m_iPrevDir = m_iDir;
}

void CPlayer::render(HDC _dc)
{
	// 컴포넌트(충돌체, etc...)가 있는 경우 렌더
	component_render(_dc);
}

void CPlayer::CreateMissile()
{
	Vec2 vMissilePos = GetPos();
	vMissilePos.y -= GetScale().y / 2.f;

	// Missile Object
	CMissile* pMissile = new CMissile;
	pMissile->SetName(L"Missile_Player");
	pMissile->SetPos(vMissilePos);
	pMissile->SetScale(Vec2(25.f, 25.f));
	pMissile->SetDir(Vec2(0.f, -1.f));

	CreateObject(pMissile, GROUP_TYPE::PROJ_PLAYER);

}

void CPlayer::update_state()
{
	if (KEY_TAP(KEY::A))
	{
		m_iDir = -1;
		m_eCurState = PLAYER_STATE::WALK;
	}

	if (KEY_TAP(KEY::D))
	{
		m_iDir = 1;
		m_eCurState = PLAYER_STATE::WALK;
	}

	if (0.f == GetRigidBody()->GetSpeed())
	{
		m_eCurState = PLAYER_STATE::IDLE;
	}

	if (KEY_TAP(KEY::SPACE))
	{
		m_eCurState = PLAYER_STATE::JUMP;

		if(GetRigidBody())
		{
			GetRigidBody()->AddVelocity(Vec2(0.f, -600.f));
		}
	}
}

void CPlayer::update_move()
{
	CRigidBody* pRigid = GetRigidBody();

	if (KEY_HOLD(KEY::A))
	{
		pRigid->AddForce(Vec2(-200.f, 0.f));
	}

	if (KEY_HOLD(KEY::D))
	{
		pRigid->AddForce(Vec2(200.f, 0.f));
	}

	if (KEY_TAP(KEY::A))
	{
		pRigid->AddVelocity(Vec2(-100.f, 0.f));
	}

	if (KEY_TAP(KEY::D))
	{
		pRigid->AddVelocity(Vec2(100.f, 0.f));
	}
}

void CPlayer::update_animation()
{
	if (m_ePrevState == m_eCurState && m_iPrevDir == m_iDir)
		return;

	switch (m_eCurState)
	{
	case PLAYER_STATE::IDLE:
	{
		if(m_iDir == -1)
			GetAnimator()->Play(L"IDLE_LEFT", true);
		else
			GetAnimator()->Play(L"IDLE_RIGHT", true);
	}
		break;
	case PLAYER_STATE::WALK:
	{
		if (m_iDir == -1)
			GetAnimator()->Play(L"WALK_LEFT", true);
		else
			GetAnimator()->Play(L"WALK_RIGHT", true);
	}
		break;
	case PLAYER_STATE::JUMP:
	{
		if (m_iDir == -1)
			GetAnimator()->Play(L"JUMP_LEFT", true);
		else
			GetAnimator()->Play(L"JUMP_RIGHT", true);
	}
		break;
	case PLAYER_STATE::ATTACK:

		break;
	case PLAYER_STATE::DEAD:

		break;
	}
}

void CPlayer::update_gravity()
{
	GetRigidBody()->AddForce(Vec2(0.f, 500.f));
}

