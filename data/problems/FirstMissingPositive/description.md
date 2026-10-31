# First Missing Positive

You are given an unsorted integer array ``nums``. Return the smallest positive integer (``1``, ``2``, ``3``, ...) that does not appear in ``nums``.

Your algorithm must run in ``O(n)`` time and use ``O(1)`` extra memory.
\
\
\
**Example 1:**

>**Input:** nums = [2,1,5]\
>**Output:** 3\
>**Explanation:** 1 and 2 are present, so 3 is the first missing one.

**Example 2:**

>**Input:** nums = [4,-2,9,12]\
>**Output:** 1\
>**Explanation:** 1 doesn't appear.

**Example 3:**

>**Input:** nums = [1,2,3,4]\
>**Output:** 5

**Constraints:**

* ``1 <= nums.length <= 10^5``
* ``-2^31 <= nums[i] <= 2^31 - 1``
