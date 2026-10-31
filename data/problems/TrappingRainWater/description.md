# Trapping Rain Water

You are given an array ``height`` of non-negative integers describing a row of bars, each one unit wide. After it rains, water collects in the dips between bars. Return the total units of water held.

Water above a bar rises to the lower of the tallest bar on its left and the tallest bar on its right.
\
\
\
**Example 1:**

>**Input:** height = [3,0,2,0,4]\
>**Output:** 7\
>**Explanation:** The bars at heights 0, 2 and 0 hold 3, 1 and 3 units.

**Example 2:**

>**Input:** height = [1,2,3]\
>**Output:** 0\
>**Explanation:** The bars only go up, so water runs off.

**Example 3:**

>**Input:** height = [5,1,1,5]\
>**Output:** 8

**Constraints:**

* ``n == height.length``
* ``1 <= n <= 2 * 10^4``
* ``0 <= height[i] <= 10^5``
