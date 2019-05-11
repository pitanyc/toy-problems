# Problems

## 1. Strings

* __Is Unique:__ Implement an algorithm to determine if a string has all unique characters.
* __Check Permutation:__ Given 2 strings, write a method to decide if one is a permutation of the other.
* __URLify:__ Write a method to replace all spaces in a string with '%20'.  You may assume that the string has sufficient space at the end to hold the additional characters, and that you are given the "true" length of the string.
  * _EXAMPLE_
  * INPUT:  "Mr John Smith       ", 13
  * OUTPUT: "Mr%20John%20Smith%20", 13
* __Palindrome Permutation:__ Given a string, write a function to check if it is a permutation of a palindrome.  A permutation is a rearrangement of letters.
* __One Way:__ There are 3 types of edits that can be performed on strings: (1) insert a character, (2) remove a character, (3) replace a character.  Given 2 strings, write a function to check if they are one or zero edits away.
  * _EXAMPLE_
  * pale, ple &rarr; true
  * pales, pale &rarr; true
  * pale, bale &rarr; true
  * pale, bake &rarr; false
* __String Compression:__ Implement a method to perform basic string compression using the counts of repeated characters.  For example, the string aabcccccaaa would become a2b1c5a3.  If the "compressed" string would not become smaller than the original string, your method should return the original string.  You can assume the string has only uppercase & lowercase letters (a - z).
* __Rotate Matrix:__ Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees.  Can you do this in place?
* __Zero Matrix:__ Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are set to 0.
* __String Rotation:__ Assume you have a method isSubstring() which checks if one  word is a substring of another.  Given 2 strings, s1 and s2, write code to check if s2 is a rotation of s1 using only one call to isSubstring.
  * _EXAMPLE_
  * "waterbottle" is a rotation of "erbottlewat"

## 2. Linked Lists

* __Remove Duplicates:__ Write code to remove duplicates from an unsorted linked list.
* __Return Kth to Last:__ Implement an algorithm to find the k-th to last element of a singly linked list.
* __Delete Middle Node:__ Implement an algorithm to delete a node in the middle of a singly linked list, given only access to that node.
  * _EXAMPLE_
  * INPUT:  1 &rarr; 2 &rarr; 3 &rarr; 4 &rarr; 5
  * OUTPUT: 1 &rarr; 2 &rarr; 4 &rarr; 5
* __Partition:__ Write code to partition a linked list around a value X, such that all nodes less than X come before all nodes greater than or equal to X.  If X is contained in the list, the values of X only need to be after the elements less than X.
  * _EXAMPLE_
  * INPUT:  3 &rarr; 5 &rarr; 8 &rarr; 5 &rarr; 10 &rarr; 2 &rarr; 1 [partition = 5]
  * OUTPUT: 3 &rarr; 1 &rarr; 2 &rarr; 10 &rarr; 5 &rarr; 5 &rarr; 8
* __Sum Lists:__ You have two numbers represented by a linked list, where each node contains a single digit.  The digits are stored in _reverse_ order, such that the 1's digit is at the head of the list.  Write a function that adds the two numbers and returns the sum as a linked list.
  * _EXAMPLE_
  * INPUT:  (7 &rarr; 1 &rarr; 6) + (5 &rarr; 9 &rarr; 2).  That is, 617 + 295.
  * OUTPUT: (2 &rarr; 1 &rarr; 9).  That is, 912.
  * _FOLLOW UP EXAMPLE_
  * INPUT:  (6 &rarr; 1 &rarr; 7) + (2 &rarr; 9 &rarr; 5).  That is, 617 + 295.
  * OUTPUT: (9 &rarr; 1 &rarr; 2).  That is, 912.
* __Palindrome:__ Implement a function to check if a linked list is a palindrome.
* __Intersection:__ Given 2 singly linked lists, determine if the two lists intersect.  Return the intersecting node.  Note that the intersection is defined based on reference, not value.  That is, if the k-th node the first linked list is the exact same node (by reference) as the j-th node of the second linked list, then they are intersecting.
* __Loop Detection:__ Given a circular linked list, implement an algorithm that returns the node at the beginning of the loop.
  * _EXAMPLE_
  * INPUT:  A &rarr; B &rarr; C &rarr; D &rarr; E &rarr; C (the same C as earlier)
  * OUTPUT: C

## 3. Stacks and Queues

