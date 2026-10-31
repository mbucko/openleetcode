# Group Anagrams

You are given an array of strings ``strs``. Group together the strings that are anagrams of each other, meaning they use exactly the same letters the same number of times.

Sort the strings within each group in ascending order, then sort the groups by their first string. If the same string appears more than once in ``strs``, every copy goes into its group.
\
\
\
**Example 1:**

>**Input:** strs = ["tops","cat","spot","act","pots","dog"]\
>**Output:** [["act","cat"],["dog"],["pots","spot","tops"]]

**Example 2:**

>**Input:** strs = [""]\
>**Output:** [[""]]

**Example 3:**

>**Input:** strs = ["z"]\
>**Output:** [["z"]]

**Constraints:**

* ``1 <= strs.length <= 10^4``
* ``0 <= strs[i].length <= 100``
* ``strs[i]`` contains only lowercase English letters.
