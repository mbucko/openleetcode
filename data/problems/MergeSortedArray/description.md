# Merge Sorted Array

You are given two integer arrays ``nums1`` and ``nums2``, each sorted in non-decreasing order, and two integers ``m`` and ``n``. The first ``m`` elements of ``nums1`` are its real values. It has ``n`` extra slots at the end, filled with ``0``, to make room. ``nums2`` has exactly ``n`` elements.

Merge ``nums2`` into ``nums1`` **in place** so that ``nums1`` holds all ``m + n`` values in sorted order, and return ``nums1``.
\
\
\
**Example 1:**

>**Input:** nums1 = [2,5,9,0,0], m = 3, nums2 = [1,6], n = 2\
>**Output:** [1,2,5,6,9]

**Example 2:**

>**Input:** nums1 = [4,0], m = 1, nums2 = [3], n = 1\
>**Output:** [3,4]

**Example 3:**

>**Input:** nums1 = [0], m = 0, nums2 = [8], n = 1\
>**Output:** [8]\
>**Explanation:** nums1 has no real values, only the one empty slot.

**Constraints:**

* ``nums1.length == m + n``
* ``nums2.length == n``
* ``0 <= m, n <= 200``
* ``1 <= m + n <= 200``
* ``-10^9 <= nums1[i], nums2[j] <= 10^9``

**Follow up:** Can you do it in ``O(m + n)`` time?
