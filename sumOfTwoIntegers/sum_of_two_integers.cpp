/**
 * LEETCODE 371. Sum of Two Integers
 *
 * https://leetcode.com/problems/sum-of-two-integers/
 *
 * Calculate the sum of two integers a and b, but you are not allowed to
 * use the operator + and -.
 *
 * Example 1:
 * Input: a = 1, b = 2
 * Output: 3
 * 
 * Example 2:
 * Input: a = -2, b = 3
 * Output: 1
 */

#include <iostream>

// SOLUTION: 
int getSum(int a, int b)
{
    // base case
    if ( b == 0 )
    {
        return a;
    }

    int sum = a ^ b;            // XOR
    int carry = (a & b) << 1;   // AND

    return getSum(sum, carry);
}

// MAIN
int main(int argc, char const *argv[])
{
    // test case 1
    int a = 1;
    int b = 2;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    int sum = getSum(a, b);
    std::cout << "sum: " << sum << std::endl;

    // test case 2
    std::cout << "\n====\n" << std::endl;
    a = -2;
    b = 3;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    sum = getSum(a, b);
    std::cout << "sum: " << sum << std::endl;

    return 0;
}
