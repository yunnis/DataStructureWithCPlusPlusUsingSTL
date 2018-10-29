#ifndef D_NODE_H_INCLUDED
#define D_NODE_H_INCLUDED
// 结构体中不能重写构造函数 都是零散的结点
// 类可以使用构造函数使 建立节点时更方便
template <typename T>
class node
{
public:
	T nodeValue;
	node <T> *next;

	node() : next ( NULL )
	{ }
	node ( const T& item, node <T> *nextNode = NULL ) :
		nodeValue ( item ), next ( nextNode )
	{ }
};


#endif // D_NODE_H_INCLUDED
