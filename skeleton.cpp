/**
 * LEETCODE 55. Jump Game
 *
 * https://leetcode.com/problems/jump-game/
 *
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// STREAM OPERATOR ==> vector of int
ostream& operator<<(ostream& os, const vector<int>& arr)
{
    os << "[";
    for ( vector<int>::const_iterator it = arr.begin(); it != arr.end(); it++ )
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

// STREAM OPERATOR ==> vector of vector of int
ostream& operator<<(ostream &os, const vector<vector<int>>& arr)
{
    os << endl;
    for ( vector<vector<int>>::const_iterator it = arr.begin();
          it != arr.end();
          it++ )
    {
        os << "  " << *it;
        if (it + 1 != arr.end()) os << endl;
    }
    return os;
}

// SOLUTION 1:
//
// Time:
// Space:
vector<int> moveZeros(const vector<int>& in)
{
    return vector<int>();
}

int main(int argc, const char** argv)
{
    // test case 1
    vector<int> input = {2, 3, 1, 1, 4};
    cout << "input: " << input << endl;
    vector<int> output = moveZeros(input);
    cout << "output: " << output << endl;

    // test case 2
    // cout << "====" << endl;
    // input = {3, 2, 1, 0, 4};
    // cout << "input: " << input << endl;
    // output = moveZeros(input);
    // cout << "output: " << output << endl;

    return 0;
}