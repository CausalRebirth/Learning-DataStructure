#pragma once
//�������Ľڵ�ṹ
template <typename T>
struct BSNode
{
	BSNode(T t) : value(t), lchild(nullptr), rchild(nullptr) {}
	BSNode() = default;
	T value; //�ڵ��ֵ
	BSNode<T>* lchild;//ָ��ڵ������
	BSNode<T>* rchild;//ָ��ڵ���Һ���
	BSNode<T>* parent;//ָ��ڵ��˫��
};

template <typename T>
class CTowBifurcateTree
{
public:
	CTowBifurcateTree();
	~CTowBifurcateTree();
	void preOrder();    //ǰ�����������
	void inOrder();        //�������������
	void postOrder();    //�������������
	void layerOrder();    //��α���������

	BSNode<T>* search_recursion(T key);        //�ݹ�ؽ��в���
	BSNode<T>* search_Iterator(T key);        //�����ؽ��в���

	T search_minimun(); //������СԪ��
	T search_maximum(); //�������Ԫ��

	BSNode<T>* successor(BSNode<T>* x);    //����ָ���ڵ�ĺ�̽ڵ�
	BSNode<T>* predecessor(BSNode<T>* x);    //����ָ���ڵ��ǰ���ڵ�

	void insert(T key);    //����ָ��ֵ�ڵ�
	void remove(T key);    //ɾ��ָ��ֵ�ڵ�
	void destory();        //���ٶ�����
	void print();        //��ӡ������


private:
	BSNode<T>* root; //���ڵ�
private:
	BSNode<T>* search(BSNode<T>* & p, T key);
	void remove(BSNode<T>*  p, T key);
	void preOrder(BSNode<T>* p);
	void inOrder(BSNode<T>* p);
	void postOrder(BSNode<T>* p);
	void layerOrder(BSNode<T>* p);
	T search_minimun(BSNode<T>* p);
	T search_maximum(BSNode<T>* p);
	void destory(BSNode<T>* &p);
};

