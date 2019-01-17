#include "CNodeItem.h"
#include <QPainter>
#include <QMenu>
#include <QGraphicsSceneContextMenuEvent>
#include "CTreeLayout.h"
#include "CLinkItem.h"
#include <QGraphicsScene>
#include <QDebug>

CNodeItem::CNodeItem(QGraphicsScene*	scene)
:m_scene(scene)
{
	m_toParentlink = 0;
}

CNodeItem::~CNodeItem()
{
	int c = 0;

	if (m_toParentlink)
	{
		delete m_toParentlink;
	}

	qDebug() << "delete node:" << m_num;
}

void CNodeItem::setToParentLink(CLinkItem* pLink)
{
	m_toParentlink = pLink;
}

QPointF CNodeItem::getCenterPoint()
{
	return QPointF(x() + 15, y() + 15);
}

QRectF CNodeItem::boundingRect() const
{
	return QRectF(0, 0, 30, 30);
}

void CNodeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

	painter->setBrush(QColor(80,161,241));
	painter->drawEllipse(boundingRect());

	painter->setPen(Qt::white);
	QFont f;
	f.setPointSize(20);
	painter->setFont(f);
	painter->drawText(boundingRect(), Qt::AlignCenter, QString::number(m_num));
}

CPoint CNodeItem::nodePos() const
{
	double x1 = x();
	double y1 = y(); 
	return CPoint(x1, y1);
}

void CNodeItem::adjustX(double distance)
{
	//QString text = QString("node(%1):X(%2)--->X(%3)").arg(m_num).arg(x()).arg(x() + distance);
	//qDebug() << text;
	setX(x() + distance);
}

void CNodeItem::adjustY(double distance)
{
	setY(y() + distance);
}

void CNodeItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
	QMenu menu;
	QAction *addAct = menu.addAction("AddChild");
	QAction *removeAct = menu.addAction("Remove");
	QAction *selectedAction = menu.exec(event->screenPos());

	if (selectedAction == addAct)
	{
		CNodeItem* pNode = new CNodeItem(m_scene);
		pNode->setX(x());
		CLinkItem* pLink = new CLinkItem(this, pNode);
		pNode->setToParentLink(pLink);

		addChild(pNode);
		m_scene->addItem(pNode);
		m_scene->addItem(pLink);

		m_scene->update();
	}
	else if (selectedAction == removeAct)
	{
		if (m_parent)
		{
			QGraphicsScene*	scene = m_scene;
			//删除后不可再次调用本类
			m_parent->removeChild(this);
			scene->update();
		}
	}
}

