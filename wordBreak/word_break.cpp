/**
 * LEETCODE 139. Word Break
 *
 * https://leetcode.com/problems/word-break/
 *
 * Given a non-empty string s and a dictionary wordDict containing a
 * list of non-empty words, determine if s can be segmented into a
 * space-separated sequence of one or more dictionary words.
 *
 * Note:
 *
 * The same word in the dictionary may be reused multiple times in the
 * segmentation. You may assume the dictionary does not contain
 * duplicate words.
 * 
 * Example 1:
 * Input: s = "leetcode", wordDict = ["leet", "code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet
 * code".
 * 
 * Example 2:
 * Input: s = "applepenapple", wordDict = ["apple", "pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as
 * "apple pen apple". Note that you are allowed to reuse a dictionary
 * word.
 * 
 * Example 3:
 * Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and",
 * "cat"]
 * Output: false
 */

#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

// STREAM OPERATOR ==> vector of string
std::ostream& operator<<(std::ostream &os, const vector<string>& arr)
{
    os << "[";
    for ( vector<string>::const_iterator it = arr.begin();
          it != arr.end();
          it++ )
    {
        os << "\"" << *it << "\"";
        if (it + 1 != arr.end()) os << ", ";
    }
    os << "]";
    return os;
}


// PSEUDO CODE:
//
// BacktrackingProcedure(someVector, dimension)
// {
//   if(someVector==isSolution)
//     PrintSolution OR StoreSolution
//   else
//     CheckAllPromisingCandidates(i)
//     {
//       someVector addPromissingCandidate(i);
//       checkIfCandidatePromising(i);
//       BacktrackingProcedure(temporatyVector, increaseDimenzsionOfVector);
//     }
// }
void wordBreakBacktrack(
        const string& s,
        const set<string>& words,
        string& word,
        int start,
        int end,
        bool& returnValue)
{
    // check for next word
    if ( words.count(word) > 0 )
    {
        // cout << "111 start: " << start << ", word: " << word << endl;
        start += word.length();
        end = start + 1;
        word.clear();

        // check for solution
        if ( start == s.length() )
        {
            returnValue = true;
            return;
        }
    }

    // look for next word, from 'start' to end of the string
    // cout << "start: " << start << ", end: " << end << ", word: " << word << endl;
    for ( unsigned int i = end; i <= s.length(); i++ )
    {
        word = s.substr(start, i - start);
        wordBreakBacktrack(s, words, word, start, i + 1, returnValue);
        if ( returnValue )
        {
            // break out at the first solution
            break;
        }
    }
}

// SOLUTION: Use backtracking, stop either when we fully consumed the input
//           string, OR we have reached the end of it.
// 
//           For faster O(1) lookups, throw the words in wordDict into a set
//           upfront.
//
// Time:    O(S^3) --> S = length of s
// Space:   O(N)   --> N = wordDict size
bool wordBreak(string s, vector<string>& wordDict)
{
    // sanity checks
    if ( s.empty() )
    {
        return false;
    }

    // at this point, s is non-empty

    // locals
    set<string> words(wordDict.begin(), wordDict.end());    // what's on the menu
    string word;                // what we are building next
    bool returnValue = false;   // what we return

    // delegate to backtracker
    wordBreakBacktrack(s, words, word, 0, 1, returnValue);

    return returnValue;
}

int main(int argc, char const *argv[])
{
    // test case 1
    std::string input = "leetcode";
    std::vector<string> wordDict = {"leet", "code"};
    std::cout << "input: \"" << input << "\", wordDict: " << wordDict << std::endl;
    bool output = wordBreak(input, wordDict);
    std::cout << "output: " << (output ? "true" : "false") << std::endl;

    // test case 2
    std::cout << "\n====\n" << std::endl;
    input = "applepenapple";
    wordDict = {"apple", "pen"};
    std::cout << "input: \"" << input << "\", wordDict: " << wordDict << std::endl;
    output = wordBreak(input, wordDict);
    std::cout << "output: " << (output ? "true" : "false") << std::endl;

    // test case 3
    std::cout << "\n====\n" << std::endl;
    input = "catsandog";
    wordDict = {"cats", "dog", "sand", "and", "cat"};
    std::cout << "input: \"" << input << "\", wordDict: " << wordDict << std::endl;
    output = wordBreak(input, wordDict);
    std::cout << "output: " << (output ? "true" : "false") << std::endl;

    // test case 4
    std::cout << "\n====\n" << std::endl;
    input = "bloombergisfun";
    wordDict = {"bloom","bloomberg","is","fun"};
    std::cout << "input: \"" << input << "\", wordDict: " << wordDict << std::endl;
    output = wordBreak(input, wordDict);
    std::cout << "output: " << (output ? "true" : "false") << std::endl;

    return 0;
}
