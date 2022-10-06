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
	T				m_Data;			// ���� �����͸� ������ ����
	CListNode<T>*	m_pNext;		// ���� ����� �ּҸ� ������ ����
	CListNode<T>*	m_pPrev;		// ���� ����� �ּҸ� ������ ����
};

// ���ͷ����Ͱ� ��� �ϳ��� ������ �ְ� ���ͷ����͸� �̿��ؼ� ��忡�� �ʿ��� ������ ������.
// Ȥ�� ������ �Ѵ�.
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
	// �ܺο��� ���� �Ұ���
	typedef CListNode<Tx>	NODE;
	typedef CListNode<Tx>*	PNODE;

public:
	// public���� �����ϸ� �̳� Ŭ����ó�� ��밡��
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

	void push_front(const Tx& data)
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
		assert(!empty());

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
		assert(!empty());

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

public:
	// begin() �Լ��� �߰��� ���� ù��° ����� �ּҸ� ������ �ִ�
	// iterator�� ��ȯ�Ѵ�.
	iterator begin() const
	{
		iterator iter;
		iter.m_pNode = m_pBegin->m_pNext;
		return iter;
	}
	
	// end() �Լ��� End ��带 ������ �ִ� iterator �� ��ȯ�Ѵ�.
	iterator end() const
	{
		iterator iter;
		iter.m_pNode = m_pEnd;
		return iter;
	}

	// rbegin() �Լ��� ���� �������� �߰��� ��带 ������ �ִ�
	// reverse_iterator �� ��ȯ�Ѵ�.
	reverse_iterator rbegin() const
	{
		reverse_iterator iter;
		iter.m_pNode = m_pEnd->m_pPrev;
		return iter;
	}

	// rend() �Լ��� Begin��带 ������ �ִ� reverse_iterator��
	// ��ȯ�Ѵ�.
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