#ifndef D_MATRIX_H_INCLUDED
#define D_MATRIX_H_INCLUDED
#include <vector>
template <typename T>
class maxtrix
{
public:
	/// ���캯��
	// ����������������numRows*numCols ��Ԫ�ص����飬����Ԫ��ֵ��Ϊ
	// initVal
	matrix(int numRows = 1,int numCols = 1, const T& initVal = T());
	/// �±������
	// ǰ��������0 <= i < numRows,Υ����ǰ�������������indexRangeError�쳣
	// ������������������������ڸ�ֵ�������꣬��ı���i��Ԫ��
	vector<T> & operator[] (int i);
	// ���ڳ�������İ汾
	const vector<T>& operator[] (int i) const;

	int rows() const;
	int cols() const;
	/// �ı����ߴ�
	// ��������������ߴ�ΪnumRows * numCols����Ԫ�ض�������T��Ĭ��ֵ���
	void resize(int numRows, int numcols);
private:
	int nRows, nCols;
	// ����ʵ��ΪnRows����������������ÿ��������nCols��Ԫ�أ�������
	vector<vector<T> > mat;
};

/// ���캯��
template <typename T>
matrix<T>::matrix(int numRows,int numCols, const T& initVal):
	nRows(numRows), nCols(numCols), mat(numRows,vector<T>(numCols, initVal))
	{

	}
/// �±������
template <typename T>
vector<T>& matrix<T>::operator[] (int i)
{

}
#endif // D_MATRIX_H_INCLUDED
