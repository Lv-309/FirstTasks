#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	ListElement list = nullptr;

	AddStringToList(&list, "SoftServe");
	AddStringToList(&list, "IT Academy");
	AddStringToList(&list, "Lv-309.C++");
	AddStringToList(&list, "Orest");
	AddStringToList(&list, "SoftServe");
	AddStringToList(&list, "Student");
	AddStringToList(&list, "SoftServe");

	cout << "List of string:" << endl;
	PrintList(list);
	cout << endl;

	cout << "Sorted list: " << endl;
	QSortList(list, AlphabetComparator);
	PrintList(list);
	cout << endl;

	cout << "Without dublicates:" << endl;
	RemoveDublicates(&list);
	PrintList(list);
	cout << endl;

	cout << "Removed Orest: " << endl;
	RemoveStringFromList(&list, (String)"Orest");
	PrintList(list);

	DestroyList(&list);

	system("pause");
	return 0;
}
