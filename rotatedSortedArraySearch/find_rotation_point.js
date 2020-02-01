/**
 * LEETCODE 33: Search in Rotated Sorted Array
 
 https://leetcode.com/problems/search-in-rotated-sorted-array/

 I have an array of words that are mostly alphabetical, except they
 start somewhere in the middle of the alphabet, reach the end, and then
 start from the beginning of the alphabet. In other words, this is an
 alphabetically ordered array that has been "rotated." For example:

  const words = [
    'ptolemaic',
    'retrograde',
    'supplant',
    'undulate',
    'xenoepist',
    'asymptote',  // <-- rotates here! 'babka', 'banoffee',
    'engender',
    'karpatka',
    'othellolagkage',
];
 */

//// SOLUTION ////
const findRotationPoint = A => {
  // double binary search ==> O(nlogn)

  // edge cases
  let len = A.length;
  if (len === 0) {
    return NaN;
  } else if (len === 1) {
    return A[0];
  }

  // at this point A contains at least 2 words

  // locals
  let current = 1;
  let prev = 0;

  // double until current is smaller than prev
  while (A[prev] < A[current] && current < len) {
    prev = current;
    current *= 2;
  }

  // ensure current is within bounds
  current = Math.min(current, len - 1);

  // at this point, perform binary search between prev..current
  while (current !== prev + 1) {
    let middle = (prev + current) / 2;
    if (A[prev] < A[middle]) {
      prev = middle;
    } else if (A[prev] === A[middle]) {
      // duplicates in array ==> return
      return A[middle];
    } else {
      current = middle;
    }
  }

  // simply return
  return A[current];
};

//// TEST CASES ////

// 1
let words = [
  "ptolemaic",
  "retrograde",
  "supplant",
  "undulate",
  "xenoepist",
  "asymptote", // <-- rotates here! 'babka', 'banoffee',
  "engender",
  "karpatka",
  "othellolagkage"
];
let output = findRotationPoint(words);
console.log("words: ", words, "\noutput: ", output);

// 2
console.log("====");
words = [];
output = findRotationPoint(words);
console.log("words: ", words, "\noutput: ", output);

// 2
console.log("====");
words = ["111", "b", "c", "d", "a", "asdf"];
output = findRotationPoint(words);
console.log("words: ", words, "\noutput: ", output);
