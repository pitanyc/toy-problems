/**
 * LEETCODE 135: Candy.
 * 
 * https://leetcode.com/problems/candy/
 * https://www.programcreek.com/2014/03/leetcode-candy-java/
 *
 *  There are N children standing in a line. Each child is assigned a
 *  rating value. You are giving candies to these children subjected to
 *  the following requirements:
 *
 * 1. Each child must have at least one candy.
 * 2. Children with a higher rating get more candies than their
 *    neighbors. What is the minimum candies you must give?
 */
#include <numeric>
#include <iostream>
#include <vector>

using namespace std;

int candy(const vector<int> &ratings)
{
    // validate input
    unsigned int len = ratings.size();
    if (len == 0)
    {
        return 0;
    }

    // init results to all 1
    vector<int> result;
    result.resize(len, 1);

    // go from left, starting  at index 1
    unsigned int give = 1;
    for (unsigned int i = 1; i < len; i++)
    {
        if (ratings.at(i) > ratings.at(i - 1))
        {
            // neighbor has more ==> give more
            give++;
            result[i] = give;
        }
        else if (ratings.at(i) == ratings.at(i - 1))
        {
            // neighbor has same ==> give same
            result[i] = give;
        }
        else
        {
            // neighbor has less ==> start over at 1
            give = 1;
        }
    }

    // repeat: go from right
    give = 1;
    for (int i = len - 2; i >= 0; i--)
    {
        if (ratings.at(i) > ratings.at(i + 1))
        {
            // neighbor has more ==> give more
            give++;
            result[i] = give;
        }
        else if (ratings.at(i) == ratings.at(i + 1))
        {
            // neighbor has same ==> give same
            result[i] = give;
        }
        else
        {
            // neighbor has less ==> start over at 1
            give = 1;
        }
    }

    // finally return
    return std::accumulate(result.begin(), result.end(), 0);
}

std::ostream &operator<<(std::ostream &os, const std::vector<int> &input)
{
    for (std::vector<int>::const_iterator it = input.begin();
         it != input.end();
         it++)
    {
        os << *it << " ";
    }
    return os;
}

int main(int argc, char const *argv[])
{
    // test case 1: regular input
    vector<int> ratings = {1, 0, 2};
    cout << "input: " << ratings << endl;
    int result = candy(ratings);
    cout << "output: " << result << endl;

    // test case 2: descending start
    cout << "====" << endl;
    ratings = {1, 2, 2};
    cout << "input: " << ratings << endl;
    result = candy(ratings);
    cout << "output: " << result << endl;

    return 0;
}
