# Gray Code

An ``n``-bit Gray code is an ordering of all ``2^n`` integers from ``0`` to ``2^n - 1`` that starts at ``0``, in which each pair of neighbouring values (including the last and the first) differs in exactly one bit.

Return the **reflected** Gray code for ``n``. It is built recursively: the 1-bit code is ``[0, 1]``, and the ``n``-bit code is the ``(n - 1)``-bit code followed by the ``(n - 1)``-bit code in reverse order with the bit ``2^(n - 1)`` added to each value.
\
\
\
**Example 1:**

>**Input:** n = 3\
>**Output:** [0,1,3,2,6,7,5,4]\
>**Explanation:** In binary: 000, 001, 011, 010, 110, 111, 101, 100. Each step flips one bit.

**Example 2:**

>**Input:** n = 4\
>**Output:** [0,1,3,2,6,7,5,4,12,13,15,14,10,11,9,8]

**Constraints:**

* ``1 <= n <= 16``
