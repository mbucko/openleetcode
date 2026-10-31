# Length of Last Word

You are given a string ``s`` of words and spaces. A word is a maximal run of non-space characters. Return the length of the last word in ``s``.
\
\
\
**Example 1:**

>**Input:** s = "open the window"\
>**Output:** 6\
>**Explanation:** The last word is "window".

**Example 2:**

>**Input:** s = "  sky is blue   "\
>**Output:** 4\
>**Explanation:** Trailing spaces don't count, so the last word is "blue".

**Example 3:**

>**Input:** s = "a"\
>**Output:** 1

**Constraints:**

* ``1 <= s.length <= 10^4``
* ``s`` contains only English letters and spaces.
* ``s`` contains at least one word.
