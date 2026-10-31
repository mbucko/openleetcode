from typing import List
from collections import Counter


class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        word_len = len(words[0])
        total = word_len * len(words)
        need = Counter(words)
        result = []
        for offset in range(word_len):
            seen = Counter()
            left = offset
            count = 0
            for right in range(offset, len(s) - word_len + 1, word_len):
                word = s[right:right + word_len]
                if word not in need:
                    seen.clear()
                    count = 0
                    left = right + word_len
                    continue
                seen[word] += 1
                count += 1
                while seen[word] > need[word]:
                    seen[s[left:left + word_len]] -= 1
                    count -= 1
                    left += word_len
                if count == len(words):
                    result.append(left)
        return sorted(result)
