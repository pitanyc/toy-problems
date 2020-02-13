/**
 * LEETCODE 198. House Robber
 *
 * https://leetcode.com/problems/house-robber/
 *
 * You are a professional robber planning to rob houses along a street.
 * Each house has a certain amount of money stashed, the only constraint
 * stopping you from robbing each of them is that adjacent houses have
 * security system connected and it will automatically contact the
 * police if two adjacent houses were broken into on the same night.
 *
 * Given a list of non-negative integers representing the amount of
 * money of each house, determine the maximum amount of money you can
 * rob tonight without alerting the police.
 *
 * Example 1:
 *
 * Input: [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
 *              Total amount you can rob = 1 + 3 = 4.
 * 
 * Example 2:
 * Input: [2,7,9,3,1]
 * Output: 12
 * Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and 
 *              rob house 5 (money = 1). Total amount you can rob = 2 + 9 + 1 = 12.
 */

#include <iostream>
#include <vector>

using namespace std;

std::ostream& operator<<(std::ostream &os, const std::vector<int> arr)
{
    for (std::vector<int>::const_iterator it = arr.begin();
         it != arr.end();
         it++)
    {
        os << *it << " ";
    }
    return os;
}

// SOLUTION: O(n) time, O(n) space, using a vector for dynamic programming.
//
//           At each step, compare if adding the current house value to
//           to the total value 2 houses ago is LARGER THAN the total value
//           robbed until the previous house (1 house ago).
int rob(vector<int>& nums)
{
    // sanity checks
    unsigned int count = nums.size();
    if ( count == 0 )
    {
        return 0;
    }
    else if ( count == 1 )
    {
        return nums.at(0);
    }
    
    // at this point, we have at least 2 points in the input vector

    // dynamic programming, bottom up
    vector<int> dp = {nums.at(0), max(nums.at(0), nums.at(1))};
    for ( unsigned int i = 2; i < count; i++ )
    {
        dp.push_back(max(nums.at(i) + dp.at(i - 2), dp.at(i - 1)));
    }

    // finally return
    return dp.back();
}

// MAIN
int main(int argc, char const *argv[])
{
    // test case 1
    std::vector<int> input = {1, 2, 3, 1};
    std::cout << "input = " << input << std::endl;
    int output = rob(input);
    std::cout << "output: " << output << std::endl;
    
    // test case 2
    std::cout << "\n====\n" << std::endl;
    input = {2, 7, 9, 3, 1};
    std::cout << "input: " << input << std::endl;
    output = rob(input);
    std::cout << "output: " << output << std::endl;

    return 0;
}
