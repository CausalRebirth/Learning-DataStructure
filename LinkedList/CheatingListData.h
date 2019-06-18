#ifndef CheatingListData_h__
#define CheatingListData_h__

#pragma once
template<class Type>
struct Node
{
	Type data;
	Node<Type> *next;
};
template<class Type>
/*
	ʹ�û��������������Ϣ
	���̴߳��������ڵ����ݣ���ֹ�����ڴ��ͻʹ�ÿ���������ʱ������ԭ�ڴ棩
	������Զ�ɾ��
*/
class CCheatingListData
{
protected:
	int len;//�����н�����  
public:
	Node<Type>* Head; //ָ��ͷ���  
public:
	CCheatingListData();
	CCheatingListData(const CCheatingListData<Type>& otherList);//�������캯��  
	~CCheatingListData();
public:
	void createListForward(Type f_seat);//ͷ�巨  
	void createBackward(Type f_seat);//β�巨  
	void initList();//����ͷ��㣬β������ΪNULL  
	bool isEmptyList();//�鿴�Ƿ�Ϊ��
	void printList();//��ӡ����
	int  length();//��ȡ������
	void destoryList();//��������
	void getFirstData(Type& firstItem);//��ȡͷ�ڵ�����
	void search(const Type searchItem);//�����ڵ���Ϣ
	void insertFirst(const Type newItem);//����ͷ�ڵ�
	void insertLast(const Type newItem);//����β�ڵ�
	void insertBefore(const int pos, const Type newItem);//���뵽ĳ�ڵ�֮ǰ
	void insertAfter(const int pos, const Type newItem);//���뵽ĳ�ڵ�֮��
	void deleteNode(const Type deleteItem);//
	void deleteNode(const int pos, Type& deleteItem);//ɾ��ĳ���ڵ�
	void reverse();
	bool FindLoopNode();//�ж��Ƿ��л�
	Node<Type>* findLoopStart();
	const CCheatingListData<Type>& operator=(const CCheatingListData<Type>&otherList);
};
#endif // CheatingListData_h__

