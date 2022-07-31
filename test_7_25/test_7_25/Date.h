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
	
	//��ӡ
	void Print();
	//�������������졢��ֵ���أ����Բ�д����ΪĬ�����ɵľ͹�����
	
	//day+= 100 �ӵ�����
	Date& operator+=(int day);

	//day+ 100 ������
	Date operator+(int day);
	
	//day-= 100 ��������
	Date& operator-=(int day);

	//day -= 100 ������
	Date operator-(int day);

	//*��ô����ǰ��++�ͺ���++
	//++d  -> d.operator++(&d)
	Date& operator++();  //�ܼ����ã�����++���������÷���
	//d++  -> d.operator++(&d, 0)
	Date operator++(int);//int ��������Ҫ��ʵ�Σ���Ϊû�ã�����������Ϊ�˸�ǰ��++���ɺ�������
	//--����
	Date& operator--();
	//����--
	Date operator--(int);

	//�Ƚ�
	bool operator>(const Date& d);
	bool operator<(const Date& d);
	bool operator>=(const Date& d);
	bool operator<=(const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);

	//���� - ����
	int operator-(const Date& d);

private:
	int _year;
	int _month;
	int _day;
};
