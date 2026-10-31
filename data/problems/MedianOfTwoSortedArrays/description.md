# Median of Two Sorted Arrays

You are given two arrays ``nums1`` and ``nums2``, each sorted in ascending order, of sizes ``m`` and ``n``. Return the median of all ``m + n`` values combined.

The median is the middle value of the combined sorted values. When there is an even number of values, it is the average of the two middle ones.

Your algorithm should run in ``O(log (m + n))`` time.
\
\
\
**Example 1:**

>**Input:** nums1 = [2,5], nums2 = [3]\
>**Output:** 3.0\
>**Explanation:** Combined, the values are [2,3,5], and the middle one is 3.

**Example 2:**

>**Input:** nums1 = [1,4], nums2 = [6,8]\
>**Output:** 5.0\
>**Explanation:** Combined, the values are [1,4,6,8], so the median is (4 + 6) / 2 = 5.0.

**Example 3:**

>**Input:** nums1 = [], nums2 = [7]\
>**Output:** 7.0

**Constraints:**

* ``nums1.length == m``
* ``nums2.length == n``
* ``0 <= m, n <= 1000``
* ``1 <= m + n <= 2000``
* ``-10^6 <= nums1[i], nums2[i] <= 10^6``
