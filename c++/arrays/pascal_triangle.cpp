/**
 * https://www.programcreek.com/2014/04/leetcode-pascals-triangle-ii-java/
 *
 *  Pascal’s Triangle
 * 
 *  0)         1
 *  1)        1 1
 *  2)       1 2 1
 *  3)      1 3 3 1
 *  4)     1 4 6 4 1
 *  5)    1 5 10 10 5 1
 * 
 * Write a method to return the coefficient at given row & column:
 * int coeff(int row, int col)
 * 
 * For example, coeff(4, 2) should return 6.
 */

#include <iostream>
#include <vector>

void print(const std::vector<std::vector<unsigned int>> &pascal)
{
    unsigned int count = pascal.size();
    for (unsigned int i = 0; i < count; i++)
    {
        for (unsigned int j = 0; j <= i; j++)
        {
            std::cout << pascal.at(i).at(j) << " ";
        }
        std::cout << std::endl;
    }
}

void computeRowNaive(unsigned int row,
                     std::vector<std::vector<unsigned int>> &pascal)
{
    // naive: empty out
    pascal.clear();

    // compute values fresh
    std::vector<unsigned int> values;

    // row 0
    values.push_back(1);
    pascal.push_back(values);

    // row 1
    values.resize(2, 1);
    pascal.push_back(values);

    // row >= 2
    for (unsigned int i = 2; i < row + 1; i++)
    {
        values.resize(i + 1, 1);
        for (unsigned int j = 1; j < i; j++)
        {
            values.at(j) = pascal.at(i - 1).at(j - 1) +
                           pascal.at(i - 1).at(j);
        }
        pascal.push_back(values);
    }
}

void computeRow(unsigned int row,
                std::vector<std::vector<unsigned int>> &pascal)
{
    // special case ==> pascal still empty
    std::vector<unsigned int> values;
    if (pascal.empty())
    {
        // push back first 2 rows

        // row 0
        values.push_back(1);
        pascal.push_back(values);

        // row 1
        values.resize(2, 1);
        pascal.push_back(values);
    }

    // build from current size up to requested row
    for (unsigned int currentSize = pascal.size();
         currentSize < row + 1;
         currentSize++)
    {
        values.resize(currentSize + 1, 1);
        for (unsigned int j = 1; j < currentSize; j++)
        {
            values.at(j) = pascal.at(currentSize - 1).at(j - 1) +
                           pascal.at(currentSize - 1).at(j);
        }
        pascal.push_back(values);
    }
}

unsigned int coeff(unsigned int row,
                   unsigned int col)
{
    // validate input
    if (col > row)
    {
        throw "Column cannot be greater than the row";
    }

    // at this point we have valid input

    // memoize: store coefficient rows in a vector
    static std::vector<std::vector<unsigned int>> pascal;

    // delegate
    computeRow(row, pascal);

    // finally return
    return pascal.at(row).at(col);
}

int main(int argc, char const *argv[])
{
    // test case 1
    unsigned int row = 3;
    unsigned int col = 0;
    std::cout << "row = " << row << ", col = " << col << std::endl;
    unsigned int output = coeff(row, col);
    std::cout << "coeff = " << output << std::endl;

    // test case 1
    row = 5;
    col = 2;
    std::cout << "====\nrow = " << row << ", col = " << col << std::endl;
    output = coeff(row, col);
    std::cout << "coeff = " << output << std::endl;

    // test case 2
    row = 0;
    col = 2;
    std::cout << "====\nrow = " << row << ", col = " << col << std::endl;
    output = coeff(row, col);
    std::cout << "coeff = " << output << std::endl;

    return 0;
}
