#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//int globalVar = 1;
//static int staticGlobalVar = 1;
//void Test()
//{
//	static int staticVar = 1;
//	int localVar = 1;
//
//	int num1[10] = { 1, 2, 3, 4 };
//	char char2[] = "abcd";  //char2��һ�����飬������ջ�ϣ�*char2Ҳ��ջ��
//	char* pChar3 = "abcd";  //pChar3��һ���ֲ�������ָ�룬��ջ�ϡ���ָ���ĳ������ĵ�ַ������*pChar3�ڳ�����
//	int* ptr1 = (int*)malloc(sizeof(int) * 4);//ͬ��ptr1��ջ�ϣ�*ptr1�ڶ���
//	int* ptr2 = (int*)calloc(4, sizeof(int));
//	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
//	free(ptr1);
//	free(ptr3);
//}
//
////1. ѡ���⣺
////ѡ�� : A.ջ B.�� C.���ݶ�(��̬��) D.�����(������)
////globalVar�����____ staticGlobalVar�����____
////staticVar�����____ localVar�����____
////num1 �����____
////
//// CCCAA
//// 
////char2�����____ * char2�����___
////pChar3�����____ * pChar3�����____
////ptr1�����____ * ptr1�����____
////2. ����⣺
////sizeof(num1) = ____; //40
////sizeof(char2) = ____; strlen(char2) = ____;   //5 4
////sizeof(pChar3) = ____; strlen(pChar3) = ____; //4 4
////sizeof(ptr1) = ____; //4

//void Test()
//{
//	int* p1 = (int*)malloc(sizeof(int));
//	free(p1);
//
//	int* p2 = (int*)calloc(4, sizeof(int));
//	int* p3 = (int*)realloc(p2, sizeof(int) * 10);
//
//	// ������Ҫfree(p2)��
//	free(p3);
//}

//int main()
//{
//	//new/delete��malloc/free�����������û���κβ��ֻ���÷���һ��
//
//	//C���Զ�̬����ռ�
//	int* p1 = (int*)malloc(sizeof(int) * 10); 
//	free(p1);
//
//	//C++��̬����ռ�
//	//new/delete new[]/delete[]һ��Ҫƥ��ʹ�ã�������ܻ����
//	int* p2 = new int[10];//����������
//	int* p3 = new int;    //���뵥������
//
//	delete[] p2;
//	delete p3;
//
//	return 0;
//}

//struct ListNode
//{
//	//struct ListNode* _next; //C �ṹ��
//
//	//��
//	ListNode* _next;
//	ListNode* _prev;
//	int _val;
//
//	//���캯��
//	ListNode(int val = 0)
//		:_next(nullptr)
//		, _prev(nullptr)
//		, _val(val)
//	{}
//	~ListNode()
//	{
//
//	}
//
//};
//
//int main()
//{
//	//C mallocֻ�ǿ��ռ�,free�������ͷſռ�
//	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	//���˹��캯����n1������ݻ������ֵ����n2�Ѿ�����ʼ����
//	free(n1);
//
//	//C++ 
//	//new    ����Զ������ͣ����ռ� + ���ù��캯����ʼ��
//	//delete ����Զ������ͣ����������������� + �ͷſռ�
//	ListNode* n2 = new ListNode; //new + ����
//	delete n2;
//
//	//�������valΪ����ֵ������
//	ListNode* n3 = new ListNode(5); //�൱�ڴ�����c�����е�BuyListNode(5)
//	delete n3;
//
//	//C��������������
//	struct ListNode* arr3 = (struct ListNode*)malloc(sizeof(struct ListNode) * 4);
//	free(arr3);
//
//	//C++����������
//	ListNode* arr4 = new ListNode[4]; //������4�ι��캯�� ��֧��ListNode* arr4 = new ListNode[4](5)������ֵ
//	//C++11֧��ListNode* arr4 = new ListNode[4]{1,2,3};arr[3]��ʼ��Ϊ0
//
//	delete[] arr4; //����4����������
//
//	int* p1 = new int(0);
//	int* p2 = new int[4]{ 1,2,3,4 };
//
//	return 0;
//}

////mallloc �����������ռ䣿
//int main()
//{
//	 
//	return 0;
//}

//struct ListNode
//{
//	ListNode* _next;
//	ListNode* _prev;
//	int _val;
//
//	//���캯��
//	ListNode(int val = 0)
//		:_next(nullptr)
//		, _prev(nullptr)
//		, _val(val)
//	{}
//	~ListNode()
//	{}
//
//};
//
//int main()
//{
//	ListNode* p1 = (ListNode*)malloc(sizeof(ListNode));
//	free(p1);
//
//	//���÷���operator new/delete��malloc/free����ȫһ���ģ������ڶ���������ͷſռ�
//	//������ʧ�ܺ�Ĵ���ʽ��һ����mallocʧ�ܺ󷵻�NULL��operator newʧ�ܺ����쳣
//	ListNode* p2 = (ListNode*)operator new(sizeof(ListNode));
//	operator delete(p2);
//
//
//	return 0;
//}

//struct ListNode
//{
//	ListNode* _next;
//	ListNode* _prev;
//	int _val;
//
//	//����������ר����operator new
//	//
//	void* operator new(size_t n)
//	{
//		void* p = nullptr;
//		p = allocator<ListNode>().allocate(1); //STL�еĿռ�����������ʵ����һ���򵥵��ڴ��
//		cout << "memory pool allocate" << endl;
//		return p;
//	}
//	void operator delete(void* p)
//	{
//		allocator<ListNode>().deallocate((ListNode*)p, 1);
//		cout << "memory pool deallocate" << endl;
//	}
//
//	//���캯��
//	ListNode(int val = 0)
//		:_next(nullptr)
//		, _prev(nullptr)
//		, _val(val)
//	{}
//
//};
//
//int main()
//{
//	ListNode* p = new ListNode(5);
//	delete(p);
//
//
//	return 0;
//}

//class A
//{
//public:
//	A()
//		: _a(0)
//	{
//		cout << "A():" << this << endl;
//	}
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p = (A*)malloc(sizeof(A));
//	//��ζ���Ƭ�ռ���г�ʼ��? ����ֻ��������һ��ռ䣬��û�д���������ô�������Ĺ��캯�����г�ʼ���أ�
//	//�����ʽ�ص��ù��캯���� 
//	//-> ��λnew, replacement-new,��ʽ���ù��캯����ʼ��
//	new(p)A;//������캯�����ξ͸��� new(p)A(3);
//
//	//�����д����൱��delete
//	//��������������ʽ����
//	p->~A();
//	operator delete(p);
//
//	//�����еȼ���A* p1 = new A;
//	A* p1 = (A*)operator new(sizeof(A)); //����ռ�
//	new(p1)A; //���ù��캯��
//
//	p1->~A();
//	operator delete(p1);
//
//	return 0;
//}

//// ����������x64�Ľ��̼���
//#include <iostream>
//using namespace std;
//int main()
//{
//	void* p = new char[0xfffffffful];
//	cout << "new:" << p << endl;
//	return 0;
//}
