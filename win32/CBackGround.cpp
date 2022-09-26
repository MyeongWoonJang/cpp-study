#include "pch.h"
#include "CBackGround.h"

#include "CResMgr.h"
#include "CTexture.h"

CBackGround::CBackGround()
	: m_pBackgroundTex(nullptr)
{
	CTexture* pTileTex = CResMgr::GetInst()->LoadTexture(L"BackGround", L"texture\\Tile.bmp");
}

CBackGround::~CBackGround()
{
}

void CBackGround::update()
{
}

void CBackGround::render(HDC _dc)
{
	BitBlt(_dc
		, 0, 0
		, 1920, 663
		, m_pBackgroundTex->GetDC()
		, 1920, 663
		, SRCCOPY);
}
