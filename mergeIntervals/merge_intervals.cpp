/**
 * LEETCODE 56. Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/
 *
 * Given an array of intervals where intervals[i] = [starti, endi],
 * merge all overlapping intervals, and return an array of the non-overlapping
 * intervals that cover all the intervals in the input.
 * 
 * Example 1:
 * Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
 * 
 * Example 2:
 * 
 * Input: intervals = [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// STREAM OPERATOR ==> vector of int
ostream& operator<<(ostream& os, const vector<int>& arr)
{
    os << "[";
    for ( vector<int>::const_iterator it = arr.begin(); it != arr.end(); it++ )
    {
        os << *it;
        if ( it + 1 != arr.end() )
        {
            os << " ";
        }
    }
    os << "]";
    return os;
}

// STREAM OPERATOR ==> vector of vector of int
ostream& operator<<(ostream &os, const vector<vector<int>>& arr)
{
    os << endl;
    for ( vector<vector<int>>::const_iterator it = arr.begin();
          it != arr.end();
          it++ )
    {
        os << "  " << *it;
        if (it + 1 != arr.end()) os << endl;
    }
    return os;
}

// SOLUTION 1: If the input is sorted, then we can do this in place:
//               * set curr = first interval, next = second interval
//               * check if curr's end time >= next's start time
//               * if so, merge them:
//                   ** curr's end time = max(curr end time, next end time)
//                   ** erase next from the intervals
//               * repeat until we reach the end
//
//             If the input isn't sorted, then we can do one of 2 things:
//               * sort the input array: O(nlogn)
//               * create another (initially empty) 'merged' vector, and
//                 copy the first interval into it.  Iterate thru the input
//                 intervals, and merge each input into the 'merged' vector.
//
// Time:  O(N)
// Space: O(1)
vector<vector<int>> mergeSorted(vector<vector<int>>& intervals)
{
    // locals
    int count = intervals.size();

    // consume input
    for (int i = 0; i < count - 1; i++)
    {
        vector<int>& curr = intervals.at(i);
        vector<int>& next = intervals.at(i + 1);

        // check if need to merge
        if (curr[1] >= next[0])
        {
            // merge next into curr
            curr[1] = max(curr[1], next[1]);
            intervals.erase(intervals.begin() + i + 1);
            count--;
        }
    }

    return intervals;
}

bool myComp(const vector<int>& a, const vector<int>& b)
{
    return a[0] < b[0];
}

// SOLUTION 2: If the input isn't sorted, then we can do one of 2 things:
//               * sort the input array: O(nlogn)
//               * create another (initially empty) 'merged' vector, and
//                 copy the first interval into it.  Iterate thru the input
//                 intervals, and merge each input into the 'merged' vector.
//
// Time:  O(nlogn)
// Space: O(n)
vector<vector<int>> mergeUnSorted(vector<vector<int>>& intervals)
{
    // what we return
    vector<vector<int>> merged(intervals);

    // sort input
    sort(merged.begin(), merged.end(), myComp);

    // locals
    int count = merged.size();

    // consume input
    for (int i = 0; i < count - 1; i++)
    {
        vector<int>& curr = merged.at(i);
        vector<int>& next = merged.at(i + 1);

        // check if need to merge
        if (curr[1] >= next[0])
        {
            // merge next into curr
            curr[1] = max(curr[1], next[1]);
            merged.erase(merged.begin() + i + 1);
            count--;
        }
    }

    return merged;
}

int main(int argc, const char** argv)
{
    // test case 1
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    cout << "intervals: " << intervals << endl;
    vector<vector<int>> output = mergeUnSorted(intervals);
    cout << "output: " << output << endl;

    // test case 2
    cout << "====" << endl;
    intervals = {{4,5},{1,4}};
    cout << "intervals: " << intervals << endl;
    output = mergeUnSorted(intervals);
    cout << "output: " << output << endl;

    return 0;
}