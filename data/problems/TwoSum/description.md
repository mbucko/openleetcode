# Two Sum

You are given an array of integers ``nums`` and an integer ``target``, return indices of the two numbers that they add up to the ``target``.

You may assume that the array has exactly one solution, and you may not use the same interger twice.

You can return the answer in any order.
\
\
\
**Example 1:**

>**Input:** nums = [3,7,11,25], target = 10\
>**Output:** [0,1]\
>**Explanation:** Because nums[0] + nums[1] == 10, we return [0, 1].

**Example 2:**

>**Input:** nums = [1,3,4], target = 7\
>**Output:** [1,2]

**Example 3:**

>**Input:** nums = [1,1], target = 2\
>**Output:** [0,1]

**Constraints:**

* ``2 <= nums.length <= 104``
* ``-109 <= nums[i] <= 109``
* ``-109 <= target <= 109``
* **Only one valid answer exists.**