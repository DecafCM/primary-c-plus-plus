#pragma once
#include <iostream>
#include "assert.h"

using std::cout;
using std::cin;
using std::endl;

class Date
{
public:
	Date(int year = 0, int month = 1, int day = 1);
	
	//打印
	void Print();
	//析构、拷贝构造、赋值重载，可以不写，因为默认生成的就够用了
	
	//day+= 100 加等天数
	Date& operator+=(int day);

	//day+ 100 加天数
	Date operator+(int day);
	
	//day-= 100 减等天数
	Date& operator-=(int day);

	//day -= 100 减天数
	Date operator-(int day);

	//*怎么区分前置++和后置++
	//++d  -> d.operator++(&d)
	Date& operator++();  //能加引用，后置++不能用引用返回
	//d++  -> d.operator++(&d, 0)
	Date operator++(int);//int 参数不需要给实参，因为没用，他的作用是为了跟前置++构成函数重载
	//--天数
	Date& operator--();
	//天数--
	Date operator--(int);

	//比较
	bool operator>(const Date& d);
	bool operator<(const Date& d);
	bool operator>=(const Date& d);
	bool operator<=(const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);

	//日期 - 日期
	int operator-(const Date& d);

private:
	int _year;
	int _month;
	int _day;
};
