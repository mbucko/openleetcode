# Missing Number

You are given an array ``nums`` of ``n`` distinct integers, all taken from the range ``[0, n]``. Exactly one number in that range is absent. Return it.
\
\
\
**Example 1:**

>**Input:** nums = [4,0,2,1]\
>**Output:** 3\
>**Explanation:** There are 4 numbers, so the range is [0,4]. The only value from that range not in nums is 3.

**Example 2:**

>**Input:** nums = [1,2]\
>**Output:** 0\
>**Explanation:** The range is [0,2], and 0 is missing.

**Example 3:**

>**Input:** nums = [7,3,0,5,1,6,2,8]\
>**Output:** 4

**Constraints:**

* ``n == nums.length``
* ``1 <= n <= 10^4``
* ``0 <= nums[i] <= n``
* All values in ``nums`` are distinct.
