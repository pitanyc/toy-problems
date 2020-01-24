# toy-problems

Coding exercises

## Patterns

1. If the given input is sorted _(array, list, or matrix)_, then use __Binary Search__ or __Two Pointers__ strategy.

2. If we need _top/maximum/minimum/closest k elements_ among N elements, then use a __Heap__.

3. If we need to try all combinations (or permutations) of the input, then use recursive __Backtracking__ or iterative __Breadth-First Search__.

4. Questions on Trees & Graphs can be solved through __BFS__ or __DFS__.

5. Every recursive solution can be converted to an iterative solution using a __Stack__.

6. If there is a solution in O(n^2) time and O(1) space, then there are 2 other solutions:
   - Use a __Map__ or __Set__ for O(1) time and O(n) space
   - Use __sorting__ for O(n logn) time and O(1) space

7. If the problem is asking for optimization (eg: maximize or minimize something), then use __Dynamic Programming__.

8. If we need to find some common substring among a set of strings, then use a __HashMap__ or a __Trie__.

9. If we need to search among a bunch of strings, then use a __Trie__.

10. If the problem is a Linked List, and we cannot use extra space, then use __Fast & Slow__ pointer approach.

    <https://medium.com/better-programming/the-ultimate-strategy-to-preparing-for-the-coding-interview-ee9f7eb439f3>

11. Sliding window Dynamic Programming questions can be solved using __Fast & Slow__ pointer approach:
    - __Fast / Slow__:
        - Bit Flip
        - Minimum Window Substring
        - Consecutive Subarray Sum
    - __Fast / Catchup__:
        - Max Consecutive Sum
        - Buy/Sell Stocks
    - __Fast / Lag__:
        - House Robber
    - __Front / Back__:
        - Rainwater
        - Sorted Two Sum

    <https://medium.com/outco/how-to-solve-sliding-window-problems-28d67601a66>

## Links

- Solution patterns: <https://medium.com/better-programming/the-ultimate-strategy-to-preparing-for-the-coding-interview-ee9f7eb439f3>

- Algorithm solving techniques: <https://medium.com/@shinjukudev/algorithm-solve-techniques-7e4fd008306f>
