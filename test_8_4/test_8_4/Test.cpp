#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <assert.h>

using namespace std;

//int main()
//{
//	//最常用的
//	//无参构造
//	string s1;
//	//带参构造
//	string s2("hello zqf");
//	//拷贝构造
//	string s3(s2);
//	//也可以这样
//	//因为string类支持string(const char* s);的构造函数，相当于先用"hello zqf"构造，再拷贝构造给s4
//	//编译器优化后变成直接构造了
//	string s4 = "hello zqf";
//
//	//string (const string& str, size_t pos, size_t len = npos);
//	//str从pos开始，拷贝构造len长度,如果len过大，则拷贝到字符串结尾
//	//string s5(s4, 3, string::npos); //也是拷贝到字符串结尾
//	string s5(s4, 3, 5);
//	cout << s5 << endl; //lo zq
//
//	//string(const char* s, size_t n); //拷贝构造s的前n个字符
//	string s6("hello zqf", 7);
//	cout << s6 << endl; //hello z
//
//	//string (size_t n, char c); //构造一个n个字符的字符串
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
//	//三种遍历方式
//	//1、下标 + []
//	for (size_t i = 0; i < s2.size(); ++i)
//	{
//		//s2.operator[](i) //*可读可写
//		cout << s2[i] << " ";
//		//cout << s2.at(i) << " ";at是比较早期的语法，和s2唯一的区别是，用[]越界后会断言报错，at会抛异常
//	}
//	cout << endl;
//
//	//2、迭代器
//	//begin()返回的是开始的位置，end()返回的是最后一个数据的下一个位置(不是最后一个数据的位置)
//	//需要注意的是，C++中凡是迭代器一般都是给的左闭右开[)的区间
//	//迭代器和指针类似
//	//可读可写，如果是const_iterator就不能修改
//	string::iterator it = s2.begin();
//	while (it != s2.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	//迭代器的意义在于:  像string、vector支持[]遍历，但是list、map等等容器不支持[]
//	//迭代器是一种统一使用的方式
//
//	//反向迭代器
//	string s3("123456"); //怎么倒着遍历s3?
//	string::reverse_iterator rit = s3.rbegin();
//	while (rit != s3.rend())
//	{
//		cout << *rit << " ";
//		rit++;
//	}
//	cout << endl;
//
//	//3、C++11 提供 单位for，特点: 写起来很简洁
//	//依次取出容器(s3)中的值赋给e，自动判断结束，如果要修改需要这样 for (auto& e : s3)
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
//	//尾插
//	s1.push_back('h');
//	s1.push_back('e');
//	s1.push_back('l');
//	s1.push_back('l');
//	s1.push_back('o');
//	//这样一个一个字符的插入很麻烦
//
//	//append 在字符串后追加一个字符串
//	s1.append(" world");
//	cout << s1 << endl; //hello world
//
//	//也可以append一个对象
//	string s2("!!");
//	s1.append(s2);
//	//迭代器
//	s1.append(s2.begin(), s2.end());
//	cout << s1 << endl; //hello world!!!!
//
//	//*但在实际中，最喜欢使用+=
//	string s3("hello");
//	s3 += " ";
//	s3 += "world";
//	s3 += s2;
//	cout << s3 << endl;//hello world!!
//
//	//在头或中间位置插入*字符串*(双引号):insert,必须是合法位置插入
//	//尽量少用insert,因为底层实现是数组，头部或中间插入会挪动数据
//	//最常用: string& insert (size_t pos, const string& str);和string& insert (size_t pos, char* s);
//	string s4("11111");
//	s4.insert(0, "x");//在第0个位置插入"x"
//	s4.insert(2, "yy");//在第2个位置插入"yy"
//	//s4.insert(100, "x");//非法位置插入，报错
//	cout << s4 << endl; //x1yy1111
//
//	//删除 erase
//	//string& erase (size_t pos = 0, size_t len = npos);//默认删完
//	string s5("hello");
//	s5.erase(0, 1);
//	//cout << s5 << endl;//ello
//	s5.erase();
//	cout << s5 << endl;//全删
//
//	return 0;
//}

