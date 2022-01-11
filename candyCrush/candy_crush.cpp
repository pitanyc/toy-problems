/**
 * LEETCODE 723: Candy Crush
 *
 * https://leetcode.com/problems/candy-crush/
 *
 * Given a string, remove all characters of 3 or more occurrences on it,
 * ala candy crush.
 *
 * Example:
 * INPUT: "aabbcccbad"
 * OUTPUT: "d"
 */

#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

std::ostream& operator<<(std::ostream& os, std::stack<char> stack)
{
    std::string string;
    while ( !stack.empty() )
    {
        string += stack.top();
        stack.pop();
    }
    os << string;
    return os;
}

// Helper method to crush candies on the stack.
void crushStack(unsigned int count, std::stack<char>& stack)
{
    if ( count > 2 )
    {
        // crush here
        for ( unsigned j = 0; j < count; j++ )
        {
            stack.pop();
        }
        // std::cout << "stack AFTER CRUSH: " << stack << std::endl;
    }
}

// SOLUTION:
//  1) Use a Stack of characters.
//  2) Iterate thru all characters, throw them on the Stack.
//  3) When you encounter 3 or more on top of the Stack, remove them.
//  4) Final answer is whatever remains in the Stack.
//
// TIME: O(N), where N = length of input String
std::string candyCrush(const std::string& input)
{
    // validate input
    unsigned int len = input.length();
    if ( len < 3 )
    {
        // echo back the input
        return input;
    }

    // if we are here ==> input has at least 3 characters

    std::stack<char> stack;

    char lastChar = input.at(0);
    stack.push(lastChar);
    unsigned int count = 1; // counts how many same chars on top of the Stack
    for ( unsigned int i = 1; i < len; i++ )
    {
        char c = input.at(i);
        if ( lastChar == c )
        {
            // same as last char
            count++;
            stack.push(c);
        }
        else
        {
            // last char different
            crushStack(count, stack);

            // reset lastChar
            lastChar = c;
            stack.push(c);

            // reset count
            count = 1;
            if ( stack.size() > 1 )
            {
                // we have at least 2 elements on the stack
                std::stack<char> tempStack;
                while ( stack.size() && c == lastChar )
                {
                    c = stack.top();
                    stack.pop();
                    tempStack.push(c);
                }

                // count is how many same elements we have in temp stack
                count = tempStack.size();
                if ( !stack.empty() )
                {
                    // top of temp stack contains different character
                    count--;
                }

                // put temp stack back into stack
                while ( !tempStack.empty() )
                {
                    stack.push(tempStack.top());
                    tempStack.pop();
                }
            }
        }
        // std::cout << "stack: " << stack << std::endl;
        // std::cout << "count: " << count << std::endl;
    }

    // check if we need to crush at the end
    crushStack(count, stack);

    // assemble output
    std::string returnValue;
    while ( !stack.empty() )
    {
        returnValue = returnValue + stack.top();
        stack.pop();
    }

    return returnValue;
}

int main(int argc, char const* argv[])
{
    // test case 1
    std::string input = "aabbba";
    std::cout << "input: '" << input << "'" << std::endl;
    std::string output = candyCrush(input);
    std::cout << "output: '" << output << "'" << std::endl;

    // test case 2
    input = "aabbccdddccbba";
    std::cout << "====\ninput: '" << input << "'" << std::endl;
    output = candyCrush(input);
    std::cout << "output: '" << output << "'" << std::endl;

    // test case 3
    input = "aabbcccbaed";
    std::cout << "====\ninput: '" << input << "'" << std::endl;
    output = candyCrush(input);
    std::cout << "output: '" << output << "'" << std::endl;

    return 0;
}
