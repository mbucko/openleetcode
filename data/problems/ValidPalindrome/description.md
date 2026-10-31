# Valid Palindrome

Take a string, convert every uppercase letter to lowercase, and remove every character that is not a letter or a digit. If what remains reads the same forwards and backwards, the original string is a **palindrome**.

Given a string ``s``, return ``true`` if it is a palindrome under this rule, and ``false`` otherwise.
\
\
\
**Example 1:**

>**Input:** s = "Step on no pets!"\
>**Output:** true\
>**Explanation:** After cleaning, the string is "steponnopets", which reads the same in both directions.

**Example 2:**

>**Input:** s = "open a door"\
>**Output:** false\
>**Explanation:** "openadoor" reversed is "roodanepo".

**Example 3:**

>**Input:** s = ":- "\
>**Output:** true\
>**Explanation:** Nothing is left after cleaning, and an empty string counts as a palindrome.

**Constraints:**

* ``1 <= s.length <= 2 * 10^5``
* ``s`` contains only printable ASCII characters.
