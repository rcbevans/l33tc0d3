#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

//
//2. Add Two Numbers
//Medium
//
//You are given two non - empty linked lists representing two non - negative integers.The digits are stored in reverse order and each of their nodes contain a single digit.Add the two numbers and return it as a linked list.
//
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//Example:
//
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//	Output : 7 -> 0 -> 8
//	Explanation : 342 + 465 = 807.
//

namespace Microsoft::VisualStudio::CppUnitTestFramework {
}


namespace l33tc0d3cpp
{
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}
	};

	class Solution {
	public:
		// Doesn't support arbitrarily large numbers - overflows...
		/*ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			ListNode *c1 = l1, *c2 = l2;
			
			if (l1 == nullptr || l2 == nullptr)
			{
				throw exception("Unexpected nullptr");
			}

			int64_t i1 = 0, i2 = 0;
			int64_t m1 = 1, m2 = 1;

			while (c1 && c2)
			{
				if (c1->next && c2->next)
				{
					i1 += c1->val * m1;
					c1 = c1->next;
					i2 += c2->val * m2;
					c2 = c2->next;
					m1 *= 10;
					m2 *= 10;
				}
				else if (c1->next)
				{
					i1 += c1->val * m1;
					c1 = c1->next;
					m1 *= 10;
				}
				else if (c2->next)
				{
					i2 += c2->val * m2;
					c2 = c2->next;
					m2 *= 10;
				}
				else
				{
					i1 += c1->val * m1;
					i2 += c2->val * m2;
					c1 = nullptr;
					c2 = nullptr;
				}
			}

			int64_t sum = i1 + i2;

			if (!sum)
			{
				return new ListNode(0);
			}

			ListNode* head = nullptr;
			ListNode* previous = nullptr;
			ListNode* next = nullptr;
			
			while (sum)
			{
				next = new ListNode(sum % 10);
				if (head == nullptr)
				{
					head = next;
				}
				else
				{
					previous->next = next;
				}
				previous = next;
				sum /= 10;
			}

			return head;
		}*/

		// Returns a newly created list
		/*ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			ListNode *head = nullptr, *previous = nullptr, *next = nullptr;
			ListNode *c1 = l1, *c2 = l2;

			int carry = 0;
			int sum = 0;

			while (c1 || c2)
			{
				if (c1 && c2)
				{
					sum = c1->val + c2->val + carry;
					c1 = c1->next;
					c2 = c2->next;
				}
				else if (c1)
				{
					sum = c1->val + carry;
					c1 = c1->next;
				}
				else if (c2)
				{
					sum = c2->val + carry;
					c2 = c2->next;
				}

				next = new ListNode(sum % 10);
				carry = sum / 10;

				if (!head)
				{
					head = next;
				}
				else
				{
					previous->next = next;
				}

				previous = next;
			}

			if (carry)
			{
				next = new ListNode(carry % 10);
				previous->next = next;
			}

			return head;
		}*/

		// In-place
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			bool returnL1 = true;
			ListNode *c1 = l1, *c1p = nullptr, *c2 = l2, *c2p = nullptr;

			int carry = 0;
			int sum = 0;

			while (c1 || c2)
			{
				if (c1 && c2)
				{
					sum = c1->val + c2->val + carry;
					c1->val = sum % 10;
					c2->val = sum % 10;
					c1p = c1;
					c1 = c1->next;
					c2p = c2;
					c2 = c2->next;
				}
				else if (c1)
				{
					sum = c1->val + carry;
					c1->val = sum % 10;
					c1p = c1;
					c1 = c1->next;
				}
				else if (c2)
				{
					returnL1 = false;
					sum = c2->val + carry;
					c2->val = sum % 10;
					c2p = c2;
					c2 = c2->next;
				}

				carry = sum / 10;

				if (carry && !(c1 || c2))
				{
					if (returnL1)
					{
						c1p->next = new ListNode(carry % 10);
					}
					else
					{
						c2p->next = new ListNode(carry % 10);
					}
				}
			}

			return returnL1 ? l1 : l2;
		}
	};

	TEST_CLASS(AddTwoNumbers)
	{
	public:
		AddTwoNumbers() : _solution() {};

		TEST_METHOD(Example1)
		{
			ListNode* l1 = BuildList({ 2, 4, 3 });
			ListNode* l2 = BuildList({ 5, 6, 4 });

			ListNode* expected = BuildList({ 7,0,8 });

			Assert::IsTrue(AreEquivalent(expected, _solution.addTwoNumbers(l1, l2)));

			FreeList(l1);
			FreeList(l2);
			FreeList(expected);
		}

		TEST_METHOD(Example2)
		{
			ListNode* l1 = BuildList({ 0 });
			ListNode* l2 = BuildList({ 5, 6, 4 });

			ListNode* expected = BuildList({ 5, 6, 4 });

			Assert::IsTrue(AreEquivalent(expected, _solution.addTwoNumbers(l1, l2)));

			FreeList(l1);
			FreeList(l2);
			FreeList(expected);
		}

		TEST_METHOD(Example3)
		{
			ListNode* l1 = BuildList({ 0 });
			ListNode* l2 = BuildList({ 0 });

			ListNode* expected = BuildList({ 0 });

			Assert::IsTrue(AreEquivalent(expected, _solution.addTwoNumbers(l1, l2)));

			FreeList(l1);
			FreeList(l2);
			FreeList(expected);
		}

		TEST_METHOD(Example4)
		{
			ListNode* l1 = BuildList({ 1 });
			ListNode* l2 = BuildList({ 0 });

			ListNode* expected = BuildList({ 1 });

			Assert::IsTrue(AreEquivalent(expected, _solution.addTwoNumbers(l1, l2)));

			FreeList(l1);
			FreeList(l2);
			FreeList(expected);
		}

		TEST_METHOD(Example5)
		{
			ListNode* l1 = BuildList({ 1 });
			ListNode* l2 = BuildList({ 2 });

			ListNode* expected = BuildList({ 3 });

			Assert::IsTrue(AreEquivalent(expected, _solution.addTwoNumbers(l1, l2)));

			FreeList(l1);
			FreeList(l2);
			FreeList(expected);
		}

		TEST_METHOD(Example6)
		{
			ListNode* l1 = BuildList({ 1 });
			ListNode* l2 = BuildList({ 9 });

			ListNode* expected = BuildList({ 0, 1 });

			Assert::IsTrue(AreEquivalent(expected, _solution.addTwoNumbers(l1, l2)));

			FreeList(l1);
			FreeList(l2);
			FreeList(expected);
		}

		TEST_METHOD(Example7)
		{
			ListNode* l1 = BuildList({ 1 });
			ListNode* l2 = BuildList({ 9, 9 });

			ListNode* expected = BuildList({ 0, 0, 1 });

			Assert::IsTrue(AreEquivalent(expected, _solution.addTwoNumbers(l1, l2)));

			FreeList(l1);
			FreeList(l2);
			FreeList(expected);
		}

		TEST_METHOD(Example8)
		{
			ListNode* l1 = BuildList({ 9, 9 });
			ListNode* l2 = BuildList({ 1 });

			ListNode* expected = BuildList({ 0, 0, 1 });

			Assert::IsTrue(AreEquivalent(expected, _solution.addTwoNumbers(l1, l2)));

			FreeList(l1);
			FreeList(l2);
			FreeList(expected);
		}

		TEST_METHOD(Example9)
		{
			ListNode* l1 = BuildList({ 9 });
			ListNode* l2 = BuildList({ 1, 9, 9, 9, 9, 9, 9, 9, 9, 9 });

			ListNode* expected = BuildList({ 0,0,0,0,0,0,0,0,0,0,1 });

			Assert::IsTrue(AreEquivalent(expected, _solution.addTwoNumbers(l1, l2)));

			FreeList(l1);
			FreeList(l2);
			FreeList(expected);
		}

		TEST_METHOD(Example10)
		{
			ListNode* l1 = BuildList({ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 });
			ListNode* l2 = BuildList({ 5, 6, 4 });

			ListNode* expected = BuildList({ 6,6,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 });

			Assert::IsTrue(AreEquivalent(expected, _solution.addTwoNumbers(l1, l2)));

			FreeList(l1);
			FreeList(l2);
			FreeList(expected);
		}

	private:
		ListNode* BuildList(const initializer_list<int>& values)
		{
			ListNode* head = nullptr;
			ListNode* previous = nullptr;
			ListNode* next = nullptr;

			if (!values.size())
			{
				return nullptr;
			}

			for (auto&& v : values)
			{
				next = new ListNode(v);
				if (head == nullptr)
				{
					head = next;
				}
				else
				{
					previous->next = next;
				}
				previous = next;
			}

			return head;
		}

		void FreeList(ListNode* list)
		{
			ListNode* current = list;
			ListNode* next = nullptr;
			
			while (current != nullptr)
			{
				next = current->next;
				delete current;
				current = next;
			}
		}

		bool AreEquivalent(ListNode* l1, ListNode* l2)
		{
			ListNode *it1 = l1, *it2 = l2;

			while (it1 != nullptr && it2 != nullptr)
			{
				if (it1->val != it2->val)
				{
					return false;
				}

				it1 = it1->next;
				it2 = it2->next;
			}

			if (it1 || it2)
			{
				return false;
			}

			return true;
		}

		Solution _solution;
	};
}