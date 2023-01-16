#pragma once

#include <assert.h>
/*
Stack : ���������� �ڷᱸ���̴�.
���� �߰��� �����Ͱ� ���߿� �����±����̴�.
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
		// �����͸� �߰��ϱ� ���� ��带 �����Ѵ�.
		PNODE pNode = new NODE;

		pNode->m_Data = data;

		// ���� ������ ����� �������� ������ m_pNode�� �ش�.
		// m_pNode�� �׻� ���� �������� �߰��� ����̴�.
		// ���� ó�� �߰��Ѵٸ� m_pNode�� nullptr�̱� ������ ���� ������
		// ����� ���� ���� nullptr�� �ȴ�.
		pNode->m_pNext = m_pNode;

		// ���� ������ ��尡 ���� �������� �߰��� ����̹Ƿ�
		// m_pNode�� �� ����� �ּҷ� �����Ѵ�.
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

		// ���� �������� �߰��� ����� ���� ��带 ���´�.
		PNODE pNext = m_pNode->m_pNext;
		T data = m_pNode->m_Data;

		// ���� ������ ��带 �����.
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
			// ���� ��带 ���´�.
			PNODE pNext = pNode->m_pNext;

			// ��带 �����.
			delete pNode;

			// ������ ���� ���� pNode�� �������ش�.
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

			// memcpy : �޸𸮸� �������ִ� �Լ��̴�.
			// 1�������� �ּҿ� 2�������� �ּҿ� �ִ� �����͸� �����Ѵ�.
			// 3�����ڿ� �����ϴ� ũ�⸸ŭ.
			memcpy(pArray, m_pArray, sizeof(Tx) * m_iSize);

			// ���� �迭�� �����ش�.
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
