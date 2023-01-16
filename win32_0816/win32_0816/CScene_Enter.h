#pragma once
#include "CScene.h"

class CScene_Enter
    : public CScene
{
public:
    virtual void update();
    virtual void render(HDC _dc);

    virtual void Enter();
    virtual void Exit();

public:
	CScene_Enter();
	~CScene_Enter();
};

