#ifndef D_NODE_H_INCLUDED
#define D_NODE_H_INCLUDED
// �ṹ���в�����д���캯�� ������ɢ�Ľ��
// �����ʹ�ù��캯��ʹ �����ڵ�ʱ������
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
