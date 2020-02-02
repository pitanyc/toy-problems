/**
 * LEETCODE 3: Longest Substring Without Repeating Characters
 * 
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * 
 * Given a string, find the length of the longest substring without
 * repeating characters.
 *
 * Example 1:
 *
 * Input: "abcabcbb" Output: 3 Explanation: The answer is "abc", with
 * the length of 3.
 * 
 * Example 2:
 *
 * Input: "bbbbb" Output: 1 Explanation: The answer is "b", with the
 * length of 1.
 * 
 * Example 3:
 *
 * Input: "pwwkew" Output: 3 Explanation: The answer is "wke", with the
 * length of 3. Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 */

#include <iostream>
#include <string>
#include <set>

std::ostream &operator<<(std::ostream &os, const std::set<char> set)
{
    for (std::set<char>::const_iterator it = set.begin();
         it != set.end();
         it++)
    {
        os << *it << " ";
    }
    return os;
}

// Return value must be between [0, 26].
int lengthOfLongestSubstring(std::string s)
{
    // what we return
    int longest = 0;

    // locals
    unsigned int len = s.length();
    std::set<char> set;

    // consume input
    for (unsigned int i = 0; i < len; i++)
    {
        // next char
        const char &c = s.at(i);

        if (set.find(c) != set.end())
        {
            // already in set ==> reset counter, empty set
            set.clear();
        }

        // insert incoming char into set
        set.insert(c);
        // std::cout << "c = " << c << ", set = " << set << std::endl;

        // see if we need to update longest
        if (set.size() > longest)
        {
            longest = set.size();
        }
    }

    // finally return
    return longest;
}

int main(int argc, char const *argv[])
{
    // test case 1
    std::string input = "abcabcbb";
    std::cout << "input: '" << input << "'" << std::endl;
    int output = lengthOfLongestSubstring(input);
    std::cout << "output: '" << output << "'" << std::endl;

    // test case 2
    input = "bbbbb";
    std::cout << "====\ninput: '" << input << "'" << std::endl;
    output = lengthOfLongestSubstring(input);
    std::cout << "output: '" << output << "'" << std::endl;

    // test case 3
    input = "pwwkew";
    std::cout << "====\ninput: '" << input << "'" << std::endl;
    output = lengthOfLongestSubstring(input);
    std::cout << "output: '" << output << "'" << std::endl;

    return 0;
}
