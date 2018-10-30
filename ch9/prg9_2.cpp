#include <iostream>

#include "../include/d_lqueue.h"

using namespace std;

int main()
{
	int arr[] = {6, 9, 2, 5}, i;
	int arrSize = sizeof ( arr ) / sizeof ( int );
	linkedQueue<int> q;
	for(i = 0; i < arrSize; i++)
	{
		q.push(arr[i]);
	}
	cout << "Queue size is : " << q.size() << endl;

	// 清除数列
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
	// 处理pop（）时可能产生的underflowError异常
	try
	{
		q.pop();
	}
	catch (const underflowError& ue)
	{
		cout << ue.what() << endl;
	}

	return 0;
}
