#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

//
//977. Squares of a Sorted Array
//Easy
//
//Given an array of integers A sorted in non - decreasing order, return an array of the squares of each number, also in sorted non - decreasing order.
//
//
//
//Example 1:
//
//Input: [-4, -1, 0, 3, 10]
//	Output : [0, 1, 9, 16, 100]
//	Example 2 :
//
//	Input : [-7, -3, 2, 3, 11]
//	Output : [4, 9, 9, 49, 121]
//
//Note:
//
//1 <= A.length <= 10000
//- 10000 <= A[i] <= 10000
//A is sorted in non - decreasing order.
//

namespace Microsoft::VisualStudio::CppUnitTestFramework {
	using vectint = typename std::vector<int>;
	template<> inline wstring ToString<vectint>(const vectint & t) {
		wostringstream ss;
		ss << " { ";
		for (auto&& i : t)
		{
			ss << i << ", ";
		}
		ss << " } ";
		return ss.str();
	}
}

namespace l33tc0d3cpp
{
	class Solution {
	public:
		vector<int> sortedSquares(vector<int>& A) {
			vector<int> res(A.size());

			int start = 0, end = A.size() - 1;
			
			for (int i = A.size() - 1; i >= 0; i--)
			{
				if (std::abs(A[start]) <= std::abs(A[end]))
				{
					res[i] = std::pow(A[end--], 2);
				}
				else
				{
					res[i] = std::pow(A[start++], 2);
				}
			}
			
			return res;
		}
	};

	TEST_CLASS(SquaresOfSortedArray)
	{
	public:
		SquaresOfSortedArray() : _solution() {};

		TEST_METHOD(Example1)
		{
			vector<int> testVector{ -4, -1, 0, 3, 10 };
			Assert::AreEqual(vector<int>{ 0, 1, 9, 16, 100 }, _solution.sortedSquares(testVector));
		}

		TEST_METHOD(Example2)
		{
			vector<int> testVector{ -7, -3, 2, 3, 11 };
			Assert::AreEqual(vector<int>{ 4, 9, 9, 49, 121 }, _solution.sortedSquares(testVector));
		}

		TEST_METHOD(Example3)
		{
			vector<int> testVector{ 0, 1, 2, 3, 4 };
			Assert::AreEqual(vector<int>{ 0, 1, 4, 9, 16 }, _solution.sortedSquares(testVector));
		}

		TEST_METHOD(Example4)
		{
			vector<int> testVector{ 0, 0, 0, 0, 0 };
			Assert::AreEqual(vector<int>{ 0, 0, 0, 0, 0 }, _solution.sortedSquares(testVector));
		}

		TEST_METHOD(Example5)
		{
			vector<int> testVector{ -4, -3, -2, -1, 0 };
			Assert::AreEqual(vector<int>{ 0, 1, 4, 9, 16 }, _solution.sortedSquares(testVector));
		}

	private:
		Solution _solution;
	};
}