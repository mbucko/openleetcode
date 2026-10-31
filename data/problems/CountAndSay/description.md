# Count and Say

The count-and-say sequence is a list of digit strings. The first term is ``"1"``. Each later term describes the previous one by reading it aloud, group by group: a run of the same digit becomes the run's length followed by the digit.

For example, ``"3322251"`` reads as "two 3s, three 2s, one 5, one 1", which gives ``"23321511"``.

Given ``n``, return the ``n``th term of the sequence.
\
\
\
**Example 1:**

>**Input:** n = 5\
>**Output:** "111221"\
>**Explanation:** The terms are "1", "11", "21", "1211" and then "111221".

**Example 2:**

>**Input:** n = 1\
>**Output:** "1"

**Constraints:**

* ``1 <= n <= 30``
