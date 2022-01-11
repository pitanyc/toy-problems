/**
 * LEETCODE 3. Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/
 *
 * Given a string, find the length of the longest substring without
 * repeating characters.
 *
 * Example 1:
 *
 * Input: "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 * 
 * Example 2:
 *
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * Example 3:
 *
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * Note that the answer must be a substring, "pwke" is a subsequence
 * and not a substring.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// SOLUTION:    Keep a vector for the last seen index of the current char.
//
//              This is a static vector<int> v(256) where the index
//              is the character and the value is the last index of it
//              seen in the input string.
//
//              Use a left pointer and catch it up to current pointer - 1
//              whenever we see a repeat char.
//
// Time: O(n)
// Space: O(1)
int lengthOfLongestSubstring(const string& input)
{
    // sanity checks
    if (input.empty())
    {
        return 0;
    }
    
    // what we return
    int returnValue = 0;
    
    // locals
    unsigned int count = input.size();
    vector<int> v(256, -1);     // index of the character last seen in 'input'
    int left = -1;              // left pointer
    for ( int i = 0; i < count; i++ )
    {
        left = max(left, v[input[i]]);  // left points to the last occurrence of this char
        v[input[i]] = i;                // record this index as the new last occurrence for this char
        returnValue = max(returnValue, i - left);   // record the distance between i and left
    }

    // finally return
    return returnValue;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    // test case 1
    string input = "abcabcbb";
    cout << "input: " << input << endl;
    int result = lengthOfLongestSubstring(input);
    cout << "result: " << result << endl;
    
    // test case 2
    cout << "\n====\n" << endl;
    input = "pwwkew";
    cout << "input: " << input << endl;
    result = lengthOfLongestSubstring(input);
    cout << "result: " << result << endl;

    return 0;
}
