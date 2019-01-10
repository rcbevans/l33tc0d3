#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

//832. Flipping an Image
//Easy
//
//Given a binary matrix A, we want to flip the image horizontally, then invert it, and return the resulting image.
//To flip an image horizontally means that each row of the image is reversed.For example, flipping{1, 1, 0} horizontally results in{0, 1, 1}.
//To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. For example, inverting{0, 1, 1} results in{1, 0, 0}.
//Example 1:
//Input: {{1, 1, 0}, {1, 0, 1}, {0, 0, 0}}
//	Output : {{1, 0, 0}, {0, 1, 0}, {1, 1, 1}}
//	Explanation : First reverse each row : {{0, 1, 1}, {1, 0, 1}, {0, 0, 0}}.
//	Then, invert the image : {{1, 0, 0}, {0, 1, 0}, {1, 1, 1}}
//	Example 2 :
//	Input : {{1, 1, 0, 0}, {1, 0, 0, 1}, {0, 1, 1, 1}, {1, 0, 1, 0}}
//	Output : {{1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 1}, {1, 0, 1, 0}}
//	Explanation : First reverse each row : {{0, 0, 1, 1}, {1, 0, 0, 1}, {1, 1, 1, 0}, {0, 1, 0, 1}}.
//	Then invert the image : {{1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 1}, {1, 0, 1, 0}}
//	Notes :
//	1 <= A.length = A{0}.length <= 20
//	0 <= A{i}{j} <= 1
//

namespace Microsoft::VisualStudio::CppUnitTestFramework {
	using vecvecint = typename std::vector<std::vector<int>>;
	template<> inline wstring ToString<vecvecint>(const vecvecint & t) {
		wostringstream ss;
		ss << " { ";
		for (auto&& row : t)
		{
			ss << " { ";
			for (auto&& i : row)
			{
				ss << i << ", ";
			}
			ss << " } ";
		}
		ss << " } ";
		return ss.str();
	}
}

namespace l33tc0d3cpp
{
	class Solution {
	public:
		vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
			for (auto&& row : A)
			{
				for (int start = 0; start < static_cast<int>(row.size() / 2); start++)
				{
					int startVal = row[start];
					row[start] = row[row.size() - 1 - start] ? 0 : 1;
					row[row.size() - 1 - start] = startVal ? 0 : 1;
				}
				if (row.size() % 2)
				{
					row[row.size() / 2] = row[row.size() / 2] ? 0 : 1;
				}
			}

			return A;
		}
	};

	TEST_CLASS(FlipImage)
	{
	public:
		FlipImage() : _solution() {};

		TEST_METHOD(Example1)
		{
			vector<vector<int>> testInput{ {{1,1,0},{1,0,1},{0,0,0}} };
			Assert::AreEqual(vector<vector<int>>{{1, 0, 0}, {0, 1, 0}, {1, 1, 1}}, _solution.flipAndInvertImage(testInput));
		}

		TEST_METHOD(Example2)
		{
			vector<vector<int>> testInput{{1, 1, 0, 0}, {1, 0, 0, 1}, {0, 1, 1, 1}, {1, 0, 1, 0}};
			Assert::AreEqual(vector<vector<int>>{{1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 1}, {1, 0, 1, 0}}, _solution.flipAndInvertImage(testInput));
		}

		TEST_METHOD(Example3)
		{
			vector<vector<int>> testInput{ {{0,0,0},{0,0,0},{0,0,0}} };
			Assert::AreEqual(vector<vector<int>>{ {1,1,1}, {1,1,1}, { 1, 1, 1 }}, _solution.flipAndInvertImage(testInput));
		}

		TEST_METHOD(Example4)
		{
			vector<vector<int>> testInput{ {1, 1, 1}, { 1,1,1 }, { 1, 1, 1 } };
			Assert::AreEqual(vector<vector<int>>{ {0,0,0}, { 0,0,0 }, { 0,0,0 }}, _solution.flipAndInvertImage(testInput));
		}

		TEST_METHOD(Example5)
		{
			vector<vector<int>> testInput{ {1, 0, 1}, { 1,0,1 }, { 1, 0, 1 } };
			Assert::AreEqual(vector<vector<int>>{ {0, 1, 0}, { 0,1,0 }, { 0,1,0 }}, _solution.flipAndInvertImage(testInput));
		}

		TEST_METHOD(Example6)
		{
			vector<vector<int>> testInput{ {}, {}, {} };
			Assert::AreEqual(vector<vector<int>>{ {}, {}, {} }, _solution.flipAndInvertImage(testInput));
		}

		TEST_METHOD(Example7)
		{
			vector<vector<int>> testInput{ {} };
			Assert::AreEqual(vector<vector<int>>{ {} }, _solution.flipAndInvertImage(testInput));
		}

	private:
		Solution _solution;
	};
}