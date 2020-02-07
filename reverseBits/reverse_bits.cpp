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
#include <bitset>

// SOLUTION: O(logn) using block swapping
uint32_t reverseBits(uint32_t n)
{
    // locals
    unsigned int size = 8 * sizeof(n);  // sizeof() gives you size in bytes
    uint32_t mask = ~0;                 // all 1-s
    std::cout << "mask: " << std::bitset<32>(mask) << std::endl;

    // consume input
    while ((size >>= 1) > 0)
    {
        mask ^= (mask << size);
        std::cout << "size: " << size << ", mask: " << std::bitset<32>(mask) << std::endl;
        n = ((n >> size) & mask) | ((n << size) & ~mask);
    }    
    // finally return
    return n;
}

// SOLUTION: O(n) using masks
uint32_t reverseBits2(uint32_t n)
{
    // what we return
    uint32_t returnValue = 0;

    // locals
    unsigned int size = 8 * sizeof(n);  // sizeof() gives you size in bytes

    // create masks
    uint32_t mask = 1;
    uint32_t reverseMask = 1 << (size - 1);

    // consume input, build output
    for ( unsigned int i = 0; i < size; i++)
    {
        if ( n & mask )
        {
            returnValue |= reverseMask; 
        }
        mask <<= 1;
        reverseMask >>= 1;
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
