# Find Minimum in Rotated Sorted Array

An array of distinct integers was sorted in ascending order and then rotated some number of times (possibly zero). Rotating once moves the last element to the front, so ``[1,2,3,4]`` rotated once becomes ``[4,1,2,3]``.

Given the rotated array ``nums``, return its smallest element.

Your algorithm must run in ``O(log n)`` time.
\
\
\
**Example 1:**

>**Input:** nums = [6,7,9,2,4]\
>**Output:** 2\
>**Explanation:** The sorted array was [2,4,6,7,9], rotated 3 times.

**Example 2:**

>**Input:** nums = [8,10,12,14,1,3,5]\
>**Output:** 1

**Example 3:**

>**Input:** nums = [21,23,25,27]\
>**Output:** 21\
>**Explanation:** The array was rotated a multiple of 4 times, so it is still sorted.

**Constraints:**

* ``n == nums.length``
* ``1 <= n <= 5000``
* ``-5000 <= nums[i] <= 5000``
* All values in ``nums`` are distinct.
* ``nums`` is a sorted array rotated between ``1`` and ``n`` times.
