# Scramble String

A string ``s`` can be **scrambled** like this:

1. If it has length 1, stop.
2. Otherwise, split it at any position into two non-empty parts ``x`` and ``y``, so ``s = x + y``.
3. Optionally swap them, giving ``y + x``.
4. Scramble each part again, recursively.

You are given two strings ``s1`` and ``s2`` of the same length. Return ``true`` if ``s2`` can be produced by scrambling ``s1``.
\
\
\
**Example 1:**

>**Input:** s1 = "abcd", s2 = "cdba"\
>**Output:** true\
>**Explanation:** Split into "ab" + "cd" and swap to get "cd" + "ab". Then split "ab" into "a" + "b" and swap to get "ba".

**Example 2:**

>**Input:** s1 = "abcd", s2 = "bdac"\
>**Output:** false

**Example 3:**

>**Input:** s1 = "z", s2 = "z"\
>**Output:** true

**Constraints:**

* ``s1.length == s2.length``
* ``1 <= s1.length <= 30``
* ``s1`` and ``s2`` contain only lowercase English letters.
