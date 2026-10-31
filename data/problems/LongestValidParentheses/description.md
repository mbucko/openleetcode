# Longest Valid Parentheses

You are given a string ``s`` containing only ``'('`` and ``')'``. Return the length of its longest substring in which the parentheses are correctly balanced.
\
\
\
**Example 1:**

>**Input:** s = ")(())("\
>**Output:** 4\
>**Explanation:** "(())" is balanced and has length 4.

**Example 2:**

>**Input:** s = "()(()"\
>**Output:** 2\
>**Explanation:** "()" is the longest balanced piece. The final "(()" has an unmatched '('.

**Example 3:**

>**Input:** s = ""\
>**Output:** 0

**Constraints:**

* ``0 <= s.length <= 3 * 10^4``
* ``s[i]`` is ``'('`` or ``')'``.
