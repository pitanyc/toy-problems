/**
 * LEETCODE 73. Set Matrix Zeroes
 *
 * https://leetcode.com/problems/set-matrix-zeroes/
 *
 * Given an m x n integer matrix matrix, if an element is 0, set its entire row
 * and column to 0's, and return the matrix.
 * 
 * You must do it in place.
 */

#include <algorithm>
#include <iostream>
#include <set>
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
ostream& operator<<(ostream& os, const vector<vector<int>>& arr)
{
    os << endl;
    for ( vector<vector<int>>::const_iterator it = arr.begin(); it != arr.end();
          it++ )
    {
        os << "  " << *it;
        if ( it + 1 != arr.end() )
        {
            os << endl;
        }
    }
    return os;
}

// SOLUTION 1: Iterate thru entire matrix.  When you encounter a zero:
//              * record the row & col into another datastructure (eg: 2 sets)
//
//             Then, on the second pass, consume this other datastructure
//             and set all elements to zero.
//
// Time:  O(M*N)
// Space: O(M + N) = O(N)
void setZeroes(vector<vector<int>>& grid)
{
    // sanity checks
    int rowCount = grid.size();
    int colCount = grid[0].size();

    // locals
    set<int> zeroRows;
    set<int> zeroCols;

    // iterate thru entire grid
    for (size_t i = 0; i < rowCount; i++)
    {
        for (size_t j = 0; j < colCount; j++)
        {
            if (grid[i][j] == 0)
            {
                zeroRows.insert(i);
                zeroCols.insert(j);
            }
        }
    }

    // set zero rows
    for (set<int>::iterator it = zeroRows.begin(); it != zeroRows.end(); it++)
    {
        int row = *it;
        for (size_t col = 0; col < colCount; col++)
        {
            grid[row][col] = 0;
        }
    }

    // set zero cols
    for (set<int>::iterator it = zeroCols.begin(); it != zeroCols.end(); it++)
    {
        int col = *it;
        for (size_t row = 0; row < rowCount; row++)
        {
            grid[row][col] = 0;
        }
    }
}

int main(int argc, const char** argv)
{
    // test case 1
    vector<vector<int>> input = {{1,1,1},{1,0,1},{1,1,1}};
    cout << "input: " << input << endl;
    setZeroes(input);
    cout << "output: " << input << endl;

    // test case 2
    cout << "====" << endl;
    input = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    cout << "input: " << input << endl;
    setZeroes(input);
    cout << "output: " << input << endl;

    return 0;
}