// 输入要打乱的单词个数
// 根据随机数把单词每个字母加入双向链表的表头或表尾
// 0加入表头，1加入表尾
#include <iostream>
#include <string>

#include "../include/d_node.h"
#include "../include/d_nodel.h"
#include "../include/d_random.h"

using namespace std;

template <typename T>
void clear(dnode<T> *header);

int main()
{
	dnode<char> *header = new dnode<char>;
	string word;
	int numWords, i, j;
	randomNumber rnd;
	cout << "How many words will you enter?";
	cin >> numWords;
	cout << endl;
	for(i = 0; i < numWords; i++)
	{
		cout << "Word: ";
		cin >> word;

		for(j = 0; j <word.length(); j++)
			if( rnd.random(2) == 0)
				insert(header->next, word[j]);
			else
				insert(header,word[j]);
		cout << "Word/Jumbled Word: " << word << "  ";
		writeDLinkedList(header," ");
		cout << endl << endl;

		clear(header);
	}
}

template <typename T>
void clear( dnode<T> *header)
{
	while(header->next != header)
		erase(header->next);
}
