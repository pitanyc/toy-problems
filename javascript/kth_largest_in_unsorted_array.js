/**
 Find the kth largest element in an unsorted array. Note that it is the
 kth largest element in the sorted order, not the kth distinct element.

 For example, given [3,2,1,5,6,4] and k = 2, return 5.
 */

// SOLUTION #1: Sort, then jump to k-th index ==> O(nlog(n))
const findKthLargest = (A, k) => {
  // finally return
  return A.sort().reverse()[k - 1];
};

// SOLUTION #2: Use heap ==> O(nlog(n))
const findKthLargestUsingHeap = (A, k) => {
  // what we return
  let returnValue = NaN;

  // consume input

  // finally return
  return returnValue;
};

//// TEST CASES ////

// 1
let A = [3, 2, 1, 5, 6, 4];
let k = 2;
let output = findKthLargest(A, k);
console.log("A: ", A, "\nk: ", k, "\noutput: ", output);

// 2
console.log("====");
output = findKthLargestUsingHeap(A, k);
console.log("A: ", A, "\nk: ", k, "\noutput: ", output);
