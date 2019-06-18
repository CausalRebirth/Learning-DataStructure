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
	使用环形链表储存表内消息
	多线程处理链表内的数据（防止访问内存冲突使用拷贝，处理时不调用原内存）
	处理后自动删除
*/
class CCheatingListData
{
protected:
	int len;//链表中结点个数  
public:
	Node<Type>* Head; //指向头结点  
public:
	CCheatingListData();
	CCheatingListData(const CCheatingListData<Type>& otherList);//拷贝构造函数  
	~CCheatingListData();
public:
	void createListForward(Type f_seat);//头插法  
	void createBackward(Type f_seat);//尾插法  
	void initList();//生成头结点，尾部设置为NULL  
	bool isEmptyList();//查看是否为空
	void printList();//打印链表
	int  length();//获取链表长度
	void destoryList();//销毁链表
	void getFirstData(Type& firstItem);//获取头节点数据
	void search(const Type searchItem);//搜索节点信息
	void insertFirst(const Type newItem);//插入头节点
	void insertLast(const Type newItem);//插入尾节点
	void insertBefore(const int pos, const Type newItem);//插入到某节点之前
	void insertAfter(const int pos, const Type newItem);//插入到某节点之后
	void deleteNode(const Type deleteItem);//
	void deleteNode(const int pos, Type& deleteItem);//删除某个节点
	void reverse();
	bool FindLoopNode();//判断是否有环
	Node<Type>* findLoopStart();
	const CCheatingListData<Type>& operator=(const CCheatingListData<Type>&otherList);
};
#endif // CheatingListData_h__

