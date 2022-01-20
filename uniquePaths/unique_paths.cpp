/**
 * LEETCODE 62. Unique Paths
 *
 * https://leetcode.com/problems/unique-paths/
 *
 * There is a robot on an m x n grid. The robot is initially located at the
 * top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right
 * corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right
 * at any point in time.
 * 
 * Given the two integers m and n, return the number of possible unique paths that
 * the robot can take to reach the bottom-right corner.
 * 
 * Example 1:
 * Input: m = 3, n = 7
 * Output: 28
 * 
 * Example 2:
 * Input: m = 3, n = 2
 * Output: 3
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

// SOLUTION 1: Go from the back, count how many ways you can reach each cell.
//
//             If you are already on the last row or column, then there is
//             only 1 way to reach the last cell: keep going on the last
//             row right or on the last column down.
//
//             For any other cell that has both down and right neighbors:
//               * the cell's value is simply the sum of the down and right neighbors value
//
//             Return the value obtained at index (0, 0).
//
// Time:  O(m*n)
// Space: O(m*n)
int uniquePaths(int m, int n)
{
    // sanity checks
    if ( m < 1 || n < 1 )
    {
        return 0;
    }

    // at this point both m & n are >= 1

    // locals
    vector<vector<int>> grid;
    vector<int> row(n, 1);
    grid.resize(m, row);
    // cout << "grid: " << grid << endl;

    // go from bottom-right to top-left
    for (int row = m - 2; row >= 0; row--)
    {
        for (int col = n - 2; col >= 0; col--)
        {
            // value = sum(bottom + right)
            grid[row][col] = grid[row + 1][col] + grid[row][col + 1];
        }
    }
    
    // finally return with the (0, 0) index value
    return grid[0][0];
}

int main(int argc, const char** argv)
{
    // test case 1
    int m = 3;
    int n = 7;
    cout << "m: " << m << ", n: " << n << endl;
    int output = uniquePaths(m, n);
    cout << "output: " << output << endl;

    // test case 2
    // cout << "====" << endl;
    // input = {3, 2, 1, 0, 4};
    // cout << "input: " << input << endl;
    // output = moveZeros(input);
    // cout << "output: " << output << endl;

    return 0;
}