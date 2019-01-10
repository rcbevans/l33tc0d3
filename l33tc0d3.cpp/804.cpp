#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

//804. Unique Morse Code Words
//Easy
//
//International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows : "a" maps to ".-", "b" maps to "-...", "c" maps to "-.-.", and so on.
//For convenience, the full table for the 26 letters of the English alphabet is given below :
//[".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."]
//Now, given a list of words, each word can be written as a concatenation of the Morse code of each letter.For example, "cba" can be written as "-.-..--...", (which is the concatenation "-.-." + "-..." + ".-").We'll call such a concatenation, the transformation of a word.
//Return the number of different transformations among all words we have.
//Example :
//	Input : words = ["gin", "zen", "gig", "msg"]
//	Output : 2
//	Explanation :
//	The transformation of each word is :
//"gin" -> "--...-."
//"zen" -> "--...-."
//"gig" -> "--...--."
//"msg" -> "--...--."
//
//There are 2 different transformations, "--...-." and "--...--.".
//Note:
//The length of words will be at most 100.
//Each words[i] will have length in range[1, 12].
//words[i] will only consist of lowercase letters.

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
		int uniqueMorseRepresentations(vector<string>& words) {
			std::unordered_set<string> representations{};

			for (auto&& word : words)
			{
				std::stringstream sstream;
				for (auto&& ch : word)
				{
					sstream << _representations.at(ch);
				}
				representations.insert(sstream.str());
			}

			return representations.size();
		}

	private:
		const std::unordered_map<char, string> _representations
		{
			{'a', ".-"},
			{'b', "-..."},
			{'c', "-.-."},
			{'d', "-.."},
			{'e', "."},
			{'f', "..-."},
			{'g', "--."},
			{'h', "...."},
			{'i', ".."},
			{'j', ".---"},
			{'k', "-.-"},
			{'l', ".-.."},
			{'m', "--"},
			{'n', "-."},
			{'o', "---"},
			{'p', ".--."},
			{'q', "--.-"},
			{'r', ".-."},
			{'s', "..."},
			{'t', "-"},
			{'u', "..-"},
			{'v', "...-"},
			{'w', ".--"},
			{'x', "-..-"},
			{'y', "-.--"},
			{'z', "--.."}
		};
	};

	TEST_CLASS(UniqueMorse)
	{
	public:
		UniqueMorse() : _solution() {};

		TEST_METHOD(Example1)
		{
			vector<string> testInput{ "gin", "zen", "gig", "msg" };
			Assert::AreEqual(2, _solution.uniqueMorseRepresentations(testInput));
		}

	private:
		Solution _solution;
	};
}