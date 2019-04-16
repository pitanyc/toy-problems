/**
 At Bloomberg we usually run around finding meeting rooms. In order to
 understand our usage better, we would like to implement a system that
 is checking what is the maximum number of meeting rooms that are
 occupied in parallel. Given a list of start and end times for meetings,
 find the minimum number of rooms required to accomodate all the
 meetings. Another way of thinking about this is to find the maximum
 number of meetings that overlap during some period of time.

 Sample inputs - Expected outputs Array of pairs, and every pair
 represents the start and end of a meeting.

 [(1,2), (3,4)] - 1 as meetings don't overlap
 [(1,5), (3,6), (8,9)] - 2 as Meeting (1,5) and (3,6) overlap
 [(2,5), (4,7), (3,9), (1,5), (10, 20)] - 4 as meetings
 (1,5), (2,5), (3,9), (4,7) overlap
 */

/// SOLUTION
const countMeetingRooms = A => {
  // consume input, store in a datastructure ==> O(n^2), can be O(nlogn)

  // edge cases
  let len = A.length;
  if (len === 0) {
    return 0;
  }

  // locals
  let merged = []; // merged meetings

  // consume input & populate merged array
  let overlapCount = 0;
  A.forEach(meeting => {
    let start = meeting[0];
    let end = meeting[1];

    let inserted = false;
    for (let i = 0; i < merged.length; i++) {
      if (
        (start < merged[i][0] && merged[i][0] < end) ||
        start < merged[i][1]
      ) {
        // overlapping meetings
        // console.log("overlapping: ", meeting);
        // console.log("merged[i][0]: ", merged[i][0]);
        // console.log("merged[i][1]: ", merged[i][1]);

        start = Math.min(start, merged[i][0]);
        end = Math.max(end, merged[i][1]);
        merged.splice(i, 1, [start, end]);
        inserted = true;
        overlapCount++;
        break;
      }
    }

    if (!inserted) {
      merged.push([start, end]);
    }
  });

  // debug
  console.log("merged: ", merged);

  // simply return with merged array count
  return overlapCount + 1;
};

//// TEST CASES ////

// 1
let meetings = [[1, 2], [3, 4]];
console.log("meetings: ", meetings);
let output = countMeetingRooms(meetings);
console.log("output: ", output);

// 2
console.log("====");
meetings = [[1, 5], [3, 6], [8, 9]];
console.log("meetings: ", meetings);
output = countMeetingRooms(meetings);
console.log("output: ", output);

// 3
console.log("====");
meetings = [[2, 5], [4, 7], [3, 9], [1, 5], [10, 20]];
console.log("meetings: ", meetings);
output = countMeetingRooms(meetings);
console.log("output: ", output);
