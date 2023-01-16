#pragma once

#include <assert.h>

enum NODE_INSERT_TYPE
{
	NIT_SIBLING,
	NIT_CHILD,
};

template <typename nodeKey, typename nodeValue>
class CTreeNode
{
	template <typename Key, typename Value>
	friend class CTree;

private:
	CTreeNode()
	{
		m_pSibling = nullptr;
		m_pChild = nullptr;
	}

	~CTreeNode()
	{
	}

private:
	CTreeNode<nodeKey, nodeValue>* m_pSibling;
	CTreeNode<nodeKey, nodeValue>* m_pChild;
	nodeKey m_Key;
	nodeValue m_Value;
};

template <typename Key, typename Value>
class CTree
{
public:
	CTree()
	{
		m_pRoot = nullptr;
	}

	~CTree()
	{
	}

private:
	typedef CTreeNode<Key, Value>	NODE;
	typedef CTreeNode<Key, Value>*	PNODE;

private:
	PNODE		m_pRoot;
	int			m_iSize;

public:
	void Insert(const Key& key, const Value& value, const Key& BaseKey = Key(),
		NODE_INSERT_TYPE eType = NIT_SIBLING)
	{
		// ��带 �����Ѵ�.
		PNODE pNode = new NODE;

		pNode->m_Key = key;
		pNode->m_Value = value;

		// Root ��尡 nullptr�̶�� ó�� �߰��ϴ� ����� ���̴�.
		if (!m_pRoot) 
		{
			m_pRoot = pNode;
			++m_iSize;
		}
		else
		{
			// �ٿ��� ���س�带 ã���ش�.
			PNODE pBaseNode = FindNode(BaseKey, m_pRoot);

			if (!pBaseNode)
			{
				delete pNode;
				return;
			}
			else if(pBaseNode == m_pRoot && eType == NIT_SIBLING)
			{
				delete pNode;
				return;
			}
			
			switch (eType)
			{
			case NIT_SIBLING:
				// ������ �߰��Ҷ� ���� ������ �ִ� ������ ���ٸ�
				// �ٷ� ������ �߰��Ѵ�.
				if (pBaseNode->m_pSibling)
					pBaseNode->m_pSibling = pNode;
				else
				{
					// ���� ������ �޾ƿ´�.
					PNODE pSibling = pBaseNode->m_pSibling;

					// ���� ������ ����� ������ ������ ������带 �ش�.
					pNode->m_pSibling = pSibling;

					// ������ �Ǵ� ����� ������ ���� ������ ��带 �߰��Ѵ�.
					pBaseNode->m_pSibling = pNode;

				}
				break;
			case NIT_CHILD:			
				// �ڽ����� �߰��Ҷ� ���� ������ �ִ� �ڽ��� ���ٸ�
				// �ٷ� �ڽ����� �߰��Ѵ�.
				if (pBaseNode->m_pChild)
					pBaseNode->m_pChild = pNode;
				else
				{
					// ���� �ڽ��� �޾ƿ´�.
					PNODE pChild = pBaseNode->m_pChild;

					// ���� ������ ����� ������ ������ �ڽĳ�带 �ش�.
					pNode->m_pSibling = pChild;

					// ������ �Ǵ� ����� �ڽ����� ���� ������ ��带 �߰��Ѵ�.
					pBaseNode->m_pChild = pNode;
				}
				break;
			}
			
		}
	}

	bool empty() const
	{
		return m_iSize == 0;
	}

	int size() const
	{
		return m_iSize;
	}

private:
	PNODE FindNode(const Key& key, PNODE pNode)
	{
		PNODE pResult = nullptr;

		if (pNode->m_Key == key)
			return pNOde;

		if (pNode->m_pSibling)
			pResult = FindNode(key, pNode->child);

		if (pNode->m_pChild && !pResult)
			pResult = FindNode(key, pNode->m_pChild);

		return pResult; 
	}
};

