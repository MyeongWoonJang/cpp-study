#pragma once

#include <assert.h>

/*
Queue : ���Լ����� �ڷᱸ���̴�.
���� �� �����Ͱ� ���� ������ �����̴�.
*/

template <typename Tx>
class CQueueNode
{
	template <typename T>
	friend class CQueueList;

private:
	CQueueNode()
		: m_pNext(nullptr)
	{}

	~CQueueNode()
	{}

private:
	CQueueNode<Tx>* m_pNext;
	Tx				m_Data;
};

template <typename T>
class CQueueList
{
public:
	CQueueList()
		: m_pFirst(nullptr)
		, m_pLast(nullptr)
		, m_iSize(0)
	{}

	~CQueueList()	
	{
		clear();
	}

private:
	typedef CQueueNode<T>	NODE;
	typedef CQueueNode<T>* PNODE;

private:
	PNODE	m_pFirst;
	PNODE	m_pLast;
	int		m_iSize;

public:
	void push(const T& data)
	{
		// �߰��� ��带 �����Ѵ�.
		PNODE pNode = new NODE;

		pNode->m_Data = data;

		// m_pLast�� nullptr�� ��� ó�� �߰��ϴ� ����� �ǹ��̴�.
		// �׷��� ������ m_pLast�� nullptr�� �ƴ� ��쿡�� m_pLast�� ���� ����
		// ���� ������ ��带 �ش�.
		if (m_pLast)
			m_pLast->m_pNext = pNode;

		m_pLast = pNode;

		if (!m_pFirst)
			m_pFirst = pNode;

		++m_iSize;
	}

	T front() const
	{
		assert(!empty());

		return m_pFirst->m_Data;
	}

	T pop()
	{
		assert(!empty());

		// ù��° ����� ���� ����� �ּҸ� �����Ѵ�.
		PNODE	pNext = m_pFirst->m_pNext;

		// ù��° ����� �����͸� �����Ѵ�.
		T data = m_pFirst->m_Data;

		// ù��° ��带 �����ش�.

		delete m_pFirst;

		// �����ص� ù��° ����� ���� ���� m_pFirst�� �����Ѵ�.
		m_pFirst = pNext;

		// pNext�� nullptr�� ���� ���� �������� �߰��� ��带 �����ٴ�
		// ���̴�. ��  ���� �����ִ� ���� �����Ƿ� m_pLast�� nullptr��
		// �ش�.
		if (!m_pFirst)
			m_pLast = nullptr;

		--m_iSize;

		return data;
	}

	void clear()
	{
		PNODE pNode = m_pFirst;

		// pNode�� nullptr�� ������ ���� ������ ������ �� �����ٴ� ���̴�.
		while (pNode)
		{
			// ���� ����� ���� ��带 �����Ѵ�.
			PNODE pNext = pNode->m_pNext;

			// ��带 �����ش�.
			delete pNode;

			// ��带 �����ص� �������� �����Ѵ�.
			pNode = pNext;
		}

		m_iSize = 0;

		m_pFirst = nullptr;
		m_pLast = nullptr;
	}

	bool empty() const
	{
		return m_iSize == 0;
	}

	int size() const
	{
		return m_iSize;
	}
};

template <typename Ty, int SIZE = 100>
class CCircleQueue
{
public:
	CCircleQueue()
		: m_iSize(0)
		, m_iHead(0)
		, m_iTail(0)
	{}

	~CCircleQueue()
	{}

private:
	Ty		m_Array[SIZE + 1];
	int		m_iSize;
	int		m_iHead;
	int		m_iTail;

public:
	void push(const Ty& data)
	{
		assert(!full());
		
		int iHead = (m_iHead + 1) % (SIZE + 1);

		m_Array[iHead] = data;
		m_iHead = iHead;
		++m_iSize;	}

	Ty front() const
	{
		assert(!empty());

		int iTail = (m_iTail + 1) % (SIZE + 1);

		return m_Array[iTail];
	}

	Ty pop()
	{
		assert(!empty());

		int iTail = (m_iTail + 1) % (SIZE + 1);
		
		Ty data = m_Array[iTail];

		m_iTail = iTail;
		--m_iSize;

		return data;
	}

	void clear()
	{
		m_iSize = 0;
		m_iHead = 0;
		m_iTail = 0;
	}

	bool full() const
	{
		return m_iSize == SIZE;
	}

	bool empty() const
	{
		return m_iSize == 0;
	}

	int size() const
	{
		return m_iSize;
	}
};