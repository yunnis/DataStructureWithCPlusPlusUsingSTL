#ifndef D_LIST_H_INCLUDED
#define D_LIST_H_INCLUDED

template <typename T>
class miniList
{
public:
	miniList();

	~miniList();
	T& back();
	bool empty() const;
	T& front();
	void push_back(const T& value);
	void pop_back();
	void push_front(const T& value);
	void pop_front();
	void erase(iterator pos);
	void erase(iterator first, iterator last);
	iterator insert(iterator pos, const T& value);
	int size() const;
private:

};


#endif // D_LIST_H_INCLUDED
