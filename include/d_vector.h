#ifndef D_VECTOR_H_INCLUDED
#define D_VECTOR_H_INCLUDED

#include "d_except.h"

using namespace std;

template <typename T>
class miniVector
{
public:
	/// @param ���캯��
	miniVector ( int size = 0 );
	/// @param ���ƹ��캯��
	miniVector ( const miniVector<T> & obj );
	/// @param ��������
	~miniVector();

	/// @param ��ֵ�����
	miniVector& operator = ( const miniVector<T> & rhs );
	/// @param ����β���ĺ���
	T& back();
	/// @param ����β���ĺ���(������)
	const T& back() const;
	/// @param ���±��ṩ��Ԫ�صĳ�������
	T& operator[] ( int i );
	/// @param �����߰�, miniVector�����ǳ���ʱʹ��
	const T& operator[] ( int i ) const;
	/// @param β������Ԫ��
	void push_back ( const T& item );
	/// @param ɾ��β����Ԫ��
	void pop_back();
	/// @param ���ر�Ĵ�С
	int size() const;
	/// @param �������Ϊ��,����true
	bool empty() const;
	/// @param ���ص�ǰ������
	int capacity() const;
private:
	int vSize;    // �ռ��С
	int vCapacity; // ������С,����>=�ռ�
	T *vArr;       // ��̬����
	/// @param ��n>vCapacityʱ�����к�������, ������չ��n��
	///                copy==true,������Ԫ�ظ�ֵ���¿ռ�,ɾ���ɵĶ�̬����
	void reserve ( int n, bool copy );
};

/// reserve()
template <typename T>
void miniVector<T>::reserve ( int n, bool copy )
{
	T *newarr;
	int i;
	// �����µ�n��Ԫ�صĶ�̬����
	newarr = new T[n];
	if ( newarr == NULL )
		throw memoryAllocationError (
		        "miniVector reserve(): memory allocation failure" );
	// ���copyΪture, ��Ӿɱ���Ԫ�ص��±�
	if ( copy )
		for ( i = 0; i < vSize; i++ )
			newarr[i] = vArr[i];
	// ���vArrΪ��,����Ҫɾ��,����ɾ��ԭʼ����
	if ( vArr != NULL )
		delete [] vArr;
	// ����vCapcity��vArr
	vCapacity = n;
	vArr = newarr;
}

/// miniVector() ���캯��
template <typename T>
miniVector<T>::miniVector ( int size ) : vSize ( 0 ), vCapacity ( 0 ), vArr ( NULL )
{
	int i;
	// ���size=0,��vsize��vcapacity=0,varr=null,ֻ�Ƿ���
	if ( size = 0 )
		return;

	// ��������Ϊsize,��Ϊ�ڽ�������,����copyΪfalse
	reserve ( size, false );
	// ???Ϊʲô����Ҫ2��resrve???
	reserve ( size, false );
	// vsize  = size
	vSize = size;

	// ����T()��ÿ������Ԫ��
	for ( i = 0; i < vSize; i++ )
		// ???���T()��ʲô???
		vArr[i] = T();
}

/// ~miniVector()
template <typename T>
miniVector<T>::~miniVector()
{
	// �ͷŶ�̬����
	if ( vArr != NULL )
		delete [] vArr;
}

/// miniVector��ֵ�����
template <typename T>
miniVector<T> &miniVector<T>::operator = ( const miniVector<T> & rhs )
{
	int i;
	// ���vCapacity,���Ƿ���Ҫ����������
	if ( vCapacity < rhs.vSize )
		// �ǵ�ǰ�����������rhs�Ĵ�С��ͬ�����ø��ƣ���ΪҪ�滻��ֵ
		reserve ( rhs.vSize, false );
	// ʹ��ǰ������rhs����ͬ�Ĵ�С
	vSize = rhs.vSize;
	for ( i = 0; i < vSize; i++ )
		vArr[i] = rhs.vArr[i];
	return *this;
}

/// push_back()
template <typename T>
void miniVector<T>::push_back ( const T& item )
{
	// if full, get more capacity
	if ( vSize == vCapacity )
	{
		if ( vCapacity == 0 )
			// copy is false,because no element
			reserve(1, false);
		else
			// double capacity
			reserve(2 * vCapacity, true);
	}
	vArr[vSize] = item;
	vSize++;
}

/// pop_back()
template <typename T>
void miniVector<T>::pop_back()
{
    if (vSize == 0)
		throw underflowError("miniVector pop_back(): vector is empty");
	vSize--;
}

/// back()
template <typename T>
T& miniVector<T>::back()
{
	if (vSize == 0)
		throw underflowError("miniVector back(): vector empty");
	return vArr[vSize-1];
}

/// Operator[]
template <typename T>
T& miniVector<T>::operator[] (int i)
{
	if(i < 0 || i >= vSize)
		throw indexRangeError("miniVector: index range error", i, vSize);
	return vArr[i];
}

/// size()
template <typename T>
int miniVector<T>::size() const
{
	return vSize;
}
#endif // D_VECTOR_H_INCLUDED
