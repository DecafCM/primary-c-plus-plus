#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <assert.h>

using namespace std;

//int main()
//{
//	//��õ�
//	//�޲ι���
//	string s1;
//	//���ι���
//	string s2("hello zqf");
//	//��������
//	string s3(s2);
//	//Ҳ��������
//	//��Ϊstring��֧��string(const char* s);�Ĺ��캯�����൱������"hello zqf"���죬�ٿ��������s4
//	//�������Ż�����ֱ�ӹ�����
//	string s4 = "hello zqf";
//
//	//string (const string& str, size_t pos, size_t len = npos);
//	//str��pos��ʼ����������len����,���len�����򿽱����ַ�����β
//	//string s5(s4, 3, string::npos); //Ҳ�ǿ������ַ�����β
//	string s5(s4, 3, 5);
//	cout << s5 << endl; //lo zq
//
//	//string(const char* s, size_t n); //��������s��ǰn���ַ�
//	string s6("hello zqf", 7);
//	cout << s6 << endl; //hello z
//
//	//string (size_t n, char c); //����һ��n���ַ����ַ���
//	string s7(10, 'x');
//	cout << s7 << endl;//xxxxxxxxxx
//
//	return 0;
//}

//int main()
//{
//	string s1;
//	string s2("hello zqf");
//
//	//���ֱ�����ʽ
//	//1���±� + []
//	for (size_t i = 0; i < s2.size(); ++i)
//	{
//		//s2.operator[](i) //*�ɶ���д
//		cout << s2[i] << " ";
//		//cout << s2.at(i) << " ";at�ǱȽ����ڵ��﷨����s2Ψһ�������ǣ���[]Խ������Ա���at�����쳣
//	}
//	cout << endl;
//
//	//2��������
//	//begin()���ص��ǿ�ʼ��λ�ã�end()���ص������һ�����ݵ���һ��λ��(�������һ�����ݵ�λ��)
//	//��Ҫע����ǣ�C++�з��ǵ�����һ�㶼�Ǹ�������ҿ�[)������
//	//��������ָ������
//	//�ɶ���д�������const_iterator�Ͳ����޸�
//	string::iterator it = s2.begin();
//	while (it != s2.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	//����������������:  ��string��vector֧��[]����������list��map�ȵ�������֧��[]
//	//��������һ��ͳһʹ�õķ�ʽ
//
//	//���������
//	string s3("123456"); //��ô���ű���s3?
//	string::reverse_iterator rit = s3.rbegin();
//	while (rit != s3.rend())
//	{
//		cout << *rit << " ";
//		rit++;
//	}
//	cout << endl;
//
//	//3��C++11 �ṩ ��λfor���ص�: д�����ܼ��
//	//����ȡ������(s3)�е�ֵ����e���Զ��жϽ��������Ҫ�޸���Ҫ���� for (auto& e : s3)
//	for (auto e : s3)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	return 0;
//}
//
//int main()
//{
//	string s1;
//	
//	//β��
//	s1.push_back('h');
//	s1.push_back('e');
//	s1.push_back('l');
//	s1.push_back('l');
//	s1.push_back('o');
//	//����һ��һ���ַ��Ĳ�����鷳
//
//	//append ���ַ�����׷��һ���ַ���
//	s1.append(" world");
//	cout << s1 << endl; //hello world
//
//	//Ҳ����appendһ������
//	string s2("!!");
//	s1.append(s2);
//	//������
//	s1.append(s2.begin(), s2.end());
//	cout << s1 << endl; //hello world!!!!
//
//	//*����ʵ���У���ϲ��ʹ��+=
//	string s3("hello");
//	s3 += " ";
//	s3 += "world";
//	s3 += s2;
//	cout << s3 << endl;//hello world!!
//
//	//��ͷ���м�λ�ò���*�ַ���*(˫����):insert,�����ǺϷ�λ�ò���
//	//��������insert,��Ϊ�ײ�ʵ�������飬ͷ�����м�����Ų������
//	//���: string& insert (size_t pos, const string& str);��string& insert (size_t pos, char* s);
//	string s4("11111");
//	s4.insert(0, "x");//�ڵ�0��λ�ò���"x"
//	s4.insert(2, "yy");//�ڵ�2��λ�ò���"yy"
//	//s4.insert(100, "x");//�Ƿ�λ�ò��룬����
//	cout << s4 << endl; //x1yy1111
//
//	//ɾ�� erase
//	//string& erase (size_t pos = 0, size_t len = npos);//Ĭ��ɾ��
//	string s5("hello");
//	s5.erase(0, 1);
//	//cout << s5 << endl;//ello
//	s5.erase();
//	cout << s5 << endl;//ȫɾ
//
//	return 0;
//}

