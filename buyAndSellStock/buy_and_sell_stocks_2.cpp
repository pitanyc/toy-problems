/**
 * LEETCODE 122. Best Time to Buy and Sell Stock II
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
 *
 * Say you have an array for which the ith element is the price of a
 * given stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete as
 * many transactions as you like (i.e., buy one and sell one share of
 * the stock multiple times).
 *
 * Note: You may not engage in multiple transactions at the same time
 * (i.e., you must sell the stock before you buy again).
 *
 * Example 1:
 *
 * Input: [7,1,5,3,6,4]
 * Output: 7
 * 
 * Example 2:
 *
 * Input: [1,2,3,4,5]
 * Output: 4
 */

#include <iostream>
#include <map>
#include <vector>

using namespace std;

std::ostream &operator<<(std::ostream &os, const std::vector<int> arr)
{
    for (std::vector<int>::const_iterator it = arr.begin();
         it != arr.end();
         it++)
    {
        os << *it << " ";
    }
    return os;
}

// SOLTION 1: O(n) solution by consuming input prices
int maxProfit(const vector<int>& prices)
{
    // what we return
    int returnValue = 0;

    // locals
    unsigned int count = prices.size();
    if (count == 0)
    {
        return returnValue;
    }

    // we have at least 1 element in the array ==> consume input from the right
    int maxSoFar = 0;
    for (int i = count -1; i >= 0; i--)
    {
        // check if this is a bigger max
        if ( prices[i] > maxSoFar )
        {
            maxSoFar = prices[i];
        }
        returnValue += maxSoFar - prices[i];
        std::cout << "prices[i] = " << prices[i] << ", maxSoFar = " << maxSoFar << ", maxSoFar - prices[i] = " << (maxSoFar - prices[i]) << std::endl;
    }

    // finally return
    return returnValue;
}

int main(int argc, char const *argv[])
{
    // test case 1
    std::vector<int> input = {7,1,5,3,6,4};
    std::cout << "input: " << input << std::endl;
    int output = maxProfit(input);
    std::cout << "maxProfit: " << output << std::endl;

    // 2
    std::cout << "\n====\n" << std::endl;
    input = {1, 5, 2, 3, 5};
    std::cout << "input: " << input << std::endl;
    output = maxProfit(input);
    std::cout << "maxProfit: " << output << std::endl;

    return 0;
}