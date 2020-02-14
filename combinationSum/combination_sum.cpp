/**
 * LEETCODE 39. Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/
 *
 * Given a set of candidate numbers (candidates) (without duplicates)
 * and a target number (target), find all unique combinations in
 * candidates where the candidate numbers sums to target.
 *
 * The same repeated number may be chosen from candidates unlimited
 * number of times.
 *
 * Note:
 *
 * All numbers (including target) will be positive integers. The
 * solution set must not contain duplicate combinations.
 * 
 * Example 1:
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 *   [
 *      [7],
 *      [2,2,3]
 *   ]
 * 
 * Example 2:
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 *   [
 *      [2,2,2,2],
 *      [2,3,3],
 *      [3,5]
 *   ]
 */

#include <iostream>
#include <set>
#include <vector>

using namespace std;

// STREAM OPERATOR ==> vector of int
std::ostream& operator<<(std::ostream &os, const vector<int>& arr)
{
    os << "[";
    for ( vector<int>::const_iterator it = arr.begin();
          it != arr.end();
          it++ )
    {
        os << *it;
        if (it + 1 != arr.end()) os << ", ";
    }
    os << "]";
    return os;
}

// STREAM OPERATOR ==> vector of vector of int
std::ostream& operator<<(std::ostream &os, const vector<vector<int>>& arr)
{
    os << std::endl << "  [" << std::endl;
    for ( vector<vector<int>>::const_iterator it = arr.begin();
          it != arr.end();
          it++ )
    {
        os << "    " << *it;
        if (it + 1 != arr.end()) os << ", ";
    }
    os << std::endl << "  ]";
    return os;
}

// STREAM OPERATOR ==> vector of vector of vector of int
std::ostream& operator<<(
        std::ostream &os, 
        const vector<vector<vector<int>>> arr)
{
    os << std::endl << "{";
    for ( vector<vector<vector<int>>>::const_iterator it = arr.begin();
          it != arr.end();
          it++ )
    {
        os << "  " << *it;
        if (it + 1 != arr.end()) os << ", ";
    }
    os << std::endl << "}";
    return os;
}

// SOLUTION: This is similar to the coin change problem.
//           In there, we are asked to come up with the least number of
//           coins to sum up to a particular target.
//
//           Here, we are asked to come up with ALL unique combinations of
//           the coins that sum to the given target.
//
//           Thus, we'll follow a similar approach, but instead of minimizing
//           the DP vector, we'll keep a set of combinations in the DP table
//           for each of the target amounts in [1..target].
//
// Time:    O(target * candidates_size^2)
// Space:   O(target * candidates_size^2)
vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    // sanity checks
    unsigned int count = candidates.size();
    if ( count == 0 || target < 1 )
    {
        return vector<vector<int>>();
    }

    // at this point we have at least 1 candidate in candidates

    // consume input
    vector<vector<vector<int>>> dp(target + 1);
    for ( unsigned int i = 1; i < target + 1; i++ )
    {
        // i = the next target
        for ( unsigned int j = 0; j < count; j++ )
        {
            int diff = i - candidates.at(j);
            if ( diff == 0 )
            {
                vector<int> v = {candidates.at(j)};
                dp.at(i).push_back(v);
            }
            else if ( diff > 0 )
            {
                // check if adding this candidate to a previous record works
                vector<vector<int>> prev = dp.at(diff);
                // std::cout << "i: " << i << ", candidates.at(j): " << candidates.at(j) << " | diff: " << diff << ", prev: " << prev << std::endl;
                for ( unsigned int k = 0; k < prev.size(); k++ )
                {
                    // add this candidate to all previous records
                    vector<int> a = prev.at(k);
                    a.push_back(candidates.at(j));
                    std::sort(a.begin(), a.end());
                    dp.at(i).push_back(a);
                }
            }
        }
    }

    // debug
    // std::cout << "dp: " << dp << std::endl;

    // unique last element of dp
    set<vector<int>> returnSet(dp.back().begin(), dp.back().end());
    return vector<vector<int>>(returnSet.begin(), returnSet.end());
}

// MAIN
int main(int argc, char const *argv[])
{
    // test case 1
    std::vector<int> candidates = {2,3,6,7};
    int target = 7;
    std::cout << "candidates = " << candidates << ", target = " << target << std::endl;
    vector<vector<int>> output = combinationSum(candidates, target);
    std::cout << "output: " << output << std::endl;
    
    // test case 2
    std::cout << "\n====\n" << std::endl;
    candidates = {2, 3, 5};
    target = 8;
    std::cout << "candidates = " << candidates << ", target = " << target << std::endl;
    output = combinationSum(candidates, target);
    std::cout << "output: " << output << std::endl;

    // test case 3
    std::cout << "\n====\n" << std::endl;
    candidates = {2, 3, 5};
    target = 9;
    std::cout << "candidates = " << candidates << ", target = " << target << std::endl;
    output = combinationSum(candidates, target);
    std::cout << "output: " << output << std::endl;

    return 0;
}