# LEETCODE 70: Climbing Stairs
#
# https://leetcode.com/problems/climbing-stairs/
#
# You are climbing a stair case. It takes n steps to reach to the top.
#
# Each time you can either climb 1 or 2 steps.
# How many distinct ways can you climb to the top?
#
# Example 1:
#
# Input: 2
# Output: 2
# Explanation: There are two ways to climb to the top.
# 1. 1 step + 1 step
# 2. 2 steps
#
# Example 2:
#
# Input: 3
# Output: 3
# Explanation: There are three ways to climb to the top.
# 1. 1 step + 1 step + 1 step
# 2. 1 step + 2 steps
# 3. 2 steps + 1 step

# SOLUTION 1: DP, O(n)
def climb_stairs(n):
    dp = [0, 1, 2]
    for i in range(3, n + 1):
        dp.append(dp[i-1] + dp[i-2])
    return dp[n]

# SOLUTION 2: Recursive, O(2^n)
def climb_stairs_slow(n):
    # sanity check
    if n <= 0:
        return 0
    elif n == 1:
        return 1
    elif n == 2:
        return 2
    else:
        return climb_stairs_slow(n-1) + climb_stairs_slow(n-2)


####

# test cases
n = 0
print('n =', n, 'slow:', climb_stairs_slow(n), 'fast:', climb_stairs(n))

n = 1
print('n =', n, 'slow:', climb_stairs_slow(n), 'fast:', climb_stairs(n))

n = 2
print('n =', n, 'slow:', climb_stairs_slow(n), 'fast:', climb_stairs(n))

n = 3
print('n =', n, 'slow:', climb_stairs_slow(n), 'fast:', climb_stairs(n))

n = 4
print('n =', n, 'slow:', climb_stairs_slow(n), 'fast:', climb_stairs(n))

n = 5
print('n =', n, 'slow:', climb_stairs_slow(n), 'fast:', climb_stairs(n))

n = 10
print('n =', n, 'slow:', climb_stairs_slow(n), 'fast:', climb_stairs(n))
