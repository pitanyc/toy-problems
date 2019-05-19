/**
 * Given a string, remove all characters of 3 or more occurrences on it, 
 * ala candy crush.
 * 
 * Example:
 * INPUT: "aabbcccbad"
 * OUTPUT: "d"
 */

#include <iostream>
#include <string>
#include <vector>

// SOLUTION:
//  1) Use a Stack of characters.
//  2) Iterate thru all characters, throw them on the Stack.
//  3) When you encounter 3 or more on top of the Stack, remove them.
//  4) Final answer is whatever remains in the Stack.
//
// TIME: O(N), where N = length of input String
std::string candyCrush(const std::string &input)
{
    // validate input
    unsigned int len = input.length();
    if (len < 3)
    {
        // echo back the input
        return input;
    }

    // if we are here ==> input has at least 3 characters

    // what we return
    std::string returnValue;

    // use a Stack
    std::vector<char> stack;

    // consume input
    char lastChar = input.at(0);
    stack.push_back(lastChar);
    unsigned int count = 1; // counts how many same chars on top of the Stack
    for (unsigned int i = 1; i < len; i++)
    {
        // get next char
        char c = input.at(i);
        if (c == lastChar)
        {
            // same as top of the Stack
            count++;
        }
        else
        {
            // different than top of the Stack
            lastChar = c;

            // crush same characters
            if (count >= 3)
            {
                for (unsigned j = 0; j < count; j++)
                {
                    stack.pop_back();
                }
            }

            // figure out what count should be
            count = 1;
            if (stack.size() > 0)
            {
                char top = stack.back();
                stack.pop_back();
                if (top == c)
                {
                    count++;
                    if (stack.size() > 0)
                    {
                        char next = stack.back();
                        stack.pop_back();
                        if (next == c)
                        {
                            count++;
                        }
                        stack.push_back(next);
                    }
                }
                stack.push_back(top);
            }
        }

        // push to stack
        stack.push_back(c);

        // debug
        // std::cout << "count: " << count << std::endl;
        // std::cout << "stack: [" << std::string(stack.begin(), stack.end()) << "]" << std::endl;
    }

    // check if we have uncrushed items at the end
    if (count >= 3)
    {
        for (unsigned j = 0; j < count; j++)
        {
            stack.pop_back();
        }
    }

    // assemble output
    returnValue = std::string(stack.begin(), stack.end());

    // finally return
    return returnValue;
}

int main(int argc, char const *argv[])
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
