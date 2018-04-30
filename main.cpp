
#include "List.h"

#include <iostream>
#include <chrono>
#include <ctime>

void ShowList(char*** list) {

	if (IsEmpty(list)) {
		std::cout << "Empty" << std::endl;
		return;
	}

	const size_t SIZE = StringListSize(list);

	for (size_t i = 0; i < SIZE; ++i) {
		std::cout << *list[i] << " ";		
	}
	std::cout << std::endl;
}

int main() {	
	
	const char str1[] = "Serhii";
	const char str2[] = "Tom";
	const char str3[] = "Sem";
	const char str4[] = "Bob";
	const char str5[] = "Mark";		

	char** list = nullptr;

	StringListInit(&list);

	StringListAdd(&list, str2);
	StringListAdd(&list, str3);
	StringListAdd(&list, str4);
	StringListAdd(&list, str4);
	StringListAdd(&list, str2);
	//StringListAdd(&list, str5);

 	ShowList(&list);	
	
	std::cout << " Size " << StringListSize(&list) << std::endl << std::endl;
		
	std::chrono::time_point<std::chrono::system_clock> start, end;
	
	start = std::chrono::system_clock::now();	

	std::cout << std::endl << " After Sorting " << std::endl;
	//StringListSort(&list);	
	QuikSortList(&list, 0, StringListSize(&list) - 1);

	end = std::chrono::system_clock::now();

	ShowList(&list);	
	
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);

	std::cout << " Elapsed time: " << elapsed_seconds.count() << "s\n";

	std::cout << std::endl << " After Removing " << str4 << std::endl;
	StringListRemove(&list, str4);
	ShowList(&list);

	std::cout << std::endl << " After Removing duplicates " << std::endl;
	StringListRemoveDuplicates(&list);
	ShowList(&list);
	
	char strRep[] = "Replaced";

	std::cout << std::endl << " After Replacing Serhii" << std::endl;
	StringListReplaceInStrings(&list, str1, strRep);
	ShowList(&list);

	size_t i = StringListSize(&list);
	size_t j = StringListIndexOf(&list, "Stepan");

	if( i != j)
	std::cout << std::endl << "Index of first occurrence is [" << j << "]";
	else std::cout << " Not found ! ";		

	StringListDestroy(&list);
	
	std::cout << std::endl << "Enter any key to continue...";
	std::cin.get();

	return 0;
}