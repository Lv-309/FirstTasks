#pragma once

#define INIT_METHOD(MethodName, Owner, Priority) \
		BEGIN_TEST_METHOD_ATTRIBUTE(MethodName)  \
			TEST_OWNER(Owner)					 \
			TEST_PRIORITY(Priority)				 \
		END_TEST_METHOD_ATTRIBUTE()

#define TWO_LISTS_ARE_EQUAL(_list1, _list2)		\
		for (; PTR_TO_NEXT(_list1) != NULL &&	\
			   PTR_TO_NEXT(_list2) != NULL;		\
			  _list1 = NEXT(_list1),			\
			  _list2 = NEXT(_list2))			\
		{										\
			Assert::IsTrue(strcmp(DATA(_list1),	\
				DATA(_list2)) == 0,				\
				L"These lists are different");	\
		}

auto CheckStrInList = [&](list_element list_ptr, char_ptr str) -> bool
{
	if (strcmp(DATA(list_ptr), str) == 0)
	{
		return true;
	}
	for (; list_ptr != NULL && PTR_TO_NEXT(list_ptr) != NULL;
		list_ptr = NEXT(list_ptr))
	{
		if (strcmp(DATA(NEXT(list_ptr)), str) == 0)
		{
			return true;
		}
	}
	return false;
};
