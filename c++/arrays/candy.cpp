/**
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
#include <iostream>
#include <vector>

using namespace std;

vector<int> candy(const vector<int> &ratings)
{
    // what we return
    vector<int> result;

    // validate input
    unsigned int len = ratings.size();
    if (len == 0)
    {
        return result;
    }

    // init result to all zeros
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
    return result;
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
    vector<int> ratings = {1, 2, 4, 2, 1, 5};
    cout << "input: " << ratings << endl;
    vector<int> result = candy(ratings);
    cout << "output: " << result << endl;

    // test case 2: descending start
    cout << "====" << endl;
    ratings = {5, 4, 3, 2, 2, 6};
    cout << "input: " << ratings << endl;
    result = candy(ratings);
    cout << "output: " << result << endl;

    return 0;
}
