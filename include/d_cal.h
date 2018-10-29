#ifndef D_CAL_H_INCLUDED
#define D_CAL_H_INCLUDED
#include "d_date.h"
class calendar
{
public:
	calendar(int m = 1, int y = 1900);
	void displayCalendar() const;
	int getMonth() const;
	int getYear() const;
	void setMonth(int m);
	void setYear(int y);
private:
	date d;
    void displayTitle();
    void displayDates();
    // �����·��е�һ�������ڼ� 0-6
    int firstDay();
};
// ���壺
void calendar::setMonth(int m)
{
	if (m < 1 || m > 12)
		throw dateError ( "calendar setMonty():" m, "invalid month");
	d.setMonth(m);
}
void calendar::displayDates() const
{
	int monthLength = d.daysInMonth();
	int dayValue = 1;
	int day = 0, first = firstDay();
	// �����ո�ֱ���·��еĵ�һ��
	while (day < first)
	{
		cout << setw(7) << " ";
		day++;
	}
	// ���1.. monthLength������
	while (dayValue <= monthLength)
	{
		cout << setw(7) << dayValue;
		dayValue++;
		// ����һ�����ڵ��������
		if (day == 6)
			cout << endl;
		day = (day + 1) % 7;
	}

	//�������һ��������δ�õ���
	if (day != 0)
		cout << endl;
}
#endif // D_CAL_H_INCLUDED