* __Three In One:__ Describe how you could use a single array to implement 3 stacks.
* __Stack Min:__ How would you design a stack which, in addition to push() and pop(), has a function min() which returns the minimum element?  Push(), pop() and min() should all operate in O(1) time.
* __Stack of Plates:__ Imagine a (literal) stack of plates.  If the stack gets too high, it might topple.  Therefore, in real life, we would likely start a new stack when the previous stack exceeds some threshold.  Implement a data structure __SetOfStacks__ that mimics this.  __SetOfStacks__ should be composed of several stacks and should create a new stack once the previous once exceeds capacity.  __SetOfStacks.push()__ and __SetOfStacks.pop()__ should behave identically to a single stack (that is, pop() should return the same values as it would if there were just a single stack).
  * _FOLLOW UP_
  * Implement a function __popAt(int index)__ which performs a pop operation on a specific sub-stack.
* __Queue via Stacks:__ Implement a __MyQueue__ class which implements a queue using 2 stacks.
* __Sort Stack:__ Write a program to sort a stack such that the smallest items are on the top.  You can use an additional temporary stack, but you may not copy the elements into any other data structure (such as an array).  The stack supports the following operations: __push, pop, peek, and isEmpty__.
* __Animal Shelter:__ An animal shelter, which holds only dogs & cats, operates on a strictly "first in, first out" basis.  People must adopt either the "oldest" (based on arrival time) or all animals at the shelter, or they can select whether they would prefer a dog or a cat (and will receive the oldest animal of that type).  They cannot select which specific animal they would like.  Create the data structures to maintain this system and implement operations such as enqueue, dequeueAny, dequeueDog, and dequeueCat.  You may use the built-in __LinkedList__ data structure.

## 4. Trees and Graphs

