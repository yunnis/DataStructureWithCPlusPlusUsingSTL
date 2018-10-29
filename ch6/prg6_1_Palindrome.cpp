#include <iostream>
#include <string>
#include <list>
#include <ctype.h>  // 用于isalpha() tolower()

using namespace std;

template <typename T>
bool isPalindrome (const list<T>& alist);

int main()
{
	string str;
	list<char> charList;
	int i;
	char ch;
	// 可能会包含空格
	cout << "Enter the string: ";
	getline(cin, str, '\n');
	for(i = 0; i < str.length(); i++)
	{
		ch = str[i];
		if(isalpha(ch))
			charList.push_back(tolower(ch));
	}
	if(isPalindrome(charList))
		cout << "' " << str << " ' is a Palindrome" << endl;
	else
		cout << "' " << str << " ' is not a palindrome" << endl;

	return 0;
}
template <typename T>
bool isPalindrome(const list<T>& alist)
{
	list<T> copylist;
	copylist = alist;
	// list bigger than 1, cheak back of list
	while(copylist.size() > 1)
	{
		if(copylist.front() != copylist.back())
			return false;
		copylist.pop_front();
		copylist.pop_back();
	}
	return true;
}
