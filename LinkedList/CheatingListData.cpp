#include "stdafx.h"
#include "CheatingListData.h"

template<class Type>
CCheatingListData<Type>::CCheatingListData() //初始化时，只有一个头结点，有head指向  
{
	Head = new Node<Type>;
	Head->next = Head;
	Head->data = 0;
	len = 0;
}

template<class Type>
CCheatingListData<Type>::CCheatingListData(const CCheatingListData<Type>&otherList)
{
	Head = new Node<Type>;
	Head->next = Head;
	len = 0;
	Node<Type>* current = Head;
	Node<Type>* otherListCurrent = otherList.Head->next;//otherListCurrent指向第一个元素  
	if (otherList.Head->next != otherList.Head)//被拷贝的表不是空表  
	{
		while (otherListCurrent->next != otherList.Head)//拷贝的目标不为空  
		{
			Node<Type>* newNode = new Node<Type>;
			newNode->data = otherListCurrent->data;
			newNode->next = current->next;
			current->next = newNode;
			current = current->next;
			otherListCurrent = otherListCurrent->next;
			len++;
		}
		if (otherListCurrent->next == otherList.Head)
		{
			Node<Type>* newNode = new Node<Type>;
			newNode->data = otherListCurrent->data;
			newNode->next = current->next;
			current->next = newNode;
			len++;
		}
	}
}

template<class Type>
const CCheatingListData<Type>& CCheatingListData<Type>::operator=(const CCheatingListData<Type>&otherList)//赋值函数  
{
	Node<Type>* current = Head;//current总是指向要插的位置  
	Node<Type>* otherListCurrent = otherList.Head->next;//otherListCurrent指向第一个元素  
	if (this != &otherList)//避免自己给自己赋值  
	{
		if (current->next != Head)
		{
			initList();//自己有结点，先销毁  
		}
		while (otherListCurrent != otherList.Head)
		{
			Node<Type>* newNode = new Node<Type>;
			newNode->data = otherListCurrent->data;
			newNode->next = current->next;
			current->next = newNode;
			current = current->next;
			otherListCurrent = otherListCurrent->next;
			len++;
		}

	}
	return *this;//为了连续赋值  
}

template<class Type>
CCheatingListData<Type>::~CCheatingListData()
{
	destoryList();
}

template<class Type>
void CCheatingListData<Type>::createListForward(Type f_seat)//头插法  
{
	Node<Type>* newNode;
	newNode = new Node<Type>;
	newNode->data = f_seat;
	newNode->next = Head->next;
	Head->next = newNode; //每插入一个结点，都是要把它放在第一个结点的位置  
}

template<class Type>
void CCheatingListData<Type>::createBackward(Type f_seat)//尾插法  
{
	Node<Type>* current = Head;//current指向头结点 
	while (current->next != Head) {
		current = current->next;
	}
	Node<Type>* newNode;
	newNode = new Node<Type>;
	newNode->data = f_seat;
	newNode->next = current->next;
	current->next = newNode;
	current = current->next;
}

template<class Type>
void CCheatingListData<Type>::initList() //只剩下头结点，和指针设置  
{
	destoryList();//所有结点都销毁，在重建头结点  
	Head = new Node<Type>;
	Head->next = Head;
	len = 0;
}

