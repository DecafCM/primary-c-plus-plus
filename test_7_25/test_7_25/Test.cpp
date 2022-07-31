#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

////C语言定义栈
//typedef int STDataType;
////数据
//struct Stack
//{
//	STDataType* a;
//	int size;
//	int capacity;
//};
////方法 -- 数据和方法是分离的，重点关注的是过程 -> 函数方法
//void StackPush(struct Stack* ps, STDataType x);

////C++
////类 -- 定义出一个新的类型
////类由两部分构成：1、成员变量(属性) 2、成员函数 (做的行为)
////C++中的struct兼容C的所有用法，同时C++中把struct升级成类
//typedef int STDataType;
//struct Stack
//{
//	//属性
//	STDataType* a;
//	int size;
//	int capacity;
//
//	//方法
//	void Init(int initSize = 4)
//	{
//		a = (STDataType*)malloc(sizeof(STDataType) * initSize);
//		size = 0;
//		capacity = initSize;
//	}
//
//	void Push(STDataType x)
//	{
//		//...增容
//		a[size] = x;
//		size++;
//	}
//
//	//...其余接口
//};
//
//int main()
//{
//	//C++中类名就是可以当做类型直接用 不用写struct Stack st
//	Stack st;
//
//	st.Init();
//	st.Push(1);
//	st.Push(2);
//	st.Push(3);
//
//	return 0;
//}

//class className
//{
//	//类体：由成员函数和成员变量组成
//
//}; //一定要注意后面的分号

////声明和定义全部放在类体中
//class Person
//{
//public:
//	//显示基本信息
//	void showInfo()
//	{
//		cout << _name << "-" << _sex << "-" << _age << endl;
//	}
//public:
//	char* _name; //姓名
//	char* _sex;  //性别
//	int _age;    //年龄
//};

////声明放在.h文件中，类的定义放在.cpp中
////声明放在类的头文件person.h中
//class Person
//{
//public:
//	//显示基本信息
//	void showInfo();
//public:
//	char* _name; //姓名
//	char* _sex;  //性别
//	int _age;    //年龄
//};
//
////定义放在类的实现文件person.cpp中
//#include <person.h>
//
////显示基本信息
//void Person::showInfo() //类{}内是一个域，使用时需要指明是哪个域的
//{
//	cout << _name << "-" << _sex << "-" << _age << endl;
//}

//class Person
//{
//public:
//	void PrintPersonInfo();
//private:
//	char _name[20];
//	char _gender[3];
//	int _age;
//};
//// 这里需要指定PrintPersonInfo是属于Person这个类域
//void Person::PrintPersonInfo()
//{
//	cout << _name << " "<<_gender << " " << _age << endl;
//}

//typedef int STDataType;
//struct Stack
//{
//	//属性
//	STDataType* a;
//	int size;
//	int capacity;
//
//	//方法
//	void Init(int initSize = 4)
//	{
//		a = (STDataType*)malloc(sizeof(STDataType) * initSize);
//		size = 0;
//		capacity = initSize;
//	}
//
//	void Push(STDataType x)
//	{
//		//...增容
//		a[size] = x;
//		size++;
//	}
//
//	//...其余接口
//};
//
//int main()
//{
//	//类的实例化
//	Stack st;
//
//	st.Init();
//	st.Push(1);
//	st.Push(2);
//	st.Push(3);
//
//	//类的实例化
//	Stack s1;
//	Stack s2;
//
//	cout << sizeof(s1) << endl; //12
//	cout << sizeof(s2) << endl; //12
//
//	return 0;
//}

//class A
//{
//public:
//	void PrintA()
//	{
//		cout << _a << endl;
//	}
//private:
//	char _a;
//};

//// 类中既有成员变量，又有成员函数
//class A1 {
//public:
//	void f1() {}
//private:
//	int _a;
//};
//// 类中仅有成员函数
//class A2 {
//public:
//	void f2() {}
//};
//// 类中什么都没有---空类
//class A3
//{};
//
//int main()
//{
//	
//	cout << sizeof(A1) << endl; //4
//	//A2 a2;
//	cout << sizeof(A2) << endl; //1
//	//A3 a3;
//	cout << sizeof(A3) << endl; //1
//
//	return 0;
//}

