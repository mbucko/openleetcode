# Plus One

A non-negative integer is given as an array ``digits``, with the most significant digit first and no leading zeros (except for the number 0 itself). Add one to the number and return the result in the same format.
\
\
\
**Example 1:**

>**Input:** digits = [4,5,6]\
>**Output:** [4,5,7]\
>**Explanation:** 456 + 1 = 457.

**Example 2:**

>**Input:** digits = [2,9,9]\
>**Output:** [3,0,0]\
>**Explanation:** 299 + 1 = 300, so the carry ripples through the 9s.

**Example 3:**

>**Input:** digits = [9]\
>**Output:** [1,0]

**Constraints:**

* ``1 <= digits.length <= 100``
* ``0 <= digits[i] <= 9``
* ``digits`` has no leading zeros, except for the number 0 itself.
