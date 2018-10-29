#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void hanoi ( int n, const string& initNeedle, const string& endNeedle, const string& tempNeedle );

int main()
{
	int n;
	string beginNeedle = "A_beginNeedle",
		   middleNeedle = "B_middleNeedle",
		   endNeedle = "C_endNeedle";
	cout << "Enter the number of disk: ";
	cin >> n;
	cout << "The solution for n = " << n << endl;
	double start,end;
	start = clock();
	hanoi(n, beginNeedle, endNeedle, middleNeedle);
	end = clock();
	cout << (start-end)/CLOCKS_PER_SEC;
	return 0;
}

void hanoi(int n, const string& initNeedle, const string& endNeedle, const string& tempNeedle)
{
	if (n == 1)
		cout << "move " << initNeedle << " to " << endNeedle << endl;
	else
	{
		//
		hanoi(n-1, initNeedle,tempNeedle,endNeedle);
		//
		cout << "move " << initNeedle << " to " << endNeedle << endl;
		//
		hanoi(n-1,tempNeedle,endNeedle,initNeedle);
	}
}
