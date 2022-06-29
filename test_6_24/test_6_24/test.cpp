#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

#include <iostream>
using namespace std;

//int main()
//{
//	cout << "hello world" << endl;
//
//	return 0;
//}

//namespace 定义的是一个域
//用于解决C语言命名冲突问题

//eg:命名冲突
//C语言的库中，有两个函数用scanf和strlen名称
//假设代码里，想用这两个名称命名变量，就会产生冲突
//int main()
//{
//	//定义不会报错，但用的时候会报错
//	int scanf = 10;
//	int strlen = 20;
//
//	//以下均会报错,且C语言解决不了冲突的问题
//	scanf("%d", &scanf);
//	printf("%d\n", scanf);
//	printf("%d\n", strlen);
//
//	return 0;
//}

////使用C++命名空间，进行名字的隔离
////1. 普通的命名空间
//namespace N1 // N1为命名空间的名称
//{
//	//命名空间中的内容，既可以定义变量，也可以定义函数
//	int scanf = 10;
//	int strlen = 20;
//
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//}
//
////2. 命名空间可以嵌套
//namespace N2
//{
//	int a;
//	int b;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//
//	namespace N3
//	{
//		int c;
//		int d;
//		int Sub(int left, int right)
//		{
//			return left - right;
//		}
//	}
//}
//
////3. 同一个工程中允许存在多个相同名称的命名空间,编译器最后会合成同一个命名空间中。
////注意：同一个域里不能定义同名的变量或函数
//namespace N1
//{
//	int Mul(int left, int right)
//	{
//		return left * right;
//	}
//}
//
//
//
//int main()
//{
//	//默认访问局部其次是全局
//	//由于局部没有，访问全局的头文件,所以此时打印的是库函数的地址
//	printf("%x\n", scanf);   //411433
//	printf("%x\n", strlen);  //4113d4
//
//	//指定访问N1命名空间
//	printf("%x\n", N1::scanf);   //a
//	printf("%x\n", N1::strlen);  //14
//	
//	//指定命名空间后，才能调用N1里的函数
//	int a = N1::Add(1, 2);
//	printf("%d\n", a); //3
//
//	//访问嵌套命名空间的内容
//	int b = N2::N3::Sub(5, 3);
//	printf("%d\n", b); //2
//
//	return 0;
//}

//#include <iostream>
////C++库为了防止命名冲突，把自己库里的东西都定义在了一个std的命名空间中
////要使用标准库中的东西，有三种方式
////1. 指定命名空间 
////   -> 缺陷: 麻烦，每个地方要用都要制定，但是这是最规范的使用方式
////2. 把std整个展开:using namespace std ,相当于库里的东西都到全局域了 
////   ->缺陷: 如果自己定义的和库冲突了就无法解决了
////   所以规范的工程项目中是不推荐这种方式的，日常练习无所谓
////3. 对部分常用的库里面的东西展开，是针对1和2折中的方案，在项目中经常使用
// using std::cout;
// using std::endl;
//
//
//
////using namespace std;
//
//int main()
//{
//	//1. 指定命名空间
//	std::cout << "hello world" << std::endl;
//
//	// 2.把std整个展开,上面写了using namespace std;下面直接用即可
//	cout << "hello world" << endl;
//
//	// 3.对部分常用的库里面的东西展开
//	cout << "hello world" << endl;
//	std::string s; //没展开的就不能直接使用
//
//	return 0;
//}

//#include<iostream>
//
////cout 是ostream类型全局对象
////cin  是istream类型全局对象
////endl 是全局的换行符号
//int main()
//{
//	std::cout << "hello world!" << std::endl;
//
//	//对比C语言printf和scanf区别是：
//	//可以自动识别类型
//	int a = 10;
//	int* p = &a;
//	//c语言打印
//	printf("%d,%p\n", a, p);
//	//c++打印
//	std::cout << a << "," << p << std::endl;
//
//	return 0;
//}

