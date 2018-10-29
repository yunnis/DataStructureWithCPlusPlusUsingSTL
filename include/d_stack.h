#ifndef D_STACK_H_INCLUDED
#define D_STACK_H_INCLUDED
#include <vector>

template <typename T>
class miniStack
{
public:
	miniStack();
	void push(const T& item);
	void pop();
	T& top();
	const T& top() const;
	bool empty() const;
	int size() const;
private:
	vector<T> stackVector;
};

template <typename T>
void miniStack<T>::push(const T& item)
{
	stackVector.push_back(item);
}

template <typename T>
T& miniStack<T>::top()
{
	// �˴�Ϊʲôֻ��empty�����Ϳ��ԣ���
	// �����е�empty������
	if(empty())
		throw underflowError("miniStack top(): stack empty");
	return stackVector.back();
}

template <typename T>
void miniStack<T>::pop()
{
	if(empty())
		throw underflowError("miniStack pop(): stack empty");
	stackVector.pop_back();
}
#endif // D_STACK_H_INCLUDED
