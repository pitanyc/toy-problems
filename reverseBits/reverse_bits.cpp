/**
 * LEETCODE 190. Reverse Bits
 *
 * https://leetcode.com/problems/reverse-bits/
 *
 * Reverse bits of a given 32 bits unsigned integer.
 *
 * Example 1:
 * Input: 43261596
 * Output: 964176192
 *
 * Example 2:
 * Input: 4294967293 
 * Output: 3221225471
 */

#include <iostream>

// SOLUTION
uint32_t reverseBits(uint32_t n)
{
    // what we return
    uint32_t returnValue = 0;

    // create mask
    uint32_t mask = 1;
    uint32_t reverseMask = 1 << 31;

    // consume input, build output
    for ( unsigned int i = 0; i < 32; i++)
    {
        if ( n & mask )
        {
            returnValue = returnValue | reverseMask; 
        }
        mask = mask << 1;
        reverseMask = reverseMask >> 1;
    }

    // finally return
    return returnValue;
}

// MAIN
int main(int argc, char const *argv[])
{
    // test case 1
    uint32_t input = 43261596;
    std::cout << "input = " << input << std::endl;
    uint32_t output = reverseBits(input);
    std::cout << "output: " << output << std::endl;

    // test case 2
    std::cout << "\n====\n" << std::endl;
    input = 4294967293;
    std::cout << "input = " << input << std::endl;
    output = reverseBits(input);
    std::cout << "output: " << output << std::endl;

    return 0;
}
