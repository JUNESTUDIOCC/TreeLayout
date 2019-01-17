#ifndef CTreeLayout_H
#define CTreeLayout_H
#include <map>
#include <list>
using namespace std;

class CTreeLayoutNode;
class CTreeLayout
{
public:
	CTreeLayout();
	~CTreeLayout();

	//布局
	void layout();
	//设置根
	void setRoot(CTreeLayoutNode* root);
	//设置节点宽度
	void setNodeWidth(double width);
	//设置节点高度
	void setNodeHeight(double height);
	//设置水平间距
	void setHorizontalSpacing(double space);
	//设置垂直间距
	void setVerticalSpacing(double space);

private:
	//编号
	void number();
	//基本调整
	void calChildrenPos(CTreeLayoutNode* node);
	//判断重叠
	bool detectionOverlap(CTreeLayoutNode*& left, CTreeLayoutNode*& right);
	//调整子节点
	void adjustChildren(CTreeLayoutNode*& left, CTreeLayoutNode*& right);
	//调整父节点
	void adjustParent(CTreeLayoutNode*& node);

protected:
	CTreeLayoutNode*		m_root;
	double					m_nodeWidth;
	double					m_nodeHeight;
	double					m_horSpacing;
	double					m_verSpacing;
	map<int, list<CTreeLayoutNode*>> m_layerNodes;
};



#endif