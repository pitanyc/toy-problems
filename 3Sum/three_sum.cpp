/**
 * LEETCODE 15. 3Sum
 * 
 * https://leetcode.com/problems/3sum/
 * 
 * Given an array S of n integers, are there elements a, b, c in S such
 * that a + b + c = 0? Find all unique triplets in the array which gives
 * the sum of zero.
 * 
 * Example: given array = [-1, 0, 1, 2, -1, -4]
 *
 * A solution set is:
 * [
 *   [-1, 0, 1],
 *   [-1, -1, 2]
 * ]
 */

#include <algorithm> // std::sort
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

std::ostream& operator<<(std::ostream& os, const std::vector<int>& arr)
{
    for (std::vector<int>::const_iterator it = arr.begin(); it != arr.end();
         it++)
    {
        os << *it << " ";
    }
    return os;
}

std::ostream& operator<<(std::ostream& os,
                         const std::vector<std::vector<int>>& arr)
{
    os << "[\n";
    for ( std::vector<std::vector<int>>::const_iterator it = arr.begin();
          it != arr.end();
          it++ )
    {
        os << "[";
        os << *it << " ";
        os << "]" << std::endl;
    }
    os << "]" << std::endl;
    return os;
}

// O(n) solution in 2 runs using map
vector<int> twoSum(const vector<int> &nums, int target)
{
    // what we return
    vector<int> returnValue;

    // locals
    int count = nums.size();

    // create helper map of (target - num) -> index
    map<int, int> m;
    for ( unsigned int i = 0; i < count; i++ )
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

// SOLUTION: Double hash-map, reuse twoSum() solution.
// Time: O(n^2)
// Space: O(n)
vector<vector<int>> threeSum(const vector<int>& nums)
{
    // what we return
    set<vector<int>> returnValue;

    // locals
    unsigned int count = nums.size();

    // consume input, create map
    std::map<int, int> target;  // value --> index
    for ( unsigned int i = 0; i < count; i++ )
    {
        int num = nums.at(i);
        target[-num] = i;
    }

    for ( std::map<int, int>::const_iterator it = target.begin();
          it != target.end();
          it++ )
    {
        // helpers
        int value = it->first;
        int index = it->second;

        // look for value using twoSum
        vector<int> pairIndex = twoSum(nums, value);
        //std::cout << "value: " << value << ", index: " << index << ", pairIndex: " << pairIndex << std::endl;
        if ( pairIndex.size() > 1 )
        {
            // success
            vector<int> result = {
                nums.at(index),
                nums.at(pairIndex[0]),
                nums.at(pairIndex[1])};
            std::sort(result.begin(), result.end());
            //std::cout << "result: " << result << std::endl;
            returnValue.insert(result);
        }
    }

    // finally return
    return vector<vector<int>>(returnValue.begin(), returnValue.end());
}

// MAIN
int main(int argc, char const* argv[])
{
    // test case 1
    std::vector<int> input = {-1, 0, 1, 2, -1, -4};
    std::cout << "input: " << input << std::endl;
    vector<vector<int>> output = threeSum(input);
    std::cout << "output: " << output << std::endl;

    // test case 2
    std::cout << "====\n" << std::endl;
    input = {-3, 0, 1, 2, -4, 2, -1};
    std::cout << "input: " << input << std::endl;
    output = threeSum(input);
    std::cout << "output: " << output << std::endl;

    return 0;
}