#include "pch.h"
#include "CScene_Enter.h"
#include "CBackGround.h"

#include "CCamera.h"
#include "CCore.h"
#include "CResMgr.h"
#include "CKeyMgr.h"

CScene_Enter::CScene_Enter()
{
}

CScene_Enter::~CScene_Enter()
{
}

void CScene_Enter::update()
{
	if (KEY_TAP(KEY::ENTER))
	{
		ChangeScene(SCENE_TYPE::START);
	}
}

void CScene_Enter::render(HDC _dc)
{

}

void CScene_Enter::Enter()
{
	// 배경 오브젝트
	CBackGround* pBackGround = new CBackGround;
	CTexture* pTex = CResMgr::GetInst()->LoadTexture(L"Enter_BackGround", L"texture\\enterScene.bmp");
	pBackGround->SetTexture(pTex);

	AddObject(pBackGround, GROUP_TYPE::BACK_GROUND);

	// Camera
	Vec2 vResolution = CCore::GetInst()->GetResolution();
	CCamera::GetInst()->SetLookAt(vResolution / 2.f);
}

void CScene_Enter::Exit()
{
	DeleteAll();
}

