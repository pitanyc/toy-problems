/**
 * LEETCODE 12. Integer to Roman
 *
 * https://leetcode.com/problems/integer-to-roman/
 *
 * Roman numerals are represented by seven different symbols: I, V, X,
 * L, C, D and M.
 *
 * Roman numerals are usually written largest to smallest from left to
 * right. However, the numeral for four is not IIII. Instead, the number
 * four is written as IV. Because the one is before the five we subtract
 * it making four. The same principle applies to the number nine, which
 * is written as IX. There are six instances where subtraction is used:
 *
 * --> I can be placed before V (5) and X (10) to make 4 and 9.
 * --> X can be placed before L (50) and C (100) to make 40 and 90.
 * --> C can be placed before D (500) and M (1000) to make 400 and 900.
 * 
 * Given an integer, convert it to a roman numeral. 
 * Input is guaranteed to be within the range from 1 to 3999.
 *
 * Examples:
 * 
 * Input: 3
 * Output: "III"
 *
 * Input: 4
 * Output: "IV"
 *
 * Input: 9
 * Output: "IX"
 *
 * Input: 58
 * Output: "LVIII"
 * 
 * Input: 1994
 * Output: "MCMXCIV"
 */

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// STREAM OPERATOR ==> map of <int, string>
std::ostream& operator<<(std::ostream &os, const map<int, string>& m)
{
    os << endl;
    for ( map<int, string>::const_iterator it = m.begin();
          it != m.end();
          it++ )
    {
        os << "<" << it->first << ", \"" << it->second << "\">" << endl;
    }
    return os;
}

// STREAM OPERATOR ==> map of <int, string, std::greater<int>>
std::ostream& operator<<(std::ostream &os, const map<int, string, std::greater<int>>& m)
{
    os << endl;
    for ( map<int, string>::const_iterator it = m.begin();
          it != m.end();
          it++ )
    {
        os << "<" << it->first << ", \"" << it->second << "\">" << endl;
    }
    return os;
}

// SOLUTION: Create a static map with all the corner cases:
//           int --> roman numeral.
//
//           Then, consume down the input until it's 0.
//
// Time:     O(logn)
// Space:    O(1)
string integerToRoman(int num)
{
    // sanity checks
    if (num < 1 || num > 3999)
    {
        // shouldn't happen
        throw runtime_error("Input number out of range");
    }

    // at this point, num = [1..3999]

    // what we return
    string returnValue;

    // for immediate reverse (descending) sort by keys:
    // NOTE: make sure to update the operator<<() with the std::greater<int> as well!
    static const map<int, string, std::greater<int>> m = {
        {1000, "M"},
        {900,  "CM"},
        {500,  "D"},
        {400,  "CD"},
        {100,  "C"},
        {90,   "XC"},
        {50,   "L"},
        {40,   "XL"},
        {10,   "X"},
        {9,    "IX"},
        {5,    "V"},
        {4,    "IV"},
        {1,    "I"}
    };

    // use this for reverse iterator:
    // static const map<int, string> m = {
    //     {1000, "M"},
    //     {900,  "CM"},
    //     {500,  "D"},
    //     {400,  "CD"},
    //     {100,  "C"},
    //     {90,   "XC"},
    //     {50,   "L"},
    //     {40,   "XL"},
    //     {10,   "X"},
    //     {9,    "IX"},
    //     {5,    "V"},
    //     {4,    "IV"},
    //     {1,    "I"}
    // };

    // debug
    cout << "m: " << m << endl;

    // consume input
    for ( map<int, string>::const_iterator it = m.begin(); 
          it != m.end();
          /* nothing */ )
    {
        // cout << "num: " << num << ", it->first: " << it->first << endl;
        if ( num - it->first >= 0 )
        {
            returnValue += it->second;
            num -= it->first;
        }
        else
        {
            it++;
        }
    }

    // finally return
    return returnValue;
}

// MAIN
int main(int argc, char* argv[])
{
    // test case 1
    int input = 3;
    std::cout << "input = " << input << std::endl;
    string output = integerToRoman(input);
    std::cout << "output = \"" << output << "\"" << std::endl;

    // test case 2
    std::cout << "\n====\n" << std::endl;
    input = 49;
    std::cout << "input = " << input << std::endl;
    output = integerToRoman(input);
    std::cout << "output = \"" << output << "\"" << std::endl;

    // test case 3
    std::cout << "\n====\n" << std::endl;
    input = 61;
    std::cout << "input = " << input << std::endl;
    output = integerToRoman(input);
    std::cout << "output = \"" << output << "\"" << std::endl;

    return 0;
}
