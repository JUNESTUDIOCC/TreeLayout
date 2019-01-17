#include "CTreeLayout.h"
#include "CTreeLayoutNode.h"
#include <queue>
#include <stack>

CTreeLayout::CTreeLayout()
{
	m_root = 0;
	m_nodeWidth = 50;
	m_nodeHeight = 50;
	m_horSpacing = 30;
	m_verSpacing = 30;
}

CTreeLayout::~CTreeLayout()
{

}

void CTreeLayout::setRoot(CTreeLayoutNode* root)
{
	m_root = root;
	m_root->m_layout = this;
}

void CTreeLayout::setNodeWidth(double width)
{
	m_nodeWidth = width;
}

void CTreeLayout::setNodeHeight(double height)
{
	m_nodeHeight = height;
}

void CTreeLayout::setHorizontalSpacing(double space)
{
	m_horSpacing = space;
}

void CTreeLayout::setVerticalSpacing(double space)
{
	m_verSpacing = space;
}

void CTreeLayout::layout()
{
	m_root->adjustX(0 - m_root->nodePos().m_x);

	//编号、分层
	number();
	//基本调整
	calChildrenPos(m_root);
	//检测重叠
	CTreeLayoutNode*	left;
	CTreeLayoutNode*	right;
	while (detectionOverlap(left, right))
	{
		//调整子节点
		adjustChildren(left, right);
		//调整父节点
		adjustParent(left->m_parent);
	}
}

void CTreeLayout::number()
{
	m_layerNodes.clear();
	//层序遍历
	queue<CTreeLayoutNode*> q;
	q.push(m_root);

	int num = 0;
	while (!q.empty())
	{
		CTreeLayoutNode* node = q.front();
		q.pop();

		//编号
		node->m_num = num;
		//层分
		m_layerNodes[node->m_layer].push_back(node);

		if (!node->m_children.empty())
		{
			list<CTreeLayoutNode*>::iterator itr = node->m_children.begin();
			while (itr != node->m_children.end())
			{
				q.push(*itr);
				++itr;
			}
		}
		++num;
	}
}

void CTreeLayout::calChildrenPos(CTreeLayoutNode* parentNode)
{

	stack<CTreeLayoutNode*> s;
	s.push(parentNode);

	while (!s.empty())
	{
		CTreeLayoutNode* node = s.top();
		s.pop();

		list<CTreeLayoutNode*>& li = node->m_children;
		CPoint parentPt = node->nodePos();
		int count = li.size();
		double totalW = count*(m_nodeWidth)+(count - 1)*m_horSpacing;
		double firstX = parentPt.m_x - 0.5*totalW + 0.5*m_nodeWidth;
		double y = parentPt.m_y + m_nodeHeight + m_verSpacing;

		list<CTreeLayoutNode*>::iterator itr = li.begin();
		int i = 0;
		while (itr != li.end())
		{
			CTreeLayoutNode* node = *itr;
			CPoint selfPt = node->nodePos();

			double x = firstX + i*(m_nodeWidth + m_horSpacing);
			node->adjustX(x - selfPt.m_x);
			node->adjustY(y - selfPt.m_y);

			s.push(*itr);
			++itr;
			++i;
		}
	}
}

bool CTreeLayout::detectionOverlap(CTreeLayoutNode*& left, CTreeLayoutNode*& right)
{
	map<int, list<CTreeLayoutNode*>>::iterator itr = m_layerNodes.begin();
	while (itr != m_layerNodes.end())
	{
		list<CTreeLayoutNode*>& li = itr->second;
		if (li.size()<2)
		{
			++itr;
			continue;
		}

		list<CTreeLayoutNode*>::iterator itr1 = li.begin();
		while (itr1 != li.end())
		{
			left = *itr1;
			++itr1;
			if (itr1 != li.end())
			{
				right = *itr1;

				CPoint lPt = left->nodePos();
				CPoint rPt = right->nodePos();

				double pos1 = lPt.m_x + m_nodeWidth + m_horSpacing;
				double pos2 = rPt.m_x;
				if (pos1>pos2)
				{
					return true;
				}

			}
		}
		++itr;
	}
	return false;
}

void CTreeLayout::adjustChildren(CTreeLayoutNode*& left, CTreeLayoutNode*& right)
{
	double rX = right->nodePos().m_x - m_horSpacing - m_nodeWidth;
	double di = rX - left->nodePos().m_x;
	left->adjustX(di);
	calChildrenPos(left);
}

void CTreeLayout::adjustParent(CTreeLayoutNode*& node)
{
	CTreeLayoutNode* n = node;
	while (n != 0)
	{
		int count = n->m_children.size();
		double firstX = n->m_children.front()->nodePos().m_x;
		double lastX = n->m_children.back()->nodePos().m_x;
		double totalW = fabs(lastX-firstX) + m_nodeWidth;
		double midX = firstX + 0.5*totalW - 0.5*m_nodeWidth;
		n->adjustX(midX - n->nodePos().m_x);

		n = n->m_parent;
	}
}

