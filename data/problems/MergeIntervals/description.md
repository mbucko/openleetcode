# Merge Intervals

You are given an array ``intervals`` where ``intervals[i] = [start_i, end_i]``. Merge every group of overlapping intervals into one, and return the resulting intervals sorted by start. Intervals that only touch, like ``[1,3]`` and ``[3,5]``, count as overlapping.
\
\
\
**Example 1:**

>**Input:** intervals = [[5,8],[1,4],[3,6],[10,12]]\
>**Output:** [[1,8],[10,12]]\
>**Explanation:** [1,4], [3,6] and [5,8] chain together into [1,8].

**Example 2:**

>**Input:** intervals = [[2,3],[3,7]]\
>**Output:** [[2,7]]\
>**Explanation:** Touching intervals are merged.

**Example 3:**

>**Input:** intervals = [[1,2],[4,5]]\
>**Output:** [[1,2],[4,5]]

**Constraints:**

* ``1 <= intervals.length <= 10^4``
* ``intervals[i].length == 2``
* ``0 <= start_i <= end_i <= 10^4``
