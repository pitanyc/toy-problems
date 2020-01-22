/**
 * LEETCODE 4: Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/
 *
 * There are two sorted arrays nums1 and nums2 of size m and n
 * respectively.
 *
 * Find the median of the two sorted arrays. The overall run time
 * complexity should be O(log (m+n)).
 *
 * You may assume nums1 and nums2 cannot be both empty.
 *
 * Example 1:
 *
 * nums1 = [1, 3] nums2 = [2]
 *
 * The median is 2.0
 * 
 * Example 2:
 *
 * nums1 = [1, 2] nums2 = [3, 4]
 *
 * The median is (2 + 3)/2 = 2.5
 */

#include <iostream>
#include <vector>

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

// O(N+M) solution: merge sorted arrays into 1, look at middle element.
double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2)
{
    // locals
    unsigned int N = nums1.size();
    unsigned int M = nums2.size();
    unsigned int S = N + M;

    // create merged array
    std::vector<int> merged;

    // merge
    unsigned int i = 0;
    unsigned int j = 0;
    for (unsigned int k = 0; k < S; k++)
    {
        if (i < N && j < M)
        {
            // both have elements ==> choose smaller one
            if (nums1.at(i) < nums2.at(j))
            {
                merged.push_back(nums1.at(i));
                i++;
            }
            else
            {
                merged.push_back(nums2.at(j));
                j++;
            }
        }
        else if (i < N)
        {
            merged.push_back(nums1.at(i));
            i++;
        }
        else if (j < M)
        {
            merged.push_back(nums2.at(j));
            j++;
        }
    }

    // std::cout << "merged: " << merged << std::endl;

    // at this point, merged contains all elements in a sorted order
    //  ==> choose middle element, or avg of the middle 2
    double median = 0.0;
    unsigned int middleIndex = S / 2;
    if (S % 2 == 0)
    {
        // even elements ==> average middle ones
        if (middleIndex > 0)
        {
            median = (merged.at(middleIndex - 1) + merged.at(middleIndex)) / 2.0;
        }
        else
        {
            median = merged.at(middleIndex);
        }
    }
    else
    {
        // odd elements ==> choose middle one
        median = merged.at(middleIndex);
    }

    // finally return
    return median;
}

int main(int argc, char const *argv[])
{
    // test case 1
    std::vector<int> nums1 = {1, 3};
    std::vector<int> nums2 = {2};
    std::cout << "nums1: " << nums1 << "\nnums2: " << nums2 << std::endl;
    double output = findMedianSortedArrays(nums1, nums2);
    std::cout << "median: " << output << std::endl;

    // test case 2
    nums1 = {1, 2};
    nums2 = {3, 4};
    std::cout << "nums1: " << nums1 << "\nnums2: " << nums2 << std::endl;
    output = findMedianSortedArrays(nums1, nums2);
    std::cout << "median: " << output << std::endl;

    return 0;
}
