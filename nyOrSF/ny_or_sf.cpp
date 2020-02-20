/**
 * Let's suppose Bloomberg is sponsoring a coding competition at its New
 * York and San Francisco offices. We will have to fly the participants
 * to either one of these two offices. Each office can only accommodate
 * half of the participants. The goal is to assign each participant to
 * an office in a way that the total travel cost for the company is
 * minimized. Each participant will be represented as a pair of costs:
 * <costToFlyToNY, costToFlyToSF>. Determine the minimum cost given a
 * list of participants.
 *
 * Example:
 *
 * <500, 600>,
 * <600, 400>,
 * <200, 900>,
 * <700, 300>
 * Output: 1400
 *  With only 4 participants, 2 must fly to SF and 2 must fly to NY
 */

#include <iostream>
#include <vector>

using namespace std;

class Participant
{
    public:
        int d_cost_to_ny;
        int d_cost_to_sf;

        Participant(int to_ny, int to_sf)
        {
            d_cost_to_ny = to_ny;
            d_cost_to_sf = to_sf;
        }

        friend bool operator<(const Participant& a,
                              const Participant& b) //true if a is less than b
        {
            if (abs(a.d_cost_to_ny - a.d_cost_to_sf) < abs(b.d_cost_to_ny - b.d_cost_to_sf))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};

// STREAM OPERATOR ==> vector of int
std::ostream& operator<<(std::ostream& os, const vector<int>& arr)
{
    os << "[";
    for (vector<int>::const_iterator it = arr.begin();
         it != arr.end();
         it++)
    {
        os << *it;
        if (it + 1 != arr.end())
        {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

// STREAM OPERATOR ==> vector of Participant
std::ostream& operator<<(std::ostream& os, const vector<Participant>& arr)
{
    os << std::endl;
    for (vector<Participant>::const_iterator it = arr.begin();
         it != arr.end();
         it++)
    {
        os << "<" << it->d_cost_to_ny << ", " << it->d_cost_to_sf << ">";
        if (it + 1 != arr.end())
        {
            os << "," << std::endl;
        }
    }
    return os;
}

// SOLUTION: Idea is to sort the participants based on the difference
//           between flying to NY vs flying to SF.
//
//           Starting with the BIGGEST differences, pick the smaller amount.
//           Keep doing this until either one of the offices has reached max
//           capacity, or we reached the end of our input participants vector.
//
// Time:    O(n)
// Space:   O(n)
int getMinCost(const vector<Participant>& p)
{
    // sanity checks
    unsigned int count = p.size();
    if (count == 0)
    {
        // nothing to do
        return 0;
    }

    // what we return
    int returnValue = 0;

    // locals
    vector<Participant> sorted(p.begin(), p.end());
    std::sort(sorted.begin(), sorted.end());
    std::reverse(sorted.begin(), sorted.end());

    // debug
    std::cout << "sorted: " << sorted << std::endl;

    // local counters
    unsigned int nyCount = 0;
    unsigned int sfCount = 0;
    unsigned int NY_MAX = count / 2;
    unsigned int SF_MAX = count / 2;
    if ( count % 2 == 1 )
    {
        // odd participant count ==> increase one of the office capacities
        NY_MAX++;
    }

    // consume sorted, pick smaller amount
    for ( unsigned int i = 0; i < count; i++ )
    {
        const Participant& participant = sorted.at(i);
        if ( participant.d_cost_to_ny < participant.d_cost_to_sf )      // NY cheaper
        {
            if ( nyCount < NY_MAX )
            {
                // we have NY capacity
                returnValue += participant.d_cost_to_ny;
                nyCount++;
            }
            else
            {
                // we don't have NY capacity ==> must use SF
                returnValue += participant.d_cost_to_sf;
                sfCount++;
            }
        }
        else if ( participant.d_cost_to_ny > participant.d_cost_to_sf ) // SF cheaper
        {
            if ( sfCount < SF_MAX )
            {
                // we have SF capacity
                returnValue += participant.d_cost_to_sf;
                sfCount++;
            }
            else
            {
                // we don't have SF capacity ==> must use NY
                returnValue += participant.d_cost_to_ny;
                nyCount++;
            }
            
        }
        else if ( participant.d_cost_to_ny == participant.d_cost_to_sf )    // same cost
        {
            // use whoever has capacity, prefer NY over SF
            if ( nyCount < NY_MAX )
            {
                // we have NY capacity
                returnValue += participant.d_cost_to_ny;
                nyCount++;
            }
            else
            {
                // we have SF capacity
                returnValue += participant.d_cost_to_sf;
                sfCount++;
            }
        }
    }

    // debug
    std::cout << "nyCount: " << nyCount << ", sfCount: " << sfCount << std::endl;

    // finally return
    return returnValue;
}

// MAIN
int main(int argc, char const* argv[])
{
    // test case 1
    vector<Participant> p;
    p.push_back(Participant(700, 300));
    p.push_back(Participant(500, 600));
    p.push_back(Participant(600, 400));
    p.push_back(Participant(200, 900));
    std::cout << "participants = " << p << std::endl;
    int minCost = getMinCost(p);
    std::cout << "minCost: " << minCost << std::endl;

    // test case 2
    std::cout << "\n====\n" << std::endl;
    p.clear();
    p.push_back(Participant(1,   100));
    p.push_back(Participant(2,   200));
    p.push_back(Participant(3,   300));
    p.push_back(Participant(4,   400));
    std::cout << "participants = " << p << std::endl;
    minCost = getMinCost(p);
    std::cout << "minCost: " << minCost << std::endl;

    return 0;
}