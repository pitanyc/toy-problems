/**
 * LEETCODE 88. Merge Sorted Array
 *
 * https://leetcode.com/problems/merge-sorted-array/
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into
 * nums1 as one sorted array.
 *
 * Note:
 *
 * The number of elements initialized in nums1 and nums2 are m and n
 * respectively. You may assume that nums1 has enough space (size that
 * is greater or equal to m + n) to hold additional elements from nums2.
 * 
 * Example:
 *
 * Input:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 *
 * Output: [1,2,2,3,5,6]
 */

#include <iostream>
#include <vector>

using namespace std;

std::ostream& operator<<(std::ostream &os, const std::vector<int> arr)
{
    os << "[";
    for ( vector<int>::const_iterator it = arr.begin();
          it != arr.end();
          it++ )
    {
        os << *it;
        if (it + 1 != arr.end()) os << ", ";
    }
    os << "]";
    return os;
}

// SOLUTION 1: Go from the back of both arrays, pick the larger of the 2 elements.
//
// Time:  O(n)
// Space: O(1)
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    // sanity checks
    if (nums1.size() < (m + n))
    {
        throw runtime_error("Not enough space in nums1!");
    }

    // at this point, we have enough space in nums1

    // locals
    int i = m - 1;
    int j = n - 1;
    int k = (m + n) - 1;
    while (k > 0)
    {
        if (i > -1 && j > -1)
        {
            if (nums1.at(i) > nums2.at(j))
            {
                // use nums1
                nums1.at(k) = nums1.at(i);
                i--;
            }
            else
            {
                // use nums2
                nums1.at(k) = nums2.at(j);
                j--;
            }
        }
        else if (i > -1)
        {
            // use nums1
            nums1.at(k) = nums1.at(i);
            i--;
        }
        else
        {
            // use nums2
            nums1.at(k) = nums2.at(j);
            j--;
        }
        k--;        
    }
}

// SOLUTION 2: Use a temporary vector to hold the merged results.
//             Copy it back to nums1 at the end.
//
// Time:  O(n)
// Space: O(n)
void mergeWithExtraSpace(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    // sanity checks
    if (nums1.size() < (m + n))
    {
        throw runtime_error("Not enough space in nums1!");
    }

    // at this point, we have enough space in nums1

    // since both arrays are sorted, use 2 pointers
    std::vector<int> merged;
    int i = 0;
    int j = 0;
    for (int k = 0; k < m + n; k++)
    {
        if (i < m && j < n)
        {
            if (nums1.at(i) < nums2.at(j))
            {
                // push from nums1
                merged.push_back(nums1.at(i));
                i++;
            }
            else
            {
                // push from nums2
                merged.push_back(nums2.at(j));
                j++;
            }
        }
        else if (i < m)
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

    // debug
    // std::cout << "merged: " << merged << std::endl;

    nums1 = merged;
}

// MAIN
int main(int argc, char* argv[])
{
    // test case 1
    std::vector<int> nums1 = {1,2,3,0,0,0};
    int m = 3;
    std::vector<int> nums2 = {2,5,6};
    int n = 3;
    std::cout << "nums1 = " << nums1 << ", m: " << m << std::endl;
    std::cout << "nums2 = " << nums2 << ", n: " << n << std::endl;
    mergeWithExtraSpace(nums1, m, nums2, n);
    std::cout << "mergeWithExtraSpace = " << nums1 << std::endl;

    // test case 2
    std::cout << "\n====\n" << std::endl;
    nums1 = {1,2,3,0,0,0};
    std::cout << "nums1 = " << nums1 << ", m: " << m << std::endl;
    std::cout << "nums2 = " << nums2 << ", n: " << n << std::endl;
    merge(nums1, m, nums2, n);
    std::cout << "merge = " << nums1 << std::endl;

    return 0;
}
