# Reverse Integer

You are given a signed 32-bit integer ``x``. Return ``x`` with its digits in reverse order, keeping the sign. If the reversed value is outside the signed 32-bit range ``[-2^31, 2^31 - 1]``, return ``0``.

Assume you cannot store 64-bit integers.
\
\
\
**Example 1:**

>**Input:** x = 456\
>**Output:** 654

**Example 2:**

>**Input:** x = -708\
>**Output:** -807\
>**Explanation:** The digits 708 reversed are 807, and the sign stays.

**Example 3:**

>**Input:** x = 1200\
>**Output:** 21\
>**Explanation:** Leading zeros are dropped after reversing.

**Constraints:**

* ``-2^31 <= x <= 2^31 - 1``
