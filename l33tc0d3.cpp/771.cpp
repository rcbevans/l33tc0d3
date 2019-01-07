#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

//
//771. Jewels and Stones
//Easy
//
//You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.
//
//The letters in J are guaranteed distinct, and all characters in J and S are letters.Letters are case sensitive, so "a" is considered a different type of stone from "A".
//
//Example 1:
//
//Input: J = "aA", S = "aAAbbbb"
//	Output : 3
//
//	Example 2 :
//
//	Input : J = "z", S = "ZZ"
//	Output : 0
//
//	Note :
//
//	S and J will consist of letters and have length at most 50.
//	The characters in J are distinct.
//

namespace l33tc0d3cpp
{
	class Solution {
	public:
		//int numJewelsInStones(string J, string S) {
		//	int count = 0;
		//	for (auto&& jewel : J)
		//	{
		//		count += std::count(S.cbegin(), S.cend(), jewel);
		//	}
		//	return count;
		//}

		//int numJewelsInStones(string J, string S) {
		//	int res = 0;
		//	unordered_set<char> setJ(J.cbegin(), J.cend());
		//	for (auto&& s : S) if (setJ.count(s)) res++;
		//	return res;
		//}

		int numJewelsInStones(string J, string S) {
			unsigned int res = 0;
			std::array<unsigned int, ('z' - 'A') + 1> counters{ 0 };

			for (const auto& s : S)
			{
				++counters[s - 'A'];
			}

			for (const auto& j : J)
			{
				res += counters[j - 'A'];
			}

			return res;
		}
	};

	TEST_CLASS(JewelsAndStones)
	{
	public:
		JewelsAndStones() : _solution() {};

		TEST_METHOD(Example1)
		{
			string J = "aA";
			string S = "aAAbbbb";
			Assert::AreEqual(3, _solution.numJewelsInStones(J, S));
		}

		TEST_METHOD(Example2)
		{
			string J = "z";
			string S = "ZZ";
			Assert::AreEqual(0, _solution.numJewelsInStones(J, S));
		}

	private:
		Solution _solution;
	};
}