//int main()
//{
//	string s1;
//	string s2("hello world");
//
//	//size():返回字符串有效字符长度
//	cout << s1.size() << endl; //0
//	cout << s2.size() << endl; //11
//
//	//capacity():返回空间总大小
//	cout << s1.capacity() << endl; //15 实际上开辟的空间是16，留了一个给'/0'
//	cout << s2.capacity() << endl; //15
//
//	//empty():判空 
//	cout << s1.empty() << endl; //1
//
//	//clear():清空有效字符（没释放空间,空间在作用域结束调用析构函数销毁）
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
//	//resize():将有效字符的个数改成n个，如果有多出的空间用字符c填充(不写默认为'\0')
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
//	//reserve: 为字符串预留空间
//	string s3;
//	cout << "s3.size:" << s3.size() << endl;   //0
//	cout << "s3.capacity:" << s3.capacity() << endl;//15
//	s3.reserve(50);
//	cout << "s3.size:" << s3.size() << endl;   //0
//	cout << "s3.capacity:" << s3.capacity() << endl;//63
//
//	string s4;
//	s4.reserve(127); //此时capacity到127，size为0，插入数据就是从下标0开始
//	//s4.resize(127); //区别在于capacity到127了，但size也到了127(默认插入'\0')，插入操作是在向128的位置进行
//	for (char ch = 0; ch < 127; ++ch)
//	{
//		//不用reverse会发生多次增容
//		s4 += ch;
//	}
//
//
//	return 0;
//}

//int main()
//{
//	//c_str: 获取c形式的字符串(到'\0'结束)
//	string s1("hello world");
//	//输出结果是一样的，区别在哪里？
//	cout << s1 << endl;          //调用operator<<(cout, s1)输出 (自定义类型的重载输出)
//	cout << s1.c_str() << endl; //调用 operator<< (cout, const char*) (内置类型的重载输出)
//
//	s1.resize(20);
//	s1 += "!!!";
//	cout << s1 << endl;         //hello world        !!!      
//	cout << s1.c_str() << endl; //hello world  遇到'\0'就截止了，导致后续还有字符输出不了
//	//c_str主要是为了配合c语言的接口使用
//	cout << strlen(s1.c_str()) << endl; //11
//	cout << s1.size() << endl; //23
//
//	//find()
//	//假设要求取出文件名的后缀 -> 找到'.' -> find()
//	string filename1 = "test.cpp";
//	//find(),可以找字符也可以找字符串。找到返回位置，没找到返回-1(无符号的-1，即整型最大值npos)
//	size_t pos = filename1.find('.'); 
//	if (pos != string::npos)
//	{
//		//string suff(filename1, pos, filename.size() - pos);
//		string suff(filename1, pos);//从pos拷贝到结束，拷贝长度默认为npos
//		cout << suff << endl; //.cpp
//	}
//	
//	//rfind: 从字符串pos位置开始往前找字符c，返回该字符在字符串中的位置
//	string filename2("test.cpp.txt");
//	size_t pos2 = filename2.rfind('.');
//
//	//substr: 在str中从pos位置开始，截取n个字符，然后将其返回
//	//string substr (size_t pos = 0, size_t len = npos) const;
//	if (pos != string::npos)
//	{
//		string suff2 = filename2.substr(pos2);
//		cout << suff2 << endl;
//	}
//
//	return 0;
//}

////返回域名
//string GetDomain(const string& url)
//{
//	size_t pos = url.find("://");
//	if (pos != string::npos)
//	{
//		size_t start = pos + 3;
//		//找结束的位置
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
////返回协议
//string GetProtocol(const string& url)
//{
//	size_t pos = url.find("://");
//	if (pos != string::npos)
//	{
//		return url.substr(0, pos - 0);
//	}
//	else
//	{
//		//没找到，返回空串
//		return string();
//	}
//}
//
//int main()
//{
//	//要求写一个程序分别写出域名和协议名
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
//		//string(const char* str = "\0")    //错误示范,这样写虽然不会报错，但相当于字符串变成了"\0\0"	
//		//string(const char* str = nullptr) //错误示范,在strlen(str)中会对str解引用出现错误
//		string(const char* str = "")//编译器会存'\0'进去，strlen(str) = 0
//		{
//			// 构造string类对象时，如果传递nullptr指针，认为程序非法，此处断言下
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
//		//拷贝构造
//		string(const string& s)//对于s2(s1)把s2传给this,s1传给s
//			:_str(new char[strlen(s._str) + 1])//深拷贝:开一个新空间，让s2的_str指向该空间，再把s1的数据拷贝过去
//		{
//			strcpy(_str, s._str);
//		}
//
//		//赋值运算符重载
//		string& operator= (const string& s)
//		{
//			if (this != &s)
//			{
//				//s1 = s3;
//				//销毁原来的空间(s1)，再开辟一个和拷贝内容(s3)一样大的空间，最后把数据拷贝过去
//				//这样做是为了防止s1空间小于s3，直接把s3数据拷过去会出问题
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
//	zqf::string s2(s1); //没写拷贝构造函数时报错，因为s2和s1的_str指向同一个空间，当s2空间释放后，s1又把该空间释放一次，就出现了报错
//
//	zqf::string s3;
//	s3 = s1; //没写赋值运算符重载会报错，自定义类型需要显式定义
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
//	//对于静态变量只有在第一次调用该函数时会被初始化
//	static A aa; 
//	return aa;
//}
//
//int main()
//{
//	//本来应该先构造一个临时的匿名对象，再拷贝构造给aa
//	//但实际上并没有调用拷贝构造函数
//	//编译器的优化行为: 
//	//在同一个表达式中，产生了一个临时对象，再用临时对象拷贝构造一个对象时
//	//编译器可能会进行优化，让两个对象合二为一，直接构造出一个对象(C++并没有规定要优化，一般新一点的编译器都会优化)
//	f1(A());
//
//	//同理
//	A a3 = 3;//这里本来应该是先构造A tmp(3);再用tmp拷贝构造给a3，会被编译器优化成直接构造a3
//
//	/*
//	f2();//静态变量第一次调用时候会调用构造函数初始化
//	f2();//这次就不会调用构造函数了
//	*/
//	
//	A a4 = f2(); //本来应该: 构造aa，拷贝构造给临时变量，临时变量再拷贝给a4
//	//实际上，编译器优化后只发生了一次拷贝构造
//	//连续多个构造函数会被优化成一次
//  
//
//	return 0;
//}

