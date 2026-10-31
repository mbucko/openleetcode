# Decode Ways

A message of capital letters was encoded by replacing each letter with its position in the alphabet: ``'A'`` becomes ``"1"``, ``'B'`` becomes ``"2"``, ..., ``'Z'`` becomes ``"26"``. The numbers were then written next to each other without separators.

Given the encoded string ``s``, return how many different messages it could have come from. A group can't start with ``'0'``, so ``"06"`` is not a valid code. If ``s`` can't be decoded at all, return ``0``. Every answer fits in a 32-bit integer.
\
\
\
**Example 1:**

>**Input:** s = "123"\
>**Output:** 3\
>**Explanation:** "ABC" (1 2 3), "LC" (12 3) or "AW" (1 23).

**Example 2:**

>**Input:** s = "27"\
>**Output:** 1\
>**Explanation:** 27 is too large for one letter, so it can only be "BG" (2 7).

**Example 3:**

>**Input:** s = "30"\
>**Output:** 0\
>**Explanation:** "30" is too large and "0" alone isn't a letter.

**Constraints:**

* ``1 <= s.length <= 100``
* ``s`` contains only digits and may contain leading zeros.
