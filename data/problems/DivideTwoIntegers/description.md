# Divide Two Integers

You are given two integers ``dividend`` and ``divisor``. Divide them **without** using multiplication, division or the modulo operator, and return the quotient rounded towards zero (so ``7.9`` becomes ``7`` and ``-3.6`` becomes ``-3``).

Work within the signed 32-bit range ``[-2^31, 2^31 - 1]``. If the quotient is larger than ``2^31 - 1``, return ``2^31 - 1``. If it is smaller than ``-2^31``, return ``-2^31``.
\
\
\
**Example 1:**

>**Input:** dividend = 20, divisor = 6\
>**Output:** 3\
>**Explanation:** 20 / 6 = 3.33..., which rounds towards zero to 3.

**Example 2:**

>**Input:** dividend = 9, divisor = -4\
>**Output:** -2\
>**Explanation:** 9 / -4 = -2.25, which rounds towards zero to -2.

**Example 3:**

>**Input:** dividend = -2147483648, divisor = -1\
>**Output:** 2147483647\
>**Explanation:** The true quotient 2^31 is too large, so the answer is 2^31 - 1.

**Constraints:**

* ``-2^31 <= dividend, divisor <= 2^31 - 1``
* ``divisor != 0``
