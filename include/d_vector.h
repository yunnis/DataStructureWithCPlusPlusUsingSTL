#ifndef D_VECTOR_H_INCLUDED
#define D_VECTOR_H_INCLUDED

#include "d_except.h"

using namespace std;

template <typename T>
class miniVector
{
public:
	/// @param 构造函数
	miniVector ( int size = 0 );
	/// @param 复制构造函数
	miniVector ( const miniVector<T> & obj );
	/// @param 析构函数
	~miniVector();

	/// @param 赋值运算符
	miniVector& operator = ( const miniVector<T> & rhs );
	/// @param 返回尾部的函数
	T& back();
	/// @param 返回尾部的函数(常数版)
	const T& back() const;
	/// @param 用下标提供对元素的常见访问
	T& operator[] ( int i );
	/// @param 常量斑斑, miniVector对象是常量时使用
	const T& operator[] ( int i ) const;
	/// @param 尾部插入元素
	void push_back ( const T& item );
	/// @param 删除尾部的元素
	void pop_back();
	/// @param 返回表的大小
	int size() const;
	/// @param 如果向量为空,返回true
	bool empty() const;
	/// @param 返回当前的容量
	int capacity() const;
private:
	int vSize;    // 空间大小
	int vCapacity; // 容量大小,容量>=空间
	T *vArr;       // 动态数组
	/// @param 当n>vCapacity时被公有函数调用, 容量扩展到n个
	///                copy==true,将现有元素赋值到新空间,删除旧的动态数组
	void reserve ( int n, bool copy );
};

/// reserve()
template <typename T>
void miniVector<T>::reserve ( int n, bool copy )
{
	T *newarr;
	int i;
	// 分配新的n个元素的动态数组
	newarr = new T[n];
	if ( newarr == NULL )
		throw memoryAllocationError (
		        "miniVector reserve(): memory allocation failure" );
	// 如果copy为ture, 则从旧表复制元素到新表
	if ( copy )
		for ( i = 0; i < vSize; i++ )
			newarr[i] = vArr[i];
	// 如过vArr为空,不许要删除,否则删除原始数组
	if ( vArr != NULL )
		delete [] vArr;
	// 更新vCapcity和vArr
	vCapacity = n;
	vArr = newarr;
}

/// miniVector() 构造函数
template <typename T>
miniVector<T>::miniVector ( int size ) : vSize ( 0 ), vCapacity ( 0 ), vArr ( NULL )
{
	int i;
	// 如果size=0,则vsize和vcapacity=0,varr=null,只是返回
	if ( size = 0 )
		return;

	// 设置容量为size,因为在建立向量,所以copy为false
	reserve ( size, false );
	// ???为什么这里要2个resrve???
	reserve ( size, false );
	// vsize  = size
	vSize = size;

	// 复制T()到每个向量元素
	for ( i = 0; i < vSize; i++ )
		// ???这个T()是什么???
		vArr[i] = T();
}

/// ~miniVector()
template <typename T>
miniVector<T>::~miniVector()
{
	// 释放动态数组
	if ( vArr != NULL )
		delete [] vArr;
}

/// miniVector赋值运算符
template <typename T>
miniVector<T> &miniVector<T>::operator = ( const miniVector<T> & rhs )
{
	int i;
	// 检查vCapacity,看是否需要分配新数组
	if ( vCapacity < rhs.vSize )
		// 是当前对象的容量与rhs的大小相同，不用复制，因为要替换旧值
		reserve ( rhs.vSize, false );
	// 使当前对象与rhs有相同的大小
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
