#ifndef CLinkItem_H
#define CLinkItem_H
#include <QGraphicsItem>

class CNodeItem;
class CLinkItem : public QGraphicsItem
{
public:
	CLinkItem(CNodeItem* source, CNodeItem* dest);
	~CLinkItem();


	virtual QRectF	boundingRect() const override;
	virtual void	paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

protected:
	CNodeItem*		m_source;
	CNodeItem*		m_dest;
};



#endif // !CLinkItem_H
