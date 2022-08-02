#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//bool operator==(const Date& d) //这样保护了d,却没保护*this指针,但this指针又是隐含的，怎么样保护呢？
//	
//	//const加在后面，修饰的就是*this，好处在于:函数中不小心改变的成员变量，在编译时会被检查出来
//	bool operator==(const Date& d) const  
//	{
//		return (_year == d._year)
//			&& (_month == d._month)
//			&& (_day == d._day);
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
//	Date d1(2022, 7, 31);
//	Date d2(2022, 8, 31);
//
//	d1 == d2;
//	d1.Print();
//
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//取地址运算符的重载
//	//了解即可，基本没有被重载的价值
//	Date* operator&()
//	{
//		return this;
//	}
//
//	const Date* operator&() const 
//	{
//		return this;
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
//	Date d1(2022, 7, 31);
//	const Date d2(2022, 8, 31);
//
//	&d1;
//	&d2;
//
//	return 0;
//}

//class Date
//{
//	//友元函数的声明
//	friend ostream& operator<<(ostream& out, const Date& d);
//	friend istream& operator>>(istream& in,Date& d);
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
////cout << d1
////但放到类外面，访问类的私有成员就会被限制，所以引入友元
//ostream& operator<<(ostream& out, const Date& d) //void operator<<(Date *this, ostream& out)
//{
//	out << d._year << "-" << d._month << "-" << d._day << endl;
//	return out;
//}
//
//istream& operator>>(istream& in, Date& d) //void operator<<(Date *this, ostream& out)
//{
//	in >> d._year >> d._month >> d._day;
//
//	return in;
//}
//
//int main()
//{
//	Date d1(2022, 7, 31);
//	Date d2(2022, 8, 1);
//	cout << d1 << d2;
//	cin >> d1 >> d2;
//	cout << d1 << d2;
//	return 0;
//}

