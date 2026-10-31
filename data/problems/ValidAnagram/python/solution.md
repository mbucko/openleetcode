## Approach
First, check whether the two strings have the same length. If they don't, return False.
Next, count how many times each letter appears in the first string. 
Then go through the second string and subtract from those counts.

If a letter is missing or appears too many times, return False. Otherwise, return True.

## Complexity Analysis
- **Time complexity:** O(n), because we go through both strings once.
- **Space complexity:** O(n), because we store letter counts in a dictionary.
