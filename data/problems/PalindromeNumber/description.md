# Palindrome Number

Given an integer x, return true if x is a palindrome and false if it is not.

A number is a palindrome when its digits read the same from left to right as they do from right to left.

**Example 1:**

Input: x = 1331
Output: true
Explanation: Reading 1331 backward still gives 1331.

**Example 2:**

Input: x = -88
Output: false
Explanation: Read backward, -88 becomes 88-, which is not the same, so negative numbers are never palindromes.

**Example 3:**

Input: x = 470
Output: false
Explanation: Read backward, 470 becomes 074. Since a number cannot start with 0, any number ending in 0 (other than 0 itself) is not a palindrome.

**Example 4:**

Input: x = 5
Output: true
Explanation: A single digit reads the same in both directions.

**Constraints:**

-2^31 <= x <= 2^31 - 1