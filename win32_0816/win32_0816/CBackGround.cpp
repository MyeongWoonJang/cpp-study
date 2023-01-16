#include "pch.h"
#include "CBackGround.h"

#include "CResMgr.h"
#include "CTexture.h"

CBackGround::CBackGround()
	: m_pBackgroundTex(nullptr)
{
	//m_pBackgroundTex = CResMgr::GetInst()->LoadTexture(L"BackGround", L"texture\\background.bmp");
}

CBackGround::~CBackGround()
{
}

void CBackGround::update()
{
}

void CBackGround::render(HDC _dc)
{
	// test
	// test

	int iWidth = (int)m_pBackgroundTex->Width();
	int iHeight = (int)m_pBackgroundTex->Heigth();
	
	BitBlt(_dc
		, 0
		, 0
		, iWidth
		, iHeight
		, m_pBackgroundTex->GetDC()
		, 0
		, 0
		, SRCCOPY);
}