//int main()
//{
//	string s1;
//	string s2("hello world");
//
//	//size():�����ַ�����Ч�ַ�����
//	cout << s1.size() << endl; //0
//	cout << s2.size() << endl; //11
//
//	//capacity():���ؿռ��ܴ�С
//	cout << s1.capacity() << endl; //15 ʵ���Ͽ��ٵĿռ���16������һ����'/0'
//	cout << s2.capacity() << endl; //15
//
//	//empty():�п� 
//	cout << s1.empty() << endl; //1
//
//	//clear():�����Ч�ַ���û�ͷſռ�,�ռ���������������������������٣�
//	s2.clear();
//	cout << s2.size() << endl;     //0
//	cout << s2.capacity() << endl; //15
//
//	return 0;
//}


//int main()
//{
//	string s1;
//	cout << "size:" << s1.size() << endl;  //0
//	cout << "capacity:" << s1.capacity() << endl; //15
//	cout << s1 << endl;
//
//	//resize():����Ч�ַ��ĸ����ĳ�n��������ж���Ŀռ����ַ�c���(��дĬ��Ϊ'\0')
//	s1.resize(20);
//	cout << "size:" << s1.size() << endl;  //20
//	cout << "capacity:" << s1.capacity() << endl; //31
//	cout << s1 << endl;
//
//	string s2("hello");
//	s2.resize(20, 'x');
//	cout << s2 << endl;//helloxxxxxxxxxxxxxxx
//
//	s2.resize(3);
//	cout << s2 << endl;//hel
//
//	//reserve: Ϊ�ַ���Ԥ���ռ�
//	string s3;
//	cout << "s3.size:" << s3.size() << endl;   //0
//	cout << "s3.capacity:" << s3.capacity() << endl;//15
//	s3.reserve(50);
//	cout << "s3.size:" << s3.size() << endl;   //0
//	cout << "s3.capacity:" << s3.capacity() << endl;//63
//
//	string s4;
//	s4.reserve(127); //��ʱcapacity��127��sizeΪ0���������ݾ��Ǵ��±�0��ʼ
//	//s4.resize(127); //��������capacity��127�ˣ���sizeҲ����127(Ĭ�ϲ���'\0')���������������128��λ�ý���
//	for (char ch = 0; ch < 127; ++ch)
//	{
//		//����reverse�ᷢ���������
//		s4 += ch;
//	}
//
//
//	return 0;
//}

//int main()
//{
//	//c_str: ��ȡc��ʽ���ַ���(��'\0'����)
//	string s1("hello world");
//	//��������һ���ģ����������
//	cout << s1 << endl;          //����operator<<(cout, s1)��� (�Զ������͵��������)
//	cout << s1.c_str() << endl; //���� operator<< (cout, const char*) (�������͵��������)
//
//	s1.resize(20);
//	s1 += "!!!";
//	cout << s1 << endl;         //hello world        !!!      
//	cout << s1.c_str() << endl; //hello world  ����'\0'�ͽ�ֹ�ˣ����º��������ַ��������
//	//c_str��Ҫ��Ϊ�����c���ԵĽӿ�ʹ��
//	cout << strlen(s1.c_str()) << endl; //11
//	cout << s1.size() << endl; //23
//
//	//find()
//	//����Ҫ��ȡ���ļ����ĺ�׺ -> �ҵ�'.' -> find()
//	string filename1 = "test.cpp";
//	//find(),�������ַ�Ҳ�������ַ������ҵ�����λ�ã�û�ҵ�����-1(�޷��ŵ�-1�����������ֵnpos)
//	size_t pos = filename1.find('.'); 
//	if (pos != string::npos)
//	{
//		//string suff(filename1, pos, filename.size() - pos);
//		string suff(filename1, pos);//��pos��������������������Ĭ��Ϊnpos
//		cout << suff << endl; //.cpp
//	}
//	
//	//rfind: ���ַ���posλ�ÿ�ʼ��ǰ���ַ�c�����ظ��ַ����ַ����е�λ��
//	string filename2("test.cpp.txt");
//	size_t pos2 = filename2.rfind('.');
//
//	//substr: ��str�д�posλ�ÿ�ʼ����ȡn���ַ���Ȼ���䷵��
//	//string substr (size_t pos = 0, size_t len = npos) const;
//	if (pos != string::npos)
//	{
//		string suff2 = filename2.substr(pos2);
//		cout << suff2 << endl;
//	}
//
//	return 0;
//}

