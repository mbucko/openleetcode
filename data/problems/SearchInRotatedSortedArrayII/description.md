# Search in Rotated Sorted Array II

An array of integers, which **may contain repeated values**, was sorted in non-decreasing order and then possibly rotated at an unknown pivot, so ``[1,2,2,4,6]`` might have become ``[4,6,1,2,2]``.

Given the rotated array ``nums`` and an integer ``target``, return ``true`` if ``target`` appears in ``nums``.

Try to do fewer steps than checking every element.
\
\
\
**Example 1:**

>**Input:** nums = [4,6,1,2,2], target = 2\
>**Output:** true

**Example 2:**

>**Input:** nums = [4,6,1,2,2], target = 5\
>**Output:** false

**Example 3:**

>**Input:** nums = [1,1,1,3,1], target = 3\
>**Output:** true\
>**Explanation:** Repeated values hide which half is sorted, so the search sometimes has to step past them.

**Constraints:**

* ``1 <= nums.length <= 5000``
* ``-10^4 <= nums[i], target <= 10^4``
* ``nums`` is a non-decreasing array that was possibly rotated.