//class Date
//{
//public:
//	//隐含的this指针：
//	//*编译器会增加一个隐含的参数:void Init(Date* this, int year, int month, int day)
//	//1.this指针是隐含的、编译器编译时加的，我们不能自己在调用和函数定义中加上
//	//2.可以在成员函数中使用this指针
//	//3.this一般是存在栈上的
//	
//	void Init(int year, int month, int day)
//	{
//		//封装的好处在于可以先检查输入数据的合法性
//		//...
//
//		//year = year; //这样会分不清谁初始化的谁,并且实际上两个year都是函数里的year(就近原则)
//		//Date::year = year;//可行但麻烦
//		
//		//命名区分以后
//		_year = year;
//		_month = month;
//		_day = day;
//		/*//编译器会自动处理成：
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;*/
//
//	}
//
//private:
//	//凡是成员变量，建议命名风格区分一下
//	int _year;
//	int _month;
//	int _day;
//
//	//其他命名风格
//	//int year_;
//	//int m_year;
//	//int mYear;
//};
//
//int main()
//{
//	Date d1;
//	//如何对d1进行初始化？ d1._year = 2022 报错
//	d1.Init(2022, 7, 25);
//
//	Date d2;
//	d1.Init(2022, 7, 26);
//
//	//*问题来了，d1和d2调用的是同一个函数，该函数是怎么知道使用的哪个对象呢？
//	//调用d1.Init时候，实际调用的是d1.Init(&d1, 2021, 5, 24),即传入了对象的地址
//
//	//结论：哪个对象去调用成员函数，成员函数中访问的就是哪个对象中的成员变量，通过this指针做到
//
//	return 0;
//}

//// 腾讯面试题
//// 1.下面程序能编译通过吗？
//// 2.下面程序会崩溃吗？在哪里崩溃
//class A
//{
//public:
//	void PrintA()
//	{
//		cout << _a << endl;
//	}
//
//	void Show()
//	{
//		cout << "Show()" << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p = nullptr;
//	//p->PrintA(); //崩溃，空指针的访问
//	p->Show();   //正常运行
//
//	//未报错的原因：
//	//p—>Show()、p—>PrintA()函数，可以进入函数内部运行的原因是没有对p进行解引用操作
//	//因为Show等成员函数的地址没有存到对象里，所以不会引发空指针访问的崩溃
//
//	//进入函数内部
//	//p->PrintA()和p->Show()只是把空指针p传给了PrintA()和p->Show()
//	//此时两个成员函数接受到的this是空指针
//	//而PrintA对空指针进行了解引用(this->_a)操作所以崩溃，p->Show()没有，所以正常运行
//
//}

//类里面成员函数什么都不写时，编译器会自动生成6个函数，这6个函数叫做默认(缺省)成员函数

////1、构造函数 -->对象的初始化
//class Date
//{
//public:
//	//构造函数顶替的是Init函数
//	//这里写Init时，我们可能会在调用时忘记它，即没有进行初始化调用其他函数
//	//C++为了解决这个问题，引入了构造函数，来进行初始化
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//构造函数 -> 对象实例化的时候自动调用，这样保证对象一定初始化
//	//Date(int year, int month, int day)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//
//	////重载，传参的个数或类型不同
//	//Date()
//	//{
//	//	_year = 0;
//	//	_month = 1;
//	//	_day = 1;
//	//}
//
//	//一般情况，对象初始化惯例都分两种，默认初始化和给定值初始化
//	//把上面两个代码合二为一，定义一个全缺省的Date，很好用
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//class Stack
//{
//public:
//	void Init()
//	{
//		_a = nullptr;
//		_size = _capacity = 0;
//	}
//
//	//构造函数
//	Stack()
//	{
//		_a = nullptr;
//		_size = _capacity = 0;
//	}
//
//	//重载
//	Stack(int capacity)
//	{
//		_a = (int*)malloc(sizeof(int) * capacity);
//		_size = 0;
//		_capacity = capacity;
//	}
//	//合二为一
//	Stack(int capacity = 4)
//	{
//		if (capacity == 0)
//		{
//			_a = nullptr;
//			_size = _capacity = 0;
//		}
//		else
//		{
//			_a = (int*)malloc(sizeof(int) * capacity);
//			_size = 0;
//			_capacity = capacity;
//		}
//	}
//
//	void Push(int x)
//	{
//		//...
//	}
//private:
//	int* _a;
//	int _size;
//	int _capacity;
//};
//
//int main()
//{
//	Date d1(2022, 7, 25);//注意调用构造函数，在对象后面加参数
//	d1.Print(); //2022-7-25
//
//	//重载
//	Date d2;
//	// 注意：如果通过无参构造函数创建对象时，对象后面不用跟括号，否则就成了函数声明
//	d2.Print(); //0-1-1
//
//	/*Stack st;
//	st.Push(1);*/ //忘记调用Init进行初始化，出问题
//	
//	Stack st1;
//	st1.Push(1);
//
//	//重载
//	Stack st2 (4);
//
//	return 0;
//}

