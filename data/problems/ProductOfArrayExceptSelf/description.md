# Product of Array Except Self

You are given an integer array ``nums``. Return an array ``answer`` where ``answer[i]`` is the product of every element of ``nums`` except ``nums[i]``.

Every prefix and suffix product of ``nums`` fits in a **32-bit** integer.

Your algorithm must run in ``O(n)`` time and must not use division.
\
\
\
**Example 1:**

>**Input:** nums = [2,3,4,5]\
>**Output:** [60,40,30,24]

**Example 2:**

>**Input:** nums = [-2,1,0,4,-1]\
>**Output:** [0,0,8,0,0]\
>**Explanation:** Every product except the one that skips the 0 includes the 0.

**Constraints:**

* ``2 <= nums.length <= 10^5``
* ``-30 <= nums[i] <= 30``
* Each ``answer[i]`` fits in a **32-bit** integer.

**Follow up:** Can you use only ``O(1)`` extra space? The output array does not count.
