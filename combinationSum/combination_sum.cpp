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

std::ostream& operator<<(std::ostream &os, const std::vector<int> arr)
{
    os << "[";
    for (std::vector<int>::const_iterator it = arr.begin();
         it != arr.end();
         it++)
    {
        os << *it;
        if (it + 1 != arr.end()) os << ", ";
    }
    os << "]";
    return os;
}

// SOLUTION:
vector<vector<int> > combinationSum(vector<int>& candidates, int target)
{
    // what we return
    set<vector<int> > s;

    return vector<vector<int> >(s.begin(), s.end());
}

// MAIN
int main(int argc, char const *argv[])
{
    // test case 1
    std::vector<int> candidates = {2,3,6,7};
    int target = 7;
    std::cout << "candidates = " << candidates << ", target = " << target << std::endl;
    vector<vector<int> > output = combinationSum(candidates, target);
    //std::cout << "output: " << output << std::endl;
    
    // test case 2
    // std::cout << "\n====\n" << std::endl;
    // input = {2, 7, 9, 3, 1};
    // std::cout << "input: " << input << std::endl;
    // output = rob(input);
    // std::cout << "output: " << output << std::endl;

    return 0;
}
