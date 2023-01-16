#pragma once

#include <assert.h>

template <typename T>
class CListNode
{
	template <typename Tx>
	friend class CLinkedList;
	template <typename Ty>
	friend class CListIterator;
	template <typename Tz>
	friend class CListReverseIterator;

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
	T				m_Data;			// 실제 데이터를 저장할 변수
	CListNode<T>*	m_pNext;		// 다음 노드의 주소를 저장할 변수
	CListNode<T>*	m_pPrev;		// 이전 노드의 주소를 저장할 변수
};

// 이터레이터가 노드 하나를 가지고 있고 이터레이터를 이용해서 노드에서 필요한 정보를 빼간다.
// 혹은 연산을 한다.
template <typename Ty>
class CListIterator
{
	template <typename Tx>
	friend class CLinkedList;

public:
	CListIterator()
	{
		m_pNode = nullptr;
	}

	~CListIterator()
	{

	}

private:
	typedef CListNode<Ty>* PNODE;

private:
	PNODE	m_pNode;

public:
	bool operator == (const CListIterator<Ty>& iter)
	{
		return m_pNode == iter.m_pNode;
	}

	bool operator != (const CListIterator<Ty>& iter)
	{
		return m_pNode != iter.m_pNode;
	}

	void operator ++ ()
	{
		m_pNode = m_pNode->m_pNext;
	}

	void operator -- ()
	{
		m_pNode = m_pNode->m_pPrev;
	}

	Ty& operator * ()
	{
		return m_pNode->m_Data;
	}
};

template <typename Tz>
class CListReverseIterator
{
	template <typename Tx>
	friend class CLinkedList;

public:
	CListReverseIterator()
	{
		m_pNode = nullptr;
	}

	~CListReverseIterator()
	{

	}

private:
	typedef CListNode<Tz>* PNODE;

private:
	PNODE	m_pNode;

public:
	bool operator == (const CListReverseIterator<Tz>& iter)
	{
		return m_pNode == iter.m_pNode;
	}

	bool operator != (const CListReverseIterator<Tz>& iter)
	{
		return m_pNode != iter.m_pNode;
	}

	void operator ++ ()
	{
		m_pNode = m_pNode->m_pPrev;
	}

	void operator -- ()
	{
		m_pNode = m_pNode->m_pNext;
	}

	Tz& operator * ()
	{
		return m_pNode->m_Data;
	}
};

template <typename Tx>
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
	// 외부에서 접근 불가능
	typedef CListNode<Tx>	NODE;
	typedef CListNode<Tx>*	PNODE;

public:
	// public으로 정의하면 이너 클래스처럼 사용가능
	typedef CListIterator<Tx>		iterator;
	typedef CListReverseIterator<Tx> reverse_iterator;

private:
	PNODE	m_pBegin;
	PNODE	m_pEnd;
	int		m_iSize;

