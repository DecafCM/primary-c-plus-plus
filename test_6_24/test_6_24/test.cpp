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

//namespace �������һ����
//���ڽ��C����������ͻ����

//eg:������ͻ
//C���ԵĿ��У�������������scanf��strlen����
//���������������������������������ͻ������ͻ
//int main()
//{
//	//���岻�ᱨ�����õ�ʱ��ᱨ��
//	int scanf = 10;
//	int strlen = 20;
//
//	//���¾��ᱨ��,��C���Խ�����˳�ͻ������
//	scanf("%d", &scanf);
//	printf("%d\n", scanf);
//	printf("%d\n", strlen);
//
//	return 0;
//}

////ʹ��C++�����ռ䣬�������ֵĸ���
////1. ��ͨ�������ռ�
//namespace N1 // N1Ϊ�����ռ������
//{
//	//�����ռ��е����ݣ��ȿ��Զ��������Ҳ���Զ��庯��
//	int scanf = 10;
//	int strlen = 20;
//
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//}
//
////2. �����ռ����Ƕ��
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
////3. ͬһ��������������ڶ����ͬ���Ƶ������ռ�,����������ϳ�ͬһ�������ռ��С�
////ע�⣺ͬһ�����ﲻ�ܶ���ͬ���ı�������
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
//	//Ĭ�Ϸ��ʾֲ������ȫ��
//	//���ھֲ�û�У�����ȫ�ֵ�ͷ�ļ�,���Դ�ʱ��ӡ���ǿ⺯���ĵ�ַ
//	printf("%x\n", scanf);   //411433
//	printf("%x\n", strlen);  //4113d4
//
//	//ָ������N1�����ռ�
//	printf("%x\n", N1::scanf);   //a
//	printf("%x\n", N1::strlen);  //14
//	
//	//ָ�������ռ�󣬲��ܵ���N1��ĺ���
//	int a = N1::Add(1, 2);
//	printf("%d\n", a); //3
//
//	//����Ƕ�������ռ������
//	int b = N2::N3::Sub(5, 3);
//	printf("%d\n", b); //2
//
//	return 0;
//}

//#include <iostream>
////C++��Ϊ�˷�ֹ������ͻ�����Լ�����Ķ�������������һ��std�������ռ���
////Ҫʹ�ñ�׼���еĶ����������ַ�ʽ
////1. ָ�������ռ� 
////   -> ȱ��: �鷳��ÿ���ط�Ҫ�ö�Ҫ�ƶ�������������淶��ʹ�÷�ʽ
////2. ��std����չ��:using namespace std ,�൱�ڿ���Ķ�������ȫ������ 
////   ->ȱ��: ����Լ�����ĺͿ��ͻ�˾��޷������
////   ���Թ淶�Ĺ�����Ŀ���ǲ��Ƽ����ַ�ʽ�ģ��ճ���ϰ����ν
////3. �Բ��ֳ��õĿ�����Ķ���չ���������1��2���еķ���������Ŀ�о���ʹ��
// using std::cout;
// using std::endl;
//
//
//
////using namespace std;
//
//int main()
//{
//	//1. ָ�������ռ�
//	std::cout << "hello world" << std::endl;
//
//	// 2.��std����չ��,����д��using namespace std;����ֱ���ü���
//	cout << "hello world" << endl;
//
//	// 3.�Բ��ֳ��õĿ�����Ķ���չ��
//	cout << "hello world" << endl;
//	std::string s; //ûչ���ľͲ���ֱ��ʹ��
//
//	return 0;
//}

//#include<iostream>
//
////cout ��ostream����ȫ�ֶ���
////cin  ��istream����ȫ�ֶ���
////endl ��ȫ�ֵĻ��з���
//int main()
//{
//	std::cout << "hello world!" << std::endl;
//
//	//�Ա�C����printf��scanf�����ǣ�
//	//�����Զ�ʶ������
//	int a = 10;
//	int* p = &a;
//	//c���Դ�ӡ
//	printf("%d,%p\n", a, p);
//	//c++��ӡ
//	std::cout << a << "," << p << std::endl;
//
//	return 0;
//}

////ȱʡ����
//void TestFunc(int a = 0)
//{
//	cout << a << endl;
//}
//int main()
//{
//	TestFunc(); // û�д���ʱ��ʹ�ò�����Ĭ��ֵ
//	TestFunc(10); // ����ʱ��ʹ��ָ����ʵ��
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


////C���Բ�������ͬ������
////C++���� -> �������� -> ����(���ͻ������˳��)��ͬ
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
//	//b��a������(����)
//	//ע���������ú�ȡ��ַ�����������ͺ�&������ȡ��ַ��ֱ��&����
//	int& b = a;
//	b = 20;
//
//	//����ȡ����
//	int& c = b;
//	c = 30;
//
//	return 0;
//}

////���õļ�ֵ
////�ñ����Ϳ��Բ��ô���ַ���н���
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
//	swap(a, b); //c������Ҫ����ַ
//
//	struct Stack st;
//	StackInit(st);
//
//	return 0;
//}

