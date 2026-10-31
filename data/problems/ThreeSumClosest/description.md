# 3Sum Closest

You are given an integer array ``nums`` and an integer ``target``. Pick three values from three different positions in ``nums`` so that their sum is as close to ``target`` as possible, and return that sum.

Each test has exactly one closest sum.
\
\
\
**Example 1:**

>**Input:** nums = [-2,3,1,5], target = 2\
>**Output:** 2\
>**Explanation:** -2 + 3 + 1 = 2 hits the target exactly.

**Example 2:**

>**Input:** nums = [4,4,4], target = 1\
>**Output:** 12\
>**Explanation:** The only possible sum is 12.

**Example 3:**

>**Input:** nums = [1,6,9,14], target = 20\
>**Output:** 21\
>**Explanation:** 1 + 6 + 14 = 21 is the closest you can get to 20.

**Constraints:**

* ``3 <= nums.length <= 500``
* ``-1000 <= nums[i] <= 1000``
* ``-10^4 <= target <= 10^4``
