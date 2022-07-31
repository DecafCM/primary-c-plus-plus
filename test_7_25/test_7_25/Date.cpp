#define _CRT_SECURE_NO_WARNINGS 1

#include "Date.h"
 
inline int GetMonthDay(int year, int month) //由于会被频繁调用，所以定义成内联函数
{
	//存储每个月的天数(不考虑二月是否为闰年的情况),用static把数组放到静态区，频繁调用时不需要每次都创建数组
	static int dayArry[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31 , 30, 31, 30, 31 };
	int day = dayArry[month];
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
	{
		day = 29;
	}

	return day;
}

Date::Date(int year, int month, int day)
{
	//检查日期合法性
	if (year >= 0 
		&& month >0 && month < 13
		&& day > 0 && day <= GetMonthDay(year, month)) 
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		cout << "非法日期" << endl;
		//严格来说抛异常更好
		//assert(false);
	}
}

void Date::Print()
{
	cout << _year << "年" << _month << "月" << _day << "日" << endl;
}

//day+= 100 加等天数
//类似加法的进位规则: 
//1、天满了，减去当月的天数，月加1;2、月满了，年加1，再把月置成1
//2021 5 25 + 20天
//2021 5 45 //检查是否合法
//-> 2021 6 (45- GetMonthDay(2021, 6)) 此时再检查是否合法
Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		*this -= -day;
	}
	else
	{
		_day += day;
		//天数不合法，不断进位，让他合法
		while (_day > GetMonthDay(_year, _month)) //_day <= GetMonthDay()说明是合法的
		{
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month > 12)
			{
				_year++;
				_month = 1;
			}
		}
	}

	return *this;
}

//day+ 100 加天数
Date Date::operator+(int day)
{
	Date ret(*this);
	/*
	ret._day += day;
	while (ret._day > GetMonthDay(ret._year, ret._month))
	{
		ret._day -= GetMonthDay(ret._year, ret._month);
		ret._month++;
		if (ret._month > 12)
		{
			ret._year++;
			ret._month = 1;
		}
	*/
	
	//复用
	ret += day;
	return ret; //这里ret是一个临时对象，不能用引用返回

}

//day -= 100 减等天数
//如果day是负数如何处理？//减一个负数等于加一个正数，用+=的逻辑即可
Date& Date::operator-=(int day)
{
	if(day < 0)
	{
		//_day += -day;
		////天数不合法，不断进位，让他合法
		//while (_day > GetMonthDay(_year, _month)) //_day <= GetMonthDay()说明是合法的
		//{
		//	_day -= GetMonthDay(_year, _month);
		//	_month++;
		//	if (_month > 12)
		//	{
		//		_year++;
		//		_month = 1;
		//	}
		//}

		//复用
		*this += -day;
	}
	else
	{
		_day -= day;
		while (_day <= 0) //0号也是不合法的
		{
			_month--; //先减是因为，是用前一个月的天数来算，如5月-5日，是用的4月的30+(-5)
			if (_month == 0)
			{
				_year--;
				_month = 12;
			}

			_day += GetMonthDay(_year, _month);
	}
	}

	return *this;
}

////day - 100 减天数
Date Date::operator-(int day)
{
	Date ret(*this); //Date ret = (*this);
	
	//复用
	ret -= day;//ret.operator-=(&ret.day)

	return ret;
}

//前置++和后置++都完成了+1，不同的地方在于返回值不一样
//由于他们运算符是一样的，函数名就是一样的，为了区分，对后置++做了特殊处理,加了一个参数，形成函数重载
//++d  -> d.operator++(&d)
Date& Date::operator++() //能加引用，后置++不能用引用返回
{
	*this += 1;
	return *this;
}

//d++  -> d.operator++(&d, 0)
Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;

	return tmp;
}

//--天数
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}
//天数--
Date Date::operator--(int)
{
	Date tmp = *this;
	*this -= 1;

	return tmp;
}

//比较

bool Date::operator==(const Date& d)
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

//d1 > d2 -> d1.operator>(&d1, d2)
bool Date::operator>(const Date& d)
{
	if (_year > d._year)
	{
		return true;
	}
	else if (_year == d._year)
	{
		if (_month > d._month)
		{
			return true;
		}
		else if (_month == d._month)
		{
			if (_day > d._day)
			{
				return true;
			}
		}
	}

	return false;
}
bool Date::operator<(const Date& d)
{
	//复用
	return !(*this >= d);
}
bool Date::operator>=(const Date& d)
{
	//复用
	return *this > d || *this == d;
}
bool Date::operator<=(const Date& d)
{
	//复用
	return !(*this > d);
}
bool Date::operator!=(const Date& d)
{
	//复用
	return !(*this == d);
}

//日期 - 日期
//别想着用年-年，月-月...因为每个月天数不一样，这样非常复杂
//最好的思路:让小的日期不断++知道加到大日期，加了多少次就差了多少天
int Date::operator-(const Date& d)
{
	//假设第一个日期大
	Date max = *this;
	Date min = d;
	int flag = 1; //第一个大，相减为正数，最后用n*flag表示即可
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;//第一个小，相减为负数，最后用n*flag
	}

	int n = 0;
	while (min != max)
	{
		++min;
		++n;
	}

	return n * flag;//非常巧妙
}

int main()
{
	Date d1(2022, 7, 27);
	d1.Print();

	//不合法日期
	//Date d2(2022, 0, 0);
	//d2.Print();

	//加等天数
	d1 += 20;
	d1.Print();//2022年8月16日

	//加天数
	Date d2 = d1 + 100;
	d2.Print();//2022年11月24日

	//减等天数
	d2 -= (-20);
	d2.Print();//2022年12月14日

	//减天数
	Date d3 = d2 - 30;
	d3.Print();//2022年11月14日

	//天数++
	d3++;      //d3.operator++(&d3, 0) 可以是0，可以是其他的任意整型
	d3.Print();//2022年11月15日
	//++天数
	++d3;      //d3.operator++(&d3)
	d3.Print();//2022年11月16日
	//--天数
	d3--;
	d3.Print();//2022年11月15日
	//天数--
	--d3;
	d3.Print();//2022年11月14日

	//日期 - 日期
	Date d4(2022, 7, 30);
	Date d5(2022, 12, 23);
	cout << d5 - d4 << endl;  //146
	cout << d4 - d5 << endl;  //-146

	return 0;
}