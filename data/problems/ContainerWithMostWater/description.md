# Container With Most Water

You are given an array ``height`` of ``n`` integers. Picture ``n`` vertical walls at positions ``0`` to ``n - 1``, where wall ``i`` has height ``height[i]``.

Any two walls, together with the ground, form a container. It holds water up to the height of the shorter wall, across the distance between them.

Return the largest amount of water a single container can hold. The container cannot be tilted.
\
\
\
**Example 1:**

>**Input:** height = [2,7,3,8,4,6]\
>**Output:** 24\
>**Explanation:** Walls 1 (height 7) and 5 (height 6) are 4 apart, so they hold min(7, 6) * 4 = 24.

**Example 2:**

>**Input:** height = [3,3]\
>**Output:** 3

**Constraints:**

* ``n == height.length``
* ``2 <= n <= 10^5``
* ``0 <= height[i] <= 10^4``
