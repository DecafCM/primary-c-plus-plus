#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

////C���Զ���ջ
//typedef int STDataType;
////����
//struct Stack
//{
//	STDataType* a;
//	int size;
//	int capacity;
//};
////���� -- ���ݺͷ����Ƿ���ģ��ص��ע���ǹ��� -> ��������
//void StackPush(struct Stack* ps, STDataType x);

////C++
////�� -- �����һ���µ�����
////���������ֹ��ɣ�1����Ա����(����) 2����Ա���� (������Ϊ)
////C++�е�struct����C�������÷���ͬʱC++�а�struct��������
//typedef int STDataType;
//struct Stack
//{
//	//����
//	STDataType* a;
//	int size;
//	int capacity;
//
//	//����
//	void Init(int initSize = 4)
//	{
//		a = (STDataType*)malloc(sizeof(STDataType) * initSize);
//		size = 0;
//		capacity = initSize;
//	}
//
//	void Push(STDataType x)
//	{
//		//...����
//		a[size] = x;
//		size++;
//	}
//
//	//...����ӿ�
//};
//
//int main()
//{
//	//C++���������ǿ��Ե�������ֱ���� ����дstruct Stack st
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
//	//���壺�ɳ�Ա�����ͳ�Ա�������
//
//}; //һ��Ҫע�����ķֺ�

////�����Ͷ���ȫ������������
//class Person
//{
//public:
//	//��ʾ������Ϣ
//	void showInfo()
//	{
//		cout << _name << "-" << _sex << "-" << _age << endl;
//	}
//public:
//	char* _name; //����
//	char* _sex;  //�Ա�
//	int _age;    //����
//};

////��������.h�ļ��У���Ķ������.cpp��
////�����������ͷ�ļ�person.h��
//class Person
//{
//public:
//	//��ʾ������Ϣ
//	void showInfo();
//public:
//	char* _name; //����
//	char* _sex;  //�Ա�
//	int _age;    //����
//};
//
////����������ʵ���ļ�person.cpp��
//#include <person.h>
//
////��ʾ������Ϣ
//void Person::showInfo() //��{}����һ����ʹ��ʱ��Ҫָ�����ĸ����
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
//// ������Ҫָ��PrintPersonInfo������Person�������
//void Person::PrintPersonInfo()
//{
//	cout << _name << " "<<_gender << " " << _age << endl;
//}

//typedef int STDataType;
//struct Stack
//{
//	//����
//	STDataType* a;
//	int size;
//	int capacity;
//
//	//����
//	void Init(int initSize = 4)
//	{
//		a = (STDataType*)malloc(sizeof(STDataType) * initSize);
//		size = 0;
//		capacity = initSize;
//	}
//
//	void Push(STDataType x)
//	{
//		//...����
//		a[size] = x;
//		size++;
//	}
//
//	//...����ӿ�
//};
//
//int main()
//{
//	//���ʵ����
//	Stack st;
//
//	st.Init();
//	st.Push(1);
//	st.Push(2);
//	st.Push(3);
//
//	//���ʵ����
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

//// ���м��г�Ա���������г�Ա����
//class A1 {
//public:
//	void f1() {}
//private:
//	int _a;
//};
//// ���н��г�Ա����
//class A2 {
//public:
//	void f2() {}
//};
//// ����ʲô��û��---����
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
//	//������thisָ�룺
//	//*������������һ�������Ĳ���:void Init(Date* this, int year, int month, int day)
//	//1.thisָ���������ġ�����������ʱ�ӵģ����ǲ����Լ��ڵ��úͺ��������м���
//	//2.�����ڳ�Ա������ʹ��thisָ��
//	//3.thisһ���Ǵ���ջ�ϵ�
//	
//	void Init(int year, int month, int day)
//	{
//		//��װ�ĺô����ڿ����ȼ���������ݵĺϷ���
//		//...
//
//		//year = year; //������ֲ���˭��ʼ����˭,����ʵ��������year���Ǻ������year(�ͽ�ԭ��)
//		//Date::year = year;//���е��鷳
//		
//		//���������Ժ�
//		_year = year;
//		_month = month;
//		_day = day;
//		/*//���������Զ�����ɣ�
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;*/
//
//	}
//
//private:
//	//���ǳ�Ա���������������������һ��
//	int _year;
//	int _month;
//	int _day;
//
//	//�����������
//	//int year_;
//	//int m_year;
//	//int mYear;
//};
//
//int main()
//{
//	Date d1;
//	//��ζ�d1���г�ʼ���� d1._year = 2022 ����
//	d1.Init(2022, 7, 25);
//
//	Date d2;
//	d1.Init(2022, 7, 26);
//
//	//*�������ˣ�d1��d2���õ���ͬһ���������ú�������ô֪��ʹ�õ��ĸ������أ�
//	//����d1.Initʱ��ʵ�ʵ��õ���d1.Init(&d1, 2021, 5, 24),�������˶���ĵ�ַ
//
//	//���ۣ��ĸ�����ȥ���ó�Ա��������Ա�����з��ʵľ����ĸ������еĳ�Ա������ͨ��thisָ������
//
//	return 0;
//}

