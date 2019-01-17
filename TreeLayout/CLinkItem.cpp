#include "CLinkItem.h"
#include "CNodeItem.h"
#include <QPainter>


CLinkItem::CLinkItem(CNodeItem* source, CNodeItem* dest)
:m_source(source), m_dest(dest)
{
	setZValue(-1);
}

CLinkItem::~CLinkItem()
{

}

QRectF CLinkItem::boundingRect() const
{
	if (!m_source || !m_dest)
		return QRectF();

	qreal penWidth = 1;
	qreal extra = (penWidth) / 2.0;

	QPointF sPt = m_source->getCenterPoint();
	QPointF dPt = m_dest->getCenterPoint();


	return QRectF(sPt, QSizeF(dPt.x() - sPt.x(), dPt.y() - sPt.y())).normalized().adjusted(-extra, -extra, extra, extra);
}

void CLinkItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);


	QPointF sPt = m_source->getCenterPoint();
	QPointF dPt = m_dest->getCenterPoint();

	painter->drawLine(sPt,dPt);
}

