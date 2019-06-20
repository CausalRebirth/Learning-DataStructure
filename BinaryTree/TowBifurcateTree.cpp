#include "stdafx.h"
#include "TowBifurcateTree.h"
#include <queue>

template <typename T>
CTowBifurcateTree<T>::CTowBifurcateTree()
{
}

template <typename T>
CTowBifurcateTree<T>::~CTowBifurcateTree()
{
}

//前序遍历二叉树
template <typename T>
void CTowBifurcateTree<T>::preOrder() {
	preOrder(root);
}
//中序遍历二叉树
template <typename T>
void CTowBifurcateTree<T>::inOrder() {
	inOrder(root);
}

//后序遍历二叉树
template <typename T>
void CTowBifurcateTree<T>::postOrder(){
	postOrder(root);
}

//层次遍历二叉树
template <typename T>
void CTowBifurcateTree<T>::layerOrder(){
	layerOrder(root);
}

//递归地进行查找
template <typename T>
BSNode<T>* CTowBifurcateTree<T>::search_recursion(T key) {
	return search(root, key);
}

//迭代地进行查找
template <typename T>
BSNode<T>* CTowBifurcateTree<T>::search_Iterator(T key) {
	BSNode<T>* ponde = root;
	while (ponde != nullptr)
	{
		if (ponde->value == key)
			return ponde;
		if (ponde->value > key)
			ponde = ponde->lchild;
		else
			ponde = ponde->rchild;
	}
	return nullptr;
}

//查找最小元素
template <typename T>
T CTowBifurcateTree<T>::search_minimun() {
	return search_minimun(root);
}

//查找最大元素
template <typename T>
T CTowBifurcateTree<T>::search_maximum(){
	return search_maximum(root);
}

//查找指定节点的后继节点
template <typename T>
BSNode<T>* CTowBifurcateTree<T>::successor(BSNode<T>* pnode) {
	/*
	后继节点是中序遍历后的集合每个元素的下一个元素
	它有右子树；则其后继节点为其右子树的最左节点
	它没有右子树，但它本身是一个左孩子，则后继节点为它的双亲
	它没有右子树，但它本身是一个右孩子，此时沿着指向父节点的指针一直向上遍历，直到找到一个是它父节点的左子节点的节点，如果这个节点存在，那么这个节点的父节点就是我们要找的下一个节点
	*/
	if (pnode->rchild != nullptr) {
		//玩家有右子树
		pnode = pnode->rchild;
		while (pnode->lchild != nullptr) {
			pnode = pnode->lchild;
		}
		return pnode;
	}
	/////////////////////////没有右子树情况////////////////////////
	BSNode<T>* pparent = pnode->parent;
	if (pparent == nullptr)
		return pnode;
	//它没有右子树，但它本身是一个左孩子，则后继节点为它的双亲
	//if (pparent->lchild == pnode)
	//	return pparent;
	//但它本身是一个右孩子，则其后继节点为“具有左孩子的最近父节点”
	//整棵数的最右节点没有后继节点，因此加上parent != null。
	while (pparent->rchild == pnode && pparent != nullptr) {
		pnode = pparent;
		if (pparent->parent != nullptr)
			pparent = pparent->parent;
		else
			break;
	}
	return pparent;

}

//查找指定点的前驱节点
template <typename T>
BSNode<T>* CTowBifurcateTree<T>::predecessor(BSNode<T>* pnode){
	/*
	它有左子树，则左子树根节点为其前驱节点
	它没有左子树，且它本身为右子树，则其父节点为其前驱节点
	它没有左子树，且它本身为左子树，此时沿着指向父节点的指针一直向上遍历，直到找到一个是它父节点的右子节点的节点，如果这个节点存在，那么这个节点的父节点就是我们要找的下一个节点
	*/
	if (pnode->lchild != nullptr)//有左子树
	{
		pnode = pnode->lchild;
		while (pnode->rchild != nullptr)
		{
			pnode = pnode->rchild;
		}
		return pnode;
	}

	BSNode<T>* pparent = pnode->parent;
	while (pparent != nullptr && pparent->lchild == pnode)//如果进入循环，则是第三种情况；否则为第二种情况
	{
		pnode = pparent;
		if (pparent->parent != nullptr)
			pparent = pparent->parent;
		else
			break;
	}
	return pparent;
}

//插入指定值节点
template <typename T>
void CTowBifurcateTree<T>::insert(T key) {
	BSNode<T>* pparent = nullptr;
	BSNode<T>* pnode = root;

	while (pnode != nullptr)        //寻找合适的插入位置
	{
		pparent = pnode;
		if (key > pnode->value)
			pnode = pnode->rchild;
		else if (key < pnode->value)
			pnode = pnode->lchild;
		else
			break;
	}

	pnode = new BSNode<T>(key); //以元素的值构建新节点

	if (pparent == nullptr)            //如果是空树
	{
		root = pnode;                  //则新节点为根
	}
	else
	{
		if (key > pparent->value)
		{
			pparent->rchild = pnode;//否则新节点为其父节点的左孩
		}
		else if (key < pparent->value)
		{
			pparent->lchild = pnode; //或右孩
		}
	}
	pnode->parent = pparent;        //指明新节点的父节点 
}

