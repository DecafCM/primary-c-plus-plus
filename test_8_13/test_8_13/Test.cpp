#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<algorithm>

#include "Vector.h"
using namespace std;

void PrintVector(const vector<int>& v)
{
	//����const���󷵻ص���const����������ֻ�ܶ�����д
	vector<int>::const_iterator it1 = v.begin();
	while (it1 != v.end())
	{
		cout << *it1 << " ";
		it1++;
	}
	cout << endl;
}

//ģ��֧����������
template<class T>
void PrintVector(const vector<T>& v)
{
	//����const���󷵻ص���const����������ֻ�ܶ�����д
	typename vector<T>::const_iterator it1 = v.begin();//ͨ������typename�ؼ��֣�����C++��������const_iterator��һ�����͡�
	while (it1 != v.end())
	{
		cout << *it1 << " ";
		it1++;
	}
	cout << endl;
}

void test_vector1()
{
	//�޲ι��죬����Ĺ��췽ʽ
	vector<int> v1;

	//���첢��ʼ��n��val
	vector<int> v2(10, 0);

	//ʹ�õ�����������г�ʼ������
	vector<int> v3(v2.begin(), v2.end());

	string s("hello world");
	vector<char> v4(s.begin(), s.end());

	vector<string> v5;
	//��һ�ֲ��룬�ȹ���һ��������β��
	string s3("sort");
	v5.push_back(s3);
	
	//������������
	v5.push_back(string("insert"));
	//�ȼ���
	//Ҳ���Ƽ���д��
	v5.push_back("insert");//����������ʽ����ת��

	PrintVector(v1);
	PrintVector(v2);
	PrintVector(v3);
	PrintVector(v4);
	PrintVector(v5);

	//��������
	vector<string> copy(v5);
	PrintVector(copy);

}

void test_vector2()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(1);
	//[]��Ԫ�ص��޸�
	v1[3] = 4;

	//����1 �±�+[] �ɶ���д
	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	//����2 ������ �ɶ���д
	vector<int>::iterator it1 = v1.begin();
	while (it1 != v1.end())
	{
		cout << *it1 << " ";
		it1++;
	}
	cout << endl;

	//����3 ��Χfor(���Զ��жϽ������Զ�����++)
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	//���������
	vector<string> v2;
	v2.push_back("hello world");
	//vector<string>::reverse_iterator rit = v2.rbegin();//����rit�����ͣ��ٰ�v2.begin()��ֵ����
	auto rit = v2.rbegin();//ͨ��auto�Ƴ�v2.begin()���ص����ͣ������������ܶ�
	while (rit != v2.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;
}

void test_vector3()
{
	//��֤vector�����ݷ�ʽ
	size_t sz;
	std::vector<int> foo;

	//��ǰ���������100,����100�������򲻻�����
	foo.reserve(100);
	sz = foo.capacity();

	cout << "making foo grow:\n";
	for (int i = 0; i < 100; ++i) 
	{
		foo.push_back(i);
		if (sz != foo.capacity())//���������֮ǰ��һ���˾ʹ�ӡһ��
		{
			sz = foo.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
	
	/*���н�� 
	making foo grow:
	*/

	vector<int> v1;
	v1.reserve(10); //capacity���10��sizeΪ0

	vector<int> v2;
	v2.resize(10); //size,capacity�����10(����10��0��ȥ)��Ĭ��ȱʡֵ��0

}

//void test_vector5()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	v.push_back(5);
//
//	v.insert(v.begin(), 0);
//	PrintVector(v);//0 1 2 3 4 5
//
//
//	v.erase(v.begin());
//	PrintVector(v);//1 2 3 4 5
//
//	//����[first, last),û�ҵ�����last
//	//vector<int>::iterator pos = find(v.begin(), v.end(), 5);
//	auto pos = find(v.begin(), v.end(), 3);
//	if (pos != v.end())
//	{
//		v.insert(pos, 30);
//	}
//	PrintVector(v);//1 2 30 3 4 5
//
//	//ɾ��
//	//v.erase(pos);//������ʧЧ:��ʱpos��λ���Ѿ�����3������30���������
//	//����취:ʹ��pos֮ǰ�������¸�ֵ
//	pos = find(v.begin(), v.end(), 3);
//	v.erase(pos);
//	PrintVector(v);//1 2 30 4 5 
//}

//int main()
//{
//	vector<int> v{ 1,2,3,4,5,6 };//��ʱsize = capacity = 6���ٲ���Ԫ�ؾͻ�����
//	
//	auto it = v.begin();
//
//	// ����ЧԪ�ظ������ӵ�100���������λ��ʹ��8��䣬�����ڼ�ײ������
//	// v.resize(100, 8);
//
//	// reserve�����þ��Ǹı����ݴ�С�����ı���ЧԪ�ظ����������ڼ���ܻ�����ײ������ı�
//	// v.reserve(100);
//
//	// ����Ԫ���ڼ䣬���ܻ��������ݣ�������ԭ�ռ䱻�ͷţ�posָ��Ŀռ䱻�ͷţ��Ѿ���Ұָ����
//	// v.insert(v.begin(), 0);
//	// v.push_back(8);
//
//	// ��vector���¸�ֵ�����ܻ�����ײ������ı�
//	//v.assign(100, 8);
//
//	/*
//	  ����ԭ�����ϲ��������п��ܻᵼ��vector���ݣ�Ҳ����˵vector�ײ�ԭ��ɿռ䱻�ͷŵ���
//    ���ڴ�ӡʱ��it��ʹ�õ����ͷ�֮��ľɿռ䣬�ڶ�it����������ʱ��ʵ�ʲ�������һ���Ѿ����ͷŵ�
//    �ռ䣬�������������ʱ������
//	  �����ʽ�������ϲ������֮�������Ҫ����ͨ������������vector�е�Ԫ�أ�ֻ���it����
//    ��ֵ���ɡ�
//	*/
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	return 0;
//}

//int main()
//{
//	vector<int> v{ 1, 2, 3, 4 };
//	auto it = v.begin();
//	while (it != v.end())
//	{
//		if (*it % 2 == 0)
//			v.erase(it);
//		++it;
//	}
//
//	return 0;
//}
//int main()
//{
//	vector<int> v{ 1, 2, 3, 4 };
//	auto it = v.begin();
//	while (it != v.end())
//	{
//		if (*it % 2 == 0)
//			it = v.erase(it);
//		else
//			++it;
//	}
//	return 0;
//}

//void test_vector6()
//{
//	vector<int> v1;
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	
//	vector<int> v2;
//	v2.push_back(10);
//	v2.push_back(20);
//
//	//C++ 98�Ƽ�ʹ�õڶ���
//	swap(v1, v2);//�漰�������
//	PrintVector(v1);
//	v1.swap(v2);
//}

int main()
{
	//test_vector6();
	zqf::test_vector7();
	return 0;
}