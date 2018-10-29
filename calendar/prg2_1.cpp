// 测试calendar类，方法是提示用户输入月份和年份
// 显示日历，运行是包括输入无效数据
// 测试程序对错误的处理
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

	// setYear() 或 setMonth() 可能引起的错误
	// 将调用放入try中

	try
	{
		cal.setYear(year);
		cal.setMonth(month);
	}
	//如果setYear() 或 setMonth()产生异常，则捕获他
	catch (const dateError& de)
	{
		cerr << de.what() << endl;
		exit(1);
	}

	// 显示日历
	cal.displayCalendar();
	return 0;
}
