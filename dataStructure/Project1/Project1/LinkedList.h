#pragma once

#include <assert.h>

template <typename T>
class CListNode
{
	template <typename T>
	friend class CLinkedList;

private:
	CListNode()
	{
		m_pNext = nullptr;
		m_pPrev = nullptr;
	}

	~CListNode()
	{

	}

private:
	T				m_Data;			// ���� �����͸� ������ ����
	CListNode<T>*	m_pNext;		// ���� ����� �ּҸ� ������ ����
	CListNode<T>*	m_pPrev;		// ���� ����� �ּҸ� ������ ����
};

template <typename T>
class CLinkedList
{
public:
	CLinkedList()
	{
		m_pBegin = new NODE;
		m_pEnd = new NODE;

		m_pBegin->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = m_pBegin;

		m_iSize = 0;
	}

	~CLinkedList()
	{
		clear();
		delete m_pBegin;
		delete m_pEnd;
	}

private:
	typedef CListNode<T>	NODE;
	typedef CListNode<T>*	PNODE;

private:
	PNODE	m_pBegin;
	PNODE	m_pEnd;
	int		m_iSize;

public:
	void push_back(const T& data)
	{
		PNODE pNode = new NODE;
		pNode->m_Data = data;

		// �ڿ� �߰��� �ؾ� �ϹǸ� End�� ���� ��带 ���´�.
		PNODE pPrev = m_pEnd->m_pPrev;

		// ���� ���� ���� End��� ���̿� ���� ������ ��带
		// �߰��Ѵ�.
		pPrev->m_pNext = pNode;
		pNode->m_pPrev = pPrev;

		// End���� ���� ������ ��带 �����Ѵ�.
		pNode->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = pNode;

		++m_iSize;
	}

	void push_front(const T& data)
	{
		PNODE pNode = new NODE;
		pNode->m_Data = data;

		// Begin�� Begin�� ���� ��� ���̿� ���� ������ ��带
		// �߰��Ѵ�.
		PNODE pNext = m_pBegin->m_pNext;

		// ���� ������ ����� �������� Begin�� ���� ��带
		// �ش�. Begin�� ���� ����� �������� ����  ������
		// ��带 �ش�.
		pNode->m_pNext = pNext;
		pNext->m_pPrev = pNode;

		// Begin�� �������� ���� ������ ��带 �ش�.
		// ���� ������ ����� ���� ���� Begin�� �ش�.
		m_pBegin->m_pNext = pNode;
		pNode->m_Prev = m_pBegin;

		++m_iSize;
	}

	void pop_back()
	{
		if (empty())
			assert(false);

		// ���� ������ ��带 ������ �ϹǷ� End����� ���� ��带
		// ���´�.
		PNODE pDeleteNode = m_pEnd->m_pPrev;

		// ���� ����� ���� ��带 ���´�.
		PNODE pPrev = pDeleteNode->m_pPrev;

		// ��������� �������� End�� �ְ� End�� ��������
		// ������带 �ش�.
		pPrev->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = pPrev;

		// ��带 �����ش�.
		delete pDeleteNode;

		// ����� 1 ���� ��Ų��.
		--m_iSize;
	}

	void pop_front()
	{
		if (empty())
			assert(false);

		// ���� ��带 ���´�.
		PNODE pDeleteNode = m_pBegin->m_pNext;

		// ���� ����� ���� ��带 ������ �ش� ���� Begin ��带
		// �������ش�.
		PNODE pNext = pDeleteNode->m_pNext;

		pNext->m_pPrev = m_pBegin;
		m_pBegin->m_pNext = pNext;

		// ��带 �����ش�.
		delete pDeleteNode;

		// ����� 1 ���ҽ�Ų��.
		--m_iSize;
	}

	T front()const
	{
		if (empty())
			assert(false);

		return m_pBegin->m_pNext->m_Data;
	}

	T back()const
	{
		if (empty())
			assert(false);

		return m_pEnd->m_pPrev->m_Data;
	}

	// Begin�� End�� ������ ���� �߰��� ����� ���� �����
	// ������ش�.
	void clear()
	{
		PNODE pNode = m_pBegin->m_pNext;

		while (pNode != m_pEnd)
		{
			// ���� ����� ���� ��带 ���´�.
			PNODE pNext = pNode->m_pNext;

			// ���� ��带 �����ش�.
			delete pNode;

			// pNode�� ���� ����� �ּҸ� �־��ش�.
			pNode = pNext;
		}

		m_iSize = 0;

		// Begin�� End�� ���� �������ش�.
		m_pBegin->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = m_pBegin;
	}

	int size() const
	{
		return m_iSize;
	}

	// ����Ʈ�� ������� ��� true, �ƴ� ��� false�� ��ȯ�Ѵ�.
	bool empty() const
	{
		return m_iSize == 0;
	}


};