//namespace zqf
//{
//	//管理字符串的数组，可以增删查修
//	//字符串数组的结尾又'\0'
//	class string
//	{
//	public:
//		//构造
//		string(const char* str = "")
//			:_str(new char[strlen(str) + 1])
//		{
//			strcpy(_str, str);
//		}
//		/* 传统写法: 开辟一个相同大小的空间，然后拷贝
//		//拷贝构造
//		//s2(s1)
//		string(const string& s)
//			:_str(new char[strlen(s._str) + 1])
//		{
//			strcpy(_str, s._str);
//		}
//
//		//赋值重载
//		//s3 = s1
//		string& operator=(const string& s)
//		{
//			//防止自己给自己赋值
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
//		//现代写法 思想: 别人弄好我来交换
//		//拷贝构造 s2(s1)
//		string(const string& s)
//			:_str(nullptr) //不设成空，_str就是个随机值，交换给tmp后，调用析构函数时会报错
//		{
//			string tmp(s._str);  //调用了构造函数，使得tmp._str有了和s._str一样大的空间和值
//			swap(_str, tmp._str);//库里提供的，任意类型均可交换
//		}
//
//		//赋值运算符重载 s1 = s3 
//		string& operator=(string s)//这里故意使用的传值，因为这样会调用拷贝构造，这样s和s3有了一样的空间和值
//		{
//			swap(_str, s._str);
//			return *this;
//		}
//
//		//析构
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//
//		//方便打印
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
//	//管理字符串的数组，可以增删查修
//	//字符串数组的结尾有'\0'
//	class string
//	{
//	public:
//		//迭代器
//		typedef char* iterator;
//		typedef const char* const_iterator;
//
//		iterator begin()//读、写
//		{
//			return _str; //首元素地址
//		}
//
//		const_iterator begin()const //读
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
//		//构造
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
//			::swap(_str, s._str); //::前面不写说明是全局的
//			::swap(_size, s._size);
//			::swap(_capacity, s._capacity);
//		}
//
//		//现代写法 思想: 别人弄好我来交换
//		//拷贝构造 s2(s1)
//		string(const string& s)
//			: _str(nullptr) //不设成空，_str就是个随机值，交换给tmp后，调用析构函数时会报错
//			, _size(0)
//			, _capacity(0)
//		{
//			string tmp(s._str);  //调用了构造函数，使得tmp._str有了和s._str一样大的空间和值
//			//全换。注意不能直接string tmp(s)，这样会在拷贝构造里又调用拷贝构造，死循环
//			/*swap(_str, tmp._str);
//			swap(_size, tmp._size);
//			swap(_capacity, tmp._capacity);*/
//			
//			swap(tmp);//this->swap(tmp);
//
//		}
//
//		//赋值运算符重载 s1 = s3 
//		string& operator=(string s)//这里故意使用的传值，因为这样会调用拷贝构造，这样s和s3有了一样的空间和值
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
//		//析构
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//			_size = 0;
//			_capacity = 0;
//		}
//
//		//遍历 需要写两个版本
//		//const版本 读
//		const char& operator[](size_t i)const //只能读
//		{
//			assert(i < _size); //防止越界
//			return _str[i];
//		}
//		//非const版本 可读可写
//		char& operator[](size_t i)//可读可写，给非const对象使用
//		{
//			assert(i < _size); //防止越界
//			return _str[i];
//		}
//
//		//开空间，扩展capacity
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
//		//开空间 + 初始化，扩展capacity并且初始化空间，size也要动
//		//三种情况:
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
//		//插入字符
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
//			//复用
//			insert(_size, ch);
//		}
//
//		//插入字符串
//		void append(const char* str)
//		{
//			////先算出需要多少长度，不能直接用容量的几倍来扩容，因为str可能会超出这个容量
//			/*size_t len = _size + strlen(str);
//			if (len > _capacity)
//			{
//				reserve(len);
//			}
//
//			strcpy(_str + _size, str);
//			_size = len;*/
//			//复用
//			insert(_size, str);
//		}
//
//		//最好用的插入(字符)
//		string& operator+=(char ch)
//		{
//			push_back(ch);
//			return *this;
//		}
//
//		//最好用的插入(字符串)
//		string& operator+=(const char* str)
//		{
//			append(str);
//			return *this;
//		}
//
//		//pos位置插入字符
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
//			//不推荐
//			//int end = _size; //顺序表是从size开始挪，这里是把'\0'也往后挪
//			//while (end >= (int)pos)//由于pos是无符号整型，比较时会自动把end从int类型转换成无符号整型，所以需要强制类型转换
//			//{
//			//	_str[end + 1] = _str[end];
//			//	end--; //易错点：这里end会减到负数，所以不能用size_t来定义end，否则会造成死循环
//			//}
//
//			//改变下标或用指针
//			size_t end = _size + 1; //故意设置成size+1,好让循环的最后end不会减成负数
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
//		//pos位置插入字符串
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
//			//挪动(用指针)
//			char* end = _str + _size;
//			while (end >= _str + pos)
//			{
//				*(end + len) = *end;
//				end--;
//			}
//
//			//strcpy(_str + pos, str);//这样不行，因为会把'\0'也拷贝进来
//			strncpy(_str + pos, str, len);
//			_size += len;
//
//			return *this;
//
//		}
//
//		//删除
//		string& erase(size_t pos, size_t len = npos)
//		{
//			assert(pos < _size);
//			size_t leftLen = _size - pos;
//
//			//1. 剩余字符长度小于等于要删的长度
//			if (len >= leftLen)//说明pos后面的字符要删完
//			{
//				_str[pos] = '\0';
//				_size = pos;
//			}
//			else //剩余字符长度大于要删除的长度
//			{
//				//挪动(把后面元素往前面移)
//				strcpy(_str + pos, _str + pos + len);
//				_size -= len;
//			}
//
//			return *this;
//		}
//
//		//查找字符
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
//		//查找字符串
//		size_t find(const char* str, size_t pos = 0)
//		{
//			assert(pos < _size);
//
//			const char* ret = strstr(_str + pos, str);
//			if (ret)
//			{
//				return ret - _str;//画图理解
//			}
//			else
//			{
//				return npos;
//			}
//		}
//
//		//字符串长度
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
//		//方便打印
//		const char* c_str()const
//		{
//			return _str;
//		}
//
//		void f(const string& s)
//		{
//			for (size_t i = 0; i < s.size(); i++)
//			{
//				//s[i] += 1; //报错，因为s是const对象，调用的operator[]的const版本
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
//		//注意:如果总空间是10byte,则_size最大值是9，因为最后一个位置要给'/0'
//		//_capacity可以是10也可以是9，建议给9(有效字符个数)
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
//	//输出
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
//	//输入
//	istream& operator>>(istream& in, string& s)
//	{
//		//如果s原来有数据 先清理掉
//		s.clear();
//		char ch;
//		//in >> ch;//这样不行，因为cin会自动把空格和换行当成输入元素之间的间隔符
//		ch = in.get();
//		while (ch != ' ' && ch != '\n')//遇到空格和换行结束
//		{
//			s += ch;
//			ch = in.get();
//		}
//
//		return in;
//	}
//
//	//输入
//	istream& getline(istream& in, string& s)
//	{
//		//如果s原来有数据 先清理掉
//		s.clear();
//		char ch;
//		//in >> ch;//这样不行，因为cin会自动把空格和换行当成输入元素之间的间隔符
//		ch = in.get();
//		while (ch != '\n')//遇到换行才停止
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
//	//[]遍历
//	for (size_t i = 0; i < s4.size(); i++)
//	{
//		cout << s4[i] << " ";
//	}
//	cout << endl;
//	
//	//为说明const对象不能调用普通成员函数，让size()函数加上const
//	s4.f(s4);
//
//	//迭代器遍历
//	s4.test_iterator();
//
//	//范围for遍历
//	//看起来很神奇，但原理很简单，范围for会被编译器替换成迭代器形式
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