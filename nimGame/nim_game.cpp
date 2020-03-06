/**
 * LEETCODE 292. Nim Game
 *
 * https://leetcode.com/problems/nim-game/
 *
 * You are playing the following Nim Game with your friend: There is a
 * heap of stones on the table, each time one of you take turns to
 * remove 1 to 3 stones. The one who removes the last stone will be the
 * winner. You will take the first turn to remove the stones.
 *
 * Both of you are very clever and have optimal strategies for the game.
 * Write a function to determine whether you can win the game given the
 * number of stones in the heap.
 *
 * Example:
 * Input: 4
 * Output: false
 * 
 * Explanation: If there are 4 stones in the heap, then you will never 
 * win the game; No matter 1, 2, or 3 stones you remove, 
 * the last stone will always be removed by your friend.
 */

#include <iostream>

// SOLUTION: If the number is divisible by 4, then we CANNOT win the game.
//           Thus, the game is ONLY WINNABLE if n is NOT divisble by 4.
//
// Time: O(1)
// Space: O(1)
bool canWinNim(int n)
{
    if (n < 0 ) return false;
    return (n % 4);
}

// MAIN
int main(int argc, char const *argv[])
{
    // test case 1
    int n = 4;
    bool output = canWinNim(n);
    std::cout << "n: " << n << "\noutput: " << output << std::endl;

    // test case 2
    std::cout << "\n====\n" << std::endl;
    n = 6;
    output = canWinNim(n);
    std::cout << "n: " << n << "\noutput: " << output << std::endl;

    return 0;
}
