#pragma once
#include "CObject.h"

class CTexture;

class CBackGround :
    public CObject
{
private:
    CTexture* m_pBackgroundTex;

private:
    virtual void update();
    virtual void render(HDC _dc);

public:
    void SetTexture(CTexture* _pTex) { m_pBackgroundTex = _pTex; }

    CLONE(CBackGround);
public:
    CBackGround();
    ~CBackGround();
};


