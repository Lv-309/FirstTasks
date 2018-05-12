#include <stdlib.h>
#include <string.h>

#include "List.h"

void StringListInit(char*** list)
{
	*list = (char**)malloc(2 * sizeof(char*));
}

void StringListDestroy(char*** list)
{
	if (*list == NULL)
	{
		std::cout << "List is empty\n";
	}
	else
	{
		char** next_element = NULL;

		while (*list != NULL)
		{
			next_element = (char**)(*list)[1];
			free(*list);
			*list = next_element;
		}

		*list = NULL;
	}
}

void StringListAdd(char*** list, char* str)
{
	char** new_element;

	StringListInit(&new_element);

	new_element[0] = str;
	new_element[1] = NULL;

	if (*list == NULL)
	{
		*list = new_element;
	}
	else
	{
		char** storage_list = *list;

		while (storage_list[1] != NULL) 
			storage_list = (char**)storage_list[1];

		storage_list[1] = (char*)new_element;
	}
}

void StringListRemove(char*** list, char* str)
{
	if (list == NULL)
	{
		std::cout << "List is empty\n";
	}
	else
	{
		char** necessary_element = *list;

		while (necessary_element != NULL && necessary_element[0] != str)
		{
			necessary_element = (char**)necessary_element[1];
		}

		if (necessary_element != NULL)
		{
			char** storage_list = *list;

			if (storage_list[0] == str)
			{
				*list = (char**)storage_list[1];
				free(storage_list);
			}
			else
			{
				while ((char**)storage_list[1] != necessary_element)
				{
					storage_list = (char**)storage_list[1];
				}

				storage_list[1] = necessary_element[1];
				free(necessary_element);
			}
		}
		else
		{
			std::cout << "Necessary stuff wasn't finded\n";
		}
	}
}

size_t StringListSize(char** list)
{
	if (list == NULL)
	{
		std::cout << "List is empty\n";
	}
	else
	{
		size_t counter = 0;

		while (list != NULL)
		{
			list = (char**)list[1];
			counter++;
		}

		return counter;
	}
}

size_t StringListIndexOf(char** list, char* str)
{
	if (list == NULL)
	{
		std::cout << "List is empty\n";
	}
	else
	{
		size_t counter = 0;

		while (list != NULL)
		{
			counter++;

			if (strstr(list[0], str) != NULL)
			{
				return counter;
			}

			list = (char**)list[1];
		}
	}
}

void StringListReplaceInStrings(char*** list, char* before, char* after)
{
	if (list == NULL)
	{
		std::cout << "List is empty\n";
	}
	else
	{
		char** storage_list = *list;

		while (storage_list != NULL)
		{
			if (strcmp((char*)storage_list[0], before) == 0)
			{
				storage_list[0] = after;
			}

			storage_list = (char**)storage_list[1];
		}
	}
}

void StringListPrint(char** list)
{
	if (list == NULL)
	{
		std::cout << "It is nothing to print\n";
	}
	else
	{
		while (list != NULL)
		{
			std::cout << list[0];
			list = (char**)list[1];
		}

		std::cout << "\n\n";
	}
}