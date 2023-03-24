#include "pch.h"
#include "CppUnitTest.h"
#include "../12,6зірочка/12,6зірочка.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* first = NULL; 
			Elem* last = NULL;
			int t = isEmpty(first);
			Assert::AreEqual(t, 1);
		}
	};
}