//class A
//{
//public:
//	//构造函数
//	A(int a = 0)
//	{
//		_a = a;
//	}
//
//	void Print()
//	{
//		cout << _a << endl;
//	}
//private:
//	int _a;
//};
//
//class Date
//{
//public:
//	//我们不写，编译器会生成一个构造函数，自己写了编译器就不会生成，所以构造函数叫默认成员函数
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//		//cout << _aa._a << endl; //这样无法访问_a,因为a是私有的,如何访问呢?
//		_aa.Print(); //0
//	}
//private:
//	//内置类型(基本类型):语言原生定义的类型如int、char、double等、指针，不会初始化
//	int _year;
//	int _month;
//	int _day;
//
//	//自定义类型:使用class、struct等定义的类型，编译器会调用他们的默认构造函数进行初始化
//	A _aa;
//};
//
//int main()
//{
//	Date d1;
//	d1.Print();
//	//-858993460--858993460--858993460 内置类型不初始化
//	//0 自定义类型调用默认构造函数初始化
//
//	return 0;
//}

//class A
//{
//public:
//	//构造函数
//	A(int a = 0)
//	{
//		_a = a;
//	}
//
//	void Print()
//	{
//		cout << _a << endl;
//	}
//private:
//	int _a;
//};
//
//class Date
//{
//public:
//	//我们不写，编译器会生成一个构造函数，自己写了编译器就不会生成，所以构造函数叫默认成员函数
//
//	/*Date()
//	{
//		_year = 0;
//		_month = 1;
//		_day = 1;
//	}*/
//	
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	
//	
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	//内置类型(基本类型):语言原生定义的类型如int、char、double等、指针，不会初始化
//	int _year;
//	int _month;
//	int _day;
//};
//
////很多人认为默认构造函数是，自己不写，编译器默认生成的函数，这个理解是不全面的
////1.我们不写，编译器默认生成
////2.我们自己写的无参的
////3.我们写的全缺省
//
////总结:不用传参就可以调用的构造函数
//int main()
//{
//	Date d1;
//	d1.Print();
//	//0-1-1
//
//	return 0;
//}

//class Date
//{
//public:
//
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//析构函数
//	~Date()
//	{
//		//资源的清理
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//class Stack
//{
//public:
//	Stack(int capacity = 4)
//	{
//		_a = (int*)malloc(sizeof(int) * capacity);
//		_size = 0;
//		_capacity = capacity;
//	}
//
//	void Push(int x)
//	{
//		//...
//	}
//
//	//析构函数 -> 清理资源
//	~Stack()
//	{
//		free(_a);
//		_a = nullptr;
//		_size = _capacity = 0;
//	}
//
//private:
//	int* _a;
//	int _size;
//	int _capacity;
//};
//
//int main()
//{
//	Stack st;
//	
//	st.Push(1);
//	st.Push(1);
//	st.Push(1);
//
//	//不需要手动销毁开辟的空间了，因为析构函数会默认执行
//
//	Stack st2;
//	st2.Push(2);
//	st2.Push(2);
//	st2.Push(2);
//
//	//问题：有多个对象时，谁先析构？ -> st2先
//
//	return 0;
//}

