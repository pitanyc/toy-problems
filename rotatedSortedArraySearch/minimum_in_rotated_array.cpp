/**
 * LEETCODE 153. Find Minimum in Rotated Sorted Array
 * 
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
 *
 * Suppose an array sorted in ascending order is rotated at some pivot
 * unknown to you beforehand.  Find the minimum element.
 * 
 * You may assume no duplicate exists in the array.
 *
 * Example:
 * Input: [3,4,5,1,2] 
 * Output: 1
 */

#include <iostream>
#include <map>
#include <vector>

using namespace std;

std::ostream &operator<<(std::ostream &os, const std::vector<int> arr)
{
    for (std::vector<int>::const_iterator it = arr.begin();
         it != arr.end();
         it++)
    {
        os << *it << " ";
    }
    return os;
}

// Binary search in O(logn) time.
int findRotationPoint(const vector<int>& nums, int start, int end, int middle)
{
    // std::cout << "start: " << start << ", middle: " << middle << ", end: " << end << std::endl;
    
    // base condition
    if (nums.at(middle-1) > nums.at(middle) &&
        nums.at(middle) < nums.at(middle+1))
    {
        // found rotation point
        return nums.at(middle);
    }
    else
    {
        // recursive branch
        if (nums.at(start) < nums.at(middle))
        {
            // middle is greater than start
            return findRotationPoint(nums, middle, end, middle + (end - middle) / 2);
        }
        else
        {
            // middle is less than start
            return findRotationPoint(nums, start, middle, (middle - start) / 2);
        }
    }
}

// SOLUTION: Binary search
int findMin(vector<int>& nums)
{
    // what we return
    int returnValue = -1;

    // locals
    unsigned int count = nums.size();
    if (count == 0)
    {
        return returnValue;
    }

    // delegate
    returnValue = findRotationPoint(nums, 0, count - 1, count / 2);

    // finally return
    return returnValue;
}

int main(int argc, char const *argv[])
{
    // test case 1
    std::vector<int> input = {3,4,5,1,2};
    std::cout << "input: " << input << std::endl;
    int output = findMin(input);
    std::cout << "output: " << output << std::endl;

    // test case 2
    std::cout << "====" << std::endl;
    input = {4,5,6,7,0,1,2};
    std::cout << "input: " << input << std::endl;
    output = findMin(input);
    std::cout << "output: " << output << std::endl;

    return 0;
}