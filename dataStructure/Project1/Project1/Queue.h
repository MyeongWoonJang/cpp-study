#pragma once

#include <assert.h>

/*
Queue : 선입선출의 자료구조이다.
먼저 들어간 데이터가 먼저 나오는 구조이다.
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
		// 추가할 노드를 생성한다.
		PNODE pNode = new NODE;

		pNode->m_Data = data;

		// m_pLast가 nullptr일 경우 처음 추가하는 노드라는 의미이다.
		// 그렇기 떄문에 m_pLast가 nullptr이 아닐 경우에만 m_pLast의 다음 노드로
		// 새로 생성한 노드를 준다.
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

		// 첫번째 노드의 다음 노드의 주소를 저장한다.
		PNODE	pNext = m_pFirst->m_pNext;

		// 첫번째 노드의 데이터를 저장한다.
		T data = m_pFirst->m_Data;

		// 첫번째 노드를 지워준다.

		delete m_pFirst;

		// 저장해둔 첫번째 노드의 다음 노드로 m_pFirst를 갱신한다.
		m_pFirst = pNext;

		// pNext가 nullptr일 경우는 가장 마지막에 추가한 노드를 지웠다는
		// 것이다. 즉  현재 남아있는 노드는 없으므로 m_pLast도 nullptr로
		// 준다.
		if (!m_pFirst)
			m_pLast = nullptr;

		--m_iSize;

		return data;
	}

	void clear()
	{
		PNODE pNode = m_pFirst;

		// pNode가 nullptr이 나오면 가장 마지막 노드까지 다 지웠다는 것이다.
		while (pNode)
		{
			// 지울 노드의 다음 노드를 저장한다.
			PNODE pNext = pNode->m_pNext;

			// 노드를 지워준다.
			delete pNode;

			// 노드를 저장해둔 다음노드로 갱신한다.
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