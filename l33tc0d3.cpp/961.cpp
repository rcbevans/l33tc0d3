#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

//
//961. N - Repeated Element in Size 2N Array
//Easy
//
//In a array A of size 2N, there are N + 1 unique elements, and exactly one of these elements is repeated N times.
//
//Return the element repeated N times.
//
//
//
//Example 1:
//
//Input: [1, 2, 3, 3]
//	Output : 3
//
//	Example 2 :
//
//	Input : [2, 1, 2, 5, 3, 2]
//	Output : 2
//
//	Example 3 :
//
//	Input : [5, 1, 5, 2, 5, 3, 5, 4]
//	Output : 5
//
//	Note :
//
//	4 <= A.length <= 10000
//	0 <= A[i] < 10000
//	A.length is even
//

namespace l33tc0d3cpp
{
	class Solution {
	public:
		int repeatedNTimes(vector<int>& A) {
			array<unsigned int, 10000> values{};
			auto target = A.size() / 2;
			
			for (auto&& i : A)
			{
				if (++values[i] == target) return i;
			}

			return 0;
		}
	};

	TEST_CLASS(NRepeatedElementsIn2NArray)
	{
	public:
		NRepeatedElementsIn2NArray() : _solution() {};
		
		TEST_METHOD(Example1)
		{
			vector<int> testVector{ 1, 2, 3, 3 };
			Assert::AreEqual(3, _solution.repeatedNTimes(testVector));
		}

		TEST_METHOD(Example2)
		{
			vector<int> testVector{ 2, 1, 2, 5, 3, 2 };
			Assert::AreEqual(2, _solution.repeatedNTimes(testVector));
		}

		TEST_METHOD(Example3)
		{
			vector<int> testVector{ 5, 1, 5, 2, 5, 3, 5, 4 };
			Assert::AreEqual(5, _solution.repeatedNTimes(testVector));
		}

	private:
		Solution _solution;
	};
}