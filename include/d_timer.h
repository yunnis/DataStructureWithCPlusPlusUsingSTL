#ifndef D_TIMER_H_INCLUDED
#define D_TIMER_H_INCLUDED

#include <ctime>
class timer
{
public:
	timer():startTime(0), stopTime(0) {};
	void start();
	void stop();
	double time() const;
private:
	double startTime,stopTime;
};

// ∂®“Â
void timer::start()
{
	startTime = clock();
}
void timer::stop()
{
	stopTime = clock();
}
double timer::time() const
{
	return (startTime-stopTime) / double(CLOCKS_PER_SEC);
}
#endif // D_TIMER_H_INCLUDED
