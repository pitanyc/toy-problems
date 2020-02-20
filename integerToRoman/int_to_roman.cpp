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
#include <string>
#include <vector>

using namespace std;

// SOLUTION: 
//
// Time:  
// Space: 
string intToRoman(int num)
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

    return returnValue;
}

// MAIN
int main(int argc, char* argv[])
{
    // test case 1
    int input = 3;
    std::cout << "input = " << input << std::endl;
    string output = intToRoman(input);
    std::cout << "output = \"" << output << "\"" << std::endl;

    // test case 2
    // std::cout << "\n====\n" << std::endl;
    // x = 3;
    // n = 2;
    // std::cout << "x = " << x << ", n: " << n << std::endl;
    // result = myPow(x, n);
    // std::cout << "result = " << result << std::endl;

    return 0;
}
