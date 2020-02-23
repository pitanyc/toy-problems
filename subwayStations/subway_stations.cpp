/**
 * LEETCODE 200. Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number
 * of islands. An island is surrounded by water and is formed by
 * connecting adjacent lands horizontally or vertically. You may assume
 * all four edges of the grid are all surrounded by water.
 *
 * Example 1:
 *
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 * Output: 1
 * 
 * Example 2:
 *
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 * Output: 3
 */

#include <iostream>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>

using namespace std;

// Datastructures
struct StationPair
{
    string from;
    string to;

    bool operator<(const StationPair& another) const
    {
        return from < another.from;
    }
};

struct StationStat
{
    int totalTime;
    int riderCount;
    double averageTime;
};

typedef unordered_map<int, pair<string, int>> RiderMap;
typedef map<StationPair, StationStat> StatMap;

// holds the current riders in the subway
RiderMap riderMap;

// holds the stats between station pairs
StatMap statMap;

void swipeIn(const string& station, int userId, int time)
{
    // sanity checks
    if (riderMap.count(userId) > 0)
    {
        // user already riding ==> override existing entry
        // could do some alerting here?
    }

    // add user to the riders
    riderMap[userId] = make_pair(station, time);
}

void swipeOut(const string& station, int userId, int time)
{
    // sanity checks
    if ( !riderMap.count(userId) )
    {
        // user swiping out but never swiped in
        // could do some alerting here?

        // ignore this user
        return;
    }

    // locals
    const string from = riderMap[userId].first;
    int startTime = riderMap[userId].second;

    // create stationPair
    StationPair stationPair;
    stationPair.from = from;
    stationPair.to = station;

    // create stationStat
    StationStat stat;
    if ( statMap.count(stationPair) > 0 )
    {
        // this station pair is already in the map ==> update it
        stat = statMap[stationPair];
        stat.totalTime += (time - startTime);
        stat.riderCount++;
        stat.averageTime = (double)stat.totalTime / (double)stat.riderCount;
    }
    else
    {
        // this pair not NOT YET in the map ==> create it now
        stat.totalTime = (time - startTime);
        stat.riderCount = 1;
        stat.averageTime = (double)(time - startTime);
    }
    statMap[stationPair] = stat;
}

void printStats()
{
    for (StatMap::const_iterator it = statMap.begin();
         it != statMap.end();
         it++)
    {
        const StationPair& stationPair = it->first;
        const StationStat& stationStat = it->second;
        cout << stationPair.from << " --> " << stationPair.to << ": " << stationStat.averageTime << endl;
    }
}

int main()
{
    swipeIn("GHC", 1, 100);
    swipeIn("96", 2, 101);
    swipeIn("96", 4, 103);
    swipeIn("86", 3, 105);
    swipeOut("42", 1, 106);
    swipeOut("42", 2, 108);
    swipeOut("42", 4, 108);

    printStats();

    return 0;
}