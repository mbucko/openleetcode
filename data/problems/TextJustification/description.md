# Text Justification

You are given an array of words and a line width ``maxWidth``. Lay the words out into lines of exactly ``maxWidth`` characters:

* Fill each line greedily: put as many words on it as fit, with at least one space between neighbouring words.
* Spread the extra spaces on each line as evenly as possible between its words. If they don't divide evenly, the gaps on the left get one more space than the gaps on the right.
* A line with a single word is left-justified and padded with spaces on the right.
* The **last line** is left-justified: one space between words, padded with spaces on the right.

Return the lines.
\
\
\
**Example 1:**

>**Input:** words = ["The","quick","brown","fox","jumps"], maxWidth = 11\
>**Output:** ["The   quick","brown   fox","jumps      "]\
>**Explanation:** "The quick" has one gap, so both extra spaces go there. "jumps" is on the last line, so it is left-justified.

**Example 2:**

>**Input:** words = ["a","b","c","d"], maxWidth = 3\
>**Output:** ["a b","c d"]

**Constraints:**

* ``1 <= words.length <= 300``
* ``1 <= words[i].length <= 20``
* ``words[i]`` contains only English letters and punctuation other than commas.
* ``1 <= maxWidth <= 100``
* ``words[i].length <= maxWidth``
