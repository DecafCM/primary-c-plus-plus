#define _CRT_SECURE_NO_WARNINGS 1

#include "Date.h"
 
inline int GetMonthDay(int year, int month) //���ڻᱻƵ�����ã����Զ������������
{
	//�洢ÿ���µ�����(�����Ƕ����Ƿ�Ϊ��������),��static������ŵ���̬����Ƶ������ʱ����Ҫÿ�ζ���������
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
	//������ںϷ���
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
		cout << "�Ƿ�����" << endl;
		//�ϸ���˵���쳣����
		//assert(false);
	}
}

void Date::Print()
{
	cout << _year << "��" << _month << "��" << _day << "��" << endl;
}

//day+= 100 �ӵ�����
//���Ƽӷ��Ľ�λ����: 
//1�������ˣ���ȥ���µ��������¼�1;2�������ˣ����1���ٰ����ó�1
//2021 5 25 + 20��
//2021 5 45 //����Ƿ�Ϸ�
//-> 2021 6 (45- GetMonthDay(2021, 6)) ��ʱ�ټ���Ƿ�Ϸ�
Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		*this -= -day;
	}
	else
	{
		_day += day;
		//�������Ϸ������Ͻ�λ�������Ϸ�
		while (_day > GetMonthDay(_year, _month)) //_day <= GetMonthDay()˵���ǺϷ���
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

//day+ 100 ������
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
	
	//����
	ret += day;
	return ret; //����ret��һ����ʱ���󣬲��������÷���

}

//day -= 100 ��������
//���day�Ǹ�����δ���//��һ���������ڼ�һ����������+=���߼�����
Date& Date::operator-=(int day)
{
	if(day < 0)
	{
		//_day += -day;
		////�������Ϸ������Ͻ�λ�������Ϸ�
		//while (_day > GetMonthDay(_year, _month)) //_day <= GetMonthDay()˵���ǺϷ���
		//{
		//	_day -= GetMonthDay(_year, _month);
		//	_month++;
		//	if (_month > 12)
		//	{
		//		_year++;
		//		_month = 1;
		//	}
		//}

		//����
		*this += -day;
	}
	else
	{
		_day -= day;
		while (_day <= 0) //0��Ҳ�ǲ��Ϸ���
		{
			_month--; //�ȼ�����Ϊ������ǰһ���µ��������㣬��5��-5�գ����õ�4�µ�30+(-5)
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

////day - 100 ������
Date Date::operator-(int day)
{
	Date ret(*this); //Date ret = (*this);
	
	//����
	ret -= day;//ret.operator-=(&ret.day)

	return ret;
}

//ǰ��++�ͺ���++�������+1����ͬ�ĵط����ڷ���ֵ��һ��
//���������������һ���ģ�����������һ���ģ�Ϊ�����֣��Ժ���++�������⴦��,����һ���������γɺ�������
//++d  -> d.operator++(&d)
Date& Date::operator++() //�ܼ����ã�����++���������÷���
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

//--����
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}
//����--
Date Date::operator--(int)
{
	Date tmp = *this;
	*this -= 1;

	return tmp;
}

//�Ƚ�

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
	//����
	return !(*this >= d);
}
bool Date::operator>=(const Date& d)
{
	//����
	return *this > d || *this == d;
}
bool Date::operator<=(const Date& d)
{
	//����
	return !(*this > d);
}
bool Date::operator!=(const Date& d)
{
	//����
	return !(*this == d);
}

//���� - ����
//����������-�꣬��-��...��Ϊÿ����������һ���������ǳ�����
//��õ�˼·:��С�����ڲ���++֪���ӵ������ڣ����˶��ٴξͲ��˶�����
int Date::operator-(const Date& d)
{
	//�����һ�����ڴ�
	Date max = *this;
	Date min = d;
	int flag = 1; //��һ�������Ϊ�����������n*flag��ʾ����
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;//��һ��С�����Ϊ�����������n*flag
	}

	int n = 0;
	while (min != max)
	{
		++min;
		++n;
	}

	return n * flag;//�ǳ�����
}

int main()
{
	Date d1(2022, 7, 27);
	d1.Print();

	//���Ϸ�����
	//Date d2(2022, 0, 0);
	//d2.Print();

	//�ӵ�����
	d1 += 20;
	d1.Print();//2022��8��16��

	//������
	Date d2 = d1 + 100;
	d2.Print();//2022��11��24��

	//��������
	d2 -= (-20);
	d2.Print();//2022��12��14��

	//������
	Date d3 = d2 - 30;
	d3.Print();//2022��11��14��

	//����++
	d3++;      //d3.operator++(&d3, 0) ������0����������������������
	d3.Print();//2022��11��15��
	//++����
	++d3;      //d3.operator++(&d3)
	d3.Print();//2022��11��16��
	//--����
	d3--;
	d3.Print();//2022��11��15��
	//����--
	--d3;
	d3.Print();//2022��11��14��

	//���� - ����
	Date d4(2022, 7, 30);
	Date d5(2022, 12, 23);
	cout << d5 - d4 << endl;  //146
	cout << d4 - d5 << endl;  //-146

	return 0;
}