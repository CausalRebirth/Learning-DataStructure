#pragma once
//二叉树的节点结构
template <typename T>
struct BSNode
{
	BSNode(T t) : value(t), lchild(nullptr), rchild(nullptr) {}
	BSNode() = default;
	T value; //节点的值
	BSNode<T>* lchild;//指向节点的左孩子
	BSNode<T>* rchild;//指向节点的右孩子
	BSNode<T>* parent;//指向节点的双亲
};

template <typename T>
class CTowBifurcateTree
{
public:
	CTowBifurcateTree();
	~CTowBifurcateTree();
	void preOrder();    //前序遍历二叉树
	void inOrder();        //中序遍历二叉树
	void postOrder();    //后序遍历二叉树
	void layerOrder();    //层次遍历二叉树

	BSNode<T>* search_recursion(T key);        //递归地进行查找
	BSNode<T>* search_Iterator(T key);        //迭代地进行查找

	T search_minimun(); //查找最小元素
	T search_maximum(); //查找最大元素

	BSNode<T>* successor(BSNode<T>* x);    //查找指定节点的后继节点
	BSNode<T>* predecessor(BSNode<T>* x);    //查找指定节点的前驱节点

	void insert(T key);    //插入指定值节点
	void remove(T key);    //删除指定值节点
	void destory();        //销毁二叉树
	void print();        //打印二叉树


private:
	BSNode<T>* root; //根节点
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