* __Route Between Nodes:__ Given a directed graph, design an algorithm to find out whether there is a route between 2 nodes.
* __Minimal Tree:__ Given a sorted (increasing order) array with unique integer elements, write an algorithm to create a binary search tree with minimal height.
* __List of Depths:__ Given a binary tree, design an algorithm which creates a linked list of all the nodes at each depth (eg: if you have a tree with depth D, you'll have D linked lists).
* __Checked Balanced:__ Implement a function to check if a binary tree is balanced.  For the purposes of this question, a balanced tree is defined to be a tree such that the height of the two subtrees of any node never differ by more than one.
* __Validate BST:__ Implement a function to check if a binary tree is a binary search tree.
* __Successor:__ Write an algorithm to find the "next" node (ie: in-order successor) or a given node in a binary search tree.  You may assume that each node has a link to its parent.
* __Build Order:__ You are given a list of projects and a list of dependencies (which is a list of pairs of projects, where the first project is dependent on the second project).  All of a project's dependencies must be built before the project is.  Find a build order that will allow the projects to be built.  If there is no valid build order, return an error.
  * _EXAMPLE_
  * INPUT:
    * projects: a, b, c, d, e, f
    * dependencies: (d, a), (b, f), (d, b), (a, f), (c, d)
  * OUTPUT: f, e, a, b, d, c
* __First Common Ancestor:__ Design an algorithm and write code to find the first common ancestor of two nodes in a binary tree.  Avoid storing additional nodes in a data structure.  NOTE: This is not necessarily a binary search tree.
* __BST Sequences:__ A binary search tree was created by traversing through an array from left to right and inserting each element.  Given a binary search tree with distinct elements, print all possible arrays that could have led to this tree.
  * _EXAMPLE_
  * INPUT:  2 &rarr; 1, 2 &rarr; 3
  * OUTPUT: {2, 1, 3}, {2, 3, 1}
* __Check Subtree:__ T1 and T2 are 2 very large binary trees, with T1 much bigger than T2.  Create an algorithm to determine if T2 is a subtree of T1.  A tree T2 is a subtree of T1 if there exists a node __n__ in T1 such that the subtree of __n__ is identical to T2.  That is, if you cut off the tree at node __n__, the two trees would be identical.
* __Random Node:__  You are implementing a binary tree class from scratch which, in addition to _insert_, _find_, and _delete_, has a method _getRandomNode()_ which returns a random node from the tree.  All nodes should be equally likely to be chosen.  Design and implement an algorithm for _getRandomNode()_, and explain how you would implement the rest of the methods.
* __Paths with Sum:__ You are given a binary tree in which each node contains an integer value (which might be positive or negative).  Design an algorithm to count the number of paths that sum to a given value.  The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

## 5. Bit Manipulation

* __5.1 Insertion:__ You are given two 32-bit numbers, __N__ and __M__, and two bit positions, __i__ and __j__.  Write a method to insert __M__ into __N__ such that __M__ starts at bit __j__ and ends at bit __i__.  You can assume that the bits __j__ through __i__ have enough space to fit all of __M__.  That is, if __M = 10011__, you can assume that there are at least 5 bits between __j__ and __i__.  You would not, for example, have __j = 3__, and __i = 2__, because __M__ could not fully fit between bit 3 and bit 2.
  * _EXAMPLE_
  * INPUT: N = 10000000000, M = 10011, i = 2, j = 6
  * OUTPUT: N = 10001001100
* __5.2 Binary to String:__ Given a real number between 0 and 1 (eg: 0.72), that is passed in as a double, print the binary representation.  If the number cannot represented accurately in binary with at most 32 characters, print "ERROR".
* __5.3 Flip Bit to Win:__ You have an integer and you can flip exactly one bit from a __0__ to a __1__.  Write code to find the length of the longest sequence of 1s you could create.
  * _EXAMPLE_
  * INPUT: 1775 (or: 11011101111)
  * OUTPUT: 8
* __5.4 Next Number:__ Given a positive integer, print the next smallest and the next largest number that have the same number of 1 bits in their binary representation.
* __5.5 Debugger:__ Explain what the following code does: __((n & (n - 1)) == 0).
* __5.6 Conversion:__ Write a function to determine the number of bits you would need to flip to convert integer A to integer B.
  * _EXAMPLE_
  * INPUT: 29 (or: 11101), 15 (or: 01111)
  * OUTPUT: 2
* __5.7 Pairwise Swap:__ Write a program to swap odd and even bits in an integer with as few instructions as possible (eg: bit __0__ and bit __1__ are swapped, bit __2__ and bit __3__ are swapped, and so on).
* __5.8 Draw Line:__ A monochrome screen is stored as a single array of bytes, allowing eight consecutive pixels to be stored in one byte.  The screen has a width __w__, where __w__ is divisible by 8 (that is, no byte will be split across rows).  The height of the screen, of course, can be derived from the length of the array and the width.  Implement a function that draws a horizontal line from (x1, y) to (x2, y).<br>
The method signature should look something like:<br/>
_drawLine(byte[] screen, int width, int x1, int x2, int y)_

## 8. Recursion & Dynamic Programming

* __8.1 Triple Step:__ A child is running up a staircase with __n__ steps and can hop either 1 step, 2 steps, or 3 steps at a time.  Implement a method to count how many possible ways the child can run up the stairs.
* __8.2 Robot in a Grid:__ Imagine a robot sitting on the upper left corner of a grid with r rows and c columns.  The robot can only move in 2 directions, right and down, but certain cells are "off limits", such that the robot cannot step on them.  Design an algorithm to find a path for the robot from the top left to the bottom right.
* __8.3 Magic Index:__ A magic index in an array A[0...n - 1] is defined to be an index such that A[i] = i.  Given a sorted array of distinct integers, write a method to find a magic index, if one exists, in array A.  What if the values are not distinct?
* __8.4 Power Set:__ Write a method to return all subsets of a set.
* __8.5 Recursive Multiply:__ Write a recursive function to multiply 2 numbers without using the * operator.  You can use additions, subtraction, and bit shifting, but you should minimize the number of those operations.
* __8.6 Towers of Hanoi:__ In the classic problem of the Towers of Hanoi, you have 3 towers and __N__ disks of different sized which can slide onto any tower.  The puzzle starts with disks sorted in ascending order of size from top to bottom (ie: each disk sits on top of an even larger one).  You have the following constraints:
  * Only 1 disk can be moved at a time.
  * A disk is slid off the top of one tower onto the next tower.
  * A disk can only be placed on top of a larger disk.<br>
Move the disks from the first tower to the last using stacks.
* __8.7 Permutation without Dups:__ Write a method to compute all permutations of a string of unique characters.
* __8.8 Permutation with Dups:__ Write a method to compute all permutations of a string whose characters are not necessarily unique.  The list of permutations should not have duplicates.
* __8.9 Parentheses:__ Implement an algorithm to print all valid (eg: properly opened & closed) combinations of __n__ pairs of parentheses.
  * _EXAMPLE_
  * INPUT: 3
  * OUTPUT: ((())), (()()), (())(), ()(()), ()()()
* __8.10 Paint Fill:__ Implement the "paint fill" function that one might see on many image editing programs.  That is, given a screen (represented by a 2 dimensional array of colors), and a point, and a new color, fill in the surrounding area until the color changes from the original color.
* __8.11 Coins:__ Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5 cents), and pennies (1 cent), write code to calculate the number of ways of representing __n__ cents.
* __8.12 Eight Queens:__ Write an algorithm to print all ways of arranging 8 queens on an 8x8 chess board so that none of them share the same row, column or diagonal.
* __8.13 Stack of Boxes:__ You have a stack of __n__ boxes with widths __w_i__, heights __h_i__, and depths __d_i__.  The boxes cannot be rotated and can only be stacked on top of one another if each box in the stack is strictly larger than the box above it in width, height and depth.  Implement a method to compute the height of the tallest possible stack.  The height of a stack is the sum of the heights of each box.
