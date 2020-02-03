# LEETCODE 121: Best Time to Buy and Sell Stock
#
# https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#
# Say you have an array for which the ith element is the price of a given stock on day i.
# 
# If you were only permitted to complete at most one transaction 
# (i.e., buy one and sell one share of the stock), 
# design an algorithm to find the maximum profit.
#
# Example 1:
#
# Input: [7,1,5,3,6,4]
# Output: 7
#
# Example 2:
#
# Input: [7,6,4,3,1]
# Output: 0

def max_profit(prices):
    # sanity checks
    count = len(prices)
    if count < 2:
        return 0

    # at this point, we have at least 2 data points in prices

    # what we return
    profit = 0

    # compute differences list
    diff = [0]
    for i in range(1, count):
        diff.append(prices[i] - prices[i-1])

    # debug
    print('Prices:', prices)
    print('Diff:', diff)

    # consume differences list
    is_buy = True
    for i,_ in enumerate(diff):
        if is_buy:
            if (i == 0 and diff[1] > 0) or (
                    i > 0 and 
                    i < count - 2 and
                    diff[i-1] >= 0 and
                    diff[i+1] > 0 and
                    diff[i] <= 0):
                print('Buy:', prices[i])
                profit -= prices[i]
                is_buy = False
        else:
            if (i == count - 1) or (
                    i < count - 1 and
                    diff[i-1] <= 0 and
                    diff[i+1] < 0 and
                    diff[i] > 0):
                #print('Sell:', prices[i])
                profit += prices[i]
                is_buy = True

    # finally return
    return profit

####

# test cases
prices = [7,1,5,3,6,4]
profit = max_profit(prices)
print('prices =', prices, ', profit =', profit)

prices = [7,6,4,3,1]
profit = max_profit(prices)
print('prices =', prices, ', profit =', profit)