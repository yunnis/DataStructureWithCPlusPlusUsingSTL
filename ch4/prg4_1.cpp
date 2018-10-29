#include <iostream>
#include <string>
#include <ostream>
#include "..\include\d_store.h"

using namespace std;

int main()
{
	store<int> intStore(5);
	store<double> doubleStore(2.718);
	store<string> strStore("Template");

	cout << "The values stored by the objects are:" << endl;
	cout << intStore << endl;
	cout << doubleStore << endl;
	cout << strStore << endl;
	cout << endl;
	cout << "The concdtenation of 'template' in strStore and "
	<< "'Class' is:" << endl;
	strStore.setValue(strStore.getValue() + "Class");
	cout << strStore <<endl;
	return 0;
}
