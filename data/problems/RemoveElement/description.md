# Remove Element

You are given an integer array ``nums`` and an integer ``val``. Remove every occurrence of ``val`` from ``nums`` **in place**, so that the first ``k`` elements are the values that are not equal to ``val``, in their original order.

Return those first ``k`` elements. Your algorithm should use ``O(1)`` extra memory apart from the returned result.
\
\
\
**Example 1:**

>**Input:** nums = [4,1,4,2,4], val = 4\
>**Output:** [1,2]

**Example 2:**

>**Input:** nums = [6,6], val = 6\
>**Output:** []\
>**Explanation:** Every element is removed.

**Example 3:**

>**Input:** nums = [1,2,3], val = 9\
>**Output:** [1,2,3]\
>**Explanation:** 9 doesn't appear, so nothing changes.

**Constraints:**

* ``0 <= nums.length <= 100``
* ``0 <= nums[i] <= 50``
* ``0 <= val <= 100``
