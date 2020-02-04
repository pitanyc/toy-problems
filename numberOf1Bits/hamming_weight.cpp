/**
 * LEETCODE 191. Number of 1 Bits
 *
 * https://leetcode.com/problems/number-of-1-bits/
 *
 * Write a function that takes an unsigned integer and return the number
 * of '1' bits it has (also known as the Hamming weight).
 *
 * Example 1:
 * Input: 11
 * Output: 3
 * 
 * Example 2:
 * Input: 128
 * Output: 1
 */

#include <iostream>

// SOLUTION: 
int hammingWeight(uint32_t n)
{
    // what we return
    int count = 0;

    // locals
    uint32_t mask = 1;

    // count number of 1 bits
    for ( unsigned int i = 0; i < 32; i++)
    {
        uint32_t sum = n & mask;
        if ( sum > 0 )
        {
            count++;
        }
        mask = mask << 1;
    }

    // finally return
    return count;
}

// MAIN
int main(int argc, char const *argv[])
{
    // test case 1
    uint32_t input = 11;
    std::cout << "input = " << input << std::endl;
    int output = hammingWeight(input);
    std::cout << "output: " << output << std::endl;

    // test case 2
    std::cout << "\n====\n" << std::endl;
    input = 128;
    std::cout << "input = " << input << std::endl;
    output = hammingWeight(input);
    std::cout << "output: " << output << std::endl;

    return 0;
}
