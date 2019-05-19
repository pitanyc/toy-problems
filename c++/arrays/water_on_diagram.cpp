/**
 * https://www.programcreek.com/2014/06/leetcode-trapping-rain-water-java/
 *
 *  Trapping Rain Water
 *
 * Given n non-negative integers representing an elevation map where the
 * width of each bar is 1, compute how much water it is able to trap
 * after raining.
 *
 * For example, given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 */

#include <iostream>
#include <vector>

std::ostream &operator<<(std::ostream &os, const std::vector<unsigned int> arr)
{
    for (std::vector<unsigned int>::const_iterator it = arr.begin();
         it != arr.end();
         it++)
    {
        os << *it << " ";
    }
    return os;
}

unsigned int calculateWater(const std::vector<unsigned int> &input)
{
    // what we return
    unsigned int amount = 0;

    // locals
    unsigned int len = input.size();
    if (len == 0)
    {
        return amount;
    }

    // length at least 1

    // transfrom input into left & right arrays

    // build left
    std::vector<unsigned int> left;
    unsigned int max = input.at(0);
    left.push_back(max);
    for (int i = 1; i < len; i++)
    {
        if (input.at(i) > max)
        {
            max = input.at(i);
        }
        left.push_back(max);
    }
    // std::cout << "left: " << left << std::endl;

    // build right
    std::vector<unsigned int> right;
    right.resize(len, 0);
    max = input.at(len - 1);
    right.at(len - 1) = max;
    for (int i = len - 2; i >= 0; i--)
    {
        if (input.at(i) > max)
        {
            max = input.at(i);
        }
        right.at(i) = max;
    }
    // std::cout << "right: " << right << std::endl;

    // merge
    for (int i = 0; i < len; i++)
    {
        amount += std::min(left.at(i), right.at(i)) - input.at(i);
    }

    // finally return
    return amount;
}

int main(int argc, char const *argv[])
{
    // test case 1
    std::vector<unsigned int> input = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    std::cout << "input: " << input << std::endl;
    unsigned int output = calculateWater(input);
    std::cout << "output: " << output << std::endl;

    // test case 2
    input = {6, 5, 4, 2, 1, 4, 5, 1, 0, 3};
    std::cout << "====\ninput: " << input << std::endl;
    output = calculateWater(input);
    std::cout << "output: " << output << std::endl;

    return 0;
}
