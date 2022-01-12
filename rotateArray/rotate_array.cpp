/**
 * LEETCODE 189: Rotate Array
 *
 * https://leetcode.com/problems/rotate-array/
 *
 * Rotate an array of n elements to the right by k steps.
 *
 * For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated
 * to [5,6,7,1,2,3,4].
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// STREAM OPERATOR ==> vector of int
std::ostream& operator<<(std::ostream& os, const vector<int>& arr)
{
    os << "[";
    for (vector<int>::const_iterator it = arr.begin();
         it != arr.end();
         it++)
    {
        os << *it;
        if (it + 1 != arr.end())
        {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

void myRotate(vector<int>& input, int k)
{
    // sanity checks
    if ( k == 0 )
    {
        return;
    }
    else if ( k < 0 )
    {
        // we could use this to rotate the array to the left
        // for now, simply ignore this case and throw an exception
        throw runtime_error("k must be positive");
    }

    // at this point, k > 0
    rotate(input.begin(), input.end() - k, input.end());
}

// MAIN
int main(int argc, char* argv[])
{
    // test case 1
    vector<int> input = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    cout << "input: " << input << endl;
    myRotate(input, k);
    cout << "output: " << input << endl;

    return 0;
}
