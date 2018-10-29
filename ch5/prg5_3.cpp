#include <iostream>
#include "../include/d_vector.h"

using namespace std;

int main()
{
	miniVector<int> v;
	// try 块检测空间向量
	try
	{
		v.pop_back();
	}
	// catch 块从pop——back（）捕获underflowError异常
	catch (const underflowError& e)
	{
		cout << e.what() << endl;
		v.push_back(99);
	}

	cout << "The size of v = " << v.size() << endl;
	// try 块提供下标范围检测： catch块从operator[]捕获indexRangeError异常
	try
	{
		cout << "v[0] = " << v[0] << endl;
		cout << "v[1] = " << v[1] << endl;
	}
	catch(const indexRangeError &e)
	{
		cout << e.what() << endl;
	}
	return 0;
}
