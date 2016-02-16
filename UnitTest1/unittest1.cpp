#include "stdafx.h"
#include "CppUnitTest.h"
#include "C:\Users\PeiChangHong\Documents\NUS Modules 14 I 15\Semester 4\CS2103\TextBuddy\Datafile.cpp"
//#include "Datafile.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: Your test code here
			Assert::AreEqual(5,testUnit(5));
		}

	};
}