#include "pch.h"
#include "CppUnitTest.h"
#include "../lab12.5/Source.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestStackOperations)
		{
			Node* top = nullptr;
			push(top, "banana");
			push(top, "cherry");
			push(top, "cherry");
			push(top, "grape");
			push(top, "apple");
			push(top, "apple");
			push(top, "cherry");
			push(top, "banana");
			push(top, "banana");
			push(top, "banana");
			push(top, "cherry");
			push(top, "cherry");
			push(top, "orange");
			push(top, "grape");
			push(top, "grape");
			push(top, "grape");
			push(top, "grape");
			push(top, "banana");
			push(top, "banana");
			push(top, "banana");
			push(top, "orange");

			int stackLengthResult = stackLength(top);
			std::pair<std::string, int> longestWordInfo = findLongestWord(top);
			std::pair<std::string, int> shortestWordInfo = findShortestWord(top);
			int appleCount = countWordOccurrences(top, "apple");
			int grapeCount = countWordOccurrences(top, "grape");

			Assert::AreEqual(21, stackLengthResult);
			Assert::AreEqual("orange", longestWordInfo.first.c_str()); 
			Assert::AreEqual(0, longestWordInfo.second);
			Assert::AreEqual("grape", shortestWordInfo.first.c_str()); 
			Assert::AreEqual(4, shortestWordInfo.second);
			Assert::AreEqual(2, appleCount);
			Assert::AreEqual(5, grapeCount);

		}
	};
}