//// ��Ѷ������
//// 1.��������ܱ���ͨ����
//// 2.����������������������
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
//	//p->PrintA(); //��������ָ��ķ���
//	p->Show();   //��������
//
//	//δ�����ԭ��
//	//p��>Show()��p��>PrintA()���������Խ��뺯���ڲ����е�ԭ����û�ж�p���н����ò���
//	//��ΪShow�ȳ�Ա�����ĵ�ַû�д浽��������Բ���������ָ����ʵı���
//
//	//���뺯���ڲ�
//	//p->PrintA()��p->Show()ֻ�ǰѿ�ָ��p������PrintA()��p->Show()
//	//��ʱ������Ա�������ܵ���this�ǿ�ָ��
//	//��PrintA�Կ�ָ������˽�����(this->_a)�������Ա�����p->Show()û�У�������������
//
//}

//�������Ա����ʲô����дʱ�����������Զ�����6����������6����������Ĭ��(ȱʡ)��Ա����

////1�����캯�� -->����ĳ�ʼ��
//class Date
//{
//public:
//	//���캯���������Init����
//	//����дInitʱ�����ǿ��ܻ��ڵ���ʱ����������û�н��г�ʼ��������������
//	//C++Ϊ�˽��������⣬�����˹��캯���������г�ʼ��
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//���캯�� -> ����ʵ������ʱ���Զ����ã�������֤����һ����ʼ��
//	//Date(int year, int month, int day)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//
//	////���أ����εĸ��������Ͳ�ͬ
//	//Date()
//	//{
//	//	_year = 0;
//	//	_month = 1;
//	//	_day = 1;
//	//}
//
//	//һ������������ʼ�������������֣�Ĭ�ϳ�ʼ���͸���ֵ��ʼ��
//	//��������������϶�Ϊһ������һ��ȫȱʡ��Date���ܺ���
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
//	//���캯��
//	Stack()
//	{
//		_a = nullptr;
//		_size = _capacity = 0;
//	}
//
//	//����
//	Stack(int capacity)
//	{
//		_a = (int*)malloc(sizeof(int) * capacity);
//		_size = 0;
//		_capacity = capacity;
//	}
//	//�϶�Ϊһ
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
//	Date d1(2022, 7, 25);//ע����ù��캯�����ڶ������Ӳ���
//	d1.Print(); //2022-7-25
//
//	//����
//	Date d2;
//	// ע�⣺���ͨ���޲ι��캯����������ʱ��������治�ø����ţ�����ͳ��˺�������
//	d2.Print(); //0-1-1
//
//	/*Stack st;
//	st.Push(1);*/ //���ǵ���Init���г�ʼ����������
//	
//	Stack st1;
//	st1.Push(1);
//
//	//����
//	Stack st2 (4);
//
//	return 0;
//}

//class A
//{
//public:
//	//���캯��
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
//	//���ǲ�д��������������һ�����캯�����Լ�д�˱������Ͳ������ɣ����Թ��캯����Ĭ�ϳ�Ա����
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//		//cout << _aa._a << endl; //�����޷�����_a,��Ϊa��˽�е�,��η�����?
//		_aa.Print(); //0
//	}
//private:
//	//��������(��������):����ԭ�������������int��char��double�ȡ�ָ�룬�����ʼ��
//	int _year;
//	int _month;
//	int _day;
//
//	//�Զ�������:ʹ��class��struct�ȶ�������ͣ���������������ǵ�Ĭ�Ϲ��캯�����г�ʼ��
//	A _aa;
//};
//
//int main()
//{
//	Date d1;
//	d1.Print();
//	//-858993460--858993460--858993460 �������Ͳ���ʼ��
//	//0 �Զ������͵���Ĭ�Ϲ��캯����ʼ��
//
//	return 0;
//}

