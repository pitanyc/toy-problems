/**
 * LEETCODE 200. Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number
 * of islands. An island is surrounded by water and is formed by
 * connecting adjacent lands horizontally or vertically. You may assume
 * all four edges of the grid are all surrounded by water.
 *
 * Example 1:
 *
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 * Output: 1
 * 
 * Example 2:
 *
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 * Output: 3
 */

#include <iostream>
#include <vector>

using namespace std;

// STREAM OPERATOR ==> vector of char
std::ostream &operator<<(std::ostream &os, const vector<char> &arr)
{
    for (vector<char>::const_iterator it = arr.begin();
         it != arr.end();
         it++)
    {
        os << *it;
    }
    return os;
}

// STREAM OPERATOR ==> vector of vector of char
std::ostream &operator<<(std::ostream &os, const vector<vector<char>> &arr)
{
    os << std::endl;
    for (vector<vector<char>>::const_iterator it = arr.begin();
         it != arr.end();
         it++)
    {
        os << *it;
        if (it + 1 != arr.end())
            os << std::endl;
    }
    os << std::endl;
    return os;
}

// Bucket fill the passed grid starting with the given (x,y) coordinates.
void fillGrid(vector<vector<char>> &grid, int x, int y, int nofRows, int nofCols)
{
    // sanity checks
    if ( x >= 0 && x < nofRows && 
         y >= 0 && y < nofCols &&
         grid[x][y] == '1' )
    {
        // yes, this is a valid, still unvisited coordinate ==> visit it now
        grid[x][y] = '2';

        // bucket fill all its neighbors
        fillGrid(grid, x - 1, y, nofRows, nofCols);
        fillGrid(grid, x + 1, y, nofRows, nofCols);
        fillGrid(grid, x, y - 1, nofRows, nofCols);
        fillGrid(grid, x, y + 1, nofRows, nofCols);
    }

    // debug
    // std::cout << "grid: " << grid << std::endl;
}

// SOLUTION:
//
// Time:
// Space:
int numberOfIslands(vector<vector<char>> &grid)
{
    // sanity checks
    unsigned int nofRows = grid.size();
    unsigned int nofCols = 0;
    if (nofRows > 0)
    {
        nofCols = grid.at(0).size();
    }

    // debug
    // std::cout << "nofRows: " << nofRows << ", nofCols: " << nofCols << std::endl;

    if (nofRows == 0 || nofCols == 0)
    {
        // nothing to do
        return 0;
    }

    // at this point, we have nofRows > 0 AND nofCols > 0

    // what we return
    int returnValue = 0;

    // iterate over every cell, see if it was visited already and counted for
    for (unsigned int i = 0; i < nofRows; i++)
    {
        for (unsigned j = 0; j < nofCols; j++)
        {
            // std::cout << "grid[i][j]: " << grid[i][j] << std::endl;
            if (grid[i][j] == '1')
            {
                // this is a new island ==> fill it & all its neighbors
                returnValue++;
                fillGrid(grid, i, j, nofRows, nofCols);
                // std::cout << "222 grid: " << grid << std::endl;
            }
        }
    }

    // finally return
    return returnValue;
}

// MAIN
int main(int argc, char const *argv[])
{
    // test case 1
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    std::cout << "grid = " << grid << std::endl;
    int output = numberOfIslands(grid);
    std::cout << "output: " << output << std::endl;

    // test case 2
    std::cout << "\n====\n" << std::endl;
    grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    std::cout << "grid = " << grid << std::endl;
    output = numberOfIslands(grid);
    std::cout << "output: " << output << std::endl;

    // test case 3
    std::cout << "\n====\n" << std::endl;
    grid = {
        {'0', '1', '0', '1', '0'},
        {'1', '0', '1', '0', '1'},
        {'0', '1', '0', '1', '0'},
        {'1', '0', '1', '0', '1'}
    };
    std::cout << "grid = " << grid << std::endl;
    output = numberOfIslands(grid);
    std::cout << "output: " << output << std::endl;

    // test case 4
    std::cout << "\n====\n" << std::endl;
    grid = {
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    std::cout << "grid = " << grid << std::endl;
    output = numberOfIslands(grid);
    std::cout << "output: " << output << std::endl;

    // test case 4
    std::cout << "\n====\n" << std::endl;
    grid = {
        {'1', '1', '1'},
        {'1', '1', '1'},
        {'1', '1', '1'}
    };
    std::cout << "grid = " << grid << std::endl;
    output = numberOfIslands(grid);
    std::cout << "output: " << output << std::endl;

    return 0;
}