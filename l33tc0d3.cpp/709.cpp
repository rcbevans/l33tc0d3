#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

//
//709. To Lower Case
//Easy
//
//Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.
//
//
//Example 1:
//
//	Input: "Hello"
//	Output : "hello"
//
//	Example 2 :
//
//	Input : "here"
//	Output : "here"
//
//	Example 3 :
//
//	Input : "LOVELY"
//	Output : "lovely"
//

namespace l33tc0d3cpp
{
	class Solution {
	public:
		//string toLowerCase(string str) {
		//	for (int i = 0; i < str.length(); i++)
		//	{
		//		str[i] = tolower(str[i]);
		//	}
		//	return str;
		//}

		string toLowerCase(string str) {
			for (int i = 0; i < str.length(); i++)
			{
				auto&& ch = str[i];

				if (ch >= 'A' && ch <= 'Z')
				{
					str[i] = ch - 'A' + 'a';
				}
			}
			return str;
		}
	};

	TEST_CLASS(ToLowerCase)
	{
	public:
		ToLowerCase() : _solution() {};

		TEST_METHOD(Example1)
		{
			string testInput{ "Hello" };
			Assert::AreEqual(string{ "hello" }, _solution.toLowerCase(testInput));
		}

		TEST_METHOD(Example2)
		{
			string testInput{ "here" };
			Assert::AreEqual(string{ "here" }, _solution.toLowerCase(testInput));
		}

		TEST_METHOD(Example3)
		{
			string testInput{ "LOVELY" };
			Assert::AreEqual(string{ "lovely" }, _solution.toLowerCase(testInput));
		}

		TEST_METHOD(Example4)
		{
			string testInput{ "TesTC@s3" };
			Assert::AreEqual(string{ "testc@s3" }, _solution.toLowerCase(testInput));
		}

	private:
		Solution _solution;
	};
}