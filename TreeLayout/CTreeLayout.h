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

	//����
	void layout();
	//���ø�
	void setRoot(CTreeLayoutNode* root);
	//���ýڵ���
	void setNodeWidth(double width);
	//���ýڵ�߶�
	void setNodeHeight(double height);
	//����ˮƽ���
	void setHorizontalSpacing(double space);
	//���ô�ֱ���
	void setVerticalSpacing(double space);

private:
	//���
	void number();
	//��������
	void calChildrenPos(CTreeLayoutNode* node);
	//�ж��ص�
	bool detectionOverlap(CTreeLayoutNode*& left, CTreeLayoutNode*& right);
	//�����ӽڵ�
	void adjustChildren(CTreeLayoutNode*& left, CTreeLayoutNode*& right);
	//�������ڵ�
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