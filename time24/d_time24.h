#ifndef D_TIME24_H_INCLUDED
#define D_TIME24_H_INCLUDED
#include <iostream>

class time24
{
private:
	int hour;
	int minute;
	void normalizeTime();
public:
	time24():hour(0), minute(00){}
	time24(int h, int m):hour(h), minute(m){ normalizeTime(); }
	int getHour() const;
	int getMinute() const { return minute; }
	void setHour(const int& t);
	void readTime();
	time24 addTime(int mins);
	time24 duration(const time24& t);
	void writeTime();
};

void time24::normalizeTime()
{
	int extraHours = minute / 60;
	minute %= 60;
	hour = (hour + extraHours) % 24;
}

int time24::getHour() const
{
	return hour;
}
void time24::setHour(const int& t)
{
	hour = t;
}
time24 time24::addTime(int min)
{
	minute += min;
	normalizeTime();
	return time24(hour, minute);
}
void time24::readTime()
{
	char delimiter;
	std::cin >> hour >> delimiter >> minute;
	normalizeTime();
}
time24 time24::duration(const time24& t)
{
	// 将当前时间和时间t转成分钟
	int currTime = hour * 60 + minute;
	int tTime = t.hour * 60 + t.minute;
	// t早于当前时间,引发异常
	if (tTime < currTime )
		throw std::range_error (
			"time24 duration(): argument is an earlier time");
	else
	// 创建一个匿名对象作为返回值
	return time24(0, tTime-currTime);
}
void time24::writeTime()
{
	std::cout << hour << ":" << minute << std::endl;
}


#endif // D_TIME24_H_INCLUDED
