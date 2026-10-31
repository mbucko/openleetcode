# String to Integer (atoi)

Write ``myAtoi(s)``, which turns a string into a signed 32-bit integer using these steps:

1. Skip any leading spaces.
2. Read an optional ``'+'`` or ``'-'`` sign. Without a sign the number is positive.
3. Read digits until a non-digit character or the end of the string. Leading zeros are allowed. If there are no digits, the result is ``0``.
4. If the number is outside ``[-2^31, 2^31 - 1]``, clamp it to the nearest end of that range.

Everything after the digits is ignored. Return the result.
\
\
\
**Example 1:**

>**Input:** s = "58"\
>**Output:** 58

**Example 2:**

>**Input:** s = "   -0071"\
>**Output:** -71\
>**Explanation:** Spaces are skipped, the sign is read, and leading zeros are ignored.

**Example 3:**

>**Input:** s = "2048 bytes"\
>**Output:** 2048\
>**Explanation:** Reading stops at the space after 2048.

**Example 4:**

>**Input:** s = "words 99"\
>**Output:** 0\
>**Explanation:** The first non-space character is not a digit or sign, so nothing is read.

**Constraints:**

* ``0 <= s.length <= 200``
* ``s`` contains English letters, digits, ``' '``, ``'+'``, ``'-'`` and ``'.'``.
