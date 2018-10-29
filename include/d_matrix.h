#ifndef D_MATRIX_H_INCLUDED
#define D_MATRIX_H_INCLUDED
#include <vector>
template <typename T>
class maxtrix
{
public:
	/// 构造函数
	// 后置条件：生成有numRows*numCols 个元素的数组，所有元素值都为
	// initVal
	matrix(int numRows = 1,int numCols = 1, const T& initVal = T());
	/// 下标运算符
	// 前提条件：0 <= i < numRows,违反此前提条件，则产生indexRangeError异常
	// 后置条件：如果这个运算符用于赋值语句的坐标，则改变行i的元素
	vector<T> & operator[] (int i);
	// 用于常量对象的版本
	const vector<T>& operator[] (int i) const;

	int rows() const;
	int cols() const;
	/// 改变矩阵尺寸
	// 后置条件：矩阵尺寸为numRows * numCols。新元素都用类型T的默认值填充
	void resize(int numRows, int numcols);
private:
	int nRows, nCols;
	// 矩阵实现为nRows个向量（行数），每个向量有nCols个元素（列数）
	vector<vector<T> > mat;
};

/// 构造函数
template <typename T>
matrix<T>::matrix(int numRows,int numCols, const T& initVal):
	nRows(numRows), nCols(numCols), mat(numRows,vector<T>(numCols, initVal))
	{

	}
/// 下标运算符
template <typename T>
vector<T>& matrix<T>::operator[] (int i)
{

}
#endif // D_MATRIX_H_INCLUDED
