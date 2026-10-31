# Daily Temperatures

You are given an array ``temperatures`` where ``temperatures[i]`` is the temperature on day ``i``. Return an array ``answer`` where ``answer[i]`` is how many days after day ``i`` you must wait for a strictly warmer day. If no warmer day comes later, ``answer[i]`` is ``0``.
\
\
\
**Example 1:**

>**Input:** temperatures = [65,70,68,72,60,75]\
>**Output:** [1,2,1,2,1,0]\
>**Explanation:** After day 1 (70), the next warmer day is day 3 (72), two days later. Nothing after day 5 (75) is warmer.

**Example 2:**

>**Input:** temperatures = [40,45,50,55,60]\
>**Output:** [1,1,1,1,0]

**Example 3:**

>**Input:** temperatures = [35,90,40]\
>**Output:** [1,0,0]

**Constraints:**

* ``1 <= temperatures.length <= 10^5``
* ``30 <= temperatures[i] <= 100``
