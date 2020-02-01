# LEETCODE 152: Maximum Product Subarray
#
# https://leetcode.com/problems/maximum-subarray/
#
# Given an integer array nums, find the contiguous subarray within an array 
# (containing at least one number) which has the largest product.
#
# Example 1:
#
# Input: [2,3,-2,4]
# Output: 6
# Explanation: [2,3] has the largest product 6.
#
# Example 2:
#
# Input: [-2,0,-1]
# Output: 0
# Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

def max_product(nums):
    # what we return
    product = 0

    # helper
    count = len(nums)

    # sanity check
    if count == 0:
        return product

    # at this point we have at least 1 element ==> consume input
    product = nums[0]
    maximum = nums[0]
    minimum = nums[0]
    for i in range(1, count):
        # save out values
        mx = maximum
        mn = minimum

        # update minimum and maximum
        maximum = max(max(nums[i], mx * nums[i]), mn * nums[i])
        minimum = min(min(nums[i], mx * nums[i]), mn * nums[i])
        product = max(product, maximum)

    # finally return
    return product

# test cases
nums = [2,3,-2,4]
result = max_product(nums)
print('Nums:', nums, 'Result:', result)

nums = [-2,0,-1]
result = max_product(nums)
print('Nums:', nums, 'Result:', result)