//删除指定值节点
template <typename T>
void CTowBifurcateTree<T>::remove(T key){
	remove(root, key);
}
//销毁二叉树
template <typename T>
void CTowBifurcateTree<T>::destory() {
	destory(root);
}
//打印二叉树
template <typename T>
void CTowBifurcateTree<T>::print() {}
template <typename T>
BSNode<T>* CTowBifurcateTree<T>::search(BSNode<T>* & pnode, T key){
	if (pnode == nullptr) return nullptr;
	if (pnode->value == key) return pnode;
	if (pnode->value > key)	search(pnode->lchild, key);
	else search(pnode->rchild, key);
}

template <typename T>
void CTowBifurcateTree<T>::remove(BSNode<T>*  pnode, T key){
	if (pnode != nullptr)
	{
		if (pnode->value == key)
		{
			BSNode<T>* pdel = nullptr;//记录要删的节点

			if (pnode->lchild == nullptr || pnode->rchild == nullptr)
				pdel = pnode;                    //情况二、三：被删节点只有左子树或右子树，或没有孩子
			else
				pdel = predecessor(pnode);      //情况一：被删节点同时有左右子树，则删除该节点的前驱

												//此时，被删节点只有一个孩子（或没有孩子）.保存该孩子指针
			BSNode<T>* pchild = nullptr;//获取要顶替本节点的子节点
			if (pdel->lchild != nullptr)
				pchild = pdel->lchild;
			else if(pdel->rchild != nullptr)
				pchild = pdel->rchild;

			//让孩子指向被删除节点的父节点
			if (pchild != nullptr)
				pchild->parent = pdel->parent;

			//如果要删除的节点是头节点，注意更改root的值
			if (pdel->parent == nullptr)
				root = pchild;

			//如果要删除的节点不是头节点，要注意更改它的双亲节点指向新的孩子节点
			else if (pdel->parent->lchild == pdel)
			{
				pdel->parent->lchild = pchild;
			}
			else if (pdel->parent->rchild == pdel)
			{
				pdel->parent->rchild = pchild;
			}

			if (pnode->value != pdel->value)
				pnode->value = pdel->value;
			delete pdel;
		}
		//进行递归查找当前节点位置
		else if (key > pnode->value)
		{
			remove(pnode->rchild, key);
		}
		else remove(pnode->lchild, key);
	}
}

//前序遍历 若二叉树为空，则空操作返回，否则先访问根节点，然后前序遍历左子树，再前序遍历右子树
template <typename T>
void CTowBifurcateTree<T>::preOrder(BSNode<T>* ponde){
	if (ponde == nullptr) return;
	cout << ponde->value << endl;
	preOrder(ponde->lchild);
	preOrder(ponde->rchild);
}

//中序遍历 若二叉树为空，则空操作返回，否则从根节点开始，中序遍历根节点的左子树，然后访问根节点，最后中序遍历右子树。
template <typename T>
void CTowBifurcateTree<T>::inOrder(BSNode<T>* ponde){
	if (ponde != nullptr)
	{
		inOrder(ponde->lchild);
		cout << ponde->value << endl;
		inOrder(ponde->rchild);
	}
}

//后序遍历 若树为空，则返回空操作，否则从左到右先叶子后节点的方式遍历访问左右子树，左右子树都访问结束，才访问根节点
template <typename T>
void CTowBifurcateTree<T>::postOrder(BSNode<T>* p) {
	if (p != nullptr)
	{
		postOrder(p->lchild);
		postOrder(p->rchild);
		cout << p->value << endl;
	}
}

//层次遍历
template<typename T>
void CTowBifurcateTree<T>::layerOrder(BSNode<T>* p) {
	std::queue<BSNode<T>*> q;
	if (p == nullptr) return;
	BSNode<T>* ponde;
	q.push(p);
	cout << p->value << endl;
	while (!q.empty())
	{
		ponde = q.front();
		q.pop();

		if (ponde->lchild != nullptr)
		{
			q.push(ponde->lchild);
			cout << ponde->lchild->value << endl;
		}
		if (ponde->rchild != nullptr)
		{
			q.push(ponde->rchild);
			cout << ponde->rchild->value << endl;
		}
	}
}
template <typename T>
T CTowBifurcateTree<T>::search_minimun(BSNode<T>* p) {
	if (p != nullptr)
	{
		if (p->lchild != nullptr)
		{
			return search_minimun(p->lchild);
		}
		return p->value;
	}
	return 0;
}

template <typename T>
T CTowBifurcateTree<T>::search_maximum(BSNode<T>* p) {
	if (p != nullptr)
	{
		if (p->rchild != nullptr)
		{
			return search_maximum(p->rchild);
		}
		return p->value;
	}
	return 0;
}

template <typename T>
void CTowBifurcateTree<T>::destory(BSNode<T>* &p) {
	if (p != nullptr)
	{
		if (p->lchild != nullptr)
			destory(p->lchild);
		if (p->rchild != nullptr)
			destory(p->rchild);
		delete p;
		p = nullptr;
	}
}
