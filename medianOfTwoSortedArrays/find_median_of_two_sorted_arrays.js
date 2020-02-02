/**
 * LEETCODE 4: Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/
 *  
 * There are two sorted arrays A and B of size m and n respectively. Find
 * the median of the two sorted arrays.
 * 
 * The overall run time complexity should be O(log (m+n)).
 */
const findMedian = (A, B) => {
  // debug
  // console.log("A: ", A, "\nB: ", B);

  // what we return
  let median = NaN;

  // helpers
  const lenA = A.length;
  const lenB = B.length;
  const k = Math.floor((lenA + lenB) / 2);

  // delegate
  if ((lenA + lenB) % 2 === 0) {
    // even count
    median = (findKthElement(A, B, k) + findKthElement(A, B, k - 1)) / 2;
  } else {
    // odd count
    median = findKthElement(A, B, k);
  }

  // finally return
  return median;
};

const findKthElement = (A, B, k) => {
  // debug
  // console.log("k: ", k);

  // helpers
  const lenA = A.length;
  const lenB = B.length;

  // pointers to A & B
  let i = 0;
  let j = 0;
  let isEmptyA = lenA === 0;
  let isEmptyB = lenB === 0;

  // find k-th element
  while (k > 0) {
    // ensure boundaries
    if (i >= lenA && j >= lenB) {
      // shouldn't happen
      console.log("Shouldn't happen");
      break;
    } else if (i >= lenA) {
      // A is done
      j++;
      isEmptyA = true;
    } else if (j >= lenB) {
      // B is done
      i++;
      isEmptyB = true;
    } else {
      // both A & B non-empty
      if (A[i] < B[j]) {
        i++;
      } else if (A[i] === B[j]) {
        i++;
      } else {
        j++;
      }
    }
    k--;
  }

  // finally return
  let returnValue = NaN;
  if (!isEmptyA && !isEmptyB) {
    // return the smaller
    if (A[i] < B[j]) {
      returnValue = A[i];
    } else if (B[j] < A[i]) {
      returnValue = B[j];
    } else {
      returnValue = A[i];
    }
  } else if (isEmptyA) {
    returnValue = B[j - 1];
  } else if (isEmptyB) {
    returnValue = A[i - 1];
  } else {
    // both empty ==> shouldn't happen
    console.log("Shouldn't happen");
  }

  return returnValue;
};

//// TEST CASES ////

// 1
let A = [1, 3, 5, 7];
let B = [2, 4, 6, 8];
let median = findMedian(A, B);
console.log("A: ", A, "\nB: ", B, "\nmedian: ", median);

// 2
A = [1, 3, 5];
B = [2, 4];
median = findMedian(A, B);
console.log("A: ", A, "\nB: ", B, "\nmedian: ", median);
