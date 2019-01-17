#ifndef CTreeView_H
#define CTreeView_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include "CTreeLayout.h"


class CNodeItem;
class CTreeView : public QGraphicsView
{
	Q_OBJECT
public:
	CTreeView(QWidget* parent = 0);
	~CTreeView();


protected:
	CTreeLayout			m_treeLayout;
	QGraphicsScene*		m_scene;
	CNodeItem*			m_root;
};



#endif