//class A
//{
//public:
//	//���캯��
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
//	//���ǲ�д��������������һ�����캯�����Լ�д�˱������Ͳ������ɣ����Թ��캯����Ĭ�ϳ�Ա����
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
//	//��������(��������):����ԭ�������������int��char��double�ȡ�ָ�룬�����ʼ��
//	int _year;
//	int _month;
//	int _day;
//};
//
////�ܶ�����ΪĬ�Ϲ��캯���ǣ��Լ���д��������Ĭ�����ɵĺ������������ǲ�ȫ���
////1.���ǲ�д��������Ĭ������
////2.�����Լ�д���޲ε�
////3.����д��ȫȱʡ
//
////�ܽ�:���ô��ξͿ��Ե��õĹ��캯��
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
//	//��������
//	~Date()
//	{
//		//��Դ������
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
//	//�������� -> ������Դ
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
//	//����Ҫ�ֶ����ٿ��ٵĿռ��ˣ���Ϊ����������Ĭ��ִ��
//
//	Stack st2;
//	st2.Push(2);
//	st2.Push(2);
//	st2.Push(2);
//
//	//���⣺�ж������ʱ��˭�������� -> st2��
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
//	//��������
//	~Date()
//	{
//		//��Դ������
//	}
//
//	//��ͳ�����Ƚ����ڴ�С
//	bool Equel(Date d)
//	{
//		return _year == d._year
//			&& _month == d._month
//			&& _day == d._day;
//	}
//
//	//���������
//	bool operator== (Date x)
//	{
//		return _day == x._day
//			&& _month == x._month
//			&& _year == x._year;
//	}
//
//	//�������������������ʱ����һ������������������ڶ����������Ҳ�����
//	//d1 < d2 => d1������this, d2������x
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
//	int& operator[](size_t pos) //�����ò������ܼ��ٿ���
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
//	//����ж��������������Ƿ���ȣ�
//	//��ͳ������
//	cout << d1.Equel(d2) << endl; //0
//
//	//�ܷ��� d1 == d2; d1 < d2; d1 > d2���жϴ�С��
//	//�������ͣ����Բ���֧�������
//	//�Զ�������Ĭ�ϲ�֧�� => C++������������������������֧����ĳ�������
//
//	//����Ӧ����������: operator==(d1, d2);
//	//�������������Զ�������d1�������==����ȥ�����û�ж����������������أ�����оͻ���øú���
//	//d1.operator == (d2); //�ȼ���d1.operator == (&d1, d2);
//	d1 == d2; //�ȼ���d1.operator == (&d1, d2);
//
//	cout << (d1 == d2) << endl; //ע��: <<���ȼ�����<�����Ա��������
//	cout << (d1 < d2) << endl;
//
//	//������ʵ������+���ڣ�����+����������-����
//	//cout << (d1 + 100) << endl;
//	//cout << (d1 - 100) << endl;
//	//cout << (d1 - d2) << endl;
//
//	//���� []�����
//	Array ay;
//	cout << ay[0] << endl; //0  //ay[0]�ȼ���ay.operator[](&ay, 0);
//	cout << ay[1] << endl; //10
//	cout << ay[2] << endl; //20
//
//	//�����ú�ɶ�ay�����޸� => ��ֵ���˷��ض���ı���
//	ay[0] = 100; //��100��ֵ��operator[]����ֵ�ı���
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