////Ȩ�޿�����С�������ܷŴ�
//int main()
//{
//	const int a = 10;//��const���κ�aֻ�ܶ�����д
//	//int& ra = a;//����ra����a����Ȩ�޷Ŵ�(�ɶ���д)
//	const int& ra = a; //��ȷ����
//
//	int b = 10;
//	int& rb = b;
//	const int& crb = b;//��ȷ��ceb����b����Ȩ�޵���С�����Կ���
//
//	int c = 10;
//	double d = 1.11;
//	d = c; //��ʽ����ת������int���͵�c�ŵ�һ��double���͵���ʱ�����У��ٸ�ֵ��d
//
//	//double& rc = c; //��������ԭ�򲢲�����Ϊ���Ͳ�ͬ
//	const double& rc = c; //*��ȷ���룬��ʱrc��c��ʱ�����ı�������ʱ�������г��ԣ����Լ�const�Ϳ���
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

////��ֵ���� ���ص��Ƿ��ض���c�Ŀ���
//int Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//int main()
//{
//	//int& ret = Add(1, 2); //������Ϊret���յ��Ǵ���c��ֵ����ʱ����(����c)�����г��ԣ�����ǰ����const
//	const int& ret = Add(1, 2);
//	
//	return 0;
//}

////�����÷��� ���ص��Ƕ���c�����ã���ʵ����c
////ʵ���У�������˺��������򣬷��ر����Ͳ������ˣ����������÷���;������������:������static����
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
//	// ��ֵ��Ϊ��������
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//
//	// ��������Ϊ��������
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//
//	// �ֱ���������������н������ʱ��
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;  //11
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl; //1
//}


//#include <time.h>
//struct A { int a[10000]; };
//A a;
//// ֵ����
//A TestFunc1() { return a; }
//// ���÷���
//A& TestFunc2() { return a; }
//void TestReturnByRefOrValue()
//{
//	// ��ֵ��Ϊ�����ķ���ֵ����
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc1();
//	size_t end1 = clock();
//	// ��������Ϊ�����ķ���ֵ����
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//	// �������������������֮���ʱ��
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
//	//���﷨�ϣ���a�����ռ�ȡ�˸�������û���¿��ռ�
//	int& ra = a;
//	ra = 20;
//
//	//���﷨�ϣ�������һ��paָ�����,������4���ֽڣ��洢a�ĵ�ַ
//	int* pa = &a;
//	*pa = 20;
//
//	return 0;
//}

//ADD�ĺ꺯��
//#define ADD(int x, int y) return x+y  //���ʹ���д��
//#define ADD(x, y) (x)+(y);  //���ʹ���д��,���˷ֺ�
//��׼д��
//#define ADD(x, y) ((x) + (y))


////C++�Ƽ���Ƶ�����õ�С�����������inline(����)�����ڵ��õĵط�չ����û��ջ֡�Ŀ���
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
////�����﷨,��ǰ�˽⼴��
////auto
//int main()
//{
//	int a = 10;
//	//int b = a;
//	auto b = a; //����������auto�����Ը���a�������Զ��Ƶ�b������Ϊint
//
//	map<string, string> m;
//	//map<string, string>::iterator it = m.begin();
//	//������Ը���m.begin()�Զ��Ƶ���it��������map<string, string>::iterator
//	//����д�Ƚϼ��
//	auto it = m.begin();
//
//	return 0;
//}

//int main()
//{
//	int x = 10;
//	auto a = &x;    //a��������int*
//	auto* b = &x;   //������ȷ˵����ָ��,b��������int*
//	
//	int& y = x;     //y��������int
//	auto& c = y;    //y��x�ı�����y��������int��c��������int
//
//	auto& d = x;    //d��������int,���˴�ָ����d��x������
//
//	//��ӡ����������
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
//	auto c = 3, d = 4.0; // ���д�������ʧ�ܣ���Ϊc��d�ĳ�ʼ�����ʽ���Ͳ�ͬ
//}

//int main()
//{
//	int array[] = { 1, 2, 3, 4, 5 };
//	//��ǰ��������ķ�ʽ
//	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
//		cout << array[i] << " ";
//	cout << endl;
//	// 1 2 3 4 5 
//	
//	//��Χfor�����򵥣�����Ҳ����ֱ�ӱ���
//	//�Զ��������Դ�ȡ��array�е�Ԫ�أ���ֵ��e��ֱ������
//	for (auto e : array)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	//1 2 3 4 5 
//
//	//������"��"�Ĳ�����"д"�Ĳ�����Ҫע������÷���
//	for (auto& ee : array) //ee������Ԫ�ص���ʱ������Ҫ���޸�������Ҫ�����÷���
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
//	//��ǰʹ�õ�
//	int* p1 = NULL;
//
//	//C++�Ƽ�ʹ�õ�
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
//	f(0);         //����ƥ�����β�����f�����:f(int)
//	f(NULL);      //����ƥ��ָ�������f�����:f(int),��ΪNULL���滻��0��
//	f((int*)NULL);//f(int*)
//	f(nullptr);   //f(int*)
//
//	return 0;
//}