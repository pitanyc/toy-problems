/**
 * A Round Robin Tournament is a competiton in which every player will
 * face off with every other player in turn. It is widely used in sports
 * tournaments. Let's say we want to produce a round robin tournament
 * schedule for a soccer league that consists of 10 teams. In each turn
 * or round, every team team will play one game. It takes 2 teams to
 * play a game so we have 5 games in each round. After 9 rounds, all
 * teams should have played with all the opponents.
 *
 * The goal is to generate a schedule such that there are no repeated
 * games and all teams will participate in exactly one game in each
 * round.
 *
 * The following describes an algorithm to achieve this.
 *
 * Arrange the teams into 2 lists of equal size. first team on the list
 * will be paired up with the first team on the 2nd list. 2nd team on
 * the list will be paired up with the 2nd team on the 2nd list and so
 * on as illustrated below.
 *
 * 1 2 3 4 5
 * 6 7 8 9 10
 *
 * Round 1 ( 1vs6, 2vs7, 3vs8, 4vs9, 5vs10 )
 * 
 * For the following rounds we rotate the list clockwise but fix the 
 * postion of one team (we use team 1 in this case)
 *
 * 1 3 4 5 10
 * 2 6 7 8 9
 * 
 * Round 2 ( 1vs2, 3vs6, 4vs7, 5vs8, 10vs9 )
 * 
 * We repeat this process til all games are played.
 */

#include <iostream>
#include <vector>

using namespace std;

// STREAM OPERATOR ==> vector of int
std::ostream& operator<<(std::ostream &os, const vector<int>& arr)
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

// Rotates the passed array in place to the left by 1 position.
void rotateArray(vector<int>& arr, int start, bool isLeft)
{
    unsigned int count = arr.size();
    for (int i = start; i < count - 1; i++)
    {
        if ( isLeft )
        {
            // << left
            arr.at(i) = arr.at(i + 1);
        }
        else
        {
            // >> right
            arr.at(count - 1 - i) = arr.at(count - i - 2);
        }
    }
}

// SOLUTION: Generate 2 groups: 
//  
//           group1 = [1..n/2]
//           group2 = [n/2 + 1..n]
//
//           At each round, simply pair up the teams at the same index.
//           Then, rotate the groups clockwise, as requested.
//
// Time:     O(n)
// Space:    O(n)
void generateMatches(int n)
{
    // sanity checks
    if ( n < 2 || (n % 2 == 1) )
    {
        std::cout << "Input: " << n << " is either less than 2 or not even!";
    }

    // at this point, n >= 2 AND is even

    // locals
    int nofRounds = n - 1;
    int half = n / 2;
    vector<int> group1;
    vector<int> group2;

    // create groups
    for (int i = 1; i <= half; i++)
    {
        group1.push_back(i);
        group2.push_back(half + i);
    }

    // debug
    std::cout << "group1: " << group1 << std::endl;
    std::cout << "group2: " << group2 << std::endl;

    // generate rounds
    for ( int i = 1; i <= nofRounds; i++ )
    {
        // print
        std::cout << "-- Round " << i << " --" << std::endl;
        for (int j = 0; j < half; j++)
        {
            std::cout << group1.at(j) << " vs " << group2.at(j) << std::endl;
        }

        // shuffle groups
        // 1 2 3 4 5
        // 6 7 8 9 10
        //
        // 1 3 4 5 10
        // 2 6 7 8 9
        if ( nofRounds > 1 )
        {
            int g1Second = group1.at(1);        // 2
            rotateArray(group1, 1, true);       // 1 3 4 5 5
            int g2Last = group2.at(half - 1);   // 10
            group1.at(half - 1) = g2Last;       // 1 3 4 5 10
            rotateArray(group2, 0, false);      // 6 6 7 8 9
            group2.at(0) = g1Second;            // 2 6 7 8 9
        }

        // debug
        std::cout << "group1: " << group1 << std::endl;
        std::cout << "group2: " << group2 << std::endl;
    }
}

// MAIN
int main(int argc, char const *argv[])
{
    // test case 1
    int n = 6;
    std::cout << "n = " << n << std::endl;
    generateMatches(n);
    
    // test case 2
    // std::cout << "\n====\n" << std::endl;
    // candidates = {2, 3, 5};
    // target = 8;
    // std::cout << "candidates = " << candidates << ", target = " << target << std::endl;
    // output = combinationSum(candidates, target);
    // std::cout << "output: " << output << std::endl;

    return 0;
}