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
//	//bool operator==(const Date& d) //����������d,ȴû����*thisָ��,��thisָ�����������ģ���ô�������أ�
//	
//	//const���ں��棬���εľ���*this���ô�����:�����в�С�ĸı�ĳ�Ա�������ڱ���ʱ�ᱻ������
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
//	//ȡ��ַ�����������
//	//�˽⼴�ɣ�����û�б����صļ�ֵ
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
//	//��Ԫ����������
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
////���ŵ������棬�������˽�г�Ա�ͻᱻ���ƣ�����������Ԫ
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

//class Date; // ǰ������
//class Time
//{
//	friend class Date; // ����������Ϊʱ�������Ԫ�࣬�����������о�ֱ�ӷ���Time���е�˽�г�Ա����
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
//		// ֱ�ӷ���ʱ����˽�еĳ�Ա����
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
//	//*�������Ϊ:һ������ĵ�����Ա��������ʼ���б���������Ľ׶�
//	Date(int year = 0, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _n(10)
//		, _ref(year)
//		, _a(1)
//	{
//		_day = day;
//		//_n = 1;   //����,����ʹ�ó�ʼ���б��ʼ��
//		//_ref = 2; //�����������ͱ����ó�ʼ���б��ʼ��
//	}
//
//
//private:
//	//��������ǳ�Ա�����������������ǳ�Ա�����Ķ���
//	int _year;
//	int _month;
//	int _day;
//	
//	//���Ǳ����ڶ����ʱ���ʼ��������ֻ���ó�ʼ���б��ʼ��
//	const int _n; //const���ε�����
//	int& _ref;    //��������
//	A _a;         //û��Ĭ�Ϲ��캯�����Զ�������
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
//	////�Զ������ͣ�ʹ�ó�ʼ���б� -> ������Time��Ĺ��캯��
//	//Date(int day, int hour)
//	//	: _t(hour)
//	//{}
//
//	//�Զ������ͣ���ʹ�ó�ʼ���б� -> ����Time�๹�캯�� + ��ֵ
//	Date(int day, int hour)
//	{
//		//�������ڳ�ʼ��
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
//	//_a2������������������_a2(_a1) -> _a2�����ֵ
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
////A.���1 1
////B.�������
////C.���벻ͨ��
////D.���1 ���ֵ ��ȷ��

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
//	//��ʼ���ļ��ַ�ʽ
//	A aa1(1); //������ʼ��
//	A aa2(aa1); //��������
//
//	//�������Ĺ��캯����֧����ʽ����ת��
//	A aa3 = 2; 
//	//���ڱ�������A tmp(2) -> A aa2(tmp) ��:����+��������
//	//���ڱ������Ż�:ֱ�ӵ��ÿ�������
//	//����ڹ��캯��ǰ�� explicit����ʽ����ת���ͷ���������
//
//
//	//eg:
//	int i = 0;
//	double d = i; //��ʽ����ת��
//}

////���������A�����˶��ٸ��������
//class A
//{
//public:
//	//����
//	A()
//	{
//		++_n;
//	}
//	//��������
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
//	//ֻ������ , _n���ڹ��캯����ʼ������������棬ȫ�ֵ�λ�ó�ʼ��
//	static int _n; //n�Ǵ��ھ�̬���ģ����������࣬Ҳ����������ж���
//};
//
////��̬��Ա�����Ķ����ʼ��
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
//	//cout << A::_n << endl; //_n����public����������
//	//cout << a1._n << endl; //_n����public����������
//	//cout << A()._n << endl; //_n����public����������
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
//	//����ֻ������û�п��ռ�� -> ȱʡֵ��������캯��û�ж�������г�ʼ��������ȱʡֵ��ʼ��
//	int _a = 0;         //��ʼ���б��ʼ����_a = 1
//	int* _p = nullptr;  //��ʼ���б��ʼ��
//
//	//BUG�����淨���ú�������ȱʡֵ
//	int* _arr = (int*)malloc(sizeof(int) * 10); //_arr��ʼ���б���û��ֵ���������ȱʡֵmalloc��ʼ��
//
//	B _b = 6;//_b = 6,����_b�Ŀ�������
//	
//	//��̬��Ա�����������ֵ
//	//static int n = 0;
//};
//
//int main()
//{
//	A aa; //����Ĭ�Ϲ��캯��
//
//	return 0;
//}

//class A
//{
//public:
//	class B //B��������A����Ԫ��
//	{
//	public:
//		void foo(const A& a)
//		{
//			//B�п�ֱ�ӷ���A��Ԫ��
//			cout << a._a << endl;   //1
//			cout << a._p << endl;   //00000000
//			cout << A::_n << endl;//0����cout << _n << endl;��������Ҳ��
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