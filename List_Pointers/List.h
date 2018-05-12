#pragma once
#include <iostream>

/* Initializes list */
void StringListInit(char*** list);

/* Destroy list and set pointer to NULL. */
void StringListDestroy(char*** list);

/* Inserts value at the end of the list. */
void StringListAdd(char*** list, char* str);

/* Removes all occurrences of str in the list. */
void StringListRemove(char*** list, char* str);

/* Returns the number of items in the list. */
size_t StringListSize(char** list);

/* Returns the index position of the first occurrence of str in the list. */
size_t StringListIndexOf(char** list, char* str);

/* Replaces every occurrence of the before, in each of the string lists's strings, with after. */
void StringListReplaceInStrings(char*** list, char* before, char* after);

/* Prints list's elements */
void StringListPrint(char** list);