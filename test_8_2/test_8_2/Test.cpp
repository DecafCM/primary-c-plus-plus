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
//	char char2[] = "abcd";  //char2是一个数组，所以在栈上，*char2也在栈上
//	char* pChar3 = "abcd";  //pChar3是一个局部变量的指针，在栈上。该指针存的常量区的地址，所以*pChar3在常量区
//	int* ptr1 = (int*)malloc(sizeof(int) * 4);//同理，ptr1在栈上，*ptr1在堆上
//	int* ptr2 = (int*)calloc(4, sizeof(int));
//	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
//	free(ptr1);
//	free(ptr3);
//}
//
////1. 选择题：
////选项 : A.栈 B.堆 C.数据段(静态区) D.代码段(常量区)
////globalVar在哪里？____ staticGlobalVar在哪里？____
////staticVar在哪里？____ localVar在哪里？____
////num1 在哪里？____
////
//// CCCAA
//// 
////char2在哪里？____ * char2在哪里？___
////pChar3在哪里？____ * pChar3在哪里？____
////ptr1在哪里？____ * ptr1在哪里？____
////2. 填空题：
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
//	// 这里需要free(p2)吗？
//	free(p3);
//}

//int main()
//{
//	//new/delete和malloc/free针对内置类型没有任何差别，只是用法不一样
//
//	//C语言动态申请空间
//	int* p1 = (int*)malloc(sizeof(int) * 10); 
//	free(p1);
//
//	//C++动态申请空间
//	//new/delete new[]/delete[]一定要匹配使用，否则可能会出错
//	int* p2 = new int[10];//申请多个对象
//	int* p3 = new int;    //申请单个对象
//
//	delete[] p2;
//	delete p3;
//
//	return 0;
//}

//struct ListNode
//{
//	//struct ListNode* _next; //C 结构体
//
//	//类
//	ListNode* _next;
//	ListNode* _prev;
//	int _val;
//
//	//构造函数
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
//	//C malloc只是开空间,free仅仅是释放空间
//	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	//有了构造函数后n1里的数据还是随机值，而n2已经被初始化了
//	free(n1);
//
//	//C++ 
//	//new    针对自定义类型，开空间 + 调用构造函数初始化
//	//delete 针对自定义类型，调用析构函数清理 + 释放空间
//	ListNode* n2 = new ListNode; //new + 类型
//	delete n2;
//
//	//如果想让val为其他值还可以
//	ListNode* n3 = new ListNode(5); //相当于代替了c语言中的BuyListNode(5)
//	delete n3;
//
//	//C语言申请多个对象
//	struct ListNode* arr3 = (struct ListNode*)malloc(sizeof(struct ListNode) * 4);
//	free(arr3);
//
//	//C++申请多个对象
//	ListNode* arr4 = new ListNode[4]; //调用了4次构造函数 不支持ListNode* arr4 = new ListNode[4](5)这样赋值
//	//C++11支持ListNode* arr4 = new ListNode[4]{1,2,3};arr[3]初始化为0
//
//	delete[] arr4; //调用4次析构函数
//
//	int* p1 = new int(0);
//	int* p2 = new int[4]{ 1,2,3,4 };
//
//	return 0;
//}

////mallloc 最大能申请多大空间？
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
//	//构造函数
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
//	//在用法上operator new/delete和malloc/free是完全一样的，都是在堆上申请和释放空间
//	//但它们失败后的处理方式不一样，malloc失败后返回NULL，operator new失败后抛异常
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
//	//在类中重载专属的operator new
//	//
//	void* operator new(size_t n)
//	{
//		void* p = nullptr;
//		p = allocator<ListNode>().allocate(1); //STL中的空间配置器，其实就是一个简单的内存池
//		cout << "memory pool allocate" << endl;
//		return p;
//	}
//	void operator delete(void* p)
//	{
//		allocator<ListNode>().deallocate((ListNode*)p, 1);
//		cout << "memory pool deallocate" << endl;
//	}
//
//	//构造函数
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
//	//如何对这片空间进行初始化? 这里只是申请了一块空间，并没有创建对象，怎么调用它的构造函数进行初始化呢？
//	//如何显式地调用构造函数？ 
//	//-> 定位new, replacement-new,显式调用构造函数初始化
//	new(p)A;//如果构造函数带参就给参 new(p)A(3);
//
//	//这两行代码相当于delete
//	//析构函数可以显式调用
//	p->~A();
//	operator delete(p);
//
//	//这两行等价于A* p1 = new A;
//	A* p1 = (A*)operator new(sizeof(A)); //申请空间
//	new(p1)A; //调用构造函数
//
//	p1->~A();
//	operator delete(p1);
//
//	return 0;
//}

//// 将程序编译成x64的进程即可
//#include <iostream>
//using namespace std;
//int main()
//{
//	void* p = new char[0xfffffffful];
//	cout << "new:" << p << endl;
//	return 0;
//}
