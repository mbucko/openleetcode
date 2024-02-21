# Longest Substring Without Repeating Characters

Given a string `s`, find the length of the longest substring that has no repeating characters.


***Example 1:***

&emsp;&emsp;***Input:*** s = "abcabcbb"<br>
&emsp;&emsp;***Output:*** 3<br>
&emsp;&emsp;***Explanation:*** The answer is "abc", with the length of 3.



***Example 2:***

&emsp;&emsp;***Input:*** s = "bbbbb"<br>
&emsp;&emsp;***Output:*** 1<br>
&emsp;&emsp;***Explanation:*** The answer is "b", with the length of 1.<br>



***Example 3:***

&emsp;&emsp;***Input:*** s = "pwwkew"<br>
&emsp;&emsp;***Output:*** 3<br>
&emsp;&emsp;***Explanation:*** The answer is "wke", with the length of 3.<br>
&emsp;&emsp;Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

***Constraints:***

* ``0 <= s.length <= 5 * 104``
* ``s consists of English letters, digits, symbols and spaces.``