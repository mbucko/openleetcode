# 3Sum

You are given an integer array ``nums``. Find every distinct triplet of values ``[a, b, c]`` taken from three different positions in ``nums`` such that ``a + b + c == 0``.

Write each triplet in ascending order, list the triplets in ascending lexicographic order, and don't repeat a triplet.
\
\
\
**Example 1:**

>**Input:** nums = [-3,1,2,-1,0,1]\
>**Output:** [[-3,1,2],[-1,0,1]]\
>**Explanation:** [-3,1,2] and [-1,0,1] add up to 0. [-1,0,1] can be formed with either of the two 1s, but it is listed once.

**Example 2:**

>**Input:** nums = [2,4,5]\
>**Output:** []\
>**Explanation:** No triplet adds up to 0.

**Example 3:**

>**Input:** nums = [0,0,0,0]\
>**Output:** [[0,0,0]]

**Constraints:**

* ``3 <= nums.length <= 3000``
* ``-10^5 <= nums[i] <= 10^5``
