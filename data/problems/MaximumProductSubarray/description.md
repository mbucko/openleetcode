# Maximum Product Subarray

You are given an integer array ``nums``. Among all of its non-empty contiguous subarrays, find the one whose elements multiply to the largest value, and return that product.

Every test case is built so that the answer fits in a **32-bit** integer.
\
\
\
**Example 1:**

>**Input:** nums = [3,-1,2,5]\
>**Output:** 10\
>**Explanation:** The subarray [2,5] multiplies to 10.

**Example 2:**

>**Input:** nums = [-3,0,-2]\
>**Output:** 0\
>**Explanation:** [-3,-2] would give 6, but it is not contiguous.

**Example 3:**

>**Input:** nums = [-1,4,-3]\
>**Output:** 12\
>**Explanation:** The two negatives cancel out, so the whole array gives the largest product.

**Constraints:**

* ``1 <= nums.length <= 2 * 10^4``
* ``-10 <= nums[i] <= 10``
* Every prefix and suffix product of ``nums`` fits in a **32-bit** integer.
