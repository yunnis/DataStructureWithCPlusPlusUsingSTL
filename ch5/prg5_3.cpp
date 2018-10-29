#include <iostream>
#include "../include/d_vector.h"

using namespace std;

int main()
{
	miniVector<int> v;
	// try ����ռ�����
	try
	{
		v.pop_back();
	}
	// catch ���pop����back��������underflowError�쳣
	catch (const underflowError& e)
	{
		cout << e.what() << endl;
		v.push_back(99);
	}

	cout << "The size of v = " << v.size() << endl;
	// try ���ṩ�±귶Χ��⣺ catch���operator[]����indexRangeError�쳣
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
