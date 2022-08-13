#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;


//���ͱ�� -- ģ�� �����������

//����ģ��
//����ģ�����T��������typenameҲ������class����һ��
template<class T> //T����Type����д ���� template<typename T> 
void Swap(T& x1, T& x2) //����������͵Ľ���
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
//	//��������ͨ��ʵ�����βε�����T�ֱ�Ϊint��double
//	//���ַ�ʽ����ʽʵ����
//	cout << Add(a, b) << endl;
//	cout << Add(c, d) << endl;
//	//cout << Add(a, c) << endl; //����
//	cout << Add(a, (int)c) << endl; //ǿת��c����double������ֻ������c������һ����ʱ����ת��double
//
//	//���ñ������������ͣ���ʽָ������ -> �ں������Ͳ����б��м�Ӹ�<>,ָ������
//	//���ַ�ʽ����ʽʵ����
//	cout << Add<int>(a, c) << endl;
//	cout << Add<double>(a, c) << endl;
//
//	return 0;
//}

//// ר�Ŵ���int�ļӷ�����
//int Add(int left, int right)
//{
//	return left + right;
//}
//// ͨ�üӷ�����
//template<class T>
//T Add(T left, T right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2);      // ���ģ�庯��ƥ�䣬����������Ҫ�ػ�
//	Add<int>(1, 2); // ���ñ������ػ���Add�汾
//}

//// ר�Ŵ���int�ļӷ�����
//int Add(int left, int right)
//{
//	return left + right;
//}
//// ͨ�üӷ�����
//template<class T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // ��Ǻ���ģ��������ȫƥ�䣬����Ҫ����ģ��ʵ����
//	Add(1, 2.0); // ģ�庯���������ɸ���ƥ��İ汾������������ʵ�����ɸ���ƥ���Add����
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

////Ϊ��ֹͷ�ļ�����vector���������ͻ
//namespace zqf
//{
//	//��ģ��
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
//		//�������캯����operator=�漰��ǳ������������̸
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
//			//���ݲ���
//			if (_size == _capacity)
//			{
//				int newcapacity = (_capacity == 0 ? 4 : _capacity * 2);
//				T* tmp = new T[newcapacity];
//				if (_a) //���ԭ�ռ䲻Ϊ�գ�������ݿ�������
//				{
//					memcpy(tmp, _a, sizeof(T) * _size);
//					delete[] _a;
//				}
//
//				_a = tmp;//_aָ���¿ռ�
//				_capacity = newcapacity;
//			}
//			_a[_size] = x;
//			_size++;
//		}
//
//		//����
//		T& operator[](size_t pos); //���÷��غܹؼ����ɶ���д
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
//	//1.�������涨�壬��Ҫ��дһ��ģ�����
//	//2.vector<>�������ͣ�vectorֻ������
//	//3.ģ�岻֧�ַ�����룬Ҳ���ǲ�֧��������.h��������.cpp
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
//	//�޸������ֵ�������޸ĵ�ԭ���ǣ�operator[]�����õ����÷��أ���_a[pos]�ڶ�ȥ�����˺�����������
//	for (size_t i = 0; i < v1.size(); i++)
//	{
//		v1[i] *= 2;
//	}
//
//	//����
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