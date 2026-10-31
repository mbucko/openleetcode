# Search in Rotated Sorted Array

An array of distinct integers was sorted in ascending order and then possibly rotated at an unknown pivot, so ``[1,3,5,7,9]`` might have become ``[7,9,1,3,5]``.

Given the rotated array ``nums`` and an integer ``target``, return the index of ``target`` in ``nums``, or ``-1`` if it isn't there.

Your algorithm must run in ``O(log n)`` time.
\
\
\
**Example 1:**

>**Input:** nums = [7,9,1,3,5], target = 3\
>**Output:** 3

**Example 2:**

>**Input:** nums = [7,9,1,3,5], target = 8\
>**Output:** -1

**Example 3:**

>**Input:** nums = [2], target = 2\
>**Output:** 0

**Constraints:**

* ``1 <= nums.length <= 5000``
* ``-10^4 <= nums[i], target <= 10^4``
* All values in ``nums`` are distinct.
* ``nums`` is an ascending array that was possibly rotated.
