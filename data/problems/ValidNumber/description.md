# Valid Number

You are given a string ``s``. Return ``true`` if it is a valid number under these rules:

* An **integer** is an optional sign (``'+'`` or ``'-'``) followed by one or more digits.
* A **decimal** is an optional sign followed by one of: digits then ``'.'``; digits, ``'.'`` and more digits; or ``'.'`` then digits.
* A **number** is an integer or a decimal, optionally followed by an exponent: ``'e'`` or ``'E'`` followed by an integer.

For example ``"7"``, ``"-0.25"``, ``"3."``, ``".5"``, ``"6e3"`` and ``"+2.5E-4"`` are valid. ``"e5"``, ``"1e"``, ``"--3"``, ``"4.2.1"`` and ``"x9"`` are not.
\
\
\
**Example 1:**

>**Input:** s = "-12.5e3"\
>**Output:** true

**Example 2:**

>**Input:** s = "."\
>**Output:** false\
>**Explanation:** A decimal point needs a digit on at least one side.

**Example 3:**

>**Input:** s = "7e2.5"\
>**Output:** false\
>**Explanation:** The exponent must be an integer.

**Constraints:**

* ``1 <= s.length <= 20``
* ``s`` contains only English letters, digits, ``'+'``, ``'-'`` and ``'.'``.
