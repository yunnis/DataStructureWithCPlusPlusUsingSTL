#include <iostream>
#include "d_tcard.h"
#include "d_random.h"

using namespace std;
int main()
{
	// ÿСʱ����
	const double PAYRATE = 12.50;
	// 5���������
	const time24 CHECKOUT(17,0);
	// ����Ա������
	string id;
	int inHour,inMinute;
	// ģ��1/4��Ա�����Ǵ�
	randomNumber rnd;

	cout << "Enter hour and minute of arrival at work: ";
	cin >> inHour >> inMinute;
	cout << "Enter social security number: ";
	cin >> id;
	// ΪԱ������timecard����
	timeCard employee(id, PAYRATE, inHour, inMinute);
	//��ʾ3/4��Ա���Լ���
	if (rnd.frandom() > .25)
		// punch out
		employee.punchOut(CHECKOUT);
	try
	{
		employee.writeSalaryInfo();
	}
	catch (const rangeError& re)
	{
		// rangeError����re��,��������ַ���
		cerr << re.what() << endl;
		employee.punchOut(CHECKOUT);
		employee.writeSalaryInfo();
	}
	return 0;
}
