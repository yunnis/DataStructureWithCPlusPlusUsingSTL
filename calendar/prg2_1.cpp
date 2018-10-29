// ����calendar�࣬��������ʾ�û������·ݺ����
// ��ʾ�����������ǰ���������Ч����
// ���Գ���Դ���Ĵ���
#include <iostream>
#include <cstdlib> // exit()
#include "d_cal.h" // calendar

using namespace std;

int main()
{
	int month, year;
	calendar cal;
	cout << "enter the month and year: ";
	cin >> month >> year;
	cout << endl;

	// setYear() �� setMonth() ��������Ĵ���
	// �����÷���try��

	try
	{
		cal.setYear(year);
		cal.setMonth(month);
	}
	//���setYear() �� setMonth()�����쳣���򲶻���
	catch (const dateError& de)
	{
		cerr << de.what() << endl;
		exit(1);
	}

	// ��ʾ����
	cal.displayCalendar();
	return 0;
}
