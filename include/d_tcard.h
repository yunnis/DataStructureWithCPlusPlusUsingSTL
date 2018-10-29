#ifndef D_TCARD_H_INCLUDED
#define D_TCARD_H_INCLUDED
#include "d_time24.h"
#include "d_except.h"
#include "d_util.h"
class timeCard
{
public:
	timeCard(const string& ssno, double rate, int punchInHour, int punchInMinute):
		workID(ssno),payrate(rate),hasPunched(false), purchInTime(punchInHour, punchInMinute);
	// 将punchOutTime赋值t，将hanPunched设置为true
	void punchOut(const time24& t);
	//输出一个日志，其中包括工作的起止时间，工作量，每小时费用和收入
	// 前提：员工没有打卡则产生rangeError
	// 以尝（hasPunched==false）
	void writeSalaryInfo();
private:
	string workerID;
	time24 punchInTime, punchOutTime;
	double payrate;
	bool hasPunched;
};

// 定义:
void timeCard::punchOut(const time24& t)
{
	punchOutTime = t;
	hasPunched = true;
}
void timeCard::writeSalaryInfo()
{
	if (hasPunched == false)
		throw rangeError ("timeCard: writeSalaryInfo() called before" "punching out");
	time24 timeWorked = punchInTime.duration(punchOutTime);
	double hoursWorked = timeWorked.getHour() + timeWorked.getHour()/60;

	cout << "Worker:     " << workerID << endl;
	cout << "start time: ";
	punchInTime.writeTime();
	cout << "  End time: ";
	punchOutTime.writeTime();
	cout << endl;
	cout << "Total Time: " << setreal(1,2) << hoursWorked
		  << " hours" << endl;
	cout << "At $" << setreal(1,2) << payrate
		  << " per hour, the days earnings are $"
		  << setreal(1,2) << payrate*hoursWorked << endl;

}

#endif // D_TCARD_H_INCLUDED
