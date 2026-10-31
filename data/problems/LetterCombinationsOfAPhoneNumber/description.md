# Letter Combinations of a Phone Number

On a phone keypad, the digits ``2`` to ``9`` each stand for some letters:

| Digit | Letters |
|-------|---------|
| 2 | abc |
| 3 | def |
| 4 | ghi |
| 5 | jkl |
| 6 | mno |
| 7 | pqrs |
| 8 | tuv |
| 9 | wxyz |

You are given a string ``digits`` containing only ``2`` to ``9``. Return every string you can type by choosing one letter for each digit, in order. List the strings in lexicographic order. If ``digits`` is empty, return an empty array.
\
\
\
**Example 1:**

>**Input:** digits = "47"\
>**Output:** ["gp","gq","gr","gs","hp","hq","hr","hs","ip","iq","ir","is"]\
>**Explanation:** 4 gives g, h or i, and 7 gives p, q, r or s.

**Example 2:**

>**Input:** digits = ""\
>**Output:** []

**Example 3:**

>**Input:** digits = "9"\
>**Output:** ["w","x","y","z"]

**Constraints:**

* ``0 <= digits.length <= 4``
* ``digits[i]`` is a digit from ``'2'`` to ``'9'``.
