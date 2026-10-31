# Remove Duplicates from Sorted Array

You are given an integer array ``nums`` sorted in non-decreasing order. Rearrange it **in place** so that its first ``k`` elements are the distinct values of ``nums``, each appearing once, in their original order. Here ``k`` is the number of distinct values.

Return those first ``k`` elements. Your algorithm should use ``O(1)`` extra memory apart from the returned result.
\
\
\
**Example 1:**

>**Input:** nums = [2,2,3,7,7,7]\
>**Output:** [2,3,7]\
>**Explanation:** The distinct values are 2, 3 and 7.

**Example 2:**

>**Input:** nums = [-1,0,0,0,4,5,5]\
>**Output:** [-1,0,4,5]

**Example 3:**

>**Input:** nums = [9]\
>**Output:** [9]

**Constraints:**

* ``1 <= nums.length <= 3 * 10^4``
* ``-100 <= nums[i] <= 100``
* ``nums`` is sorted in non-decreasing order.
