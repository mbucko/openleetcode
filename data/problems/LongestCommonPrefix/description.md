# Longest Common Prefix

You are given an array of strings ``strs``. Return the longest string that every string in ``strs`` starts with. If they share no common start, return an empty string ``""``.
\
\
\
**Example 1:**

>**Input:** strs = ["interval","internet","interior"]\
>**Output:** "inter"

**Example 2:**

>**Input:** strs = ["dog","cat","dove"]\
>**Output:** ""\
>**Explanation:** "cat" doesn't start with 'd', so nothing is shared.

**Example 3:**

>**Input:** strs = ["solo"]\
>**Output:** "solo"

**Constraints:**

* ``1 <= strs.length <= 200``
* ``0 <= strs[i].length <= 200``
* ``strs[i]`` contains only lowercase English letters.
