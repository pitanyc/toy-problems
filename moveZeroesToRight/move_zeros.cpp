/**
 * LEETCODE 283. Move Zeroes
 *
 * https://leetcode.com/problems/move-zeroes/
 *
 * Given an array nums, write a function to move all 0's to the end of
 * it while maintaining the relative order of the non-zero elements.
 *
 * For example, given nums = [0, 1, 0, 3, 12], after calling your
 * function, nums should be [1, 3, 12, 0, 0].
 */
#include <iostream>
#include <vector>

using namespace std;

std::ostream& operator<<(std::ostream& os, const std::vector<int> arr)
{
    os << "[";
    for ( std::vector<int>::const_iterator it = arr.begin(); it != arr.end();
          it++ )
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

// SOLUTION 1: Iterate thru all elements starting at index 0.
//             If current element is zero:
//               * push back a zero at the end
//               * erase current element
//
// Time:  O(N) - must iterate thru entire input vector
// Space: O(1) - no additional data structure needed
vector<int> moveZeros(vector<int>& in)
{
    // sanity checks

    // consume input
    for ( vector<int>::iterator it = in.begin(); it != in.end(); it++ )
    {
        cout << "in: " << in << endl;
        if ( *it == 0 )
        {
            in.push_back(0);
            in.erase(it);
        }
    }

    // finally return
    return in;
}

// SOLUTION 2: Use 2 pointers, iterate thru input array:
//               * if element is non-zero, swap it with the left zero
//
// Time:  O(N) - must iterate thru entire input vector
// Space: O(1) - no additional data structure needed
vector<int> moveZeros2(vector<int>& in)
{
    // locals
    unsigned int count = in.size();
    int left = -1;

    // consume input
    for (size_t i = 0; i < count; i++)
    {
        // cout << "i: " << i << ", left: " << left << ", in: " << in << endl;
        int curr = in.at(i);
        if ( curr == 0 )
        {
            // 0
            if ( left == -1 )
            {
                // first 0 in vector => update left zero pointer
                left = i;
            }
        }
        else
        {
            // non-zero
            if ( left >= 0 )
            {
                // move non-zero element to left zero
                in.at(left) = curr;
                in.at(i) = 0;
                left++;
            }
        }
    }
    
    // finally return
    return in;
}

int main(int argc, char const* argv[])
{
    // test case 1
    vector<int> input = {0, 1, 0, 3, 12};
    cout << "input = " << input << endl;
    vector<int> output = moveZeros2(input);
    cout << "output: " << output << endl;

    return 0;
}