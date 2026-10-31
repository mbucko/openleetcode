# Zigzag Conversion

Write the characters of a string ``s`` in a zigzag over ``numRows`` rows: go down the rows one character at a time, then diagonally back up, then down again, and so on. For ``s = "ABCDEFGHIJ"`` and ``numRows = 3`` the layout is:

```
A   E   I
B D F H J
C   G
```

Then read the rows from top to bottom, left to right, which gives ``"AEIBDFHJCG"``.

Given ``s`` and ``numRows``, return the string read off the zigzag.
\
\
\
**Example 1:**

>**Input:** s = "ABCDEFGHIJ", numRows = 3\
>**Output:** "AEIBDFHJCG"

**Example 2:**

>**Input:** s = "ABCDEFGHIJ", numRows = 4\
>**Output:** "AGBFHCEIDJ"\
>**Explanation:** The rows are A G, B F H, C E I and D J.

**Example 3:**

>**Input:** s = "XY", numRows = 1\
>**Output:** "XY"\
>**Explanation:** With one row the string is unchanged.

**Constraints:**

* ``1 <= s.length <= 1000``
* ``s`` contains English letters, ``','`` and ``'.'``.
* ``1 <= numRows <= 1000``
