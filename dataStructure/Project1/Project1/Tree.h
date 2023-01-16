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
		// 노드를 생성한다.
		PNODE pNode = new NODE;

		pNode->m_Key = key;
		pNode->m_Value = value;

		// Root 노드가 nullptr이라면 처음 추가하는 노드라는 것이다.
		if (!m_pRoot) 
		{
			m_pRoot = pNode;
			++m_iSize;
		}
		else
		{
			// 붙여줄 기준노드를 찾아준다.
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
				// 형제로 추가할때 만약 가지고 있는 형제가 없다면
				// 바로 형제로 추가한다.
				if (pBaseNode->m_pSibling)
					pBaseNode->m_pSibling = pNode;
				else
				{
					// 기존 형제를 받아온다.
					PNODE pSibling = pBaseNode->m_pSibling;

					// 새로 생성한 노드의 형제로 기존의 형제노드를 준다.
					pNode->m_pSibling = pSibling;

					// 기준이 되는 노드의 형제로 새로 생성한 노드를 추가한다.
					pBaseNode->m_pSibling = pNode;

				}
				break;
			case NIT_CHILD:			
				// 자식으로 추가할때 만약 가지고 있는 자식이 없다면
				// 바로 자식으로 추가한다.
				if (pBaseNode->m_pChild)
					pBaseNode->m_pChild = pNode;
				else
				{
					// 기존 자식을 받아온다.
					PNODE pChild = pBaseNode->m_pChild;

					// 새로 생성한 노드의 형제로 기존의 자식노드를 준다.
					pNode->m_pSibling = pChild;

					// 기준이 되는 노드의 자식으로 새로 생성한 노드를 추가한다.
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