public:
	void push_back(const Tx& data)
	{
		PNODE pNode = new NODE;
		pNode->m_Data = data;

		// 뒤에 추가를 해야 하므르 End의 이전 노드를 얻어온다.
		PNODE pPrev = m_pEnd->m_pPrev;

		// 얻어온 이전 노드와 End노드 사이에 새로 생성한 노드를
		// 추가한다.
		pPrev->m_pNext = pNode;
		pNode->m_pPrev = pPrev;

		// End노드와 새로 생성한 노드를 연결한다.
		pNode->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = pNode;

		++m_iSize;
	}

	void push_front(const Tx& data)
	{
		PNODE pNode = new NODE;
		pNode->m_Data = data;

		// Begin과 Begin의 다음 노드 사이에 새로 생성한 노드를
		// 추가한다.
		PNODE pNext = m_pBegin->m_pNext;

		// 새로 생성한 노드의 다음노드로 Begin의 다음 노드를
		// 준다. Begin의 다음 노드의 이전노드로 새로  생성한
		// 노드를 준다.
		pNode->m_pNext = pNext;
		pNext->m_pPrev = pNode;

		// Begin의 다음노드로 새로 생성한 노드를 준다.
		// 새로 생성한 노드의 이전 노드로 Begin을 준다.
		m_pBegin->m_pNext = pNode;
		pNode->m_Prev = m_pBegin;

		++m_iSize;
	}

	void pop_back()
	{
		assert(!empty());

		// 가장 마지막 노드를 지워야 하므로 End노드의 이전 노드를
		// 얻어온다.
		PNODE pDeleteNode = m_pEnd->m_pPrev;

		// 지울 노드의 이전 노드를 얻어온다.
		PNODE pPrev = pDeleteNode->m_pPrev;

		// 이전노드의 다음으로 End를 주고 End의 이전으로
		// 이전노드를 준다.
		pPrev->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = pPrev;

		// 노드를 지워준다.
		delete pDeleteNode;

		// 사이즈를 1 감소 시킨다.
		--m_iSize;
	}

	void pop_front()
	{
		assert(!empty());

		// 지울 노드를 얻어온다.
		PNODE pDeleteNode = m_pBegin->m_pNext;

		// 지울 노드의 다음 노드를 얻어오고 해당 노드와 Begin 노드를
		// 연결해준다.
		PNODE pNext = pDeleteNode->m_pNext;

		pNext->m_pPrev = m_pBegin;
		m_pBegin->m_pNext = pNext;

		// 노드를 지워준다.
		delete pDeleteNode;

		// 사이즈를 1 감소시킨다.
		--m_iSize;
	}

	Tx front()const
	{
		assert(!empty());

		return m_pBegin->m_pNext->m_Data;
	}

	Tx back()const
	{
		assert(!empty());

		return m_pEnd->m_pPrev->m_Data;
	}

	// Begin과 End를 제외한 실제 추가한 노드의 삭제 기능을
	// 만들어준다.
	void clear()
	{
		PNODE pNode = m_pBegin->m_pNext;

		while (pNode != m_pEnd)
		{
			// 현재 노드의 다음 노드를 얻어온다.
			PNODE pNext = pNode->m_pNext;

			// 현재 노드를 지워준다.
			delete pNode;

			// pNode에 다음 노드의 주소를 넣어준다.
			pNode = pNext;
		}

		m_iSize = 0;

		// Begin과 End를 서로 연결해준다.
		m_pBegin->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = m_pBegin;
	}

	int size() const
	{
		return m_iSize;
	}

	// 리스트가 비어있을 경우 true, 아닐 경우 false를 반환한다.
	bool empty() const
	{
		return m_iSize == 0;
	}

public:
	// begin() 함수는 추가된 가장 첫번째 노드의 주소를 가지고 있는
	// iterator를 반환한다.
	iterator begin() const
	{
		iterator iter;
		iter.m_pNode = m_pBegin->m_pNext;
		return iter;
	}
	
	// end() 함수는 End 노드를 가지고 있는 iterator 를 반환한다.
	iterator end() const
	{
		iterator iter;
		iter.m_pNode = m_pEnd;
		return iter;
	}

	// rbegin() 함수는 가장 마지막에 추가된 노드를 가지고 있는
	// reverse_iterator 를 반환한다.
	reverse_iterator rbegin() const
	{
		reverse_iterator iter;
		iter.m_pNode = m_pEnd->m_pPrev;
		return iter;
	}

	// rend() 함수는 Begin노드를 가지고 있는 reverse_iterator를
	// 반환한다.
	reverse_iterator rend() const
	{
		reverse_iterator iter;
		iter.m_pNode = m_pBegin;
		return iter;
	}

	void sort(bool (*pFunc)(const Tx&, const Tx&))
	{
		for (PNODE pFirst = m_pBegin->m_pNext;
			pFirst != m_pEnd->m_pPrev; pFirst = pFirst->m_pNext)
		{
			for (PNODE pSecond = pFirst->m_pNext; 
				pSecond != m_pEnd; pSecond = pSecond->m_pNext)
			{
				if (pFunc(pFirst->m_Data, pSecond->m_Data))
				{
					Tx temp = pFirst->m_Data;
					pFirst->m_Data = pSecond->m_Data;
					pSecond->m_Data = temp;
				}
			}
		}
	}
};