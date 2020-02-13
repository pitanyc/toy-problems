/**
 * LEETCODE 322. Coin Change
 *
 * https://leetcode.com/problems/coin-change/
 *
 * You are given coins of different denominations and a total amount of
 * money amount. Write a function to compute the fewest number of coins
 * that you need to make up that amount. If that amount of money cannot
 * be made up by any combination of the coins, return -1.
 *
 * Example 1:
 * Input: coins = [1, 2, 5], amount = 11
 * Output: 3
 * Explanation: 11 = 5 + 5 + 1
 * 
 * Example 2:
 * Input: coins = [2], amount = 3
 * Output: -1
 * 
 * Note: You may assume thatyou have an infinite number of each kind of coin.
 */

#include <iostream>
#include <limits>
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

// SOLUTION: Bottom up DP.
//
// Time: O(amount * sizeof(coins))
// Space: O(amount)
int coinChange(vector<int>& coins, int amount)
{
    // sanity check
    if ( amount <= 0 )
    {
        return -1;
    }

    // locals
    unsigned int count = coins.size();

    // build dp
    vector<int> dp(amount + 1, INT_MAX);
    for ( int i = 1; i <= amount; i++ )
    {
        for ( int j = 0; j < count; j++ )
        {
            int diff = i - coins.at(j);
            if ( diff == 0 )
            {
                dp.at(i) = 1;
            }
            else if ( diff > 0 && dp.at(diff) < INT_MAX )
            {
                // std::cout << "i: " << i << " | diff: " << diff << ", dp(diff): " << dp.at(diff) << std::endl;
                dp.at(i) = std::min(dp.at(i), dp.at(diff) + 1);
            }
        }
    }

    // debug
    // std::cout << "dp: " << dp << std::endl;

    return dp.back() == INT_MAX ? -1 : dp.back();
}

// MAIN
int main(int argc, char const *argv[])
{
    // test case 1
    std::vector<int> coins = {1, 2, 5};
    int amount = 11;
    std::cout << "coins = " << coins << ", amount = " << amount << std::endl;
    int output = coinChange(coins, amount);
    std::cout << "output: " << output << std::endl;

    // test case 2
    std::cout << "\n====\n" << std::endl;
    coins = {2};
    amount = 3;
    std::cout << "coins = " << coins << ", amount = " << amount << std::endl;
    output = coinChange(coins, amount);
    std::cout << "output: " << output << std::endl;

    return 0;
}
