#include "CTreeView.h"
#include "CNodeItem.h"
#include "CLinkItem.h"




CTreeView::CTreeView(QWidget* parent /*= 0*/)
:QGraphicsView(parent)
{
	m_scene = new QGraphicsScene(this);
	setScene(m_scene);
	m_treeLayout.setHorizontalSpacing(50);
	m_treeLayout.setVerticalSpacing(50);
	m_treeLayout.setNodeWidth(30);
	m_treeLayout.setNodeHeight(30);


	m_root = new CNodeItem(m_scene);
	m_treeLayout.setRoot(m_root);
	m_scene->addItem(m_root);
}

CTreeView::~CTreeView()
{

}


