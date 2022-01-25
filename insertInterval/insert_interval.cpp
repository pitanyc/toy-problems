/**
 * LEETCODE 57. Insert Interval
 *
 * https://leetcode.com/problems/insert-interval/
 *
 * You are given an array of non-overlapping intervals intervals where
 * intervals[i] = [starti, endi] represent the start and the end of the
 * ith interval and intervals is sorted in ascending order by starti.
 * You are also given an interval newInterval = [start, end] that
 * represents the start and end of another interval.
 * 
 * Insert newInterval into intervals such that intervals is still sorted
 * in ascending order by starti and intervals still does not have any
 * overlapping intervals (merge overlapping intervals if necessary).
 * 
 * Return intervals after the insertion.
 * 
 * Example 1:
 * 
 * Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
 * Output: [[1,5],[6,9]]
 * 
 * Example 2:
 * 
 * Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * Output: [[1,2],[3,10],[12,16]]
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

// SOLUTION 1: Since intervals is sorted by start time: use binary search
//             to find where the new interval's start time fits in.
//             There can be edge cases:
//              * intervals is empty
//              * new interval is the first (earliest start time)
//              * new interval is the last (last start time)
//
//             The new interval will either be inserted AFTER an existing
//             interval IF new interval start time > existing interval end time,
//             OR it will be merged into the previous interval IF new interval
//             start time <= existing interval end time.
//
//             After finding the insert location: starting at the insert
//             location, iterate thru all existing intervals and compare the
//             end times.  If new interval end time > existing interval
//             end time, then we need to merge this subsequent interval
//             into the newly inserted interval.  Do this until we either
//             run out of intervals, or find an interval whose start time
//             is after our end time.
//
// Time:  O(logn) + O(N) = O(N)
// Space: 
vector<vector<int>> insert(
        vector<vector<int>>& intervals,
        vector<int>& newInterval)
{
    // locals
    int count = intervals.size();
    int newStart = newInterval.at(0);
    int newEnd = newInterval.at(1);

    // binary search intervals until we find the insert location
    int start = 0;
    int end = count - 1;
    int middle = 0;
    bool found = false;
    do
    {
        middle = (start + end) / 2;
        int after = min(middle + 1, count - 1);
        // cout << "start: " << start << ", end: " << end << ", middle: " << middle << ", after: " << after << endl;
        if (intervals[middle][0] <= newStart &&
            newStart <= intervals[after][0])
        {
            // found it
            found = true;
        }
        else if (newStart > intervals[after][0])
        {
            // go right
            start = middle;
        }
        else
        {
            // go left
            end = middle;
        }
    } while (!found && start < end);

    // at this point, we know the new interval will be inserted between middle and after
    cout << "found: " << found << ", middle: " << middle << endl;

    // check if we need to merge new interval with the previous interval
    if (intervals[middle][1] >= newStart)
    {
        // need to merge into previous
        intervals[middle][1] = max(intervals[middle][1], newEnd);
    }
    else
    {
        // insert after previous
        count++;
        intervals.resize(count);
        for (int i = count - 1; i > middle; i--)
        {
            intervals.at(i) = intervals.at(i-1);
        }
        intervals.at(middle + 1) = newInterval;
    }


    // ensure all later intervals are non-overlapping
    bool allGood = false;
    int curr = middle;
    int next = min(middle + 1, count - 1);
    while (!allGood && next < count)
    {
        if (intervals[curr][1] >= intervals[next][0])
        {
            // merge
            intervals[curr][1] = max(intervals[curr][1], intervals[next][1]);
            intervals.erase(intervals.begin() + next);
            count--;
        }
        else
        {
            // all good
            allGood = true;
        }
    }

    return intervals;
}

int main(int argc, const char** argv)
{
    // test case 1
    vector<vector<int>> intervals = {{1,3},{6,9}};
    vector<int> newInterval = {2,5};
    cout << "intervals: " << intervals << endl;
    cout << "newInterval: " << newInterval << endl;
    vector<vector<int>> output = insert(intervals, newInterval);
    cout << "output: " << output << endl;

    // test case 2
    cout << "====" << endl;
    intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    newInterval = {4,8};
    cout << "intervals: " << intervals << endl;
    cout << "newInterval: " << newInterval << endl;
    output = insert(intervals, newInterval);
    cout << "output: " << output << endl;

    return 0;
}