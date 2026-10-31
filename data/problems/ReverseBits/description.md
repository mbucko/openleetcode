# Reverse Bits

You are given an integer ``n``. Treat it as a 32-bit unsigned value, reverse the order of its 32 bits, and return the resulting number.
\
\
\
**Example 1:**

>**Input:** n = 6\
>**Output:** 1610612736\
>**Explanation:** 6 is ``00000000000000000000000000000110`` in binary. Reversed, that is ``01100000000000000000000000000000``, which is 1610612736.

**Example 2:**

>**Input:** n = 40\
>**Output:** 335544320\
>**Explanation:** 40 is ``00000000000000000000000000101000``. Reversed, that is ``00010100000000000000000000000000``, which is 335544320.

**Constraints:**

* ``0 <= n <= 2^31 - 2``
* ``n`` is even, so the result also fits in a signed 32-bit integer.
