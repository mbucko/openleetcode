# Search Insert Position

You are given a sorted array ``nums`` of distinct integers and an integer ``target``. Return the index of ``target`` if it is in the array. If not, return the index where it would go to keep the array sorted.

Your algorithm must run in ``O(log n)`` time.
\
\
\
**Example 1:**

>**Input:** nums = [2,4,8,10], target = 8\
>**Output:** 2

**Example 2:**

>**Input:** nums = [2,4,8,10], target = 5\
>**Output:** 2\
>**Explanation:** 5 would go between 4 and 8.

**Example 3:**

>**Input:** nums = [2,4,8,10], target = 12\
>**Output:** 4

**Constraints:**

* ``1 <= nums.length <= 10^4``
* ``-10^4 <= nums[i], target <= 10^4``
* ``nums`` contains distinct values sorted in ascending order.