template<class Type>
bool CCheatingListData<Type>::isEmptyList()
{
	if (Head->next == Head)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class Type>
void CCheatingListData<Type>::printList()
{
	Node<Type>*current = Head->next;
	while (current != Head)
	{
		cout << current->data << endl;
		current = current->next;
	}
}

template<class Type>
int CCheatingListData<Type>::length()
{
	return len;
}

template<class Type>
void CCheatingListData<Type>::destoryList()//销毁包括头结点  
{
	Node<Type>* current;
	Node<Type>* temp;
	if (Head != NULL)//析构函数也要调这个函数，因此要判断头是不是为空，为空表示已经释放  
	{
		temp = Head;
		current = Head->next;
		while (current != Head)
		{
			delete temp;
			temp = current;
			current = current->next;
		}
		delete temp;
		len = 0;
	}
}

template<class Type>
void CCheatingListData<Type>::getFirstData(Type& firstItem)
{
	if (!isEmptyList())
	{
		firstItem = (Head->next)->data;
	}
	else
	{
		cout << "链表为空!" << endl;
	}
}

template<class Type>
void CCheatingListData<Type>::search(Type searchItem)
{
	Node<Type>* current;
	if (isEmptyList())
	{
		cout << "List is Empty" << endl;
	}
	else
	{
		current = Head->next;//越过头结点，指向第一个元素  
		while (current != Head && current->data != searchItem)
		{
			current = current->next;
		}
		if (current != Head)
		{
			cout << searchItem << "is Found in the list" << endl;
		}
		else
		{
			cout << searchItem << "Item is not Found in the list" << endl;
		}
	}
}

template<class Type>
void CCheatingListData<Type>::insertFirst(const Type newItem)
{
	Node<Type> *newNode = new Node<Type>;
	newNode->data = newItem;
	newNode->next = Head->next;
	Head->next = newNode;
	len++;
}

template<class Type>
void CCheatingListData<Type>::insertLast(const Type newItem)
{
	Node<Type> *newNode = new Node<Type>;
	newNode->data = newItem;
	//寻找位置  
	Node<Type>* current = Head;
	while (current->next != Head)
	{
		current = current->next;
	}
	//此时current指向结点的尾部，就是应该插入的位置  
	newNode->next = current->next;
	current->next = newNode;
	len++;
}

template<class Type>
void CCheatingListData<Type>::insertBefore(const int pos, const Type newItem)
{
	int i = 1;
	Node<Type>* current = Head->next;
	if (pos<1 || pos>len)
	{
		cout << "插入位置不正确!" << endl;
		return;
	}
	Node<Type>* newNode = new Node<Type>;
	newNode->data = newItem;
	if (1 == pos)
	{
		newNode->next = Head->next;
		Head->next = newNode;
	}
	else
	{
		while (i < pos - 1)
		{
			current = current->next;
			i++;
		}
		newNode->next = current->next;
		current->next = newNode;
	}
	len++;
}

template<class Type>
void CCheatingListData<Type>::insertAfter(const int pos, const Type newItem)
{
	int i = 1;
	Node<Type>* current = Head->next;//current指向第一个位置，和i配合，指向第i个结点  
	if (pos<1 || pos>len)
	{
		cout << "插入位置不正确!" << endl;
		return;
	}
	Node<Type>* newNode = new Node<Type>;
	newNode->data = newItem;
	while (i < pos)
	{
		current = current->next;
		i++;
	}
	newNode->next = current->next;
	current->next = newNode;
	len++;
}



template<class Type>
void CCheatingListData<Type>::deleteNode(const Type deleteItem)
{
	Node<Type>* current = Head->next;
	Node<Type>* trailCurrent = Head;//指向current前面的结点  
	if (isEmptyList())
	{
		cout << "List is Empty" << endl;
	}
	else
	{
		while (current != Head && current->data != deleteItem)//删除第一个元素后的元素  
		{
			trailCurrent = current;
			current = current->next;
		}
		if (current == NULL)
		{
			cout << "Item is not Found in the list" << endl;
		}
		else
		{
			trailCurrent->next = current->next;
			//delete current;
			cout << "Item is delete in the list" << endl;
		}
		len--;
	}
}

template<class Type>
void CCheatingListData<Type>::deleteNode(const int pos, Type& deleteItem)
{
	int i = 1;
	Node<Type>* current = Head;
	Node<Type>* temp;
	if (pos<1 || pos>len)
	{
		cout << "删除位置不正确!" << endl;
		//deleteItem = -1;
		return;
	}
	while (i < pos)
	{
		current = current->next;
		i++;
	}
	temp = current->next;
	current->next = temp->next;
	deleteItem = temp->data;
	delete temp;
	len--;
}

template<class Type>
//逆转链表,依次取出链表里的元素对链表进行头插
void CCheatingListData<Type>::reverse()
{
	//先处理头结点  
	Node<Type>* current = Head->next;
	Head->next = Head;
	if (current == Head)
	{
		cout << "链表为空!" << endl;
	}
	else
	{
		while (current != Head)
		{
			Node<Type>* nextCurrent = current->next;
			current->next = Head->next;
			Head->next = current;
			current = nextCurrent;
		}
	}
}

//判断是否有环
template<class Type>
bool CCheatingListData<Type>::FindLoopNode() {
	Node<Type>* one, *tow;
	one = tow = Head;
	while (one != NULL && tow->next != NULL)
	{
		one = one->next;
		tow = tow->next->next;
		if (one == tow)
			return true;
	}
	return false;
}
template<class Type>
Node<Type>* CCheatingListData<Type>::findLoopStart() {
	Node<Type>* one, *tow;
	one = tow = Head;
	while (one != NULL && tow->next != NULL)
	{
		one = one->next;
		tow = tow->next->next;
		if (one == tow)
			break;;
	}
	if (one == NULL || tow->next == NULL) return NULL; //没有环，返回NULL值 
	Node<Type> * ptr1 = Head; //链表开始点  
	Node<Type> * ptr2 = one; //相遇点  
	while (ptr1 != ptr2)
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	return ptr1; //找到入口点  
}