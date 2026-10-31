# 4Sum

You are given an integer array ``nums`` and an integer ``target``. Find every distinct quadruplet of values ``[a, b, c, d]``, taken from four different positions in ``nums``, such that ``a + b + c + d == target``.

Write each quadruplet in ascending order, list the quadruplets in ascending lexicographic order, and don't repeat a quadruplet.
\
\
\
**Example 1:**

>**Input:** nums = [3,-1,0,2,-2,1], target = 2\
>**Output:** [[-2,-1,2,3],[-2,0,1,3],[-1,0,1,2]]

**Example 2:**

>**Input:** nums = [5,5,5,5,5], target = 20\
>**Output:** [[5,5,5,5]]\
>**Explanation:** Every choice of four 5s gives the same quadruplet, so it is listed once.

**Example 3:**

>**Input:** nums = [1,2,3], target = 6\
>**Output:** []\
>**Explanation:** There are fewer than four values.

**Constraints:**

* ``1 <= nums.length <= 200``
* ``-10^9 <= nums[i] <= 10^9``
* ``-10^9 <= target <= 10^9``
