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

#include <algorithm> // std::find
#include <iostream>
#include <map>
#include <vector>

using namespace std;

std::ostream& operator<<(std::ostream& os, const std::vector<int> arr)
{
    for ( std::vector<int>::const_iterator it = arr.begin(); it != arr.end();
          it++ )
    {
        os << *it << " ";
    }
    return os;
}

// SOLTION: Find local minimum & maximum points.
//          Iterate thru prices and calculate profit between those points.
// Time: O(N)
// Space: O(N)
int maxProfit(const vector<int>& prices)
{
    // what we return
    int returnValue = 0;

    // locals
    unsigned int count = prices.size();
    if ( count < 2 )
    {
        return returnValue;
    }

    // we have at least 2 prices ==> find local minimum and maximum points

    // use: 1 = local minimum, 2 = local maximum
    vector<int> locals;
    locals.resize(count); // resize inits all elements to 0 automatically

    // first and last elements
    if ( prices.at(0) < prices.at(1) )
    {
        locals.at(0) = 1;
    }
    if ( prices.at(count - 2) < prices.at(count - 1) )
    {
        locals.at(count - 1) = 2;
    }

    // middle elements
    for ( unsigned int i = 1; i < count - 1; i++ )
    {
        int current = prices.at(i);
        int prev = prices.at(i - 1);
        int next = prices.at(i + 1);

        if ( prev > current && current < next )
        {
            // local min
            locals.at(i) = 1;
        }
        else if ( prev < current && current > next )
        {
            // local max
            locals.at(i) = 2;
        }
    }
    std::cout << "locals: " << locals << std::endl;

    // simply count the profit between local min & max points
    for ( unsigned int i = 0; i < count; i++ )
    {
        if ( locals.at(i) == 1 )
        {
            // this is a local minimum ==> find corresponding local max
            for ( unsigned int j = i + 1; j < count; j++ )
            {
                if ( locals.at(j) == 2 )
                {
                    // this is the next local max, calculate profit
                    returnValue += prices.at(j) - prices.at(i);
                    i = j;
                    break;
                }
            }
        }
    }

    // finally return
    return returnValue;
}

int main(int argc, char const* argv[])
{
    // test case 1
    std::vector<int> input = {7, 1, 5, 3, 6, 4};
    std::cout << "input: " << input << std::endl;
    int output = maxProfit(input);
    std::cout << "maxProfit: " << output << std::endl;

    // 2
    std::cout << "\n====\n" << std::endl;
    input = {1, 5, 2, 3, 5};
    std::cout << "input: " << input << std::endl;
    output = maxProfit(input);
    std::cout << "maxProfit: " << output << std::endl;

    // 3
    std::cout << "\n====\n" << std::endl;
    input = {1, 2, 3, 4, 5};
    std::cout << "input: " << input << std::endl;
    output = maxProfit(input);
    std::cout << "maxProfit: " << output << std::endl;

    return 0;
}