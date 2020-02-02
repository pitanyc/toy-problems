/**
 * LEETCODE 10: Regular Expression Matching
 *
 * https://leetcode.com/problems/regular-expression-matching/
 *
 * Given an input string (s) and a pattern (p), implement regular
 * expression matching with support for '.' and '*'.
 *
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * 
 * The matching should cover the entire input string (not partial).
 *
 * Note:
 *
 * 1) s could be empty and contains only lowercase letters a-z.
 * 2) p could be empty and contains only lowercase letters a-z, and
 *    characters like . or *.
 * 
 * Example 1:
 *
 * Input:
 * s = "aa"
 * p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 * 
 * Example 2:
 *
 * Input:
 * s = "aa"
 * p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the preceding element, 'a'.
 * Therefore, by repeating 'a' once, it becomes "aa".
 * 
 * Example 3:
 *
 * Input:
 * s = "ab"
 * p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 * 
 * Example 4:
 *
 * Input:
 * s = "aab"
 * p = "c*a*b"
 * Output: true
 * Explanation: c can be repeated 0 times, a can be repeated 1 time.
 * Therefore, it matches "aab".
 * 
 * Example 5:
 *
 * Input:
 * s = "mississippi"
 * p = "mis*is*p*."
 * Output: false
 */

#include <iostream>
#include <string>
#include <vector>

bool checkPrefix(const std::string &p, unsigned int start, unsigned int end)
{
    // assume success
    bool good = true;

    // locals
    std::string prefix = p.substr(start, end);
    unsigned int len = prefix.length();

    // 1. prefix must have even length
    if (len % 2 == 0)
    {
        // 2. every other element must be '*'
        for (unsigned int i = 1; i < len; i += 2)
        {
            if (prefix.at(i) != '*')
            {
                good = false;
                break;
            }
        }
    }
    else
    {
        good = false;
    }

    return good;
}

// SOLUTION:
// Starting with first char in s, find that char OR . in p.
// If found: see how many of that char we need by seeking ahead in s.
// If just 1: then go back to the first step.
// If more than 1 (repeating character): see how many times we need that in p.
//
// Special case: '.*' matches everything, so if true so far then true overall.
bool isMatch(std::string s, std::string p)
{
    // what we return
    bool match = true;

    // size checks
    unsigned int lenS = s.length();
    unsigned int lenP = p.length();
    if (lenS == 0 || lenP == 0)
    {
        return false;
    }

    // at this point, both s & p have size > 0
    unsigned int i = 0; // pointer to char in s
    unsigned int j = 0; // pointer to char in p
    unsigned int prevJ = 0;
    while (match && i < lenS)
    {
        // what we are looking for in p
        const char &c = s.at(i);

        // std::cout << "c = " << c << std::endl;

        // if p is already consumed then we are done
        if (j >= lenP)
        {
            return false;
        }
        else
        {
            bool found = false;
            while (j < lenP && !found)
            {
                const char &pChar = p.at(j);
                // std::cout << "pChar: " << pChar << std::endl;

                if (pChar == '.')
                {
                    // see if followed by '*'
                    if (j + 1 < lenP && p.at(j + 1) == '*')
                    {
                        return true;
                    }
                    else if (prevJ + 1 < j)
                    {
                        if (!checkPrefix(p, prevJ, j))
                        {
                            match = false;
                            break;
                        }
                    }
                    prevJ = j;
                    found = true;
                }
                else if (pChar == '*')
                {
                    prevJ = j;
                }
                else if (pChar == c)
                {
                    // see if followed by '*'
                    if (j + 1 < lenP && p.at(j + 1) == '*')
                    {
                        // advance i until it changes chars or over
                        while (i + 1 < lenS && s.at(i + i) == c)
                        {
                            // advance i
                            i++;
                        }
                    }

                    if (prevJ + 1 < j)
                    {
                        if (!checkPrefix(p, prevJ, j))
                        {
                            match = false;
                            break;
                        }
                    }
                    prevJ = j;
                    found = true;
                }
                j++;
            }
        }
        i++;
    }

    // finally return
    return match;
}

int main(int argc, char const *argv[])
{
    // test case 1
    std::string s = "aa";
    std::string p = "a";
    std::cout << "s = '" << s << "'" << std::endl;
    std::cout << "p = '" << p << "'" << std::endl;
    bool output = isMatch(s, p);
    std::cout << "output: " << output << std::endl;

    // test case 2
    s = "aa";
    p = "a*";
    std::cout << "====\ns = '" << s << "'" << std::endl;
    std::cout << "p = '" << p << "'" << std::endl;
    output = isMatch(s, p);
    std::cout << "output: " << output << std::endl;

    // test case 3
    s = "ab";
    p = ".*";
    std::cout << "====\ns = '" << s << "'" << std::endl;
    std::cout << "p = '" << p << "'" << std::endl;
    output = isMatch(s, p);
    std::cout << "output: " << output << std::endl;

    // test case 4
    s = "aab";
    p = "c*a*b";
    std::cout << "====\ns = '" << s << "'" << std::endl;
    std::cout << "p = '" << p << "'" << std::endl;
    output = isMatch(s, p);
    std::cout << "output: " << output << std::endl;

    // test case 5
    s = "mississippi";
    p = "mis*is*p*.";
    std::cout << "====\ns = '" << s << "'" << std::endl;
    std::cout << "p = '" << p << "'" << std::endl;
    output = isMatch(s, p);
    std::cout << "output: " << output << std::endl;

    return 0;
}