//class Date; // 前置声明
//class Time
//{
//	friend class Date; // 声明日期类为时间类的友元类，则在日期类中就直接访问Time类中的私有成员变量
//public:
//	Time(int hour = 0, int minute = 0, int second = 0)
//		: _hour(hour)
//		, _minute(minute)
//		, _second(second)
//	{}
//
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{
//		_t._hour = 1;
//	}
//
//	void SetTimeOfDate(int hour, int minute, int second)
//	{
//		// 直接访问时间类私有的成员变量
//		_t._hour = hour;
//		_t._minute = minute;
//		_t._second = second;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};

//int main()
//{
//	return 0;
//}


//class Date
//{
//public:
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//class Date
//{
//public:
//	Date(int year, int month, int day)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//class A
//{
//public:
//	A(int x)
//	{
//		_x = x;
//	}
//private:
//	int _x;
//};
//
//class Date
//{
//public:
//	//*可以理解为:一个对象的单个成员变量，初始化列表是他定义的阶段
//	Date(int year = 0, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _n(10)
//		, _ref(year)
//		, _a(1)
//	{
//		_day = day;
//		//_n = 1;   //报错,必须使用初始化列表初始化
//		//_ref = 2; //报错，引用类型必须用初始化列表初始化
//	}
//
//
//private:
//	//这里仅仅是成员变量的声明，而不是成员变量的定义
//	int _year;
//	int _month;
//	int _day;
//	
//	//他们必须在定义的时候初始化，所以只能用初始化列表初始化
//	const int _n; //const修饰的类型
//	int& _ref;    //引用类型
//	A _a;         //没有默认构造函数的自定义类型
//};

//class Time
//{
//public:
//	Time(int hour = 0)
//		:_hour(hour)
//	{}
//
//private:
//	int _hour;
//};
//
//class Date
//{
//public:
//	////自定义类型，使用初始化列表 -> 调用了Time类的构造函数
//	//Date(int day, int hour)
//	//	: _t(hour)
//	//{}
//
//	//自定义类型，不使用初始化列表 -> 调用Time类构造函数 + 赋值
//	Date(int day, int hour)
//	{
//		//函数体内初始化
//		Time t(hour);
//		_t = t;
//	}
//
//private:
//	int _day;
//	Time _t;
//};
//int main()
//{
//	Date d(12, 12);
//}

//class A
//{
//public:
//	A(int a)
//		:_a1(a)
//		, _a2(_a1)
//	{}
//
//	void Print() {
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	//_a2先声明，所以先运行_a2(_a1) -> _a2是随机值
//	int _a2;
//	int _a1;
//};
//
//int main() 
//{
//	A aa(1);
//	aa.Print();
//}
//
////A.输出1 1
////B.程序崩溃
////C.编译不通过
////D.输出1 随机值 正确答案

//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{}
//private:
//	int _a;
//};
//
//int main()
//{
//	//初始化的几种方式
//	A aa1(1); //正常初始化
//	A aa2(aa1); //拷贝构造
//
//	//单参数的构造函数，支持隐式类型转换
//	A aa3 = 2; 
//	//早期编译器：A tmp(2) -> A aa2(tmp) 即:构造+拷贝构造
//	//现在编译器优化:直接调用拷贝构造
//	//如果在构造函数前加 explicit，隐式类型转换就发生不了了
//
//
//	//eg:
//	int i = 0;
//	double d = i; //隐式类型转换
//}

////计算程序中A定义了多少个对象出来
//class A
//{
//public:
//	//构造
//	A()
//	{
//		++_n;
//	}
//	//拷贝构造
//	A(const A& a)
//	{
//		++_n;
//	}
//
//	int GetN()
//	{
//		return _n;
//	}
//
//private:
//	//只是声明 , _n不在构造函数初始化，在类的外面，全局的位置初始化
//	static int _n; //n是存在静态区的，属于整个类，也属于类的所有对象
//};
//
////静态成员变量的定义初始化
//int A::_n = 0;
//
//void f(A a)
//{
//
//}
//
//int main()
//{
//	A a1;
//	A a2;
//	A();
//	f(a1);
//
//	//cout << A::_n << endl; //_n属于public可以这样用
//	//cout << a1._n << endl; //_n属于public可以这样用
//	//cout << A()._n << endl; //_n属于public可以这样用
//	
//	cout << a1.GetN()  << endl; //4
//	cout << A().GetN() << endl; //5
//
//
//	return 0;
//}

//class B
//{
//public:
//	B(int x = 0)
//		:_x(x)
//	{
//
//	}
//	int _x;
//};
//
//class A 
//{
//public:
//	A(int a = 1, int* p = nullptr)
//		:_a(a)
//		, _p(p)
//	{}
//private:
//	//这里只是声明没有开空间的 -> 缺省值，如果构造函数没有对这其进行初始化，则用缺省值初始化
//	int _a = 0;         //初始化列表初始化后_a = 1
//	int* _p = nullptr;  //初始化列表初始化
//
//	//BUG级的玩法，用函数来给缺省值
//	int* _arr = (int*)malloc(sizeof(int) * 10); //_arr初始化列表里没给值，用这里的缺省值malloc初始化
//
//	B _b = 6;//_b = 6,调用_b的拷贝构造
//	
//	//静态成员不能在这里给值
//	//static int n = 0;
//};
//
//int main()
//{
//	A aa; //调用默认构造函数
//
//	return 0;
//}

//class A
//{
//public:
//	class B //B天生就是A的友元类
//	{
//	public:
//		void foo(const A& a)
//		{
//			//B中可直接访问A的元素
//			cout << a._a << endl;   //1
//			cout << a._p << endl;   //00000000
//			cout << A::_n << endl;//0，用cout << _n << endl;不加类名也可
//		}
//	};
//
//	A(int a = 1, int* p = nullptr)
//		:_a(a)
//		, _p(p)
//	{}
//private:
//	
//	int _a = 0;         
//	int* _p = nullptr;  
//
//	int* _arr = (int*)malloc(sizeof(int) * 10); 
//
//	static int _n;
//};
//
//int A::_n = 0;
//
//int main()
//{
//	A aa;
//	A::B cc;
//
//	cc.foo(aa);
//
//	return 0;
//}