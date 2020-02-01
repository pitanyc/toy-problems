/**
 * LEETCODE 151: Reverse Words in String
 *
 * https://leetcode.com/problems/reverse-words-in-a-string/
 *
 * Given an input string, reverse the string word by word. A word is
 * defined as a sequence of non-space characters.
 *
 * The input string does not contain leading or trailing spaces and the
 * words are always separated by a single space. For example, Given s =
 * "the sky is blue", return "blue is sky the".
 */

// SOLUTION #1: WITH STACK
const reverseWords = input => {
  // what we return
  let returnValue = "";

  // parse input, throw words into a Stack
  const stack = [];
  const tokens = input.split(" ");
  tokens.forEach(token => {
    if (token.length > 0) stack.push(token); // trim spaces before & after?
  });

  // iterate thru stack, build output
  stack.reverse().forEach(word => {
    returnValue += word + " ";
  });
  returnValue = returnValue.trim();

  // finally return
  return returnValue;
};

// SOLUTION #2: IN PLACE
const noStackReverseWords = input => {
  // what we return
  let returnValue = "";

  // reverse input
  input = input
    .split("")
    .reverse()
    .join("");
  console.log(input);

  returnValue = input
    .split(" ")
    .map(word => {
      return word
        .split("")
        .reverse()
        .join("");
    })
    .join(" ");

  // finally return
  return returnValue;
};

//// TEST CASES ////

// 1
let input = "the sky is blue";
let output = noStackReverseWords(input);
console.log("in:  <" + input + ">\nout: <" + output + ">");

// 2
console.log("====");
input = "  welcome to Florida!";
output = noStackReverseWords(input);
console.log("in:  <" + input + ">\nout: <" + output + ">");
