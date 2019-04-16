/**
 Evaluate the value of an arithmetic expression in Reverse Polish
 Notation. Valid operators are +, -, *, /. Each operand may be an
 integer or another expression.

 For example:
 ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/

// SOLUTION #1: WITH STACK
const evaluatePolishNotation = input => {
  // debug
  console.log("input: ", input);

  // create stack & helpers
  const stack = [];

  // digest input
  input.forEach(letter => {
    switch (letter) {
      case "+": {
        const op1 = stack.pop();
        const op2 = stack.pop();
        stack.push(op2 * 1 + op1 * 1);
        break;
      }
      case "-": {
        const op1 = stack.pop();
        const op2 = stack.pop();
        stack.push(op2 * 1 - op1 * 1);
        break;
      }
      case "*": {
        const op1 = stack.pop();
        const op2 = stack.pop();
        stack.push(op2 * 1 * op1 * 1);
        break;
      }
      case "/": {
        const op1 = stack.pop();
        const op2 = stack.pop();
        stack.push((op2 * 1) / (op1 * 1));
        break;
      }
      default:
        stack.push(letter);
        break;
    }
  });

  // debug
  // console.log(stack);

  // finally return
  return stack.pop();
};

//// TEST CASES ////

// 1
let input = ["2", "1", "+", "3", "*"];
let output = evaluatePolishNotation(input);
console.log("in:  ", input, "\nout: ", output);

// 2
console.log("====");
input = ["4", "13", "5", "/", "+"];
output = evaluatePolishNotation(input);
console.log("in:  ", input, "\nout: ", output);
