#include "stdafx.h"
#include "CheatingListData.h"

template<class Type>
CCheatingListData<Type>::CCheatingListData() //��ʼ��ʱ��ֻ��һ��ͷ��㣬��headָ��  
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
	Node<Type>* otherListCurrent = otherList.Head->next;//otherListCurrentָ���һ��Ԫ��  
	if (otherList.Head->next != otherList.Head)//�������ı��ǿձ�  
	{
		while (otherListCurrent->next != otherList.Head)//������Ŀ�겻Ϊ��  
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
const CCheatingListData<Type>& CCheatingListData<Type>::operator=(const CCheatingListData<Type>&otherList)//��ֵ����  
{
	Node<Type>* current = Head;//current����ָ��Ҫ���λ��  
	Node<Type>* otherListCurrent = otherList.Head->next;//otherListCurrentָ���һ��Ԫ��  
	if (this != &otherList)//�����Լ����Լ���ֵ  
	{
		if (current->next != Head)
		{
			initList();//�Լ��н�㣬������  
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
	return *this;//Ϊ��������ֵ  
}

template<class Type>
CCheatingListData<Type>::~CCheatingListData()
{
	destoryList();
}

template<class Type>
void CCheatingListData<Type>::createListForward(Type f_seat)//ͷ�巨  
{
	Node<Type>* newNode;
	newNode = new Node<Type>;
	newNode->data = f_seat;
	newNode->next = Head->next;
	Head->next = newNode; //ÿ����һ����㣬����Ҫ�������ڵ�һ������λ��  
}

template<class Type>
void CCheatingListData<Type>::createBackward(Type f_seat)//β�巨  
{
	Node<Type>* current = Head;//currentָ��ͷ��� 
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
void CCheatingListData<Type>::initList() //ֻʣ��ͷ��㣬��ָ������  
{
	destoryList();//���н�㶼���٣����ؽ�ͷ���  
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
void CCheatingListData<Type>::destoryList()//���ٰ���ͷ���  
{
	Node<Type>* current;
	Node<Type>* temp;
	if (Head != NULL)//��������ҲҪ��������������Ҫ�ж�ͷ�ǲ���Ϊ�գ�Ϊ�ձ�ʾ�Ѿ��ͷ�  
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
		cout << "����Ϊ��!" << endl;
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
		current = Head->next;//Խ��ͷ��㣬ָ���һ��Ԫ��  
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
	//Ѱ��λ��  
	Node<Type>* current = Head;
	while (current->next != Head)
	{
		current = current->next;
	}
	//��ʱcurrentָ�����β��������Ӧ�ò����λ��  
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
		cout << "����λ�ò���ȷ!" << endl;
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
	Node<Type>* current = Head->next;//currentָ���һ��λ�ã���i��ϣ�ָ���i�����  
	if (pos<1 || pos>len)
	{
		cout << "����λ�ò���ȷ!" << endl;
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
	Node<Type>* trailCurrent = Head;//ָ��currentǰ��Ľ��  
	if (isEmptyList())
	{
		cout << "List is Empty" << endl;
	}
	else
	{
		while (current != Head && current->data != deleteItem)//ɾ����һ��Ԫ�غ��Ԫ��  
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
		cout << "ɾ��λ�ò���ȷ!" << endl;
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
//��ת����,����ȡ���������Ԫ�ض��������ͷ��
void CCheatingListData<Type>::reverse()
{
	//�ȴ���ͷ���  
	Node<Type>* current = Head->next;
	Head->next = Head;
	if (current == Head)
	{
		cout << "����Ϊ��!" << endl;
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

//�ж��Ƿ��л�
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
	if (one == NULL || tow->next == NULL) return NULL; //û�л�������NULLֵ 
	Node<Type> * ptr1 = Head; //����ʼ��  
	Node<Type> * ptr2 = one; //������  
	while (ptr1 != ptr2)
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	return ptr1; //�ҵ���ڵ�  
}