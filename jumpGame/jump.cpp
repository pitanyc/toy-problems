/**
 * LEETCODE 55. Jump Game
 *
 * https://leetcode.com/problems/jump-game/
 *
 * You are given an integer array nums. You are initially positioned at \
 * the array's first index, and each element in the
 * array represents your maximum jump length at that position.
 *
 * Return true if you can reach the last index, or false otherwise.
 *
 * Example 1:
 *
 * Input: nums = [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
 *
 * Example 2:
 *
 * Input: nums = [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what.
 * Its maximum jump length is 0, which makes it impossible to reach the last
 * index.
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

std::ostream& operator<<(std::ostream& os, const std::vector<int> arr)
{
    os << "[";
    for ( std::vector<int>::const_iterator it = arr.begin(); it != arr.end();
          it++ )
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

// SOLUTION 1: Starting at index 0, create a can-reach vector for each index:
//              * Take the number at index 0.
//              * From 1 to that number, mark each index as reachable in this
//                secondary can-reach vector.
//              * Continue with index 1, index 2, but check if those we can
//                reach from a previous step, otherwise discard.
//              * Stop either when we can reach the last index, or all indices
//                have been consumed.
//
// Time:  O(kn): k = average value of nums[i], n = nums count
// Space: O(n):  keeping values of reachable indices in this secondary vector
class Solution
{
  public:
    bool canJump(vector<int>& nums)
    {
        // sanity checks
        unsigned int count = nums.size();
        if ( count == 0 || nums.at(0) == 0 )
        {
            return false;
        }

        // what we return
        bool returnValue = false;

        // locals
        vector<int> reachable(count, 0);
        reachable[0] = 1;

        // consume input
        for ( size_t i = 0; i < count; i++ )
        {
            cout << "reachable: " << reachable << endl;
            // check if this index is reachable
            if ( reachable.at(i) )
            {
                for ( size_t j = 1; j <= nums.at(i); j++ )
                {
                    // check if we reached the end
                    unsigned int index = min<int>(i + j, count - 1);
                    if ( index == count - 1 )
                    {
                        returnValue = true;
                        break;
                    }

                    // update reachable
                    reachable.at(index) = 1;
                }
            }
        }

        // finally return
        return returnValue;
    }
};

// SOLUTION 2: Use greedy approach:
//              * Go from the back, see if you you can reach target index from
//              an earlier index.
//              * If so, update the target index to this earlier index.
//              * Repeat process until you reach index 0 (or not).
//
// Time:  O(n)
// Space: O(1)
bool canJumpGreedy(const vector<int>& nums)
{
    // sanity checks
    unsigned int count = nums.size();
    if ( count == 0 )
    {
        return false;
    }
    else if ( count == 1 )
    {
        return (nums.at(0) > 0);
    }

    // at this point, count is at least 2

    // set goal index
    unsigned int goal = count - 1;

    // keep moving goal back towards the beginning until we reach index 0
    for ( int i = count - 2; i >= 0; i-- )
    {
        // check if we can reach the goal from this index
        if ( (i + nums.at(i)) >= goal )
        {
            goal = i;
        }
        // cout << "i: " << i << ", goal: " << goal << endl;
    }

    // finally return ==> check if we reached all the way to index 0
    return (goal == 0);
}

int main(int argc, const char** argv)
{
    // test case 1
    vector<int> input = {2, 3, 1, 1, 4};
    cout << "input: " << input << endl;
    Solution sol;
    bool output = canJumpGreedy(input);
    cout << "output: " << output << endl;

    // test case 2
    cout << "====" << endl;
    input = {3, 2, 1, 0, 4};
    cout << "input: " << input << endl;
    output = canJumpGreedy(input);
    cout << "output: " << output << endl;

    return 0;
}