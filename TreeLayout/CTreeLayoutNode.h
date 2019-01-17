#ifndef CTreeLayoutNode_H
#define CTreeLayoutNode_H
#include <list>
using namespace std;


struct CPoint
{
	CPoint(double x, double y)
	:m_x(x), m_y(y){}

	double m_x;
	double m_y;
};

struct CSize
{
	CSize(double w, double h)
	:m_width(w), m_height(h){}

	double m_width;
	double m_height;
};


class CTreeLayoutNode
{
	friend class CTreeLayout;
public:
	CTreeLayoutNode();
	virtual ~CTreeLayoutNode();

	void addChild(CTreeLayoutNode* node);
	void removeChild(CTreeLayoutNode* node);

	virtual CPoint	nodePos()const = 0;
	virtual void	adjustX(double distance) = 0;
	virtual void	adjustY(double distance) = 0;
protected:
	int						m_num;
	CTreeLayoutNode*		m_parent;
	list<CTreeLayoutNode*>	m_children;
	int						m_layer;
	CTreeLayout*			m_layout;
};


#endif