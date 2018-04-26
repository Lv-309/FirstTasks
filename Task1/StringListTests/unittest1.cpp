#include "stdafx.h"
#include "CppUnitTest.h"
#include "../../SoftServe_task1/SoftServe_task1/list.h"
#include "../../SoftServe_task1/SoftServe_task1/MakeRandStr.h"
#include "helptools.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;															

namespace UnitTest1
{
	TEST_CLASS(StringListUnitTest1)
	{
	public:
		INIT_METHOD(StringListInit_PositiveTest, L"Andrew", 1)
		TEST_METHOD(StringListInit_PositiveTest)
		{
			// Init
			list_element str_list = NULL;
			StringListInit(&str_list);
			// Check
			Assert::IsNotNull(str_list, L"Memory not allocated");
		}

		INIT_METHOD(StringListAdd_PositiveTest, L"Andrew", 1)
		TEST_METHOD(StringListAdd_PositiveTest)
		{
			// Init
			list_element str_list = NULL;
			char str1[256];
			// Add in str_list
			StringListAdd(&str_list, MakeString(str1));
			// Check
			Assert::IsTrue(CheckStrInList(str_list, str1), 
					L"Didn't add string");
		}

		INIT_METHOD(StringListDestroy_NegativeTest, L"Andrew", 2)
		TEST_METHOD(StringListDestroy_NegativeTest)
		{
			// Init
			list_element str_list = NULL;
			char str1[256];
			// Add in str_list
			StringListAdd(&str_list, MakeString(str1));
			// Destroy
			StringListDestroy(&str_list);
			// Check
			Assert::IsNull(str_list, L"String list must be NULL");
		}

		INIT_METHOD(StringListSize_PositiveTest, L"Andrew", 2)
		TEST_METHOD(StringListSize_PositiveTest)
		{
			// Init
			list_element str_list = NULL;
			char str1[256];
			size_t counter = 0U;
			// Add in str_list and INC counter
			StringListAdd(&str_list, MakeString(str1));
			++counter;
			StringListAdd(&str_list, MakeString(str1));
			++counter;
			// Check
			Assert::AreEqual(StringListSize(str_list), counter, 
					L"List size isn't correct");
		}

		INIT_METHOD(StringListRemove_NegativeTest, L"Andrew", 1)
		TEST_METHOD(StringListRemove_NegativeTest)
		{
			// Init
			list_element str_list = NULL;
			char str1[256];
			// Add in str_list
			StringListAdd(&str_list, MakeString(str1));
			StringListAdd(&str_list, MakeString(str1));
			// Remove
			StringListRemove(&str_list, str1);
			// Check
			Assert::IsFalse(CheckStrInList(str_list, str1), 
					L"String hasn't been deleted");
		}

		INIT_METHOD(StringListSort_PositiveTest, L"Andrew", 1)
		TEST_METHOD(StringListSort_PositiveTest)
		{
			// Init
			list_element str_list1 = NULL;
			list_element str_list2 = NULL;
			char str1[] = "Hi, im a very long string";
			char str2[] = "String list init";
			char str3[] = "Another long string";
			// Add in str_list1
			StringListAdd(&str_list1, str2);
			StringListAdd(&str_list1, str3);
			StringListAdd(&str_list1, str1);
			// Add in str_list2
			StringListAdd(&str_list2, str1);
			StringListAdd(&str_list1, str3);
			StringListAdd(&str_list2, str2);
			// Sort
			StringListSort(str_list2);
			// Check
			TWO_LISTS_ARE_EQUAL(str_list2, str_list1);
		}

		INIT_METHOD(StringListRemoveDuplicates_PositiveTest, L"Andrew", 2)
		TEST_METHOD(StringListRemoveDuplicates_PositiveTest)
		{
			// Init
			list_element str_list = NULL;
			char str1[] = "Hi, im a very long string";
			char str2[] = "String list init";
			// Add in str_list
			StringListAdd(&str_list, str1);
			StringListAdd(&str_list, str2);
			StringListAdd(&str_list, str2);
			StringListAdd(&str_list, str1);
			// Sort
			StringListSort(str_list);
			// Remove Duplicates
			StringListRemoveDuplicates(str_list);
			// Check
			Assert::IsTrue(CheckStrInList(str_list, str1) &&
					CheckStrInList(str_list, str2),
					L"The list don't contain these strings");
			Assert::IsTrue(StringListSize(str_list) == 2,
					L"String isn't removed");
		}

		INIT_METHOD(StringListReplaceInStrings_PositiveTest, L"Andrew", 2)
		TEST_METHOD(StringListReplaceInStrings_PositiveTest)
		{
			// Init
			list_element str_list = NULL;
			char before[] = "Hi, im a very long string";
			char after[]  = "String for replace";
			// Add in str_list
			StringListAdd(&str_list, before);
			// Replace Strings
			StringListReplaceInStrings(str_list, before, after);
			// Check
			Assert::IsTrue(strcmp(DATA(str_list), after) == 0,
					L"String isn't replaced");
		}
	};
}