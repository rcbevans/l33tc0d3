#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

//905. Sort Array By Parity
//Easy
//
//Given an array A of non - negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.
//You may return any answer array that satisfies this condition.
//
//Example 1:
//Input: [3, 1, 2, 4]
//	Output : [2, 4, 3, 1]
//	The outputs[4, 2, 3, 1], [2, 4, 1, 3], and[4, 2, 1, 3] would also be accepted.
//
//	Note :
//	1 <= A.length <= 5000
//	0 <= A[i] <= 5000

namespace Microsoft::VisualStudio::CppUnitTestFramework {
	using vecint = typename std::vector<int>;
	template<> inline wstring ToString<vecint>(const vecint & t) {
		wostringstream ss;
		for (auto&& i : t)
		{
			ss << i << ", ";
		}
		return ss.str();
	}
}
namespace l33tc0d3cpp
{
	class Solution {
	public:
		vector<int> sortArrayByParity(vector<int>& A) {
			std::vector<int> res{};
			//std::deque<int> values{};
			std::array<int, 5000> odd{};

			int oddIndex = 0;
			
			//values.resize(A.size());

			res.reserve(A.size());

			for (auto&& a : A)
			{
				if (a % 2)
				{
					//values.push_back(a);
					odd[oddIndex++] = a;
				}
				else
				{
					//values.push_front(a);
					res.push_back(a);
				}
			}

			res.insert(res.end(), odd.begin(), odd.begin() + oddIndex);

			return res;
		}
	};

	TEST_CLASS(SortArrayByParity)
	{
	public:
		SortArrayByParity() : _solution() {};

		TEST_METHOD(Example1)
		{
			vector<int> testInput{ 3, 1, 2, 4 };
			Assert::AreEqual(vector<int>{2, 4, 3, 1}, _solution.sortArrayByParity(testInput));
		}

		TEST_METHOD(Example2)
		{
			vector<int> testInput{ 0 };
			Assert::AreEqual(vector<int>{0}, _solution.sortArrayByParity(testInput));
		}

		TEST_METHOD(Example3)
		{
			vector<int> testInput{ 0, 1 };
			Assert::AreEqual(vector<int>{0, 1}, _solution.sortArrayByParity(testInput));
		}

		TEST_METHOD(Example4)
		{
			vector<int> testInput{ 1, 0 };
			Assert::AreEqual(vector<int>{0, 1}, _solution.sortArrayByParity(testInput));
		}

		TEST_METHOD(Example5)
		{
			vector<int> testInput{ 1, 0, 1 };
			Assert::AreEqual(vector<int>{0, 1, 1}, _solution.sortArrayByParity(testInput));
		}

		TEST_METHOD(Example6)
		{
			vector<int> testInput{ 1, 0, 1, 3, 5 };
			Assert::AreEqual(vector<int>{0, 1, 1, 3, 5}, _solution.sortArrayByParity(testInput));
		}

		TEST_METHOD(Example7)
		{
			vector<int> testInput{ };
			Assert::AreEqual(vector<int>{}, _solution.sortArrayByParity(testInput));
		}

	private:
		Solution _solution;
	};
}
