# Pow(x, n)

You are given a number ``x`` and an integer ``n``. Return ``x`` raised to the power ``n``.

Answers within ``10^-5`` of the exact value are accepted.
\
\
\
**Example 1:**

>**Input:** x = 3.0, n = 4\
>**Output:** 81.0\
>**Explanation:** 3 * 3 * 3 * 3 = 81.

**Example 2:**

>**Input:** x = 1.5, n = 3\
>**Output:** 3.375

**Example 3:**

>**Input:** x = 4.0, n = -2\
>**Output:** 0.0625\
>**Explanation:** 4^-2 = 1 / 4^2 = 1 / 16 = 0.0625.

**Constraints:**

* ``-100.0 < x < 100.0``
* ``-2^31 <= n <= 2^31 - 1``
* ``n`` is an integer.
* ``x`` is not zero, or ``n > 0``.
* ``-10^4 <= x^n <= 10^4``
