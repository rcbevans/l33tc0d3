#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

//1. Two Sum
//Easy
//
//Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
//Example:
//
//Given nums = [2, 7, 11, 15], target = 9,
//
//Because nums[0] + nums[1] = 2 + 7 = 9,
//return[0, 1].

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
		//C++11 - leetcode submission
		//vector<int> twoSum(vector<int>& nums, int target) {
		//	unordered_map<int, int> seen{};
		//	for (int i = 0; i < nums.size(); i++)
		//	{
		//		auto found = seen.find(target - nums[i]);
		//		if (found != seen.end())
		//		{
		//			return { found->second, i };
		//		}
		//		seen.emplace(nums[i], i);
		//	}
		//}

		vector<int> twoSum(vector<int>& nums, int target) {
			unordered_map<int, int> seen{};

			for (int i = 0; i < nums.size(); i++)
			{
				if (auto found = seen.find(target - nums[i]); found != seen.end())
				{
					return { found->second, i };
				}
				seen.emplace(nums[i], i);
			}

			throw new exception("Didn't find solution");
		}
	};

	TEST_CLASS(TwoSum)
	{
	public:
		TwoSum() : _solution() {};

		TEST_METHOD(Example1)
		{
			vector<int> testInput{ 2, 7, 11, 15 };
			Assert::AreEqual(vector<int>{0, 1}, _solution.twoSum(testInput, 9));
		}

		TEST_METHOD(Example2)
		{
			vector<int> testInput{ 2, 7, 11, 15 };
			Assert::AreEqual(vector<int>{0, 2}, _solution.twoSum(testInput, 13));
		}

		TEST_METHOD(Example3)
		{
			vector<int> testInput{ 2, 7, 11, 15 };
			Assert::AreEqual(vector<int>{0, 3}, _solution.twoSum(testInput, 17));
		}

		TEST_METHOD(Example4)
		{
			vector<int> testInput{ 2, 7, 11, 15 };
			Assert::AreEqual(vector<int>{1, 2}, _solution.twoSum(testInput, 18));
		}

		TEST_METHOD(Example5)
		{
			vector<int> testInput{ 2, 7, 11, 15 };
			Assert::AreEqual(vector<int>{1, 3}, _solution.twoSum(testInput, 22));
		}

		TEST_METHOD(Example6)
		{
			vector<int> testInput{ 2, 7, 11, 15 };
			Assert::AreEqual(vector<int>{2, 3}, _solution.twoSum(testInput, 26));
		}

		TEST_METHOD(Example7)
		{
			vector<int> testInput{ -2, 7, 11, 15 };
			Assert::AreEqual(vector<int>{0, 1}, _solution.twoSum(testInput, 5));
		}

	private:
		Solution _solution;
	};
}