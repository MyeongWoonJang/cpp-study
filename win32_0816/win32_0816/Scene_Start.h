#pragma once
#include "CScene.h"
class Scene_Start :
    public CScene
{
private:
    Vec2    m_vForcePos;
    float   m_fForceRadius;
    float   m_fCurRadius;
    float   m_fForce;
    bool    m_bUseForce;

public:
    virtual void update();
    virtual void render(HDC _dc);

    virtual void Enter();
    virtual void Exit();

public:
    void CreateForce();
    void CreateBackGround();

public:
    Scene_Start();
    ~Scene_Start();
};

