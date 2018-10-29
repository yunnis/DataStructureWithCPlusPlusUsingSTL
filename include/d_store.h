#ifndef D_STORE_H_INCLUDED
#define D_STORE_H_INCLUDED
#include <iostream>
#include <ostream>
// �۵�ģ��汾(ģ����)
template <typename T>
class store
{
public:
	// ʹ�� item �� ����T ��Ĭ�϶�����г�ʼ��
	store(const T& item = T() );
	// �������������ݳ�Աֵ
	T getValue() const;
	// �����ݳ�Աֵ����Ϊitem
	// ʹ��Ƕ����
	void setValue(const T& item)
	{
		value = item;
	};
	// ��"value = "����ʽ��ʾ���
	// ���ģ����,��ʹ��ĳ����������������ʱ, ������������ͽ������е�ģ������T
	/// ע����Ԫ������������ģ��, ����Ҫ����������廯
	friend std::ostream& operator<< (std::ostream& ostr, const store<T>& obj)
	{
		ostr << "Value = " << obj.value;
		return ostr;
	}
private:
	T value;
};

// ʹ�ó�ʼ���б�ֵ
template <typename T>
store<T>::store (const T& item) : value(item)
{}

template <typename T>
T store<T>::getValue() const
{
	return value;
}

#endif // D_STORE_H_INCLUDED
