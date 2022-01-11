/**
 * LEETCODE 11. Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/
 *
 * Given n non-negative integers a1, a2, ..., an , where each represents
 * a point at coordinate (i, ai). n vertical lines are drawn such that
 * the two endpoints of line i is at (i, ai) and (i, 0). Find two lines,
 * which together with x-axis forms a container, such that the container
 * contains the most water.
 *
 * Example:
 *
 * Input: [1,8,6,2,5,4,8,3,7]
 * Output: 49
 */

#include <iostream>
#include <map>
#include <vector>

using namespace std;

std::ostream& operator<<(std::ostream &os, const std::vector<int> arr)
{
    for (std::vector<int>::const_iterator it = arr.begin();
         it != arr.end();
         it++)
    {
        os << *it << " ";
    }
    return os;
}

// SOLUTION: 
int maxArea(const vector<int>& height)
{
    // what we return
    int returnValue = 0;

    // sanity check
    unsigned int count = height.size();
    if ( count < 2 )
    {
        return returnValue;
    }

    // at this point, we have at least 2 points in heights input array

    // locals
    vector<int> maxRight(count);
    vector<int> maxLeft(count);

    // go from the back
    int maxRightSide = height.at(count - 1);
    for ( unsigned int i = count - 1; i > 0; i--)
    {
        maxRightSide = std::max(maxRightSide, height.at(i));
        maxRight.at(i) = maxRightSide;
    }
    // std::cout << "maxRight: " << maxRight << std::endl;

    // go from the beginning
    int maxLeftSide = height.at(0);
    for ( unsigned int i = 0; i < count; i++)
    {
        maxLeftSide = std::max(maxLeftSide, height.at(i));
        maxLeft.at(i) = maxLeftSide;
    }
    // std::cout << "maxLeft: " << maxLeft << std::endl;

    // calculate volumes
    for ( unsigned int i = 1; i < count; i++)
    {
        for ( unsigned int j = i; j < count; j++)
        {
            int w = j - i;
            int h = std::min(maxLeft.at(i), maxRight.at(j));
            int volume = w * h;
            returnValue = std::max(returnValue, volume);
            std::cout << "i: " << i << ", j: " << j << " | h = " << h << ", w = " << w << ", volume = " << volume << std::endl;
        }
    }

    // finally return
    return returnValue;
}

// SOLUTION
int main(int argc, char const *argv[])
{
    // test case 1
    std::vector<int> input = {1,8,6,2,5,4,8,3,7};
    std::cout << "input: " << input << std::endl;
    int output = maxArea(input);
    std::cout << "output: " << output << std::endl;
    
    // test case 2
    std::cout << "\n====\n" << std::endl;
    input = {0,1,2,3,4,5};
    std::cout << "input: " << input << std::endl;
    output = maxArea(input);
    std::cout << "output: " << output << std::endl;

    return 0;
}
