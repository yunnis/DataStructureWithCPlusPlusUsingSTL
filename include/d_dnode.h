#ifndef D_DNODE_H_INCLUDED
#define D_DNODE_H_INCLUDED
template <typename T>
class dnode
{
public:
	T nodeValue;
	dnode<T> *prev;
	dnode<T> *next;
	dnode()
	{
		prev = this;
		next = this;
	}
	dnode(const T& value):nodeValue(value)
	{
		prev = this;
		next = this;
	}
};


#endif // D_DNODE_H_INCLUDED
