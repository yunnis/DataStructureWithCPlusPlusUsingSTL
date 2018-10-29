/**
 * 用time24对象计算停车场收费,每小时6元
 * @param 输入两个时间:进入和离开的时间
 * @return 输出一张收据:到达时间,离开时间,停放时间和收费
 */
#include "d_time24.h"
using namespace std;

int main()
{
	const double PERHOUR_PARKING = 6.00;
	time24 enterGarage, exitGarage, pakingTime;
	double billingHours;

	std::cout << "Enter the times the car enters and exists the garage: ";
	enterGarage.readTime();
	exitGarage.readTime();

	pakingTime = enterGarage.duration(exitGarage);

	billingHours = pakingTime.getHour() + pakingTime.getMinute()/60;

	cout << "car enter at: ";
	enterGarage.writeTime();
	cout << endl;

	cout << "car exits at: ";
	exitGarage.writeTime();
	cout << endl;

	cout << "parking time: ";
	pakingTime.writeTime();
	cout << endl;

	cout << "cost is $" << billingHours * PERHOUR_PARKING << endl;

	return 0;
}
