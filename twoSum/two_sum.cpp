/**
 * LEETCODE 1: Two Sum
 * 
 * https://leetcode.com/problems/two-sum/
 *
 * Given an array of integers, return indices of the two numbers such
 * that they add up to a specific target.
 *
 * You may assume that each input would have exactly one solution, and
 * you may not use the same element twice.
 *
 * Example:
 *
 * Given nums = [2, 7, 11, 15], target = 9,
 *
 * Because nums[0] + nums[1] = 2 + 7 = 9, return [0, 1].
 */

#include <iostream>
#include <map>
#include <vector>

using namespace std;

// O(n) solution in 2 runs using map
vector<int> twoSum(vector<int> &nums, int target)
{

    // what we return
    vector<int> returnValue;

    // locals
    int count = nums.size();

    // create helper map of (target - num) -> index
    map<int, int> m;
    for (unsigned int i = 0; i < count; i++)
    {
        m[target - nums.at(i)] = i;
    }

    // now look for num in map
    for (unsigned int i = 0; i < count; i++)
    {
        if (m.find(nums.at(i)) != m.end() &&
            m[nums.at(i)] != i)
        {
            // found it
            returnValue.push_back(i);
            returnValue.push_back(m[nums.at(i)]);
            break;
        }
    }

    // finally return
    return returnValue;
}

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

int main(int argc, char const *argv[])
{
    // test case 1
    std::vector<int> input = {2, 7, 11, 15};
    int target = 9;
    std::cout << "input: " << input << std::endl;
    vector<int> output = twoSum(input, target);
    std::cout << "output: " << output << std::endl;

    return 0;
}