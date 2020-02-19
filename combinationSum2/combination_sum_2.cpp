/**
 * LEETCODE 40. Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/
 *
 * Given a collection of candidate numbers (candidates) and a target
 * number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 *
 * Each number in candidates may only be used ONCE in the combination.
 *
 * Note:
 *
 * All numbers (including target) will be positive integers. The
 * solution set must not contain duplicate combinations.
 * 
 * Example 1:
 * Input: candidates = [10,1,2,7,6,1,5], target = 8
 * A solution set is:
 * [
 *      [1, 7], [1, 2, 5], [2, 6], [1, 1, 6]
 * ]
 * 
 * Example 2:
 * Input: candidates = [2,5,2,1,2], target = 5
 * A solution set is:
 * [
 *      [1,2,2], [5]
 * ]
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

void combinationSumBacktrack(
        const vector<int>& candidates,  // the candidates
        int target,                     // the remaining target
        int start,                      // where to start
        vector<int>& out,               // possible output to add to return
        set<vector<int>>& returnValue)  // what we return
{
    if ( target < 0 ) return;
    else if ( target == 0 ) returnValue.insert(out);
    else
    {
        // target is positive
        for ( unsigned int i = start; i < candidates.size(); i++ )
        {
            out.push_back(candidates.at(i));
            combinationSumBacktrack(
                candidates,
                target - candidates.at(i),
                i + 1,
                out,
                returnValue);
            out.pop_back();
        }
    }
}

// SOLUTION: Use Backtracking to find all unique set of candidates
//           that add up to the target.
//
// Time:    O(candidates_size^2)
// Space:   O(candidates_size)
vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
    // sanity checks
    unsigned int count = candidates.size();
    if ( count == 0 )
    {
        return vector<vector<int>>();
    }

    // at this point we have at least 1 candidate in candidates

    sort(candidates.begin(), candidates.end()); // for nicer output

    // locals
    set<vector<int>> returnValue;
    vector<int> out;

    // delegate
    combinationSumBacktrack(candidates, target, 0, out, returnValue);

    return vector<vector<int>>(returnValue.begin(), returnValue.end());
}

// MAIN
int main(int argc, char const *argv[])
{
    // test case 1
    std::vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    std::cout << "candidates = " << candidates << ", target = " << target << std::endl;
    vector<vector<int>> output = combinationSum2(candidates, target);
    std::cout << "output: " << output << std::endl;
    
    // test case 2
    // std::cout << "\n====\n" << std::endl;
    // candidates = {2, 3, 5};
    // target = 8;
    // std::cout << "candidates = " << candidates << ", target = " << target << std::endl;
    // output = combinationSum(candidates, target);
    // std::cout << "output: " << output << std::endl;

    return 0;
}