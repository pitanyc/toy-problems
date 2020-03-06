/**
 * LEETCODE 38. Count and Say
 *
 * https://leetcode.com/problems/count-and-say/
 *
 * The count-and-say sequence is the sequence of integers with the first
 * five terms as following:
 *
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221 1 is read off as "one 1" or 11. 11 is read off as "two
 *        1s" or 21. 21 is read off as "one 2, then one 1" or 1211.
 *
 * Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the
 * count-and-say sequence. You can do so recursively, in other words
 * from the previous member read off the digits, counting the number of
 * digits in groups of the same digit.
 *
 * Note: Each term of the sequence of integers will be represented as a
 * string.
 *
 * Example 1:
 *
 * Input: 1
 * Output: "1"
 * Explanation: This is the base case.
 * 
 * Example 2:
 * 
 * Input: 4
 * Output: "1211"
 * Explanation: For n = 3 the term was "21" in which we have two
 * groups "2" and "1", "2" can be read as "12" which means frequency = 1
 * and value = 2, the same way "1" is read as "11", so the answer is the
 * concatenation of "12" and "11" which is "1211".
 */

#include <iostream>
#include <string>

using namespace std;

// SOLUTION: Build the output bottom up, starting with the base case.
//           At each iteration, we go thru the previous result (previous string)
//           and simply count how many of the same numbers (characters) are 
//           there one after another.
//
//           This solution uses 3 loops:
//              => to go from 1..n
//              => to go thru the previous result string
//              => to find the same repeating chars in the previous result string
//
// Time: O(n) - need to build stuff bottom up
// Space: O(n) - two strings, their lengths depends on the input n
string countAndSay(int n)
{
    // sanity checks
    if (n < 1 || n > 30)
    {
        return std::string();
    }

    // what we return
    string returnValue("1");    // base case, stores previous result

    // build output from the bottom up
    for ( int i = 1; i < n; i++ )
    {
        // build current string by consuming previous result
        string current;
        for ( int j = 0; j < returnValue.size(); j++ )
        {
            int count = 1;
            const char& what = returnValue[j];
            for ( int k = j + 1; k < returnValue.size(); k++ )
            {
                if ( returnValue[k] == what )
                {
                    count++;
                    j++;
                }
                else
                {
                    break;
                }
            }
            current += to_string(count) + what;
        }
        returnValue = current;
    }

    // finally return
    return returnValue;
}

int main(int argc, char const *argv[])
{
    // test case 1
    int n = 1;
    string output = countAndSay(n);
    std::cout << "n: " << n << "\noutput: " << output << std::endl;

    // test case 2
    std::cout << "\n====\n" << std::endl;
    n = 2;
    output = countAndSay(n);
    std::cout << "n: " << n << "\noutput: " << output << std::endl;

    // test case 3
    std::cout << "\n====\n" << std::endl;
    n = 3;
    output = countAndSay(n);
    std::cout << "n: " << n << "\noutput: " << output << std::endl;

    // test case 4
    std::cout << "\n====\n" << std::endl;
    n = 4;
    output = countAndSay(n);
    std::cout << "n: " << n << "\noutput: " << output << std::endl;

    // test case 5
    std::cout << "\n====\n" << std::endl;
    n = 5;
    output = countAndSay(n);
    std::cout << "n: " << n << "\noutput: " << output << std::endl;

    return 0;
}
