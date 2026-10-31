# Permutation Sequence

The numbers ``1`` to ``n`` can be arranged in ``n!`` different orders. List all of those orderings in lexicographic order and number them starting from 1. For ``n = 3`` the list is:

1. ``"123"``
2. ``"132"``
3. ``"213"``
4. ``"231"``
5. ``"312"``
6. ``"321"``

Given ``n`` and ``k``, return the ``k``th ordering as a string.
\
\
\
**Example 1:**

>**Input:** n = 3, k = 5\
>**Output:** "312"

**Example 2:**

>**Input:** n = 4, k = 10\
>**Output:** "2341"

**Example 3:**

>**Input:** n = 2, k = 1\
>**Output:** "12"

**Constraints:**

* ``1 <= n <= 9``
* ``1 <= k <= n!``
