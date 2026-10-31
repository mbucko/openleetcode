# Integer to Roman

Roman numerals use seven symbols:

| Symbol | Value |
|--------|-------|
| I | 1 |
| V | 5 |
| X | 10 |
| L | 50 |
| C | 100 |
| D | 500 |
| M | 1000 |

A numeral is written from the largest value to the smallest. The values 4, 9, 40, 90, 400 and 900 use subtraction instead of repeating a symbol four times: ``IV``, ``IX``, ``XL``, ``XC``, ``CD`` and ``CM``. Only ``I``, ``X``, ``C`` and ``M`` may repeat, at most three times in a row.

Given an integer ``num``, return its Roman numeral.
\
\
\
**Example 1:**

>**Input:** num = 2024\
>**Output:** "MMXXIV"\
>**Explanation:** 2000 = MM, 20 = XX and 4 = IV.

**Example 2:**

>**Input:** num = 49\
>**Output:** "XLIX"\
>**Explanation:** 40 = XL and 9 = IX.

**Example 3:**

>**Input:** num = 8\
>**Output:** "VIII"

**Constraints:**

* ``1 <= num <= 3999``
