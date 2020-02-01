# LEETCODE 53: Maximum Subarray
#
# https://leetcode.com/problems/maximum-subarray/
#
# Find the maximum consecutive sum in an unsorted int array.
#
# Example:
#
# Input: [-2,1,-3,4,-1,2,1,-5,4],
# Output: 6
# Explanation: [4,-1,2,1] has the largest sum = 6.

def max_sum(nums):
    # what we return
    global_max = -1
    current_max = -1

    # helper
    count = len(nums)

    # sanity check
    if count > 0:
        global_max = nums[0]
        current_max = nums[0]

    # consume input
    for i in range(1, count):
        current_max = max(current_max + nums[i], nums[i])
        if current_max > global_max:
            global_max = current_max

    # finally return
    return global_max

# test cases
result = max_sum([2,1,-3,4,-1,2,1,-5,4])
print('Test 1:', result)

result = max_sum([2, -1, 3, 0])
print('Test 2:', result)