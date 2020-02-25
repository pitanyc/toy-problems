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

11. __Sliding window Dynamic Programming__ questions can be solved using __Fast & Slow__ pointer approach:
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


## Data Structures

|   #| Name                            | Methods                                            |
| --:|---------------------------------|----------------------------------------------------|
|   1| vector                          | back(), front(), pop_back(), push_back(), resize() |
|   2| map _(unordered_map, multimap)_ | count(), empty(), erase() find(), operator[]       |
|   3| set _(unordered_set, multiset)_ | count(), find(), lower_bound(), upper_bound()      |
|   4| stack                           | empty(), pop(), push(), size(), top()              |
|   5| queue                           | back(), empty(), front(), pop(), push(), size()    |
|   6| priority_queue _(make_heap())_  | empty(), pop(), push(), size(), top()              |
|   7| dequeue                         | back(), clear(), empty(), erase(), front(), pop_back(), pop_front(), push_back(), push_front(), size()   |
|   8| list                            | back(), clear(), empty(), erase(), front(), pop_back(), pop_front(), push_back(), push_front(), remove(), remove_if(), reverse(), size(), sort(), splice(), unique()  |
|   9| forward_list                    | empty(), erase_after(), front(), pop_front(), push_front(), remove(), remove_if(), reverse(), sort(), splice_after(), unique()  |
|  10| int array[100]                  | size_t size = sizeof(arr)/sizeof(arr[0]);                     |
|  11| bitset                          | Emulates an array of _bool_: all(), any(), count(), flip(), none(), operator[], reset(), set(), size(), test(), to_string()    |
|  12| Trie                            | __Doesn't exist in STL!__ Implement using _map_ & _set_.                 |
|  13| Binary tree                     |                  |

---

## Questions

- Top 100 LeetCode questions asked _(from a Facebook engineer)_: <https://www.teamblind.com/post/New-Year-Gift---Curated-List-of-Top-100-LeetCode-Questions-to-Save-Your-Time-OaM1orEU>

- Top EASY interview questions _(focus on string & arrays)_: <https://leetcode.com/explore/interview/card/top-interview-questions-easy/>

- Top MEDIUM interview questions: <https://leetcode.com/explore/interview/card/top-interview-questions-easy/>

- Top HARD interview questions: <https://leetcode.com/explore/interview/card/top-interview-questions-hard/>

- Curated list of BFS/DFS questions: <https://leetcode.com/list/x5lle9o1/>

- Arden Dertat 28 questions _(from a Microsoft engineer)_: <http://www.ardendertat.com/2012/01/09/programming-interview-questions/>

## Solutions

- Counting sort _(open in Incognito)_: <https://medium.com/free-code-camp/my-favorite-linear-time-sorting-algorithm-f82f88b5daa1>

- How to solve the Knapsack Problem _(open in Incognito)_: <https://medium.com/@fabianterh/how-to-solve-the-knapsack-problem-with-dynamic-programming-eb88c706d3cf>

- Reversing bits (an n-bit number) in O(log n): <https://medium.com/hackernoon/reversing-an-n-bit-number-in-o-log-n-time-9bf69363d452>

- Range Sum with BIT and Segment Trees: <https://medium.com/@harekrishnamahto18/range-sum-and-update-in-arrays-competitive-programming-82ae5039a16f>

  <https://www.geeksforgeeks.org/segment-tree-set-1-sum-of-given-range/>

- Use struct as key in unordered_map in C++ : <https://www.techiedelight.com/use-struct-key-std-unordered_map-cpp/>

- How to check if a number is prime using regular expression: <https://itnext.io/a-wild-way-to-check-if-a-number-is-prime-using-a-regular-expression-4edfb725f895>

## Study guides

- Solution patterns _(open in Incognito)_: <https://medium.com/better-programming/the-ultimate-strategy-to-preparing-for-the-coding-interview-ee9f7eb439f3>

- Algorithm solving techniques: <https://medium.com/@shinjukudev/algorithm-solve-techniques-7e4fd008306f>
