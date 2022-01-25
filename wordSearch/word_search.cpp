/**
 * LEETCODE 79. Word Search
 *
 * https://leetcode.com/problems/word-search/
 *
 * Given an m x n grid of characters board and a string word, return true if
 * word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cells, where
 * adjacent cells are horizontally or vertically neighboring. The same letter cell
 * may not be used more than once.
 * 
 * Example 1:
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
 *        word = "ABCCED"
 * Output: true
 * 
 * Example 2:
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
 *        word = "SEE"
 * Output: true
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// STREAM OPERATOR ==> vector of int
ostream& operator<<(ostream& os, const vector<char>& arr)
{
    os << "[";
    for ( vector<char>::const_iterator it = arr.begin(); it != arr.end(); it++ )
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
ostream& operator<<(ostream& os, const vector<vector<char>>& arr)
{
    os << endl;
    for ( vector<vector<char>>::const_iterator it = arr.begin(); it != arr.end();
          it++ )
    {
        os << "  " << *it;
        if ( it + 1 != arr.end() )
            os << endl;
    }
    return os;
}

void search(vector<vector<char>>& board,
            vector<vector<bool>>& visited,
            string& word,
            int index,
            int row,
            int col,
            bool& found)
{
    // check if we consumed the word
    if (index == word.length())
    {
        found = true;
        return;
    }

    // else look for the next letter in word
    char& letter = word.at(index);
    // cout << "letter: " << letter << endl;

    // up
    if (row - 1 >= 0 &&
        board[row-1][col] == letter &&
        !visited[row-1][col])
    {
        visited[row-1][col] = true;
        search(board, visited, word, index + 1, row - 1, col, found);
    }

    // down
    if (row + 1 < board.size() &&
        board[row+1][col] == letter &&
        !visited[row+1][col])
    {
        visited[row+1][col] = true;
        search(board, visited, word, index + 1, row + 1, col, found);
    }

    // left
    if (col - 1 >= 0 &&
        board[row][col-1] == letter &&
        !visited[row][col-1])
    {
        visited[row][col-1] = true;
        search(board, visited, word, index + 1, row, col - 1, found);
    }

    // right
    if (col + 1 < board[0].size() &&
        board[row][col+1] == letter &&
        !visited[row][col+1])
    {
        visited[row][col+1] = true;
        search(board, visited, word, index + 1, row, col + 1, found);
    }
}

// SOLUTION 1: Iterate thru the entire board, find the first character
//             in the word.  Then, use grid-fill (DFS) with backtracking to
//             find subsequent letters.  To ensure we don't use the same letter
//             twice, keep a visited[][] grid of used coords.
//
//             If we get to the end of the word, we return true.
//             Otherwise, if we have consumed the whole board and haven't
//             found anything, return false.
//
// Time:  O(M*N)
// Space: O(M*N)
bool exist(vector<vector<char>>& board, string& word)
{
    // locals
    int index = 0;  // next letter we are looking for in word
    char& letter = word.at(index);
    int m = board.size();
    int n = board[0].size();
    bool returnValue = false;

    // consume board, look for first letter
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // cout << "cell: " << board[i][j] << endl;
            if (board[i][j] == letter)
            {
                // found first letter ==> proceed to fill search
                vector<bool> temp(n, false);
                vector<vector<bool>> visited(m, temp);
                visited[i][j] = true;

                search(board, visited, word, index + 1, i, j, returnValue);
                if (returnValue)
                {
                    break;
                }
            }
        }
        if (returnValue)
        {
            break;
        }
    }

    return returnValue;
}

int main(int argc, const char** argv)
{
    // test case 1
    vector<vector<char>> input = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word = "ABCCED";
    cout << "input: " << input << endl;
    cout << "word: " << word << endl;
    bool output = exist(input, word);
    cout << "output: " << output << endl;

    // test case 2
    cout << "====" << endl;
    word = "SEE";
    cout << "input: " << input << endl;
    cout << "word: " << word << endl;
    output = exist(input, word);
    cout << "output: " << output << endl;

    // test case 3
    cout << "====" << endl;
    word = "ABCB";
    cout << "input: " << input << endl;
    cout << "word: " << word << endl;
    output = exist(input, word);
    cout << "output: " << output << endl;

    return 0;
}