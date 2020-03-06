/**
 * LEETCODE 461. Hamming Distance
 *
 * https://leetcode.com/problems/hamming-distance/
 *
 * The Hamming distance between two integers is the number of positions
 * at which the corresponding bits are different.
 *
 * Given two integers x and y, calculate the Hamming distance.
 *
 * Note: 0 ≤ x, y < 231.
 *
 * Example:
 *
 * Input: x = 1, y = 4
 * Output: 2
 * Explanation: 1   (0 0 0 1)
 *              4   (0 1 0 0)
 *                     ↑   ↑
 *
 * The arrows point to positions where the corresponding bits are different.
 */

#include <iostream>
#include <bitset>

// SOLUTION: Count the number of 1 bits in the XOR of the 2 numbers.
//
// Time: O(1)
// Space: O(1)
int hammingDistance(int x, int y)
{
    std::bitset<32> bits(x ^ y);
    return bits.count();
}

// MAIN
int main(int argc, char const *argv[])
{
    // test case 1
    int x = 1;
    int y = 4;
    int output = hammingDistance(x, y);
    std::cout << "x: " << x << ", y: " << y << "\noutput: " << output << std::endl;

    // test case 2
    std::cout << "\n====\n" << std::endl;
    x = 7;
    y = 8;
    output = hammingDistance(x, y);
    std::cout << "x: " << x << ", y: " << y << "\noutput: " << output << std::endl;

    return 0;
}
