/**
 * LEETCODE 1. Two Sum
 *
 * https://leetcode.com/problems/two-sum/
 *
 * Given an array of integers, find two numbers such that they add up to a
 * specific target number.
 *
 * The function twoSum should return indices of the two numbers such that
 * they add up to the target, where index1 must be less than index2.
 * Please note that your returned answers (both index1 and index2) are not
 * zero-based. For example:
 *
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=0, index2=1
 */

// SOLUTION
const twoSum = (arr, target) => {
  // use HashMap ==> O(n)

  // edge cases
  const len = arr.length;
  if (len === 0) {
    throw "Empty array was passed!";
  }

  // what we return
  const returnValue = {
    index1: -1,
    index2: -2
  };

  // locals
  const map = new Map();

  // consume array, build map
  arr.forEach((value, index) => {
    map.set(target - value, index);
  });

  // look for matching pair in map, break in first match
  arr.forEach((value, index) => {
    if (map.get(value) > 0) {
      returnValue.index1 = index;
      returnValue.index2 = map.get(value);
      return returnValue;
    }
  });

  // if we are here ==> unable to find 2 indices to map to target
  throw "Unable to find 2 indices that map to target!";
};

// / TEST CASES ///

// 1
let arr = [2, 7, 11, 15];
let target = 9;
console.log("arr: ", arr, ", target: ", target);
let output = twoSum(arr, target);
console.log("output: ", output);

// 2
console.log("====");
arr = [2, 7, 11, 15];
target = 1;
console.log("arr: ", arr, ", target: ", target);
output = twoSum(arr, target);
console.log("output: ", output);
