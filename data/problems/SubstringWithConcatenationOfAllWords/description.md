# Substring with Concatenation of All Words

You are given a string ``s`` and an array ``words`` of strings that all have the same length. A **concatenated string** contains every word in ``words`` exactly once, joined together in any order. For ``words = ["ab", "cd"]``, both ``"abcd"`` and ``"cdab"`` are concatenated strings.

Return the starting index of every substring of ``s`` that is a concatenated string, in ascending order.
\
\
\
**Example 1:**

>**Input:** s = "xyzabcxyz", words = ["xyz","abc"]\
>**Output:** [0,3]\
>**Explanation:** "xyzabc" starts at 0 and "abcxyz" starts at 3.

**Example 2:**

>**Input:** s = "catdogcat", words = ["dog","dog"]\
>**Output:** []\
>**Explanation:** "dog" appears only once in s, but the words need it twice.

**Example 3:**

>**Input:** s = "aaaa", words = ["aa"]\
>**Output:** [0,1,2]

**Constraints:**

* ``1 <= s.length <= 10^4``
* ``1 <= words.length <= 5000``
* ``1 <= words[i].length <= 30``
* ``s`` and ``words[i]`` contain only lowercase English letters.