////��������
//string GetDomain(const string& url)
//{
//	size_t pos = url.find("://");
//	if (pos != string::npos)
//	{
//		size_t start = pos + 3;
//		//�ҽ�����λ��
//		size_t end = url.find( '/', start);
//		if (end != string::npos)
//		{
//			return url.substr(start, end - start);
//		}
//	} 
//	else
//	{
//		return string();
//	}
//}
//
////����Э��
//string GetProtocol(const string& url)
//{
//	size_t pos = url.find("://");
//	if (pos != string::npos)
//	{
//		return url.substr(0, pos - 0);
//	}
//	else
//	{
//		//û�ҵ������ؿմ�
//		return string();
//	}
//}
//
//int main()
//{
//	//Ҫ��дһ������ֱ�д��������Э����
//	string url1 = "http://www.cplusplus.com/reference/string/string/rfind/";
//	string url2 = "https://tower.im/users/sign_in";
//	cout << GetDomain(url1) << endl;//www.cplusplus.com
//	cout << GetProtocol(url1) << endl; //http
//
//	cout << GetDomain(url2) << endl;//tower.im
//	cout << GetProtocol(url2) << endl; //https
//
//	return 0;
//}


//namespace zqf
//{
//	class string
//	{
//	public:
//		/*string()
//		:_str(new char[1])
//		{*_str = '\0';}
//		*/
//		//string(const char* str = "\0")    //����ʾ��,����д��Ȼ���ᱨ�����൱���ַ��������"\0\0"	
//		//string(const char* str = nullptr) //����ʾ��,��strlen(str)�л��str�����ó��ִ���
//		string(const char* str = "")//���������'\0'��ȥ��strlen(str) = 0
//		{
//			// ����string�����ʱ���������nullptrָ�룬��Ϊ����Ƿ����˴�������
//			if (nullptr == str)
//			{
//				assert(false);
//				return;
//			}
//
//			_str = new char[strlen(str) + 1];
//			strcpy(_str, str);
//		}
//
//		//��������
//		string(const string& s)//����s2(s1)��s2����this,s1����s
//			:_str(new char[strlen(s._str) + 1])//���:��һ���¿ռ䣬��s2��_strָ��ÿռ䣬�ٰ�s1�����ݿ�����ȥ
//		{
//			strcpy(_str, s._str);
//		}
//
//		//��ֵ���������
//		string& operator= (const string& s)
//		{
//			if (this != &s)
//			{
//				//s1 = s3;
//				//����ԭ���Ŀռ�(s1)���ٿ���һ���Ϳ�������(s3)һ����Ŀռ䣬�������ݿ�����ȥ
//				//��������Ϊ�˷�ֹs1�ռ�С��s3��ֱ�Ӱ�s3���ݿ���ȥ�������
//				delete[] _str;
//				_str = new char[strlen(s._str) + 1];
//				strcpy(_str, s._str);
//			}
//
//			return *this;
//		}
//
//		~string()
//		{
//			if (_str)
//			{
//				delete[] _str;
//				_str = nullptr;
//			}
//		}
//
//	private:
//		char* _str;
//	};
//}
//
//int main()
//{
//	zqf::string s1("hello zqf!!!");
//	zqf::string s2(s1); //ûд�������캯��ʱ������Ϊs2��s1��_strָ��ͬһ���ռ䣬��s2�ռ��ͷź�s1�ְѸÿռ��ͷ�һ�Σ��ͳ����˱���
//
//	zqf::string s3;
//	s3 = s1; //ûд��ֵ��������ػᱨ���Զ���������Ҫ��ʽ����
//
//	return 0;
//}

