# toy-problems

Coding exercises

    string input;
    while (getline(cin, input))
    {
        cout << "input: " << input << endl;
        string output = candyCrush(input);
        cout << "output: " << output << endl;
        cout << "\n====\n" << endl;
    }

    ostream& operator<<(ostream &os, const vector<int>& arr)
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

## Patterns

1. If the given input is __unsorted _(array, string)_ &rarr;__  check if sorting it helps.

2. If the given input is __sorted _(array, string, list, or matrix)_ &rarr;__ use __Binary Search__ or __Two Pointers__ strategy.

3. If we need to find a __continuous/contiguous subarray &rarr;__ __Sliding Window__: add elements on the right, and remove them from the left.

4. If we need __top/maximum/minimum/closest k elements among N elements &rarr;__ use a __Heap__.

5. If we need to try all combinations (or permutations) of the input, then use recursive __Backtracking__.

6. Questions on Trees & Graphs can be solved through __BFS__ or __DFS__.

7. Every recursive solution can be converted to an iterative solution using a __Stack__.

8. If there is a solution in O(n^2) time and O(1) space, then there are 2 other solutions:
   - Use a __Map__ or __Set__ for O(1) time and O(n) space
   - Use __sorting__ for O(n logn) time and O(1) space

9. If the problem is asking for optimization (eg: maximize or minimize something), then use __Dynamic Programming__.

10. If we need to find some common substring among a set of strings, then use a __HashMap__ or a __Trie__.

11. If we need to search among a bunch of strings, then use a __Trie__.

12. If the problem is a __Linked List & we cannot use extra space &rarr;__ use __Fast & Slow__ pointers.

    <https://medium.com/better-programming/the-ultimate-strategy-to-preparing-for-the-coding-interview-ee9f7eb439f3>

13. __Sliding window Dynamic Programming__ questions can be solved using __Fast & Slow__ pointer approach:
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

|   #| Name                                | Methods                                              |
| --:|-------------------------------------|------------------------------------------------------|
|   1| vector                              | _back(), front(), pop_back(), push_back(), resize()_ |
|   2| map<br/>unordered_map<br/>multimap  | _clear(), count(), empty(), erase(), find(), operator[]_       |
|   3| set<br/>unordered_set<br/>multiset) | _clear(), count(), empty(), erase(), insert(), find(), lower_bound(), upper_bound()_ |
|   4| stack                               | _empty(), pop(), push(), size(), top()_              |
|   5| queue                               | _back(), empty(), front(), pop(), push(), size()_    |
|   6| priority_queue                      | _empty(), pop(), push(), size(), top()_              |
|   7| dequeue                             | _back(), clear(), empty(), erase(), front(), pop_back(), pop_front(), push_back(), push_front(), size()_ |
|   8| list                                | _back(), clear(), empty(), erase(), front(), pop_back(), pop_front(), push_back(), push_front(), remove(), remove_if(), reverse(), size(), sort(), splice(), unique()_  |
|   9| forward_list                        | _empty(), erase_after(), front(), pop_front(), push_front(), remove(), remove_if(), reverse(), sort(), splice_after(), unique()_ |
|  10| int array[100]                      | size_t size = sizeof(arr)/sizeof(arr[0]);            |
|  11| bitset                              | Emulates an __array of bool__: _all(), any(), count(), flip(), none(), operator[], reset(), set(), size(), test(), to_string()_ |
|  12| Trie                                | __Doesn't exist in STL!__ Implement using _map_ & _set_. |
|  13| Binary tree                         |                  |
|  14| Vector heap methods                 | _make_heap(), push_heap(), pop_heap(), front(), is_heap(), is_heap_until(), sort_heap()_  |

---

## Questions

- Top 100 LeetCode questions asked _(from a Facebook engineer)_: <https://www.teamblind.com/post/New-Year-Gift---Curated-List-of-Top-100-LeetCode-Questions-to-Save-Your-Time-OaM1orEU>

- Top EASY interview questions _(focus on string & arrays)_: <https://leetcode.com/explore/interview/card/top-interview-questions-easy/>

- Top MEDIUM interview questions: <https://leetcode.com/explore/interview/card/top-interview-questions-easy/>

- Top HARD interview questions: <https://leetcode.com/explore/interview/card/top-interview-questions-hard/>

- Curated list of BFS/DFS questions: <https://leetcode.com/list/x5lle9o1/>

- Arden Dertat 28 questions _(from a Microsoft engineer)_: <http://www.ardendertat.com/2012/01/09/programming-interview-questions/>

- System design interview questions with solutions: <https://github.com/donnemartin/system-design-primer#system-design-interview-questions-with-solutions>

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
