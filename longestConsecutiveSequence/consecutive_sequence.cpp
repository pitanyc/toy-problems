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

// SOLUTION 1:
//
// Time:
// Space:
int longestConsecutive(vector<int>& nums)
{
    return 0;
}

int main(int argc, const char** argv)
{
    // test case 1
    vector<int> nums = {100,4,200,1,3,2};
    cout << "nums: " << nums << endl;
    int output = longestConsecutive(nums);
    cout << "output: " << output << endl;

    // test case 2
    // cout << "====" << endl;
    // input = {3, 2, 1, 0, 4};
    // cout << "input: " << input << endl;
    // output = moveZeros(input);
    // cout << "output: " << output << endl;

    return 0;
}