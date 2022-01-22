/**
 * LEETCODE 91. Decode Ways
 *
 * https://leetcode.com/problems/decode-ways/
 *
 * A message containing letters from A-Z can be encoded into numbers using the
following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back
into letters using the reverse of the mapping above (there may be multiple
ways). For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into
'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The test cases are generated so that the answer fits in a 32-bit integer.



Example 1:

Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: s = "226"
Output: 3
Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
6). Example 3:

Input: s = "06"
Output: 0
Explanation: "06" cannot be mapped to "F" because of the leading zero ("6" is
different from "06").
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// STREAM OPERATOR ==> vector of int
ostream& operator<<(ostream& os, const vector<int>& arr)
{
    os << "[";
    for ( vector<int>::const_iterator it = arr.begin(); it != arr.end(); it++ )
    {
        os << *it;
        if ( it + 1 != arr.end() )
        {
            os << " ";
        }
    }
    os << "]";
    return os;
}

// STREAM OPERATOR ==> vector of vector of int
ostream& operator<<(ostream& os, const vector<vector<int>>& arr)
{
    os << endl;
    for ( vector<vector<int>>::const_iterator it = arr.begin(); it != arr.end();
          it++ )
    {
        os << "  " << *it;
        if ( it + 1 != arr.end() )
            os << endl;
    }
    return os;
}

// SOLUTION 1: This is a Fibonacci-style problem.
//             Every Fibonacci style problem is a 1 dimensional DP problem
//             (or recursive).
//
//             Base cases:
//              * empty string => 0
//              * "0" => 0
//              * "1-9" => 1
//                        
//             At each index in the string, the number of ways it can be
//             decoded equals the number of ways a 1 char (next char)
//             smaller substring can be decoded + the number of ways the 
//             second next can be decoded IF the first two chars are valid.
//
// Time:  O(N)
// Space: O(1)
int numDecodings(string s)
{
    // sanity checks
    if ( s.empty() )
    {
        return 0;
    }

    // locals
    int len = s.length();
    string validDigits = "0123456";

    // create dp table:
    // Each position means how many ways the string can be decoded up
    // to that index.  We consume the string backwards because the last digit
    // what we want to return is the dp[0].
    vector<int> dp(len + 1, 1);

    for (int i = len - 2; i >= 0; i--)
    {
        char& curr = s.at(i);
        char& next = s.at(i + 1);
        if ( curr == '0' )
        {
            // 0
            dp.at(i) = 0;
        }
        else
        {
            // 1..9
            dp.at(i) = dp.at(i + 1);
        }

        // check if curr char + next char is valid
        if ( curr == '1' ||
            (curr == '2' && validDigits.find(next) != string::npos) )
        {
            dp.at(i) += dp.at(i + 2);
        }
    }
    
    // finally return
    return dp.at(0);
}

int main(int argc, const char** argv)
{
    // test case 1
    string input = "12";
    cout << "input: '" << input << "'" << endl;
    int output = numDecodings(input);
    cout << "output: " << output << endl;

    // test case 2
    cout << "====" << endl;
    input = "22226";
    cout << "input: '" << input << "'" << endl;
    output = numDecodings(input);
    cout << "output: " << output << endl;

    return 0;
}