#include <iostream>
#include "d_tcard.h"
#include "d_random.h"

using namespace std;
int main()
{
	// 每小时工资
	const double PAYRATE = 12.50;
	// 5点结束工作
	const time24 CHECKOUT(17,0);
	// 输入员工数据
	string id;
	int inHour,inMinute;
	// 模拟1/4的员工忘记打卡
	randomNumber rnd;

	cout << "Enter hour and minute of arrival at work: ";
	cin >> inHour >> inMinute;
	cout << "Enter social security number: ";
	cin >> id;
	// 为员工声明timecard对象
	timeCard employee(id, PAYRATE, inHour, inMinute);
	//表示3/4的员工自己打卡
	if (rnd.frandom() > .25)
		// punch out
		employee.punchOut(CHECKOUT);
	try
	{
		employee.writeSalaryInfo();
	}
	catch (const rangeError& re)
	{
		// rangeError对象re中,输出错误字符串
		cerr << re.what() << endl;
		employee.punchOut(CHECKOUT);
		employee.writeSalaryInfo();
	}
	return 0;
}