////缺省参数
//void TestFunc(int a = 0)
//{
//	cout << a << endl;
//}
//int main()
//{
//	TestFunc(); // 没有传参时，使用参数的默认值
//	TestFunc(10); // 传参时，使用指定的实参
//}

//void TestFunc(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
//void TestFunc(int a, int b = 10, int c = 20)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}


////C语言不允许定义同名函数
////C++可以 -> 函数重载 -> 参数(类型或个数或顺序)不同
//int Add(int left, int right)
//{
//	return left + right;
//}
//
//double Add(double left, double right)
//{
//	return left + right;
//}
//
//int main()
//{
//	cout << Add(1, 2) << endl;     //3
//	cout << Add(1.1, 2.2) << endl; //3.3
//
//	return 0;
//}

//short Add(short left, short right)
//{
//	return left + right;
//}
//int Add(int left, short right)
//{
//	return left + right;
//}

//int main()
//{
//	int a = 10;
//
//	//b是a的引用(别名)
//	//注意区分引用和取地址，引用是类型后&变量，取地址是直接&变量
//	int& b = a;
//	b = 20;
//
//	//继续取别名
//	int& c = b;
//	c = 30;
//
//	return 0;
//}

////引用的价值
////用别名就可以不用传地址进行交换
//void swap(int& r1, int& r2)
//{
//	int tmp = r1;
//	r1 = r2;
//	r2 = tmp;
//}
//
//void StackInit(struct Stack& s)
//{
//	//...
//}
//
//int main()
//{
//	int a = 1, b = 2;
//	swap(a, b); //c语言需要传地址
//
//	struct Stack st;
//	StackInit(st);
//
//	return 0;
//}

////权限可以缩小，但不能放大
//int main()
//{
//	const int a = 10;//用const修饰后，a只能读不能写
//	//int& ra = a;//报错，ra引用a属于权限放大(可读可写)
//	const int& ra = a; //正确代码
//
//	int b = 10;
//	int& rb = b;
//	const int& crb = b;//正确，ceb引用b属于权限的缩小，所以可以
//
//	int c = 10;
//	double d = 1.11;
//	d = c; //隐式类型转换，将int类型的c放到一个double类型的临时变量中，再赋值给d
//
//	//double& rc = c; //报错，报错原因并不是因为类型不同
//	const double& rc = c; //*正确代码，此时rc是c临时变量的别名，临时变量具有常性，所以加const就可以
//
//	return 0;
//}

//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}

//int& Count()
//{
//	static int n = 0;
//	n++;
//	// ...
//	return n;
//}

////传值返回 返回的是返回对象c的拷贝
//int Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//int main()
//{
//	//int& ret = Add(1, 2); //报错，因为ret接收的是储存c的值的临时变量(不是c)，具有常性，需在前加上const
//	const int& ret = Add(1, 2);
//	
//	return 0;
//}

////传引用返回 返回的是对象c的引用，其实就是c
////实际中，如果出了函数作用域，返回变量就不存在了，不能用引用返回;出了作用域还在:例如用static修饰
//int& Add(int a, int b)
//{
//	static int c = a + b;
//	return c;
//}
//
//int main()
//{
//	int& ret = Add(1, 2);
//	cout << ret << endl; //3
//
//	return 0;
//}

//#include <time.h>
//struct A { int a[10000]; };
//void TestFunc1(A a) {}
//void TestFunc2(A& a) {}
//void TestRefAndValue()
//{
//	A a;
//
//	// 以值作为函数参数
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//
//	// 以引用作为函数参数
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//
//	// 分别计算两个函数运行结束后的时间
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;  //11
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl; //1
//}


//#include <time.h>
//struct A { int a[10000]; };
//A a;
//// 值返回
//A TestFunc1() { return a; }
//// 引用返回
//A& TestFunc2() { return a; }
//void TestReturnByRefOrValue()
//{
//	// 以值作为函数的返回值类型
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc1();
//	size_t end1 = clock();
//	// 以引用作为函数的返回值类型
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//	// 计算两个函数运算完成之后的时间
//	cout << "TestFunc1 time:" << end1 - begin1 << endl;  //254
//	cout << "TestFunc2 time:" << end2 - begin2 << endl;  //2
//}
//int main()
//{
//	TestReturnByRefOrValue();
//
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int& ra = a;
//
//	cout << "&a = " << &a << endl;    //00B5FD7C
//	cout << "&ra = " << &ra << endl;  //00B5FD7C
//
//	return 0;
//}

