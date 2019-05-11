/**
 * Given an array nums, write a function to move all 0's to the end of
 * it while maintaining the relative order of the non-zero elements.
 *
 * For example, given nums = [0, 1, 0, 3, 12], after calling your
 * function, nums should be [1, 3, 12, 0, 0].
 */

// SOLUTION: in place, using O(2N) = O(N)
const moveZeroes = A => {
  // find first zero
  let left = 0;
  let right = 1;
  let len = A.length;
  while (right < A.length) {
    while (left < len && A[left] !== 0) left++;

    // sanity check
    if (left === A.length) break;

    // at this point we have first zero at index left
    // ==> find first non-zero
    while (right < A.length && A[right] === 0) right++;

    // sanity check
    if (right === A.length) break;

    // now swap left & right
    A[left] = A[right];
    A[right] = 0;

    // move left & right pointers
    left++;
    right++;
  }
};

// TEST CASES
let case1 = [0, 1, 0, 3, 12];
console.log("case1: ", case1);
moveZeroes(case1);
console.log("output: ", case1);

console.log("====");
let case2 = [0, 0, 0, 3, 12];
console.log("case2: ", case2);
moveZeroes(case2);
console.log("output: ", case2);
