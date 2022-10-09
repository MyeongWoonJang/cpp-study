#pragma once

#include <assert.h>
/*
Stack : 선입후출의 자료구조이다.
먼저 추가된 데이터가 나중에 나오는구조이다.
*/

template <typename Tn>
class CStackNode
{
	template <typename T>
	friend class CStackList;

private:
	CStackNode()
		: m_pNext(nullptr)
	{}

	~CStackNode()
	{}

private:
	CStackNode<Tn>* m_pNext;
	Tn				m_Data;
};

template <typename T>
class CStackList
{
public:
	CStackList()
		: m_pNode(nullptr)
		, m_iSize(0)
	{

	}

	~CStackList()
	{
		clear();
	}

private:
	typedef CStackNode<T>	NODE;
	typedef CStackNode<T>*	PNODE;

private:
	PNODE	m_pNode;
	int		m_iSize;

public:
	void push(const T& data)
	{
		// 데이터를 추가하기 위한 노드를 생성한다.
		PNODE pNode = new NODE;

		pNode->m_Data = data;

		// 새로 생성한 노드의 다음노드로 기존의 m_pNode를 준다.
		// m_pNode는 항상 가장 마지막에 추가한 노드이다.
		// 만약 처음 추가한다면 m_pNode는 nullptr이기 때문에 새로 생성한
		// 노드의 다음 노드는 nullptr이 된다.
		pNode->m_pNext = m_pNode;

		// 새로 생성한 노드가 가장 마지막에 추가한 노드이므로
		// m_pNode를 이 노드의 주소로 갱신한다.
		m_pNode = pNode;

		++m_iSize;
	}

	T top() const
	{
		assert(!empty());

		return m_pNode->m_Data;
	}

	T pop()
	{
		assert(!empty());

		// 가장 마지막에 추가된 노드의 다음 노드를 얻어온다.
		PNODE pNext = m_pNode->m_pNext;
		T data = m_pNode->m_Data;

		// 가장 마지막 노드를 지운다.
		delete m_pNode;

		m_pNode = pNext;
		--m_iSize;

		return data;
	}
	
	void clear()
	{
		PNODE pNode = m_pNode;

		while (pNode)
		{
			// 다음 노드를 얻어온다.
			PNODE pNext = pNode->m_pNext;

			// 노드를 지운다.
			delete pNode;

			// 얻어놓은 다음 노드로 pNode를 갱신해준다.
			pNode = pNext;
		}
		
		m_iSize = 0;
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

template <typename Tx, int SIZE = 10>
class CStackArray
{
public:
	CStackArray()
	{
		m_iCapacity = SIZE;
		m_iSize = 0;

		m_pArray = new Tx[m_iCapacity];
	}

	~CStackArray()
	{
		delete[] m_pArray;
	}

private:
	Tx* m_pArray;
	int m_iSize;
	int m_iCapacity;

public:
	void push(const Tx& data)
	{
		if (full())
		{
			m_iCapacity *= 2;
			Tx* pArray = new Tx[m_iCapacity];

			// memcpy : 메모리를 복사해주는 함수이다.
			// 1번인자의 주소에 2번인자의 주소에 있는 데이터를 복사한다.
			// 3번인자에 지정하는 크기만큼.
			memcpy(pArray, m_pArray, sizeof(Tx) * m_iSize);

			// 기존 배열을 지워준다.
			delete[] m_pArray;

			m_pArray = pArray;
		}

		m_pArray[m_iSize++] = data;
	}

	Tx top() const
	{
		assert(!empty());

		return m_pArray[m_iSize - 1];
	}

	Tx pop()
	{
		assert(!empty());

		Tx data = m_pArray[m_iSize - 1];
		--m_iSize;

		return data;
	}

	void clear()
	{
		m_iSize = 0;
	}

	bool empty() const
	{
		return m_iSize == 0;
	}

	bool full() const
	{
		return m_iSize == m_iCapacity;
	}

	int size() const
	{
		return m_iSize;
	}

	int capacity() const
	{
		return m_iCapacity;
	}
};
