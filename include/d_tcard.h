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
	// ��punchOutTime��ֵt����hanPunched����Ϊtrue
	void punchOut(const time24& t);
	//���һ����־�����а�����������ֹʱ�䣬��������ÿСʱ���ú�����
	// ǰ�᣺Ա��û�д������rangeError
	// �Գ���hasPunched==false��
	void writeSalaryInfo();
private:
	string workerID;
	time24 punchInTime, punchOutTime;
	double payrate;
	bool hasPunched;
};

// ����:
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