//int main()
//{
//	int a = 10;
//
//	//在语法上，给a的这块空间取了个别名，没有新开空间
//	int& ra = a;
//	ra = 20;
//
//	//在语法上，定义了一个pa指针变量,开辟了4个字节，存储a的地址
//	int* pa = &a;
//	*pa = 20;
//
//	return 0;
//}

//ADD的宏函数
//#define ADD(int x, int y) return x+y  //典型错误写法
//#define ADD(x, y) (x)+(y);  //典型错误写法,加了分号
//标准写法
//#define ADD(x, y) ((x) + (y))


////C++推荐将频繁调用的小函数，定义成inline(内联)，会在调用的地方展开。没有栈帧的开销
//inline int Add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	int c = Add(1, 2);
//	cout << c << endl;
//
//	return 0;
//}

//#include <map>
//#include <string>
////以下语法,当前了解即可
////auto
//int main()
//{
//	int a = 10;
//	//int b = a;
//	auto b = a; //类型声明成auto，可以根据a的类型自动推导b的类型为int
//
//	map<string, string> m;
//	//map<string, string>::iterator it = m.begin();
//	//这里可以根据m.begin()自动推导到it的类型是map<string, string>::iterator
//	//这样写比较简洁
//	auto it = m.begin();
//
//	return 0;
//}

//int main()
//{
//	int x = 10;
//	auto a = &x;    //a的类型是int*
//	auto* b = &x;   //这里明确说明是指针,b的类型是int*
//	
//	int& y = x;     //y的类型是int
//	auto& c = y;    //y是x的别名，y的类型是int。c的类型是int
//
//	auto& d = x;    //d的类型是int,但此处指定了d是x的引用
//
//	//打印变量的类型
//	cout << typeid(x).name() << endl;   //int
//	cout << typeid(y).name() << endl;   //int
//	cout << typeid(a).name() << endl;   //int*
//	cout << typeid(b).name() << endl;   //int*
//	cout << typeid(c).name() << endl;   //int
//	cout << typeid(d).name() << endl;   //int
//	  
//	return 0;
//}

//void TestAuto()
//{
//	auto a = 1, b = 2;
//	auto c = 3, d = 4.0; // 该行代码会编译失败，因为c和d的初始化表达式类型不同
//}

//int main()
//{
//	int array[] = { 1, 2, 3, 4, 5 };
//	//以前遍历数组的方式
//	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
//		cout << array[i] << " ";
//	cout << endl;
//	// 1 2 3 4 5 
//	
//	//范围for，更简单，数组也可以直接遍历
//	//自动遍历，以此取出array中的元素，赋值给e，直到结束
//	for (auto e : array)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	//1 2 3 4 5 
//
//	//以上是"读"的操作，"写"的操作需要注意加引用符号
//	for (auto& ee : array) //ee是数组元素的临时拷贝，要想修改数组需要加引用符号
//	{
//		ee *= 2;
//	}
//
//	return 0;
//}
//
//void TestFor(int array[])
//{
//	for (auto& e : array)
//		cout << e << endl;
//}

////C++11
//int main()
//{
//	//以前使用的
//	int* p1 = NULL;
//
//	//C++推荐使用的
//	int* p2 = nullptr;
//
//	return 0;
//}

//void f(int i)
//{
//	cout << "f(int)" << endl;
//}
//void f(int* p)
//{
//	cout << "f(int*)" << endl;
//}
//int main()
//{
//	f(0);         //期望匹配整形参数的f，结果:f(int)
//	f(NULL);      //期望匹配指针参数的f，结果:f(int),因为NULL被替换成0了
//	f((int*)NULL);//f(int*)
//	f(nullptr);   //f(int*)
//
//	return 0;
//}