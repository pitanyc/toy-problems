/**
 * LEETCODE 560. Subarray Sum Equals K
 *
 * https://leetcode.com/problems/subarray-sum-equals-k/
 *
 * Given an array of integers and an integer k, you need to find the
 * total number of continuous subarrays whose sum equals to k.
 *
 * Example 1:
 * Input:nums = [1,1,1], k = 2
 * Output: 2
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

// SOLUTION: O(n) using sliding window:
//      * add elements on the right until sum is >= K
//      * if sum == K, increment count
//      * if sum > K, remove elements from the left until sum <= K
//      * return count
int subarraySum(vector<int>& nums, int k)
{
    // what we return
    int returnValue = 0;

    // sanity check
    unsigned int count = nums.size();
    if ( count < 2 )
    {
        // nums must have at least 2 elements
        return returnValue;
    }

    // at this point, we have at least 2 points in the input vector

    // locals
    int left = 0;
    int right = 1;
    int sum = nums[0] + nums[1];

    // consume input, build sliding window
    while ( left < count - 1 )
    {
        // std::cout << "left: " << left << ", right: " << right << ", sum: " << sum << std::endl;
        // add elements until sum is >= k
        while ( sum < k && right < count - 1 )
        {
            sum += nums[++right];
        }

        // check if we hit k
        if ( sum == k )
        {
            // bingo, increment count
            if ( left < right )     // this is just to make sure NOT to include single element = k
            {
                returnValue++;
            }
            sum -= nums[left++];
        }
        else
        {
            // remove elements from the left until sum <= K
            while ( sum > k && left < count - 1 )
            {
                sum -= nums[left++];
            }
        }
    }

    // finally return
    return returnValue;
}

// SOLUTION
int main(int argc, char const *argv[])
{
    // test case 1
    std::vector<int> input = {1, 1, 1};
    int k = 2;
    std::cout << "input = " << input << ", k = " << k << std::endl;
    int output = subarraySum(input, k);
    std::cout << "output: " << output << std::endl;
    
    // test case 2
    std::cout << "\n====\n" << std::endl;
    input = {1, 3, 1, 4, 2, 2};
    k = 4;
    std::cout << "input: " << input << std::endl;
    output = subarraySum(input, k);
    std::cout << "output: " << output << std::endl;

    return 0;
}
