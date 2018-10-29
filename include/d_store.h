#ifndef D_STORE_H_INCLUDED
#define D_STORE_H_INCLUDED
#include <iostream>
#include <ostream>
// 累的模板版本(模板类)
template <typename T>
class store
{
public:
	// 使用 item 或 类型T 的默认对象进行初始化
	store(const T& item = T() );
	// 检索并返回数据成员值
	T getValue() const;
	// 将数据成员值更新为item
	// 使用嵌入码
	void setValue(const T& item)
	{
		value = item;
	};
	// 以"value = "的形式显示输出
	// 这个模板类,在使用某个具体类型引用类时, 必须包括类名和角括号中的模板类型T
	/// 注意友元函数本身不是类模板, 必须要地难以其具体化
	friend std::ostream& operator<< (std::ostream& ostr, const store<T>& obj)
	{
		ostr << "Value = " << obj.value;
		return ostr;
	}
private:
	T value;
};

// 使用初始化列表赋值
template <typename T>
store<T>::store (const T& item) : value(item)
{}

template <typename T>
T store<T>::getValue() const
{
	return value;
}

#endif // D_STORE_H_INCLUDED
