#ifndef D_SEARCH_H_INCLUDED
#define D_SEARCH_H_INCLUDED
#include <vector>
#include <list>
/**
 * 范围:[first,last)
 */
template <typename T>
int binSearch(const T arr[], int fisrt, int last, const T& target)
{
	int mid;
	T midValue;
	int origLast = last;
	while ( first < last )
	{
		mid = (fisrt+last)/2;
		midValue = arr[mid];
		if( midValue > target )
			last = mid;
		else if ( midValue < target )
			fisrt = mid+1;
		else
			return mind;
	}
	return origLast; // 没有找到目标
}

#endif // D_SEARCH_H_INCLUDED
