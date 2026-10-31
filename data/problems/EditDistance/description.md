# Edit Distance

You are given two strings ``word1`` and ``word2``. In one operation you can insert a character, delete a character or replace a character in ``word1``.

Return the fewest operations needed to turn ``word1`` into ``word2``.
\
\
\
**Example 1:**

>**Input:** word1 = "kitten", word2 = "sitting"\
>**Output:** 3\
>**Explanation:** Replace 'k' with 's', replace 'e' with 'i', then insert 'g' at the end.

**Example 2:**

>**Input:** word1 = "abc", word2 = "abc"\
>**Output:** 0

**Example 3:**

>**Input:** word1 = "", word2 = "four"\
>**Output:** 4\
>**Explanation:** Insert all four characters.

**Constraints:**

* ``0 <= word1.length, word2.length <= 500``
* ``word1`` and ``word2`` contain only lowercase English letters.
