/**
 * LEETCODE 128. Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/
 *
 * Given an unsorted array of integers nums, return the length of the
 * longest consecutive elements sequence.
 * 
 * You must write an algorithm that runs in O(n) time.
 * 
 * Example 1:
 *  Input: nums = [100,4,200,1,3,2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 *              Therefore its length is 4.
 * 
 * Example 2:
 * Input: nums = [0,3,7,2,5,8,4,6,0,1]
 * Output: 9
 */

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

// STREAM OPERATOR ==> vector of int
ostream& operator<<(ostream& os, const vector<int>& arr)
{
    os << "[";
    for ( vector<int>::const_iterator it = arr.begin(); it != arr.end(); it++ )
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

// STREAM OPERATOR ==> vector of vector of int
ostream& operator<<(ostream &os, const vector<vector<int>>& arr)
{
    os << endl;
    for ( vector<vector<int>>::const_iterator it = arr.begin();
          it != arr.end();
          it++ )
    {
        os << "  " << *it;
        if (it + 1 != arr.end()) os << endl;
    }
    return os;
}

// SOLUTION 1: We have to write an algorithm that runs in O(n) time.
//             Thus, we cannot sort it (which is O(nlogn)) and simply
//             count consecutive elements.
//
//             We need to use an additional data structure to help
//             counting consecutive elements.
//
//             Here is the algorithm:
//             1. Run thru nums, find the absolute min and max in it: O(n).
//             2. Create a dp vector with size (max - min + 1).
//             3. Run thru nums again, and mark in the dp vector the occurence
//                of each element: O(n).
//             4. For mapping an element to an index in dp:
//                index = nums[i] - min
//             5. Run thru dp and find the longest consecutive sequence.
//
// Time:  O(n)
// Space: O(n)
int longestConsecutive(vector<int>& nums)
{
    // what we return
    int longest = 0;

    // locals
    int count = nums.size();
    int minValue = INT32_MAX;
    int maxValue = INT32_MIN;

    // find absolute min & max
    for (int i = 0; i < count; i++)
    {
        minValue = min(minValue, nums.at(i));
        maxValue = max(maxValue, nums.at(i));
    }
    
    // create dp
    vector<bool> dp(maxValue - minValue + 1, false);

    // mark occurrence of each element in dp
    for (int i = 0; i < count; i++)
    {
        int index = nums.at(i) - minValue;
        dp.at(index) = true;
    }

    // consume dp
    int dpCount = dp.size();
    int currMax = 0;
    for (int i = 0; i < dpCount; i++)
    {
        if (!dp.at(i))
        {
            // no element for this value, reset currMax
            currMax = 0;
        }
        else
        {
            // element for this value, increment currMax
            currMax++;
            longest = max(longest, currMax);
        }
    }
    
    return longest;
}

// SOLUTION 2: Here is the algorithm:
//             1. Convert the input nums into a set.
//             2. Iterate thru nums, and check for each element
//                whether it's the start of a consecutive sequence: if the set
//                doesn't an element 1 smaller than current element, then
//                the current element is the start of a sequence.
//             3. If we are at a start of a sequence:
//                * run a for loop until we have elements in the set, count
//                  length.
//
// Time:  O(n)
// Space: O(n)
int longestConsecutive2(vector<int>& nums)
{
    // what we return
    int longest = 0;

    // throw nums into a set
    set<int> numsSet(nums.begin(), nums.end());

    // consume nums
    int count = nums.size();
    for (int i = 0; i < count; i++)
    {
        int num = nums.at(i);
        if (!numsSet.count(num - 1))
        {
            // num is the start of a sequence
            int currLength = 1;
            while (numsSet.count(num + currLength))
            {
                currLength++;
            }
            longest = max(longest, currLength);
        }
    }
    
    // finally return
    return longest;
}

int main(int argc, const char** argv)
{
    // test case 1
    vector<int> nums = {100,4,200,1,3,2};
    cout << "nums: " << nums << endl;
    int output = longestConsecutive2(nums);
    cout << "output: " << output << endl;

    // test case 2
    cout << "====" << endl;
    nums = {0,3,7,2,5,8,4,6,0,1};
    cout << "nums: " << nums << endl;
    output = longestConsecutive2(nums);
    cout << "output: " << output << endl;

    return 0;
}