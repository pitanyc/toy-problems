/**
 * LEETCODE 50. Pow(x, n)
 *
 * https://leetcode.com/problems/powx-n/
 *
 * Compute the integer power of an integer.
 * Implement pow(x, n), which calculates int x raised to the power int y: x^y.
 *
 * Example 1:
 *
 * Input: 2.00000, 10 
 * Output: 1024.00000
 * 
 * Example 2:
 *
 * Input: 2.00000, -2 
 * Output: 0.25000 
 * Explanation: 2^(-2) = 1/(2^2) = 1/4 = 0.25
 */

#include <iostream>
#include <vector>

using namespace std;

// SOLUTION 1: Cover the corner cases.
//             After that, recursive solution by halving n each time.
//             This gives a log(n) runtime.
//
// Time:  O(log(n))
// Space: O(1)
double myPow(int x, int n)
{
    if (x == 0) return 0;
    else if (x == 1 || n == 0) return 1;
    else if (n < 0) return 1 / myPow(x, -n);
    else if (n == 1) return x;
    
    // at this point, n > 2
    double r = myPow(x, n/2);
    return (n % 2 ? r * r * x : r * r);
}

// SOLUTION 1: Cover the corner cases.
//             Then, iterate from 0 to n and multiply result with x again.
//
// Time:  O(N)
// Space: O(1)
double myPow2(int x, int n)
{
    if (x == 0) return 0;
    else if (x == 1 || n == 0) return 1;
    else if (n < 0) return 1 / myPow2(x, -n);
    else if (n == 1) return x;
    
    // at this point, n > 1
    double result = x;
    for (int i = 1; i < n; i++)
    {
        result *= x;
    }
    
    return result;
}

// MAIN
int main(int argc, char* argv[])
{
    // test case 1
    int x = 2;
    int n = 10;
    std::cout << "x = " << x << ", n: " << n << std::endl;
    double result = myPow2(x, n);
    std::cout << "result = " << result << std::endl;

    // test case 2
    std::cout << "\n====\n" << std::endl;
    x = 3;
    n = 2;
    std::cout << "x = " << x << ", n: " << n << std::endl;
    result = myPow2(x, n);
    std::cout << "result = " << result << std::endl;

    return 0;
}
