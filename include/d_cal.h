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
    // 返回月份中第一天是星期几 0-6
    int firstDay();
};
// 定义：
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
	// 跳过空格，直到月份中的第一天
	while (day < first)
	{
		cout << setw(7) << " ";
		day++;
	}
	// 输出1.. monthLength的日期
	while (dayValue <= monthLength)
	{
		cout << setw(7) << dayValue;
		dayValue++;
		// 是下一个星期的星期日嘛？
		if (day == 6)
			cout << endl;
		day = (day + 1) % 7;
	}

	//跳过最后一个星期中未用的天
	if (day != 0)
		cout << endl;
}
#endif // D_CAL_H_INCLUDED