//class Date
//{
//public:
//
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//析构函数
//	~Date()
//	{
//		//资源的清理
//	}
//
//	//传统方法比较日期大小
//	bool Equel(Date d)
//	{
//		return _year == d._year
//			&& _month == d._month
//			&& _day == d._day;
//	}
//
//	//运算符重载
//	bool operator== (Date x)
//	{
//		return _day == x._day
//			&& _month == x._month
//			&& _year == x._year;
//	}
//
//	//当运算符是两个操作数时，第一个参数是左操作数，第二个参数是右操作数
//	//d1 < d2 => d1传给了this, d2传给了x
//	bool operator< (Date x)
//	{
//		if (_year < x._year)
//		{
//			return true;
//		}
//		else if (_year == x._year)
//		{
//			if (_month < x._month)
//			{
//				return true;
//			}
//			else if (_month == _month)
//			{
//				if (_day < x._day)
//					return true;
//			}
//		}
//
//		return false;
//	}
//
//	//d1 - 100
//	Date operator-(int day)
//	{}
//
//	//d1 + 100
//	Date operator+(int day)
//	{}
//
//	//d1 - d2
//	int operator-(Date d)
//	{}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//class Array
//{
//public:
//	Array()
//	{
//		for (int i = 0; i < 10; i++)
//		{
//			_a[i] = i * 10;
//		}
//	}
//
//	int& operator[](size_t pos) //加引用不仅仅能减少拷贝
//	{
//		return _a[pos];
//	}
//
//private:
//	int _a[10];
//};
//
//int main()
//{
//	Date d1(2022, 7, 26);
//	Date d2(2022, 7, 27);
//	//如何判断两个对象日期是否相等？
//	//传统方法：
//	cout << d1.Equel(d2) << endl; //0
//
//	//能否用 d1 == d2; d1 < d2; d1 > d2来判断大小？
//	//内置类型，语言层面支持运算符
//	//自定义类型默认不支持 => C++可以用运算符重载来让类对象支持用某个运算符
//
//	//本来应该这样调用: operator==(d1, d2);
//	//当编译器看到自定义类型d1和运算符==，会去检查有没有对这个运算符进行重载，如果有就会调用该函数
//	//d1.operator == (d2); //等价于d1.operator == (&d1, d2);
//	d1 == d2; //等价于d1.operator == (&d1, d2);
//
//	cout << (d1 == d2) << endl; //注意: <<优先级高于<，所以必须加括号
//	cout << (d1 < d2) << endl;
//
//	//还可以实现日期+日期，日期+天数，日期-日期
//	//cout << (d1 + 100) << endl;
//	//cout << (d1 - 100) << endl;
//	//cout << (d1 - d2) << endl;
//
//	//重载 []运算符
//	Array ay;
//	cout << ay[0] << endl; //0  //ay[0]等价于ay.operator[](&ay, 0);
//	cout << ay[1] << endl; //10
//	cout << ay[2] << endl; //20
//
//	//加引用后可对ay进行修改 => 赋值给了返回对象的别名
//	ay[0] = 100; //把100赋值给operator[]返回值的别名
//	ay[1] = 200;
//	ay[2] = 300;
//
//	cout << ay[0] << endl; //100
//	cout << ay[1] << endl; //200
//	cout << ay[2] << endl; //300
//
//	return 0;
//}

//class Date
//{
//public:
//
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}

//	//拷贝构造函数
//	//Date d4(d1),d4传给this，d1传给d
//	//为什么用引用传参？ => 没有引用传参会无限调用拷贝构造 Date d2(d1) -> d1传值给Date (Date d)中的d
//	// -> Date d(d1) -> 无限调用。
//	//即：调用拷贝构造函数，要先传参，传参如果使用的传值，又会变成拷贝构造,循环往复
//	//使用引用传参后，把参数d1传到了Date(Date& d)这里是，不是在调用拷贝构造函数，可以顺利的把d2传给this，d1传给d
//	Date(Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	void Print()
//	{
//
//	}
//
//	//析构函数
//	~Date()
//	{
//		//资源的清理
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//class Stack
//{
//public:
//	Stack(int capacity = 4)
//	{
//		_a = (int*)malloc(sizeof(int) * capacity);
//		_size = 0;
//		_capacity = capacity;
//	}
//
//	void Push(int x)
//	{
//		//...
//	}
//
//	//析构函数 -> 清理资源
//	~Stack()
//	{
//		free(_a);
//		_a = nullptr;
//		_size = _capacity = 0;
//	}
//
//private:
//	int* _a;
//	int _size;
//	int _capacity;
//}; 
//
//int main()
//{
//	Date d1(2022, 7, 26);
//
//	//如何让对象d2拥有d1的日期?
//	Date d2(d1); //拷贝构造函数
//
//	return 0;
//}

