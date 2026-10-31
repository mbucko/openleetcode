# Next Permutation

Arrange the permutations of an array in lexicographic order. The **next permutation** of ``nums`` is the one that comes right after it in that order. For ``[1,2,3]`` the order is ``[1,2,3]``, ``[1,3,2]``, ``[2,1,3]``, ``[2,3,1]``, ``[3,1,2]``, ``[3,2,1]``. The last permutation wraps around to the first, so the next permutation of ``[3,2,1]`` is ``[1,2,3]``.

Rearrange ``nums`` **in place** into its next permutation, using only ``O(1)`` extra memory, and return it.
\
\
\
**Example 1:**

>**Input:** nums = [1,4,3,2]\
>**Output:** [2,1,3,4]

**Example 2:**

>**Input:** nums = [5,4,1]\
>**Output:** [1,4,5]\
>**Explanation:** This is the last permutation, so it wraps around to the first.

**Example 3:**

>**Input:** nums = [2,2,7]\
>**Output:** [2,7,2]

**Constraints:**

* ``1 <= nums.length <= 100``
* ``0 <= nums[i] <= 100``
