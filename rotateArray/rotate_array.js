/**
 * LEETCODE 189: Rotate Array
 *
 * https://leetcode.com/problems/rotate-array/
 *
 * Rotate an array of n elements to the right by k steps.
 *
 * For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated
 * to [5,6,7,1,2,3,4].
 */
function rotateArray(arr, k) {
  // what we return
  let returnValue = [];

  //  helpers
  let len = arr.length;

  // check rotate direction
  if (k > 0) {
    // rotate right
    k = k % len; // k = [0..len-1]
    for (let i = 0; i < len; i++) {
      returnValue[i] = arr[len - k];
      k--;
      if (k === 0) {
        k = len;
      }
    }
  } else {
    // rotate left
    k *= -1;
    k = k % len; // k = [0..len-1]
    for (let i = 0; i < len; i++) {
      returnValue[i] = arr[k];
      k++;
      if (k === len) {
        k = 0;
      }
    }
  }

  return returnValue;
}

//// TEST CASES ////

// 1
let input = [1, 2, 3, 4, 5, 6, 7];
let output = rotateArray(input, 3);
console.log("in:  ", input, "\nout: ", output);

// 2
console.log("====");
input = [1, 2, 3, 4, 5, 6, 7];
output = rotateArray(input, -3);
console.log("in:  ", input, "\nout: ", output);

// 3
console.log("====");
input = [1, 2, 3, 4, 5, 6, 7];
output = rotateArray(input, -3);
console.log("in:  ", input, "\nout: ", output);
