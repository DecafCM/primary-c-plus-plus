#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <assert.h>
#include<algorithm>

using namespace std;

#pragma once

//ģ��ʵ��vector
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
			//���
			//���ýӿ�
			/*this->reserve(v.capacity());//��һ����v1��ͬ��С�Ŀռ�
			//�򿪵Ŀռ��︳ֵ
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
			//����ȫ�ֵ�swap
			::swap(_start, v.start);
			::swap(_finish, v.finish);
			::swap(_endofstorage, v._endofstorage);
		}

		//v1 = v3
		//��ͳд��
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

		//�ִ�д����ֱ��ʹ�ô�ֵ��v��v1�Ŀ�������
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

		void resize(size_t n, T val = T())//T()��ʾ��������T��Ĭ�Ϲ��캯��
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
				size_t sz = size();//�ȴ�һ��ԭ��С
				T* tmp = new T[n];
				//������Ҫ�Ѿɿռ俽�����¿ռ�
				if (_start)//��ʼ�����_startΪ�գ�����Ҫ�������
				{
					//memcpy(tmp, _start, sz * sizeof(T));
					//ʹ��memcopy����ֵ�����:����string����˵���¿ռ��_str��ԭ_strָ���ͬһƬ�ռ�
					//��delete[] _start��ԭ�ռ��Ѿ�������(����������Ѿ�������)��_strָ����Ұָ��
					
					for (size_t i = 0; i < sz; i++)
					{
						tmp[i] = _start[i];
					}
					
					delete[] _start;

					//�ܽ�: ��Tʱ�������ͻ�ǳ�������Զ������ͣ��������ݻ򿽱������У���memcpy��û�������
					//����,T��������Զ������ͣ��������
					//ʹ��forѭ����ֵ����������⣺��Ϊtmp[i] = _start[i]���õ���string:operator=�����������

				}

				_start = tmp;//�ɿռ�ָ���¿ռ�
				//_finish = _start + size();//�����ǲ��Եģ���Ϊsize = finish - start,��ʱ��start�Ѿ����ˣ���һƬ�¿ռ�ĵ�ַ
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
			if (_finish == _endofstorage)//���ˣ���Ҫ����
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

		//���뺯���ڲ�Ҳ����pos������ʧЧ������
		void insert(iterator pos, const T& x)
		{
			if (_finish == _endofstorage)//����ռ����ˣ�����
			{
				//�ȼ���pos�����λ��
				size_t len = pos - _start;

				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);//���ݺ�pos��ָ��ɿռ䣬����Ҫ��pos���д���Ҫָ���¿ռ��lenλ��
				
				//����pos��������ݺ�posʧЧ������
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

			//���Ҫ����ⲿpos�����Ұָ����������1.������pos��2. ���������pos = pos+1
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

	//����pop_back
	void test_vector2()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);

		v.pop_back();
		v.pop_back();

	}

	//����resize
	void test_vector3()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		v.resize(3);//��ԭ�ռ�С���൱��ɾ������
		PrintVector(v);//1 2 3
		
		v.resize(6);//��ԭ�ռ�󣬵�û�г�������
		PrintVector(v);//1 2 3 0 0 0

		v.resize(10, 2); //��������
		PrintVector(v);//1 2 3 0 0 0 2 2 2 2

	}

	//����insert
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
		//insert�Ժ�pos������ʧЧ��1.posָ��λ�õ�������ˣ�pos����ָ��3��(����30) 2.����pos����Ұָ��
		PrintVector(v);//1 2 30 3 4 5 6 7 8
	}

	//����erase
	void test_vector5()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);

		//ɾ������ż��
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
		v1.push_back("55555");//����β����(���ݺ�)����
		
		for (const auto& e : v1)//Ϊ�˼������
		{
			cout << e << " ";
		}
		cout << endl;

	}
}





