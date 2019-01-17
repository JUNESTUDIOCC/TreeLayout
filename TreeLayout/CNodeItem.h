#ifndef CNodeItem_H
#define CNodeItem_H
#include <QGraphicsItem>
#include "CTreeLayoutNode.h"

class CLinkItem;
class CTreeLayout;
class QGraphicsScene;
class CNodeItem :  public CTreeLayoutNode,public QGraphicsItem
{
public:
	CNodeItem(QGraphicsScene*	scene);
	~CNodeItem();

	void		setToParentLink(CLinkItem* pLink);
	QPointF		getCenterPoint();


	virtual QRectF	boundingRect() const override;
	virtual void	paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

	virtual CPoint	nodePos()const ;
	virtual void	adjustX(double distance);
	virtual void    adjustY(double distance);

protected:
	virtual void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);

protected:
	CLinkItem*		m_toParentlink;
	QGraphicsScene*	m_scene;
};



#endif