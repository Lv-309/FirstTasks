#pragma once
#include<stdlib.h>
#include<string.h>

void StringListInit(char*** list)
{
	*list = NULL;
	*list = (char**)malloc(2 * sizeof(char*)); // allocate memory for 2 pointers

	if (!(*list)) // if memory allocation wasn't happened
		return;
}

void StringListAdd(char***list, char* str)
{
	if (str == NULL)
		return;

	char** temp_node;

	StringListInit(&temp_node);

	temp_node[0] = str;
	temp_node[1] = NULL;

	if (*list == NULL) // if it's our first node
		*list = temp_node;
	else
	{
		char** temp_list = *list;

		while (temp_list[1] != NULL) // goes to the end of the list
			temp_list = (char**)temp_list[1];

		temp_list[1] = (char*)temp_node;
	}
}

void StringListDestroy(char*** list)
{
	while (*list != NULL)
	{
		char** temp_node = *list;
		*list = (char**)(*list)[1];
		free(temp_node);
	}
}

void StringListRemove(char*** list, char* str)
{
	if (str == NULL)
		return;

	bool find = false;
	char** needed_node = *list;

	while (needed_node != NULL && needed_node[0] != str) // searching for needed node
		needed_node = (char**)needed_node[1];

	if (needed_node != NULL)
		find = true;

	if (find)
	{
		char** temp_list = *list;

		if (temp_list[0] == str) // if needed node is the first node in our list
		{
			*list = (char**)temp_list[1];
			free(temp_list);
		}
		else
		{
			while ((char**)temp_list[1] != needed_node) // search node that situated before needed node
				temp_list = (char**)temp_list[1];

			temp_list[1] = needed_node[1]; // connect list
			free(needed_node);
		}
	}
	//else printf("didn't find")
}

int StringListSize(char** list)
{
	int counter = 0;

	while (list != NULL)
	{
		list = (char**)list[1];
		counter++;
	}

	return counter;
}

int StringListIndexOf(char** list, char* str)
{
	if (str == NULL)
		return 0;

	int counter = 0, index = 0;

	while (list != NULL)
	{
		index++;

		for (int i(0); i < strlen(list[0]); i++)
			if (list[0][i] == str[0])				// check if there is first exact match of specified string
			{
				for (int j(0); j < strlen(str); j++)
					if (list[0][i + j] == str[j])
						counter++;

				if (counter == strlen(str))
					return index;
				else
					counter = 0;
			}
		list = (char**)list[1];
	}

	// maybe cout << "There isn't such string:" << str;
	return 0;
}

void StringListRemoveDuplicates(char*** list)
{
	char** first_list = *list;
	char** second_list = *list;

	while (first_list != NULL)
	{
		char* str = first_list[0];
		first_list = (char**)first_list[1]; // first list goes to next node to avoid exception

		while (second_list != NULL)
		{
			second_list = (char**)second_list[1]; // starts from next node as we shouldn't compare node between itself
			if (second_list != NULL && str == second_list[0])
			{
				StringListRemove(list, str);
				break;
			}
		}

		second_list = first_list;
	}
}

void StringListReplace(char*** list, char* before, char* after)
{
	if (*list == NULL || before == NULL || after == NULL)
		return;

	char** temp_list = *list;
	int index = StringListIndexOf(*list, before); // find index of before string

	if (index > 0) // if such string exists
	{
		for (int i(0); i < index - 1; i++) // go to node that have this string
			temp_list = (char**)temp_list[1];

		temp_list[0] = after; // replace
	}
}

void StringListBubbleSort(char*** list)
{
	if (*list == NULL)
		return;

	for (int i(0); i < StringListSize(*list) - 1; i++)
	{
		char** first_list = *list;
		char** second_list = (char**)first_list[1];

		for (int j(0); j < StringListSize(*list) - 1; j++)
		{
			if (strcmp(first_list[0], second_list[0]) > 0) // strcmp return 1 if first_str > second_str
			{
				char* temp_str = first_list[0];
				first_list[0] = second_list[0];
				second_list[0] = temp_str;
			}

			/*if (second_list[1] != NULL) // if we remove "-1" from if-statement
			{*/
			first_list = (char**)first_list[1];
			second_list = (char**)second_list[1];
			//}
		}
	}
}

char*** GetArrayOfStrings(char** list)
{
	if (list == NULL)
		return NULL;

	int size = StringListSize(list);

	char*** array = (char***)malloc(size * sizeof(char**));

	for (int i(0); i < size; i++)
	{
		array[i] = list;
		list = (char**)list[1];
	}

	return array;
}

void QuickSort(char*** array_of_strings, int start, int end)
{
	int i = start;
	int j = end;
	char* middle = *(array_of_strings[(i + j) / 2]);

	do
	{
		while (strcmp(middle, *(array_of_strings[i])) > 0) i++;
		while (strcmp(*(array_of_strings[j]), middle) > 0) j--;

		if (i <= j)
		{
			char* temp = *(array_of_strings[i]);
			*(array_of_strings[i]) = *(array_of_strings[j]);
			*(array_of_strings[j]) = temp;

			i++;
			j--;
		}
	} while (i < j);

	if (i < end) QuickSort(array_of_strings, i, end);
	if (j > start) QuickSort(array_of_strings, start, j);
}

void StringListQuickSort(char** list)
{
	char*** array_of_strings = GetArrayOfStrings(list);

	if (array_of_strings == NULL)
		return;

	QuickSort(array_of_strings, 0, StringListSize(list) - 1);
}