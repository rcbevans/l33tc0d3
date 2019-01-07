#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

//
//929. Unique Email Addresses
//Easy
//
//Every email consists of a local name and a domain name, separated by the @ sign.
//
//For example, in alice@leetcode.com, alice is the local name, and leetcode.com is the domain name.
//
//Besides lowercase letters, these emails may contain '.'s or '+'s.
//
//If you add periods('.') between some characters in the local name part of an email address, mail sent there will be forwarded to the same address without dots in the local name.For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same email address.  (Note that this rule does not apply for domain names.)
//
//If you add a plus('+') in the local name, everything after the first plus sign will be ignored.This allows certain emails to be filtered, for example m.y + name@email.com will be forwarded to my@email.com.  (Again, this rule does not apply for domain names.)
//
//It is possible to use both of these rules at the same time.
//
//Given a list of emails, we send one email to each address in the list.How many different addresses actually receive mails ?
//
//
//
//Example 1 :
//
//	Input : ["test.email+alex@leetcode.com", "test.e.mail+bob.cathy@leetcode.com", "testemail+david@lee.tcode.com"]
//	Output : 2
//	Explanation : "testemail@leetcode.com" and "testemail@lee.tcode.com" actually receive mails
//
//
//
//	Note :
//
//1 <= emails[i].length <= 100
//1 <= emails.length <= 100
//Each emails[i] contains exactly one '@' character.
//

namespace l33tc0d3cpp
{
	class Solution {
	public:
		//int numUniqueEmails(vector<string>& emails) {
		//	std::unordered_set<std::string> distinct;

		//	for (auto&& email : emails)
		//	{
		//		auto plus = std::find(email.begin(), email.end(), '+');
		//		auto at = std::find(email.begin(), email.end(), '@');

		//		if (plus != email.end())
		//		{
		//			email.erase(plus, at);
		//		}

		//		at = std::find(email.begin(), email.end(), '@');

		//		email.erase(std::remove_if(email.begin(), at, [](auto&& ch) { return ch == '.'; }), at);

		//		distinct.insert(email);
		//	}

		//	return distinct.size();
		//}

		int numUniqueEmails(vector<string>& emails) {
			std::unordered_set<std::string> distinct;

			for (auto&& email : emails)
			{
				for (int i = 0; i < email.length(); i++)
				{
					if (email[i] == '.')
					{
						email.erase(i--, 1);
					}
					else if (email[i] == '+')
					{
						email.erase(i, email.find('@', i) - i);
						break;
					}
					else if (email[i] == '@')
					{
						break;
					}
				}

				distinct.insert(email);
			}

			return distinct.size();
		}
	};

	TEST_CLASS(UniqueEmailAddresses)
	{
	public:
		UniqueEmailAddresses() : _solution() {};

		TEST_METHOD(Example1)
		{
			vector<string> testInput{ "test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com" };
			Assert::AreEqual(2, _solution.numUniqueEmails(testInput));
		}

	private:
		Solution _solution;
	};
}