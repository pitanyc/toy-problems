/**
 * LEETCODE 238: Product of Array Except Self
 * 
 * https://leetcode.com/problems/product-of-array-except-self/
 *
 * Given an array nums of n integers where n > 1, 
 * return an array output such that output[i] is equal to the 
 * product of all the elements of nums except nums[i].
 *
 * Example:
 * 
 * Input:  [1,2,3,4]
 * Output: [24,12,8,6]
 * 
 * Note: Please solve it without division and in O(n).
 */

#include <iostream>
#include <map>
#include <vector>

using namespace std;

std::ostream &operator<<(std::ostream &os, const std::vector<int> arr)
{
    for (std::vector<int>::const_iterator it = arr.begin();
         it != arr.end();
         it++)
    {
        os << *it << " ";
    }
    return os;
}

// SOLTION 1: O(n) solution WITH division
vector<int> productExceptSelfWithDivision(vector<int>& nums)
{
    // what we return
    vector<int> returnValue;

    // locals
    unsigned int count = nums.size();
    if (count == 0)
    {
        return returnValue;
    }

    // we have at leats 1 element in the array ==> get product
    int product = 1;
    for(vector<int>::const_iterator it = nums.begin();
        it < nums.end();
        it++)
    {
        product *= *it;
    }

    // populate output
    for(vector<int>::const_iterator it = nums.begin();
        it < nums.end();
        it++)
    {
        returnValue.push_back(product / (*it));
    }

    // finally return
    return returnValue;
}

//////////////////

// SOLTION 2: O(n^2) solution WITHOUT division
vector<int> productExceptSelfWithoutDivisionSlow(vector<int>& nums)
{
    // what we return
    vector<int> returnValue;

    // locals
    unsigned int count = nums.size();
    if (count == 0)
    {
        return returnValue;
    }

    // resize output
    returnValue.resize(count, 1);

    // we have at leats 1 element in the array ==> calculate products
    for(unsigned int i = 0; i < count; i++)
    {
        for(unsigned int j = 0; j < count; j++)
        {
            if (i != j)
            {
                returnValue.at(j) *= nums.at(i);
            }
        }
    }

    // finally return
    return returnValue;
}

////////////////////////////

// SOLTION 3: O(n) solution WITHOUT division
vector<int> productExceptSelfWithoutDivisionFast(vector<int>& nums)
{
    // what we return
    vector<int> returnValue;

    // locals
    unsigned int count = nums.size();
    if (count == 0)
    {
        return returnValue;
    }

    // create forward and backward product vectors
    vector<int> forward(count, 1);
    vector<int> backward(count, 1);
    for(unsigned int i = 0; i < count - 1; i++)
    {
        forward.at(i + 1) = forward.at(i) * nums.at(i);
    }
    for(unsigned int i = count - 1; i > 0; i--)
    {
        backward.at(i - 1) = backward.at(i) * nums.at(i);
    }
    std::cout << "forward: " << forward << std::endl;
    std::cout << "backward: " << backward << std::endl;

    // assemble return value
    for(unsigned int i = 0; i < count; i++)
    {
        returnValue.push_back(forward.at(i) * backward.at(i));
    }

    // finally return
    return returnValue;
}

int main(int argc, char const *argv[])
{
    // test case 1
    std::vector<int> input = {1,2,3,4};
    std::cout << "input: " << input << std::endl;
    vector<int> output = productExceptSelfWithDivision(input);
    vector<int> output2 = productExceptSelfWithoutDivisionSlow(input);
    vector<int> output3 = productExceptSelfWithoutDivisionFast(input);
    // std::cout << "productExceptSelfWithDivision: " << output << std::endl;
    // std::cout << "productExceptSelfWithoutDivisionSlow: " << output2 << std::endl;
    std::cout << "productExceptSelfWithoutDivisionFast: " << output3 << std::endl;

    return 0;
}