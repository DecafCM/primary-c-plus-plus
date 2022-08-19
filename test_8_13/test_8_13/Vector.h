#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <assert.h>
#include<algorithm>

using namespace std;

#pragma once

//模拟实现vector
namespace zqf
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef T* const_iterator;

		vector()
			:_start(nullptr)
			,_finish(nullptr)
			,_endofstorage(nullptr)
		{}

		//v2(v1)
		vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			//深拷贝
			//复用接口
			/*this->reserve(v.capacity());//开一个和v1相同大小的空间
			//向开的空间里赋值
			for (auto e : v)
			{
				push_back(e);
			}*/
			_start = new T[v.capacity()];
			//memcpy(_start, v._start, sizeof(T) * v.size());
			for (size_t i = 0; i < v.size(); i++)
			{
				_start[i] = v._start[i];
			}
			_endofstorage = _start + v.capacity();
			_finish = _start +v.size();
		}

		~vector()
		{
			if (_start)
			{
				delete[] _start;
			}

			_start = _finish = _endofstorage = nullptr;
		}

		//v1.swap(v2)
		void swap(vector<T>& v)
		{
			//调用全局的swap
			::swap(_start, v.start);
			::swap(_finish, v.finish);
			::swap(_endofstorage, v._endofstorage);
		}

		//v1 = v3
		//传统写法
		/*
		T& operator=(const vector<T>& v)
		{
			if (this != &v)
			{
				delete[] _start;
				_start = new T[v.capacity()];
				memcpy(_start, v._start, sizeof(T) * v.size());
				_finish = _start + v.size();
				_endofstorage = _start + v.capacity();
			}

			return *this;
		}*/

		//现代写法，直接使用传值，v是v1的拷贝构造
		T& operator=(vector<T>& v)
		{
			/*swap(_start, v.start);
			swap(_finish, v.finish);
			swap(_endofstorage, v._endofstorage);*/
			swap(v);
			return *this;
		}

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin() const
		{
			return _start;
		}

		const iterator end() const
		{
			return _finish;
		}

		size_t capacity() const
		{
			return _endofstorage - _start;
		}

		void resize(size_t n, T val = T())//T()表示匿名调用T的默认构造函数
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				/*if (n < capacity())
				{
					while (_finish < _start + n)
					{
						*_finish = val;
						++_finish;
					}
				}
				else
				{
					reserve(n);
					while (_finish < _start + n)
					{
						*_finish = val;
						++_finish;
					}
				}*/
				if (n > capacity())
				{
					reserve(n);
				}
				while (_finish < _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}

		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();//先存一份原大小
				T* tmp = new T[n];
				//接着需要把旧空间拷贝到新空间
				if (_start)//初始情况，_start为空，不需要这个步骤
				{
					//memcpy(tmp, _start, sz * sizeof(T));
					//使用memcopy会出现的问题:对于string类来说，新空间的_str和原_str指向的同一片空间
					//当delete[] _start后，原空间已经被销毁(存入的数据已经被销毁)，_str指针变成野指针
					
					for (size_t i = 0; i < sz; i++)
					{
						tmp[i] = _start[i];
					}
					
					delete[] _start;

					//总结: 当T时内置类型或浅拷贝的自定义类型，他们增容或拷贝构造中，用memcpy是没有问题的
					//但是,T是深拷贝的自定义类型，会出问题
					//使用for循环赋值不会出现问题：因为tmp[i] = _start[i]调用的是string:operator=函数，是深拷贝

				}

				_start = tmp;//旧空间指向新空间
				//_finish = _start + size();//这样是不对的，因为size = finish - start,此时的start已经变了，是一片新空间的地址
				_finish = _start + sz;
				_endofstorage = _start + n;
			}
		}

		bool empty() const
		{
			return _start == _finish;
		}

		size_t size() const
		{
			return _finish - _start;
		}

		T& operator[](size_t i)
		{
			assert(i < size());

			return _start[i];
		}

		const T& operator[](size_t i) const
		{
			assert(i < size());

			return _start[i];
		}

		void push_back(const T& x)
		{
			if (_finish == _endofstorage)//满了，需要增容
			{
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
			}

			*_finish = x;
			_finish++;
		}

		void pop_back()
		{
			assert(!empty());

			_finish--;
		}

		//插入函数内部也面临pos迭代器失效的问题
		void insert(iterator pos, const T& x)
		{
			if (_finish == _endofstorage)//如果空间满了，增容
			{
				//先计算pos的相对位置
				size_t len = pos - _start;

				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);//增容后，pos仍指向旧空间，所以要对pos进行处理，要指向新空间的len位置
				
				//更新pos，解决增容后pos失效的问题
				pos = _start + len;
			}
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				end --;
			}
			*pos = x;
			_finish++;

			//如果要解决外部pos不变成野指针的情况，就1.传引用pos，2. 插入结束后pos = pos+1
			//pos = pos + 1;
		}
		
		iterator erase(iterator pos)
		{
			iterator it = pos + 1;
			while (it != _finish)
			{
				*(it - 1) = *it;
				it++;
			}
			_finish--;

			return pos;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};

	template<class T>
	void PrintVector(const vector<T>& c)
	{
		vector<int>::const_iterator it = c.begin();
		while (it != c.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;
	}

	void test_vector1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);

		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;

		PrintVector(v);
	}

	//测试pop_back
	void test_vector2()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);

		v.pop_back();
		v.pop_back();

	}

	//测试resize
	void test_vector3()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		v.resize(3);//比原空间小，相当于删除数据
		PrintVector(v);//1 2 3
		
		v.resize(6);//比原空间大，但没有超出容量
		PrintVector(v);//1 2 3 0 0 0

		v.resize(10, 2); //超出容量
		PrintVector(v);//1 2 3 0 0 0 2 2 2 2

	}

	//测试insert
	void test_vector4()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		v.push_back(7);
		v.push_back(8);

		PrintVector(v);

		vector<int>::iterator pos = find(v.begin(), v.end(), 3);
		v.insert(pos, 30);//1 2 3 4 5 6 7 8
		//insert以后pos迭代器失效：1.pos指向位置的意义变了，pos不是指向3了(而是30) 2.或是pos成了野指针
		PrintVector(v);//1 2 30 3 4 5 6 7 8
	}

	//测试erase
	void test_vector5()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);

		//删除所有偶数
		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)
			{
				it = v.erase(it);
			}
			else
			{
				++it;
			}
		}
		PrintVector(v);
	}

	void test_vector6()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		
		vector<int> v2(v1);

		PrintVector(v2);
		

		vector<int> v3 = v1;
		PrintVector(v3);//1 2 3 
	}

	void test_vector7()
	{
		vector<string> v1;
		v1.push_back("11111");
		v1.push_back("22222");
		v1.push_back("33333");
		v1.push_back("44444");
		v1.push_back("55555");//第五次插入后(增容后)崩溃
		
		for (const auto& e : v1)//为了减少深拷贝
		{
			cout << e << " ";
		}
		cout << endl;

	}
}





