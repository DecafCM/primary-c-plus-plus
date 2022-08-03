#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;


//泛型编程 -- 模板 解决复用问题

//函数模板
//定义模板参数T，可以用typename也可以用class，都一样
template<class T> //T就是Type的缩写 或者 template<typename T> 
void Swap(T& x1, T& x2) //完成任意类型的交换
{
	T tmp = x1;
	x1 = x2;
	x2 = tmp;
}

//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//
//int main()
//{
//	int a = 1, b = 2;
//	double c = 1.1, d = 2.2;
//	
//	//编译器会通过实参推形参的类型T分别为int和double
//	//这种方式是隐式实例化
//	cout << Add(a, b) << endl;
//	cout << Add(c, d) << endl;
//	//cout << Add(a, c) << endl; //报错
//	cout << Add(a, (int)c) << endl; //强转后c还是double，这里只不过是c生成了一个临时变量转成double
//
//	//不让编译器推演类型，显式指定类型 -> 在函数名和参数列表中间加个<>,指定类型
//	//这种方式叫显式实例化
//	cout << Add<int>(a, c) << endl;
//	cout << Add<double>(a, c) << endl;
//
//	return 0;
//}

//// 专门处理int的加法函数
//int Add(int left, int right)
//{
//	return left + right;
//}
//// 通用加法函数
//template<class T>
//T Add(T left, T right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2);      // 与非模板函数匹配，编译器不需要特化
//	Add<int>(1, 2); // 调用编译器特化的Add版本
//}

//// 专门处理int的加法函数
//int Add(int left, int right)
//{
//	return left + right;
//}
//// 通用加法函数
//template<class T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // 与非函数模板类型完全匹配，不需要函数模板实例化
//	Add(1, 2.0); // 模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的Add函数
//}

//typedef int VDataType;
//class vector
//{
//public:
//	//...
//private:
//	VDataType* _a;
//	int _size;
//	int _capacity;
//};
//
//int main()
//{
//	vector v1;
//	vector v2;
//
//	return 0;
//}

////为防止头文件里有vector造成命名冲突
//namespace zqf
//{
//	//类模板
//	template <class T>
//	class vector
//	{
//	public:
//		vector()
//			:_a(nullptr)
//			, _size(0)
//			, _capacity(0)
//		{}
//
//		//拷贝构造函数和operator=涉及深浅拷贝，后续再谈
//
//		~vector()
//		{
//			delete[] _a;
//			_a = nullptr;
//			_size = _capacity = 0;
//		}
//
//		void push_back(const T& x)
//		{
//			//扩容操作
//			if (_size == _capacity)
//			{
//				int newcapacity = (_capacity == 0 ? 4 : _capacity * 2);
//				T* tmp = new T[newcapacity];
//				if (_a) //如果原空间不为空，则把数据拷贝过来
//				{
//					memcpy(tmp, _a, sizeof(T) * _size);
//					delete[] _a;
//				}
//
//				_a = tmp;//_a指向新空间
//				_capacity = newcapacity;
//			}
//			_a[_size] = x;
//			_size++;
//		}
//
//		//声明
//		T& operator[](size_t pos); //引用返回很关键，可读可写
//		
//		size_t size()
//		{
//			return _size;
//		}
//
//	private:
//		T* _a;
//		size_t _size;
//		size_t _capacity;
//	};
//
//	//1.在类外面定义，需要再写一次模板参数
//	//2.vector<>才是类型，vector只是类名
//	//3.模板不支持分离编译，也就是不支持声明在.h，定义在.cpp
//	template<class T>
//	T& vector<T>::operator[](size_t pos)
//	{
//		assert(pos < _size);
//		return _a[pos];
//	}
//	
//}
//
//int main()
//{
//	zqf::vector<int> v1;
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);
//
//	//v1.operator[](3);
//	cout << v1[3] << endl; //4
//
//	//修改数组的值，可以修改的原理是，operator[]函数用的引用返回，且_a[pos]在堆去，出了函数作用域还在
//	for (size_t i = 0; i < v1.size(); i++)
//	{
//		v1[i] *= 2;
//	}
//
//	//遍历
//	for (size_t i = 0; i < v1.size(); i++)
//	{
//		cout << v1[i] << " "; //2 4 6 8
//	}   
//	cout << endl;
//
//	zqf::vector<double> v2;
//	v2.push_back(1.1);
//	v2.push_back(2.2);
//	v2.push_back(3.3);
//	v2.push_back(4.4);
//
//	cout << v2[2] << endl; //3.3
//
//	return 0;
//}