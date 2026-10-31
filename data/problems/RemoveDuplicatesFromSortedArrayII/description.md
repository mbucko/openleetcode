# Remove Duplicates from Sorted Array II

You are given an integer array ``nums`` sorted in non-decreasing order. Rearrange it **in place** so that each distinct value appears **at most twice**, keeping the original order, in the first ``k`` positions.

Return those first ``k`` elements. Your algorithm should use ``O(1)`` extra memory apart from the returned result.
\
\
\
**Example 1:**

>**Input:** nums = [3,3,3,5,6,6,6,6]\
>**Output:** [3,3,5,6,6]\
>**Explanation:** The extra copies of 3 and 6 are dropped.

**Example 2:**

>**Input:** nums = [1,2,2]\
>**Output:** [1,2,2]

**Example 3:**

>**Input:** nums = [4]\
>**Output:** [4]

**Constraints:**

* ``1 <= nums.length <= 3 * 10^4``
* ``-10^4 <= nums[i] <= 10^4``
* ``nums`` is sorted in non-decreasing order.