//class A
//{
//public:
//	A(int a = 0)
//	{
//		_a = a;
//	}
//private:
//	int _a;
//};
//
//void f1(A aa)
//{}
//
//A f2()
//{
//	//���ھ�̬����ֻ���ڵ�һ�ε��øú���ʱ�ᱻ��ʼ��
//	static A aa; 
//	return aa;
//}
//
//int main()
//{
//	//����Ӧ���ȹ���һ����ʱ�����������ٿ��������aa
//	//��ʵ���ϲ�û�е��ÿ������캯��
//	//���������Ż���Ϊ: 
//	//��ͬһ�����ʽ�У�������һ����ʱ����������ʱ���󿽱�����һ������ʱ
//	//���������ܻ�����Ż�������������϶�Ϊһ��ֱ�ӹ����һ������(C++��û�й涨Ҫ�Ż���һ����һ��ı����������Ż�)
//	f1(A());
//
//	//ͬ��
//	A a3 = 3;//���ﱾ��Ӧ�����ȹ���A tmp(3);����tmp���������a3���ᱻ�������Ż���ֱ�ӹ���a3
//
//	/*
//	f2();//��̬������һ�ε���ʱ�����ù��캯����ʼ��
//	f2();//��ξͲ�����ù��캯����
//	*/
//	
//	A a4 = f2(); //����Ӧ��: ����aa�������������ʱ��������ʱ�����ٿ�����a4
//	//ʵ���ϣ��������Ż���ֻ������һ�ο�������
//	//����������캯���ᱻ�Ż���һ��
//  
//
//	return 0;
//}

//namespace zqf
//{
//	//�����ַ��������飬������ɾ����
//	//�ַ�������Ľ�β��'\0'
//	class string
//	{
//	public:
//		//����
//		string(const char* str = "")
//			:_str(new char[strlen(str) + 1])
//		{
//			strcpy(_str, str);
//		}
//		/* ��ͳд��: ����һ����ͬ��С�Ŀռ䣬Ȼ�󿽱�
//		//��������
//		//s2(s1)
//		string(const string& s)
//			:_str(new char[strlen(s._str) + 1])
//		{
//			strcpy(_str, s._str);
//		}
//
//		//��ֵ����
//		//s3 = s1
//		string& operator=(const string& s)
//		{
//			//��ֹ�Լ����Լ���ֵ
//			if (this != &s)
//			{
//				delete[] _str;
//				_str = new char[strlen(s._str) + 1];
//				strcpy(_str, s._str);
//			}
//
//			return *this;
//		}
//		*/
//
//		//�ִ�д�� ˼��: ����Ū����������
//		//�������� s2(s1)
//		string(const string& s)
//			:_str(nullptr) //����ɿգ�_str���Ǹ����ֵ��������tmp�󣬵�����������ʱ�ᱨ��
//		{
//			string tmp(s._str);  //�����˹��캯����ʹ��tmp._str���˺�s._strһ����Ŀռ��ֵ
//			swap(_str, tmp._str);//�����ṩ�ģ��������;��ɽ���
//		}
//
//		//��ֵ��������� s1 = s3 
//		string& operator=(string s)//�������ʹ�õĴ�ֵ����Ϊ��������ÿ������죬����s��s3����һ���Ŀռ��ֵ
//		{
//			swap(_str, s._str);
//			return *this;
//		}
//
//		//����
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//
//		//�����ӡ
//		const char* c_str()
//		{
//			return _str;
//		}
//
//	private:
//		char* _str;
//	};
//
//}
//
//int main()
//{
//	zqf::string s1("hello world");
//	zqf::string s2(s1);
//
//	cout << s1.c_str() << endl;//hello world
//	cout << s2.c_str() << endl;//hello world
//
//	zqf::string s3("zqf");
//	s1 = s3;
//	cout << s1.c_str() << endl;//zqf
//
//	return 0;
//}

