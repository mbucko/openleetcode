# Jump Game

You are given an array ``nums``. You start at index ``0``, and from index ``i`` you can jump forward by any distance from ``1`` up to ``nums[i]``.

Return ``true`` if you can reach the last index, and ``false`` otherwise.
\
\
\
**Example 1:**

>**Input:** nums = [1,2,0,1]\
>**Output:** true\
>**Explanation:** Jump 1 step to index 1, then 2 steps to index 3.

**Example 2:**

>**Input:** nums = [2,1,0,3]\
>**Output:** false\
>**Explanation:** Every path lands on index 2, where the 0 means you can't move.

**Example 3:**

>**Input:** nums = [0]\
>**Output:** true\
>**Explanation:** You already start at the last index.

**Constraints:**

* ``1 <= nums.length <= 10^4``
* ``0 <= nums[i] <= 10^5``