//class Date
//{
//public:
//
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//拷贝构造函数
//	//Date d4(d1),d4传给this，d1传给d
//	//为什么用引用传参？ => 没有引用传参会无限调用拷贝构造 Date d(d1) 
//	//   -> 传值是一种拷贝行为，即把d1的拷贝赋值给d 即:Date d(d1)->继续触发拷贝构造函数
//	//   -> Date d(d1) -> 无限调用。
//	//即：调用拷贝构造函数，要先传参，如果使用的传值，又会变成拷贝构造,循环往复
//	//使用引用传参后，把参数d1传到了Date(Date& d)这里是，不是在调用拷贝构造函数，可以顺利的把d2传给this，d1传给d
//	//推荐用Date(const Date& d)，防止写反了,把拷贝对象本身修改了的情况
//	/*Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}*/
//
//	//自己不写拷贝构造函数，编译器也会自动生成
//	//该拷贝构造比较特殊，对内置类型会完成浅拷贝，或者叫值拷贝
//
//	//析构函数
//	~Date()
//	{
//		//资源的清理
//	}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2022, 7, 26);
//
//	//如何让对象d2拥有d1的日期?
//	Date d2(d1); //拷贝构造函数
//	d2.Print();
//	d1.Print();
//
//	return 0;
//}

//class Stack
//{
//public:
//	Stack(int capacity = 4)
//	{
//		_a = (int*)malloc(sizeof(int) * capacity);
//		_size = 0;
//		_capacity = capacity;
//	}
//
//	void Push(int x)
//	{
//		//...
//	}
//
//	//析构函数 -> 清理资源
//	~Stack()
//	{
//		free(_a);
//		_a = nullptr;
//		_size = _capacity = 0;
//	}
//
//private:
//	int* _a;
//	int _size;
//	int _capacity;
//}; 
//
//int main()
//{
//	Stack st1;
//	Stack copy(st1);//报错
//
//	//错误原因:
//	//1. 由于拷贝的_a和原对象的_a指针指向同一块空间，在调用析构函数时，这块空间被free了两次
//	//2.其中一个对象插入删除数据，都会导致另一个对象也插入删除数据(因为用的同一块空间)
//
//	return 0;
//}

//class Date
//{
//public:
//
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//1.返回值void无法处理连续赋值的情况 d1 = d2 = d3，=>先 d2 = d3 -> d1 = d2，需要返回d2才能赋值给d1
//	//2.Date operator=(const Date& d)这样返回一个对象会调用拷贝构造函数(注意返回传引用的前提：出了函数作用域他还在，就可以，d2在该函数的生命周期外面)
//	//d2 = d1;  => d2.operator=(d1)
//	//赋值运算符也是一个默认成员函数，我们不写，编译器会自动生成
//	//编译器默认生成赋值运算符跟拷贝构造的特性是一致的
//	//1.针对内置类型会完成浅拷贝，像Date类不需要写赋值运算符重载，但Stack需要
//	//2.对于自定义类型，会调用它的赋值运算符重载完成拷贝
//
//	Date& operator=(const Date& d) //Date operator=(Date* this, const Date& d)
//	{
//		if (this != &d) //检查如果不是自己给自己赋值，才需要拷贝
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//
//		return *this;
//	}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2022, 7, 27);
//	Date d2;
//
//	d1.Print(); //2022 - 7 - 27
//	d2.Print(); //0-1-1
//
//	//这也是拷贝行为，但和拷贝构造的区别在于，拷贝构造是创建一个对象的时候，拿同类对象初始化
//	//这里的拷贝是，两个对象都已经存在了，想把一个对象拷贝给另一个对象。
//	d2 = d1;
//	d1.Print(); //2022 - 7 - 27
//	d2.Print(); //2022 - 7 - 27
//
//	Date d3;
//
//	//连续赋值
//	d1 = d2 = d3;
//	d1.Print(); //0-1-1
//	d2.Print(); //0-1-1 
//	d3.Print(); //0-1-1
//
//	Date d4(d1); //拷贝构造
//	d2 = d1;     //赋值重载
//	//这是拷贝构造还是重载？
//	Date d5 = d1; //拷贝构造
//	//因为赋值重载是两个已经存在的对象，进行拷贝操作
//	//拷贝构造是用一个已经存在的对象去初始化另一个创建的对象
//
//	return 0;
//}