//namespace zqf
//{
//	//�����ַ��������飬������ɾ����
//	//�ַ�������Ľ�β��'\0'
//	class string
//	{
//	public:
//		//������
//		typedef char* iterator;
//		typedef const char* const_iterator;
//
//		iterator begin()//����д
//		{
//			return _str; //��Ԫ�ص�ַ
//		}
//
//		const_iterator begin()const //��
//		{
//			return _str;
//		}
//
//		iterator end()
//		{
//			return _str + _size;
//		}
//
//		const_iterator end() const
//		{
//			return _str + _size;
//		}
//
//		//����
//		string(const char* str = "")
//		{
//			_size = strlen(str);
//			_capacity = _size;
//			_str = new char[_capacity + 1];
//			
//			strcpy(_str, str);
//		}
//
//		//s1.swap(s2)
//		void swap(string& s)
//		{
//			::swap(_str, s._str); //::ǰ�治д˵����ȫ�ֵ�
//			::swap(_size, s._size);
//			::swap(_capacity, s._capacity);
//		}
//
//		//�ִ�д�� ˼��: ����Ū����������
//		//�������� s2(s1)
//		string(const string& s)
//			: _str(nullptr) //����ɿգ�_str���Ǹ����ֵ��������tmp�󣬵�����������ʱ�ᱨ��
//			, _size(0)
//			, _capacity(0)
//		{
//			string tmp(s._str);  //�����˹��캯����ʹ��tmp._str���˺�s._strһ����Ŀռ��ֵ
//			//ȫ����ע�ⲻ��ֱ��string tmp(s)���������ڿ����������ֵ��ÿ������죬��ѭ��
//			/*swap(_str, tmp._str);
//			swap(_size, tmp._size);
//			swap(_capacity, tmp._capacity);*/
//			
//			swap(tmp);//this->swap(tmp);
//
//		}
//
//		//��ֵ��������� s1 = s3 
//		string& operator=(string s)//�������ʹ�õĴ�ֵ����Ϊ��������ÿ������죬����s��s3����һ���Ŀռ��ֵ
//		{
//			/*
//			swap(_str, s._str);
//			swap(_size, s._size);
//			swap(_capacity, s._capacity);
//			*/
//			
//			swap(s);//this->swap(s);
//
//			return *this;
//		}
//
//		//����
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//			_size = 0;
//			_capacity = 0;
//		}
//
//		//���� ��Ҫд�����汾
//		//const�汾 ��
//		const char& operator[](size_t i)const //ֻ�ܶ�
//		{
//			assert(i < _size); //��ֹԽ��
//			return _str[i];
//		}
//		//��const�汾 �ɶ���д
//		char& operator[](size_t i)//�ɶ���д������const����ʹ��
//		{
//			assert(i < _size); //��ֹԽ��
//			return _str[i];
//		}
//
//		//���ռ䣬��չcapacity
//		void reserve(size_t n)
//		{
//			if (n > _capacity)
//			{
//				char* tmp = new char[n + 1];
//				strcpy(tmp, _str);
//				delete[] _str;
//
//				_str = tmp;
//				_capacity = n;
//			}
//		}
//
//		//���ռ� + ��ʼ������չcapacity���ҳ�ʼ���ռ䣬sizeҲҪ��
//		//�������:
//		//1. n < size
//		//2. size < n < capacity
//		//3. n > capacity
//		void resize(size_t n, char val = '\0')
//		{
//			if (n < _size)
//			{
//				_size = n;
//				_str[_size] = '\0';
//			}
//			else
//			{
//				if (n > _capacity)
//				{
//					reserve(n);
//				}
//
//				//memset(_str+_size, val, n-_size);
//				for (size_t i = _size; i < n; i++)
//				{
//					_str[i] = val;
//				}
//
//				_str[n] = '\0';
//				_size = n;
//
//			}
//		}
//
//		//�����ַ�
//		void push_back(char ch)
//		{
//			/*if (_size == _capacity)
//			{
//				size_t new_capacity = _capacity == 0 ? 4 : _capacity * 2;
//				reserve(new_capacity);
//			}
//			_str[_size] = ch;
//			_str[_size + 1] = '\0';
//			_size++;*/
//			//����
//			insert(_size, ch);
//		}
//
//		//�����ַ���
//		void append(const char* str)
//		{
//			////�������Ҫ���ٳ��ȣ�����ֱ���������ļ��������ݣ���Ϊstr���ܻᳬ���������
//			/*size_t len = _size + strlen(str);
//			if (len > _capacity)
//			{
//				reserve(len);
//			}
//
//			strcpy(_str + _size, str);
//			_size = len;*/
//			//����
//			insert(_size, str);
//		}
//
//		//����õĲ���(�ַ�)
//		string& operator+=(char ch)
//		{
//			push_back(ch);
//			return *this;
//		}
//
//		//����õĲ���(�ַ���)
//		string& operator+=(const char* str)
//		{
//			append(str);
//			return *this;
//		}
//
//		//posλ�ò����ַ�
//		string& insert(size_t pos, char ch)
//		{
//			assert(pos <= _size);
//
//			if (_size == _capacity)
//			{
//				size_t new_capacity = _capacity == 0 ? 4 : _capacity * 2;
//				reserve(new_capacity);
//			}
//
//			//���Ƽ�
//			//int end = _size; //˳����Ǵ�size��ʼŲ�������ǰ�'\0'Ҳ����Ų
//			//while (end >= (int)pos)//����pos���޷������ͣ��Ƚ�ʱ���Զ���end��int����ת�����޷������ͣ�������Ҫǿ������ת��
//			//{
//			//	_str[end + 1] = _str[end];
//			//	end--; //�״�㣺����end��������������Բ�����size_t������end������������ѭ��
//			//}
//
//			//�ı��±����ָ��
//			size_t end = _size + 1; //�������ó�size+1,����ѭ�������end������ɸ���
//			while (end > pos)
//			{
//				_str[end] = _str[end - 1];
//				end--; 
//			}
//			
//			_str[pos] = ch;
//			_size++;
//
//			return *this;
//
//		}
//		//posλ�ò����ַ���
//		string& insert(size_t pos,const char* str)
//		{
//			assert(pos <= _size);
//			size_t len = strlen(str);
//
//			if (_size + len > _capacity)
//			{
//				reserve(_size + len);
//			}
//
//			//Ų��(��ָ��)
//			char* end = _str + _size;
//			while (end >= _str + pos)
//			{
//				*(end + len) = *end;
//				end--;
//			}
//
//			//strcpy(_str + pos, str);//�������У���Ϊ���'\0'Ҳ��������
//			strncpy(_str + pos, str, len);
//			_size += len;
//
//			return *this;
//
//		}
//
//		//ɾ��
//		string& erase(size_t pos, size_t len = npos)
//		{
//			assert(pos < _size);
//			size_t leftLen = _size - pos;
//
//			//1. ʣ���ַ�����С�ڵ���Ҫɾ�ĳ���
//			if (len >= leftLen)//˵��pos������ַ�Ҫɾ��
//			{
//				_str[pos] = '\0';
//				_size = pos;
//			}
//			else //ʣ���ַ����ȴ���Ҫɾ���ĳ���
//			{
//				//Ų��(�Ѻ���Ԫ����ǰ����)
//				strcpy(_str + pos, _str + pos + len);
//				_size -= len;
//			}
//
//			return *this;
//		}
//
//		//�����ַ�
//		size_t find(char ch, size_t pos = 0)
//		{
//			assert(pos < _size);
//
//			for (size_t i = pos; i < _size; ++i)
//			{
//				if (_str[i] = ch)
//				{
//					return i;
//				}
//			}
//
//			return npos;
//		}
//		//�����ַ���
//		size_t find(const char* str, size_t pos = 0)
//		{
//			assert(pos < _size);
//
//			const char* ret = strstr(_str + pos, str);
//			if (ret)
//			{
//				return ret - _str;//��ͼ���
//			}
//			else
//			{
//				return npos;
//			}
//		}
//
//		//�ַ�������
//		size_t size() const
//		{
//			return _size;
//		}
//
//		void clear()
//		{
//			_size = 0;
//			_str[0] = '\0';
//		}
//
//		//�����ӡ
//		const char* c_str()const
//		{
//			return _str;
//		}
//
//		void f(const string& s)
//		{
//			for (size_t i = 0; i < s.size(); i++)
//			{
//				//s[i] += 1; //������Ϊs��const���󣬵��õ�operator[]��const�汾
//				cout << s[i] << " ";
//			}
//			cout << endl;
//		}
//
//		void test_iterator()
//		{
//			string s1("hello world");
//			string::iterator it = s1.begin();
//			while (it != s1.end())
//			{
//				cout << *it << " ";
//				++it;
//			}
//			cout << endl;
//		}
//
//	private:
//		char* _str;
//		size_t _size;
//		size_t _capacity;
//		//ע��:����ܿռ���10byte,��_size���ֵ��9����Ϊ���һ��λ��Ҫ��'/0'
//		//_capacity������10Ҳ������9�������9(��Ч�ַ�����)
//
//		static const size_t npos;
//	};
//
//	const size_t string::npos = -1;
//
//	bool operator<(const string& s1, const string& s2)
//	{
//		return strcmp(s1.c_str(), s2.c_str()) < 0;
//	}
//	bool operator==(const string& s1, const string& s2)
//	{
//		return strcmp(s1.c_str(), s2.c_str()) == 0;
//	}
//	bool operator<=(const string& s1, const string& s2)
//	{
//		return (s1 < s2) || (s1 == s2);
//	}
//	bool operator>(const string& s1, const string& s2)
//	{
//		return !(s1 <= s2);
//	}
//	bool operator>=(const string& s1, const string& s2)
//	{
//		return !(s1 < s2);
//	}
//	bool operator!=(const string& s1, const string& s2)
//	{
//		return !(s1 == s2);
//	}
//	
//	//���
//	ostream& operator<<(ostream& out, const string& s)
//	{
//		for (auto ch : s)
//		{
//			out << ch;
//		}
//
//		return out;
//	}
//
//	//����
//	istream& operator>>(istream& in, string& s)
//	{
//		//���sԭ�������� �������
//		s.clear();
//		char ch;
//		//in >> ch;//�������У���Ϊcin���Զ��ѿո�ͻ��е�������Ԫ��֮��ļ����
//		ch = in.get();
//		while (ch != ' ' && ch != '\n')//�����ո�ͻ��н���
//		{
//			s += ch;
//			ch = in.get();
//		}
//
//		return in;
//	}
//
//	//����
//	istream& getline(istream& in, string& s)
//	{
//		//���sԭ�������� �������
//		s.clear();
//		char ch;
//		//in >> ch;//�������У���Ϊcin���Զ��ѿո�ͻ��е�������Ԫ��֮��ļ����
//		ch = in.get();
//		while (ch != '\n')//�������в�ֹͣ
//		{
//			s += ch;
//			ch = in.get();
//		}
//
//		return in;
//	}
//
//
//}
//
//int main()
//{
//	zqf::string s1("hello world");
//	zqf::string s2(s1);
//
//	cout << s1.c_str() << endl;//hello world
//	cout << s2.c_str() << endl;//hello world
//
//	zqf::string s3("zqf");
//	s1 = s3;
//	cout << s1.c_str() << endl;//zqf
//
//	zqf::string s4("hello world");
//	s4[0] = 'x';
//	cout << s4[0] << endl; //x
//	cout << s4.c_str() << endl;//xello world
//
//	//[]����
//	for (size_t i = 0; i < s4.size(); i++)
//	{
//		cout << s4[i] << " ";
//	}
//	cout << endl;
//	
//	//Ϊ˵��const�����ܵ�����ͨ��Ա��������size()��������const
//	s4.f(s4);
//
//	//����������
//	s4.test_iterator();
//
//	//��Χfor����
//	//�����������棬��ԭ��ܼ򵥣���Χfor�ᱻ�������滻�ɵ�������ʽ
//	for (auto ch : s4)
//	{
//		cout << ch << " ";
//	}
//	cout << endl;
//
//	s4.push_back(' ');
//	s4.push_back('h');
//	s4.append("ello");
//	s4 += "!!!!!!!!!!!!!!!!";
//	cout << s4.c_str() << endl;//xello world hello!!!!!!!!!!!!!!!!
//
//	s4.resize(6);
//	cout << s4.c_str() << endl;//xello
//
//	zqf::string s5("ello");
//	s5.insert(0, 'h');
//	cout << s5.c_str() << endl;//hello 
//	
//	s5.insert(5, " world");
//	cout << s5.c_str() << endl;//hello world
//
//	s5.erase(5);
//	cout << s5.c_str() << endl;//hello
//
//	cout << (s5 <= s4) << endl; //1
//
//	cout << s5 << endl;//hello
//
//	cin >> s5;
//	cout << s5 << endl;//hello
//
//	zqf::string line;
//	zqf::getline(cin, line);
//	cout << line << endl;
//
//	return 0;
//}