/**
 * LEETCODE 151: Reverse Words in String
 *
 * https://leetcode.com/problems/reverse-words-in-a-string/
 *
 * Given an input string, reverse the string word by word. A word is
 * defined as a sequence of non-space characters.
 *
 * The input string does not contain leading or trailing spaces and the
 * words are always separated by a single space. For example, Given s =
 * "the sky is blue", return "blue is sky the".
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

ostream& operator<<(ostream& os, stack<string> stack)
{
    while ( !stack.empty() )
    {
        string next = stack.top();
        stack.pop();
        os << "'" << next << "'" << endl;
    }
    return os;
}

// SOLUTION: Split incoming string along spaces.
//           Throw the result tokens (words) onto a stack.
//           Consume the stack: build output from the back by
//           consuming what's in it.
//
// Time:  O(N)
// Space: O(N)
string reverseWords(const string& input)
{
    // what we return
    string returnValue;

    // this is our stack that we populate
    stack<string> stack;

    // split input among spaces
    size_t start = 0;
    size_t pos = 0;
    while ( (pos = input.find(" ", start)) != string::npos )
    {
        string word = input.substr(start, pos - start);
        // cout << "word: '" << word << "', start: " << start << ", pos: " << pos << endl;
        stack.push(word);
        start = pos + 1;
    }

    // push last word onto stack
    if ( start != string::npos )
    {
        string word = input.substr(start);
        stack.push(word);
    }
    cout << "stack: " << stack << endl;

    // consume stack, build output
    while ( !stack.empty() )
    {
        returnValue += stack.top();
        stack.pop();
        if ( !stack.empty() ) returnValue += " ";
    }

    return returnValue;
}

// MAIN
int main(int argc, char const *argv[])
{
    // test case 1
    string input = "the sky is blue";
    cout << "input: '" << input << "'" << endl;
    string output = reverseWords(input);
    std::cout << "output: '" << output << "'" << endl;

    return 0;
}