//	//�������캯��
//	//Date d4(d1),d4����this��d1����d
//	//Ϊʲô�����ô��Σ� => û�����ô��λ����޵��ÿ������� Date d2(d1) -> d1��ֵ��Date (Date d)�е�d
//	// -> Date d(d1) -> ���޵��á�
//	//�������ÿ������캯����Ҫ�ȴ��Σ��������ʹ�õĴ�ֵ���ֻ��ɿ�������,ѭ������
//	//ʹ�����ô��κ󣬰Ѳ���d1������Date(Date& d)�����ǣ������ڵ��ÿ������캯��������˳���İ�d2����this��d1����d
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
//	//��������
//	~Date()
//	{
//		//��Դ������
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
//	//�������� -> ������Դ
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
//	//����ö���d2ӵ��d1������?
//	Date d2(d1); //�������캯��
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
//	//�������캯��
//	//Date d4(d1),d4����this��d1����d
//	//Ϊʲô�����ô��Σ� => û�����ô��λ����޵��ÿ������� Date d(d1) 
//	//   -> ��ֵ��һ�ֿ�����Ϊ������d1�Ŀ�����ֵ��d ��:Date d(d1)->���������������캯��
//	//   -> Date d(d1) -> ���޵��á�
//	//�������ÿ������캯����Ҫ�ȴ��Σ����ʹ�õĴ�ֵ���ֻ��ɿ�������,ѭ������
//	//ʹ�����ô��κ󣬰Ѳ���d1������Date(Date& d)�����ǣ������ڵ��ÿ������캯��������˳���İ�d2����this��d1����d
//	//�Ƽ���Date(const Date& d)����ֹд����,�ѿ����������޸��˵����
//	/*Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}*/
//
//	//�Լ���д�������캯����������Ҳ���Զ�����
//	//�ÿ�������Ƚ����⣬���������ͻ����ǳ���������߽�ֵ����
//
//	//��������
//	~Date()
//	{
//		//��Դ������
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
//	//����ö���d2ӵ��d1������?
//	Date d2(d1); //�������캯��
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
//	//�������� -> ������Դ
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
//	Stack copy(st1);//����
//
//	//����ԭ��:
//	//1. ���ڿ�����_a��ԭ�����_aָ��ָ��ͬһ��ռ䣬�ڵ�����������ʱ�����ռ䱻free������
//	//2.����һ���������ɾ�����ݣ����ᵼ����һ������Ҳ����ɾ������(��Ϊ�õ�ͬһ��ռ�)
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
//	//1.����ֵvoid�޷�����������ֵ����� d1 = d2 = d3��=>�� d2 = d3 -> d1 = d2����Ҫ����d2���ܸ�ֵ��d1
//	//2.Date operator=(const Date& d)��������һ���������ÿ������캯��(ע�ⷵ�ش����õ�ǰ�᣺���˺��������������ڣ��Ϳ��ԣ�d2�ڸú�����������������)
//	//d2 = d1;  => d2.operator=(d1)
//	//��ֵ�����Ҳ��һ��Ĭ�ϳ�Ա���������ǲ�д�����������Զ�����
//	//������Ĭ�����ɸ�ֵ����������������������һ�µ�
//	//1.����������ͻ����ǳ��������Date�಻��Ҫд��ֵ��������أ���Stack��Ҫ
//	//2.�����Զ������ͣ���������ĸ�ֵ�����������ɿ���
//
//	Date& operator=(const Date& d) //Date operator=(Date* this, const Date& d)
//	{
//		if (this != &d) //�����������Լ����Լ���ֵ������Ҫ����
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
//	//��Ҳ�ǿ�����Ϊ�����Ϳ���������������ڣ����������Ǵ���һ�������ʱ����ͬ������ʼ��
//	//����Ŀ����ǣ����������Ѿ������ˣ����һ�����󿽱�����һ������
//	d2 = d1;
//	d1.Print(); //2022 - 7 - 27
//	d2.Print(); //2022 - 7 - 27
//
//	Date d3;
//
//	//������ֵ
//	d1 = d2 = d3;
//	d1.Print(); //0-1-1
//	d2.Print(); //0-1-1 
//	d3.Print(); //0-1-1
//
//	Date d4(d1); //��������
//	d2 = d1;     //��ֵ����
//	//���ǿ������컹�����أ�
//	Date d5 = d1; //��������
//	//��Ϊ��ֵ�����������Ѿ����ڵĶ��󣬽��п�������
//	//������������һ���Ѿ����ڵĶ���ȥ��ʼ����һ�������Ķ���
//
//	return 0;
//}