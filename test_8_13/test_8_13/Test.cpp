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
	//这里const对象返回的是const迭代器，且只能读不能写
	vector<int>::const_iterator it1 = v.begin();
	while (it1 != v.end())
	{
		cout << *it1 << " ";
		it1++;
	}
	cout << endl;
}

//模板支持所有类型
template<class T>
void PrintVector(const vector<T>& v)
{
	//这里const对象返回的是const迭代器，且只能读不能写
	typename vector<T>::const_iterator it1 = v.begin();//通过增加typename关键字，告诉C++解析器，const_iterator是一个类型。
	while (it1 != v.end())
	{
		cout << *it1 << " ";
		it1++;
	}
	cout << endl;
}

void test_vector1()
{
	//无参构造，最常见的构造方式
	vector<int> v1;

	//构造并初始化n个val
	vector<int> v2(10, 0);

	//使用迭代器区间进行初始化构造
	vector<int> v3(v2.begin(), v2.end());

	string s("hello world");
	vector<char> v4(s.begin(), s.end());

	vector<string> v5;
	//第一种插入，先构造一个对象，再尾插
	string s3("sort");
	v5.push_back(s3);
	
	//插入匿名对象
	v5.push_back(string("insert"));
	//等价于
	//也是推荐的写法
	v5.push_back("insert");//单参数的隐式类型转换

	PrintVector(v1);
	PrintVector(v2);
	PrintVector(v3);
	PrintVector(v4);
	PrintVector(v5);

	//拷贝构造
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
	//[]对元素的修改
	v1[3] = 4;

	//遍历1 下标+[] 可读可写
	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	//遍历2 迭代器 可读可写
	vector<int>::iterator it1 = v1.begin();
	while (it1 != v1.end())
	{
		cout << *it1 << " ";
		it1++;
	}
	cout << endl;

	//遍历3 范围for(会自动判断结束，自动迭代++)
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	//反向迭代器
	vector<string> v2;
	v2.push_back("hello world");
	//vector<string>::reverse_iterator rit = v2.rbegin();//声明rit的类型，再把v2.begin()赋值给他
	auto rit = v2.rbegin();//通过auto推出v2.begin()返回的类型，比先声明简洁很多
	while (rit != v2.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;
}

void test_vector3()
{
	//验证vector的增容方式
	size_t sz;
	std::vector<int> foo;

	//提前把容量变成100,插入100个数据则不会增容
	foo.reserve(100);
	sz = foo.capacity();

	cout << "making foo grow:\n";
	for (int i = 0; i < 100; ++i) 
	{
		foo.push_back(i);
		if (sz != foo.capacity())//如果容量和之前不一样了就打印一次
		{
			sz = foo.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
	
	/*运行结果 
	making foo grow:
	*/

	vector<int> v1;
	v1.reserve(10); //capacity变成10，size为0

	vector<int> v2;
	v2.resize(10); //size,capacity都变成10(放了10个0进去)，默认缺省值是0

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
//	//查找[first, last),没找到返回last
//	//vector<int>::iterator pos = find(v.begin(), v.end(), 5);
//	auto pos = find(v.begin(), v.end(), 3);
//	if (pos != v.end())
//	{
//		v.insert(pos, 30);
//	}
//	PrintVector(v);//1 2 30 3 4 5
//
//	//删除
//	//v.erase(pos);//迭代器失效:此时pos的位置已经不是3，而是30，程序崩了
//	//解决办法:使用pos之前对其重新赋值
//	pos = find(v.begin(), v.end(), 3);
//	v.erase(pos);
//	PrintVector(v);//1 2 30 4 5 
//}

//int main()
//{
//	vector<int> v{ 1,2,3,4,5,6 };//此时size = capacity = 6，再插入元素就会增容
//	
//	auto it = v.begin();
//
//	// 将有效元素个数增加到100个，多出的位置使用8填充，操作期间底层会扩容
//	// v.resize(100, 8);
//
//	// reserve的作用就是改变扩容大小但不改变有效元素个数，操作期间可能会引起底层容量改变
//	// v.reserve(100);
//
//	// 插入元素期间，可能会引起扩容，而导致原空间被释放，pos指向的空间被释放，已经是野指针了
//	// v.insert(v.begin(), 0);
//	// v.push_back(8);
//
//	// 给vector重新赋值，可能会引起底层容量改变
//	//v.assign(100, 8);
//
//	/*
//	  出错原因：以上操作，都有可能会导致vector扩容，也就是说vector底层原理旧空间被释放掉，
//    而在打印时，it还使用的是释放之间的旧空间，在对it迭代器操作时，实际操作的是一块已经被释放的
//    空间，而引起代码运行时崩溃。
//	  解决方式：在以上操作完成之后，如果想要继续通过迭代器操作vector中的元素，只需给it重新
//    赋值即可。
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
//	//C++ 98推荐使用第二个
//	swap(v1, v2);//涉及三次深拷贝
//	PrintVector(v1);
//	v1.swap(v2);
//}

int main()
{
	//test_vector6();
	zqf::test_vector7();
	return 0;
}