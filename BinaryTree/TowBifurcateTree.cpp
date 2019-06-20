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

//ǰ�����������
template <typename T>
void CTowBifurcateTree<T>::preOrder() {
	preOrder(root);
}
//�������������
template <typename T>
void CTowBifurcateTree<T>::inOrder() {
	inOrder(root);
}

//�������������
template <typename T>
void CTowBifurcateTree<T>::postOrder(){
	postOrder(root);
}

//��α���������
template <typename T>
void CTowBifurcateTree<T>::layerOrder(){
	layerOrder(root);
}

//�ݹ�ؽ��в���
template <typename T>
BSNode<T>* CTowBifurcateTree<T>::search_recursion(T key) {
	return search(root, key);
}

//�����ؽ��в���
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

//������СԪ��
template <typename T>
T CTowBifurcateTree<T>::search_minimun() {
	return search_minimun(root);
}

//�������Ԫ��
template <typename T>
T CTowBifurcateTree<T>::search_maximum(){
	return search_maximum(root);
}

//����ָ���ڵ�ĺ�̽ڵ�
template <typename T>
BSNode<T>* CTowBifurcateTree<T>::successor(BSNode<T>* pnode) {
	/*
	��̽ڵ������������ļ���ÿ��Ԫ�ص���һ��Ԫ��
	�����������������̽ڵ�Ϊ��������������ڵ�
	��û��������������������һ�����ӣ����̽ڵ�Ϊ����˫��
	��û��������������������һ���Һ��ӣ���ʱ����ָ�򸸽ڵ��ָ��һֱ���ϱ�����ֱ���ҵ�һ���������ڵ�����ӽڵ�Ľڵ㣬�������ڵ���ڣ���ô����ڵ�ĸ��ڵ��������Ҫ�ҵ���һ���ڵ�
	*/
	if (pnode->rchild != nullptr) {
		//�����������
		pnode = pnode->rchild;
		while (pnode->lchild != nullptr) {
			pnode = pnode->lchild;
		}
		return pnode;
	}
	/////////////////////////û�����������////////////////////////
	BSNode<T>* pparent = pnode->parent;
	if (pparent == nullptr)
		return pnode;
	//��û��������������������һ�����ӣ����̽ڵ�Ϊ����˫��
	//if (pparent->lchild == pnode)
	//	return pparent;
	//����������һ���Һ��ӣ������̽ڵ�Ϊ���������ӵ�������ڵ㡱
	//�����������ҽڵ�û�к�̽ڵ㣬��˼���parent != null��
	while (pparent->rchild == pnode && pparent != nullptr) {
		pnode = pparent;
		if (pparent->parent != nullptr)
			pparent = pparent->parent;
		else
			break;
	}
	return pparent;

}

//����ָ�����ǰ���ڵ�
template <typename T>
BSNode<T>* CTowBifurcateTree<T>::predecessor(BSNode<T>* pnode){
	/*
	�����������������������ڵ�Ϊ��ǰ���ڵ�
	��û������������������Ϊ�����������丸�ڵ�Ϊ��ǰ���ڵ�
	��û������������������Ϊ����������ʱ����ָ�򸸽ڵ��ָ��һֱ���ϱ�����ֱ���ҵ�һ���������ڵ�����ӽڵ�Ľڵ㣬�������ڵ���ڣ���ô����ڵ�ĸ��ڵ��������Ҫ�ҵ���һ���ڵ�
	*/
	if (pnode->lchild != nullptr)//��������
	{
		pnode = pnode->lchild;
		while (pnode->rchild != nullptr)
		{
			pnode = pnode->rchild;
		}
		return pnode;
	}

	BSNode<T>* pparent = pnode->parent;
	while (pparent != nullptr && pparent->lchild == pnode)//�������ѭ�������ǵ��������������Ϊ�ڶ������
	{
		pnode = pparent;
		if (pparent->parent != nullptr)
			pparent = pparent->parent;
		else
			break;
	}
	return pparent;
}

