# Insert Interval

You are given an array ``intervals`` of non-overlapping intervals ``[start_i, end_i]``, sorted by start, and one more interval ``newInterval``. Insert ``newInterval``, merging it with any intervals it overlaps, and return the result. It must still be sorted by start and free of overlaps. Intervals that only touch, like ``[1,3]`` and ``[3,5]``, count as overlapping.
\
\
\
**Example 1:**

>**Input:** intervals = [[1,2],[5,7],[9,12]], newInterval = [6,10]\
>**Output:** [[1,2],[5,12]]\
>**Explanation:** [6,10] overlaps both [5,7] and [9,12], so all three merge into [5,12].

**Example 2:**

>**Input:** intervals = [[3,4]], newInterval = [1,2]\
>**Output:** [[1,2],[3,4]]

**Example 3:**

>**Input:** intervals = [], newInterval = [4,8]\
>**Output:** [[4,8]]

**Constraints:**

* ``0 <= intervals.length <= 10^4``
* ``intervals[i].length == 2``
* ``0 <= start_i <= end_i <= 10^5``
* ``intervals`` is sorted by ``start_i`` and has no overlaps.
* ``newInterval.length == 2``
* ``0 <= newInterval[0] <= newInterval[1] <= 10^5``
