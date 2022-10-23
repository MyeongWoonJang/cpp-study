#pragma once

class CObject;
class CAnimation;
class CTexture;

class CAnimator
{
private:
	map<wstring, CAnimation*>	m_mapAnim;		// ��� Animation
	CAnimation*					m_pCurAnim;		// ���� ������� Animation
	CObject*					m_pOwner;		// Animation ���� ������Ʈ
	bool						m_bRepeat;		// �ݺ���� ����

public:
	CObject* GetObj() { return m_pOwner; }

public:
	void CreateAnimation(const wstring& _strName, CTexture* m_pTex, Vec2 _vLT, Vec2 _vSliceSize, Vec2 _vStep, float _fDuration, UINT _iFrameCount);
	CAnimation* FindAnimation(const wstring& _strName);
	void Play(const wstring _strName, bool _bRepeat);

	void update();
	void finalupdate();
	void render(HDC _dc);
	 
public:
	CAnimator();
	~CAnimator();

	friend class CObject;
};
