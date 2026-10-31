# Roman to Integer

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

Symbols are usually written from largest to smallest, and their values are added up. For example, ``XVI`` is 10 + 5 + 1 = 16. When a smaller symbol comes right before a larger one, it is subtracted instead: ``IV`` is 4, ``IX`` is 9, ``XL`` is 40, ``XC`` is 90, ``CD`` is 400 and ``CM`` is 900.

Given a Roman numeral ``s``, return its integer value.
\
\
\
**Example 1:**

>**Input:** s = "XLII"\
>**Output:** 42\
>**Explanation:** XL = 40 and II = 2.

**Example 2:**

>**Input:** s = "CDXLIV"\
>**Output:** 444\
>**Explanation:** CD = 400, XL = 40 and IV = 4.

**Example 3:**

>**Input:** s = "MMXXVI"\
>**Output:** 2026

**Constraints:**

* ``1 <= s.length <= 15``
* ``s`` contains only the characters ``I``, ``V``, ``X``, ``L``, ``C``, ``D`` and ``M``.
* ``s`` is guaranteed to be a valid Roman numeral between ``1`` and ``3999``.
