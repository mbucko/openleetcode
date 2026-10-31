# Jump Game II

You are given an array ``nums``. You start at index ``0``, and from index ``i`` you can jump forward to any index from ``i + 1`` up to ``i + nums[i]``.

Return the fewest jumps needed to reach the last index. Every test case can reach it.
\
\
\
**Example 1:**

>**Input:** nums = [3,1,1,2,1]\
>**Output:** 2\
>**Explanation:** Jump from index 0 to index 3, then on to index 4.

**Example 2:**

>**Input:** nums = [1,1,1]\
>**Output:** 2

**Example 3:**

>**Input:** nums = [9]\
>**Output:** 0\
>**Explanation:** You already start at the last index.

**Constraints:**

* ``1 <= nums.length <= 10^4``
* ``0 <= nums[i] <= 1000``
* The last index can always be reached.
