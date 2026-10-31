# Regular Expression Matching

You are given a string ``s`` and a pattern ``p``. The pattern can contain lowercase letters and two special characters:

* ``'.'`` matches any single character.
* ``'*'`` matches zero or more copies of the character right before it.

Return ``true`` if the pattern matches the **whole** string ``s``, not just part of it.
\
\
\
**Example 1:**

>**Input:** s = "ab", p = "a"\
>**Output:** false\
>**Explanation:** The pattern only covers the first character.

**Example 2:**

>**Input:** s = "bbbb", p = "b*"\
>**Output:** true\
>**Explanation:** '*' lets the 'b' repeat four times.

**Example 3:**

>**Input:** s = "xyz", p = ".*"\
>**Output:** true\
>**Explanation:** '.*' means any character, any number of times.

**Example 4:**

>**Input:** s = "aabxx", p = "a*bx*"\
>**Output:** true

**Constraints:**

* ``1 <= s.length <= 20``
* ``1 <= p.length <= 20``
* ``s`` contains only lowercase English letters.
* ``p`` contains only lowercase English letters, ``'.'`` and ``'*'``.
* Every ``'*'`` comes right after a valid character.
