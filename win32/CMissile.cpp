#include "pch.h"
#include "CMissile.h"

#include "CTimeMgr.h"
#include "CCollider.h"

#include "CTexture.h"
#include "CResMgr.h"

CMissile::CMissile()
	: m_fTheta(PI / 4.f)
	, m_vDir(Vec2(1.f, 1.f))
	, m_pTex(nullptr)
{
	m_vDir.Normalize();

	// Texture 로딩하기
	m_pTex = CResMgr::GetInst()->LoadTexture(L"PlayerMissileTex", L"texture\\Player_Missile.bmp");

	CreateCollider();
	GetCollider()->SetScale(Vec2(15.f, 25.f));
	//GetCollider()->SetOffsetPos(Vec2(0.f, -5.f));
}

CMissile::~CMissile()
{
}

void CMissile::update()
{
	Vec2 vPos = GetPos();

	/*vPos.x += 600.f * cosf(m_fTheta) * fDT;
	vPos.y -= 600.f * sinf(m_fTheta) * fDT;*/

	vPos.x += 600.f * m_vDir.x * fDT;
	vPos.y += 600.f * m_vDir.y * fDT;

	SetPos(vPos);
}

void CMissile::render(HDC _dc)
{
	/*Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	Ellipse(_dc, (int)(vPos.x - vScale.x / 2.f), (int)(vPos.y - vScale.y / 2.f)
		, (int)(vPos.x + vScale.x / 2.f), (int)(vPos.y + vScale.y / 2.f));*/
	int iWidth = (int)m_pTex->Width();
	int iHeight = (int)m_pTex->Heigth();

	Vec2 vPos = GetPos();

	TransparentBlt(_dc
		, int(vPos.x - (float)(iWidth / 2))
		, int(vPos.y - (float)(iHeight / 2))
		, iWidth, iHeight
		, m_pTex->GetDC()
		, 0, 0, iWidth, iHeight
		, RGB(47, 95, 115));

	component_render(_dc);
}

void CMissile::OnCollisionEnter(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();

	if (pOtherObj->GetName() == L"Monster")
	{
		DeleteObject(this);
	}
}
