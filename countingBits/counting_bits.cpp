/**
 * LEETCODE 338. Counting Bits
 *
 * https://leetcode.com/problems/counting-bits/
 *
 * Given a non negative integer number num. For every numbers i in the
 * range 0 ≤ i ≤ num calculate the number of 1's in their binary
 * representation and return them as an array.
 * 
 * It is very easy to come up with a solution with run time O(n*sizeof(integer)).
 * But can you do it in linear time O(n), possibly in a single-pass?
 * Space complexity should be O(n).
 *
 * Example 1:
 * Input: 2
 * Output: [0,1,1]
 * 
 * Example 2:
 * Input: 5
 * Output: [0,1,1,2,1,2]
 */

#include <iostream>
#include <vector>

using namespace std;

std::ostream &operator<<(std::ostream &os, const std::vector<int> arr)
{
    os << "[";
    for (std::vector<int>::const_iterator it = arr.begin();
         it != arr.end();
         it++)
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

// SOLUTION: O(n) 1 iteration
vector<int> countBits(int num)
{
    // what we return
    vector<int> returnValue(num + 1, 0);

    // iterate till num
    for ( int i = 1; i <= num; i++ )
    {
        returnValue.at(i) = returnValue.at(i & (i - 1)) + 1;
    }

    // finally return
    return returnValue;
}

// SOLUTION: O(n) using bitset
vector<int> countBits2(int num)
{
    // what we return
    vector<int> returnValue(num + 1, 0);

    // iterate till num
    for ( int i = 0; i <= num; i++ )
    {
        returnValue.at(i) = bitset<32>(i).count();
    }

    // finally return
    return returnValue;
}

// SOLUTION: O(n) using odd/even at half point
vector<int> countBits3(int num)
{
    // what we return
    vector<int> returnValue(num + 1, 0);

    // iterate till num
    for ( int i = 1; i <= num; i++ )
    {
        int half = i / 2;
        if ( i % 2 == 0 ) returnValue.at(i) = returnValue.at(half);
        else returnValue.at(i) = returnValue.at(half) + 1;
    }

    // finally return
    return returnValue;
}

// MAIN
int main(int argc, char const *argv[])
{
    // test case 1
    int input = 2;
    std::cout << "input = " << input << std::endl;
    vector<int> output = countBits(input);
    std::cout << "output: " << output << std::endl;

    // test case 2
    std::cout << "\n====\n" << std::endl;
    input = 9;
    std::cout << "input = " << input << std::endl;
    output = countBits2(input);
    std::cout << "output: " << output << std::endl;

    // test case 3
    std::cout << "\n====\n" << std::endl;
    input = 15;
    std::cout << "input = " << input << std::endl;
    output = countBits3(input);
    std::cout << "output: " << output << std::endl;

    return 0;
}
