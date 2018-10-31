#ifndef D_LITER_H_INCLUDED
#define D_LITER_H_INCLUDED
class iterator
{
public:
	/// 构造函数
	iterator();
	/// 迭代器的比较符
	bool operator ==(const iterator& rhs) const;
	bool operator !=(const iterator& rhs) const;
	/// 指针反（解）引用运算符
	T& operator*();
	/// 前缀运1运算符
	iterator& operator++();
	/// 后缀加1运算符
	iterator operator++(int);
	{
		iterator tmp = *this;
		nodePtr = nodePtr->next;
		return tmp;
	}
	/// 前缀减1运算符
	iterator& operator--();
	/// 后缀减1运算符
	iterator operator--(int);
private:
	/// 指向当前结点的指针
	dnode<T> *nodePtr;
	/// 私有构造函数，把p赋给nodePtr，从而吧指针p转换为迭代器
	iterator(dnode<T> *p):nodePtr(p)
	{	}
};

#endif // D_LITER_H_INCLUDED
