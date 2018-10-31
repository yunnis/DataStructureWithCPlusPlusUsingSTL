// m = 6,n = 3
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// m(人数) = 10,n(间隔) = 5
	int arr[]{1,2,3,4,5,6,7,8,9,10}, m = 0, n = 0;
	int arrSize = sizeof(arr) / sizeof(int);
	vector<int> v(arr,arr+arrSize);
//	for(int i = 0; i < v.size(); i++)
//		cout << v.at(i) << " ";
	for(int i : v)
		cout << i << " ";
	cout << endl;
	while(v.size() != 1)
	{
		m++;n++;
		if(n == 4)
		{
			n=0;
			// 当向量size等于m时，说明应该删除下标为0的元素
			//
			if(m == v.size())
			{
				m=0;
			}
			cout << v.at(m) << " out" <<endl;
			v.erase(v.begin()+m);
			cout << "left: " ;
			for(int i : v)
				cout << i << " ";
			cout << endl;
		}
		if(m == v.size())
		{
			m=0;
		}
	}
    //cout << "Hello world!" << endl;
    return 0;
}
