/**
 * LEETCODE 268. Missing Number
 *
 * https://leetcode.com/problems/missing-number/
 *
 * Given an array containing n distinct numbers taken from 0...n,
 * find the one that is missing from the array.
 *
 * Example 1:
 * Input: [3, 0, 1]
 * Output: 2
 * 
 * Example 2:
 * Input: [9, 6, 4, 2, 3, 5, 7, 0, 1]
 * Output: 8
 */

#include <iostream>
#include <set>
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

// SOLUTION: O(n) using a Set
int missingNumber(const vector<int>& nums)
{
    // what we return
    int returnValue = -1;

    // locals
    int count = nums.size();

    // consume input, populate set
    set<int> s;
    for ( int i = 0; i < count; i++ )
    {
        s.insert(nums.at(i));
    }

    // iterate 0..n, check if in map
    for ( int i = 0; i <= count; i++ )
    {
        if ( s.find(i) == s.end() )
        {
            // found missing number
            returnValue = i;
            break;
        }
    }

    // finally return
    return returnValue;
}

// SOLUTION: O(n) without extra space, using sum formula 1..n
int missingNumber2(const vector<int>& nums)
{
    // what we return
    int returnValue = -1;

    // locals
    int count = nums.size();
    int sum = (count * (count + 1)) / 2;    // sum if all elements were present

    // iterate 0..n, calculate sum
    int actualSum = 0;
    for ( int i = 0; i < count; i++ )
    {
        actualSum += nums.at(i);
    }

    // missing value is simply: sum - actualSum
    returnValue = sum - actualSum;

    // finally return
    return returnValue;
}

// SOLUTION: O(n) without extra space, using 2 for loops
int missingNumber3(const vector<int>& nums)
{
    // what we return
    int returnValue = 0;

    // locals
    int count = nums.size();

    // iterate 0..n, calculate sum
    for ( int i = 0; i < count; i++ )
    {
        returnValue += nums.at(i);
    }

    // iterate 0..n, xor values from actualSum
    for ( int i = 0; i <= count; i++ )
    {
        returnValue -= i;
    }

    // finally return
    return -returnValue;
}

// MAIN
int main(int argc, char const *argv[])
{
    // test case 1
    vector<int> input = {3, 0, 1};
    std::cout << "input = " << input << std::endl;
    int output = missingNumber(input);
    std::cout << "output: " << output << std::endl;

    // test case 2
    std::cout << "\n====\n" << std::endl;
    input = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    std::cout << "input = " << input << std::endl;
    output = missingNumber2(input);
    std::cout << "output: " << output << std::endl;

    // test case 3
    std::cout << "\n====\n" << std::endl;
    input = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    std::cout << "input = " << input << std::endl;
    output = missingNumber3(input);
    std::cout << "output: " << output << std::endl;

    return 0;
}