//����ָ��ֵ�ڵ�
template <typename T>
void CTowBifurcateTree<T>::insert(T key) {
	BSNode<T>* pparent = nullptr;
	BSNode<T>* pnode = root;

	while (pnode != nullptr)        //Ѱ�Һ��ʵĲ���λ��
	{
		pparent = pnode;
		if (key > pnode->value)
			pnode = pnode->rchild;
		else if (key < pnode->value)
			pnode = pnode->lchild;
		else
			break;
	}

	pnode = new BSNode<T>(key); //��Ԫ�ص�ֵ�����½ڵ�

	if (pparent == nullptr)            //����ǿ���
	{
		root = pnode;                  //���½ڵ�Ϊ��
	}
	else
	{
		if (key > pparent->value)
		{
			pparent->rchild = pnode;//�����½ڵ�Ϊ�丸�ڵ����
		}
		else if (key < pparent->value)
		{
			pparent->lchild = pnode; //���Һ�
		}
	}
	pnode->parent = pparent;        //ָ���½ڵ�ĸ��ڵ� 
}

//ɾ��ָ��ֵ�ڵ�
template <typename T>
void CTowBifurcateTree<T>::remove(T key){
	remove(root, key);
}
//���ٶ�����
template <typename T>
void CTowBifurcateTree<T>::destory() {
	destory(root);
}
//��ӡ������
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
			BSNode<T>* pdel = nullptr;//��¼Ҫɾ�Ľڵ�

			if (pnode->lchild == nullptr || pnode->rchild == nullptr)
				pdel = pnode;                    //�������������ɾ�ڵ�ֻ��������������������û�к���
			else
				pdel = predecessor(pnode);      //���һ����ɾ�ڵ�ͬʱ��������������ɾ���ýڵ��ǰ��

												//��ʱ����ɾ�ڵ�ֻ��һ�����ӣ���û�к��ӣ�.����ú���ָ��
			BSNode<T>* pchild = nullptr;//��ȡҪ���汾�ڵ���ӽڵ�
			if (pdel->lchild != nullptr)
				pchild = pdel->lchild;
			else if(pdel->rchild != nullptr)
				pchild = pdel->rchild;

			//�ú���ָ��ɾ���ڵ�ĸ��ڵ�
			if (pchild != nullptr)
				pchild->parent = pdel->parent;

			//���Ҫɾ���Ľڵ���ͷ�ڵ㣬ע�����root��ֵ
			if (pdel->parent == nullptr)
				root = pchild;

			//���Ҫɾ���Ľڵ㲻��ͷ�ڵ㣬Ҫע���������˫�׽ڵ�ָ���µĺ��ӽڵ�
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
		//���еݹ���ҵ�ǰ�ڵ�λ��
		else if (key > pnode->value)
		{
			remove(pnode->rchild, key);
		}
		else remove(pnode->lchild, key);
	}
}

//ǰ����� ��������Ϊ�գ���ղ������أ������ȷ��ʸ��ڵ㣬Ȼ��ǰ���������������ǰ�����������
template <typename T>
void CTowBifurcateTree<T>::preOrder(BSNode<T>* ponde){
	if (ponde == nullptr) return;
	cout << ponde->value << endl;
	preOrder(ponde->lchild);
	preOrder(ponde->rchild);
}

//������� ��������Ϊ�գ���ղ������أ�����Ӹ��ڵ㿪ʼ������������ڵ����������Ȼ����ʸ��ڵ㣬������������������
template <typename T>
void CTowBifurcateTree<T>::inOrder(BSNode<T>* ponde){
	if (ponde != nullptr)
	{
		inOrder(ponde->lchild);
		cout << ponde->value << endl;
		inOrder(ponde->rchild);
	}
}

//������� ����Ϊ�գ��򷵻ؿղ����������������Ҷ�Ӻ�ڵ�ķ�ʽ�������������������������������ʽ������ŷ��ʸ��ڵ�
template <typename T>
void CTowBifurcateTree<T>::postOrder(BSNode<T>* p) {
	if (p != nullptr)
	{
		postOrder(p->lchild);
		postOrder(p->rchild);
		cout << p->value << endl;
	}
}

//��α���
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
