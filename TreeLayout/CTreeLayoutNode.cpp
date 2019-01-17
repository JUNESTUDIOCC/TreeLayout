#include "CTreeLayoutNode.h"
#include "CTreeLayout.h"

CTreeLayoutNode::CTreeLayoutNode()
:m_layout(0), m_num(0), m_layer(0), m_parent(0)
{

}

CTreeLayoutNode::~CTreeLayoutNode()
{
	//删除所有子对象
	list<CTreeLayoutNode*>::iterator itr1 = m_children.begin();
	while (itr1 != m_children.end())
	{
		CTreeLayoutNode* node = *itr1;
		delete node;
		++itr1;
	}
	m_children.clear();
}

void CTreeLayoutNode::addChild(CTreeLayoutNode* node)
{
	m_children.push_back(node);
	node->m_num = m_num + 1;
	node->m_layer = m_layer + 1;
	node->m_parent = this;
	node->m_layout = m_layout;

	m_layout->layout();
}

void CTreeLayoutNode::removeChild(CTreeLayoutNode* node)
{
	list<CTreeLayoutNode*>::iterator itr = m_children.begin();
	CTreeLayoutNode* pNode = 0;
	while (itr != m_children.end())
	{
		if (*itr == node)
		{
			pNode = *itr;
			itr = m_children.erase(itr);
			break;
		}
		++itr;
	}
	m_layout->layout();

	delete pNode;
}

