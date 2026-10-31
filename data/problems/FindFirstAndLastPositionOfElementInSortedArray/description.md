# Find First and Last Position of Element in Sorted Array

You are given an integer array ``nums`` sorted in non-decreasing order and an integer ``target``. Return ``[first, last]``, the first and last index where ``target`` appears. If it doesn't appear, return ``[-1, -1]``.

Your algorithm must run in ``O(log n)`` time.
\
\
\
**Example 1:**

>**Input:** nums = [1,3,3,3,6,9], target = 3\
>**Output:** [1,3]

**Example 2:**

>**Input:** nums = [1,3,3,3,6,9], target = 4\
>**Output:** [-1,-1]

**Example 3:**

>**Input:** nums = [], target = 2\
>**Output:** [-1,-1]

**Constraints:**

* ``0 <= nums.length <= 10^5``
* ``-10^9 <= nums[i], target <= 10^9``
* ``nums`` is sorted in non-decreasing order.
